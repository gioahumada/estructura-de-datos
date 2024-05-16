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

    if(habitacion->pacientes == NULL) {
        habitacion->pacientes = nuevoPaciente;
        return 1;
    }

    struct Paciente *ult = habitacion->pacientes;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoPaciente;
    nuevoPaciente->ant = ult;
    return 1;
}

int main() {
    struct Hospital *hospital = crearHospital("Sotero del Rio", "Dr. Doofenzmir");

    struct Habitacion *habitacionA = crearHabitacion('A', 1, "General");
    agregarPacienteAlFinal(habitacionA, crearPaciente("Giovanni", 20, "123425-4", 1));
    agregarPacienteAlFinal(habitacionA, crearPaciente("Pedro", 19, "6454425-1", 2));
    agregarPacienteAlFinal(habitacionA, crearPaciente("Juan", 9, "958334-3", 3));

    struct Habitacion *habitacionB = crearHabitacion('B', 2, "Cuidado Intensivos");
    agregarPacienteAlFinal(habitacionB, crearPaciente("Tanya", 25, "19248224-5", 4));
    agregarPacienteAlFinal(habitacionB, crearPaciente("Maria", 65, "49397234-2", 5));

    hospital->habitaciones = habitacionA;
    habitacionA->sig = habitacionB;

    struct Habitacion *hab = hospital->habitaciones;
    while(hab != NULL) {
        printf("Habitacion %c:\n", hab->letra);
        struct Paciente *pac = hab->pacientes;
        while(pac != NULL) {
            printf("Paciente: %s, Edad: %d, RUT: %s, ID Ficha Medica: %d\n", pac->nombre, pac->edad, pac->rut, pac->id_fecha);
            pac = pac->sig;
        }
        hab = hab->sig;
    }
    
}
