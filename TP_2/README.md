## Primera Iteración: Comunicación Python y C

En la primera etapa del trabajo, se desarrolló una interfaz entre un script en Python y un programa en C. El objetivo fue consultar el índice GINI de Argentina utilizando la API REST del Banco Mundial. Python se encargó de hacer el request a la API, obtener el valor y luego invocar al programa en C pasándole el dato como argumento.

El programa en C simplemente recibió el número en formato float, lo imprimió por pantalla y aplicó una operación básica, como sumar uno. En esta iteración no se utilizó código en ensamblador; el foco estuvo en lograr la interacción entre los lenguajes de alto nivel y garantizar que el traspaso de información fuera exitoso.
## Segunda Iteración: Agregando Lógica en Ensamblador

En la segunda fase se incorporó Assembler al proyecto. Esta vez, el valor del índice GINI obtenido en Python fue pasado al programa en C, y desde allí se llamó a una rutina asm para convertir el valor float a entero y sumarle uno.

Como parte de esta etapa, también se utilizó GDB para inspeccionar el contenido del stack antes, durante y después de la ejecución del asm. Esto permitió validar el uso correcto del stack.


![image](https://github.com/user-attachments/assets/17c79700-147f-463c-afac-bf3161add725)
![image](https://github.com/user-attachments/assets/1be2c908-72b6-4047-8c21-ed96c6f8fd3e)
![image](https://github.com/user-attachments/assets/a6836250-b691-4318-9376-a6a61f0913e8)
![image](https://github.com/user-attachments/assets/b114a1e5-eea6-4c51-a0ec-622c251c1ad0)
![image](https://github.com/user-attachments/assets/89ab780c-1ac3-4526-bb36-798156cb4fc0)

Viendo asi el cambio de contenido en los registros, especialmente con eax 
