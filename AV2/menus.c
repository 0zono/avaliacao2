#include <stdio.h>
#include <stdlib.h>
#include "interactions.h"
#include "locacoes.h"

void menu();
void menuCarro();
void menuClientes();
void menuLocacoes();
//menu principal
void menu(){
    int op;
    printf("Selecione a opção: \n 1: carros \n 2: clientes \n 3: locações \n 9: sair.\n\n");
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
    int opcao;
    printf("1: Cadastrar carro novo\n");
    printf("2: Atualizar informações de um carro\n");
    printf("3: Mostrar informações de um carro\n");
    printf("4: Listar todos os carros\n");
    printf("5: Disponibilizar carros pra venda\n");
    printf("6: Localizar carros por modelo ou motor\n");
    printf("7: Voltar para o menu principal\n");
    printf("9: Sair.\n\n");

    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            addCarro();
            break;
        case 2:
            updateCarro();
            break;
        case 3:
            mostraCarro();
            break;
        case 4:
            tdsCarros();
            break;
        case 5:

            break;
        case 6:
            searchCarro();
            break;
        case 7:
            menu();
            break;
        case 9:
            printf("até mais.");
            break;
        default:
            printf("Opção inválida");
            break;

    }


}

//menu da opção "clientes" do menu principal
void menuClientes(){
    int op;
    printf("1: Cadastrar cliente\n");
    printf("2: Atualizar informações de um cliente\n");
    printf("3: Mostrar locações realizadas\n");
    printf("4: Listar todos os clientes\n");
    printf("5: Listar clientes com mais de 200 pontos\n");
    printf("6: Listar clientes entre 18 e 25 anos\n");
    printf("9: Sair.\n\n");

    scanf("%d", &op);

    switch(op){
        case 1:
            addCliente();
            break;
        case 2:
            updateCliente();
            break;
        case 3:
            mostraCliente();
            break;
        case 4:
            tdsClientes();
            break;
        case 5:
            menu();
            break;
        case 9:
            printf("até mais.");
            break;
        default:
            printf("Opção inválida");
            break;

    }
}
//menu da opção "Locações" do menu principal
void menuLocacoes(){
    int op;
    printf("1: Nova locação\n");
    printf("2: Encerrar locação\n");
    printf("3: Listar locações atuais.\n");
    printf("9: Sair.\n\n");

    scanf("%d", &op);
    switch (op) {
        case 1:
            loca();
            break;
        case 2:

            break;
        case 3:
            //mostraLocacao();
            break;
        case 9:
            printf("até mais.");
            break;
        default:
            printf("Opção inválida");
            break;
    }
}
