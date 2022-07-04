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
void updateCliente();
void mostraCliente();
void tdsClientes();
void searchCarro();
void showPontos();
void showIdade();

//Função para adicionar um carro (ainda não nos registros) ao arquivo "Carros.dat".
void addCarro(){
    Carros carro;
    char dnv;
    FILE *car = fopen("Carros.dat", "ab");

    printf("Entre com a indentificação do carro: \n");
    scanf("%d", &carro.id);

    printf("Entre com a placa do carro: \n");
    scanf(" %s", carro.placa);

    printf("Entre com o modelo do carro: \n");
    scanf(" %s", carro.modelo);

    printf("Entre com o motor do carro: \n");
    scanf(" %f", &carro.motor);

    printf("Entre se o carro possui ar condicionado ou não (1 = possui/0 = não possui): \n");
    scanf(" %d", &carro.ar);

    printf("Entre com a cor do carro (preto ou cinza): \n");
    scanf(" %s", carro.cor);

    printf("Entre com o ano do carro: \n");
    scanf(" %d", &carro.ano);

    printf("Entre com a quilometragem do carro: \n");
    scanf(" %d", &carro.kilo);

    printf("Entre com o valor da diária do carro: \n");
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

//Função feita para listar todos os carros dos registros (disponíveis ou não).
void tdsCarros() {
    Carros carro;
    FILE *fp = fopen("Carros.dat", "rb");
    while(fread(&carro, sizeof(Carros), 1, fp)) {
        printf("Identificação: %d\n", carro.id);
        printf("Placa: %s\n", carro.placa);
        printf("Modelo: %s\n", carro.modelo);
        printf("Motor: %f\n", carro.motor);
        printf("Ar condicionado: %d\n", carro.ar);
        printf("Cor: %s\n", carro.cor);
        printf("Ano: %d\n", carro.ano);
        printf("Quilometragem: %d\n", carro.kilo);
        printf("Valor da diária: %f\n", carro.diaria);
        if (carro.dispo == 1){
            printf("Disponibilidade: Disponível\n");
        }
        else{
            printf("Disponibilidade: Indisponível\n");
        }
    }
    system("pause");
    fclose(fp);
}

//Função feita para mostrar ao usuário um veículo através do seu código de identificação (inserido no momento de seu cadastro no sistema). 
void mostraCarro() {
    system("cls");
    Carros carro;
    char op;
    FILE *fp = fopen("Carros.dat", "rb");
    int id;
    size_t count, records;
    long size;
    printf("Entre com a indentificação do carro: \n");
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
    printf("Deseja voltar ao menu principal?(s/S=Sim, caso contrário, o programa se encerrará.) \n");
    scanf(" %d", &op);
    if (op != 's' && op != 'S'){
        fclose(fp);
        menu();

    }
    else{
        fclose(fp);
        mostraCarro();
    }
    system("pause");
    fclose(fp);
}

//Função feita para atualizar um veículo que já está no sistema, a partir, também, de seu código de identificação.
void updateCarro() {
    system("cls");
    FILE *fp = fopen("Carros.dat", "r+b");
    Carros carro;
    char op;
    int id, size, count, records;
    printf("Entre com a indentificação do carro a ser atualizado: \n");
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
            printf("Entre com a identificação nova do carro: \n");
            scanf("%d", &carro.id);

            printf("Entre com a nova placa do carro: \n");
            scanf("%s", carro.placa);

            printf("Entre com o novo modelo do carro: \n");
            scanf("%s", carro.modelo);

            printf("Entre com o novo motor do carro: \n");
            scanf("%f", &carro.motor);

            printf("Entre se o carro possui ar condicionado ou não (1 = possui/0 = não possui): \n");
            scanf("%d", &carro.ar);

            printf("Entre com a nova cor do carro (preto ou cinza): \n");
            scanf("%s", carro.cor);

            printf("Entre com o novo ano do carro: \n");
            scanf("%d", &carro.ano);

            printf("Entre com a nova quilometragem do carro: \n");
            scanf("%d", &carro.kilo);

            printf("Entre com a novo valor da diária do carro: \n");
            scanf("%f", &carro.diaria);

            printf("Entre com a nova disponibilidade do carro: \n");
            scanf("%d", &carro.dispo);

            fseek(fp, -(int)sizeof(Carros), SEEK_CUR);
            fwrite(&carro, sizeof(Carros), 1, fp);
            break;
        }
    }
    fflush(fp);
    printf("Deseja atualizar mais um carro?(s/S=Sim) \n");
    scanf(" %d", &op);
    if (op != 's' && op != 'S'){
        fclose(fp);
        menu();

    }
    else{
        fclose(fp);
        updateCarro();
    }
}

