#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct tree {
    int ID;
    int valor;
    struct tree *esq;    
    struct tree *dir;    
} Tree;

//explicacao das funções
/*
cria_no    : Gere um no com o menor ID não usado maior que zero
liberdade  : Free que limpa todos os malloc de uma arvore
add_no     : Adicona o no na arvore com base no ID criado
busca_no   : Percorre a arvore e imprime se existe o ID procurado
em_ordem   : printa a arvore em ordem

*/
int global_id = 1;

Tree* cria_no(int X) {
    Tree *novo = malloc(sizeof(Tree));
    novo->ID = global_id;
    novo->valor = X;
    novo->dir = NULL;
    novo->esq = NULL;
    global_id++;
    return novo;
}

void liberdade(Tree *raiz) {
    if(raiz == NULL)
        return;
    liberdade(raiz->esq);
    liberdade(raiz->dir);
    free(raiz);
}

Tree* add_no(Tree* raiz, Tree* new_no) {
    if(raiz == NULL) {
        return new_no;  
    }
    else {
        if(new_no->ID < raiz->ID) {
            raiz->esq = add_no(raiz->esq, new_no);
        }
        else if(new_no->ID > raiz->ID) {
            raiz->dir = add_no(raiz->dir, new_no);
        }
    }
    return raiz;
}

Tree* busca_no(Tree* raiz, int X){
    if(raiz == NULL)
        {
        printf("nó não encontrado!");
        return NULL;
    }
    else if(raiz->ID < X)
        return busca_no(raiz->dir,X);
    else if(raiz->ID > X)
        return busca_no(raiz->esq,X);
    else if(raiz->ID == X)
        {
        printf("Parabens, você encontrou o nó %d\n", raiz->ID);    
        printf("valor %d\n", raiz->valor);
        return raiz;
        }
return NULL;
}

Tree* altera_valor(Tree* no, int valor){
if(no == NULL)
    printf("Nó foi susbtituido!");
else
    {
    no->valor = valor;
    printf("\nO nó %d foi substituido com sucesso!\n", no->ID);
    printf("Novo valor do nó é %d \n",no->valor);
    }
return NULL;
}

void em_ordem(Tree* raiz){
    if(raiz == NULL)
    return;


    em_ordem(raiz->esq);
    printf("ID   :\x1B[32m%d\x1B[0m\nValor:%d\n",raiz->ID, raiz->valor);
    em_ordem(raiz->dir);

}

Tree* remove_no(Tree* raiz,int id){
    if(raiz == NULL)
    {
    printf("Nó vazio!");
    return NULL;
    }

    if(raiz->ID > id)
        raiz->esq = remove_no(raiz->esq,id);

    else if(raiz->ID < id)
        raiz->dir = remove_no(raiz->dir,id);
    else
    {
        //remoção para nó sem filho
        if(raiz->dir == NULL && raiz->esq == NULL)
        {
            free(raiz);
            return NULL;
        }
        //remoção nó com 1 filho
        else if(raiz->dir == NULL)
        {
            Tree *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        else if(raiz->esq == NULL)
        {
            Tree *temp = raiz->dir;
            free(raiz);
            return temp;
        }

        else
        {
            
        Tree *temp = raiz->esq;
        while(temp->dir != NULL)
        temp = temp->dir;
        
        raiz->ID = temp->ID;
        raiz->valor = temp->valor;
            
        
        raiz->esq = remove_no(raiz->esq, temp->ID);
        }
    }
return raiz;
}


int main() {
    Tree *arv = NULL;

    for(int i = 1; i <= 20; i++) {
        
        Tree *novo = cria_no(i*i);
        arv = add_no(arv, novo);
    }
remove_no(arv, 17);

altera_valor(arv, 17);

em_ordem(arv);


liberdade(arv);
    return 0;
}
