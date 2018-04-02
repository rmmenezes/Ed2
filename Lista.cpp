#include "Lista.h"
#include <iostream>
#include <stdio.h>

using namespace std;
Lista::Lista(void)
{
    iSize=0;//ctor
}

Lista::~Lista()
{
    //dtor
}

// retorna o número de objetos da lista
int Lista::getSize(void) const{
    return iSize;
}

//Retorna o objeto existente em uma determinada posição da lista
//Caso a posição seja inválida, retorna diferente de zero
int Lista::getData(int pos, T& elem) const
{
    if (pos < 0 || pos >= iSize)
    {
        cerr << "Posição inválida!!!" << endl;
    return 1;
    }
    elem = listData[pos];
    return 0;
}

//Altera o conteudo da lista em uma determinada posição
int Lista::setData(int pos, T& data)
{
    if (pos < 0 || pos >= iSize)
    {
        cerr << "Posição inválida!!!" << endl;
        return 1;
    }
    listData[pos] = data;
    return 0;
}

// Insere um objeto no final da lista
int Lista::insert(const T& item)
{
    //Caso o número de posições máximo tenha sido atingindo retorna
    if (iSize >= iMaxListSize){
        cerr << "O tamanho máximo da lista foi atingido!" << endl;
        return 1;
    }
    // Insere um objeto no final da lista
    listData[ iSize] = item;
    // Incrementa o número de objetos
    iSize++;
    return 0;
}
// Procura por um item na lista e remove a primeira ocorrência
int Lista::remove(const T& item)
{
    //Inicializa variável ii que será utilizada para percorrer a lista
    int ii(0);
    // Procura por um objeto
    while (ii < iSize && !(item == listData[ii] ))
        ii++;
    //Caso ii seja igual ou maior que iSize, então não foi encontrado
    if (ii == iSize)
        return 1;
    //Decrementa o tamanho da lista
    iSize--;
    // move os objetos seguintes da lista para esquerda uma posição,
    //ou seja o objeto da posição ii+1 será colocado na posição ii
    while (ii < iSize)
    {
        listData[ ii] = listData[ ii+1] ;
        ii++;
    }
    return 0;
}


// Remove todos os objetos da lista
void Lista::removeAll(void){
iSize = 0;
}
// Remove o primeiro objeto da lista e retorna o valor removido
//Caso a posição seja inválida, o programa return diferente de zero
int Lista::removeFirst(T& item)
{
    // Caso a Lista esteja Vazia, finaliza o programa
    if (isEmpty())
    {
        cerr << "Erro! Lista vazia..." << endl;
        return 1;
    }
    //Recupera o primeiro objeto
    item = listData[0] ;
    //Remove o primeiro objeto
    remove(item);
    // retorna 0 - remoção bem sucedida
    return 0;
}

// Verifica se a lista está vazia
bool Lista::isEmpty(void) const
{
    return iSize==0;
}

//Este método irá percorrer a lista a fim de encontrar o objeto
//Caso o mesmo não seja encontrado retorna false
bool Lista::find(T& item) const
{
    int ii(0);
    //Caso a lista seja vazia retorna false
    if (isEmpty())
        return false;
    //Procura pelo objeto na lista
    while (ii < iSize && !(item == listData[ ii] ))
        ii++;
    //Caso ii seja igual ao tamanho da lista, indica que o item
    //nao foi encontrado
    if (ii == iSize)
        return false;
    return true;
}
//Imprime o conteúdo da lista
void Lista::print()const
{
    int ii(0);
    //Caso a lista seja vazia retorna
    if (isEmpty()){
        cout << "Lista Vazia!" << endl;
        return;
    }
    cout << "[";
    while (ii < iSize)
    {
        cout << listData[ ii] <<" ";
        ii++;
    }
    cout << "]"<<endl;
}

//- bubblesort sem melhorias
void Lista::bubbleSort(void){
	int aux;
	for(int i=0; i<iSize; i++){
		for(int j=0; j<iSize; j++){
			if(listData[j] <= listData[i]){
				aux = listData[i];
				listData[i] = listData[j];
				listData[j] = aux;
			}
		}
	}
}


//- bubblesort que itera até a última posiçao em que ocorreu troca
void Lista::bubbleSort2(void){
	int aux;
	for(int i=0; i<iSize; i++){
		for(int j=i; j<iSize-i-1; j++){
			printf("[%d][%d]\n", i, j);
			if(listData[j] > listData[i]){
				aux = listData[i];
				listData[i] = listData[j];
				listData[j] = aux;
			}
		}
	}
}

//- bubblesort que só itera enquanto ocorrer troca
int Lista::bubbleSort3(void){
	int aux = 0;
	for(int i=0; i<iSize; i++){
		for(int j=i; j<iSize-i-1; j++){
			printf("[%d][%d]\n", i, j);

			if(listData[j] > listData[i]){
				aux = listData[i];
				listData[i] = listData[j];
				listData[j] = aux;
			}
		}
		if(aux == 0){
			return 0;
		}
	}
}


void Lista::selectionSort(void){
	int i, j, menor, indice, cont;
	for(i=0; i<iSize-1; i++){
		cont=0;
		menor = listData[i];
		for(j=i; j<iSize; j++){
			if(listData[j] <-+- menor){
				menor = listData[j];
				indice = j;
				cont++;
			}
		}
		if(cont!=0){
			listData[indice] = listData[i];
			listData[i] = menor;
		}
	}
}

int main(){
	Lista *l = new Lista();
/*	l->insert(10);
	l->insert(52);
	l->insert(3);
	l->insert(69);
	l->insert(0);
	l->insert(1);
	l->insert(4);
	l->insert(-3);
	l->insert(7);
	l->insert(9);
	l->insert(32);
	l->insert(98);*/
	
	l->insert(5);
	l->insert(4);
	l->insert(3);
	l->insert(2);
	l->insert(1);
	l->insert(0);

	cout << "ORIGINAL\n";
	l->print();

/*	cout << "bubblesort sem melhorias"
	l->bubbleSort();
	l->print();

	
	cout << "bubblesort que so itera enquanto ocorrer troca\n";
	l->bubbleSort3();
	l->print();
*/
	cout << "bubblesort que itera ate a ultima posiçao em que ocorreu troca\n";
	l->bubbleSort2();
	l->print();

return 0;
}
