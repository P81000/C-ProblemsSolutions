/*Pedro Masteguin - 158471
  Problema 2 
*/

#include <stdlib.h>
#include <stdio.h>

//Estrutura dos dados inseridos na matriz
typedef struct {
    double value; 
    int index;
    int col;
} Data;

//Cria o HEAP
typedef struct {
    Data *vet;
    int size;
    int max;
} Heap;

//Inicia o HEAP
void start(Heap *heap, int max) {
    heap->vet = (Data*)malloc(max* sizeof(Data));
    heap->size = 0;
    heap->max = max;
}

//Como é um vetor, é preciso saber quais valores são pais e quais são filhos
int left_child(int i){
    return 2*i + 1; //Filhos da esquerda são guardados na posição 2*i + 1, onde i é a posição do pai
}

int right_child(int i){
    return 2*i + 2; //Filhos da direita são guardados na posição 2*i + 2, onde i é a posição do pai
}

int parent(int i) {
    return (i - 1)/2;
}

//Insere um valor no HEAP
void InsertData(Heap *heap, Data data) {
    if(heap->size == heap->max)
        return;
    
    heap->size++;

    int i = heap->size - 1;
    int parent = (i - 1)/2;
    heap->vet[i] = data;

    Data aux;
    while(i != 0 && heap->vet[parent].value > heap->vet[i].value) { //Percorre o vetor do HEAP verificando se os menores valores estão nas primeiras posiões
        /*---SWAP DE VALORES---*/
        aux = heap->vet[i];
        heap->vet[i] =  heap->vet[parent];
        heap->vet[parent] = aux;
        i = (i - 1)/2;
        parent = (i - 1)/2;
    }
}

//Procedimento que organiza o HEAP
void MinHeapfy(Heap *heap, int i) {
    int esq = left_child(i);
    int dir = right_child(i);
    int min = i;

    Data aux;
    if((esq < heap->size) && (heap->vet[esq].value <= heap->vet[i].value))
        min = esq;
    if((dir < heap->size) && (heap->vet[dir].value <= heap->vet[min].value))
        min = dir;
    if(min != i) {
        /*---SWAP DE VALORES---*/
        aux = heap->vet[i];
        heap->vet[i] = heap->vet[min];
        heap->vet[min] = aux;
        MinHeapfy(heap, min); //Realiza o processo novamente de maneira recursiva
    }
}

//Função que extrai o menor valor do heap, ou seja, o primeiro
Data ExtractMin(Heap *heap) {
    if(heap->size == 1) {
        heap->size--;
        return heap->vet[0];
    }
    Data min = heap->vet[0]; 

    heap->vet[0] = heap->vet[heap->size - 1]; //Coloca o ultimo valor na primeira posição do vetor
    heap->size--;

    MinHeapfy(heap, 0); //Reorganiza o HEAP
    return min;
}

//Calcula a soma dos valores do heap
double Sum_Heap(Heap *heap) {
    double sum = 0;
    for(int i = 0; i < heap->size; i++)
        sum += heap->vet[i].value;
    
    return sum;
}

//Funcao principal
int main (void) {
    int k, i;
    int l, c, j, aux = 0;
    scanf("%d %d", &k, &i);

    int *tam;
    Heap heap;
    Data num, extract, **vet;
    vet = (Data**)malloc(k* sizeof(Data*));
    tam = (int*)malloc(k* sizeof(int));
    start(&heap, k);

    //Leitura e Inicialização
    for(l = 0; l < k; l++)
    {   
        scanf("%d", &tam[l]);
        vet[l] = (Data*)malloc((tam[l])* sizeof(Data));
        if(tam[l] != 0)
        {
            scanf("%lf", &num.value);
            num.index = l;
            num.col = 0;
            vet[l][0] = num;
            InsertData(&heap, num);
            for(c = 1; c < tam[l]; c++)
            {
                scanf("%lf", &num.value);
                num.index = l;
                num.col = c;
                vet[l][c] = num;
            }
        }
        
    }  

    //Calculo do resultado
    for(c = 0; c < i; c++)
    {  
        aux++;
        if(aux == i)
        {    
            double sum = Sum_Heap(&heap);
            printf("%.0f", sum);
            break;
        }
        extract = ExtractMin(&heap);
        tam[extract.index]--;
        if(tam[extract.index] != 0)
            InsertData(&heap, vet[extract.index][extract.col+1]);
    }
    
    return 0;
}