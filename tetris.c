#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tipo[10];
    int id;

}pecas;

#define MAX 5

typedef struct{
    pecas itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f){
    f->inicio=0;
    f->fim=0;
    f->total=0;
}

int filaCheia(Fila *f){
    return f->total==MAX;
}
int filaVazia(Fila *f){
    return f->total==0;
}

void inserir(Fila *f, pecas p){
    if(filaCheia(f)){
        printf("Fila cheia.\n");
        return;
    }
    f->itens[f->fim]=p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, pecas *p){
    if(filaVazia(f)){
        printf("Fila vazia\n");
        return;
    }
    *p= f->itens[f->inicio];
    f->inicio = (f->inicio+1)%MAX;
    f->total--;
}

void mostrarFila(Fila *f){
    printf("Fila: ");
    for(int i=0, idx = f->inicio;
    i < f->total;
     i++,idx= (idx +1)%MAX)
     {
        printf("[%s,%d]",
        f->itens[idx].tipo,
    f->itens[idx].id);
     }
     printf("\n");

    
}
//função de limpeza de buffer
void  limparBufferEntrada(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

}

int main(){
    pecas removida;
    char nome;
    int i= 4;
    int opcao;
    Fila f;
    inicializarFila(&f);//inicialisar fila
//insere algumas pecas na fila
    pecas p1={"T",0};
    pecas p2={"O",1};
    pecas p3={"L",2};
    pecas p4={"I",3};
    pecas p5={"I",4};

    inserir(&f,p1);
    inserir(&f,p2);
    inserir(&f,p3);
    inserir(&f,p4);
    inserir(&f,p5);


    do{

        printf("---TETRIS STACK---\n");
        mostrarFila(&f);//mostrar a fila

         printf("1-Jogar pecas(dequeue)\n");
         printf("2-Inseir nova peca:\n");
         printf("3-Sair\n");
         printf("Digite uma opcao:\n");
         scanf("%d",&opcao);
         limparBufferEntrada();


        switch(opcao){
            case 1:
          
          remover(&f, &removida);
          printf("Peca removida: %s, %d\n", removida.tipo,removida.id);
         
            break;

            case 2:
            
            printf("adicionar uma peca");
            printf("Digite um item para inserir:");
            scanf("%s",&nome);
            i++;
            pecas p6 = {nome, i};
            inserir(&f,p6);
            


            break;

            case 0:
            printf("saindo do sistema\n");

            break;
        }


    }while(opcao !=3);

    printf("fim");
return 0;
}