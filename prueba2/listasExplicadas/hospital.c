#include <stdio.h>
#include <stdlib.h>

struct Hospital {
    char *nombre;
    char *director;
    struct Habitacion *habitaciones;
};

struct Habitacion {
    char letra;
    int id;
    char *tipoDeSala;
    struct Paciente *pacientes;
    struct Habitacion *sig;
};

struct Paciente {
    char *nombre;
    int edad;
    char *rut;
    int id_fecha;
    struct Paciente *ant, *sig;
};

struct Paciente *crearPaciente(char *nombre, int edad, char *rut, int id_fecha) {
    struct Paciente *nuevoPaciente =(struct Paciente *) malloc(sizeof(struct Paciente));

    nuevoPaciente->nombre = nombre;
    nuevoPaciente->edad = edad;
    nuevoPaciente->rut = rut;
    nuevoPaciente->id_fecha = id_fecha;

    nuevoPaciente->ant = NULL;
    nuevoPaciente->sig = NULL;

    return nuevoPaciente;
}

struct Habitacion *crearHabitacion(char letra, int id, char *tipoDeSala) {
    struct Habitacion *nuevaHabitacion = (struct Habitacion*) malloc(sizeof(struct Habitacion));

    nuevaHabitacion->letra = letra;
    nuevaHabitacion->id = id;
    nuevaHabitacion->tipoDeSala = tipoDeSala;

    nuevaHabitacion->pacientes = NULL; // Nodo Fantasma
    nuevaHabitacion->sig = NULL;

    return nuevaHabitacion;
}

struct Hospital *crearHospital(char *nombre, char *director) {
    struct Hospital *nuevoHospital = (struct Hospital*) malloc(sizeof(struct Hospital));

    nuevoHospital->nombre = nombre;
    nuevoHospital->director = director;

    nuevoHospital->habitaciones = NULL;

    return nuevoHospital;
}

int agregarPacienteAlFinal(struct Habitacion *habitacion, struct Paciente *nuevoPaciente) {
    if(habitacion == NULL || nuevoPaciente == NULL) return 0;

    
}
