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
