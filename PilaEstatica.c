//
// Created by Martin Valente on 23/04/2026.
//

#include "PilaEstatica.h"

void crearPila(tPila* p, const void* d, size_t tamDato)
{
    p->tope = TAM;
}

int poneEnPila(tPila* p, const void* d, size_t tamDato)
{
    if(p->tope < tamDato + sizeof(size_t))
        return SIN_MEMORIA;

    p->tope -= tamDato;
    memcpy(p->pila + p->tope, d, tamDato);

    p->tope -= sizeof(size_t);
    memcpy(p->pila + p->tope, &tamDato, sizeof(size_t));

    return TODO_OK;
}

int sacarDePila(tPila* p, void* d, size_t tamData)
{
    size_t tamDataPila;

    if(p->tope == TAM)
        return PILA_VACIA;

    memcpy(&tamDataPila, p->pila + p->tope, sizeof(size_t));
    p->tope += sizeof(size_t);

    memcpy(d, p->pila + p->tope, MINIMO(tamDataPila, tamData));
    p->tope += tamDataPila;     //es la información que saque de la pila con el tamaño real para apuntar al siguiente

    return TODO_OK;
}

int esPilaVacia(const tPila* p)
{
    return p->tope == TAM;
}

int esPilaLlena(const tPila* p, size_t tamDato)
{
    return p->tope < (tamDato + sizeof(size_t));
}

int verTopeDePila(const tPila* p, void* d, size_t tamDato)
{
    size_t tamDatoPila;

    if(p->tope == TAM)
        return PILA_VACIA;

    memcpy(&tamDatoPila, p->pila + p->tope, sizeof(size_t));
    memcpy(d, p->pila + p->tope + sizeof(size_t), MINIMO(tamDatoPila, tamDato));

    return TODO_OK;
}

void vaciarPila(tPila* p)
{
    p->tope = TAM;
}