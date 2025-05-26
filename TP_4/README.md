# TP4 - Sistemas de Computación  
## Módulo de Kernel que saluda al usuario

Este trabajo práctico explora la arquitectura modular del kernel de Linux mediante el desarrollo e inserción de un módulo propio. El objetivo es comprender cómo se cargan módulos en el kernel y cómo interactúan con el sistema.

El módulo creado recibe como parámetro un nombre de usuario y lo saluda desde el espacio del kernel al cargarse. También emite un mensaje de despedida al descargarse.

---

## Instalación del entorno de desarrollo

Para compilar módulos del kernel es necesario tener instaladas las siguientes herramientas:

```bash
sudo apt-get update
sudo apt-get install build-essential linux-headers-$(uname -r)
```
Luego se genero el codigo para crear un modulo de kernell que reciba como parametro el nombre del usuario y devuelva una bienveida:
```bash
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static char* nombre = "usuario"; // valor por defecto
module_param(nombre, charp, 0000);
MODULE_PARM_DESC(nombre, "Nombre del usuario");

static int __init iniciar(void)
{
    printk(KERN_INFO "Hola %s, ¡bienvenido/a al kernel de Linux!\n", nombre);
    return 0;
}

static void __exit salir(void)
{
    printk(KERN_INFO "Adiós %s, módulo descargado.\n", nombre);
}

module_init(iniciar);
module_exit(salir);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Magdalena");
MODULE_DESCRIPTION("Módulo que saluda al usuario desde el kernel");
MODULE_VERSION("0.1");
```
utilizando un archivo Makefile para compilarlo
```bash
obj-m += nuevo_modulo.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

![image](https://github.com/user-attachments/assets/0872523f-3882-4220-aae3-eb89b465bf9c)
 Ahora ingresando el parámetro "Magdalena" con sudo insmod nuevo_modulo.ko nombre="Magdalena"  va a devolver el siguiente 
mensaje  
![image](https://github.com/user-attachments/assets/d01da0f3-5a84-4c59-981e-494ac3b30e21)


Viendo asi en el directorio proc nuestro nuevo modulo 
![image](https://github.com/user-attachments/assets/63c8adaf-438c-47b8-a008-dde07184c9de)

## ¿Qué funciones tiene disponible un programa y un módulo?

En un sistema Linux, los programas y los módulos del kernel operan en contextos distintos y por lo tanto tienen diferentes capacidades:

### Programas (Espacio de Usuario)

Los programas se ejecutan en el espacio de usuario, una zona de memoria protegida que impide el acceso directo al hardware o a los recursos críticos del sistema. Para interactuar con el sistema operativo (por ejemplo, abrir archivos, usar la red o leer el tiempo), los programas hacen uso de llamadas al sistema (syscalls), como `open()`, `read()`, `write()`, entre otras.

Estas llamadas son gestionadas por el kernel, que actúa como intermediario entre el programa y el hardware. Herramientas como `strace` permiten ver en tiempo real qué llamadas hace un programa al sistema operativo, lo que ayuda a entender qué funciones realmente utiliza.

### Módulos del Kernel (Espacio del Kernel)

Los módulos del kernel se ejecutan en el espacio del kernel, donde el código tiene acceso directo a los recursos del sistema y al hardware. Esto les permite, por ejemplo:

- Reservar memoria usando funciones como `kmalloc`.
- Manejar interrupciones de hardware.
- Definir estructuras y registros del sistema.
- Crear y registrar controladores de dispositivos.

A diferencia de los programas tradicionales, los módulos no tienen una función `main()`, sino que definen funciones especiales como `module_init()` (para inicialización) y `module_exit()` (para limpieza). Esto significa que no se ejecutan de forma lineal, sino que son cargados y utilizados por el kernel cuando se los necesita.

### Espacios de memoria: Usuario vs Kernel

Esta separación entre espacio de usuario y espacio de kernel es fundamental por razones de seguridad y estabilidad. Un error en un programa de usuario puede causar que se cierre dicho programa; en cambio, un error en un módulo del kernel puede provocar un fallo total del sistema.

## Acceso a datos y memoria

- Los programas acceden a datos que están en regiones de memoria asignadas por el sistema operativo. Solo pueden comunicarse con dispositivos o servicios del sistema mediante interfaces proporcionadas por el kernel.

- Los módulos, por su parte, pueden asignar y gestionar directamente memoria del sistema, así como interactuar con estructuras internas del kernel o configurar regiones de memoria asociadas al hardware.

## Drivers y el contenido de /dev

El directorio `/dev` contiene los llamados archivos de dispositivo, que actúan como una interfaz entre los programas y el hardware. Por ejemplo:

- `/dev/sda` representa un disco.
- `/dev/tty` representa terminales.

Cuando un programa accede a uno de estos archivos, en realidad está interactuando con un driver, que usualmente es un módulo del kernel. Este módulo es quien traduce las operaciones (`read`, `write`, etc.) en acciones concretas sobre el hardware.

Este diseño permite al sistema operativo abstraer el acceso al hardware y mantener la coherencia del modelo "todo es un archivo" típico de los sistemas Unix y Linux.
