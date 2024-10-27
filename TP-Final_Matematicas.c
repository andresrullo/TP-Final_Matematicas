// librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){
    //VARIABLES
    int cantVariables = 0;
    int cantRow = 0, cantColumn = 0;
    char operation[4];
    char continuo[3];
    char name[100];

    printf("Por favor ingrese su nombre: ");
    scanf("%99s", &name);

    printf("\nHola %s! A continuacion te ayudaremos a generar una tabla de la verdad mediante una expresion booleana con una operacion \n", name);

    do
    { //COMIENZO DEL CÓDIGO E INGRESO DE DATOS
        printf("Ingrese la cantidad de variables para la expresion: "); //Cantidad de variables para el tamaño de la tabla
        scanf("%d", &cantVariables);

        while (cantVariables != 2 && cantVariables != 3)
        {
            printf("No me encuentro programado para generar una tabla de esas dimensiones... Ingrese un valor de 2 o 3: ");
            scanf("%d"), &cantVariables;
        }
        
        cantRow = pow(2, cantVariables); //Calcula la cantidad de filas 2^n
        cantColumn= cantVariables + 1; //Sumando 1 a la cantidad de columnas para crear la columna de resultado
        char letrasVariables[cantVariables];
        int tablaVerdad[cantRow][cantColumn]; 

        //INGRESO DE LAS LETRAS PARA LAS VARIABLES
        printf("A continuacion ingrese una letra para representar las variables en la operacion, las mismas pueden ser cualquiera del abecedario\n");
        for (int c = 0; c < cantColumn-1; c++) 
        {
            printf("Letra para la variable %d: ", c+1);
            scanf("%s", &letrasVariables[c]);
            letrasVariables[c] = toupper(letrasVariables[c]); //Pasa la letra a mayúsculas
        }
        
        //CÓDIGO PARA SELECCIONAR LA OPERACIÓN A REALIZAR
        printf("Ingresa la operacion a realizar (AND - OR): ");
        scanf("%3s", operation); //%3s leer hasta 3 caracteres
        //Convertir todos los caracteres ingresados a mayúscula
        for (int i = 0; i < 3; i++) {
            operation[i] = toupper(operation[i]);
        }
        while (strcmp(operation, "AND") != 0 && strcmp(operation, "OR") != 0) //Validación de la opción ingresada
        {
            printf("Lo siento, esa operacion no puedo realizarla. Ingrese nuevamente: "); 
            scanf("%3s", operation); //%3s Permite leer hasta 3 caracteres
            //Convierte todos los caracteres ingresados a mayúsculas
            for (int i = 0; i < 3; i++) {
                operation[i] = toupper(operation[i]);
            }
        }

        //CÓDOGO PARA CARGAR LOS VALORES DE LA TABLA
        printf("Completar la tabla con 1 para verdadero(V), 0 para falso(F) \n");
        for (int f = 0; f < cantRow; f++)
        {
            for (int c = 0; c < cantColumn-1; c++) 
            {
                printf("Valor para la posicion en columna %d, la fila %d: ", c+1, f+1);
                scanf("%d", &tablaVerdad[f][c]);
                while (tablaVerdad[f][c] != 0 && tablaVerdad[f][c] != 1) //Valida el ingreso de los valores correctos
                {
                    printf("Los valores a ingresar deben ser 0 o 1, ingresa nuevamente: ");
                    scanf("%d", &tablaVerdad[f][c]);
                }
            }
        }

        //CÓDIGO QUE REALIZA LA OPERACION
        if (cantVariables == 2) //Cuando es una operación de 2 variables
        {
            for (int f = 0; f < cantRow; f++)
            {
                int resultado = tablaVerdad[f][0]; //Compara la 1ra posición y guarda el resultado

                if (strcmp(operation, "AND") == 0)
                {
                    resultado = resultado && tablaVerdad[f][1]; //Compara la 2da posición con lo guardado en resultado
                } else if (strcmp(operation, "OR") == 0)
                {
                    resultado = resultado || tablaVerdad[f][1];
                } else{
                    resultado = 5;
                }
                tablaVerdad[f][cantColumn-1] = resultado;
            } 
        } else if (cantVariables == 3) //Cuando es una operación de 3 variables
        {
            for (int f = 0; f < cantRow; f++)
            {
                int resultado = tablaVerdad[f][0];

                if (strcmp(operation, "AND") == 0)
                {
                    resultado = resultado && tablaVerdad[f][1]; //Compara los primeros 2 valores
                    resultado = resultado && tablaVerdad[f][2]; //Luego compara el resultado de los primeros 2 con el 3er valor
                } else if (strcmp(operation, "OR") == 0)
                {
                    resultado = resultado || tablaVerdad[f][1];
                    resultado = resultado || tablaVerdad[f][2];
                } else{
                    resultado = 5;
                }
                tablaVerdad[f][cantColumn-1] = resultado;
            } 
        } else{
            printf("No deberia entrar aca\n");
        }

        //Si es OR le concatena un espacio al final para que cuando lo muestre quede con igual nro de caracteres que el AND y quede centrado
        if (strcmp(operation, "OR") == 0)
        {
            strcat(operation, " ");
        }
        
        //CÓDIGO PARA MOSTRAR LA TABLA COMPLETA
        printf("\nTABLA DE LA VERDAD: \n");   
        for (int c = 0; c < cantColumn-1; c++) { //Letra de cada variable
            printf(" %c  | ", letrasVariables[c]);        
        } 

        printf("%s | \n", operation); //Operacion elegida

        for (int f = 0; f < cantRow; f++)
        {
            printf("\n");
            for (int c = 0; c < cantColumn; c++) //Valores de la tabla
            {
                printf(" %d  | ", tablaVerdad[f][c]);
            }  
        }  

        //CÓDIGO DE CIERRE DEL PROGRAMA
        printf("\n\nQueres ingresar otra operacion? (SI - NO): ");
        scanf("%2s", continuo); //%3s Permite leer hasta 3 caracteres
        //Convierte todos los caracteres a mayúsculas
        for (int i = 0; i < 3; i++) {
            continuo[i] = toupper(continuo[i]);
        }
    } while (strcmp(continuo, "SI") == 0); //Con la palabra SI pertime repetir el programa
    
    //MENSAJE DE DESPEDIDA
    printf("\nGracias por utilizarme, %s!\n", name); 
    printf("\nAdios!!\n");

    system("pause"); //Para que no cierre la consola
    return 0;
}