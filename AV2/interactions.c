#include <stdio.h>
#include "regs.h"
#include <string.h>

void addCarro();
void mostraCarro();
void attCarro();

void addCarro(){
    Carros carro;
    FILE *car = fopen("Carros.dat", "ab");

    printf("entre com a indentificação do carro: \n");
    scanf("%d", &carro.id);
    fwrite(&carro.id, sizeof(int), 1, car);

    printf("entre com a placa do carro: \n");
    scanf(" %s", carro.placa);
    fwrite(carro.placa, sizeof(char), 8, car);

    printf("entre com o modelo do carro: \n");
    scanf(" %s", carro.modelo);
    fwrite(carro.modelo, sizeof(char), 10, car);

    printf("entre com o motor do carro: \n");
    scanf(" %f", &carro.motor);
    fwrite(&carro.motor, sizeof(float), 1, car);

    printf("entre se o carro possui ar condicionado ou não (1 = possui/0 = não possui): \n");
    scanf(" %d", &carro.ar);
    fwrite(&carro.ar, sizeof(int), 1, car);

    printf("entre com a cor do carro (preto ou cinza): \n");
    scanf(" %s", carro.cor);
    fwrite(carro.cor, sizeof(char), 6, car);

    printf("entre com o ano do carro: \n");
    scanf(" %d", &carro.ano);
    fwrite(&carro.ano, sizeof(int), 1, car);

    printf("entre com a quilometragem do carro: \n");
    scanf(" %d", &carro.kilo);
    fwrite(&carro.kilo, sizeof(int), 1, car);

    printf("entre com o valor da diária do carro: \n");
    scanf( " %f", &carro.diaria);
    fwrite(&carro.diaria, sizeof(int), 1, car);

    carro.dispo = 1;
    fwrite(&carro.dispo, sizeof(int), 1, car);

    fclose(car);
}

void mostraCarro(){
    Carros carro;
    FILE *car = fopen("Carros.dat", "rb");
    fread(&carro.id, sizeof(int), 1, car);
    fread(carro.placa, sizeof(char), 8, car);
    fread(carro.modelo, sizeof(char), 10, car);
    fread(&carro.motor, sizeof(float), 1, car);
    fread(&carro.ar, sizeof(int), 1, car);
    fread(carro.cor, sizeof (char), 6, car);
    fread(&carro.ano, sizeof (int), 1, car);
    fread(&carro.kilo, sizeof(int), 1, car);
    fread(&carro.diaria, sizeof(float), 1, car);
    fread(&carro.dispo, sizeof(int), 1, car);

    printf("Identificacao: %d\n", carro.id);
    printf("Placa: %s\n", carro.placa);
    printf("Modelo: %s\n", carro.modelo);
    printf("Motor: %f\n", carro.motor);
    printf("Tem ar: ");
    if (carro.ar == 1) {
        printf("sim.\n");
    }
    else {
        printf("nao.\n");
    }
    printf("Cor: %s\n", carro.cor);
    printf("Ano: %d\n", carro.ano);
    printf("Quilometragem: %d\n", carro.kilo);
    printf("Valor da diaria: %f\n", carro.diaria);
    printf("Disponibilidade: ");
    if(carro.dispo == 1){
        printf("disponivel\n");
    }
    else{
        printf("Indisponivel\n");
    }



    system("pause");
}

void attCarro(){
    Carros carro;
    int id;
    int c;
    c = getchar();
    printf("Entre com a identificação do carro que você deseja atualizar: \n");
    scanf("%d", &id);

    FILE *car = fopen("Carros.dat", "rb");
    //tentando fazer encontrar um carro específico, estudar FSEEK.
    while(c == EOF) {
        fread(&carro.id, sizeof(int), 1, car);
        if (id == carro.id) {
            printf("achei!");
        } else
            printf("nao achei");
    }
    fclose(car);

}