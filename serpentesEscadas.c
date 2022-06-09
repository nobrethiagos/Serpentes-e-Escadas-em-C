/*
Autores: Gabriel Martins & Thiago Nobre
Data: 13/10/2021
Email(s): gabriel.clmartins@gmail.com & thiagosn811@gmail.com
Descrição: Este programa simula o jogo de tabuleiro "Serpentes e Escadas", podendo ser jogado de 2 até 4 pessoas.
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>

#define LINUX

void escada(int *posicao, int i, int inicio, int fim) {
    if(*(posicao + i) == inicio) {
        printf("ESCADA encontrada!\n");
        *(posicao + i) = fim;
        printf("Sua nova posicao e: %d\n", posicao[i]);
    }
}

void serpente(int *posicao, int i, int inicio, int fim) {
    if(*(posicao + i) == inicio) {
        printf("SERPENTE encontrada!\n");
        *(posicao + i) = fim;
        printf("Sua nova posicao e: %d\n", posicao[i]);
    }
}

void mapa(int *campo){ 
    for(int i=0; i<100; i++){
        if(*(campo+i)==0){
            if((i + 1) == 2 || (i + 1) == 4 || (i + 1) == 8 || (i + 1) == 21 || (i + 1) == 28 || (i + 1) == 36 || (i + 1) == 51 || (i + 1) == 71 || (i + 1) == 80) {
                printf("[%3d E] ", i+1);    
            }
            else if((i + 1) == 16 || (i + 1) == 47 || (i + 1) == 48 || (i + 1) == 55 || (i + 1) == 62 || (i + 1) == 64 || (i + 1) == 92 || (i + 1) == 95 || (i + 1) == 99) {
                    printf("[%3d S] ", i+1);    
                }
                else {
                    printf("[%3d  ] ", i+1);
                }
        }
        if(*(campo+i) == 1) {
            printf("[  I  ] ");
        }
        if(*(campo+i) == 2) {
            printf("[  II ] ");
        }
        if(*(campo+i) == 3) {
            printf("[ III ] ");
        } 
        if(*(campo+i) == 4) {
            printf("[  IV ] ");
        }
        if(*(campo+i) == 5) {
            printf("[  X  ] ");
        }
        if((i + 1) % 10 == 0 && (i + 1) != 0) printf("\n");
    }
}

void movimentar(int *campo, int posInicial, int *posFinal, int player) {
    if(player + 1 == 1) {
        if(*(campo + posInicial - 1) == 1) {
            *(campo + posInicial - 1) = 0;
        }
        if(posInicial == *(posFinal + 1) && posInicial != *(posFinal + 2) && posInicial != *(posFinal + 3)) {
            *(campo + posInicial - 1) = 2;
        }
        if(posInicial != *(posFinal + 1) && posInicial == *(posFinal + 2) && posInicial != *(posFinal + 3)) {
            *(campo + posInicial - 1) = 3;    
        }
        if(posInicial != *(posFinal + 1) && posInicial != *(posFinal + 2) && posInicial == *(posFinal + 3)) {
            *(campo + posInicial - 1) = 4;
        }
        if(*(campo + *(posFinal + player) - 1) == 0) {
            *(campo + *(posFinal + player) - 1) = 1;
        }
        else {
            *(campo + *(posFinal + player) - 1) = 5;
        }
    }
    else if(player + 1 == 2) {
            if(*(campo + posInicial - 1) == 2) {
                *(campo + posInicial - 1) = 0;
            }
            if(posInicial == *(posFinal + 0) && posInicial != *(posFinal + 2) && posInicial != *(posFinal + 3)) {
                *(campo + posInicial - 1) = 1;
            }
            if(posInicial != *(posFinal + 0) && posInicial == *(posFinal + 2) && posInicial != *(posFinal + 3)) {
                *(campo + posInicial - 1) = 3;    
            }
            if(posInicial != *(posFinal + 0) && posInicial != *(posFinal + 2) && posInicial == *(posFinal + 3)) {
                *(campo + posInicial - 1) = 4;
            }
            if(*(campo + *(posFinal + player) - 1) == 0) {
                *(campo + *(posFinal + player) - 1) = 2;
            }
            else {
                *(campo + *(posFinal + player) - 1) = 5;
            }
        }
        else if(player + 1 == 3) {
                if(*(campo + posInicial - 1) == 3) {
                    *(campo + posInicial - 1) = 0;
                }
                if(posInicial == *(posFinal + 0) && posInicial != *(posFinal + 1) && posInicial != *(posFinal + 3)) {
                    *(campo + posInicial - 1) = 1;
                }
                if(posInicial != *(posFinal + 0) && posInicial == *(posFinal + 1) && posInicial != *(posFinal + 3)) {
                    *(campo + posInicial - 1) = 2;    
                }
                    if(posInicial != *(posFinal + 0) && posInicial != *(posFinal + 1) && posInicial == *(posFinal + 3)) {
                    *(campo + posInicial - 1) = 4;
                }
                    if(*(campo + *(posFinal + player) - 1) == 0) {
                    *(campo + *(posFinal + player) - 1) = 3;
                }
                else {
                    *(campo + *(posFinal + player) - 1) = 5;
                }
            }
            else if(player + 1 == 4) {
                if(*(campo + posInicial - 1) == 4) {
                    *(campo + posInicial - 1) = 0;
                }
                if(posInicial == *(posFinal + 0) && posInicial != *(posFinal + 1) && posInicial != *(posFinal + 2)) {
                    *(campo + posInicial - 1) = 1;
                }
                if(posInicial != *(posFinal + 0) && posInicial == *(posFinal + 1) && posInicial != *(posFinal + 2)) {
                    *(campo + posInicial - 1) = 2;    
                }
                if(posInicial != *(posFinal + 0) && posInicial != *(posFinal + 1) && posInicial == *(posFinal + 2)) {
                    *(campo + posInicial - 1) = 3;
                }
                if(*(campo + *(posFinal + player) - 1) == 0) {
                    *(campo + *(posFinal + player) - 1) = 4;
                }
                else {
                    *(campo + *(posFinal + player) - 1) = 5;
                }
            }
}

void limpar() {
    #ifdef LINUX
        __fpurge(stdin);
    #else
        fflush(stdin);
    #endif
}

typedef struct _APELIDO {
    char nick[42];
} APELIDO;

int main(void) {
    int i, j, party, temp, *posicao, *campo, n;
    char start; 
    APELIDO nome[4];
    campo = (int*)calloc(100, sizeof(int));
    *(campo + 0) = 5;
    printf("\t\t\t*BEM VINDO A SERPENTES E ESCADAS*\n\n");
    printf("Aperte ENTER para começar a partida.\n");
    start = getchar();
    do {
        if(start != '\n') {
            limpar();
            printf("\t\t\t*ERRO*\nAperte ENTER, e somente ENTER, para começar.\n");
            start = getchar();
        }
    } while(start != '\n');
    printf("Começou!\n");
    printf("Quantos jogadores? (2 a 4)\n");
    scanf("%d", &party);
    limpar();
    while(party < 2 || party > 4){ 
        printf("Por favor, insira um numero de jogadores valido (2 a 4)\n");
        scanf("%d", &party);
        limpar();
    } 
    posicao = calloc(party, sizeof(int));
    for(i=0; i<party; i++) {
        posicao[i] = 1;
    }
    for(i=0; i<party; i++) {
        printf("Insira o apelido do jogador %d, por favor: ", i+1);
        fgets(nome[i].nick, 42, stdin);
    }
    system("@cls||clear");
    while(1){
        for(i = 0; i < party; i++){
            mapa(campo);
            for(j=0; j<party; j++) {
                printf("\nPosicao do jogador %d: %d\n", j+1, posicao[j]);
            }
            printf("\nVez de %sAperte ENTER para jogar o dado.\n", nome[i].nick);
            start = getchar();
            limpar();
            do {
                if(start != '\n') {
                    printf("\t\t\t*ERRO*\nAperte ENTER, e somente ENTER, para jogar o dado.\n");
                    start = getchar();
                    limpar();
                }
            } while(start != '\n');
            system("@cls||clear");
            srand ( time(NULL) );
            n = ((rand() % 6) + 1);
            temp = posicao[i];
            posicao[i] += n;
            printf("Voce tirou %d no dado!\n", n);
            printf("Sua posicao e: %d\n", posicao[i]);
            escada(posicao, i, 2, 38);
            escada(posicao, i, 4, 14);
            escada(posicao, i, 8, 31);
            serpente(posicao, i, 16, 6);
            escada(posicao, i, 21, 42);
            escada(posicao, i, 28, 56);
            escada(posicao, i, 36, 44);
            serpente(posicao, i, 47, 26);
            serpente(posicao, i, 48, 11);
            escada(posicao, i, 51, 67);
            serpente(posicao, i, 55, 53);
            serpente(posicao, i, 62, 18);
            serpente(posicao, i, 64, 60);
            escada(posicao, i, 71, 91);
            escada(posicao, i, 80, 94);
            serpente(posicao, i, 92, 73);
            serpente(posicao, i, 95, 75);
            serpente(posicao, i, 99, 79);
            movimentar(campo, temp, posicao, i);
            printf("\n");
            if(posicao[0] >= 100 || posicao[1] >= 100 || posicao[2] >= 100 || posicao[3] >= 100) { 
                printf("O vencedor é: %s", nome[i].nick);
                printf("٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶٩(^‿^)۶\n");
                return 0;
            }
        }
    }
}