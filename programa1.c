/*Utilizando estructuras, memoria dinámica y funciones realizar un programa en el
que el usuario pueda guardar datos básicos de empleados:
1. Ingresar Trabajadores: El usuario podrá introducir los datos de n
trabajadores. Los datos a solicitar serán su nombre, código de empleado,
sueldo y horas trabajadas. (preguntar cuántos empleados desea ingresar,
usar memoria dinámica)
2. Consultas generales: En este apartado el usuario podrá ver los datos de
todos sus trabajadores desplegados en una misma pantalla. El orden en
que los mostrará será alfabéticamente por nombre.
3. Consultas por clave: El usuario deberá introducir el código del trabajador
que quiere buscar, y el programa deberá mostrar los datos de ese
trabajador o mostrar que no existe.
4. Consultas por nombre: El usuario tendrá que introducir el nombre del
trabajador que quiere buscar, y el programa deberá mostrar los datos de
ese trabajador o mostrar que no existe.
5. Salir*/


#include <stdio.h>
#include <stdlib.h>
int cantidad();
void mostrar(Trabajadores *puntero, int canti);
typedef struct
{
    char nombre[20];
    int código;
    float sueldo;
    int horas;
}Trabajadores;

int main()
{
    Trabajadores *puntero;
    int con;
    int canti;
    puntero=malloc(canti*sizeof(Trabajadores));
    do
    {
        printf("Ingrese una opcion\n>>");
        scanf("%d",&con);
        switch (con)
        {
        case 1:
            canti=cantidad();
            ingreso(puntero,canti);
            break;
        case 2:
            mostrar(puntero,canti);
        case 5:
            printf("Fin del programa\n");
            break;
            break;
        default:
            printf("opcion no existente\n");
            break;
        }
    } while (con!=5);
    return 0;
}

int cantidad()
{
    int can;
    printf("Ingrese la cantidad que desea ingresar\n>>");
    scanf("%d",&can);
    return can;
}

void ingreso(Trabajadores *puntero, int canti);

void ingreso(Trabajadores *puntero, int canti)
{
    int i;
    for (i=0;i<canti;i++)
    {
        printf("Ingrese el nombre del empleado %d\n>>",i+1);
        scanf("%s",&puntero[i].nombre);
        printf("Ingrese el codigo del empleado\n>>");
        scanf("%d",&puntero[i].código);
        printf("Ingrese el sueldo del empleado\n>>");
        scanf("%f",&puntero[i].sueldo);
        printf("Ingrese las horas trabajadas del empleado\n>>");
        scanf("%d",&puntero[i].horas);
    }
}


void mostrar(Trabajadores *puntero, int canti)
{
    int i;
    printf("lista de empleados\n");
    for (i=0;i<canti;i++)
    {
        printf("Nombre del empleado: %s\n",puntero[i].nombre);
        printf("Codigo del empleado: %d\n",puntero[i].código);
        printf("Sueldo del empleado: %.2f\n",puntero[i].sueldo);
        printf("Horas trabajadas del empleado: %d\n",puntero[i].horas);
    }
    free(puntero);
}