//Função para buscar um veículo a partir de seu modelo ou motor.
void searchCarro(){
    Carros carro;
    FILE *fp = fopen("Carros.dat", "rb");
    char modelo[10];
    float motor;
    int op;
    size_t count, records;
    long size;
    printf("1: Buscar por modelo\n2: Buscar por motor \n"); //Pergunta-se ao usuário que tipo de busca ele deseja.
    scanf("%d", &op);
    switch (op) {
        case 1: //Busca através do modelo do carro (Polo, Corolla, Civic, ...)
            printf("Insira o modelo do carro a ser buscado: \n");
            scanf("%s", &modelo);
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

                if(strcmp(carro.modelo, modelo)==0) {
                    printf("Carros encontrados com o modelo: %s\n", modelo);
                    printf("Identificação: %d\n", carro.id);
                    printf("Placa: %s\n", carro.placa);
                    printf("Modelo: %s\n", carro.modelo);
                    printf("Motor: %f\n", carro.motor);
                    printf("Ar condicionado: %d\n", carro.ar);
                    printf("Cor: %s\n", carro.cor);
                    printf("Ano: %d\n", carro.ano);
                    printf("Quilometragem: %d\n", carro.kilo);
                    printf("Valor da diária: %f\n", carro.diaria);
                    printf("Disponibilidade: %d\n\n", carro.dispo);
                }
            }
            break;
        case 2: //Busca através do motor do carro (1.8, 1.0, 2.0, ...).
            printf("Insira o motor do carro a ser buscado: \n");
            scanf("%f", &motor);
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

                if(carro.motor == motor) {
                    printf("Carros encontrados com o motor: %s\n", motor);
                    printf("Identificação: %d\n", carro.id);
                    printf("Placa: %s\n", carro.placa);
                    printf("Modelo: %s\n", carro.modelo);
                    printf("Motor: %f\n", carro.motor);
                    printf("Ar condicionado: %d\n", carro.ar);
                    printf("Cor: %s\n", carro.cor);
                    printf("Ano: %d\n", carro.ano);
                    printf("Quilometragem: %d\n", carro.kilo);
                    printf("Valor da diária: %f\n", carro.diaria);
                    printf("Disponibilidade: %d\n\n", carro.dispo);
                }
            }
            break;
    }
    system("pause");
}

//Função para adicionar clientes aos registros do sistema.
void addCliente(){
    system("cls");
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
    printf("Deseja adicionar mais um cliente?(s/S=Sim, n/N=Não) \n");
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

//Função feita para atualizar o cadastro de um cliente dos registros.
void updateCliente() {
    system("cls");
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
    system("cls");
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
    system("cls");
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
    fclose(fp);
    printf("Deseja voltar ao menu principal? s=Sim/n=Não(irá fechar o programa.)\n");
    scanf("%s", &dnv);
    if (dnv != 's' && dnv != 'S'){
        fclose(fp);

    }
    else{
        fclose(fp);
        menu();

    }
}

void showPontos(){
    system("cls");
    FILE *fp = fopen("Clientes.dat", "rb");
    Clientes cli;
    int size, records, aux = 0;

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

    printf("Aqui estão todos os clientes com + de 200 pontos:\n\n");
    records = size / sizeof(Clientes);
    for (int cont = 0; cont < records; cont++) {
        fread(&cli, sizeof(Clientes), 1, fp);
        if (cli.pontos > 200) {
            aux++;
            printf("CPF do cliente: %s \n", cli.cpf);
            printf("Idade do cliente: %d\n ", cli.idade);
            printf("Nome do cliente: %s \n", cli.nome);
            printf("Endereço do cliente: %s \n", cli.endereco);
            printf("Estado de moradia do cliente: %s \n", cli.estado);
            printf("Cidade de moradia do cliente: %s \n", cli.cidade);
            printf("Pontos que o cliente tem: %d \n\n", cli.pontos);

            fseek(fp, -(int) sizeof(Clientes), SEEK_CUR);
            break;
        }
    }
    if(aux == 0){
        printf("Não há nenhum cliente com + de 200 pontos. \n\n");
    }
    fclose(fp);
    system("pause");
}

//Função para mostrar os clientes com faixa de idade de 18 a 25 anos.
void showIdade(){
    system("cls");
    FILE *fp = fopen("Clientes.dat", "rb");
    Clientes cli;
    int size, count, records, aux;

    //Funções para verificar erros ou inexistência do registro.
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
    printf("Aqui estão todos os clientes entre 18 a 25 anos: \n\n");
    for (count = 0; count < records; count++) {
        fread(&cli, sizeof(Clientes), 1, fp);
        if ((cli.idade >= 18) && (cli.idade <= 25)) {
            aux++;
            printf("CPF do cliente: %s \n", cli.cpf);
            printf("Idade do cliente: %d\n ", cli.idade);
            printf("Nome do cliente: %s \n", cli.nome);
            printf("Endereço do cliente: %s \n", cli.endereco);
            printf("Estado de moradia do cliente: %s \n", cli.estado);
            printf("Cidade de moradia do cliente: %s \n", cli.cidade);
            printf("Pontos que o cliente tem: %d \n\n", cli.pontos);

            fseek(fp, -(int) sizeof(Clientes), SEEK_CUR);
            break;
        }
    }
    fclose(fp);
    if (aux == 0){
        printf("Não foram encontrados nos registros clientes nessa faixa de idade.\n\n");
    }
    system("pause");
}
