//
// Created by Martin Valente on 23/04/2026.
//

#ifndef PILAESTATICA_PILAESTATICA_H
#define PILAESTATICA_PILAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define TODO_OK 0
#define SIN_MEMORIA 1
#define PILA_VACIA 2

#define MINIMO(a,b)     ((a) < (b) ? (a) : (b))

typedef struct
{
    char pila[TAM];
    size_t tope;
}tPila;


void crearPila(tPila* p);
int poneEnPila(tPila* p, const void* d, size_t tamDato);
int sacarDePila(tPila* p, void* d, size_t tamData);
int esPilaVacia(const tPila* p);
int esPilaLlena(const tPila* p, size_t tamDato);
int verTopeDePila(const tPila* p, void* d, size_t tamDato);
void vaciarPila(tPila* p);

#endif //PILAESTATICA_PILAESTATICA_H
