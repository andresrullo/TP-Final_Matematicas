// librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char variable1;
    char variable2;

    printf("Ingrese la primer variable: \n");
    scanf("%c", &variable1);

    while (variable1 != 'v' && variable1 != 'V')
    {
        printf("La variable es incorrecta. Ingresela nuevamente\n");
        scanf("%c", &variable1);
    };
    
    /*do
    {
        
        if (variable1 != 'v' && variable1 != 'V')
        {
            printf("La variable ingresada no es correcta");
        }
    } while (variable1 != 'v' && variable1 != 'V');*/
    

    return 0;
}