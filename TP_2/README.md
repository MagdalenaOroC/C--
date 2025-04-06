## Primera Iteración: Comunicación Python y C

En la primera etapa del trabajo, se desarrolló una interfaz entre un script en Python y un programa en C. El objetivo fue consultar el índice GINI de Argentina utilizando la API REST del Banco Mundial. Python se encargó de hacer el request a la API, obtener el valor y luego invocar al programa en C pasándole el dato como argumento.

El programa en C simplemente recibió el número en formato float, lo imprimió por pantalla y aplicó una operación básica, como sumar uno. En esta iteración no se utilizó código en ensamblador; el foco estuvo en lograr la interacción entre los lenguajes de alto nivel y garantizar que el traspaso de información fuera exitoso.
## Segunda Iteración: Agregando Lógica en Ensamblador

En la segunda fase se incorporó Assembler al proyecto. Esta vez, el valor del índice GINI obtenido en Python fue pasado al programa en C, y desde allí se llamó a una rutina asm para convertir el valor float a entero y sumarle uno.

Como parte de esta etapa, también se utilizó GDB para inspeccionar el contenido del stack antes, durante y después de la ejecución del asm. Esto permitió validar el uso correcto del stack, asegurando que los valores fueran empujados y recuperados en forma coherente.
