#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "agenda.h"

void inicializarAgenda(struct Agenda *agenda);
void adicionarContato(struct Agenda *agenda);
void exibirContatos(struct Agenda *agenda);
void buscarContato(struct Agenda *agenda);
void atualizarContato(struct Agenda *agenda);
void excluirContato(struct Agenda *agenda);

#endif // FUNCOES_H_INCLUDED
