#include <stdio.h>
#include <locale.h>

int main (){
    int tamanho,qntminas;

    printf("\t  CAMPO MINADO\n");
    printf("Digite o tamanho do tabuleiro (5 a 100): ");
    scanf("%d", &tamanho);

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

    int tabu[tamanho][tamanho];

    for(int h = 0; h < qntminas; h++){
        int linha, coluna;
    }
}

