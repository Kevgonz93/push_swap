# Push_swap - 42 Project

## 📜 Descripción

**Push_swap** es un proyecto del programa 42 que consiste en desarrollar un programa para ordenar una pila de números enteros utilizando un conjunto de instrucciones específicas y optimizando el número de movimientos.

---

## 📋 Requisitos

Antes de compilar y ejecutar el proyecto, asegúrate de tener:

- 🛠️ **`gcc`**: Compilador de C.
- 🛠️ **`make`**: Herramienta de construcción.
- 🖥️ **Sistema operativo**: Unix o Mac.

---

## 🛠️ Cómo Compilar y Ejecutar

1. Clona este repositorio:

   ```bash
   git clone https://github.com/Kevgonz93/push_swap.git
   ```

2. Navega al directorio del proyecto:

   ```bash
   cd push_swap
   ```

3. Compila el programa utilizando `make`:

   ```bash
   make
   ```

4. Ejecuta el programa con una lista de números:
   ```bash
   ./push_swap "4 67 3 87 23"
   ```

---

## 🚀 Características

✔️ Ordena números en una pila utilizando operaciones específicas: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` y `rrr`.<br>
✔️ Optimización para manejar listas de 100 y 500 números.<br>
✔️ Cumple con las restricciones de tiempo y espacio del proyecto.

---

## 🧠 Estrategia de Solución

🔍 **División en bloques**: Los números se dividen en bloques más pequeños para facilitar el manejo.<br>
🔍 **Selección de operaciones óptimas**: Cada movimiento se elige con base en el menor costo para ordenar.<br>
🔍 **Algoritmo personalizado**: Desarrollado específicamente para cumplir con las restricciones de movimientos del proyecto.

---

## 🧪 Pruebas

### Tipos de entradas posibles

1. Con variable:

```bash
    ARG="4 67 3 87 23"; ./push_swap $ARG
```

2. Con varios argumentos:

```bash
    ./push_swap 4 67 3 87 23
```

3. Con un sólo argumento (como una cadena):

```bash
    ./push_swap "4 67 3 87 23"
```

### Ejemplo de ejecución:

```bash
$ ./push_swap "4 3 2 1"
ra
pb
ra
pb
sa
pa
pa
```

### Ejemplo de uso de checker

```bash
$ ./push_swap "4 3 2 1" | ./checker_Mac "4 3 2 1"
OK
```

## Bonus

Para probar "mychecker":

1. Compila el programa utilizando `make bonus`:

   ```bash
   make bonus
   ```

2. Ejecuta el programa con una lista de números:
   ```bash
   ./push_swap "4 67 3 87 23" | ./mychecker "4 67 3 87 23"
   ```

### Estadísticas del Proyecto:

| Números | Operaciones Máximas |
| ------- | ------------------- |
| 100     | Menos de 700        |
| 500     | Menos de 5500       |

### Casos de Prueba:

- ✅ Listas ya ordenadas.
- ✅ Listas inversamente ordenadas.
- ✅ Listas con valores repetidos (cuando permitido).

---

## 📂 Estructura del Proyecto

```
📦 push_swap
├── 📂 aux             # Funciones auxiliares (libft adaptado)
├── 📂 bonus           # Programa parte del bonus de push_swap
   ├── 📂 aux          # Funciones auxiliares (libft adaptado)
   ├── 📂 gnl          # Get Next Lina empleado para la realización del bonus
   ├── 📂 moves        # Funciones con los movimientos del push_swap
   ├── 📂 src          # Funciones basicas para el bonus
   ├── checker.h       # Archivo de cabecera con las funciones principales
   └── main.c          # Función main
├── 📂 moves           # Implementación de las operaciones "push", "swap", "rotate" y "reverse"
├── 📂 sorts           # Lógica de ordenamiento
├── 📂 src             # Funciones básicas para el proyecto
├── checker_linux      # Herramienta para verificar la validez de las operaciones en Linux
├── checker_Mac        # Herramienta para verificar la validez de las operaciones en Mac
├── main.c             # Función main
├── Makefile           # Archivo para la compilación
├── notas.md           # Registro de tests realizados durante la optimización del algoritmo
├── printers.c         # Funciones para tener una visión de los stacks.
├── push_swap.h        # Archivo de cabecera con las funciones principales
├── README.md          # Este documento
├── subject.md         # Enunciado en markdown
└── subject.pdf        # Enunciado en pdf

```

---

## 🧑‍💻 Autor

[Kevin Gonzales](https://github.com/Kevgonz93)
