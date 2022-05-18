#include <iostream>
#include <list>

using namespace std;

int main(){
	list<int> lista;
	int opc = 0;
	int capacidade = 0;
	int valor = 0;
	int posicao = 0;
	int itemLista = 0;
	int qtde = 0;
	
	//loop para pegar capacidade da lista - so quebra se valor for maior que 0
	while(1){
		cout << "Digite o tamanho da lista: ";
		cin >> capacidade;
		capacidade-1;
	
		if(capacidade < 1){
			cout << "Nao e possivel criar lista com capacidade de 0 ou menor que 0\n\n";
			continue;
		}else{
			cout << "\nLista criada!\n";
			break;
		}
	}
	
	list<int>::iterator it;
	for(int i=0;i<capacidade;i++){
		lista.push_back(i);
	}
	
	int primeiroItem = lista.front();
	int ultimoItem = lista.back();
	
	while (1){
		cout << "\n\n1)Remover um item da lista\n";
		cout << "2)Adicionar valor na lista\n";
		cout << "3)Mostrar os valores da lista\n";
		cout << "4)Limpar toda a lista\n";
		cout << "5)Sair\n";
		cout << "\nDigite a opcao desejada: ";
		cin >> opc;
	
		switch(opc){
			
			case 1: 
				system("cls");
				cout << "\nValores da lista: ";
				for(it = lista.begin(); it!=lista.end();it++){
					cout << *it << " ";
				}
				//remove primeiro item
				cout << "\n\nQual a posicao do item que deseja remover: ";
				cin >> posicao;
				
				if (posicao == 1){
					lista.pop_front();
				}else if(posicao == lista.size()){
					lista.pop_back();
				}else{
					for(int i=0;i<lista.size();i++){
						if(i == posicao){
							
							lista.remove(posicao);
						}
					}		
					cout << "Removido com sucesso!!\n\n";
				}
				break;
			
			case 2:
				//insere valores
				system("cls");
				if (lista.size() < capacidade){
					cout << "Digite a quantidade: ";
					cin >> qtde;
					if(qtde > capacidade || qtde < 0) {
						cout << "A quantidade e invalida!\n\n";
					}else{
					cout << "Digite o valor: ";
					cin >> valor;
					lista.insert(it, qtde, valor);
					cout << "Inserido com sucesso!!\n\n";
					}
				}else{
					cout << "A lista esta cheia!!\n\n";
				}	
				break;
				
			case 3:
				//printa os valores da lista
				system("cls");
				cout << "\nValores da lista: ";
				for(it = lista.begin(); it!=lista.end();it++){
					cout << *it << " ";
				}
	
				break;
				
			case 4:
				//limpa a lista toda
				system("cls");	
				lista.clear();
				cout << "\nElementos removidos com sucesso!!\n";
				break;
			
			case 5:
				//encerra o programa
				system("cls");
				cout << "\nPrograma finalizado com sucesso!!";
				exit(0);
				break;
			
			default:
				cout << "\nAs opcoes sao apenas de 1 a 4!!\n\n";
				break;
		}
	
	}
	
	return 0;
}
