#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    char cpf[13];
    int idade;
    char nome[50];
    char endereco[50];
    char estado[2];
    char cidade[50];
    int pontuacao;
} Clientes;

typedef struct {
    int id;
    char modelo[10];
    char cor[6];
    int ano;
    char placa[8];
    bool ar;
    int kilo;
    float diaria;
    bool dispo;
} Carros;

typedef struct {
    int hora;
    int dia;
    int mes;
    int ano;
} date;

typedef struct {
    int idloca;
    int idcarro;
    int cpflocatario;
    int kiloinicial;
    int kilofinal;
    float valor;
    date inicio;
    date devolucao;
}Locacoes;

void menu();
void op1();

int main() {
    menu(); //chama a função que cria o menu.
    return 0;
}

void menu(){
    int op;
    printf("Selecione a opção: \n 1: carros \n 2: clientes \n 3: locações \n 9: sair.");
    scanf("%d", &op);
    //verifica se as opções são válidas e chamam as funções de cada opção.
    system("cls"); //limpa a tela
    switch(op){
        case 1:
            printf("Op 1");
            break;
        case 2:
            printf("Op 2");
            break;
        case 3:
            printf("Op 3");
            break;
        case 9:
            printf("Op 9");
            break;
        default:
            printf("Opção inválida. Favor selecionar uma opção válida.");
            break;
    }

}

void op1(){

}







