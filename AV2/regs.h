//
// Created by Sapozono on 6/19/2022.
//

#ifndef AV2_REGS_H
#define AV2_REGS_H

#include <stdbool.h>
typedef struct {
    char cpf[13];
    int idade;
    char nome[50];
    char endereco[50];
    char estado[3];
    char cidade[50];
    int pontos;
} Clientes;

typedef struct {
    int id;
    char placa[8];
    char modelo[10];
    float motor;
    int ar;
    char cor[6];
    int ano;
    int kilo;
    float diaria;
    int dispo;
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
    char cpflocatario[13];
    int kiloinicial;
    int kilofinal;
    float valor;
    date inicio;
    date devolucao;
    int fina;
}Locacoes;
#endif //AV2_REGS_H
