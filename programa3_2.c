/*Programa 3:
Utilizando archivos de texto realizar un programa que pida el ingreso de cuantos
departamentos desea ingresar, posteriormente ingresar los datos a un archivo y al
consultar los datos mostrar los departamentos de forma ordenada de Z a A.*/

#include <stdio.h>
int main() {
    FILE *fp;
    char depa[30];
    int cantidad;
    fp = fopen("Departamentos.txt", "w");
    printf("Ingrese la cantidad de departamentos que desea ingresar\n>>");
    scanf("%d",&cantidad);
    for (int i = 1; i <= cantidad; i++) {
        printf("Ingrese el nombre del departamento: \n>>");
        scanf("%s", &depa);
        fprintf(fp, "%s\n", depa);
    }
    fclose(fp);
    return 0;
}