#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
mkdir -p artifacts
rm -rf artifacts/generated
rm -f artifacts/{factor,isprime,pidigits,fibonacci}{,.ll,.s} \
      artifacts/test-results.txt artifacts/files.txt \
      artifacts/unclosed-comment{,.ll,.s} artifacts/unclosed-comment.txt

check() {
    local name="$1"
    local argument="$2"
    local expected="$3"

    echo "Compilando $name.pas"
    ./build/minipas "examples/$name.pas" -o "artifacts/$name"
    local received
    received="$("./artifacts/$name" "$argument")"
    if [[ "$received" != "$expected" ]]; then
        echo "FALHOU: $name"
        echo "  esperado: $expected"
        echo "  recebido: $received"
        exit 1
    fi
    echo "OK: $name $argument -> $received"
}

check_invalid_comment() {
    local log="artifacts/unclosed-comment.txt"
    echo "Verificando erro de comentario nao terminado"
    if ./build/minipas tests/unclosed_comment.pas \
        -o artifacts/unclosed-comment >"$log" 2>&1; then
        echo "FALHOU: comentario nao terminado foi aceito"
        exit 1
    fi
    if ! grep -q "comentario nao terminado" "$log"; then
        echo "FALHOU: mensagem do erro lexico nao foi encontrada"
        exit 1
    fi
    echo "OK: comentario nao terminado foi rejeitado"
}

{
    check factor 84 "2 2 3 7"
    check isprime 97 "true"
    check pidigits 10 "3.141592653"
    check fibonacci 10 "55"
    check_invalid_comment
    echo "Todos os testes passaram."
} | tee artifacts/test-results.txt

mkdir -p artifacts/generated
cp build/lexer.cpp artifacts/generated/lexer.cpp
cp build/parser.cpp artifacts/generated/parser.cpp
cp build/parser.hpp artifacts/generated/parser.hpp
cp build/parser.output artifacts/generated/parser.output
find artifacts -maxdepth 2 -type f ! -name files.txt -print | sort > artifacts/files.txt
echo "Arquivos gerados pelo Flex e Bison copiados para artifacts/generated."
