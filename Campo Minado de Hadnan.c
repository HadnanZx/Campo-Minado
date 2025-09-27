#include <stdio.h>
#include <locale.h>

int main (){
    int tamanho,qntminas;
    int linha, coluna, h;

    printf("\t  CAMPO MINADO\n");
    printf("Digite o tamanho do tabuleiro (5 a 100): ");
    scanf("%d", &tamanho);

    int tabu[tamanho][tamanho];

    if(tamanho < 5 || tamanho > 100){
        printf("Tamanho invalido.\n");
        return 0;
    }


    printf("Digite a quantidade de minas: ");
    scanf("%d", &qntminas);

    if(qntminas <1 || qntminas >= tamanho * tamanho){
        printf("Quantidade de minas invalida. Jogo Encerrado. ");
        return 0;
    }
    printf("Tamanho escolhido %dx%d\n", tamanho, tamanho);
    printf("Quantidade de minas: %d\n", qntminas);


    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabu[i][j] = 0;
        }
    }

   for(int h = 0; h < qntminas; h++){
        printf("Digite onde a mina %d sera posicionada (linha e coluna): ", h + 1);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > tamanho || coluna < 1 || coluna > tamanho){
            printf("Posicao invalida, tente de novo. \n");
            h--;
            continue;
        }

        linha--;
        coluna--;

    if(tabu[linha][coluna] == -1){
        printf("Ja tem uma mina nessa posicao!");
        h--;
        continue;
     }

       tabu[linha][coluna] = -1;
  }

    for (int linhaAtual = 0; linhaAtual < tamanho; linhaAtual++) {
       for (int colunaAtual = 0; colunaAtual < tamanho; colunaAtual++) {

         if (tabu[linhaAtual][colunaAtual] == -1) {
            continue; // é mina,
         }

         int mnRedor = 0;

         // Percorre os vizinhos
         for (int dslLinha = -1; dslLinha <= 1; dslLinha++) {
             for (int dslColuna = -1; dslColuna <= 1; dslColuna++) {

                int vzLinha = linhaAtual + dslLinha;
                int vzColuna = colunaAtual + dslColuna;

                // Checa se tá dentro do tabuleiro
                if (vzLinha >= 0 && vzLinha < tamanho &&
                    vzColuna >= 0 && vzColuna < tamanho) {

                    if (tabu[vzLinha][vzColuna] == -1) {
                        mnRedor++;
                    }
                }
            }
        }

        tabu[linhaAtual][colunaAtual] = mnRedor;
    }
}

   printf("\nTabuleiro inicial:\n");
   for(int i = 0; i < tamanho; i++){
      for(int j = 0; j < tamanho ; j++){
         printf("%2d ", tabu[i][j]);
      }
      printf("\n");
   }



}

