// librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
    char variable1;
    char variable2;
    char resultado;
    int option;

    printf("Ingrese la primer variable: \n");
    scanf("%c", &variable1);  /*CONVERTIR A MAYUSCULA LA LETRA INGRESADA*/
    /*while (variable1 != 'V')
    {
        printf("La variable es incorrecta. Ingresela nuevamente\n");
        scanf("%c", &variable1);
    };*/

    printf("Ingrese la segunda variable: \n");
    scanf("%c", &variable2);  /*CONVERTIR A MAYUSCULA LA LETRA INGRESADA*/
    /*while (variable2 != 'V')
    {
        printf("La variable es incorrecta. Ingresela nuevamente\n");
        scanf("%c", &variable2);
    };*/
    
    printf("Seleccione una opción según la operacion deseada \n");
    printf("1) Suma \n");
    printf("2) \n");
    printf("3) \n");
    printf("4) \n");
    printf("5) \n");
    printf("6) \n");
    

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            switch (variable1)  /*CHEQUEAR LA TABLA PARA VER SI ESTÁN BIEN LOS RESULTADOS*/
            {
            case 'V':
                if (variable2 == 'V')
                {
                    resultado = "V";
                }
                    else if (variable2 = "F")
                    {
                        resultado = "F";
                    }
                break;
            case 'F':
                if (variable2 == 'F')
                {
                    resultado = "F";
                }
                else if (variable2 = "V")
                {
                    resultado = "V";
                }
                break;
            }
            break;
        
        case 2:
            break;
            
        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        default:
            printf("La opción ingresada no existe \n");
            printf("Ingrese una opción correcta \n");
            break;
        }


    return 0;
}