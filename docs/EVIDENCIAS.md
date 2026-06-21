# Roteiro para as evidencias

As capturas precisam ser reais e feitas no ambiente Linux/WSL do grupo. Nao ha
imagens preenchidas automaticamente neste repositorio.

## 1. Ambiente

Execute:

```bash
make environment | tee artifacts/environment.txt
```

Capture o terminal mostrando as versoes de GCC, Flex, Bison, NASM, Clang e LLVM.

## 2. Construcao

Execute:

```bash
make clean
make
```

Capture o trecho que mostra Bison, Flex, compilacao C++ e link do `minipas`.

## 3. Testes

Execute:

```bash
make test
```

Capture a tela completa com os quatro `OK` e `Todos os testes passaram`.

## 4. Artefatos

Execute:

```bash
find artifacts -maxdepth 2 -type f -print
```

Capture a lista dos executaveis, LLVM IR, assembly, resultados do teste e
arquivos gerados pelo Flex/Bison.

## 5. Capturas individuais

Para deixar cada requisito visivel, execute tambem:

```bash
./artifacts/factor 84
./artifacts/isprime 97
./artifacts/pidigits 10
./artifacts/fibonacci 10
```

Salve as imagens em uma pasta `docs/evidencias/` e acrescente abaixo os nomes
dos arquivos e uma pequena legenda. Nao edite o texto do terminal para alterar
resultados.
