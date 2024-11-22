#include "Arvore.h"

// Remove quebra de linha no final de uma string
void remover_quebra_linha(char* str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
    }
}

// Inicializa a árvore retornando NULL (árvore vazia)
No* inicializar_arvore() {
    return NULL;
}

// Insere um livro na árvore binária
void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        *raiz = (No*)malloc(sizeof(No));
        if (*raiz == NULL) {
            printf("Erro ao alocar memória para o nó\n");
            return;
        }
        (*raiz)->livro = livro;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else if (strcmp(livro.Genero, (*raiz)->livro.Genero) <= 0) {
        inserir_livro(&((*raiz)->esquerda), livro);
    } else {
        inserir_livro(&((*raiz)->direita), livro);
    }
}


// Função para criar um novo livro
Livro criar_livro(int codigo, const char* titulo, const char* autor, const char* genero, int ano, const char* editora, int numero_pagina) {
    Livro livro;

    livro.Codigo = codigo;
    livro.Ano = ano;
    livro.Numero_pagina = numero_pagina;

    // Alocar memória e copiar as strings
    livro.Titulo = malloc(strlen(titulo) + 1);
    if (livro.Titulo == NULL) {
        printf("Erro ao alocar memória para o título.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(livro.Titulo, titulo);

    livro.Autor = malloc(strlen(autor) + 1);
    if (livro.Autor == NULL) {
        printf("Erro ao alocar memória para o autor.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(livro.Autor, autor);

    livro.Genero = malloc(strlen(genero) + 1);
    if (livro.Genero == NULL) {
        printf("Erro ao alocar memória para o gênero.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(livro.Genero, genero);

    livro.Editora = malloc(strlen(editora) + 1);
    if (livro.Editora == NULL) {
        printf("Erro ao alocar memória para a editora.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(livro.Editora, editora);

    return livro;
}

// Exibe informações de um livro
void getLivro(Livro livro) {
    printf("----- Livro %d -----\n", livro.Codigo);
    printf("Título: %s\n", livro.Titulo);
    printf("Autor: %s\n", livro.Autor);
    printf("Gênero: %s\n", livro.Genero);
    printf("Ano: %d\n", livro.Ano);
    printf("Editora: %s\n", livro.Editora);
    printf("Número de páginas: %d\n", livro.Numero_pagina);
}

// Busca livros por gênero na árvore
void buscar_por_genero(No* raiz, char genero[]) {
    if (raiz == NULL) return;

    
    if(raiz->livro.Genero <= genero){
    buscar_por_genero(raiz->esquerda, genero);
    }
    if (strcmp(raiz->livro.Genero, genero) == 0) {
        getLivro(raiz->livro);
    }
    if(raiz->livro.Genero > genero){
    buscar_por_genero(raiz->direita, genero);
    }
}

// Libera a memória de um nó e suas strings
void libera_arvore(No* raiz) {
    if (raiz == NULL) return;

    libera_arvore(raiz->esquerda);
    libera_arvore(raiz->direita);

    free(raiz->livro.Titulo);
    free(raiz->livro.Autor);
    free(raiz->livro.Genero);
    free(raiz->livro.Editora);
    free(raiz);
}

// Função para carregar livros de um arquivo CSV
No* carregar_livros(No* raiz, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return raiz;
    }

    char buffer[1030];
    while (fgets(buffer, sizeof(buffer), file)) {
        remover_quebra_linha(buffer);
        char* token = strtok(buffer, ",");
        if (token == NULL) continue;

        int codigo = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        char titulo[100];
        strcpy(titulo, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        char autor[100];
        strcpy(autor, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        char genero[100];
        strcpy(genero, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int ano = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        char editora[100];
        strcpy(editora, token);

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        int paginas = atoi(token);

        Livro livro = criar_livro(codigo, titulo, autor, genero, ano, editora, paginas);
        inserir_livro(&raiz, livro);
    }

    fclose(file);
    return raiz;
}


// Exibe todos os livros da árvore em ordem
void exibir_arvore(No* raiz) {
    if (raiz == NULL) return;

    exibir_arvore(raiz->esquerda);
    getLivro(raiz->livro);
    exibir_arvore(raiz->direita);
}

