#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// STRUCTS

struct jogadores
{
  char nome[50];
  char cor_jogador[50];
  int P1, P2, P3, P4;
};

// FUNÇÕES

// Função para lançar o dado
int lancar_dado()
{
  int valor_dado = rand() % 6 + 1;
  return valor_dado;
}

// Função para atualizar a posição da peça escolhida
void atualizar_posicao(struct jogadores jogador[], int jogador_atual, int peao_escolhido, int valor_dado, int sequencia_seis)
{
  int posicao_destino = 0;

  if (peao_escolhido == 1)
  {
    if (jogador[jogador_atual].P1 == 0 && valor_dado == 6)
    {
      jogador[jogador_atual].P1 = 1; // Mover o peão para a posição 0 para a posição 1
      printf("A peça P1 agora está na posição 1.\n");
      sequencia_seis++;
    }
    else
    {
      posicao_destino = jogador[jogador_atual].P1 + valor_dado;
      if (posicao_destino <= 57)
      {
        jogador[jogador_atual].P1 = posicao_destino;
        printf("A peça P1 agora está na posição %d.\n", jogador[jogador_atual].P1);
        sequencia_seis = 0;
      }
    }
  }
  else if (peao_escolhido == 2)
  {
    if (jogador[jogador_atual].P2 == 0 && valor_dado == 6)
    {
      jogador[jogador_atual].P2 = 1; // Mover da posição 0 para a posição 1
      printf("A peça P2 agora está na posição 1.\n");
      sequencia_seis++;
    }
    else
    {
      posicao_destino = jogador[jogador_atual].P2 + valor_dado;
      if (posicao_destino <= 57)
      {
        jogador[jogador_atual].P2 = posicao_destino;
        printf("A peça P2 agora está na posição %d.\n", jogador[jogador_atual].P2);
        sequencia_seis = 0;
      }
    }
  }
  else if (peao_escolhido == 3)
  {
    if (jogador[jogador_atual].P3 == 0 && valor_dado == 6)
    {
      jogador[jogador_atual].P3 = 1; // Mover da posição 0 para a posição 1
      printf("A peça P3 agora está na posição 1.\n");
      sequencia_seis++;
    }
    else
    {
      posicao_destino = jogador[jogador_atual].P3 + valor_dado;
      if (posicao_destino <= 57)
      {
        jogador[jogador_atual].P3 = posicao_destino;
        printf("A peça P3 agora está na posição %d.\n", jogador[jogador_atual].P3);
        sequencia_seis = 0;
      }
    }
  }
  else if (peao_escolhido == 4)
  {
    if (jogador[jogador_atual].P4 == 0 && valor_dado == 6)
    {
      jogador[jogador_atual].P4 = 1; // Mover da posição 0 para a posição 1
      printf("A peça P4 agora está na posição 1.\n");
      sequencia_seis++;
    }
    else
    {
      posicao_destino = jogador[jogador_atual].P4 + valor_dado;
      if (posicao_destino <= 57)
      {
        jogador[jogador_atual].P4 = posicao_destino;
        printf("A peça P4 agora está na posição %d.\n", jogador[jogador_atual].P4);
        sequencia_seis = 0;
      }
    }
  }
}

// Função para capturar a peça do adversário
void capturar_peca(struct jogadores jogador[], int jogador_atual, int peao_escolhido, int valor_dado, int num_jogadores)
{
  int posicao_destino;

  if (peao_escolhido == 1)
  {
    posicao_destino = jogador[jogador_atual].P1 + valor_dado;
  }
  else if (peao_escolhido == 2)
  {
    posicao_destino = jogador[jogador_atual].P2 + valor_dado;
  }
  else if (peao_escolhido == 3)
  {
    posicao_destino = jogador[jogador_atual].P3 + valor_dado;
  }
  else if (peao_escolhido == 4)
  {
    posicao_destino = jogador[jogador_atual].P4 + valor_dado;
  }

  if (posicao_destino <= 51)
  {
    for (int i = 0; i < num_jogadores; i++)
    {
      if (i != jogador_atual && (jogador[i].P1 == posicao_destino || jogador[i].P2 == posicao_destino ||
                                 jogador[i].P3 == posicao_destino || jogador[i].P4 == posicao_destino))
      {

        // Verificar se a posição é uma casa segura
        int casa_segura = 0;
        int ponto_seguro[] = {1, 9, 14, 22, 27, 35, 40, 48};
        for (int j = 0; j < 8; j++)
        {
          if (posicao_destino == ponto_seguro[j])
          {
            casa_segura = 1;
            break;
          }
        }

        if (casa_segura)
        {
          printf("Movimento inválido. A posição destino é uma casa segura. O peão do jogador %d não pode ser capturado.\n", i + 1);
        }
        else
        {
          // Capturar o peão adversário
          printf("Você capturou o peão do jogador %d!\n", i + 1);
          if (jogador[i].P1 == posicao_destino)
            jogador[i].P1 = 0;
          else if (jogador[i].P2 == posicao_destino)
            jogador[i].P2 = 0;
          else if (jogador[i].P3 == posicao_destino)
            jogador[i].P3 = 0;
          else if (jogador[i].P4 == posicao_destino)
            jogador[i].P4 = 0;
        }
      }
    }
  }
}

