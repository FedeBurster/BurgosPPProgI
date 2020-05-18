#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}typedef eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char* cadenaCaracteres,char caracter);
int ordenarArray(eNotebook* notebooks,int arrayLength);
void hardcodeoEjemplos(eNotebook* notebooks);

int main()
{
    int i;
    eNotebook notebooks[5];

    hardcodeoEjemplos(notebooks);
    ordenarArray(notebooks,5);

    printf("ID\t|Marca\t\t|Precio\t\t|Procesador\n\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t|%s\t|%.2f\t|%s\n",notebooks[i].id,notebooks[i].marca,notebooks[i].precio,notebooks[i].procesador);
    }
    return 0;
}


int ordenarArray(eNotebook* notebooks,int arrayLength)
{
    int c,d;
    eNotebook auxNotebook;

    for (c = 0 ; c < arrayLength - 1; c++)
    {
        for (d = 0 ; d < arrayLength - c - 1; d++)
        {
            if(notebooks[d].marca[0] > notebooks[d+1].marca[0])
            {
                auxNotebook = notebooks[d];
                notebooks[d]  = notebooks[d+1];
                notebooks[d+1] = auxNotebook;
            }
            else if(strcmp(notebooks[d].marca, notebooks[d+1].marca) == 0 && notebooks[d].precio > notebooks[d+1].precio)
            {
                auxNotebook=notebooks[d];
                notebooks[d]=notebooks[d+1];
                notebooks[d+1]=auxNotebook;
            }
        }
    }
    return 0;
}

float aplicarDescuento(float precio)
{
    float precioDescuento=0;

    precioDescuento=precio-((5*precio)/100);

    return precioDescuento;
}

int contarCaracteres(char* cadenaCaracteres,char caracter)
{
    int i=0,contadorCaracter=0;
    char auxCaracterMayus,auxCaracterMinus;

    auxCaracterMayus=toupper(caracter);
    auxCaracterMinus=tolower(caracter);
    while(cadenaCaracteres[i] != '\0')
    {
        if(cadenaCaracteres[i]==auxCaracterMayus || cadenaCaracteres[i]==auxCaracterMinus)
        {
            contadorCaracter++;
        }
        i++;
    }

    return contadorCaracter;
}

void hardcodeoEjemplos(eNotebook* notebooks)
{
    notebooks[0].id=1;
    notebooks[1].id=2;
    notebooks[2].id=3;
    notebooks[3].id=4;
    notebooks[4].id=5;

    strcpy(notebooks[0].procesador,"AMD A6");
    strcpy(notebooks[1].procesador,"AMD A8");
    strcpy(notebooks[2].procesador,"AMD Ryzen");
    strcpy(notebooks[3].procesador,"Intel i7");
    strcpy(notebooks[4].procesador,"Intel i5");

    strcpy(notebooks[0].marca,"Samsung");
    strcpy(notebooks[1].marca,"Samsung");
    strcpy(notebooks[2].marca,"Asus   ");
    strcpy(notebooks[3].marca,"HP     ");
    strcpy(notebooks[4].marca,"Samsung");

    notebooks[0].precio=50000;
    notebooks[1].precio=70000;
    notebooks[2].precio=40000;
    notebooks[3].precio=50000;
    notebooks[4].precio=60000;

    return;
}
