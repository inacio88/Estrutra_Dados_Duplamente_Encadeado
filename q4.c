#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int dado;
    struct noh *proximo;
    struct noh *anterior;
}*tipoLista;


tipoLista criarNoh(int valor){
    tipoLista novoNoh = (tipoLista) malloc(sizeof(tipoLista));
    if (novoNoh == NULL){
        printf("\n erro para criar noh\n");
        return NULL;
    }
    else{
        novoNoh->dado = valor;
        novoNoh->proximo = NULL;
        novoNoh->anterior = NULL;
        return novoNoh;
    }
    
}

tipoLista inserir(int valor, tipoLista lista, int parametro){
    tipoLista novoNoh = criarNoh(valor);
    if (lista == NULL){
        return novoNoh;
    }
    if (parametro == 1){
        lista->anterior = novoNoh;
        novoNoh->proximo = lista;
        return novoNoh;
    }
    else if (parametro == 2){
        tipoLista listaAux = lista;

        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
        }
        
        listaAux->proximo = novoNoh;
        novoNoh->anterior = listaAux;
   //?     
        return lista;
        
    }
    
    
    
}


tipoLista inserirEsquerda(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);
    if (lista == NULL){
        return novoNoh;
    }
    else{
        lista->anterior = novoNoh;
        novoNoh->proximo = lista;
        return novoNoh;
    }
    
}

tipoLista inserirDireita(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);

    if (lista == NULL){
        return novoNoh;
    }
    else{
        tipoLista listaAux = lista;

        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
        }
        
        listaAux->proximo = novoNoh;
        novoNoh->anterior = listaAux;
   //?     
        return lista;
    }
}


tipoLista remover(int valor, tipoLista lista, int parametro){
    tipoLista listaAux2;
    tipoLista listaAux = lista;
    if (listaAux->proximo == NULL){
        free(listaAux);
        listaAux = NULL;
    }
    if (parametro == 1){
        lista = listaAux->proximo; 
        free(listaAux);
        listaAux = NULL;
        return lista;
    }
    else if (parametro == 2){
        while (listaAux->proximo != NULL){
                listaAux = listaAux->proximo;
        }

            listaAux2 = listaAux;
            listaAux->anterior->proximo = NULL;
            listaAux2->anterior = NULL;
            free(listaAux2);
            listaAux2 = NULL;

            return lista;
        
    }
    
    
    
}


tipoLista removerEsquerda(tipoLista lista){
    tipoLista listaAux = lista;
    
    if (lista == NULL){
        return lista;
    }

    else if (listaAux->proximo == NULL){
        free(listaAux);
        listaAux = NULL;
    }

    else{

        lista = listaAux->proximo; 
        free(listaAux);
        listaAux = NULL;
        return lista;
    }
    
}

tipoLista removerDireita(tipoLista lista){
    tipoLista listaAux = lista;
    tipoLista listaAux2;

    if (lista == NULL){
        printf("\nvazia\n");
    }
    else{
        

        if (listaAux->proximo == NULL){
           free(listaAux);
           listaAux = NULL;
        }
        else{
            while (listaAux->proximo != NULL){
                listaAux = listaAux->proximo;
            }

            listaAux2 = listaAux;
            listaAux->anterior->proximo = NULL;
            listaAux2->anterior = NULL;
            free(listaAux2);
            listaAux2 = NULL;

            return lista;


        }
        

    }
    return listaAux;
    

}
void exibir(tipoLista lista){
    printf("\n----------Lista atual--------\n");
    if (lista == NULL){
        printf("\nVazia\n");
    }
    else{
        tipoLista listaAux = lista;
        tipoLista listaAux2 = NULL;
        while (listaAux != NULL){
            printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
            
        }
        
    }
    printf("\n-----------------------------------\n");
    
}

int main(){
    int op = 11;
    int escolha = 0;
    int valor = 0;
    tipoLista lista = NULL;
    int parametro;

    printf("\n1 dinamico \n 2 estatico\n digite: ");
    scanf("%d", &escolha);
    if (escolha == 2){
        //Vetor
    }
    
    else{
    
        
        
        while (op != 0){
            escolha = 0;
            exibir(lista);
            printf("\n 1- inserir\n");
            printf("\n 2- remover \n");
            printf("\n 0- sair \n");
            printf("Digite: ");
            scanf("%d", &op);
            switch (op){
            case 1:
                printf("Valor: \n");
                scanf("%d", &valor);
                printf("1 inserir esquerda \n 2 inserir direita \n digite: \n");
                scanf("%d", &parametro);

                lista = inserir(valor, lista, parametro);
                break;
    
            case 2:
                printf("Remover esquerda \n");
                lista = removerEsquerda(lista);
        
                break;
          

            default:
                op = 0;
                printf("O programa ira encerrar \n");
                break;
            }
        }
        
    }

    
    return 0;
}