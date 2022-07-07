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

//esta função adiciona carros no fim do arquivo.
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
    fwrite(&carro, sizeof(Carros), 1, car); //escreve o registro no arquivo

    fflush(car);
    printf("Deseja adicionar mais um carro a lista de automóveis? (s/n): \n");
    scanf(" %c", &dnv);
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
//esta função imprime todos os carros no arquivo.
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
            printf("Disponibilidade: Disponível\n\n");
        }
        else{
            printf("Disponibilidade: Indisponível\n\n");
        }
    }
    system("pause");
    fclose(fp);
}
//esse arquivo busca um carro pelo seu ID
void mostraCarro() {
    system("cls");
    Carros carro;
    char op;
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
    size = ftell(fp);//a variável size recebe o tamanho do arquivo
    if(size == -1) {
        printf("Não há registros\n");
        return;
    }
    if(fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Carros); //divide o arquivo em secções por registro
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
            if (carro.dispo == 1){
                printf("Disponibilidade: Disponível\n");
            }
            else{
                printf("Disponibilidade: Indisponível\n");
            }
            break;
        }
    }
    printf("Deseja buscar outro carro? (s/n) \n");
    scanf(" %c", &op);
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
//essa função atualiza os dados de um carro, usando uma lógica similar a mostraCarro para identifica-lo
void updateCarro() {
    system("cls");
    FILE *fp = fopen("Carros.dat", "r+b"); //abrindo em r+b para ler e escrever no arquivo
    Carros carro;
    char op;
    int id, size, count, records;
    printf("entre com a indentificação do carro a ser atualizado: \n");
    scanf("%d", &id);

    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o arquivo\n");
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

            fseek(fp, -(int)sizeof(Carros), SEEK_CUR); //posiciona o ponteiro no início do registro
            fwrite(&carro, sizeof(Carros), 1, fp); //reescreve o registro com os novos dados
            break;
        }
    }
    fflush(fp);
    printf("Deseja atualizar mais um carro?(s/S=Sim) \n");
    scanf(" %c", &op);
    if (op != 's' && op != 'S'){
        fclose(fp);
        menu();

    }
    else{
        fclose(fp);
        updateCarro();
    }
}
//função que busca o carros por modelo, ou por motor(o float do motor)
void searchCarro(){
    Carros carro;
    FILE *fp = fopen("Carros.dat", "rb");
    char modelo[10];
    float motor;
    int op;
    size_t count, records;
    long size;
    printf("1: buscar por modelo\n2:buscar por motor \n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("Insira o modelo do carro a ser buscado: \n");
            scanf("%s", &modelo);
            //checa a existência do arquivo e do registro
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
        case 2:
            printf("Insira o modelo do carro a ser buscado: \n");
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
    fclose(fp);
    printf("Deseja buscar mais um carro?(s/S=Sim) \n");
    scanf(" %c", &op);
    if (op == 'S' || op == 's'){
        system("cls");
        searchCarro();
    }
    else{
        system("cls");
        menu();
    }
}

//Função para adicionar um cliente ao arquivo "Clientes.dat".
void addCliente(){
    system("cls"); //Limpa a tela do programa.
    Clientes cliente;
    char op;
    FILE *fp = fopen("Clientes.dat", "ab");
    //*Cria o arquivo binário "Clientes.dat". Se ele já existir, então apenas abre em modo de escrita.

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
    printf("Deseja adicionar mais um cliente?(s/S=Sim) \n");
    scanf(" %c", &op);
    //Operação de verificação da resposta do usuário para adicionar ou não outro cliente.
    if (op == 'S' || op == 's'){//Fecha o arquivo e inicia a função novamente para adicionar outro cliente.
        fclose(fp);
        addCliente();

    }
    else{//Fecha o arquivo e retorna ao menu anterior (principal).
        fclose(fp);
        menu();
    }
    fclose(fp);//Usado para garantir que o arquivo feche em caso de erros.
}

//Função feita para atualizar o cadastro de um cliente já existente no sistema.
void updateCliente() {
    system("cls"); //Limpa a tela do programa.
    FILE *fp = fopen("Clientes.dat", "r+b"); //Abre o arquivo com o modo de leitura e escrita em binário.
    Clientes cli;
    int size, count, records;//Variáveis para manipular o tamanho do arquivo e os laços da estrutura de repetição FOR.
    char cpf[13], dnv;
    printf("Entre com o cpf do cadastro a ser atualizado: \n"); //Solicita o CPF do cliente.
    scanf("%s", cpf);
    getchar();

    //Sequência de 3 if's para verificar se há registros ou não no arquivo.
    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("Erro ao localizar o arquivo\n");
        return;
    }
    size = ftell(fp); //Define o tamanho do arquivo atribuindo o tamanho do arquivo "fp" para a variável inteira "size".
    if (size == -1) {
        printf("Não há registros\n");
        return;
    }
    if (fseek(fp, 0, SEEK_SET) == -1) {
        printf("Erro ao localizar o registro\n");
        return;
    }
    records = size / sizeof(Clientes); //Atribui a "records" o tamanho do arquivo baseado na Struct "Clientes".
    for (count = 0; count < records; count++) {//Laço FOR para buscar o cliente por CPF para atualizá-lo.
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
            //Coloca o ponteiro no início do struct para que a função não grave os arquivos no local errado.
            fseek(fp, -(int)sizeof(Clientes), SEEK_CUR);
            fwrite(&cli, sizeof(Clientes), 1, fp); //Escreve todos os dados no arquivo.
            break;
        }
    }
    fflush(fp);//Garante que as informações sejam gravadas no arquivo.
    printf("Deseja atualizar outro cliente? s=Sim/n=Não (Voltar ao menu anterior)\n");
    scanf(" %c", &dnv);
    //Operação de verificação da resposta do usuário para atualizar ou não outro cliente.
    if (dnv == 'S' || dnv == 's'){//Fecha o arquivo e inicia a função novamente para atualizar outro cliente.
        fclose(fp);
        updateCliente();
    }
    else{//Fecha o arquivo e retorna ao menu anterior (principal).
        fclose(fp);
        menu();
    }
    fclose(fp);//Usado para garantir que o arquivo feche em caso de erros.
}

