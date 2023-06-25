#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    struct Agenda agenda;
    inicializarAgenda(&agenda);

    int opcao;

    do {
        printf("Selecione uma opção:\n");
        printf("1. Adicionar contato\n");
        printf("2. Exibir contatos\n");
        printf("3. Buscar contato por nome\n");
        printf("4. Atualizar contato\n");
        printf("5. Excluir contato\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(&agenda);
                break;
            case 2:
                exibirContatos(&agenda);
                break;
            case 3:
                buscarContato(&agenda);
                break;
            case 4:
                atualizarContato(&agenda);
                break;
            case 5:
                excluirContato(&agenda);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
