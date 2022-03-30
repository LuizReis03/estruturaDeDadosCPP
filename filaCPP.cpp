#include <iostream>
using namespace std;

//define a estrutura que será a fila
typedef struct{
	int inicio = 0;
	int fim = 0;
	int item[5];
} FILA;

//retorna se a fila está vazia ou não 
bool filaVazia(FILA f){
	if(f.inicio == f.fim) {
		return true;
	}else{
		return false;
	}
}

//retorna se a fila está cheia ou não
bool filaCheia(FILA f){
	int tamanho = sizeof(f.item)/sizeof(int);
	
	if(f.fim < tamanho) {
		return false;
	}else {
		return true;
	}
	
}

//adiciona valor na fila
void enfileirar(FILA &f, int valor){
	f.item[f.fim++] = valor;
}


//remove valor na fila
int desenfilera(FILA &f){
	return(f.item[f.inicio++]);
}

//mostra os valores armazenados na fila
void mostraFila(FILA f) {
	cout << "Valores da fila: ";
	for(int i = f.inicio; i < f.fim; i++)  {
		cout << f.item[i] << " ";
	}
	cout << "\n";
}

//código para testar a implementação
int main() {
	FILA s; //cria fila
	
	//verifica que a fila está vazia
	if(filaVazia(s)) {
		cout << "A fila esta vazia!" << endl;
	}else{
		cout << "A fila nao esta vazia";
	}
	
	//Enfileira o valor e verifica se a fila está vazia
	enfileirar(s,10);
	if(filaVazia(s)) {
		cout << "A fila esta vazia" << endl;
	}else{
		cout << "A fila nao esta vazia" << endl;
	}
	
	//Insere 3 elementos na fila
	enfileirar(s,20);
	enfileirar(s,30);
	enfileirar(s,50);
	
	//mostra os valores da fila
	mostraFila(s);
	
	//verifica que a fila está cheia
	if(filaCheia(s)) {
		cout << "A fila esta cheia" << endl;
	}else{
		cout << "A fila nao esta cheia" << endl;
	}
	
	//enfileira valor e verifica se a fila esta cheia
	enfileirar(s,50);
	mostraFila(s);
	if(filaCheia(s)){
		cout << "A fila esta vazia" << endl;
	}else{
		cout << "A fila nao esta vazia" << endl;
	}
	
	//desempilha e mostrar o valor desempilhado
	cout << "Valor removido da fila: " << desenfilera(s) << endl;
	
	mostraFila(s);
	
	if(filaCheia(s)) {
		cout << "A fila esta cheia" << endl;
	}else{
		cout << "A fila nao esta cheia" << endl;
	}
	
	return 0;
}





