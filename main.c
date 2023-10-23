/*Aluno : Gabriel Marçal Pereira Leal - Exericio 2
  Professor : Alexandre*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <conio.h>

//--------------------------------------------------------------
//---------------------- STRUCTS -------------------------------
//--------------------------------------------------------------
typedef struct pessoa{
    char nome_pessoa[30];
    char pessoa_cpf[10];
    int opcao;
    int st;
    char pagamento[10]
}pessoa;
//--------------------------------------------------------------
typedef struct Tfila{
    pessoa dados;
    struct Tfila* prox;
}Tfila;
//--------------------------------------------------------------
typedef struct fila{
    Tfila* inicio;
    Tfila* fim;
}fila;
//---------------------------------------------------------------
typedef struct Tpilha{
  char nome[30];
  char cpf[10];
  int opcaao;
  char pagamento[30];
  struct Tpilha *ant;
}Tpilha;
//---------------------------------------------------------------
typedef struct pilha{
   Tpilha *topo;
}pilha;

//--------------------------------------------------------------
//---------------------- FUNÇÕES -------------------------------
//--------------------------------------------------------------
void create_fila(fila* f){
    f->inicio = NULL;
    f->fim = NULL;
}
//--------------------------------------------------------------
void create_pilha(pilha *p){
  p->topo =NULL;
}
//--------------------------------------------------------------

int fila_vazia(fila* f){
    if(f->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}
//-------------------------------------------------------------
int pilha_vazia(pilha *p){

   if(p->topo ==NULL){
    return 1; //Pilha está vazia
   }else{
    return 0; //pilha tem elementos
   }
}
//-------------------------------------------------------------
void inserir_fila(fila* f, pessoa *dados){

    Tfila *novo = malloc(sizeof(Tfila));

    novo->dados = *dados;
    novo->prox = NULL;

    if(fila_vazia(f)){
        f->inicio = novo;
        f->fim = novo;

        novo = NULL;
        free(novo);
    }else{
        f->fim->prox = novo;
        f->fim = novo;

        novo = NULL;
        free(novo);
    }
}
//-------------------------------------------------------------
void remove_fila_vazia(fila* f){

    Tfila* aux=(Tfila*)malloc(sizeof(Tfila));
    aux = f->inicio;

    if(aux ->dados.opcao == 1)
        {
            printf("\n\t ----- Atendimeto realizado -----");
            printf("\n\t  ----- Relatorio -----");
            printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
            printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
            printf("\n\t Item de escolha do cliente : Bateria de relogio");
            printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
            printf("\n\t Status : Realizado, o pedido sera retirado da lista...\t");
        }
    else if(aux->dados.opcao == 2)
    {
        printf("\n\t ----- Atendimeto realizado -----");
        printf("\n\t  ----- Relatorio -----");
        printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
        printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
        printf("\n\t Item de escolha do cliente : Bateria de controle");
        printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
        printf("\n\t Status : Realizado, o pedido sera retirado da lista...\t");
    }

    else if(aux -> dados.opcao == 3)
    {
        printf("\n\t ----- Atendimeto realizado -----");
        printf("\n\t  ----- Relatorio -----");
        printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
        printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
        printf("\n\t Item de escolha do cliente : HD");
        printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
        printf("\n\t Status : Realizado, o pedido sera retirado da lista\t");
    }

    f->inicio = aux->prox;
    aux->prox = NULL;

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(aux);
    printf("\n\n\tPressione qualquer tecla para continuar...");
    getch();
}
//-------------------------------------------------------------
pessoa remove_fila_normal(fila* f){
    Tfila* aux=(Tfila*)malloc(sizeof(Tfila));
    aux = f->inicio;

    pessoa ddv;

    ddv = aux->dados;

    if(aux->dados.opcao == 1)
    {
        printf("\n\tErro, Produto do cliente indisponivel no estoque...");
        printf("\n\tEmpilhando para quando estiver disponivel");
        printf("e logo o relatorio sera gerado, Aguarde...");
        printf("\n\n\t ----- Atendimeto realizado -----");
        printf("\n\t  ----- Relatorio -----");
        printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
        printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
        printf("\n\t Item de escolha do cliente : Bateria de relogio");
        printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
        printf("\n\t Status : Venda nao realizada, falta da peca\t");
        printf("\n\t Esse pedido estara empilhado pela ordem de chegada");
        printf(" e voce podera visualizar ele escolhendo a opcao 5 no menu...\n");
    }
    else if(aux->dados.opcao == 2)
    {
        printf("\n\tErro, Produto do cliente indisponivel no estoque...");
        printf("\nEmpilhando para quando estiver disponivel e logo o relatorio sera gerado...");
        printf("\n\n\t ----- Atendimeto realizado -----");
        printf("\n\t  ----- Relatorio -----");
        printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
        printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
        printf("\n\t Item de escolha do cliente : Bateria de controle");
        printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
        printf("\n\t Status : Venda nao realizada, falta da peca\t");
        printf("\n\t Esse pedido estara empilhado pela ordem de chegada");
        printf(" e voce podera visualizar ele escolhendo a opcao 5 no menu...\n");
    }
    else if(aux -> dados.opcao == 3)
    {
        printf("\n\tErro, Produto do cliente indisponivel no estoque...");
        printf("\nEmpilhando para quando estiver disponivel e logo o relatorio sera gerado...");
        printf("\n\n\t ----- Atendimeto realizado -----");
        printf("\n\t  ----- Relatorio -----");
        printf("\n\t Nome do Cliente : %s",aux->dados.nome_pessoa);
        printf("\n\t CPF do Cliente : %s",aux->dados.pessoa_cpf);
        printf("\n\t Item de escolha do cliente : HD");
        printf("\n\t Forma de pagamento : %s",aux->dados.pagamento);
        printf("\n\t Status : Venda nao realizada, falta da peca\t");
        printf("\n\t Esse pedido estara empilhado pela ordem de chegada");
        printf(" e voce podera visualizar ele escolhendo a opcao 5 no menu...\n");
    }

    f->inicio = aux->prox;
    aux->prox = NULL;

    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(aux);
    printf("\n\n\tPressione qualquer tecla para continuar...");
    getch();
    return(ddv);
}

//-------------------------------------------------------------
void mostrar_fila(fila* f){
    Tfila* aux = malloc(sizeof(Tfila));
    aux = f->inicio;

    printf("\n\n\t Todas as pessoas na fila de espera\n\t");

    if(fila_vazia(f) == 1){
        printf("\n\t Fila Vazia!!!");
    }else{
        while(aux != NULL){
            if(aux->dados.opcao == 1)
                printf(" | Nome da pessoa: %s  -  cpf  %s  - Pedido : Bateria de relogio - Forma de pagamento %s| \n\t", aux->dados.nome_pessoa, aux->dados.pessoa_cpf, aux->dados.pagamento);
            else if(aux->dados.opcao == 2)
                printf(" | Nome da pessoa: %s  -  cpf  %s  - Pedido : Bateria de controle - Forma de pagamento %s| \n\t", aux->dados.nome_pessoa, aux->dados.pessoa_cpf, aux->dados.pagamento);
            else if(aux->dados.opcao == 3)
                printf(" | Nome da pessoa: %s  -  cpf  %s  - Pedido : HD - Forma de pagamento %s \n\t", aux->dados.nome_pessoa, aux->dados.pessoa_cpf, aux->dados.pagamento);

            aux = aux->prox;
            }

    printf("\n\n\t Pressione qualquer tecla para continuar...");
    getch();

    free(aux);
    }
}
//-------------------------------------------------------------
void ordenacao(pilha *p, pessoa exc)
{
    Tpilha* novo = (Tpilha*)malloc(sizeof(Tpilha));
    strcpy(novo->nome,exc.nome_pessoa);
    strcpy(novo->cpf,exc.pessoa_cpf);
    novo->opcaao = exc.opcao;
    strcpy(novo->pagamento, exc.pagamento);
    novo->ant = NULL;

    if (p->topo == NULL) {
        p->topo = novo;
    } else{
        Tpilha* generico = p->topo;
        while (generico->ant != NULL){
            generico = generico->ant;
        }
        generico->ant = novo;
    }
}
//----------------------------------------------------------------
void mostrar(pilha *p){

  Tpilha *aux;
  aux = p->topo;

  while(aux !=NULL){
    if(aux->opcaao == 1)
    {
        printf("\n\tNome : %s",aux->nome);
        printf("\n\tCpf : %s",aux->cpf);
        printf("\n\tPeca escolhida : Bateria de relogio");
        printf("\n\tForma de pagamento escolhida : %s\n\n",aux->pagamento);
    }
    else if(aux->opcaao == 2)
    {
        printf("\n\tNome : %s",aux->nome);
        printf("\n\tCpf : %s",aux->cpf);
        printf("\n\tPeca escolhida : Bateria de controle");
        printf("\n\tForma de pagamento escolhida : %s\n\n",aux->pagamento);
    }
    else if(aux->opcaao == 3)
    {
        printf("\n\tNome : %s",aux->nome);
        printf("\n\tCpf : %s",aux->cpf);
        printf("\n\tPeca escolhida : HD");
        printf("\n\tForma de pagamento escolhida : %s\n\n",aux->pagamento);
    }
    aux=aux->ant;
  }
  printf("\n\n\tAperte alguma tecla para continuar...");
  getch();
}
//--------------------------------------------------------------
void pss_s(fila* f){


    if(f->inicio == NULL){
       printf("\n\t Fila de espera vazia, parabens por ser um otimo atendente!!");
    }else{
        if(f->inicio->dados.opcao == 1)
        {
            printf("\n\n\t Nome da pessoa: %s", f->inicio->dados.nome_pessoa);
            printf("\n\t Cpf da pessoa: %s", f->inicio->dados.pessoa_cpf);
            printf("\n\t Item de escolha da pessoa : Bateria para relogio");
            printf("\n\t Forma de pagamento : %s",f->inicio->dados.pagamento);
        }
        else if(f->inicio->dados.opcao == 2)
        {
            printf("\n\n\t Nome da pessoa: %s", f->inicio->dados.nome_pessoa);
            printf("\n\t Cpf da pessoa: %s", f->inicio->dados.pessoa_cpf);
            printf("\n\t Item de escolha da pessoa : Bateria para controle");
            printf("\n\t Forma de pagamento : %s",f->inicio->dados.pagamento);
        }
        if(f->inicio->dados.opcao == 3)
        {
            printf("\n\n\t Nome da pessoa: %s", f->inicio->dados.nome_pessoa);
            printf("\n\t Cpf da pessoa: %s", f->inicio->dados.pessoa_cpf);
            printf("\n\t Item de escolha da pessoa : Hd");
            printf("\n\t Forma de pagamento : %s",f->inicio->dados.pagamento);
        }
    }

    printf("\n\n\t Pressione qualquer tecla para continuar...");
    getch();
}

//-------------------------------------------------------------
void menu(){

    int bateria_rel = 0, bateria_cont = 0, hd = 0;

    printf("Digite a quantidade de baterias de relogio que voce deseja armazenar no estoque... : ");
    fflush(stdin);
    scanf("%d",&bateria_rel);

    printf("Digite a quantidade de baterias de controle que voce deseja armazenar no estoque... : ");
    fflush(stdin);
    scanf("%d",&bateria_cont);

    printf("Digite a quantidade de HDs que voce deseja armazenar no estoque... : ");
    fflush(stdin);
    scanf("%d",&hd);

    fila *f = (fila*)malloc(sizeof(fila));
    create_fila(f);

    Tfila *dados_pessoa = malloc(sizeof(Tfila));
    dados_pessoa = f->inicio;

    pilha*p = malloc(sizeof(pilha));
    create_pilha(p);

    pessoa *comum_pessoa = malloc(sizeof(pessoa));

    Tfila *aux2 = malloc(sizeof(Tfila));

    pessoa exc;

    int opc=0;
    int cont=0;

    do{
        system("cls");
        printf("\n\t------- Atendimento -----\n\t----\n\t");
        printf("\n\t Numero de pessoas na espera:  %d", cont);
        printf("\n\n\t");
        printf("[1] - Adicionar pessoa e pedido \n\t");
        printf("[2] - Atendimento ou empilhamento em caso de falta da peca\n\t");
        printf("[3] - Listar todas as pessoas na espera \n\t");
        printf("[4] - Exibir dados da primeira pessoa na espera\n\t");
        printf("[5] - Exibir a pilha de pessoas em aguardo para pecas\n\t");
        printf("[6] - Reabastecer o estoque de pecas\n\t");
        printf("[7] - SAIR\n\n\t");

        do{
            printf("Informe a opcao...>>  ");
            scanf("%d", &opc);
            if(opc < 1 || opc > 7){
                printf("\n\t OPCAO INVALIDA....");
            }

        }while(opc < 1 || opc > 7);


        switch(opc){

            case 1:{
                printf("\n\tQUANTIDADE DE BATERIAS DE RELOGIOS DISPONIVEIS NO ESTOQUE %d",bateria_rel);
                printf("\n\tQUANTIDADE DE BATERIAS DE CONTROLE DISPONIVEIS NO ESTOQUE %d",bateria_cont);
                printf("\n\tQUANTIDADE DE HDs DISPONIVEIS NO ESTOQUE %d",hd);
                printf("\n\n");
                printf("\n\t ---- INSERIR PESSOA ------");
                printf("\n\n\t Digite o nome da pessoa...: ");
                fflush(stdin);
                gets(comum_pessoa->nome_pessoa);
                printf("\n\t Digite o cpf da pessoa...:  ");
                gets(comum_pessoa->pessoa_cpf);
                printf("\n\t Digite de 1 a 3 as opcoes que a pessoa deseja... : ");
                fflush(stdin);
                scanf("%d",&comum_pessoa->opcao);

                if(comum_pessoa->opcao == 1)
                {
                    if(bateria_rel > 0)
                    {
                        comum_pessoa->st = 1;
                        bateria_rel = bateria_rel - 1;
                    }
                    else
                    {
                        comum_pessoa->st = 0;
                    }
                }
                else if(comum_pessoa->opcao == 2)
                {
                    if(bateria_cont > 0)
                    {
                        comum_pessoa->st = 1;
                        bateria_rel = bateria_rel - 1;
                    }
                    else
                        comum_pessoa->st = 0;
                }

                else if(comum_pessoa->opcao == 3 && hd > 0)
                {
                    if(hd > 0)
                    {
                        comum_pessoa->st = 1;
                        hd = hd - 1;
                    }
                    else
                        comum_pessoa->st = 0;
                }

                printf("\n\t Digite a forma de pagamento (Cartao, Dinheiro, Pix, Paypal)... : ");
                fflush(stdin);
                gets(comum_pessoa->pagamento);

                inserir_fila(f, comum_pessoa);
                    cont++;

                break;
            }

            case 2:{
                aux2 = f->inicio;

                if(fila_vazia(f)){
                    printf("\n\n\t IMPOSSIVEL ATENDIMENTO OU EMPILHAR!!!");

                }
                else{
                    if(aux2->dados.st == 1)
                    {
                        remove_fila_vazia(f);
                    }
                    else if(aux2->dados.st == 0)
                    {
                        exc = remove_fila_normal(f);
                        ordenacao(p,exc);
                    }
                }
                aux2 = NULL;
                free(aux2);

                    cont--;
                    if(cont < 0)
                    {
                        cont = cont + 1;
                    }
                break;
            }

            case 3:{
                mostrar_fila(f);

                break;

            }

            case 4:{

                pss_s(f);

                break;

            }

            case 5:{
                mostrar(p);
                break;
            }
            case 6:{
            printf("\n\t ----- Reabastecimento de estoque ------\t\n");
            printf("\n\tDigite o numero de pecas atuais de baterias de relogio... : ");
            fflush(stdin);
            scanf("%i",&bateria_rel);
            printf("\n\tDigite o numero de pecas atuais de baterias de controle...: ");
            fflush(stdin);
            scanf("%i",&bateria_cont);
            printf("\n\tDigite o numero atual de HDs... : ");
            fflush(stdin);
            scanf("%i",&hd);
            break;
        }
        }


    }while(opc != 7);

    printf("\n\n\t FINALIZANDO PROGRAMA....");
}

//--------------------------------------------------------------
//--------------------- CODIGO PRINCIPAL -----------------------
//--------------------------------------------------------------
int main(void){
    menu();

    return 0;
}
