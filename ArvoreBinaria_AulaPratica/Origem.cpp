#include<stdio.h>
#include<stdlib.h>

struct ElementoDaArvoreBinaria {
	int dado;
	struct ElementoDaArvoreBinaria* direita, * esquerda;
};

void Inserir(ElementoDaArvoreBinaria** ElementoVarredura, int num);
int menu();
int menu2();
ElementoDaArvoreBinaria* Buscar(ElementoDaArvoreBinaria** ElementoVarredura, int num);
void Listar_EmOrdem(ElementoDaArvoreBinaria* ElementoVarredura);
void Listar_EmPreOrdem(ElementoDaArvoreBinaria* ElementoVarredura);
void Listar_EmPosOrdem(ElementoDaArvoreBinaria* ElementoVarredura);

int main() {

	int op, op2, num, pos, c, res;

	ElementoDaArvoreBinaria* root;
	root = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));
	root = NULL;

	ElementoDaArvoreBinaria* ElementoDeBusca;
	ElementoDeBusca = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));

	while (1) {
		op = menu();
		switch (op)
		{

		case 1: //adicionar elemento na arvore
			printf("Digite um numero para inserir na Arvore: ");
			scanf_s("%d", &num);
			c = getchar();
			Inserir(&root, num);
			break;
		case 2: //buscar elemento na arvore
			printf("Digite o numero a ser buscado: ");
			scanf_s("%d", &num);
			c = getchar();
			ElementoDeBusca = Buscar(&root, num);
			if (ElementoDeBusca != 0)
				printf("Valor localizado.\n");
			else
				printf("Valor nao encontrado na arvore.\n");
			system("pause");
			break;
		case 3: // listar arvore 
			op2 = menu2();
			switch (op2)
			{

			case 1: // listar em ordem
				printf("\n");
				printf("Consulta da Arvore em Ordem: \n");
				Listar_EmOrdem(root);
				system("pause");
				break;
			case 2: // lstar em pre ordem
				printf("\n");
				printf("Consulta da Arvore em Pre-Ordem: \n");
				Listar_EmPreOrdem(root);
				system("pause");
				break;
			case 3: // listar em pos ordem
				printf("\n");
				printf("Consulta da Arvore em Pos-Ordem: \n");
				Listar_EmPosOrdem(root);
				system("pause");
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Opcao Invalida: ");
				break;
			}
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("Opcao Invalida: ");
			break;
		}
	}

	return 0;
}

int menu() {
	int res, c;
	system("Cls");
	printf("******** ARVORE BINÁRIA *********\n");
	printf("1 - Adicionar Elemento na Arvore\n");
	printf("2 - Buscar Elemento na Arvore\n");
	printf("3 - Listar Arvore \n");
	printf("4 - Sair\n");

	printf("Escolha uma opcao: ");
	scanf_s("%d", &res);
	c = getchar();
	system("Cls");

	return res;
}

int menu2() {
	int res, c;
	system("Cls");
	printf("******** ARVORE BINÁRIA *********\n");
	printf("1 - Listar em Ordem\n");
	printf("2 - Listar em Pre-Ordem\n");
	printf("3 - Listar em Pos-Ordem\n");
	printf("4 - Sair\n");

	printf("Escolha uma opcao: ");
	scanf_s("%d", &res);
	c = getchar();
	system("Cls");

	return res;
}

void Inserir(ElementoDaArvoreBinaria** ElementoVarredura, int num) {

	if (*ElementoVarredura == NULL)
	{ //SE ESTÁ VAZIO, COLOCA NA ÁRVORE
		ElementoDaArvoreBinaria* NovoElemento = NULL;
		NovoElemento = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->dado = num;
		*ElementoVarredura = NovoElemento;
		return;
	}

	if (num < (*ElementoVarredura)->dado)
	{
		Inserir(&(*ElementoVarredura)->esquerda, num);
	}
	else
	{
		if (num > (*ElementoVarredura)->dado)
		{
			Inserir(&(*ElementoVarredura)->direita, num);
		}
	}
}

ElementoDaArvoreBinaria* Buscar(ElementoDaArvoreBinaria** ElementoVarredura, int num){
	
	if (*ElementoVarredura == NULL)
		return NULL;

	if (num < (*ElementoVarredura)->dado)
		Buscar(&((*ElementoVarredura)->esquerda), num);

	else if (num > (*ElementoVarredura)->dado) 
		Buscar(&((*ElementoVarredura)->direita), num);

	else if (num == (*ElementoVarredura)->dado)
			return *ElementoVarredura;
}
void Listar_EmOrdem(ElementoDaArvoreBinaria *ElementoVarredura) {
	if (ElementoVarredura)
	{
		Listar_EmOrdem(ElementoVarredura->esquerda);
		printf("%d\t\n", ElementoVarredura->dado);
		Listar_EmOrdem(ElementoVarredura->direita);
	}
}

void Listar_EmPreOrdem(ElementoDaArvoreBinaria* ElementoVarredura) {
	if (ElementoVarredura)
	{
		printf("%d\t\n", ElementoVarredura->dado);
		Listar_EmOrdem(ElementoVarredura->esquerda);
		Listar_EmOrdem(ElementoVarredura->direita);
	}
}

void Listar_EmPosOrdem(ElementoDaArvoreBinaria* ElementoVarredura) {
	if (ElementoVarredura)
	{
		Listar_EmOrdem(ElementoVarredura->esquerda);
		Listar_EmOrdem(ElementoVarredura->direita);
		printf("%d\t\n", ElementoVarredura->dado);
	}
}
