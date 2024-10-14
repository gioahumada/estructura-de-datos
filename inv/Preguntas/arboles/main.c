struct Nodo* insertar(struct Nodo* nodo, int valor) {
    if (nodo == NULL) {
        return nuevoNodo(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }
    return nodo;
}

int main() {
    struct Nodo* raiz = nuevoNodo(50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 30);
}
