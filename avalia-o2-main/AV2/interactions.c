#include <stdio.h>
#include "regs.h"
#include <string.h>
#include "menus.h"
void menu();
void addCarro();
void mostraCarro();
void updateCarro();
void tdsCarros();
void addCliente();
void updateCLiente();
void mostraCliente();
void tdsClientes();


void addCarro(){
    Carros carro;
    char dnv;
    FILE *car = fopen("Carros.dat", "ab");

    printf("entre com a indentificação do carro: \n");
    scanf("%d", &carro.id);

    printf("entre com a placa do carro: \n");
    scanf(" %s", carro.placa);

    printf("entre com o modelo do carro: \n");
    scanf(" %s", carro.modelo);

    printf("entre com o motor do carro: \n");
    scanf(" %f", &carro.motor);

    printf("entre se o carro possui ar condicionado ou não (1 = possui/0 = não possui): \n");
    scanf(" %d", &carro.ar);

    printf("entre com a cor do carro (preto ou cinza): \n");
    scanf(" %s", carro.cor);

    printf("entre com o ano do carro: \n");
    scanf(" %d", &carro.ano);

    printf("entre com a quilometragem do carro: \n");
    scanf(" %d", &carro.kilo);

    printf("entre com o valor da diária do carro: \n");
    scanf( " %f", &carro.diaria);

    carro.dispo = 1;
    fwrite(&carro, sizeof(Carros), 1, car);

    fflush(car);
    printf("Deseja adicionar mais um carro a lista de automóveis? (s/n): \n");
    scanf(" %s", &dnv);
    if (dnv != 's' && dnv != 'S'){
        fclose(car);
        menu();

    }
    else{
        fclose(car);
        addCarro();
    }
    fclose(car);
}

void tdsCarros() {
    Carros carro;
    FILE *fp = fopen("Carros.dat", "rb");
    while(!feof(fp)) {
        fread(&carro, sizeof(Carros), 1, fp);
        printf("Identificação: %d\n", carro.id);
        printf("Placa: %s\n", carro.placa);
        printf("Modelo: %s\n", carro.modelo);
        printf("Motor: %f\n", carro.motor);
        printf("Ar condicionado: %d\n", carro.ar);
        printf("Cor: %s\n", carro.cor);
        printf("Ano: %d\n", carro.ano);
        printf("Quilometragem: %d\n", carro.kilo);
        printf("Valor da diária: %f\n", carro.diaria);
        printf("Disponibilidade: %d\n", carro.dispo);
        }
    system("pause");
    fclose(fp);
}


