struct Aluno{
	char nome[50];
	int matricula;
	int idade;
	float nota1;
	float nota2;
	float media;
	int situacao = 2;
};

struct Node{
	Aluno aluno;
	Node* next;
};

struct Lista{
	int size;
	Node* inicio;
};

Lista* CriarLista();
void InserirInicio(Lista* lista, Aluno aluno);
void RemoverInicio(Lista* lista);
void PrintLista(Lista* lista);
Node* BuscarAluno(Lista* lista, int pos);
void BuscarMatricula(Lista* lista);
void RemoverPosicao(Lista* lista, int pos);
void InserirPosicao(Lista* lista, Aluno aluno, int pos);
void RemoverFim(Lista* lista);
void InserirFim(Lista* lista, Aluno aluno);
void MenuInserir(Lista* lista, Aluno aluno);
void MenuRemover(Lista* lista);
void BuscarPorAluno(Lista* lista, int pos);
void ImprimirMedia(Lista* lista, Node* node);
void MenuBusca(Lista* lista);
