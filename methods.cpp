#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "header.h"

using namespace std;

Lista* CriarLista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if (lista == NULL){
		cout<<"Alocacao falhou.\n";
		exit(0);
	}
	system("cls");
	cout<<"Lista criada com sucesso.\n";
	lista->size = 0;
	lista->inicio = NULL;
	return lista;
}

void InserirInicio(Lista* lista, Aluno aluno){
	
	if(lista != NULL){
		Node* node = (Node*)malloc(sizeof(Node));
		node->aluno = aluno;
		node->next = lista->inicio;
		lista->inicio = node;
		if(node == NULL){
			cout<<"Alocacao falhou.\n";
			exit(0);
		}
	system("cls");
	cout<<"Aluno "<<node->aluno.nome<<", adicionado com sucesso ao inicio da lista.\n";
	lista->size++;
	}else{
		cout<<"Lista não criada.\n";
	}
}

void PrintLista(Lista* lista){
	Node* aux = lista->inicio;
	
	if(aux == NULL){
		cout<<"Lista vazia\n";
	}
	int c = 0;
	while(aux != NULL){
		cout<<"["<<c<<"]"<<aux->aluno.nome<<"\n";
		cout<<"Matricula: "<<aux->aluno.matricula<<"\n";
		cout<<"Idade: "<<aux->aluno.idade<<"\n";
		cout<<"Media final: "<<aux->aluno.media<<"\n";
		if(aux->aluno.media>=6){
			cout<<"Situacao: aprovado\n";
		}else{
			cout<<"Situacao: reprovado\n";
		}
		aux = aux->next;
		c++;
	}
	
}

void RemoverInicio(Lista* lista){
	if(lista != NULL){
		Node* aux = lista->inicio;
		lista->inicio = aux->next;
		cout<<"Aluno "<<aux->aluno.nome<<" removido.\n";
		free(aux);
		lista->size--;
		
	}else{
		cout<<"Lista não criada.\n";
	}
	
}

Node* BuscarAluno(Lista* lista, int pos){
		Node* aux = lista->inicio;
		int i = 0;
		
		if(pos>=0 && pos<lista->size){
			while(i<pos){
				aux = aux->next;
				i++;
			}return aux;
	}
}

void BuscarMatricula(Lista* lista){
	if(lista!=NULL){
		Node* aux = lista->inicio;
		int mat;
		cout<<"Digite a matricula\n";
		cin>>mat;
		
		int pos = 0;
		
		while(mat != aux->aluno.matricula && pos < lista->size){
			aux = aux->next;
			pos++;
			if(aux->next == NULL){
			cout<<"Matricula nao encontrada\n";
			}
		}
		cout<<"Aluno "<<aux->aluno.nome<<" de matricula "<<mat<<" se encontra na posicao ["<<pos<<"]\n";
		int choice;
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-\n";
		cout<<"Digite[1] para modificar as notas do aluno\n";
		cout<<"Digite outra tecla para retornar\n";
		cin>>choice;
		if(choice == 1){
			cout<<"Digite a nota n1:\n";
			cin>>aux->aluno.nota1;
			cout<<"Digite a nota n2:\n";
			cin>>aux->aluno.nota2;
			cout<<"Novas notas de "<<aux->aluno.nome<<":\n";
			cout<<"N1: "<<aux->aluno.nota1<<"\n";
			cout<<"N2: "<<aux->aluno.nota2<<"\n";
			aux->aluno.media = (aux->aluno.nota1*0.4)+(aux->aluno.nota2*0.6);
			cout<<"Media final: "<<aux->aluno.media<<"\n";
			if(aux->aluno.media >= 6){
				cout<<"Situacao: aprovado\n";
			}else{
				cout<<"Situacao: reprovado\n";
			}
		}
		
	} else{
		cout<<"Lista nao criada\n";
	}
}

void RemoverPosicao(Lista* lista, int pos){
	if(lista != NULL){
		if(pos == 0){
			RemoverInicio(lista);
		}else{
			Node* excluir = BuscarAluno(lista, pos);
			if(excluir != NULL){
				Node* anterior = BuscarAluno(lista, pos-1);
				anterior->next = excluir->next;
				cout<<"Aluno "<<excluir->aluno.nome<<", removido da lista\n";
				free(excluir);
				lista->size--;
			}
		}
	}else{
		cout<<"Lista nao criada.\n";
	}
}

void InserirPosicao(Lista* lista, Aluno aluno, int pos){
	if(lista != NULL){
		if(pos == 0){
			InserirInicio(lista, aluno);
		}else{
			Node* aux = BuscarAluno(lista, pos);
			if(aux != NULL){
				Node* anterior = BuscarAluno(lista, pos-1);
				Node* novoAluno = (Node*) malloc(sizeof(Node));
				novoAluno->aluno = aluno;
			
				anterior->next = novoAluno;
				novoAluno->next = aux;
				lista->size++;
				cout<<"Aluno "<<novoAluno->aluno.nome<<", adicionado na posicao ["<<pos<<"]\n";
			}
		}
	}else{
		cout<<"Lista nao criada.\n";
	}
}

void RemoverFim(Lista* lista){
	if(lista != NULL){
		Node* excluir = BuscarAluno(lista, lista->size-1);
		Node* anterior = BuscarAluno(lista, lista->size-2);
		cout<<"Aluno "<<excluir->aluno.nome<<" removido da lista\n";
		anterior->next = NULL;
		excluir = NULL;	
		free(excluir);
		lista->size--;
	}else{
		cout<<"Lista nao criada.\n";
	}
	
}

