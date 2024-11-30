#ifndef ARVORE_H
#define ARVORE_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Livro{

	int Codigo;
	char* Titulo;
	char* Autor;
	char* Genero;
	int Ano;
	char* Editora;
	int Numero_pagina;


};
typedef struct Livro Livro;
struct No{
	Livro livro;
	struct No* esquerda;
	struct No* direita;

};
typedef struct No No;

Livro criar_livro(int codigo, const char* titulo, const char* autor, const char* genero, int ano, const char* editora, int numero_pagina);
No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void getLivro(Livro livro);
void buscar_por_genero(No* raiz, char genero[], int* cont);
No* carregar_livros(No* raiz, char* nome_arquivo);
void libera_arvore(No* raiz);
void exibir_arvore(No* raiz, int* cont);
void remover_quebra_linha(char* str);


#endif
