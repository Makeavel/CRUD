//   ------ CRUD usando Lista Ligada  -------    //
#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    char palavra;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

lista * aloca_lista(){
    lista * nov;
    nov = (lista*)malloc(sizeof(lista));
    nov->qtd= 0;
    nov -> inicio = NULL;
    nov -> fim = NULL;
    return nov;
}

elemento * aloca_elemento(){
    elemento * obw;
    obw = (elemento*)malloc(sizeof(elemento));
    obw -> valor = 0;
    obw->palavra = NULL;
    obw->ant = NULL;
    obw->prox=NULL;
    return obw;
}

void InserirFimListaLigada(lista * l1, int x){
    elemento * aux , * novo;
    novo = aloca_elemento();
    novo -> valor = x;
    if(l1->inicio == NULL){
        l1->inicio = novo;
    }
    else{
        aux = l1->inicio;
        while(aux->prox!= NULL){
            aux = aux-> prox;
        }
        aux-> prox = novo;
    }
    l1->qtd++;
}

void InserirInicioListaLigada(lista * l1 , int x){
    elemento * aux , * novo;
    novo = aloca_elemento();
    novo-> valor = x;
    if(l1->inicio == NULL){
        l1->inicio = novo;
    }
    else{
        aux = l1->inicio;
        l1->inicio = novo;
        novo->prox = aux;
    }
    l1->qtd++;
}

void MostrarLigada(lista * l1){
    elemento * aux;
    if(l1->inicio == NULL){
        printf("\nLista Vazia");
    }
    else{
        aux = l1->inicio;
        while(aux != NULL){
            
            printf(" %d", aux -> valor);
            aux = aux->prox;
        }
    }
}

void buscar_lista(lista * l1 , int x){
    elemento * ant , * aux ;

    if(l1->inicio == NULL){
        printf("\nLista Vazia\n");
    }
    else{
        aux = l1->inicio;
        ant = aux;
        while(aux -> valor != x ){
            
            ant = aux;
            aux = aux-> prox;
            
            }
        }
        if(aux-> valor != x ){
            printf("\nValor não encontrado");
        }       
        else{
            printf("\nValor selecionado: %d", x);
            
                if(ant->valor == aux->valor){
                    printf("\nValor anterior: Vazio");      
                }
                else{
                    printf("\nValor anterior: %d", ant->valor);
                }
                if(aux->prox != NULL){
                     printf("\nValor posterior: %d", aux->prox->valor);
                }
                else{
                    printf("\nValor posterior: Vazio");           
                }
            }
}

void RemoverLigada (lista * l1){
    elemento * aux , * ant;
    if(l1->inicio==NULL){
        printf("\nLista Vazia");
    }
    else{
        aux = l1->inicio;
        ant = aux;
        while(aux != NULL){
            ant = aux;
            aux= aux -> prox;
        }
        ant->prox = aux->prox;
    }
}

void menu(lista * l1){

    int dow , dow2 , d , j;
    do{
        printf("\n   Lista Ligada"
               "\n1- Inserir no Fim"
               "\n2- Inserir no Inicio"
               "\n3- Mostrar"
               "\n4- Buscar"
               "\n5- Remover"
               "\n9- Sair");
          scanf("%d", &dow);

        switch(dow){
            case 1:
                do{
                    printf("\n     Inserir no Fim ");
                    printf("\nDigite o valor a ser inserido: ");
                        scanf("%d", &d);
                    InserirFimListaLigada(l1,d);
                    printf("\n Continuar inserindo? "
                            "\n 1- SIM | 2- NAO");
                        scanf("%d", &dow2);        
                }while(dow2 !=2);
            break;
            case 2:
                do{
                    printf("\n     Inserir no Inicio ");
                    printf("\nDigite o valor a ser inserido: ");
                        scanf("%d", &d);
                    InserirInicioListaLigada(l1,d);
                    printf("\n Continuar inserindo? "
                            "\n 1- SIM | 2- NAO");
                        scanf("%d", &dow2);        
                }while(dow2 !=2);
            break;
            case 3:
                MostrarLigada(l1);
            break;
            case 4:
                do{
                    printf("\nDigite o valor a ser buscado: ");
                        scanf("%d", &d);
                    buscar_lista(l1, d);
                    printf("\n Continuar inserindo? "
                            "\n 1- SIM | 2- NAO");
                        scanf("%d", &dow2);  
                }while(dow2 !=2);    
            break;
            case 5:
                RemoverLigada(l1);
                MostrarLigada(l1);
            break;    
        }       
    }while(dow !=9);
}

int main(){

    lista * l1 = aloca_lista();
    menu(l1);
    return 0;
}