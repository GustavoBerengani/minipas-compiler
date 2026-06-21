# Registro do uso de IA

O enunciado permite o uso de modelos de linguagem, desde que as ferramentas e
os prompts sejam informados. Este arquivo deve permanecer honesto e ser
atualizado se o grupo fizer novas consultas.

## Ferramenta usada

| Ferramenta | Modelo | Uso |
|---|---|---|
| OpenAI Codex | GPT-5 | Estrutura inicial, implementacao, revisao estatica e documentacao |

## Prompt principal

O pedido feito ao Codex, em portugues, foi:

```text
Analise o arquivo Project-Create-Compiler.md do repositorio da disciplina,
analise as instrucoes e faca o projeto. O grupo e Gustavo Negrão de Souza
Berengani Ramos e William da Silva Marques.
```

Durante o trabalho, o modelo tambem recebeu o caminho local do projeto e o
enunciado foi consultado diretamente no repositorio da disciplina.

## Limites da consulta

- O ambiente usado na criacao estava no Windows sem WSL, Flex, Bison ou LLVM.
- Uma versao portatil do WinFlexBison foi usada para gerar e validar o scanner e
  o parser no Windows. A gramatica ficou sem conflitos.
- Os quatro fontes passaram pela analise sintatica e semantica em um harness de
  validacao compilado com `g++`.
- A compilacao integrada e as evidencias precisam ser executadas pelo grupo em
  Linux/WSL com `make test`.
- Nenhuma captura de tela ou resultado de execucao foi inventado.

## Revisao por um segundo modelo

O enunciado recomenda usar mais de uma IA. Um segundo modelo nao foi usado
nesta sessao, portanto nao e correto registrar uma revisao inexistente. O grupo
pode usar o prompt abaixo em outra ferramenta e depois completar a tabela.

```text
Review this educational Mini-Pascal compiler built with Flex, Bison, C++17 and
the LLVM C++ API. Focus on parser conflicts, LLVM IR validity, semantic typing,
and whether factor.pas, isprime.pas, pidigits.pas and fibonacci.pas meet the
assignment. Do not rewrite the project. List concrete bugs and missing tests.
```

| Ferramenta | Modelo/data | Resultado da revisao |
|---|---|---|
| A preencher pelo grupo | A preencher | A preencher |

Os integrantes devem ler o codigo, executar os testes e registrar qualquer
mudanca feita depois dessa revisao. IA foi usada como apoio, nao como evidencia
de que o programa funciona.
