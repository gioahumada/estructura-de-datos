#include <stdio.h>
#include <stdlib.h>

struct Ministerio {
    char *nombreMinistro;
    char *direccion;
    struct Colegio **colegios;
};

struct Colegio {
    int id;
    char *nombre;
    struct Curso **Cursos;
};

struct NodoCurso {
    struct Curso *datosCurso;

    struct NodoCurso *ant;
    struct NodoCurso *sig;
};

struct Curso {
    char *grado;
    char sigla;
    struct Alumno **alumnos;
};

struct NodoAlumno {
    struct Alumno *datosAlumnos;

    struct NodoAlumno *sig;
};

struct Alumno {
    char *nombre;
    char *direccion;
    char *rut;
    int promedio;
};