# Tutorial do compilador MiniPas

## 1. Visao geral

O projeto implementa este fluxo:

```text
fonte .pas
   |
   v
Flex (tokens)
   |
   v
Bison (AST)
   |
   v
analise semantica
   |
   v
LLVM IR (.ll)
   |
   v
Clang -> assembly (.s) e executavel
```

O Flex reconhece os elementos menores do programa. O Bison verifica se esses
elementos seguem a gramatica e monta uma arvore sintatica abstrata (AST). A
analise semantica valida nomes, tipos e chamadas. Por ultimo, `CodeGenerator`
percorre a AST e usa a API C++ do LLVM.

## 2. Ambiente

Use Linux x86-64, macOS ou WSL2 Ubuntu. No Ubuntu:

```bash
sudo apt update
sudo apt install build-essential flex bison llvm-dev clang nasm
```

Confira e guarde evidencia das versoes:

```bash
gcc -v
flex --version
bison --version
nasm -v
clang --version
llvm-config --version
```

O comando `make environment` executa essa verificacao de forma resumida.

## 3. Estrutura do projeto

Os arquivos de entrada das ferramentas sao `lexer.l` e `parser.y`. O Bison cria
`build/parser.cpp`, `build/parser.hpp` e `build/parser.output`. O Flex cria
`build/lexer.cpp`.

A AST esta em `include/ast.hpp`. Cada no guarda tambem a linha de origem. A
analise de tipos esta em `src/semantic.cpp`, e a geracao LLVM esta em
`src/codegen.cpp`. `src/main.cpp` liga todas as etapas e chama o Clang.

## 4. Analise lexica

O arquivo `lexer.l` e dividido em definicoes, expressoes regulares e acoes.
Alguns exemplos de categorias reconhecidas sao:

```text
identificador: [A-Za-z_][A-Za-z_0-9]*
inteiro:       [0-9]+
texto:         '...'
atribuicao:    :=
comparacoes:   = <> < <= > >=
```

As palavras reservadas aparecem antes da regra de identificadores. O scanner e
`caseless`, portanto `BEGIN`, `Begin` e `begin` sao equivalentes. Os estados
`BRACE_COMMENT` e `PAREN_COMMENT` permitem comentarios em mais de uma linha.

`yylineno` e copiado para `yylloc`. Assim, erros das outras etapas apontam a
linha do arquivo `.pas`.

## 5. Gramatica

A forma geral aceita e:

```text
programa       -> program id ; declaracoes rotinas bloco .
declaracoes    -> vazio | var lista_de_declaracoes
rotina         -> function id ( parametros ) : tipo ; declaracoes bloco ;
                | procedure id ( parametros ) ; declaracoes bloco ;
bloco          -> begin lista_de_comandos end
```

Os principais comandos sao:

```text
comando -> id := expressao
         | if expressao then comando else comando
         | while expressao do comando
         | for id := expressao to expressao do comando
         | write ( argumentos )
         | writeln ( argumentos )
         | id ( argumentos )
         | return expressao
         | bloco
```

A precedencia, da menor para a maior, e `or`, `and`, comparacoes, soma/subtracao,
multiplicacao/divisao/mod e operadores unarios. Isso faz `2 + 3 * 4` resultar
em 14 sem precisar de parenteses.

As acoes semanticas do Bison criam objetos como `BinaryExpr`, `IfStmt` e
`RoutineDecl`. A memoria e administrada com `std::unique_ptr` depois que os nos
entram na AST.

Para inspecionar o automato LALR e os estados da pilha:

```bash
make
less build/parser.output
```

## 6. Analise semantica

O analisador possui uma tabela para variaveis globais, outra para o escopo da
rotina atual e uma tabela de assinaturas de funcoes/procedimentos. Ele verifica:

- declaracao duplicada;
- uso de variavel ou rotina inexistente;
- tipo dos dois lados de uma atribuicao;
- condicao booleana em `if` e `while`;
- variavel e limites inteiros no `for`;
- quantidade e tipo dos argumentos;
- uso correto de funcao e procedimento;
- tipo e existencia de `return` nas funcoes.

