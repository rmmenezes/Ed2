#include <stdio.h>

void imprimeVetor(int vet[], int n){
	for(int i=0; i<n; i++){
		printf("[%d] ", vet[i]);
	}
	printf("\n");
}

void maxheap(int vet[], int n, int i){
	int direita = i*2 + 1;
	int esquerda = i*2 + 2;
	int maior = i;
	int aux;
	if(direita < n && vet[direita] > vet[maior]){
		maior = direita;
	}
	if(esquerda < n && vet[esquerda] > vet[maior]){
		maior = esquerda;
	}
	if(maior != i){
		aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;

		maxheap(vet, n, maior);
	}
}

void heapSort(int vet[], int n){
	int aux;
	for(int i=(n/2)-1; i>=0; i--){
		maxheap(vet, n, i);
	}
	for(int i=n-1; i>=0; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		maxheap(vet, i, 0);
	}
}


int main(){
	int n = 11;
	int vet[] = {51,26,0,10,2,15,6,54,66,18,9};
	imprimeVetor(vet, n);
	heapSort(vet, n);
	imprimeVetor(vet, n);
	return 0;
}

