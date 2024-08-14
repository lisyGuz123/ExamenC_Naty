#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiantes {
    char carnet[20];
    char nombre[50];
    char grado[20];
    char departamento[20];
    int edad;
};

void registrar();
void listar();
void buscar();
void listarPorGrado();
void editar();

int main() {
    int opcion;

    do {
        printf("Bienvenido al menu del registro de estudiantes:\n");
        printf("1. Registrar un estudiante\n");
        printf("2. Buscar estudiante por carnet\n");
        printf("3. Lista de estudiantes por grado\n");
        printf("4. Editar un estudiante\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrar();
                break;
            case 2:
                buscar();
                break;
            case 3:
                listarPorGrado();
                break;
            case 4:
                editar();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while(opcion != 5);

    return 0;
}

void registrar() {
    FILE *fp;
    fp = fopen("estudiantes.txt", "a");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    struct Estudiantes estudiante;
    printf("Ingrese el carnet del estudiante: ");
    scanf("%s", estudiante.carnet);
    printf("Ingrese el nombre del estudiante: ");
    scanf(" %[^\n]s", estudiante.nombre);  // Lee la línea completa incluyendo espacios
    printf("Ingrese el grado del estudiante: ");
    scanf("%s", estudiante.grado);
    printf("Ingrese el departamento del estudiante: ");
    scanf("%s", estudiante.departamento);
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante.edad);

    fwrite(&estudiante, sizeof(struct Estudiantes), 1, fp);
    fclose(fp);
    printf("Estudiante registrado exitosamente.\n");
}

void listar() {
    FILE *fp;
    struct Estudiantes estudiante;
    fp = fopen("estudiantes.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fread(&estudiante, sizeof(struct Estudiantes), 1, fp)) {
        printf("Carnet: %s\n", estudiante.carnet);
        printf("Nombre: %s\n", estudiante.nombre);
        printf("Grado: %s\n", estudiante.grado);
        printf("Departamento: %s\n", estudiante.departamento);
        printf("Edad: %d\n", estudiante.edad);
        printf("-------------------------\n");
    }
    fclose(fp);
}

void buscar() {
    FILE *fp;
    char carnet[20];
    struct Estudiantes estudiante;
    int encontrado = 0;

    printf("Ingrese el carnet del estudiante a buscar: ");
    scanf("%s", carnet);

    fp = fopen("estudiantes.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fread(&estudiante, sizeof(struct Estudiantes), 1, fp)) {
        if (strcmp(estudiante.carnet, carnet) == 0) {
            printf("Estudiante encontrado:\n");
            printf("Carnet: %s\n", estudiante.carnet);
            printf("Nombre: %s\n", estudiante.nombre);
            printf("Grado: %s\n", estudiante.grado);
            printf("Departamento: %s\n", estudiante.departamento);
            printf("Edad: %d\n", estudiante.edad);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Estudiante con el carnet %s no encontrado.\n", carnet);
    }

    fclose(fp);
}

void listarPorGrado() {
    FILE *fp;
    struct Estudiantes estudiante;
    char grado[20];
    int encontrado = 0;

    printf("Ingrese el grado para listar los estudiantes: ");
    scanf("%s", grado);

    fp = fopen("estudiantes.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fread(&estudiante, sizeof(struct Estudiantes), 1, fp)) {
        if (strcmp(estudiante.grado, grado) == 0) {
            printf("Carnet: %s\n", estudiante.carnet);
            printf("Nombre: %s\n", estudiante.nombre);
            printf("Grado: %s\n", estudiante.grado);
            printf("Departamento: %s\n", estudiante.departamento);
            printf("Edad: %d\n", estudiante.edad);
            printf("-------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron estudiantes en el grado %s.\n", grado);
    }

    fclose(fp);
}

void editar() {
    FILE *fp, *temp;
    char carnet[20];
    struct Estudiantes estudiante;
    int encontrado = 0;

    printf("Ingrese el carnet del estudiante a editar: ");
    scanf("%s", carnet);

    fp = fopen("estudiantes.txt", "r");
    temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fread(&estudiante, sizeof(struct Estudiantes), 1, fp)) {
        if (strcmp(estudiante.carnet, carnet) == 0) {
            printf("Estudiante encontrado. Ingrese los nuevos datos:\n");
            printf("Ingrese el nombre del estudiante: ");
            scanf(" %[^\n]s", estudiante.nombre);
            printf("Ingrese el grado del estudiante: ");
            scanf("%s", estudiante.grado);
            printf("Ingrese el departamento del estudiante: ");
            scanf("%s", estudiante.departamento);
            printf("Ingrese la edad del estudiante: ");
            scanf("%d", &estudiante.edad);
            encontrado = 1;
        }
        fwrite(&estudiante, sizeof(struct Estudiantes), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("estudiantes.txt");
    rename("temp.txt", "estudiantes.txt");

    if (encontrado) {
        printf("Estudiante editado exitosamente.\n");
    } else {
        printf("Estudiante con el carnet %s no encontrado.\n", carnet);
    }
}
