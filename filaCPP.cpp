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
	cout << "\nValores da fila: ";
	for(int i = f.inicio; i < f.fim; i++)  {
		cout << f.item[i] << " ";
	}
	cout << "\n\n";
}

//código para testar a implementação
int main() {
	FILA s; //cria fila
	int opc = 0;
	int valor = 0;
	
	while(1){
		cout << "Digite a opcao que deseja: \n1-Adicionar valor na lista \n2-Remover valor da lista \n3-Mostrar os valores da lista \n4-Sair\n\n";
		cin >> opc;
		cout << "\n";
			
		switch (opc) {
			case 1:
				if(filaCheia(s)) {
			        cout<<"\nA fila esta cheia.\n\n";
			    } else {
			        cout << "\nDigite o valor que deseja inserir na fila: ";
					cin >> valor;
					enfileirar(s, valor);
					cout << "\nAdicionado com sucesso!\n\n";
			    }
				break;
			case 2:
				if(filaVazia(s)) {
			        cout<<"\nA fila esta vazia.\n\n";
			    }else{
			    	desenfilera(s);
					cout << "\nRemovido com sucesso!\n\n";
				}
				break;
			case 3:
				mostraFila(s);
				break;
			case 4:
				cout << "\n\nPrograma fechado!";
				exit(0);
				break;
			default:
            	cout << "\nAs opcoes sao apenas de 1 a 4!!\n\n";
    			break;
		}

	}
	
	return 0;
}
