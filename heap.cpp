#include <iostream>
#include <string>

using namespace std;

const int TAM_MAX = 40;
int tam_atual     = 0;

void print_heap(int v[]){
if(tam_atual == 0)
{
    cout << "Vetor vazio" << endl;
    return;
}
int contador = 0;
int quebra_linha = 1;
for(int i = 0;i < tam_atual; i++)  
{
    cout << v[i] << " ";
    contador++;
    if(quebra_linha == contador)
    {
    cout << endl;
    quebra_linha *= 2;
    contador = 0;
    }      
}

}

void inseri_min_heap(int v[], int X){
if(tam_atual == TAM_MAX)
    {
        cout << "Tamanho maximo atingido!" << endl;
        return;
    }
else
    {
        //inseri o valor
        tam_atual++;
        int i = tam_atual -1;
        v[i] = X;
        
        //verifica posição do nov valor
        while(i != 0 && v[i] < v[(i-1)/2])
        {
            int pai = (i-1)/2;
            int aux = v[pai];
            v[pai] = v[i];
            v[i] = aux;

            i = pai;
        }
    }

}

void inseri_max_heap(int v[],int X){
if(tam_atual == TAM_MAX)
    {
    cout << "O elemento não foi adicionado!" << endl
         << "Vetor está completamente preenchido" << endl;
    return;
    }    

else
    {
    tam_atual++;
    int i = tam_atual-1;
    v[i] = X;

        //verifica posição
        while(i != 0 && v[i] > v[(i-1)/2])
        {
        int pai = (i-1)/2;
        int aux = v[pai];

        v[pai] = v[i];
        v[i] = aux;

        i = pai;
        }
    }

}

void remover_min_heap(int v[]){
    if(tam_atual == 0)
    {   
    cout << "Vetor não inicializado, remoção impossivel" << endl;
    return;
    }
    else
    {
        v[0] = v[tam_atual -1];
        tam_atual --;
        int i = 0;
        while(true)
        {
        int menor = i;
        int esq = (menor*2) + 1;
        int dir = (menor*2) + 2;

            if(esq < tam_atual && v[menor] > v[esq])
            {
            menor = esq;
            }

            if(dir < tam_atual && v[menor] > v[dir])
            {
            menor = dir;
            }

            if(menor == i)
                break;


            int temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;

            i = menor;

        }
    }
}

void remover_max_heap(int v[])
{
    if (tam_atual == 0)
    {
    cout << "Vetor não inicializado!" << endl;
    return;
    }

    else
    {
    int i = 0;
    tam_atual--;
    v[0] = v[tam_atual];

        while(true)
        {
        int maior = i;
        int esq = (i * 2) + 1;
        int dir = (i * 2) + 2;

            if (esq < tam_atual && v[esq] > v[maior])
            maior = esq;

            if (dir < tam_atual &&  v[dir] > v[maior])
            maior = dir;

            if (i == maior)
            return;

        int aux = v[maior];
        v[maior] = v[i]; 
        v[i] = aux;

        i = maior;
        }
    }

}




int main(){

return 0;}
