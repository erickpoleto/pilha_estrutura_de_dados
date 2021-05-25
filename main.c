#include<stdio.h>
#include<stdlib.h>

struct no {
  int info;
  struct no* elo;
};

typedef struct no No;

struct pilha{
  No* no;
};

typedef struct pilha Pilha;

Pilha* cria(void){
  Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

  pilha->no = NULL;
  return pilha;

  if(pilha->no == NULL){
      printf("\nPilha criada com sucesso!\n");
      return pilha;
  }else{
      printf("\nPilha nao foi criada!\n");           
  }
}

No* insere_no(No* no, int info){

  No* no_topo = (No*) malloc(sizeof(No));

  no_topo->info = info;
  no_topo->elo = no;

  return no_topo;

}

void push(Pilha* pilha, int info){

  pilha->no = insere_no(pilha->no, info);

}

void imprime(Pilha* pilha){

  No* no;

  if(pilha->no == NULL){
      printf("\nA pilha esta vazia!\n");   
  }else{
      printf("\n");
      no = pilha->no;
      while(no != NULL){
          printf("\n%d", no->info);
          no = no->elo;
      }
  }
}

void busca(Pilha* pilha, int valor){
  No* no;
  
  int index = 1;

  if (pilha->no != NULL) {
    printf("\n");
    no = pilha->no;
    while (no != NULL) {
      if (no->info == valor) {
        printf("Valor encontrado\n");
        printf("posição: %d", index);
        break;
      } else if (no->elo == NULL) {
        printf("Valor não encontrado\n");
        break;  
      }
      no = no->elo;
      index++;
    }
  } else {
    printf("\nA pilha esta vazia!\n");
  }
}

No* retira_no(No* no){

  No* no_topo = no->elo;
  free(no);
  return no_topo;

}

void pop(Pilha* pilha){

  if(pilha->no == NULL){
      printf("\nA pilha esta vazia!\n");   
  }else{
      pilha->no = retira_no(pilha->no);
  }

}

void libera(Pilha* pilha){

  No* no_topo = pilha->no;

  while(no_topo != NULL){
      No* novo_no_topo = no_topo->elo;
      free(no_topo);
      no_topo = novo_no_topo;
  }
  free(pilha);
  printf("\n\nPilha liberada com sucesso!");

}
    
void insere_controlador(Pilha* pilha) {
  int valor;

  printf("qual o valor? ");
  scanf("%d", &valor);

  push(pilha, valor);
  printf("Valor inserido!\n");
}

void busca_controlador(Pilha* pilha) {
  int valor;
  
  printf("qual o valor? ");
  scanf("%d", &valor);
  printf("\n");

  busca(pilha, valor);
}

int main(){    
  printf("\n");
  Pilha* pilha_de_numeros_inteiros;

  pilha_de_numeros_inteiros = cria();

  int option;
  while ( 0==0 ) {
    
    printf("\n\n");
    printf("--- pilha de números inteiros ---\n");
    printf("Selecione a operação\n");
    printf("1 - inserir valor\n");
    printf("2 - remover do topo\n");
    printf("3 - Buscar\n");
    printf("4 - limpar\n");
    printf("5 - mostrar pilha\n");
    printf("6 - sair\n");
    scanf("%d", &option);

    switch(option) {
      case 1:
        insere_controlador(pilha_de_numeros_inteiros);
        break;
      case 2:
        pop(pilha_de_numeros_inteiros);
        printf("removido!");
        break;
      case 3: 
        busca_controlador(pilha_de_numeros_inteiros);
        break;
      case 4:
        libera(pilha_de_numeros_inteiros);
        pilha_de_numeros_inteiros = cria();
        break;
      case 5:
        imprime(pilha_de_numeros_inteiros);
        break;
      case 6:
        printf("saindo...\n");
        libera(pilha_de_numeros_inteiros);
        exit(0);
        break;
      default:
        printf("opção invalida\n");
    }
  }
}