#include <stdio.h>
#include "regs.h"
#include <string.h>
#include "menus.h"
void loca();
void mostraLocacao();
void devolucao();


void loca() {
    FILE *car = fopen("Carros.dat", "rb+");
    FILE *cli = fopen("Clientes.dat", "rb+");
    FILE *loc = fopen("Locacoes.dat", "ab");
    int idcarro;
    char cpf[13];
    size_t count, records;
    long size;
    Carros carro;
    Locacoes lc;
    Clientes cliente;
    printf("Digite seu CPF: ");
    scanf("%s", cpf);
    fseek(cli, 0, SEEK_END);
    size = ftell(cli);
    records = size / sizeof(Clientes);
    fseek(cli, 0, SEEK_SET);
    for (int i = 0; i < records; i++) {
        fread(&cliente, sizeof(Clientes), 1, cli);
        if (strcmp(cliente.cpf, cpf) == 0) {
            printf("Digite o ID do carro: ");
            scanf("%d", &idcarro);
            fseek(car, 0, SEEK_END);
            size = ftell(car);
            records = size / sizeof(Carros);
            fseek(car, 0, SEEK_SET);
            for (int i = 0; i < records; i++) {
                fread(&carro, sizeof(Carros), 1, car);
                if (carro.id == idcarro) {
                    if (carro.dispo == 0) {
                        printf("Carro indisponível.\n");
                        system("pause");
                        break;
                    } else {
                        printf("Digite a identificação da locação: ");
                        scanf("%d", &lc.idloca);
                        lc.idcarro = carro.id;
                        strcpy(lc.cpflocatario, cpf);
                        lc.kiloinicial = carro.kilo;
                        lc.fina = 0;
                        printf("Digite a data de início da locação: ");
                        printf("Dia: ");
                        scanf("%d", &lc.inicio.dia);
                        printf("Mês: ");
                        scanf("%d", &lc.inicio.mes);
                        printf("Ano: ");
                        scanf("%d", &lc.inicio.ano);
                        printf("Hora: ");
                        scanf("%d", &lc.inicio.hora);
                        lc.valor = carro.diaria;
                        fwrite(&lc, sizeof(Locacoes), 1, loc);
                        carro.dispo = 0;
                        fseek(car, -(int)sizeof(Carros), SEEK_CUR);
                        fwrite(&carro, sizeof(Carros), 1, car);
                        printf("Locacao efetuada com sucesso.\n");
                        break;
                    }
                }
            }
        }
    }
    fclose(car);
    fclose(cli);
    fclose(loc);
}

void mostraLocacao(){
    FILE *loc = fopen("Locacoes.dat", "rb");
    Locacoes lc;
    size_t count, records;
    long size;
    fseek(loc, 0, SEEK_END);
    size = ftell(loc);
    records = size / sizeof(Locacoes);
    fseek(loc, 0, SEEK_SET);
    for(count = 0; count < records; count++) {
        fread(&lc, sizeof(Locacoes), 1, loc);
        printf("ID da locacao: %d\n", lc.idloca);
        printf("ID do carro: %d\n", lc.idcarro);
        printf("CPF do locatario: %s\n", lc.cpflocatario);
        printf("Kilometragem inicial: %d\n", lc.kiloinicial);
        printf("Kilometragem final: %d\n", lc.kilofinal);
        printf("Data de inicio: %d/%d/%d\n", lc.inicio.dia, lc.inicio.mes, lc.inicio.ano);
        printf("Hora de inicio: %d\n", lc.inicio.hora);
        if(lc.fina == 1){
            printf("Data de devolucao: %d/%d/%d\n", lc.devolucao.dia, lc.devolucao.mes, lc.devolucao.ano);
            printf("Hora de devolucao: %d\n", lc.devolucao.hora);
            printf("Valor final da locacao: %.2f\n\n", lc.valor);
        }
        else{
            printf("Locacao em andamento.\n\n");
        }
    }
    system("pause");
}

void devolucao() {
    FILE *loc = fopen("Locacoes.dat", "rb+");
    FILE *car = fopen("Carros.dat", "rb+");
    FILE *cli = fopen("Clientes.dat", "rb+");
    Locacoes lc;
    Carros carro;
    Clientes cliente;
    int mes[12] = {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, };
    int ano = 365;
    int dias;
    int pontos;
    int idloca;
    printf("Digite a identificacao da locacao: ");
    scanf("%d", &idloca);
    fseek(loc, 0, SEEK_END);
    size_t count, records;
    long size;
    size = ftell(loc);
    records = size / sizeof(Locacoes);
    fseek(loc, 0, SEEK_SET);
    for(count = 0; count < records; count++) {
        fread(&lc, sizeof(Locacoes), 1, loc);
        if (lc.idloca == idloca) {
            printf("Digite a quilometragem final: ");
            scanf("%d", &lc.kilofinal);
            printf("Digite a data de devolucao: \n");
            printf("Dia: ");
            scanf("%d", &lc.devolucao.dia);
            printf("Mês: ");
            scanf("%d", &lc.devolucao.mes);
            printf("Ano: ");
            scanf("%d", &lc.devolucao.ano);
            printf("Hora: ");
            scanf("%d", &lc.devolucao.hora);
            dias = ((lc.devolucao.ano-lc.inicio.ano)*ano) + (mes[lc.devolucao.mes-1]+lc.devolucao.dia)-(mes[lc.inicio.mes-1]+lc.inicio.dia);
            lc.valor = lc.valor * dias;
            pontos = (int)lc.valor;
            lc.fina = 1;
            fseek(loc, -(int)sizeof(Locacoes), SEEK_CUR);
            fwrite(&lc, sizeof(Locacoes), 1, loc);
            fseek(car, 0, SEEK_END);
            size = ftell(car);
            records = size / sizeof(Carros);
            fseek(car, 0, SEEK_SET);
            for (int i = 0; i < records; i++) {
                fread(&carro, sizeof(Carros), 1, car);
                if (carro.id == lc.idcarro) {
                    carro.dispo = 1;
                    fseek(car, -(int)sizeof(Carros), SEEK_CUR);
                    fwrite(&carro, sizeof(Carros), 1, car);
                    break;
                }
            }
            fseek(cli, 0, SEEK_END);
            size = ftell(cli);
            records = size / sizeof(Clientes);
            fseek(cli, 0, SEEK_SET);
            for (int i = 0; i < records; i++) {
                fread(&cliente, sizeof(Clientes), 1, cli);
                if (strcmp(cliente.cpf, lc.cpflocatario) == 0) {
                    cliente.pontos = pontos;
                    fseek(cli, -(int)sizeof(Clientes), SEEK_CUR);
                    fwrite(&cliente, sizeof(Clientes), 1, cli);
                    break;
                }
            }

            fclose(car);
            fclose(cli);
            fclose(loc);
            break;
        }
    }
}