Os erros sao acumulados. Isso permite mostrar mais de um problema na mesma
execucao em vez de parar sempre no primeiro.

## 7. Geracao LLVM

`CodeGenerator` cria um `llvm::Module` e um `llvm::IRBuilder`. `integer` vira
`i64`, `boolean` vira `i1` e procedimentos usam retorno `void`.

Variaveis do programa sao globais LLVM para que tambem possam ser usadas pelas
rotinas. Parametros e variaveis locais usam `alloca` no bloco de entrada.

Uma atribuicao como:

```pascal
x := x + 1
```

produz, de forma simplificada:

```llvm
%old = load i64, ptr %x
%new = add i64 %old, 1
store i64 %new, ptr %x
```

Condicionais e lacos criam `BasicBlock`s e saltos condicionais. Chamadas MiniPas
viram `call`. `write` usa a funcao C `printf`, enquanto `param(1)` acessa `argv`
e converte o texto com `atoi`.

Antes de salvar o modulo, `verifyModule` confirma a consistencia do LLVM IR.

## 8. Link e executavel

Compile o compilador:

```bash
make
```

Compile um fonte MiniPas:

```bash
./build/minipas examples/fibonacci.pas -o fibonacci
```

O driver salva `fibonacci.ll` e usa estes comandos de forma automatica:

```bash
clang -x ir fibonacci.ll -o fibonacci
clang -S -x ir fibonacci.ll -o fibonacci.s
```

O executavel nao depende do compilador MiniPas. Ele depende somente das
bibliotecas normais do sistema que o Clang liga ao programa.

## 9. Programas obrigatorios

### Fatoracao

```bash
./build/minipas examples/factor.pas -o factor
./factor 84
# 2 2 3 7
```

### Numero primo

```bash
./build/minipas examples/isprime.pas -o isprime
./isprime 97
# true
```

### Digitos de pi

```bash
./build/minipas examples/pidigits.pas -o pidigits
./pidigits 10
# 3.141592653
```

### Fibonacci

```bash
./build/minipas examples/fibonacci.pas -o fibonacci
./fibonacci 10
# 55
```

Todos podem ser verificados com `make test`.

## 10. Arquivos de resultado

Depois de `make test`, a pasta `artifacts/` contem:

- executavel de cada programa;
- LLVM IR de cada programa (`.ll`);
- assembly de cada programa (`.s`);
- `test-results.txt` com as saidas;
- `generated/lexer.cpp`, resultado do Flex;
- `generated/parser.cpp` e `parser.hpp`, resultado do Bison;
- `generated/parser.output`, estados e conflitos da gramatica.

Esses sao os arquivos pedidos como fonte, resultado lexico, resultado da
gramatica, assembly e executavel.

## 11. Erros comuns

### `llvm-config: command not found`

Instale `llvm-dev` e confirme com `llvm-config --version`.

### Header LLVM nao encontrado

Use os flags retornados por `llvm-config --cxxflags`. O Makefile ja faz isso.

### `clang: command not found`

Instale o pacote `clang`. Se o binario tiver outro nome, por exemplo `clang-18`:

```bash
MINIPAS_CLANG=clang-18 ./build/minipas examples/factor.pas -o factor
```

### Erro sintatico perto de `end`

O ponto final aparece apenas no bloco principal (`end.`). Funcoes e
procedimentos terminam com `end;`. O ponto e virgula antes de `else` nao deve
ser usado.

### Programa fecha ao usar `param(1)`

Execute o programa passando o argumento, por exemplo `./factor 84`.

### Limpar e reconstruir

```bash
make clean
make
```

## 12. Depuracao

Confira primeiro `build/parser.output` quando houver conflito de gramatica. Para
problemas de codigo, leia o `.ll` produzido e valide manualmente com:

```bash
llvm-as programa.ll -o /dev/null
```

O script de teste interrompe no primeiro resultado incorreto e mostra o valor
esperado e o recebido.
