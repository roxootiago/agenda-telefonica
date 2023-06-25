#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#define MAX_CONTATOS 100

struct Contato {
    char nome[50], cidade[50], telefone[14];
};

struct Agenda {
    struct Contato listaContatos[MAX_CONTATOS];
    int numContatos;
};

#endif // AGENDA_H_INCLUDED