void InserirFim(Lista* lista, Aluno aluno){
	if(lista != NULL){
		Node* aux = BuscarAluno(lista, lista->size-1);
		if(aux != NULL){
			Node* novoAluno = (Node*) malloc(sizeof(Node));
			novoAluno->aluno = aluno;
			cout<<"Aluno "<<novoAluno->aluno.nome<<" adicionado ao fim da lista\n";
			aux->next = novoAluno;
			novoAluno->next = NULL;
			lista->size++;
		}
	}else{
		cout<<"Lista nao criada.\n";
	}
}

void MenuInserir(Lista* lista, Aluno aluno){
	int opc = 1;
	while(opc != 0){
		system("cls");
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
		cout<<"\nDigite[1] para inserir o aluno no inicio da lista";
		cout<<"\nDigite[2] para inserir o aluno em uma posicao da lista";
		cout<<"\nDigite[3] para inserir o aluno no final da lista";
		cout<<"\nDigite[0] para retornar\n";
		cin>>opc;
		
		while(opc<0 || opc>3){
			system("cls");
			cout<<"\nOpcao invalida";
			cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
			cout<<"\nDigite[1] para inserir o aluno no inicio da lista";
			cout<<"\nDigite[2] para inserir o aluno em uma posicao da lista";
			cout<<"\nDigite[3] para inserir o aluno no final da lista";
			cout<<"\nDigite[0] para retornar\n";
			cin>>opc;
		}
		switch(opc){
			case 1:
				InserirInicio(lista, aluno);
				opc = 0;
				break;
			case 2:
				int pos;
				cout<<"Em qual posicao gostaria de adicionar o aluno\n";
				cin>>pos;
				InserirPosicao(lista, aluno, pos);
				opc = 0;
				break;
			case 3:
				InserirFim(lista, aluno);
				opc = 0;
				break;	
		}
	}
}

void MenuRemover(Lista* lista){
	int opc = 1;
	while(opc != 0){
		system("cls");
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
		cout<<"\nDigite[1] para remover o aluno no inicio da lista";
		cout<<"\nDigite[2] para remover o aluno em uma posicao da lista";
		cout<<"\nDigite[3] para remover o aluno no final da lista";
		cout<<"\nDigite[0] para retornar\n";
		cin>>opc;
		
		while(opc<0 || opc>3){
			system("cls");
			cout<<"\nOpcao invalida";
			cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
			cout<<"\nDigite[1] para remover o aluno no inicio da lista";
			cout<<"\nDigite[2] para remover o aluno em uma posicao da lista";
			cout<<"\nDigite[3] para remover o aluno no final da lista";
			cout<<"\nDigite[0] para retornar\n";
			cin>>opc;
		}
		switch(opc){
			case 1:
				RemoverInicio(lista);
				opc = 0;
				break;
			case 2:
				int pos;
				cout<<"De qual posicao gostaria de remover o aluno\n";
				cin>>pos;
				RemoverPosicao(lista, pos);
				opc = 0;
				break;
			case 3:
				RemoverFim(lista);
				opc = 0;
				break;	
		}
	}
}

void BuscarPorAluno(Lista* lista, int pos){
		Node* aux = lista->inicio;
		int i = 0;
		
		if(pos>=0 && pos<lista->size){
			while(i<pos){
				aux = aux->next;
				i++;
			}cout<<"Aluno "<<aux->aluno.nome<<" se encontra na posicao ["<<pos<<"]\n";
		int choice;
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-\n";
		cout<<"Digite[1] para modificar as notas do aluno\n";
		cout<<"Digite outra tecla para retornar\n";
		cin>>choice;
		if(choice == 1){
			cout<<"Digite a nota n1:\n";
			cin>>aux->aluno.nota1;
			cout<<"Digite a nota n2:\n";
			cin>>aux->aluno.nota2;
			cout<<"Novas notas de "<<aux->aluno.nome<<":\n";
			cout<<"N1: "<<aux->aluno.nota1<<"\n";
			cout<<"N2: "<<aux->aluno.nota2<<"\n";
			aux->aluno.media = (aux->aluno.nota1*0.4)+(aux->aluno.nota2*0.6);
			cout<<"Media final: "<<aux->aluno.media<<"\n";
			if(aux->aluno.media >= 6){
				cout<<"Situacao: aprovado\n";
			}else{
				cout<<"Situacao: reprovado\n";
			}
		}
	}
}

void ImprimirMedia(Lista* lista, Node* node){
	float notaTot = 0;
	int i;
	Node* aux = node;
	
	for(i=0; i<lista->size; i++){
		notaTot = notaTot+aux->aluno.media;
		aux = aux->next;
	}
	cout<<"Media final da turma é: "<<notaTot/lista->size<<"\n";
}

void MenuBusca(Lista* lista){
	int opc = 1;
	while(opc != 0){
		system("cls");
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
		cout<<"\nDigite[1] para buscar um aluno pela posicao";
		cout<<"\nDigite[2] para buscar um aluno pela matricula";
		cout<<"\nDigite[0] para retornar\n";
		cin>>opc;
		
		while(opc<0 || opc>3){
			system("cls");
			cout<<"\nOpcao invalida";
			cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
			cout<<"\nDigite[1] para buscar um aluno pela posicao";
			cout<<"\nDigite[2] para buscar um aluno pela matricula";
			cout<<"\nDigite[0] para retornar\n";
			cin>>opc;
		}
		switch(opc){
			case 1:
				int pos;
				cout<<"Gostaria de buscar por qual posicao:\n";
				cin>>pos;
				BuscarPorAluno(lista, pos);
				opc = 0;
				break;
			case 2:
				BuscarMatricula(lista);
				opc = 0;
				break;
		}
	}
}





