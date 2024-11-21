#include "Arvore.h"


int main(void) {
    No* raiz = NULL;  // Inicializa a raiz da árvore
    Livro* livros = NULL;  // Para armazenar os livros carregados de um arquivo
    int numLivros = 0;     // Quantidade de livros carregados
    int opcao;
    char genero[100];
    char nomeArquivo[100];

    do {
        printf("\n#### MENU ####\n");
        printf("1 - Inicializar árvore\n");
        printf("2 - Inserir livro\n");
        printf("3 - Buscar por gênero literário\n");
        printf("4 - Carregar Arquivo CSV\n");
        printf("5 - Exibir árvore\n");
        printf("6 - Liberar árvore\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (raiz != NULL) {
                    libera_arvore(raiz);  // Libera a árvore atual, se existir
                }
                raiz = inicializar_arvore();
                printf("Árvore inicializada com sucesso!\n");
                break;

            case 2: {
                Livro novoLivro;
                novoLivro.Titulo = (char*)malloc(100 * sizeof(char));
                novoLivro.Autor = (char*)malloc(100 * sizeof(char));
                novoLivro.Genero = (char*)malloc(100 * sizeof(char));
                novoLivro.Editora = (char*)malloc(100 * sizeof(char));

                if (!novoLivro.Titulo || !novoLivro.Autor || !novoLivro.Genero || !novoLivro.Editora) {
                    printf("Erro ao alocar memória para o livro.\n");
                    free(novoLivro.Titulo);
                    free(novoLivro.Autor);
                    free(novoLivro.Genero);
                    free(novoLivro.Editora);
                    break;
                }

                printf("Digite o código do livro: ");
                scanf("%d", &novoLivro.Codigo);
                printf("Digite o título do livro: ");
                scanf(" %[^\n]", novoLivro.Titulo);
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]", novoLivro.Autor);
                printf("Digite o gênero do livro: ");
                scanf(" %[^\n]", novoLivro.Genero);
                printf("Digite o ano de publicação: ");
                scanf("%d", &novoLivro.Ano);
                printf("Digite a editora do livro: ");
                scanf(" %[^\n]", novoLivro.Editora);
                printf("Digite o número de páginas: ");
                scanf("%d", &novoLivro.Numero_pagina);

                inserir_livro(&raiz, novoLivro);
                printf("Livro inserido com sucesso!\n");
                break;
            }

            case 3:
                printf("Digite o gênero para buscar: ");
                scanf(" %[^\n]", genero);
                buscar_por_genero(raiz, genero);
                break;

                case 4:
                    printf("Digite o nome do arquivo CSV: ");
                    scanf(" %[^\n]", nomeArquivo);
                    raiz = carregar_livros(raiz, nomeArquivo);
                    if (raiz != NULL) {
                        printf("Livros carregados e inseridos na árvore com sucesso.\n");
                    } else {
                        printf("Erro ao carregar os livros do arquivo.\n");
                     }
                break;


            case 5:
                printf("Exibindo todos os livros da árvore em ordem alfabética:\n");
                exibir_arvore(raiz);
                break;

            case 6:
                if (raiz != NULL) {
                    libera_arvore(raiz);
                    raiz = NULL;  // Evitar uso de memória liberada
                    printf("Árvore liberada com sucesso!\n");
                } else {
                    printf("A árvore já está vazia.\n");
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    // Liberação final para evitar vazamento de memória
    if (raiz != NULL) {
        libera_arvore(raiz);
    }

    return 0;
}
