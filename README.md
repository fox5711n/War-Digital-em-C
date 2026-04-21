# War-Digital-em-C
Este projeto é uma versão digital simplificada do clássico jogo War, desenvolvida inteiramente em Linguagem C. O objetivo foi consolidar conhecimentos avançados de programação, como gerenciamento manual de memória, ponteiros e estruturação modular de sistemas.

#Conceitos Aplicados

Para o desenvolvimento desta aplicação, apliquei conceitos fundamentais de Ciência da Computação:

Estruturas de Dados (Structs): Utilizadas para modelar os territórios (nome, cor e exército).

Alocação Dinâmica de Memória: Uso de malloc e calloc para criar o mapa conforme a escolha do usuário, garantindo eficiência no uso dos recursos.

Ponteiros e Passagem por Referência: Essenciais para a manipulação direta dos dados nas funções de ataque e cadastro, sem a criação de cópias desnecessárias na memória.

Modularização: Código organizado em funções distintas (cadastro, exibição, ataque, verificação de missão) para facilitar a manutenção e escalabilidade.

Lógica Aleatória: Implementação de simulação de dados de batalha utilizando srand e rand.

#Funcionalidades

Mapa Customizável: O usuário define quantos territórios o jogo terá.
Sistema de Ataque Realista: Cálculo de vitória baseado em rolagem de dados (1-6).
Dominação de Território: Se o atacante vence, ele assume a cor do defensor e transfere metade de suas tropas.
Missões Estratégicas: Sorteio automático de missões no início do jogo.

Validação de Regras: Impede ataques entre territórios da mesma cor.
