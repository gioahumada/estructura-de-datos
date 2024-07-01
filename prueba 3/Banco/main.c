#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Banco {
    struct Cliente *clientes;
    struct NodoReclamos *raiz;
};

struct Cliente {
    char *rut;
    char *nombre;
    int edad;
    struct NodoTransaccion *head;
};

struct NodoTransaccion {
    struct Transaccion *datos;
    struct NodoTransaccion *sig;
};

struct Transaccion {
    int numero;
    int tipo;
    int ano;
    int mes;
    int monto;
};

struct NodoReclamos {
    struct Reclamo *reclamo;
    struct NodoReclamo *izq, *der;
};

struct Reclamo {
    int id;
    char *fecha;
    struct Transaccion *reclamada;
};

void sumarReclamos(struct NodoReclamos *abb, int *suma, int *cont, int ano) {
    if(abb != NULL) {
        if(ano == abb->reclamo->reclamada->ano) {
            *suma += abb->reclamo->reclamada->monto;
            *cont += 1;
        }
        sumarReclamos(abb->izq, suma, cont, ano);
        sumarReclamos(abb->der, suma, cont, ano);
    }
}

struct Cliente *buscarClienteConMasReclamosHistoricos(struct Banco *banco) {
    struct Cliente *cliente = NULL;
    int max = 0;
    int cont = 0;
    struct NodoReclamos *aux = banco->raiz;
    while(aux != NULL) {
        cont = 0;
        sumarReclamos(aux, &cont, 0);
        if(cont > max) {
            max = cont;
            cliente = buscarCliente(banco->clientes, aux->reclamo->reclamada->numero);
        }
        aux = aux->der;
    }
    return cliente;
}

float calcularPromedioMontoReclamos(struct NodoReclamos *rec, int ano) {
    int suma = 0;
    int cont = 0;
    sumarReclamos(rec, &suma, &cont, ano);
    return (float)suma / cont;
}

int main() {

}


