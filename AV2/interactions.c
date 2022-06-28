#include <stdio.h>
#include "regs.h"
#include <string.h>

void addCarro();
void mostraCarro();
void attCarro();
void addCliente();

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


    system("pause");
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

//Função de Adicionar Clientes a um arquivo .dat - Gabs
void addCliente(){
    Clientes cliente;
    int pontos = 0;
    FILE *client = fopen("Clientes.dat", "ab");

    printf("Digite seu CPF: \n");
    scanf(" %s", cliente.cpf);
    fwrite(&cliente.cpf, sizeof(char), 11, client);

    printf("Digite sua idade: \n");
    scanf(" %d", &cliente.idade);
    fwrite(&cliente.idade, sizeof(char), 1, client);

    printf("Digite seu nome: \n");
    scanf(" %s", cliente.nome);
    fwrite(&cliente.nome, sizeof(char), 50, client);

    printf("Digite seu endereço de moradia: \n");
    scanf(" %[^\n]s", cliente.endereco);
    fwrite(&cliente.endereco, sizeof(char), 50, client);

    printf("Digite o seu estado de moradia: \n");
    scanf(" %s", cliente.estado);
    fwrite(&cliente.estado, sizeof(char), 2, client);

    printf("Digite a sua cidade de moradia: \n");
    scanf(" %s", cliente.cidade);
    fwrite(&cliente.cidade, sizeof(char), 50, client);

    printf("Você possuí %d pontos", pontos);
    fwrite(&cliente.pontos, sizeof(int), 1, client);
    fclose(client);
    }
