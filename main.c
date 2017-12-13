#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void quicksort(int *vetor,int tamanho,int i,int j)
{
    int trab,esq,dir,pivo;
    esq = i;
    dir = j;
    pivo = vetor[(esq + dir)/2];
    do
    {
        while(vetor[esq] < pivo)
            esq++;
        while(vetor[dir] > pivo)
            dir--;
        if (esq<=dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    }while (esq<=dir);

    if (dir-i >=0)
        quicksort(vetor,tamanho,i,dir);
    if (j-esq >=0)
        quicksort(vetor,tamanho,esq,j);

}

int main()
{
    int tam = 8;
    int i;
    int vetor[tam];

    char nomes[10][100];
    int tamanho = 5;
    char j;

    strcmp(nomes[0],"Monalisa");
    strcmp(nomes[1],"Thais");
    strcmp(nomes[3],"Maria");
    strcmp(nomes[3],"Mona");

    qsort(nomes,5,sizeof(nomes[0]),cmpfunc);

    for(j = nomes[];)

    for(i = 0;i<tam;i++)
    {
        vetor[i] = rand() %10000+1; //gera uma vetor com numeros aleatorios
        printf("%d\n",vetor[i]); // mostra o vetor antes
    }

    quicksort(vetor,tam,0,8); //chama a função quicksort

    for(i = 0; i<tam;i++)
    {
        printf("%d\n", vetor[i]); // mostra o vetor ordenado
    }

    qsort(vetor,9,sizeof(int),cmpfunc);


    printf("\n");

    printf("Hello world!\n");
    return 0;
}
