//   ------ CRUD usando Lista Ligada + Lista Duplamente Ligada + Fila + Pilha  -------    //
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct lista{	
	int qtd;
	struct elemento * inicio;
	struct elemento * fim;
	
}lista;

typedef struct elemento{
	
	int num;
	char palavra[30];
	struct elemento * prox;
	struct elemento * ant;

}elemento;

struct vetor{    // parametros para Sorts (implementação futura)

	int tamanho;
	int *vetor;
	int inicio;
	int fim;
	
}vetor;
//****** arquivo *******
void criar_arquivo(FILE* arquivo);
void escrever_arquivo(FILE * arquivo );

//******lista ligada*****
lista * aloca_lista();
elemento * aloca_elemento();
int inserir(lista *l1);
int mostrar(lista*l1);
void menu(lista*l1,lista*l2);
int remover(lista*l1);

//****** lista duplamente ligada *****
lista * aloca_lista2();
elemento * aloca_elemento2();
void inserir_dupla(lista*l2,int num,char *palavra);
void mostrar_dupla(lista*l2);
int remover_dupla(lista*l2); 

// ******* Fila com lista *******
void push(lista*l1);
int pop(lista*l1);
int empty(lista*l1); //função ruim...
void mostrar_fila(lista*l1);
int stack_pop(lista*l1);

//********** Pilha **************
void push_pilha(lista*l1);
int pop_pilha(lista*l1);
void mostrar_pilha(lista*l1);

// ******* Sorts **********
int * aloca_vetor(int tamanho);
void quick_sort(int vetor[], int inicio, int fim);


int main(){
	setlocale(LC_ALL, "Portuguese");


	lista* l1 = aloca_lista(); //lista ligada
	lista*l2 = aloca_lista2(); // duplamente ligada e fila encadeada


	menu(l1,l2);

	
	return 0;
}

void menu(lista *l1, lista*l2){
	//MENU 
	
	int opcoes , opcao, opcao_fila, op_sort ;
	int  dupla, num, n, pilha;
	char palavra[30];
	
	do{
		
	printf("\t**************************************\n");	
	printf("\t**  1- Lista ligada                 **\n");
	printf("\t**  2- Lista duplamente ligada      **\n");
	printf("\t**  3- fila de lista encadeada      **\n");
	printf("\t**  4- Fila circular (estr. lista)  **\n");
	printf("\t**  5- Pilha                        **\n");
	printf("\t**  99- Sair                        **\n");
	printf("\t**************************************\n");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao){
			
			case 1:
			//lista ligada
			do{	
				printf("\n\t****************************************");
				printf("\n\t**         lista  ligada              **");
				printf("\n\t** 1- Inserir elemento                **");
				printf("\n\t** 2- Mostrar elemento                **");
				printf("\n\t** 3- Remover elemento                **");
				printf("\n\t** 4- Voltar ao menu principal        **");
				printf("\n\t****************************************\n");
					scanf("%i", &opcoes);
	
				switch(opcoes){	
			
					case 1:
						inserir(l1);
					break;					
					
					case 2:				
						mostrar(l1);
					break;						
					
					case 3:
						remover(l1);
					break;	
					
					case 4:
						system("cls");
					break;
						
					default:
						printf("\nOpção invalida\n");
					break;	
						
											
				}//switch
			}while(opcoes!=4);
			break;
			
			case 2:
			// lista duplamente ligada
			do{	
				printf("\n\t****************************************");
				printf("\n\t**      Lista duplamente ligada       **");
				printf("\n\t**1- Inserir elemento                 **");
				printf("\n\t**2- Mostrar elemento                 **");
				printf("\n\t**3- Remover elemento                 **");
				printf("\n\t**4- Voltar ao menu principal         **");
				printf("\n\t****************************************\n");
					scanf("%d", &dupla);
	
				switch(dupla){
			
					case 1:
						printf("\nDigite o valor que deseja inserir: \n");
							scanf("\n%d", &num);
						printf("\nDigite uma palavra:\n");
							scanf("\n%s", palavra );	
						inserir_dupla(l2,num,palavra);
					break;					
					
					case 2:				
						mostrar_dupla(l2);
					break;						
					
					case 3:
						remover(l2);
					break;	
					
					case 4:
						system("cls");
						break;
					default:
						printf("\nOpção invalida\n");
					break;	
																	
				}//switch
			}while(dupla!=4);
			break;
			
			case 3:	
			//fila de listas
			do{
				printf("\n\t************ FILA de Lista **************");
				printf("\n\t**  1- Inserir elemento - (push)       **");
				printf("\n\t**  2- Remover elemento - (pop)        **");
				printf("\n\t**  3- Mostrar elementos               **");
				printf("\n\t**  4- Stack Pop                       **");
				printf("\n\t**  6- Voltar ao menu principal        **");
				printf("\n\t*****************************************\n");
					scanf("%i",&opcao_fila);
					
				switch(opcao_fila){
					
					case 1:					
						push(l1);
					break;
					
					case 2:
						n=pop(l1);
						if(n==-1){
							printf("\nFila vazia!\n\n");
							
						}
						else{
							printf("\nO elemento Nº: %i foi deletado\n\n",n);
						}
						break;
					
					case 3:
						mostrar_fila(l1);
					break;
					
					case 4:
						n=stack_pop(l1);
						if(n==-1){
							printf("\nFila vazia!\n\n");	
						}
						else{							
							printf("\nPróximo valor a ser chamado é: %i\n\n", n);
						}
					break;
					
					case 5:
						
					break;	
					case 6:
						system("cls");
					break;	
					default:
						printf("\nOpção invalida!");
					break;	
				}
			}while(opcao_fila!=6);	
			break;
			
			case 4:
			
			break;
			
			case 5:
			// Pilha	
			do{	
				printf("\n\t****************************************");
				printf("\n\t**             Pilha                  **");
				printf("\n\t** 1- Adicionar (push)                **");
				printf("\n\t** 2- Remover (Pop)                   **");
				printf("\n\t** 3- Mostrar Pilha                   **");
				printf("\n\t** 4- Voltar ao menu principal        **");
				printf("\n\t****************************************\n");
					scanf("%i", &pilha);
					
				switch(pilha){
					
					case 1:
						push_pilha(l1);
					break;	
					
					case 2:
						pop_pilha(l1);
					break;
						
					case 3:
						mostrar_pilha(l1);	
					break;	
					case 4:
						system("cls");
					break;
					default:
						printf("\nOpção Invalida!\n\n");
					break;		
				}	
				
				}while(pilha!=4);
				
			break;
			
			case 99:
				printf("\n\nSaindo\n\n");
			break;	
			
		}
		
		
	}while(opcao!=99); // modificar condição de saida!!!!	
	
	system("pause");

}
//******************************** ARQUIVO TXT *********************************************

