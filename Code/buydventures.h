#ifndef UNTITLED7_BUYDVENTURES_H
#define UNTITLED7_BUYDVENTURES_H
#include <iostream>
#include <cstring>
#define tamanho 10

using namespace std;

string loja[20] = {"Ametista", "Diamante", "Rubi", "BARRA DE FERRO MUITO PESADA", "Veneno pra goblin (Não tenho certeza se funciona)",
                   "Batata Frita", "Hamburguer", "Refrigerante", "Livro \"Como Conquistar o Amor da sua Vida\"", "Anel de ouro", "Taça do Hexa", "Bolsa da Gucci",
                   "Camiseta SUPREME", "Cinto Off-White", "Primeiro lote do TUSCA"};

//Definição da Pilha
typedef struct{
    int topo ;
    string item[tamanho] ;
}Pilha;

void iniciaPilha (Pilha &p) {
    p.topo = -1 ;
}

bool pilhaVazia(Pilha p){
    if(p.topo == -1 )
        return true;
    else
        return false;
}

bool pilhaCheia(Pilha p){
    if (p.topo == tamanho-1)
        return true;
    else
        return false;
}

void empilha(Pilha &p, int x){
    p.item[++p.topo]=loja[x];
}

string desempilha(Pilha &p){
    return (p.item[p.topo--]) ;
}

//Definição de itens de jogo

typedef struct{
    int gold = 70;
    int goblin[5];
    int bau[5];
    int pos = 0;
    int luck = 0;
    int fim[11] = {0,0,0,0,0,0,0,0,0,0,0};
    Pilha inv;
}Tabuleiro;

bool isGoblin(Tabuleiro *t){
    return t->pos == t->goblin[0] || t->pos == t->goblin[1] || t->pos == t->goblin[2];
}

bool isChest(Tabuleiro *t){
    return t->pos == t->bau[0] || t->pos == t->bau[1] || t->pos == t->bau[2];
}

void geraCasas(Tabuleiro *t){
    iniciaPilha(t->inv);
    t->goblin[0] = rand()%24;
    t->goblin[1] = rand()%24;
    t->goblin[2] = rand()%24;
    t->goblin[3] = rand()%24;
    t->goblin[4] = rand()%24;
    t->bau[0] = rand()%24;
    t->bau[1] = rand()%24;
    t->bau[2] = rand()%24;
    t->bau[3] = rand()%24;
    t->bau[4] = rand()%24;
}

#endif //UNTITLED7_BUYDVENTURES_H