// Função para verificar a vitória dos jogadores
int verificar_vitoria(struct jogadores jogador[], int jogador_atual)
{
  if (jogador[jogador_atual].P1 == 57 && jogador[jogador_atual].P2 == 57 &&
      jogador[jogador_atual].P3 == 57 && jogador[jogador_atual].P4 == 57)
  {
    return 1; // Jogador venceu
  }
  return 0; // Jogo continua
}

int main()
{

  // Inicializando a semente para gerar números aleatórios
  srand(time(NULL));

  // Variáveis
  int num_jogadores, jogador_atual = 0, sequencia_seis = 0, rodada = 2, vitoria = 0;
  char enter;

  // Definição do número de jogadores
  printf("\n=====================================================================");
  printf("\n================== Seja bem-vindo(a) ao jogo Ludo! ==================");
  printf("\n=====================================================================\n");
  printf("\nDigite a quantidade de jogadores (2 ou 4 jogadores): ");
  scanf("%d", &num_jogadores);

  while (num_jogadores != 2 && num_jogadores != 4)
  {
    printf("Quantidade de jogadores inválida. Digite novamente (2 ou 4 jogadores): ");
    scanf("%d", &num_jogadores);
  }

  struct jogadores jogador[num_jogadores];

  for (int i = 0; i < num_jogadores; i++)
  {
    printf("\nDigite o nome do jogador %d: ", i + 1);
    scanf("%s", jogador[i].nome);
    printf("Digite a cor do jogador %d (Vermelho, Verde, Azul ou Amarelo): ", i + 1);
    scanf("%s", jogador[i].cor_jogador);
  }

  // Apresentando algumas informações dos jogadores
  printf("\n=====================================================================\n");
  printf("\nInformações dos jogadores");

  for (int i = 0; i < num_jogadores; i++)
  {
    printf("\n\nJogador %d", i + 1);
    printf("\nNome: %s", jogador[i].nome);
    printf("\nCor: %s", jogador[i].cor_jogador);
  }

  printf("\n\n=====================================================================\n");
  printf("Rodada 1\n");

  // Inicializando as peças do jogador
  for (int i = 0; i < num_jogadores; i++)
  {
    jogador[i].P1 = 0;
    jogador[i].P2 = 0;
    jogador[i].P3 = 0;
    jogador[i].P4 = 0;
  }

  while (!vitoria)
  {
    // Lógica do jogo

    // Lançar o dado
    printf("\n%s, pressione Enter para lançar o dado.", jogador[jogador_atual].nome);
    scanf("%c", &enter);

    int valor_dado;

    if (enter == '\n')
    {
      valor_dado = lancar_dado();
      printf("\nO valor do dado foi: %d\n", valor_dado);
    }

    // Verificar se o jogador pode mover alguma peça
    int pode_mover = 0;

    // Verificar se a peça está na casa de partida
    if (valor_dado == 6)
    {
      if (jogador[jogador_atual].P1 == 0)
      {
        printf("Parabéns! Você pode mover a peça P1 para o circuito.\n");
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P2 == 0)
      {
        printf("Parabéns! Você pode mover a peça P2 para o circuito.\n");
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P3 == 0)
      {
        printf("Parabéns! Você pode mover a peça P3 para o circuito.\n");
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P4 == 0)
      {
        printf("Parabéns! Você pode mover a peça P4 para o circuito.\n");
        pode_mover = 1;
      }
    }

    // Verificar se a peça pode ser movida no circuito
    if (jogador[jogador_atual].P1 != 0 || jogador[jogador_atual].P2 != 0 ||
        jogador[jogador_atual].P3 != 0 || jogador[jogador_atual].P4 != 0)
    {

      if (jogador[jogador_atual].P1 != 0 && jogador[jogador_atual].P1 + valor_dado <= 57)
      {
        printf("Parabéns! Você pode mover a peça P1 para a posição %d no circuito.\n", jogador[jogador_atual].P1 + valor_dado);
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P2 != 0 && jogador[jogador_atual].P2 + valor_dado <= 57)
      {
        printf("Parabéns! Você pode mover a peça P2 para a posição %d no circuito.\n", jogador[jogador_atual].P2 + valor_dado);
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P3 != 0 && jogador[jogador_atual].P3 + valor_dado <= 57)
      {
        printf("Parabéns! Você pode mover a peça P3 para a posição %d no circuito.\n", jogador[jogador_atual].P3 + valor_dado);
        pode_mover = 1;
      }

      if (jogador[jogador_atual].P4 != 0 && jogador[jogador_atual].P4 + valor_dado <= 57)
      {
        printf("Parabéns! Você pode mover a peça P4 para a posição %d no circuito.\n", jogador[jogador_atual].P4 + valor_dado);
        pode_mover = 1;
      }
    }

    if (!pode_mover)
    {
      printf("Você não pode mover nenhuma peça. Passando a vez.\n");
      jogador_atual = (jogador_atual + 1) % num_jogadores; // Passa a vez para o próximo jogador

      // Verificar se todos os jogadores jogaram
      if (jogador_atual == 0)
      {
        printf("\n=====================================================================\n");
        printf("Rodada %d\n", rodada++);
      }
      continue; // Volta para o início do loop com o próximo jogador
    }

    // Movendo a peça escolhida
    int peao_escolhido, movimento_valido = 0; // Variável para controlar se o movimento é válido

    while (!movimento_valido)
    {
      printf("\nDigite o número da peça que deseja mover (1 a 4): ");
      scanf("%d", &peao_escolhido);

      // Verificar se o movimento escolhido é válido
      if ((valor_dado == 6 && (peao_escolhido == 1 || peao_escolhido == 2 || peao_escolhido == 3 || peao_escolhido == 4)) ||
          (peao_escolhido == 1 && (jogador[jogador_atual].P1 != 0 || valor_dado == 6) && jogador[jogador_atual].P1 + valor_dado <= 57) ||
          (peao_escolhido == 2 && (jogador[jogador_atual].P2 != 0 || valor_dado == 6) && jogador[jogador_atual].P2 + valor_dado <= 57) ||
          (peao_escolhido == 3 && (jogador[jogador_atual].P3 != 0 || valor_dado == 6) && jogador[jogador_atual].P3 + valor_dado <= 57) ||
          (peao_escolhido == 4 && (jogador[jogador_atual].P4 != 0 || valor_dado == 6) && jogador[jogador_atual].P4 + valor_dado <= 57))
      {
        movimento_valido = 1; // O movimento é válido, sair do loop
      }
      else
      {
        printf("Movimento inválido. Por favor, escolha outro movimento.\n");
      }
    }

    // Chamando a função para capturar o adversário
    capturar_peca(jogador, jogador_atual, peao_escolhido, valor_dado, num_jogadores);

    // Chamando a função para atualizar o valor da peça
    atualizar_posicao(jogador, jogador_atual, peao_escolhido, valor_dado, sequencia_seis);

    // Verificar se o jogador pode jogar novamente
    if (valor_dado == 6)
    {
      sequencia_seis++;

      if (sequencia_seis == 3)
      {
        printf("\n%s passou a vez, pois tirou três seis seguidos.\n", jogador[jogador_atual].nome);
        jogador_atual = (jogador_atual + 1) % num_jogadores; // Passa a vez para o próximo jogador
        sequencia_seis = 0;
      }
      
      else
      {
        continue; // Joga de novo
      }
    }
    else
    {
      jogador_atual = (jogador_atual + 1) % num_jogadores; // Passando a vez para o próximo jogador
      sequencia_seis = 0;
    }

    // Verificar se o jogador venceu o jogo
    if (verificar_vitoria(jogador, jogador_atual) == 1)
    {
      printf("\n=====================================================================\n");
      printf("Parabéns, %s! Você venceu o jogo Ludo!\n", jogador[jogador_atual].nome);
      printf("\n=====================================================================\n");
      vitoria = 1; // Encerrar o jogo
    }

    // Atualizar a rodada
    if (jogador_atual == 0)
    {
      printf("\n=====================================================================\n");
      printf("Rodada %d\n", rodada++);
    }
  }

    return 0;
}
//VAI CORINTHIANS!!!