void criar_arquivo(FILE* arquivo){
	
	arquivo = fopen("Resultados.txt", "r");
	if(arquivo == NULL){
		arquivo = fopen("Resultados.txt", "w");
		fclose(arquivo);
	}
	else{
	}
	return;
}

void escrever_arquivo(FILE * arquivo ){
	
}

//******************************** LISTA LIGADA ********************************************
lista * aloca_lista(){
	
	lista * novo;
	novo = (lista*)calloc(sizeof(lista));	
	return novo;	
}

elemento * aloca_elemento(){
	
	elemento * novo;
	novo = (elemento*)malloc(sizeof(elemento));
	novo -> prox = NULL;
	novo -> num=0;
	
	return novo;
}

int inserir (lista * l1){ 
	
	elemento * novo = aloca_elemento();
	elemento * aux;
	
	printf("\n Digite um valor para inserir na lista:");
		scanf("%d",&novo-> num);
	
	if(l1->inicio==NULL){
		
		l1->inicio=novo;
	}	
		else{
		
			aux= l1-> inicio;
	
			while(aux->prox != NULL){
		
				aux = aux -> prox;
			}
			aux -> prox = novo;
		}//else
	l1 -> qtd++;
	
	printf("\nValor adicionado com sucesso!\n");
	
	return 1;
}

int mostrar(lista*l1){
	
	elemento * aux;
	
	if(l1->inicio==NULL){
		printf("\n A lista esta vazia\n");
	}
	else{
		printf("\n Mostrando os números contidos na lista:\n");
		aux = l1->inicio;
		while(aux!=NULL){
			printf("\n%d",aux->num);
			
			aux=aux->prox;
		}
		
	}	
	printf("\n\n");
}

int remover(lista*l1){  
	
	elemento*aux=NULL;
	elemento *ant=NULL;
	
	int apagar;
	
	if(l1->inicio==NULL){
		printf("\nA lista esta vazia \n");
		return 0;
	}
	else{
		printf("\nDigite o numero que deseja apagar:");
			scanf("%i",&apagar);
			
			aux= l1->inicio;
			
		while(aux!=NULL){
			
			if(aux->num== apagar){
				
				if(ant==NULL){
					
					l1-> inicio = aux-> prox;
				}
				else{
					
					ant->prox = aux->prox;
				}
				
				printf("\nElemento apagado com sucesso! \n\n");
				free(aux);
				l1->qtd--;
				return 1;				
			}
			else{
				
				ant=aux;
				aux=aux->prox;
			}
			
		}//while	
	}
	return 0;
}

//****************************** LISTA DUPLAMENTE LIGADA ****************************************

lista * aloca_lista2(){
	
	lista*novo;
	novo=(lista*)malloc(sizeof(lista));
	novo->inicio=NULL;
	novo->fim=NULL;
	novo->qtd=0;
	
	return novo;
}

elemento * aloca_elemento2(){
	
	elemento * novo;
	novo=(elemento*)malloc(sizeof(elemento));
	novo->ant=NULL;
	novo->prox=NULL;
	novo-> num=0;
	strcpy(novo->palavra, " ");
	
	return novo;
}