//Função feita para buscar um cliente já existente no sistema e mostrar seus dados cadastrais.
void mostraCliente(){
    system("cls");//Limpa a tela do programa.
    FILE *fp = fopen("Clientes.dat", "rb");//Abre o arquivo "Clientes.dat" em modo de leitura.
    Clientes cli;
    char cpf[13];
    printf("Digite o CPF do cliente a ser encontrado: \n");
    scanf(" %s", cpf);
    getchar();
    int size, count, records;//Variáveis para manipular o tamanho do arquivo e os laços da estrutura de repetição FOR.

    //Sequência de 3 if's para verificar se há registros ou não no arquivo.
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
    records = size / sizeof(Clientes);//Atribui a "records" o tamanho do arquivo baseado na Struct "Clientes".
    for (count = 0; count < records; count++) {//Laço FOR que imprime os dados cadastrais do cliente registrado com o CPF específico.
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
            //Coloca o ponteiro no início do struct para que a função não grave os arquivos no local errado.
            break;//Rompe o laço, já que o cliente foi encontrado.
        }
    }
    fclose(fp);//Fecha o arquivo.
    printf("Deseja buscar outro cliente? s=Sim/n=Não (Voltar ao menu anterior)\n");//Questiona o usuário se quer cadastrar outro cliente.
    char dnv;
    scanf(" %c", &dnv);
    if (dnv == 'S' || dnv == 's'){//Resposta Positiva: Fecha o arquivo e reinicia a função.
        fclose(fp);
        mostraCliente();
    }
    else{//Resposta Negativa: Fecha o arquivo e retorna ao menu anterior (principal).
        fclose(fp);
        menu();
    }
}

