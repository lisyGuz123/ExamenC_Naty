#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiantes {
    char carnet[20];
    char nombre[20];
    char grado[20];
    char departamento[20];
    int edad;
};

void registrar();
void mostrar();
void buscar();

int main() {
    int opcion;

    do {
        printf("Bienvenido a nuestro menu :3\n");
        printf("Elije una opcion\n");
        printf("1.Registrar un estudiante\n2.buscar estudiante por carnet\n3.lista de estudiante por grado\n4.Editar un estudiante\n5. salir\n>>");
        scanf("%d", &opcion);

        if (opcion == 1) {
            registrar();
        } else if (opcion == 2) {
            buscar();
        } else if (opcion == 4) {
            printf("Fin del proceso\n");
            break;
        } else {
            printf("Opcion no valida\n");
        }
    } while (opcion <= 4);

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
    printf("Ingrese el no. de carnet del estudiante\n>>");
    scanf("%s", &estudiante.carnet);
    printf("Ingrese el nombre del estudiante\n>>");
    scanf("%s", &estudiante.nombre);
    printf("Ingrese el grado del estudiante\n>>");
    scanf("%s", &estudiante.grado);
    printf("Ingrese el departamento del estudiante\n>>");
    scanf("%s", &estudiante.departamento);
    printf("Ingrese la edad del estudiante\n>>");
    scanf("%d",&estudiante.edad);


    fprintf(fp, "carnet del estudiante: %s\n", estudiante.carnet);
    fprintf(fp, "nombre del estudiante: %s\n", estudiante.nombre);
    fprintf(fp, "Grado del estudiante: %s\n", estudiante.grado);
    fprintf(fp, "departamento del estudiante: %s\n", estudiante.departamento);
    fprintf(fp, "Edad del estudiante: %d\n", estudiante.edad);
    fprintf(fp, "-------------------------\n");
    fclose(fp);
}

void mostrar() {
    FILE *fp;
    char leido[100];
    fp = fopen("estudiantes.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    while (fgets(leido, sizeof(leido), fp) != NULL) {
        printf("%s", leido);
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
    while (fscanf(fp, "nombre del estudiante: %s\n", &estudiante.nombre) != EOF) {
        fscanf(fp, "carnet del estudiante: %s\n", &estudiante.carnet);
        fscanf(fp, "grado del estudiante: %s\n", &estudiante.grado);
        fscanf(fp, "departamento del estudiante: %s\n", estudiante.departamento);
        fscanf(fp, "edad del estudiante: %d\n", &estudiante.departamento);
        fgetc(fp);

        if (strcmp(estudiante.carnet,carnet)==0) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", &estudiante.nombre);
            printf("carnet: %s\n", &estudiante.carnet);
            printf("grado: %s\n", &estudiante.grado);
            printf("departamento: %s\n", &estudiante.departamento);
            printf("Edad: %d\n",&estudiante.edad);
            encontrado = 1;
            break;
        }
        char separador[25];
        fgets(separador, sizeof(separador), fp);
    }

    if (!encontrado) {
        printf("Estudiante con el carnet %s no encontrado.\n", carnet);
    }

    fclose(fp);
}
