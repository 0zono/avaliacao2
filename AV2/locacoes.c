#include <stdio.h>
#include "regs.h"
#include <string.h>
#include "menus.h"
void loca();
void devolucao();



void loca(){
    FILE *car = fopen("Carros.dat", "rb");
    FILE *cli = fopen("Clientes.dat", "rb");
    FILE *loc = fopen("Locacoes.dat", "ab");
    int idcarro, idcli, kiloinicial, kilofinal, idloca;
    float valor;
    char placa[8], cpflocatario[13];



    fwrite(&loc, sizeof(Locacoes), 1, loc);

};
