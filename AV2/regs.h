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
    char estado[2];
    char cidade[50];
    int pontos;
} Clientes;

typedef struct {
    int id;
    char modelo[10];
    char cor[6];
    int ano;
    char placa[8];
    int ar;
    int kilo;
    float diaria;
    int dispo;
    float motor;
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
    int cpflocatario;
    int kiloinicial;
    int kilofinal;
    float valor;
    date inicio;
    date devolucao;
}Locacoes;
#endif //AV2_REGS_H
