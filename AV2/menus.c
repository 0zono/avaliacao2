#include <stdio.h>
#include <stdlib.h>
#include "regs.h"

void menu();
void menuCarro();
void menuClientes();
void menuLocacoes();
//menu principal
void menu(){
    int op;
    printf("Selecione a opção: \n 1: carros \n 2: clientes \n 3: locações \n 9: sair.");
    scanf("%d", &op);
    //verifica se as opções são válidas e chamam as funções de cada opção.
    system("cls"); //limpa a tela
    switch(op){
        case 1:
            menuCarro();
            break;
        case 2:
            menuClientes();
            break;
        case 3:
            menuLocacoes();
            break;
        case 9:
            printf("até mais");
            break;
        default:
            printf("Opção inválida. Favor selecionar uma opção válida.");
            break;
    }

}
//menu da opção "carros" do menu principal
void menuCarro(){
    int op;
    printf("1: Cadastrar carro novo\n");
    printf("2: Atualizar informações de um carro\n");
    printf("3: Disponibilizar carros pra venda\n");
    printf("4: Localizar carros por modelo\n");
    printf("9: Sair.\n\n");

    scanf("%d", &op);

}

//menu da opção "clientes" do menu principal
void menuClientes(){
    int op;
    printf("1: Cadastrar carro cliente\n");
    printf("2: Atualizar informações de um cliente\n");
    printf("3: Mostrar locações realizadas\n");
    printf("4: Listar clientes com mais de 200 pontos\n");
    printf("4: Listar clientes entre 18 e 25 anos\n");
    printf("9: Sair.\n\n");

    scanf("%d", &op);
}
//menu da opção "Locações" do menu principal
void menuLocacoes(){
    int op;
    printf("1: Nova locação\n");
    printf("2: Encerrar locação\n");
    printf("3: Listar locações atuais.\n");
    printf("9: Sair.\n\n");

    scanf("%d", &op);
}

