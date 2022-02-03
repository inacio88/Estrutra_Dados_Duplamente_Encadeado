#include <stdio.h>
#include <stdlib.h>
//1) Seja L uma lista duplamente encadeada que armazena registros de um arquivo.
//Implemente em linguagem C as seguintes funções:
//a) função numero(L) – retorna o número de elementos da lista L.
//b) função troca(K, L, v) – modifica o elemento K da lista para v.
//c) função insereEsq(K, L, v) – insere o valor v a esquerda do elemento K.
//d) função insereDir(K, L, v) – insere o valor v a direita do elemento K.
//e) função banir(L,v) – elimina todas as ocorrências do elemento v da lista L
typedef struct noh{
    int dado;
    struct noh *proximo;
    struct noh *anterior;
}*tipoLista;

//Prototipacao
tipoLista excluirMeio(int valor, tipoLista lista);
tipoLista inserirDirk(int valor, tipoLista lista, int valor_novo);
tipoLista inserirEsquerda(int valor, tipoLista lista);
tipoLista criarNoh(int valor);
tipoLista inserirDireita(int valor, tipoLista lista);
//------------------------

tipoLista inserirEsqk(int valor, tipoLista lista, int valor_novo){
    
    if (lista == NULL){
        printf("Lista vazia");
        lista = inserirEsquerda(valor_novo, lista);
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        tipoLista novoNoh;
        novoNoh = criarNoh(valor_novo);
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->anterior == NULL){
                    lista = inserirEsquerda(valor_novo, lista);
                    return lista;
                }

                listaAux2 = listaAux;
                listaAux2 = listaAux2->anterior;

                listaAux2->proximo = novoNoh;
                novoNoh->anterior = listaAux2;
                novoNoh->proximo = listaAux;
                listaAux->anterior = novoNoh;

                return lista;

            }
            
            listaAux = listaAux->proximo;
            
        }
        free(listaAux);
        listaAux = NULL;
        free(listaAux2);
        listaAux2 = NULL;

    }
 

}


tipoLista inserirDirk(int valor, tipoLista lista, int valor_novo){
    
    if (lista == NULL){
        printf("Lista vazia");
        lista = inserirEsquerda(valor_novo, lista);
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        tipoLista novoNoh;
        novoNoh = criarNoh(valor_novo);
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->proximo == NULL){
                    lista = inserirDireita(valor_novo, lista);
                    return lista;
                }

                listaAux2 = listaAux->proximo;
                listaAux->proximo = novoNoh;
                novoNoh->anterior = listaAux;
                novoNoh->proximo = listaAux2;
                listaAux2->anterior = novoNoh;
                return lista;

            }
            
            listaAux = listaAux->proximo;
            
        }
        free(listaAux);
        listaAux = NULL;
        free(listaAux2);
        listaAux2 = NULL;

    }
 

}


tipoLista banir(int valor, tipoLista lista){
    if (lista == NULL){
        printf("Lista vazia");
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                lista = excluirMeio(valor, lista);
            }
            
            listaAux = listaAux->proximo;
            
        }
        return lista;

    }
}


tipoLista troca(int k_velho, tipoLista lista, int v_novo){
    if (lista == NULL){
        printf("Lista vazia");
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        
        while (listaAux != NULL){
            
            
            if (listaAux->dado == k_velho){
        
                listaAux->dado = v_novo;

                return lista;

            }
            
            listaAux = listaAux->proximo;
            
        }


    }
}



void numero(tipoLista lista){
    int contador=0;
    printf("\n=-=-=-=-=-=-=-Numero de elementos: =-=-=-=-=-=-=-\n");
    if (lista == NULL){
        printf("\n 0 \n");
    }
    else{
        tipoLista listaAux = lista;
        tipoLista listaAux2 = NULL;
        while (listaAux != NULL){
            //printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
            contador++;
        }
        printf("\n %d \n", contador);
        
    }
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
    
}






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
tipoLista excluirMeio(int valor, tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("Lista vazia");
    }
    else if (lista->anterior == NULL && lista->proximo == NULL){
        free(lista);
        lista = NULL;
        return lista;
    }
    else{

        tipoLista listaAux = lista;
        tipoLista listaAux2;
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                
                if (listaAux->proximo != NULL && listaAux->anterior != NULL){
                    listaAux2 = listaAux->anterior;
                    listaAux = listaAux->proximo;
                    listaAux2->proximo = listaAux;
                    listaAux->anterior = listaAux2;
                }
                else if (listaAux->proximo != NULL && listaAux->anterior == NULL){
                    printf("\nRemove esquerda\n");
                    
                    listaAux = listaAux->proximo;
                    listaAux->anterior = NULL;
                    return listaAux;            
                }
                else if (listaAux->proximo == NULL && listaAux->anterior != NULL){
                    printf("\nRemove direita\n");
                    
                    listaAux2 = listaAux;
                    listaAux->anterior->proximo = NULL;
                    listaAux2->anterior = NULL;
                    free(listaAux2);
                    listaAux2 = NULL;

                    return lista;
                    
                }
                
            }
            
            listaAux = listaAux->proximo;
            
        }
        return lista;
        free(listaAux2);
        listaAux2 = NULL;
        free(listaAux);
        listaAux = NULL;
        
    }

}




void pesquisar(int valor, tipoLista lista){
    int flag = 0;
    if (lista == NULL){
        printf("Lista vazia");
    }
    else{

        tipoLista listaAux = lista;
        while (listaAux != NULL){
            
            
            if (listaAux->dado == valor){
                flag++;
            }
            
            listaAux = listaAux->proximo;
            
        }


    }
    printf("Esse valor foi encontrado %d vezes", flag);

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
    int valor = 0;
    tipoLista lista = NULL;
    int k_velho, v_novo;


    while (op != 0){
        exibir(lista);
        printf("\n 1- inserir esquerda \n");
        printf("\n 2- inserir direita \n");
        printf("\n 3- remover esquerda \n");
        printf("\n 4- remover direita \n");
        printf("\n 5- numero de elementos \n");
        printf("\n 6- troca \n");
        printf("\n 7- banir \n");
        printf("\n 8 - inserir a direita de \n");
        printf("\n 9 - inserir a esquerda de \n");
        printf("\n 0- sair \n");
        printf("Digite: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            break;
        case 2:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            printf("Remover esquerda \n");
            lista = removerEsquerda(lista);
    
            break;
        case 4:
            printf("Remover direita \n");
            lista = removerDireita(lista);
    
            break;
        case 5:
            printf("Exibir \n");
            numero(lista);
            break;
        case 6:
            printf("Pequisar: \n");
            scanf("%d", &k_velho);
        
            printf("trocar por: \n");
            scanf("%d", &v_novo);

            lista = troca(k_velho, lista, v_novo);
        
            break;
        case 7:
            printf("Banir: \n");
            scanf("%d", &valor);
            lista =  banir(valor, lista);
            break;
        
        case 8:
            printf("Inserir: \n");
            scanf("%d", &v_novo);
            printf("Ao lado direito de: \n");
            scanf("%d", &valor);
            lista =  inserirDirk(valor, lista, v_novo);
            break;

        case 9:
            printf("Inserir: \n");
            scanf("%d", &v_novo);
            printf("Ao lado esquerdo de: \n");
            scanf("%d", &valor);
            lista =  inserirEsqk(valor, lista, v_novo);
            break;

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}