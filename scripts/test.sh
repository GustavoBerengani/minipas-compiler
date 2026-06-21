#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
mkdir -p artifacts

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

{
    check factor 84 "2 2 3 7"
    check isprime 97 "true"
    check pidigits 10 "3.141592653"
    check fibonacci 10 "55"
    echo "Todos os testes passaram."
} | tee artifacts/test-results.txt

mkdir -p artifacts/generated
cp build/lexer.cpp artifacts/generated/lexer.cpp
cp build/parser.cpp artifacts/generated/parser.cpp
cp build/parser.hpp artifacts/generated/parser.hpp
cp build/parser.output artifacts/generated/parser.output
echo "Arquivos gerados pelo Flex e Bison copiados para artifacts/generated."
