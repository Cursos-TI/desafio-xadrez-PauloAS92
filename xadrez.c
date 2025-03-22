#include <stdio.h>

void torre(int direita){
    if(direita > 0){
        printf("DIREITA\n");
        torre(direita - 1);
    }
}

//Determina quantas casa na diagonal o bispo vai percorrer
void bispo(int diagonal){
    if(diagonal > 0){
        for ( int i = 1 ; i > 0 ; i--){
            printf("CIMA\n");
            for(int j = 1; j > 0 ; j--){
                printf("DIREITA\n");
            }
        }
        bispo (diagonal - 1);
    }
}

void rainha(int x, int y){//X é quantidade de casas e Y é o sentido do movimento
    if (x == 0){//Se x = 0 ele encerra a função
        return;
    }
    if(x){//não é necessário colocar x > 0 pq já está sendo verificado na linha acima
        switch (y){
        case 1:
            printf("DIREITA\n");
            break;
        case 2:
            printf("ESQUERDA\n");
            break;
        case 3:
            printf("CIMA\n");
            break;
        case 4:
            printf("BAIXO\n");
            break;
        case 5://DIAGONAL PARA DIREITA E PARA CIMA SOMENTE COMO EXEMPLO, NÃO CRIEI TODAS AS DIAGONAIS
            printf("DIREITA\n");
            printf("CIMA\n");
            break;
        }        
    }rainha(x-1, y);// NÃO DECREMENTA O Y POR QUE ELE É A DIREÇÃO DO MOVIMENTO, SE DECREMENTAR, A PEÇA MUDA A DIREÇÃO
}

int main(){
    printf("TORRE:\n");
    int movimento = 5;
    torre(movimento);

    printf("\nBISPO \n");
    int movimenta = 5;
    bispo(movimenta);

    int direcao = 1;//inicializa variavel para solicitar entrada ao usuário 
    int casas;//armazena a quantidade de casas que a rainha vai andar
    printf("\nEscolha o movimento da RAINHA:\n");
    printf("1 - DIREITA\n");
    printf("2 - ESQUERDA\n");
    printf("3 - CIMA\n");
    printf("4 - BAIXO\n");
    printf("5 - DIAGONAL\n");
    do{
        if(direcao <= 0 || direcao > 5){
            printf("digite uma opção válida: \n");
        }
        printf("Digite um opção: ");
        scanf(" %d", &direcao);
    }while (direcao <= 0 || direcao > 5);
    printf("Digite quantas casas a RAINHA movimentará? ");
    scanf("%d", &casas);
    printf("\nRAINHA\n");
    rainha(casas, direcao);
    
    printf("\nCavalo\n");
    
    for (int i = 0, j = 0; i < 4 && j < 3; i++, j++){
        if(j >= 2){//Para  o loop quando J = 2
            printf("DIREITA\n");
            break;
        }
        if(i > 1){//Pula quando i = 1
            continue;
        }
        printf("CIMA\n");
    }
    
    return 0;
    
}