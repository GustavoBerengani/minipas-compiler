# MiniPas

Compilador didatico de uma parte pequena da linguagem Pascal. O compilador le
um arquivo `.pas`, faz analise lexica, sintatica e semantica, gera LLVM IR e
chama o Clang para produzir um executavel nativo.

## Integrantes

- Gustavo Negrão de Souza Berengani Ramos
- William da Silva Marques

> O enunciado informa que as equipes devem ter tres alunos, mas foram
> informados apenas os dois nomes acima. O grupo precisa confirmar essa situacao
> com o professor antes da entrega.

## Funcionalidades

- Tipos `integer` (64 bits) e `boolean`.
- Declaracao de variaveis globais e locais.
- Atribuicao e expressoes aritmeticas, relacionais e logicas.
- Comandos `if/then/else`, `while` e `for`.
- Funcoes, procedimentos, parametros e `return`.
- Saida com `write` e `writeln` para texto, inteiros e booleanos.
- Leitura de argumento com `param(1)`, que corresponde a `argv[1]`.
- Comentarios com `{ ... }`, `(* ... *)` e `//`.
- Mensagens de erro com numero da linha.
- Geracao dos arquivos LLVM IR (`.ll`) e assembly (`.s`).

## Dependencias

O projeto foi pensado para Ubuntu ou WSL2 Ubuntu:

```bash
sudo apt update
sudo apt install build-essential flex bison llvm-dev clang nasm
```

Para registrar as versoes instaladas:

```bash
make environment
```

## Compilacao

```bash
make
```

O compilador sera criado em `build/minipas`.

Para compilar um programa MiniPas:

```bash
./build/minipas examples/factor.pas -o factor
./factor 84
```

Saida esperada:

```text
2 2 3 7
```

Tambem serao criados `factor.ll` e `factor.s`.

## Testes

```bash
make test
```

O teste compila e executa:

| Programa | Argumento | Saida esperada |
|---|---:|---|
| `factor.pas` | 84 | `2 2 3 7` |
| `isprime.pas` | 97 | `true` |
| `pidigits.pas` | 10 | `3.141592653` |
| `fibonacci.pas` | 10 | `55` |

Os executaveis, os arquivos `.ll`, os arquivos `.s`, o resultado dos testes e
as saidas geradas por Flex/Bison ficam em `artifacts/`.

## Estrutura

```text
.
|-- examples/              programas obrigatorios
|-- include/               AST, semantica e geracao de codigo
|-- scripts/               verificacao do ambiente e testes
|-- src/                   implementacao C++
|-- docs/                  tutorial, evidencias e registro de IA
|-- lexer.l                 especificacao do Flex
|-- parser.y                gramatica do Bison
|-- Makefile                construcao do projeto
`-- README.md
```

## Exemplo da linguagem

```pascal
program Example;
var
  n: integer;

function Double(value: integer): integer;
begin
  return value * 2
end;

begin
  n := param(1);
  if n > 0 then
    writeln(Double(n))
  else
    writeln('valor invalido')
end.
```

## Documentacao

- [Tutorial completo](docs/TUTORIAL.md)
- [Registro do uso de IA](docs/USO-DE-IA.md)
- [Roteiro de evidencias](docs/EVIDENCIAS.md)

## Limitacoes conhecidas

- `param(indice)` considera que o argumento existe e contem um inteiro valido.
- Nao ha arrays, registros nem numeros reais.
- Os inteiros tem 64 bits. O exemplo `pidigits` pode estourar para entradas
  grandes; ele foi feito para demonstracoes pequenas, como 10 digitos.
- A verificacao de `return` confirma sua existencia, mas nao prova que todos os
  caminhos possiveis de uma funcao chegam a um `return`.
