# Micromouse 2.0 - Simulador de Labirinto (Projeto Descontinuado)

> ** Nota:** Este projeto foi descontinuado no decorrer do seu desenvolvimento e "não viu a luz do dia", permanecendo como um registo de implementação técnica de algoritmos de exploração.

Este projeto é uma implementação em C para o desafio **Micromouse**, focado na exploração de labirintos desconhecidos através de estruturas de dados e algoritmos de navegação.

## Funcionalidades Implementadas

- **Mapeamento por Grafos:** Utilização de grafos para registar vértices (posições) e conexões no labirinto.
- **Lógica de Navegação:** Sistema de comunicação com um árbitro externo para receber feedback de movimentos.
- **Gestão de Movimento:** Suporte para comandos de caminhada (`w`), rotação (`l`, `r`) e saltos/corridas (`j`, `s`).
- **Deteção de Ciclos:** Implementação de verificações para identificar quando o robô retorna a casas já visitadas.

## Estrutura do Repositório

- **main.c:** Contém a lógica principal do grafo e o loop de movimentação do robô.
- **makefile:** Script para automação da compilação e execução.
- **micromouse-rank.pdf:** Documentação de referência com as regras originais do desafio.

## Estado do Projeto

O desenvolvimento foi interrompido antes da conclusão de funcionalidades críticas, como a otimização do caminho de retorno ao ponto de partida. O código serve atualmente apenas para fins de estudo e consulta de lógica de grafos em C.

---
*Este repositório faz parte do arquivo de projetos de Davi Pierre.*
