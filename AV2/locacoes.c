#include <stdio.h>
#include "regs.h"
#include <string.h>
#include "menus.h"
void loca();



void loca(){
    FILE *car = fopen("Carros.dat", "rb");
    FILE *cli = fopen("Clientes.dat", "rb");
    FILE *loc = fopen("Locacoes.dat", "ab");
    Locacoes locacao;
    Carros carro;
    Clientes cliente;
    char dnv;
    int idcarro, cpfcliente, kiloinicial, kilofinal, idloca;
    float valor;
    date inicio, devolucao;
    printf("entre com o id do carro: \n");
    scanf(" %d", &idcarro);
    printf("entre com o id do cliente: \n");
    scanf(" %d", &cpfcliente);
    printf("entre com a quilometragem inicial do carro: \n");
    scanf(" %d", &kiloinicial);
    printf("entre com o valor da diária: \n");
    scanf(" %f", &valor);
    printf("entre com a data de início da locação: \n");
    printf("entre com o dia: \n");
    scanf(" %d", &inicio.dia);
    printf("entre com o mês: \n");
    scanf(" %d", &inicio.mes);
    printf("entre com o ano: \n");
    scanf(" %d", &inicio.ano);
    printf("entre com a data de devolução: \n");
    printf("entre com o dia: \n");
    scanf(" %d", &devolucao.dia);
    printf("entre com o mês: \n");
    scanf(" %d", &devolucao.mes);
    printf("entre com o ano: \n");
    scanf(" %d", &devolucao.ano);
    fwrite(&locacao, sizeof(Locacoes), 1, loc);

};
