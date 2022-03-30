#include <iostream>
#define tamanho 5
using namespace std;

//define a estrutura que será a pilha
//a estrutura armazena a indicação do topo da pilha e um vetor com os itens (valores) da pilha
typedef struct{
      int topo = 0;
      int item [tamanho] ;
} PILHA;

  
//retorna se a pilha está vazia ou não
bool pilhaVazia(PILHA p){
    if(p.topo == 0) {
        return true;
    } else {
        return false;
    }
}

//retorna se a pilha está cheia ou não
bool pilhaCheia(PILHA p) {
	int tam = sizeof(p.item)/sizeof(int); //determina o tamanho do vetor
	
    if (p.topo < tam) {
        return false;
    } else {
        return true;
    }
}

//adiciona valor na pilha
void empilha(PILHA &p, int x){
    p.item[p.topo++]=x;
}

//remove valor da pilha
int desempilha(PILHA &p){
    return (p.item[--p.topo]) ;
}

//mostra os valores armazenados na pilha
void mostraPilha(PILHA p) {
	cout << "Valores da pilha: ";
	for (int i = 0; i < p.topo; i++) {
		cout << p.item[i] << " ";
	}
	cout << "\n";
}

//Código para testar a implementação.
int main(){
    PILHA s; //criar a pilha
    
    //Verificar que a pilha está vazia
    if(pilhaVazia(s)) {
        cout<<"A pilha está vazia."<<endl;
    } else {
        cout<<"A pilha não está vazia."<<endl;
    }
    
    //Empilha valor e verifica se a pilha está vazia
    empilha(s,10);
    if(pilhaVazia(s)) {
        cout<<"A pilha está vazia."<<endl;
    } else {
        cout<<"A pilha não está vazia."<<endl;
    }
    
    //Empilhar 3 elementos
    empilha(s,20);
    empilha(s,30);
    empilha(s,40);

	//Mostra os valores da pilha
    mostraPilha(s);
    
    //Verifica que a pilha está cheia
    if(pilhaCheia(s)) {
        cout<<"A pilha está cheia."<<endl;
    } else {
        cout<<"A pilha não está cheia."<<endl;
    }
    
    //Empilha valor e verifica se a pilha está cheia
    empilha(s,50);
    mostraPilha(s);
    if(pilhaCheia(s)) {
        cout<<"A pilha está cheia."<<endl;
    } else {
        cout<<"A pilha não está cheia."<<endl;
    }
    
    //Desempilha e mostrar o valor desempilhado
    cout<<"Valor desempilhado: "<< desempilha(s) <<endl;

	mostraPilha(s);
	
    return 0;
}
