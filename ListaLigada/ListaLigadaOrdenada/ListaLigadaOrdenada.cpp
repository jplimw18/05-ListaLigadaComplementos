#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;


	if (primeiro == NULL)
	{
		primeiro = novo;
		return;
	}
	// procura o final da lista
	NO* aux = primeiro;

	if (novo->valor < aux->valor)
	{
		primeiro = novo;
		novo->prox = aux;
	}
	else if (novo->valor != aux->valor) {
		bool stop = false;
		while (!stop) {
			if (aux->prox == NULL)
			{
				aux->prox = novo;
				stop = !stop;
			}
			else if (novo->valor > aux->prox->valor)
			{
				aux = aux->prox;
			}
			else if (novo->valor == aux->prox->valor)
			{
				cout << "este numero ja existe na lista!" << endl;
				stop = !stop;
			}
			else
			{
				NO* temp = aux->prox;
				aux->prox = novo;
				novo->prox = temp;

				stop = !stop;
			}
		}
	}
	else
	{
		cout << "este numero ja existe na lista!" << endl;
	}
}

void excluirElemento()
{
	int valDelete = 0;
	cout << "Elemento para excluir: ";
	cin >> valDelete;


	if (primeiro == NULL)
	{
		cout << "Lista vazia." << endl;
		return;
	}

	if (valDelete < primeiro->valor)
	{
		cout << "Elemento nao existe na lista." << endl;
		return;
	}
	
	NO* aux = primeiro;
	bool _delete = false;

}

void buscarElemento()
{
	int valBusca = 0;
	cout << "Insira o elemento: ";
	cin >> valBusca;


	if (primeiro == NULL)
	{
		cout << "Lista vazia." << endl;
		return;
	}

	if (valBusca < primeiro->valor)
	{
		cout << "elemento nao existe na lista." << endl;
		return;
	}

	NO* aux = primeiro;
	bool find = false;

	while (aux != NULL && !find) {
		if (valBusca > aux->valor) {
			aux = aux->prox;
		}
		else
		{
			cout << "Elemento encontrado!" << endl;
			find = !find;
		}
	}

	if (!find) 
	{
		cout << "elemento nao existe na lista." << endl;
	}
}


