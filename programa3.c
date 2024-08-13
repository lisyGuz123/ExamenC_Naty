#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_departas(char departa[][20], int cantidad){
    char temp[100];
    for (int i = 0; i<cantidad;i++) {
        for (int j = 0;j<cantidad;j++) {
            if (strcmp(departa[j], departa[i])>0) {
                strcpy(temp, departa[i]);
                strcpy(departa[i], departa[j]);
                strcpy(departa[j], temp);
            }
        }
    }
}

int main() {
    FILE *fp;
    char departa[100][20];
    int cantidad = 0;

    fp = fopen("Departamentos.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while (fscanf(fp, "%s", departa[cantidad]) != EOF) {
        cantidad++;
    }
    fclose(fp);

    ordenar_departas(departa, cantidad);

    printf("\ndepartamentos ordenadas alfabéticamente:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", departa[i]);
    }

    return 0;
}