# Registro do uso de IA

O enunciado permite o uso de modelos de linguagem, desde que as ferramentas utilizadas e a forma de consulta sejam informadas. Este arquivo registra, de forma transparente, como a IA foi utilizada como apoio no desenvolvimento do projeto.

A IA foi usada como ferramenta auxiliar para interpretação do enunciado, organização inicial da solução, apoio na implementação e revisão do código. A validação final, a conferência dos requisitos e a execução dos testes permanecem sob responsabilidade dos autores do projeto.

## Ferramenta utilizada

| Ferramenta   | Modelo | Uso                                                                                                            |
| ------------ | ------ | -------------------------------------------------------------------------------------------------------------- |
| OpenAI Codex | GPT-5  | Apoio na análise do enunciado, estruturação do projeto, implementação inicial, revisão estática e documentação |

## Descrição da consulta principal

A consulta principal feita ao Codex teve como objetivo orientar a ferramenta a analisar o enunciado da disciplina antes de auxiliar na implementação do projeto.

O pedido foi feito em português, com foco em:

```text
Analisar o arquivo Project-Create-Compiler.md do repositório da disciplina,
identificar os requisitos obrigatórios, os arquivos esperados, as regras de
compilação e os critérios de validação do projeto.

A partir dessa análise, auxiliar na estruturação e implementação de um
compilador educacional para Mini-Pascal, utilizando Flex, Bison, C++17 e,
quando necessário, a API C++ do LLVM.

A solução também deveria considerar os programas de teste indicados no
enunciado, como factor.pas, isprime.pas, pidigits.pas e fibonacci.pas.
```

Durante o desenvolvimento, o modelo também recebeu informações sobre o caminho local do projeto e o enunciado foi consultado diretamente no repositório da disciplina.

## Forma de uso da IA

A IA foi utilizada principalmente para:

* interpretar os requisitos do arquivo `Project-Create-Compiler.md`;
* sugerir uma organização inicial para os arquivos do projeto;
* apoiar a construção do scanner com Flex;
* apoiar a construção do parser com Bison;
* auxiliar na revisão da gramática;
* apontar possíveis problemas relacionados à análise sintática e semântica;
* apoiar a organização da documentação do projeto.

## Limitações do uso da IA

O ambiente inicial utilizado estava no Windows, sem WSL, Flex, Bison ou LLVM instalados nativamente.

Por esse motivo, uma versão portátil do WinFlexBison foi usada para gerar e validar o scanner e o parser no Windows. A gramática ficou sem conflitos no ambiente de validação utilizado.

Os quatro arquivos fonte indicados no enunciado passaram por análise sintática e semântica em um harness de validação compilado com `g++`.

A compilação integrada e as evidências finais de execução devem ser verificadas em ambiente Linux/WSL com `make test`.

Nenhuma captura de tela, saída de terminal ou resultado de execução foi inventado.

## Observação sobre revisão por outro modelo

O enunciado recomenda o uso de mais de uma IA. Nesta etapa, não foi utilizada uma segunda ferramenta de IA. Portanto, não foi registrada uma revisão inexistente.

A IA foi utilizada como apoio durante o desenvolvimento, mas não substitui a verificação do funcionamento do programa nem a conferência dos requisitos solicitados no enunciado.
