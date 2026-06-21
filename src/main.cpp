#include "codegen.hpp"
#include "parser.hpp"
#include "parser_state.hpp"
#include "semantic.hpp"

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

extern FILE *yyin;
extern int yylineno;
int yyparse(void);

namespace minipas {
std::unique_ptr<Program> parsedProgram;
}

void yyerror(const char *message) {
    std::cerr << "Erro sintatico na linha " << yylloc.first_line
              << ": " << message << '\n';
}

static std::string shellQuote(const std::string &value) {
    std::string result = "'";
    for (char character : value) {
        if (character == '\'') result += "'\\''";
        else result += character;
    }
    result += "'";
    return result;
}

static void usage(const char *program) {
    std::cout << "Uso: " << program << " arquivo.pas [-o executavel]\n";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    std::filesystem::path source;
    std::filesystem::path output;
    for (int index = 1; index < argc; ++index) {
        std::string option = argv[index];
        if (option == "-o" && index + 1 < argc) {
            output = argv[++index];
        } else if (option == "--help" || option == "-h") {
            usage(argv[0]);
            return 0;
        } else if (source.empty()) {
            source = option;
        } else {
            std::cerr << "Argumento desconhecido: " << option << '\n';
            return 1;
        }
    }

    if (source.empty()) {
        usage(argv[0]);
        return 1;
    }
    if (output.empty()) output = source.stem();
    if (!output.parent_path().empty())
        std::filesystem::create_directories(output.parent_path());

    yyin = std::fopen(source.string().c_str(), "r");
    if (!yyin) {
        std::cerr << "Nao foi possivel abrir " << source << '\n';
        return 1;
    }
    yylineno = 1;
    minipas::parsedProgram.reset();
    int parseResult = yyparse();
    std::fclose(yyin);
    if (parseResult != 0 || !minipas::parsedProgram) return 1;

    minipas::SemanticAnalyzer semantic;
    if (!semantic.analyze(*minipas::parsedProgram)) {
        std::cerr << "Erros semanticos encontrados:\n";
        for (const std::string &error : semantic.errors())
            std::cerr << "  - " << error << '\n';
        return 1;
    }

    std::filesystem::path irPath = output.string() + ".ll";
    std::filesystem::path assemblyPath = output.string() + ".s";
    minipas::CodeGenerator generator;
    if (!generator.generate(*minipas::parsedProgram, irPath.string())) {
        std::cerr << "Erro na geracao de codigo: " << generator.error() << '\n';
        return 1;
    }

    const char *configuredClang = std::getenv("MINIPAS_CLANG");
    std::string clang = configuredClang ? configuredClang : "clang";
    std::string executableCommand = shellQuote(clang) +
        " -Wno-override-module -x ir " + shellQuote(irPath.string()) +
        " -o " + shellQuote(output.string());
    if (std::system(executableCommand.c_str()) != 0) {
        std::cerr << "Falha ao ligar o executavel com clang. O IR foi salvo em "
                  << irPath << '\n';
        return 1;
    }

    std::string assemblyCommand = shellQuote(clang) +
        " -Wno-override-module -S -x ir " +
        shellQuote(irPath.string()) + " -o " + shellQuote(assemblyPath.string());
    if (std::system(assemblyCommand.c_str()) != 0) {
        std::cerr << "Aviso: nao foi possivel gerar o arquivo assembly\n";
    }

    std::cout << "Compilado com sucesso:\n"
              << "  executavel: " << output << '\n'
              << "  LLVM IR:    " << irPath << '\n'
              << "  assembly:   " << assemblyPath << '\n';
    return 0;
}
