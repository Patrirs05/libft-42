*Este proyecto ha sido creado como parte del currículo de 42 por patrirod.*

# Libft — Tu primera librería

## Descripción

**Libft** es el primer proyecto de programación en C del currículo de 42. Consiste en crear una librería estática (`libft.a`) que reúne funciones de propósito general que se reutilizarán en los proyectos posteriores del cursus.

El objetivo es entender cómo funcionan por dentro las funciones estándar de C, reimplementarlas siguiendo fielmente su comportamiento (según el `man`) y aprender a usarlas de forma eficaz. Además, se añaden funciones de utilidad para manejo de cadenas, salida por descriptores de archivo y listas enlazadas.

Restricciones principales del proyecto:

- Escrito en C y conforme a la **Norma** de 42.
- Sin variables globales.
- Funciones auxiliares declaradas como `static`.
- Sin fugas de memoria ni terminaciones inesperadas (segfault, double free, etc.).
- Compilación con `cc -Wall -Wextra -Werror`.
- Librería generada con `ar` (prohibido `libtool`).

### Descripción detallada de la librería

La librería se divide en tres partes.

#### Parte 1 — Funciones de libc (prefijo `ft_`)

Reimplementaciones con el mismo prototipo y comportamiento que las originales, sin depender de funciones externas (salvo `malloc` o `write` donde se indica).

| Categoría | Funciones |
|---|---|
| Clasificación de caracteres | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` (devuelven `1` si cumple la condición, `0` si no) |
| Conversión de caracteres | `ft_toupper`, `ft_tolower` |
| Cadenas | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Memoria | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Con reserva de memoria (`malloc`) | `ft_calloc`, `ft_strdup` |

Nota: si `nmemb` o `size` es 0, `ft_calloc` devuelve un puntero único que puede pasarse con éxito a `free()`.

#### Parte 2 — Funciones adicionales

| Función | Descripción |
|---|---|
| `ft_substr` | Devuelve una subcadena de `s` que empieza en `start` y tiene como máximo `len` caracteres. |
| `ft_strjoin` | Devuelve una nueva cadena resultado de concatenar `s1` y `s2`. |
| `ft_strtrim` | Devuelve una copia de `s1` sin los caracteres de `set` al principio y al final. |
| `ft_split` | Divide `s` usando `c` como delimitador. Devuelve un array de cadenas terminado en `NULL`. |
| `ft_itoa` | Convierte un entero (incluidos negativos) en cadena. |
| `ft_strmapi` | Aplica `f(índice, carácter)` a cada carácter de `s` y devuelve la nueva cadena resultante. |
| `ft_striteri` | Aplica `f(índice, &carácter)` a cada carácter de `s`, permitiendo modificarlo. |
| `ft_putchar_fd` | Escribe un carácter en el descriptor `fd`. |
| `ft_putstr_fd` | Escribe una cadena en el descriptor `fd`. |
| `ft_putendl_fd` | Escribe una cadena seguida de un salto de línea en el descriptor `fd`. |
| `ft_putnbr_fd` | Escribe un entero en el descriptor `fd`. |

#### Parte 3 — Listas enlazadas

Se utiliza la siguiente estructura, declarada en `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Función | Descripción |
|---|---|
| `ft_lstnew` | Crea un nodo nuevo con `content` y `next = NULL`. |
| `ft_lstadd_front` | Añade un nodo al principio de la lista. |
| `ft_lstsize` | Cuenta el número de nodos de la lista. |
| `ft_lstlast` | Devuelve el último nodo de la lista. |
| `ft_lstadd_back` | Añade un nodo al final de la lista. |
| `ft_lstdelone` | Libera el contenido de un nodo con `del` y el propio nodo (no el siguiente). |
| `ft_lstclear` | Elimina y libera un nodo y todos los siguientes; deja el puntero de la lista a `NULL`. |
| `ft_lstiter` | Aplica `f` al contenido de cada nodo. |
| `ft_lstmap` | Crea una nueva lista aplicando `f` al contenido de cada nodo; usa `del` si falla una reserva. |

## Instrucciones

### Estructura del repositorio

Todos los archivos se encuentran en la raíz del repositorio:

```
.
├── Makefile
├── README.md
├── libft.h
└── ft_*.c
```

### Compilación

El `Makefile` compila los archivos fuente con `cc -Wall -Wextra -Werror` y genera `libft.a` en la raíz mediante `ar`. No hace relink.

```bash
make          # Compila la librería y genera libft.a
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los .o y libft.a
make re       # fclean + all
```

Reglas disponibles: `$(NAME)`, `all`, `clean`, `fclean`, `re`.

### Uso en otro proyecto

1. Incluye el header en tu código:

```c
#include "libft.h"
```

2. Compila enlazando la librería:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o programa
```

### Ejemplo de uso

```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hola mundo desde libft", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

## Recursos

### Documentación y referencias

- Páginas del manual (`man <función>`) de cada función reimplementada.
- [The GNU C Library Reference Manual](https://www.gnu.org/software/libc/manual/)
- Kernighan, B. & Ritchie, D. — *The C Programming Language* (2.ª ed.).
- [The Norm — 42 Network](https://github.com/42School/norminette) (norminette).
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [`ar(1)` — Linux manual page](https://man7.org/linux/man-pages/man1/ar.1.html)
- [Valgrind Documentation](https://valgrind.org/docs/manual/) para la detección de fugas de memoria.

### Uso de IA

Durante el proyecto se ha utilizado IA como herramienta de apoyo al aprendizaje, no para obtener soluciones directas, en estos casos concretos:

Resolución de errores: cuando aparecían errores de compilación o de ejecución y no se conseguía encontrar la causa ni cómo solucionarlos, se consultó a la IA para entender qué los provocaba.
Comprensión del comportamiento de las funciones: cuando no quedaba del todo claro el comportamiento exacto de alguna función (por ejemplo, casos límite o valores de retorno), se pidió una explicación detallada de cómo debería comportarse y de los pasos a seguir para implementarla
.
Comprensión del Makefile: se pidió ayuda a la IA para entender cómo funciona el Makefile (variables, reglas, reglas patrón, .PHONY, cómo evitar el relink, etc.).

README.md: la estructura base de este documento se generó con ayuda de IA y después se revisó y adaptó.
