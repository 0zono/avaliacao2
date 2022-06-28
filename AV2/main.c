#include <stdio.h>
#include "menus.c"
#include  <windows.h>

int main() {
    SetConsoleOutputCP(65001); //permitir a inclusão de caracteres especiais no console.
    menu();
    return 0;
}
