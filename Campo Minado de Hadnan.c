#include <stdio.h>
#include <locale.h>

int main (){
    int tamanho,qntminas;
    int linha, coluna, h;

    setlocale(LC_ALL, "");
    //Inicio de tudo, e definição do tamanho da matriz
    printf("\t  CAMPO MINADO\n");
    printf("Digite o tamanho do tabuleiro (5 a 100): ");
    scanf("%d", &tamanho);

    //Cria a matriz do tabuleiro do jogo.
    int tabu[tamanho][tamanho];
    //Valida o tamanho do tabuleiro, se está dentro das regras
    if(tamanho < 5 || tamanho > 100){
        printf("Tamanho invalido.\n");
        return 0;
    }


    printf("Digite a quantidade de minas: ");
    scanf("%d", &qntminas);
    //Evita situações impossiveis de jogar e garante que tenha sentido
    if(qntminas <1 || qntminas >= tamanho * tamanho){
        printf("Quantidade de minas invalida. Jogo Encerrado. ");
        return 0;
    }
    //Diz os valores escolhidos
    printf("Tamanho escolhido %dx%d\n", tamanho, tamanho);
    printf("Quantidade de minas: %d\n", qntminas);

    //Cria estrutura incial do jogo, com todas as posições sendo 0
    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            tabu[i][j] = 0;
        }
    }

    //Loop para selecionar onde é colocada cada mina
    for(int h = 0; h < qntminas; h++){
        printf("Digite onde a mina %d sera posicionada (linha e coluna): ", h + 1);
        scanf("%d %d", &linha, &coluna);
        //Garante que a posição selecionada esteja no tabuleiro
        if(linha < 1 || linha > tamanho || coluna < 1 || coluna > tamanho){
            printf("Posicao invalida, tente de novo. \n");
            //Volta a pedir a mesma mina, se a opção for invalida
            h--;
            continue;
        }
        //Volta a coordenada do tabuleiro de 1 a (n qualquer) pra 0 a (n-1)
        linha--;
        coluna--;
    //Impede duplicatas de mina na mesma posição
    if(tabu[linha][coluna] == -1){
        printf("Ja tem uma mina nessa posicão!");
        h--;
        continue;
     }
     //Marca a posição selecionada como (-1), sendo um sinal de que tem uma mina
     tabu[linha][coluna] = -1;
  }
    //Percorre todas as linhas e colunas do tabuleiro de novo
    for(int liAtual = 0; liAtual < tamanho; liAtual++) {
       for(int colAtual = 0; colAtual < tamanho; colAtual++){

         if(tabu[liAtual][colAtual] == -1){
            continue; // O codigo nao meche na posição que tiver uma mina
         }
         //Variavel contadora das minas que existem ao redor da posição atual
         int mnRedor = 0;

         // Percorre os vizinhos da posição atual
         for(int dslLinha = -1; dslLinha <= 1; dslLinha++) {
             for(int dslColuna = -1; dslColuna <= 1; dslColuna++){

                //Soma o deslocamento pra obter o local da "celula" vizinha
                int vzLinha = liAtual + dslLinha;
                int vzColuna = colAtual + dslColuna;

                // Checa se tá dentro do tabuleiro
                if(vzLinha >= 0 && vzLinha < tamanho && vzColuna >= 0 && vzColuna < tamanho){
                    //Se na casa vizinha tiver uma mina, incrementar no mnRedor
                    if(tabu[vzLinha][vzColuna] == -1){
                        mnRedor++;
                    }
                }
            }
        }
        //Define o valor da casa com o numero de minas em volta
        tabu[liAtual][colAtual] = mnRedor;
      }
   }
    //Mostra o tabuleiro por de baixo dos panos, com as minas ja incluidas e os valores das minas ao redor das casas
    printf("\nTabuleiro Real:\n");
    for(int i = 0; i < tamanho; i++){
      for(int j = 0; j < tamanho ; j++){
         printf("%2d ", tabu[i][j]);
      }
      printf("\n");
   }
    //Guarda casa ja revelada
    int tabuEstado[tamanho][tamanho]; // 0 = Tá fechado, 1 = Tá aberto

    for(int i = 0; i < tamanho; i++){
       for(int j = 0; j < tamanho; j++){
         tabuEstado[i][j] = 0; // Tudo fechado no inicio
      }
   }

    int jogoAtivo = 1;
    //Enquanto jogoAtivo for 1, o jogo roda, se cair em uma mina ou vençer, ele vai virar 0 e parar
    while(jogoAtivo){
        printf("\nTabuleiro:\n   "); // Espaço inicial pra alinhamento

        // Imprime números das colunas
        for(int col = 0; col < tamanho; col++){
        printf("%2d ", col + 1);
        }
        printf("\n");

        // Imprime cada linha
        for(int i = 0; i < tamanho; i++){
            printf("%2d ", i + 1); // Cabeçalho da linha
            for(int j = 0; j < tamanho; j++){
              if(tabuEstado[i][j] == 0){
                 printf(" O ");
              }else{
                 printf(" X ");
              }
        }
    printf("\n");
}


    // Usuário escolhe a posição onde quer arriscar
    printf("Digite a linha e coluna para revelar: ");
    scanf("%d %d", &linha, &coluna);

    //Converte de 1 a N, para 0 a N-1, deixando a tabela mais coeza
    linha--;
    coluna--;

     // Verificação da validade
    if(linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho){
        printf("Posição inválida.\n");
        continue;
    }

    //impede que o jogador jogue duas vezes na mesma posição
    if(tabuEstado[linha][coluna] == 1){
       printf("\nEssa posição já foi revelada. Escolha outra.\n");
       continue;
    }

    // Revela a posição marcada pelo usuario
    tabuEstado[linha][coluna] = 1;

    // Caso caia em uma mina
    if(tabu[linha][coluna] == -1){
        printf("BOOM! Caiu em uma mina. Game Over para você.\n");
        jogoAtivo = 0;
    }
    //calcula a quantidade de casas que nao tem minas, o jogador já abriu
    int casasReveladas = 0;
    int totalCasas = tamanho * tamanho - qntminas;

    //Conta a quantidade de casas sem minas que ja foram selecionadas
    for(int i = 0; i < tamanho; i++){
       for(int j = 0; j < tamanho; j++){
         if(tabuEstado[i][j] == 1 && tabu[i][j] != -1){
            casasReveladas++;
         }
      }
    }
    //Se a quantidade de casas selecionadas for igual o total de casas sem as minas, o jogador vence
    if(casasReveladas == totalCasas){
       printf("\nPARABÉNS! Você venceu!\n");
       jogoAtivo = 0;
     }
   }
   //Encerramento
   printf("\nJogo encerrado.\n");
   printf("Tabuleiro final:\n");

   //Mostra o tabuleiro Real depois do termino do jogo.
   for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++){
         if(tabu[i][j] == -1){
            printf(" * ");
        }else{
            printf(" %d ", tabu[i][j]);
        }
     }
    printf("\n");
   }



}

