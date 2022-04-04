#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;
	
//CRIA ESTRUTURA DE UMA PILHA
struct pilha{
	
	int topo;
	int capacidade;
	float *pElem;
	
};

pilha p;

//FUNÇÃO PARA CRIA UMA PILHA
void criaPilha (struct pilha *p, int capacidade){
	p -> topo -1;
	p -> pElem = (float*) malloc (capacidade *sizeof(float));
}


//FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ VAZIA
int verificaPilhaVazia (struct pilha*p){
	if (p -> topo == -1 ){
		return 1;
	}
	else{
		return 0;
	}
}

//FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ CHEIA
int verificaPilhaCheia(struct pilha*p) {
	if(p->topo == p->capacidade -1){
		return 1;
	}else{
		return 0;
	}
}

//FUNÇÃO PARA ADICIONAR A PILHA
void empilha (struct pilha*p, float n ){
	p-> topo++;
	
	p->pElem[p->topo] = n;
	
}

//FUNÇÃO PARA RETIRAR DA PILHA
float desempilha (struct pilha*p){
	p-> topo--;
	
	float gerencia = p->pElem[p->topo];
	
	return gerencia;
	
}

//
float retornaAoTopo(struct pilha*p) {
	return p->pElem [p->topo];
}

int main() {
	struct pilha novaPilha;
	int  capacidade = 0;
	int opcao = 0;
	float valor = 0.0;
	
	cout << "Digite a capacidade da pilha: " << endl;
	cin >> capacidade;
	criaPilha(&novaPilha, capacidade);
	
	
	while (1){
		cout << "\n1)Empilhar\n";
		cout << "2)Desempilhar\n";
		cout << "3)Mostrar topo da pilha\n";
		cout << "4)Sair\n";
		cout << "\nDigite a opcao desejada: ";
		cin >> opcao;
		
		switch(opcao){
			//empilha
			case 1: 
				if (verificaPilhaCheia(&novaPilha) == 1){
					cout << "\nA pilha esta cheia!\n";
				}else{
					cout << "Digite o valor: ";
					cin >> valor;
					empilha(&novaPilha, valor);
				}
				break;
			//desempilha
			case 2:
				if (verificaPilhaVazia(&novaPilha) == 1){
					cout << "\nA pilha esta vazia!\n";
				}else{
					valor = desempilha(&novaPilha);
					cout << "\nFoi desempilhado!\n";
				}
				break;
			//mostra o topo da lista
			case 3:
				if (verificaPilhaVazia(&novaPilha) == 1){
					cout << "\nA pilha esta vazia!\n";
				}else{
					valor = retornaAoTopo(&novaPilha);
					cout << "\nO topo da pilha e: " << valor << "\n";
				}
				break;
			//sai do loop
			case 4:
				exit(0);
				break;
			//opção diferente de 1 ou 4, para o sistema
			default:
				cout << "\nAs opcoes sao apenas de 1 a 4!!\n\n";
    			break;
		}
		
	}
	
}
