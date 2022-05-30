#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Aluno aluno;
	Lista* lista;
	int opc = 1;
	
	while(opc != 0){
		cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
		cout<<"\nDigite[1] para criar uma lista";
		cout<<"\nDigite[2] para inserir um aluno";
		cout<<"\nDigite[3] para remover um aluno";
		cout<<"\nDigite[4] para buscar um aluno";
		cout<<"\nDigite[5] para imprimir media da turma";
		cout<<"\nDigite[6] para imprimir lista de alunos";
		cout<<"\nDigite[0] para sair\n";
		cin>>opc;
		
		while(opc<0 || opc>6){
			system("cls");
			cout<<"\nOpcao invalida";
			cout<<"\n-=-=-=-=-MENU-=-=-=-=-";
			cout<<"\nDigite[1] para criar uma lista";
			cout<<"\nDigite[2] para inserir um aluno";
			cout<<"\nDigite[3] para remover um aluno";
			cout<<"\nDigite[4] para buscar um aluno";
			cout<<"\nDigite[5] para imprimir media da turma";
			cout<<"\nDigite[6] para imprimir lista de alunos";
			cout<<"\nDigite[0] para sair\n";
			cin>>opc;
		}
		
		switch(opc){
			case 1:
				lista = CriarLista();
				break;
			case 2:
				system("cls");
				cout<<"Digite o nome do aluno\n";
				cin>>aluno.nome;
				cout<<"Digite a matricula do aluno\n";
				cin>>aluno.matricula;
				cout<<"Digite a idade do aluno\n";
				cin>>aluno.idade;
				cout<<"Digite a nota 1 do aluno\n";
				cin>>aluno.nota1;
				cout<<"Digite a nota 2 do aluno\n";
				cin>>aluno.nota2;
				aluno.media = (aluno.nota1*0.4)+(aluno.nota2*0.6);
				if(aluno.media >= 6){
					aluno.situacao = 0;
				}else{
					aluno.situacao = 1;
				}
				MenuInserir(lista, aluno);
				break;
			case 3:
				system("cls");
				MenuRemover(lista);
				break;
			case 4:
				MenuBusca(lista);
				break;
			case 5:
				ImprimirMedia(lista, lista->inicio);
				break;
			case 6:
				PrintLista(lista);
				break;
		}
		
	}
	
	
	return 0;
}

