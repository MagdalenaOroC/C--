#include <stdio.h>

extern int sumo_uno(float);

int main() {
    float gini = 42.7;

    printf("Antes de llamar a sumo_uno\n");

    int resultado = sumo_uno(gini);

    printf("Después de llamar a sumo_uno\n");

    printf("Resultado retornado: %d\n", resultado);

    return 0;
}

