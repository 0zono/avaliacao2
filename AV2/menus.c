#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
#include "interactions.h"
#include "locacoes.h"

void menu();
void menuCarro();
void menuClientes();
void menuLocacoes();
//menu principal
void menu(){
    int op;
    //Interface inicial do programa
    printf("##############################################\n");
    printf("Programa Empresarial para Locação de Veículos\n");
    printf("##############################################\n\n");
    
    printf("Selecione a opção: \n 1: Carros \n 2: Clientes \n 3: Locações \n 9: Sair.\n\n");
    scanf("%d", &op);
    
    system("cls"); //Limpa a tela.
    //Verifica se as opções são válidas e chamam as funções de cada opção.
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
            printf("Até mais");
            Sleep(1500);
            break;
        default:
            printf("ERRO: Insira uma opção válida !\a");
            Sleep(2000);
            system("cls");
            menu();
            break;
    }

}
//Menu da opção "carros" do menu principal.
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
    
    system("cls");//Limpa a tela.
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
            printf("Até mais.\n");
            Sleep(1500);
            break;
        default:
            printf("ERRO: Insira uma opção válida !\a");
            Sleep(2000);
            system("cls");
            menuCarro();
            break;
    }


}

//Menu da opção "clientes" do menu principal.
void menuClientes(){
    int op;
    printf("1: Cadastrar cliente\n");
    printf("2: Atualizar informações de um cliente\n");
    printf("3: Mostrar o cadastro de um cliente específico\n");
    printf("4: Listar todos os clientes\n");
    printf("5: Listar clientes com mais de 200 pontos\n");
    printf("6: Listar clientes entre 18 e 25 anos\n");
    printf("7: Voltar ao menu anterior");
    printf("9: Sair.\n\n");
    scanf("%d", &op);
    
    system("cls");//Limpa a tela.
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
            showPontos();
            break;
        case 6:
            showIdade();
        case 7:
            menu();
        case 9:
            printf("Até mais.\n");
            Sleep(1500);
            break;
        default:
            printf("ERRO: Insira uma opção válida !\a");
            Sleep(2000);
            system("cls");
            menuClientes();
            break;

    }
}
//Menu da opção "Locações" do menu principal.
void menuLocacoes(){
    int op;
    printf("1: Nova locação\n");
    printf("2: Encerrar locação\n");
    printf("3: Listar locações atuais.\n");
    printf("9: Sair.\n\n");
    scanf("%d", &op);
    
    system("cls");//Limpa a tela.
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
            printf("Até mais.\n");
            Sleep(1500);
            break;
        default:
            printf("ERRO: Insira uma opção válida !\a");
            Sleep(2000);
            system("cls");
            menuLocacoes();
            break;
    }
}
