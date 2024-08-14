#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int codigo;
    float sueldo;
    int horas;
} Trabajadores;

int cantidad();
void ingreso(Trabajadores *puntero, int canti);
void mostrar(Trabajadores *puntero, int canti);
void ordenarPorNombre(Trabajadores *puntero, int canti);
void buscarPorCodigo(Trabajadores *puntero, int canti, int codigo);
void buscarPorNombre(Trabajadores *puntero, int canti, char nombre[]);

int main()
{
    Trabajadores *puntero = NULL;
    int con, canti = 0;

    do
    {
        printf("\nMenu:\n");
        printf("1. Ingresar Trabajadores\n");
        printf("2. Consultas generales\n");
        printf("3. Consultar por clave\n");
        printf("4. Consultar por nombre\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion\n>> ");
        scanf("%d", &con);

        switch (con)
        {
            case 1:
                canti = cantidad();
                puntero = (Trabajadores *)malloc(canti * sizeof(Trabajadores));
                if (puntero == NULL)
                {
                    printf("Error al asignar memoria\n");
                    return 1;
                }
                ingreso(puntero, canti);
                break;
            case 2:
                ordenarPorNombre(puntero, canti);
                mostrar(puntero, canti);
                break;
            case 3:
                if (canti > 0)
                {
                    int codigo;
                    printf("Ingrese el codigo del trabajador\n>> ");
                    scanf("%d", &codigo);
                    buscarPorCodigo(puntero, canti, codigo);
                }
                else
                {
                    printf("No hay trabajadores ingresados\n");
                }
                break;
            case 4:
                if (canti > 0)
                {
                    char nombre[20];
                    printf("Ingrese el nombre del trabajador\n>> ");
                    scanf("%s", nombre);
                    buscarPorNombre(puntero, canti, nombre);
                }
                else
                {
                    printf("No hay trabajadores ingresados\n");
                }
                break;
            case 5:
                printf("Fin del programa\n");
                break;
            default:
                printf("Opcion no existente\n");
                break;
        }
    } while (con != 5);

    free(puntero);
    return 0;
}

int cantidad()
{
    int can;
    printf("Ingrese la cantidad de trabajadores que desea ingresar\n>> ");
    scanf("%d", &can);
    return can;
}

void ingreso(Trabajadores *puntero, int canti)
{
    for (int i = 0; i < canti; i++)
    {
        printf("Ingrese el nombre del empleado %d\n>> ", i + 1);
        scanf("%s", puntero[i].nombre);
        printf("Ingrese el codigo del empleado\n>> ");
        scanf("%d", &puntero[i].codigo);
        printf("Ingrese el sueldo del empleado\n>> ");
        scanf("%f", &puntero[i].sueldo);
        printf("Ingrese las horas trabajadas del empleado\n>> ");
        scanf("%d", &puntero[i].horas);
    }
}

void mostrar(Trabajadores *puntero, int canti)
{
    printf("Lista de empleados:\n");
    for (int i = 0; i < canti; i++)
    {
        printf("Nombre del empleado: %s\n", puntero[i].nombre);
        printf("Codigo del empleado: %d\n", puntero[i].codigo);
        printf("Sueldo del empleado: %.2f\n", puntero[i].sueldo);
        printf("Horas trabajadas del empleado: %d\n\n", puntero[i].horas);
    }
}

void ordenarPorNombre(Trabajadores *puntero, int canti)
{
    Trabajadores temp;
    for (int i = 0; i < canti - 1; i++)
    {
        for (int j = i + 1; j < canti; j++)
        {
            if (strcmp(puntero[i].nombre, puntero[j].nombre) > 0)
            {
                temp = puntero[i];
                puntero[i] = puntero[j];
                puntero[j] = temp;
            }
        }
    }
}

void buscarPorCodigo(Trabajadores *puntero, int canti, int codigo)
{
    for (int i = 0; i < canti; i++)
    {
        if (puntero[i].codigo == codigo)
        {
            printf("Nombre del empleado: %s\n", puntero[i].nombre);
            printf("Codigo del empleado: %d\n", puntero[i].codigo);
            printf("Sueldo del empleado: %.2f\n", puntero[i].sueldo);
            printf("Horas trabajadas del empleado: %d\n", puntero[i].horas);
            return;
        }
    }
    printf("No se encontro un empleado con el codigo %d\n", codigo);
}

void buscarPorNombre(Trabajadores *puntero, int canti, char nombre[])
{
    for (int i = 0; i < canti; i++)
    {
        if (strcmp(puntero[i].nombre, nombre) == 0)
        {
            printf("Nombre del empleado: %s\n", puntero[i].nombre);
            printf("Codigo del empleado: %d\n", puntero[i].codigo);
            printf("Sueldo del empleado: %.2f\n", puntero[i].sueldo);
            printf("Horas trabajadas del empleado: %d\n", puntero[i].horas);
            return;
        }
    }
    printf("No se encontro un empleado con el nombre %s\n", nombre);
}
