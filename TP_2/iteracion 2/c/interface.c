#include <stdio.h>
#include <stdlib.h>

//Leo el gini en el lugar 0 de argv[], convierto a float y llamo la funcion de Assembler

extern int sumo_uno(float);  // de Assembler

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Valor usado: %s <valor_float>\n", argv[0]);
        return 1;
    }

    float value = atof(argv[1]);

    printf("GINI recibido: %.2f\n", value);

    int result = sumo_uno(value);

    printf("Resultado adicionando 1: %d\n", result);

    return 0;
}
