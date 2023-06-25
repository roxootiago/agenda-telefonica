#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTATOS 100

struct Contato {
    char nome[50];
    char telefone[15];
    char cidade[50];
};

struct Agenda {
    struct Contato listaContatos[MAX_CONTATOS];
    int numContatos;
};

void inicializarAgenda(struct Agenda *agenda) {
    agenda->numContatos = 0;
}

void capitalize(char *str) {
    int i = 0;

    // Converte o primeiro caractere para maiúscula
    if (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    // Converte os caracteres seguintes para minúscula, até encontrar o fim da string
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

void adicionarContato(struct Agenda *agenda) {
    if (agenda->numContatos >= MAX_CONTATOS) {
        printf("A lista de contatos está cheia.\n");
        return;
    }

    struct Contato novoContato;

    printf("Digite o nome do contato: ");
    scanf("%s", novoContato.nome);

    printf("Digite o número de telefone do contato: ");
    scanf("%s", novoContato.telefone);

    printf("Digite a cidade do contato: ");
    scanf("%s", novoContato.cidade);

    capitalize(novoContato.nome);
    capitalize(novoContato.cidade);

    agenda->listaContatos[agenda->numContatos] = novoContato;
    agenda->numContatos++;

    printf("Contato adicionado com sucesso.\n");
}

void exibirContatos(struct Agenda *agenda) {
    if (agenda->numContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    printf("Lista de contatos:\n");
    for (int i = 0; i < agenda->numContatos; i++) {
        printf("Nome: %s\n", agenda->listaContatos[i].nome);
        printf("Telefone: %s\n", agenda->listaContatos[i].telefone);
        printf("Cidade: %s\n", agenda->listaContatos[i].cidade);
        printf("-----------------\n");
    }
}

void buscarContato(struct Agenda *agenda) {
    if (agenda->numContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);

    capitalize(nomeBusca);

    int contatoEncontrado = 0,i;

    for (i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->listaContatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda->listaContatos[i].nome);
            printf("Telefone: %s\n", agenda->listaContatos[i].telefone);
            printf("Cidade: %s\n", agenda->listaContatos[i].cidade);
            printf("-----------------\n");
            contatoEncontrado = 1;
            break;
        }
    }

    if (!contatoEncontrado) {
        printf("Contato não encontrado.\n");
    }
}

void atualizarContato(struct Agenda *agenda) {
    if (agenda->numContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do contato que deseja atualizar: ");
    scanf("%s", nomeBusca);

    capitalize(nomeBusca);

    int contatoEncontrado = 0,i;

    for ( i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->listaContatos[i].nome, nomeBusca) == 0) {
            struct Contato *contato = &agenda->listaContatos[i];

            printf("Digite o novo nome do contato: ");
            scanf("%s", contato->nome);

            printf("Digite o novo número de telefone do contato: ");
            scanf("%s", contato->telefone);

            printf("Digite a nova cidade do contato: ");
            scanf("%s", contato->cidade);

            capitalize(contato->nome);
            capitalize(contato->cidade);

            printf("Contato atualizado com sucesso.\n");
            contatoEncontrado = 1;
            break;
        }
    }

    if (!contatoEncontrado) {
        printf("Contato não encontrado.\n");
    }
}

void excluirContato(struct Agenda *agenda) {
    if (agenda->numContatos == 0) {
        printf("A lista de contatos está vazia.\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do contato que deseja excluir: ");
    scanf("%s", nomeBusca);

    capitalize(nomeBusca);

    int contatoEncontrado = 0,i,j;

    for (i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->listaContatos[i].nome, nomeBusca) == 0) {
            for (j = i; j < agenda->numContatos - 1; j++) {
                agenda->listaContatos[j] = agenda->listaContatos[j + 1];
            }

            agenda->numContatos--;
            printf("Contato excluído com sucesso.\n");
            contatoEncontrado = 1;
            break;
        }
    }

    if (!contatoEncontrado) {
        printf("Contato não encontrado.\n");
    }
}