//Função para listar todos os clientes do arquivo "Clientes.dat".
void tdsClientes(){
    system("cls");//Limpa a tela.
    FILE *fp = fopen("Clientes.dat", "rb");//Abre o arquivo "Clientes.dat" em modo de leitura.
    Clientes cli;
    char dnv;
    while(fread(&cli, sizeof(Clientes), 1, fp)){
        //Laço WHILE para listar todos os clientes cadastrados no arquivo "Clientes.dat".
        printf("CPF: %s\n", cli.cpf);
        printf("Idade: %d\n", cli.idade);
        printf("Nome: %s\n", cli.nome);
        printf("Endereço: %s\n", cli.endereco);
        printf("Estado: %s\n", cli.estado);
        printf("Cidade: %s\n", cli.cidade);
        printf("Pontos: %d\n\n", cli.pontos);
    }
    fclose(fp);//Fecha o arquivo.
    printf("Deseja voltar ao menu principal? s=Sim/n=Não(irá fechar o programa.)\n");
    scanf(" %c", &dnv);
    if (dnv == 'S' || dnv == 's'){//Fecha o arquivo e volta ao menu principal.
        fclose(fp);
        menu();
    }
    else{//Fecha o arquivo e encerra o programa.
        fclose(fp);
    }
}

//Função para listar todos os clientes na faixa de 18 a 25 anos de idade.
void showIdade(){
    system("cls");//Limpa a tela do programa.
    FILE *fp = fopen("Clientes.dat", "rb");//Abre um arquivo binário em modo de leitura.
    Clientes cli;
    int size, count, records, aux = 0;

    //Sequência de 3 if's para verificar erros ou inexistência do registro.
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
        //Laço FOR para fazer a verificação e mostrar quais clientes estão na faixa requerida no printf acima.
        fread(&cli, sizeof(Clientes), 1, fp);
        if ((cli.idade >= 18) && (cli.idade <= 25)) {
            aux++;//Adição unária à variável "aux" para uso no if posterior
            printf("CPF do cliente: %s \n", cli.cpf);
            printf("Idade do cliente: %d\n ", cli.idade);
            printf("Nome do cliente: %s \n", cli.nome);
            printf("Endereço do cliente: %s \n", cli.endereco);
            printf("Estado de moradia do cliente: %s \n", cli.estado);
            printf("Cidade de moradia do cliente: %s \n", cli.cidade);
            printf("Pontos que o cliente tem: %d \n\n", cli.pontos);
            //Coloca o ponteiro no início do struct para que a função não grave os arquivos no local errado.
            fseek(fp, -(int) sizeof(Clientes), SEEK_CUR);
            break;//Finaliza o if.
        }
    }
    fclose(fp);//Fecha o arquivo
    if (aux == 0){//Verifica se o laço FOR for detectado detectou algum cliente na faixa de idade. Se não detectou, então exibe a mensagem abaixo.
        printf("Não foram encontrados nos registros clientes nessa faixa de idade.\n\n");
    }
    system("pause");//Pausa a execução do programa para que se possam ver os resultados da ação anterior.
}

//Função para mostrar os clientes com + de 200 pontos.
void showPontos(){
    system("cls");//Limpa a tela.
    FILE *fp = fopen("Clientes.dat", "rb");//Abre um arquivo binário no modo de leitura.
    Clientes cli;
    int size, records, aux = 0;

    //Sequência de 3 if's para verificar erros ou inexistência do registro.
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
    for (int cont = 0; cont < records; cont++) {//Laço FOR para exibir todos os clientes com + de 200 pontos.
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

            fseek(fp, -(int) sizeof(Clientes), SEEK_CUR);//*
            // Coloca o ponteiro no início do struct para que a função não grave os arquivos no local errado.*
            break;//Finaliza o if.
        }
    }
    if(aux == 0){//*Verifica se o laço FOR for detectado detectou algum cliente na faixa de idade.
        // Se não detectou, então exibe a mensagem abaixo.*
        printf("Não há nenhum cliente com + de 200 pontos. \n\n");
    }
    fclose(fp);//Fecha o arquivo.
    system("pause");//Pausa o sistema para que possam ser vistos os clientes.
}
