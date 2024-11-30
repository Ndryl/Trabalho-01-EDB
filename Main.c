#include "Arvore.h"


int main(void) {
    No* raiz = NULL;  // Inicializa a raiz da árvore
    Livro* livros = NULL;  // Para armazenar os livros carregados de um arquivo
    int numLivros = 0;     // Quantidade de livros carregados
    int opcao;
    char genero[100];
    char nomeArquivo[100];
    int cont = 0;
    

    do {
        printf("\n#### MENU ####\n");
        printf("1 - Inserir livro\n");
        printf("2 - Buscar por gênero literário\n");
        printf("3 - Carregar Arquivo CSV\n");
        printf("4 - Exibir árvore\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int codigo;
                char titulo[100];
                char autor[100];
                char genero[100];
                int ano;
                char editora[100];
                int paginas;
                printf("Digite o código do livro: ");
                scanf("%d", &codigo);
                printf("Digite o título do livro: ");
                scanf(" %[^\n]", &titulo);
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]", &autor);
                printf("Digite o gênero do livro: ");
                scanf(" %[^\n]", &genero);
                printf("Digite o ano de publicação: ");
                scanf("%d", &ano);
                printf("Digite a editora do livro: ");
                scanf(" %[^\n]", &editora);
                printf("Digite o número de páginas: ");
                scanf("%d", &paginas);
                Livro livro = criar_livro(codigo, titulo, autor, genero, ano, editora, paginas);
                inserir_livro(&raiz, livro);
                printf("Livro inserido com sucesso!\n");
                break;
            }

            case 2:
                printf("Digite o gênero para buscar: ");
                scanf(" %[^\n]", genero);
                buscar_por_genero(raiz, genero, &cont);
                if(cont == 0){
                    printf("Este gênero não está registrado\n");
                }else if(cont ==1){
                    printf("Há %d livro do gênero %s\n", cont, genero);
                }else{
                    printf("Há %d livros do gênero %s\n", cont, genero);

                }
        
                break;

                case 3:
                    printf("Digite o nome do arquivo CSV: ");
                    scanf(" %[^\n]", nomeArquivo);
                    raiz = carregar_livros(raiz, nomeArquivo);
                    if (raiz != NULL) {
                        printf("Livros carregados e inseridos na árvore com sucesso.\n");
                    } else {
                        printf("Erro ao carregar os livros do arquivo.\n");
                     }
                break;


            case 4:
                int contBusca = 0;
                printf("Exibindo todos os livros da árvore em ordem alfabética:\n");
                exibir_arvore(raiz, &contBusca);
                printf("Total de Livros: %d", contBusca);
                break;

            case 0:
            if (raiz != NULL) {
                    libera_arvore(raiz);
                    raiz = NULL;  // Evitar uso de memória liberada
                    printf("Árvore liberada com sucesso!\n");
                } else {
                    printf("A árvore já está vazia.\n");
                }
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    if (raiz != NULL) {
        libera_arvore(raiz);
    }

    return 0;
}