void mostraCarro() {
    Carros carro;
    FILE *fp = fopen("Carros.dat", "rb");
    int id;
    size_t count, records;
    long size;
    printf("entre com a indentificação do carro: \n");
    scanf("%d", &id);
    if(fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    size = ftell(fp);
    if(size == -1) {
        printf("Não há registros\n");
        return;
    }
    if(fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Carros);
    for(count = 0; count < records; count++) {
        fread(&carro, sizeof(Carros), 1, fp);
        if(carro.id == id) {
            printf("Identificação: %d\n", carro.id);
            printf("Placa: %s\n", carro.placa);
            printf("Modelo: %s\n", carro.modelo);
            printf("Motor: %f\n", carro.motor);
            printf("Ar condicionado: %d\n", carro.ar);
            printf("Cor: %s\n", carro.cor);
            printf("Ano: %d\n", carro.ano);
            printf("Quilometragem: %d\n", carro.kilo);
            printf("Valor da diária: %f\n", carro.diaria);
            printf("Disponibilidade: %d\n", carro.dispo);
            system("pause");
            break;
        }
    }
    system("pause");
    fclose(fp);
}

void updateCarro() {
    FILE *fp = fopen("Carros.dat", "r+b");
    Carros carro;
    int id, size, count, records;
    printf("entre com a indentificação do carro a ser atualizado: \n");
    scanf("%d", &id);

    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    size = ftell(fp);
    if (size == -1) {
        printf("Não há registros\n");
        return;
    }
    if (fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Carros);
        for (count = 0; count < records; count++) {
            fread(&carro, sizeof(Carros), 1, fp);
            if (carro.id == id) {
                printf("Oie");
                printf("entre com a identificação nova do carro: \n");
                scanf("%d", &carro.id);

                printf("entre com a nova placa do carro: \n");
                scanf("%s", carro.placa);

                printf("entre com o novo modelo do carro: \n");
                scanf("%s", carro.modelo);

                printf("entre com o novo motor do carro: \n");
                scanf("%f", &carro.motor);

                printf("entre se o carro possui ar condicionado ou não (1 = possui/0 = não possui): \n");
                scanf("%d", &carro.ar);

                printf("entre com a nova cor do carro (preto ou cinza): \n");
                scanf("%s", carro.cor);

                printf("entre com o novo ano do carro: \n");
                scanf("%d", &carro.ano);

                printf("entre com a nova quilometragem do carro: \n");
                scanf("%d", &carro.kilo);

                printf("entre com a novo valor da diária do carro: \n");
                scanf("%f", &carro.diaria);

                printf("entre com a nova disponibilidade do carro: \n");
                scanf("%d", &carro.dispo);

                fseek(fp, -(int)sizeof(Carros), SEEK_CUR);
                fwrite(&carro, sizeof(Carros), 1, fp);
                break;
            }
        }
        fflush(fp);
        fclose(fp);
    }

void addCliente(){
    Clientes cliente;
    int op;
    FILE *fp = fopen("Clientes.dat", "ab");

    printf("Digite seu CPF: \n");
    scanf(" %s", cliente.cpf);

    printf("Digite sua idade: \n");
    scanf(" %d", &cliente.idade);

    printf("Digite seu nome: \n");
    scanf(" %[^\n]s", cliente.nome);

    printf("Digite seu endereço de moradia: \n");
    scanf(" %[^\n]s", cliente.endereco);

    printf("Digite o seu estado de moradia: \n");
    scanf(" %[^\n]s", cliente.estado);

    printf("Digite a sua cidade de moradia: \n");
    scanf(" %[^\n]s", cliente.cidade);

    cliente.pontos = 0;
    fwrite(&cliente, sizeof(Clientes), 1, fp);
    system("cls");
   getchar();
    printf("Deseja adicionar mais um cliente?(0=Sim/1=Não) \n");
    scanf(" %d", &op);
    if (op != 's' && op != 'S'){
        fclose(fp);
        menu();

    }
    else{
        fclose(fp);
        addCliente();
    }
    fclose(fp);
}

void updateCliente() {
    FILE *fp = fopen("Clientes.dat", "r+b");
    Clientes cli;
    int size, count, records;
    char cpf[13], dnv;
    printf("entre com o cpf do cadastro a ser atualizado: \n");
    scanf("%s", cpf);

    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    size = ftell(fp);
    if (size == -1) {
        printf("Não há registros\n");
        return;
    }
    if (fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Clientes);
    for (count = 0; count < records; count++) {
        fread(&cli, sizeof(Clientes), 1, fp);
        if (strcmp(cli.cpf, cpf) == 0) {

            printf("Entre com a nova idade do cliente: \n");
            scanf(" %d", &cli.idade);

            printf("Entre com o nome novo do cliente: \n");
            scanf(" %[^\n]s", cli.nome);

            printf("Entre com o novo endereço do cliente: \n");
            scanf(" %[^\n]s", cli.endereco);

            printf("Entre com o novo estado de moradia do cliente: \n");
            scanf(" %[^\n]s", cli.estado);

            printf("Entre com a nova cidade de moradia do cliente: \n");
            scanf(" %[^\n]s", cli.cidade);

            cli.pontos = 0;

            fseek(fp, -(int)sizeof(Clientes), SEEK_CUR);
            fwrite(&cli, sizeof(Clientes), 1, fp);
            break;
        }
    }
    fflush(fp);
    printf("Deseja atualizar outro cliente? s=Sim/n=Não (Voltar ao menu anterior)\n");
    scanf("%s", &dnv);
    if (dnv != 's' && dnv != 'S'){
        fclose(fp);
        menu();
    }
    else{
        fclose(fp);
        updateCliente();
    }
    fclose(fp);
}

void mostraCliente(){
    FILE *fp = fopen("Clientes.dat", "rb");
    Clientes cli;
    char cpf[13];
    printf("Digite o CPF do cliente a ser encontrado: \n");
    scanf(" %s", cpf);
    getchar();
    int size, count, records;
    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    size = ftell(fp);
    if (size == -1) {
        printf("Não há registros\n");
        return;
    }
    if (fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Clientes);
    for (count = 0; count < records; count++) {
        fread(&cli, sizeof(Clientes), 1, fp);
        if (strcmp(cli.cpf, cpf) == 0) {
            printf("CPF do cliente: %s \n", cli.cpf);
            printf("Idade do cliente: %d\n ", cli.idade);
            printf("Nome do cliente: %s \n", cli.nome);
            printf("Endereço do cliente: %s \n", cli.endereco);
            printf("Estado de moradia do cliente: %s \n", cli.estado);
            printf("Cidade de moradia do cliente: %s \n", cli.cidade);
            printf("Pontos que o cliente tem: %d \n", cli.pontos);

            fseek(fp, -(int)sizeof(Clientes), SEEK_CUR);
            break;
        }
    }
    system("pause");
}

void tdsClientes(){
    FILE *fp = fopen("Clientes.dat", "rb");
    Clientes cli;
    char dnv;
    while(fread(&cli, sizeof(Clientes), 1, fp)){
        printf("CPF: %s\n", cli.cpf);
        printf("Idade: %d\n", cli.idade);
        printf("Nome: %s\n", cli.nome);
        printf("Endereço: %s\n", cli.endereco);
        printf("Estado: %s\n", cli.estado);
        printf("Cidade: %s\n", cli.cidade);
        printf("Pontos: %d\n", cli.pontos);
    }
    system("pause");
    fclose(fp);
    printf("Deseja voltar ao menu principal? s=Sim/n=Não(irá fechar o programa.)\n");
    scanf("%s", &dnv);
    if (dnv != 's' && dnv != 'S'){
        fclose(fp);
        menu();

    }
    else{
        fclose(fp);
    }
}