void inserir_dupla(lista*l2,int num, char*palavra){
	
	elemento * novo;
	elemento * aux;
	novo=aloca_elemento2();
	novo->num=num;
	strcpy(novo->palavra,palavra);
	
	if(l2->inicio==NULL){
		
		l2-> inicio=novo;
		l2-> fim=novo;
	}		
	else{
		
		aux = l2->fim;
		aux->prox = novo;
		novo-> ant=aux;
		l2-> fim=novo;
	}
	l2->qtd++;		
}

void mostrar_dupla(lista*l2){
	
	elemento* aux;
	
	if(l2->inicio==NULL){
		
		printf("\nLista vazia\n");
		return;
	}
	else{
		
		aux= l2->inicio;
		while(aux!=NULL){
			
			printf("\n%d -> %s", aux->num, aux->palavra);
			aux= aux->prox;
		}
	}
}

int remover_dupla(lista*l2){ 
	
	elemento * ant=NULL;
	elemento *aux=NULL;
	elemento * prox;
	
	int apagar;
	
	if(l2->inicio==NULL){
		printf("\nLista vazia!\n\n");
		return 0;
	}
	else{
		printf("\nDigite o que deseja apagar:");
			scanf("%i", &apagar);
		aux=l2->inicio;
		while(aux!=NULL){
			if(aux->num=apagar){
				if(ant==NULL){
					l2->inicio=aux->prox;
					l2->fim=ant->prox;
				}
				else{
						ant->prox=aux->prox;
				}
			
					free(aux);
					l2->qtd--;
					return 1;
			}
			else{
				ant=aux;
				aux=aux->prox;
			}//else
				
			}//while
			
		}//elsao
		return 0;	
	}//funcao


//******************************************  FILA *****************************************************


//push(): insere elementos na fila(no final)
// pop(): remove um elemento da fila(o primeiro)
// empty(): verifica se a estrutura está vazia
//stakpop(): mostra qual elemento esta em um ponto 
//full(): diz se a fila está cheia

//******PROVA : 1º usando estrutura de lista encadeada OU 2º ultilizando estrutura de vetor em uma fila circular*******


//****************************** FILA COM LISTA ****************************************************

//-> vou usar a função    lista * aloca_lista(); 
//->vou usar a função     elemento * aloca_elemento2();

void push(lista*l1){
	
	elemento*novo;
	elemento*aux;
	novo=aloca_elemento2();
		printf("\nDigite um valor que deseja armazenar:");
			scanf("%i", &novo->num);
		//printf("\nDigite uma palavra que deseja guardar:");
			//scanf("%s", novo->palavra);	
	
	if(empty(l1)){
		
		l1->inicio=novo;
		l1->fim=novo;
	}
	else{
		aux=l1->fim;
		aux->prox = novo;
		l1->fim=novo;
		
	}
	l1->qtd++;
}

int pop(lista*l1){
	
	elemento * aux;
	int retornar;
	
	if(empty(l1)){
		
		return -1;
	}
	else{
		
		aux=l1->inicio;
		retornar = aux->num;
		l1->inicio= aux->prox;
		free(aux);
			l1->qtd--;
		return retornar;
	}

}

int empty(lista*l1){
	
	if(l1->inicio==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void mostrar_fila(lista*l1){
	
	elemento * aux;
	
	if(empty(l1)){
		printf("\nFila vazia!!\n");
	return;
	}
	else{
		aux= l1->inicio;
		while(aux!=NULL){
			printf("- Nº: %d \n", aux->num);
			aux= aux->prox;
		
		}
		printf("\n\n");	
	}
} 

int stack_pop (lista*l1){
	
	if(l1->inicio==NULL){
		
		return -1;
	}
	else{
		
		return l1-> inicio->num;
	}
	
}

//************************************** PILHA ********************************************************

//-> vou usar a função   lista*aloca_lista();
//-> vou usar a função   elemento * aloca_elemento();

void push_pilha(lista*l1){
	
	elemento*novo;
	novo= aloca_elemento();
	
		printf("\nDigite o valor que deseja inserir:");
			scanf("%i", &novo->num);
			
	if(l1->inicio==NULL){
		
		l1->inicio=novo;
	}
	else{
		
		novo->prox=l1->inicio;
		l1->inicio=novo;
		
	}
	l1->qtd++;
			
			
}

int pop_pilha(lista*l1){
	
	elemento * novo;
	int remove;
	
	if(l1->inicio==NULL){
		
		return -1;
	}
	
	else{
		
		novo=l1->inicio;
		remove = novo->num;
		l1->inicio=novo->prox;
		free(novo);
		l1->qtd--;
		return remove;
		
	}
	
}

void mostrar_pilha(lista*l1){
	
	elemento * novo;
	
	if(l1->inicio==NULL){
		printf("\nPilha vazia!!\n");
	return;
	}
	else{
		novo= l1->inicio;
		while(novo!=NULL){
			printf("- Nº: %d \n", novo->num);
			novo= novo->prox;	
		}
		printf("\n\n");	
	}
} 




