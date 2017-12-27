//=====================================================
// Arquivo: ordenacao.h
//
// Autores: Ana Paula Fernandes de Souza
//          Renata Caroline Cunha
// Data: 31/07/2016
// Disciplina: Programacao II - AED
//=====================================================

#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct dados *Ordena;

Ordena OPcriaVetor(int qtd);

void OPdestroiVetor(Ordena p);

void OPgeraValores(Ordena p);

Ordena OPcopiaVetor(Ordena p);

void OPtrocaValores(Ordena p,int pos1,int pos2);

int OPcomparaValores(Ordena p,int pos1,int pos2);

void OPmetodoBolha(Ordena p);

void OPsalvaResultado(Ordena p,char *nome,double tempo);

void OPmetodoInsercao(Ordena p,int min,int max);

void OPmetodoQuickSort(Ordena p,int min,int max);

void OPmetodoQuickTurbinado(Ordena p,int min,int max);

unsigned long int OPretornaComparacoes(Ordena p);

unsigned long int OPretornaTroca(Ordena p);

#endif /* ORDENACAO_H */