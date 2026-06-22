#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

typedef struct{
    pecas itens[MAX];
    int topo;
} Pilha;

//codigos da fila
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
void adicionarPecas(Fila *f, pecas p, int t){
    int nu;

    char *non[]={"T","O","L","i"};
    
    srand(time(NULL));
    nu = (rand()% 4) + 1;
    

    strcpy(p.tipo,non[nu]);
    p.id = t;
    inserir(f,p);
    
}

void remover(Fila *f, pecas *p){
    if(filaVazia(f)){
        printf("Fila vazia\n");
        return;
    }
    *p = f->itens[f->inicio];
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
//codigos da pilha

void inicializarPilha(Pilha *pi){
    pi->topo = -1;
}

int pilhaVazia(Pilha *pi){
    return pi->topo == -1;
}

int pilhaCheia(Pilha *pi){ 
    return pi->topo == MAX -1;
}



void push(Pilha *pi, pecas nova){
    if(pilhaCheia(pi)){
        printf("Pilha cheia\n");
        return;
    }
    pi->topo++;
    pi->itens[pi->topo]= nova; 
}

//função de limpeza de buffer
void  limparBufferEntrada(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

}

void mostrarPilha(Pilha *pi){
    printf("Pilha Reserva:");
    for(int i = pi->topo;i>=0;i--){
        printf("[%s, %d]",pi->itens[i].tipo,pi->itens[i].id);
    }
    printf("\n");
}
void pop(Pilha *pi,pecas *removida){
    if(pilhaVazia(pi)){
        printf("Pilha vazia\n");
        return;
    }

    *removida =pi->itens[pi->topo];
    pi->topo--;
}

int main(){
    int t=4;
    Pilha pi;
    pecas p;
    pecas removida;
    pecas nova;
    int opcao;
    Fila f;
    inicializarFila(&f);
    inicializarPilha(&pi);//inicialisar fila
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
        mostrarPilha(&pi);
         printf("1-Jogar pecas(dequeue)\n");
         printf("2-reservar peca(push):\n");
         printf("3-Usar peca reserva(pop)\n");
         printf("0-Sair\n");
         printf("Digite uma opcao:");
         scanf("%d",&opcao);
         limparBufferEntrada();


        switch(opcao){
            case 1:
          
            remover(&f, &removida);
            printf("Peca removida: %s, %d\n", removida.tipo,removida.id);
            t++;
            printf("adicionando uma peca\n");
            
            adicionarPecas(&f,p,t);
            mostrarFila(&f);
            printf("pressione enter......");
            getchar();
            break;

            case 2:

            remover(&f,&nova);
            push(&pi,nova);
            mostrarPilha(&pi);
            printf("pressione enter......");
            getchar();

            break;
            case 3:
           pop(&pi,&removida);
           inserir(&f,removida);
           mostrarFila(&f);
           mostrarPilha(&pi);
           printf("pressione enter.....");
           getchar();
            break;

            case 0:
            printf("saindo do sistema\n");

            break;
        }


    }while(opcao !=0);

    printf("fim");
return 0;
}