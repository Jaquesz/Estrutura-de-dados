/******************************************************************************

 Dado duas pilhas P1 e P2 que armazenam números inteiros, faça um programa que tenha as
seguintes funções:

Uma função para testar se as duas pilhas P1 e P2 são iguais. Caso não forem iguais diga qual pilha é maior
Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma pilha.
Uma função para transferir elementos de P1 para P2 (copia).
Uma função para retornar o número de elementos de uma pilha que possuem valor ımpar.
Uma função para retornar o número de elementos da uma pilha que possuem valor par


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*registro que reprensentará cada elemento da pilha*/
struct Elemento{
int num;
struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha{
    struct Elemento *topo;/*aponta para o elemento qu esta Elemento topo da pilha*/
};
typedef struct Pilha Pilha;

 /*ponteiro auxiliar*/
 Elemento *aux;


 Pilha* cria_pilha(){
/*alocação do ponteiro pi para controlar a pilha*/
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo= NULL;  /*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
    }
    return pi;
}



/*todo elemento será inserido no topo da pilha*/
void insere_elemento(Pilha *pi){
/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
printf("Digite o numero a ser inserido na pilha: ");
scanf("%d",&novo->num);
/*como o número inserido será o novo topo, ele apontará para o topo atual que será o segundo elemento da pilha*/
novo->prox = pi->topo;
/*topo aponta para o endereço de novo*/
pi->topo = novo;
printf("\nNumero inserido na pilha!");
getch();
}



/*os elementos da pilha serão mostrados do último inserido(topo) ao primeiro*/
void consulta_pilha(Pilha *pi){
/*caso a pilha esteja vazia*/
if(pi->topo == NULL){
printf("\nPilha Vazia!!");
/*caso a pilha não esteja vazia*/
}else{
aux = pi->topo;
do{
printf(" %d ", aux->num);
aux = aux->prox;
} while(aux != NULL);
}
getch();
}


/*o elemento a ser removido será sempre o topo(último elemento inserido)*/
void remove_elemento_pilha(Pilha *pi){
if(pi->topo == NULL){
printf("\nPilha Vazia!!");
}else{
aux = pi->topo;
printf("%d removido!", pi->topo->num);
pi->topo = pi->topo->prox;
free(aux);
}
getch();
}



/*a pilha será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_pilha(Pilha *pi){
if(pi->topo == NULL){
printf("\nPilha Vazia!!");
}else{
aux = pi->topo;
do{
pi->topo = pi->topo->prox;
free(aux);
aux = pi->topo;
}while(aux != NULL);
printf("\nPilha Esvaziada!!");
}
getch();
}

//função para testar se as duas pilhas P1 e P2 são iguais.
//Caso não forem iguais diga qual pilha é maior

int testarpilha(Pilha *pi, Pilha *pi2){
    Elemento *aux1 = pi->topo;
    Elemento *aux2 = pi2->topo;
   
 
   
    while (aux1 != NULL && aux2 != NULL){
        if(aux1 != aux2){
            return 0;
        };
        aux1 = aux1->prox;
        aux2 = aux2->prox;
       
    };
   
   if (aux1 == NULL && aux2 == NULL) {
       printf("Pilhas iguais\n");
        return 1; // Pilhas são iguais
    } else if (aux1 == NULL) {
        printf("Pilha 2 é a maior\n");
        return 2; // Pilha 2 é maior
    } else {
        printf("Pilha 1 é a maior\n");
        return 3; // Pilha 1 é maior
    };
   
};

void MaiorMenorMedia(Pilha *pi){ /*** função para ver a media, o maior e o menor elemento*/ 
    float media, maior= pi->topo->num, contador = 0, menor= pi->topo->num, soma = 0;
    
    aux = pi->topo;
    
    while(aux != NULL){
        soma = soma + aux->num;
    if(aux->num > maior){
        maior = aux->num;
    };
    if(aux->num < menor){
        menor = aux->num;
    };
    contador++;
    
    aux = aux->prox;
    
    }
    
    media = soma / contador;
    
    printf("O maior elemento da pilha é: %.2f\n", maior);
    printf("O menor elemento da pilha é: %.2f\n", menor);
    printf("A média dos elementos da pilha é: %.2f\n", media);
    
    free(aux);
};

/*Uma função para retornar o número de elementos da uma pilha que possuem valor par*/
void ElementoPar(Pilha *pi){
    
    free(aux);
    aux = pi->topo;
    
    while(aux != NULL){
        if(aux->num %2 == 0){
            printf("%d é par.\n", aux->num);
        };
        
        aux = aux->prox;
    }
};

void ElementoImpar(Pilha*pi){
    
    free(aux);
    aux = pi->topo;

    while(aux != NULL){
        if(aux->num %2 != 0){
        printf("%d é impar.\n", aux->num);
        };
        
         aux = aux->prox;
    }
    
};

int main(){
    int op;
    int op2;
Pilha *pi = cria_pilha();
Pilha *pi2 = cria_pilha();
    while(1){
       
        printf("\nEscolha a opcao desejada\n ");
        printf("\n1- Inserir numero na pilha ");
        printf("\n2- Consultar pilha ");
        printf("\n3- Remover da pilha");
        printf("\n4- Esvaziar pilha: ");
        printf("\n5- comparar pilhas");
        printf("\n6- Verificar média, maior e menor elemento da pilha.");
        printf("\n7- Consultar os elementos pares da pilha:");
        printf("\n8- Consultar os elementos ímpares da pilha:\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("1 para inserir na pilha 1 e 2 para inserir na pilha 2\n");
            scanf("%d", &op2);
            if(op2 == 1){
                insere_elemento(pi);
            }
            else if(op2 == 2) {
                insere_elemento(pi2);
            }
           
            break;
        case 2:
            printf("1 para consultar a pilha 1 e 2 para consultar a pilha 2\n");
            scanf("%d", &op2);
            if(op2==1){
                consulta_pilha(pi);
            }
            else if(op2==2){
                consulta_pilha(pi2);
            };
            break;
        case 3:
            printf("1 para remover elemento da pilha 1 e 2 para remover da 2\n");
            scanf("%d", &op2);
            if(op2==1){
            remove_elemento_pilha(pi);
            }
            else if(op2==2){
                remove_elemento_pilha(pi2);
            };
            break;
        case 4:
        printf("1 para esvaziar a pilha 1 e 2 para esvaziar a pilha 2\n");
        scanf("%d", &op2);
        if(op2==1){
            esvazia_pilha(pi);
        }
        else if(op2==2){
            esvazia_pilha(pi2);
        };
           
            break;
        case 5:
        printf("-----Comparação das pilhas-----\n");
        testarpilha(pi, pi2);
        break;
        case 6:
         printf("1 para verificar a média, o maior e o menor elemento da pilha 1, e 2 para verificar da pilha 2\n");
            scanf("%d", &op2);
            if(op2==1){
            MaiorMenorMedia(pi);
            }
            else if(op2==2){
            MaiorMenorMedia(pi2);
            };
            break;
        case 7:
         printf("1 para consultar os elementos pares da pilha 1 e 2 para consultar os da 2\n");
            scanf("%d", &op2);
            if(op2==1){
            ElementoPar(pi);
            }
            else if(op2==2){
            ElementoPar(pi2);
            };
            break;
        case 8:
         printf("1 para consultar os elementos ímpares da pilha 1 e 2 para consultar os da 2\n");
         scanf("%d", &op2);
         if(op2==1){
             ElementoImpar(pi);
         }
         else if(op==2){
             ElementoImpar(pi2);
         };
         break;
       
        default:
            exit(1);
        }
    }
    return 0;
}
