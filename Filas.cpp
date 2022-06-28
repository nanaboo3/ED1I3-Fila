#include <iostream>
#include <stdlib.h>
using namespace std;

struct senhasGeradas
{
	int ini;
	int fim;
	float senha[];
};

struct senhasAtendidas
{
	int ini;
	int fim;
	float senha[];
};

senhasGeradas* init()
{
	senhasGeradas *sg = new senhasGeradas;
	sg->ini = 0;
	sg->fim = 0;
	return sg;
}

senhasAtendidas* initsa()
{
	senhasAtendidas *sa = new senhasAtendidas;
	sa->ini = 0;
	sa->fim = 0;
	return sa;
}

int incremento(int i)
{
	int retorno;
	retorno = i + 1;
	return retorno;
}

int vazio(senhasGeradas *sg)
{
	return (sg->ini == sg->fim);
}

int count(senhasGeradas *sg)
{
	int qtde = 0;
	int i = sg->ini;
	while (i != sg->fim)
	{
		qtde++;
		i = incremento(i);
	}
	return qtde;
}

void escrevaSG(senhasGeradas *sg)
{
	free(sg);
}

void escrevaSA(senhasAtendidas *sa)
{
	free(sa);
}

int geraSenha(senhasGeradas *sg, int n)
{
	int podeGera = (incremento(sg->fim) != sg->ini);
	if (podeGera)
	{
		cout << ("\nSenha criada com sucesso.");
		sg->senha[sg->fim] = n;
		sg->fim = incremento(sg->fim);
	}

	return podeGera;
}

float atendeSenha(senhasGeradas *sg, senhasAtendidas *sa)
{
	float retorno;
	if (vazio(sg))
	{
		retorno = -1;
		cout << ("Gere uma senha para ser atendida");
		cout << endl << ("-----------------------------") << endl;
	}
	else
	{
		cout << "Senha atendida: " << sg->senha[sg->ini] << endl;
		retorno = sg->senha[sg->ini];
		sg->ini = incremento(sg->ini);
		sa->senha[sa->fim] = sg->senha[sg->ini];
		sa->fim = incremento(sa->fim);
		cout << endl << ("-----------------------------") << endl;
	}
	return retorno;
}

void printNaoAtendida(senhasGeradas *sg)
{
	int i = sg->ini;
	cout << ("Senhas esperando atendimento: ") << endl;
	while(i < sg->fim)
	{
		cout << sg->senha[i];
		cout << (" // ");
		i = incremento(i);
	}
	cout << endl << ("-----------------------------") << endl;
}

void printAtendida(senhasAtendidas *sa)
{
	int i = sa->ini;
	cout << ("Senhas atendidas: ");
	//cout << sa->senha[i] << endl;
	while(i < sa->fim)
	{
		cout << sa->senha[i] - 1;
		cout << (" // ");
		i = incremento(i);
	}
	cout << endl << ("-----------------------------") << endl;
}

int main()
{
	senhasGeradas *sg = new senhasGeradas;
	sg = init();
	senhasAtendidas *sa = new senhasAtendidas;
	sa = initsa();
	int fin, choice;
	int n = 1;
	do
	{
		printNaoAtendida(sg);
		printAtendida(sa);
		cout << ("\n0. Sair\n1. Gerar senha\n2. Realizar atendimento\n");
		cout << ("\nDigite uma das opcoes acima: ");
		cin >> choice;
		switch(choice)
		{
		case 0:
			if(vazio(sg))
			{
				fin = 10;
			}
		break;
		case 1:
			geraSenha(sg, n);
			cout << endl;
			n++;
		break;
		case 2:
			atendeSenha(sg, sa);
			cout << endl << (sa->ini) << endl << (sa->fim);
			cout << ("\n");
		break;
		default:
			cout << ("Numero incorreto!") << endl;
		break;
		}
	}
	while(fin != 10 || vazio(sg));
}