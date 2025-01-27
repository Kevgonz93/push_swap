# Push_swap

Push_swap es un proyecto del programa 42 que consiste en desarrollar un programa para ordenar una pila de números enteros utilizando un conjunto de instrucciones específicas y optimizando el número de movimientos.

---

## 🚀 Características

✔️ Ordena números en una pila utilizando operaciones específicas: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` y `rrr`.<br>
✔️ Optimización para manejar listas de 100 y 500 números.<br>
✔️ Cumple con las restricciones de tiempo y espacio del proyecto.

---

## 📋 Requisitos Previos

Antes de compilar y ejecutar el proyecto, asegúrate de tener:

- 🛠️ **`gcc`**: Compilador de C.
- 🛠️ **`make`**: Herramienta de construcción.
- 🖥️ **Sistema operativo**: Unix o similar.

---

## 🛠️ Cómo Compilar y Ejecutar

1. Clona este repositorio:

   git clone https://github.com/Kevgonz93/push_swap.git
   cd push_swap

2. Compila el programa utilizando `make`:
   ```bash
   make
   ```
3. Ejecuta el programa con una lista de números:
   ```bash
   ./push_swap "4 67 3 87 23"
   ```

---

## 🧠 Estrategia de Solución

🔍 **División en bloques**: Los números se dividen en bloques más pequeños para facilitar el manejo.<br>
🔍 **Selección de operaciones óptimas**: Cada movimiento se elige con base en el menor costo para ordenar.<br>
🔍 **Algoritmo personalizado**: Desarrollado específicamente para cumplir con las restricciones de movimientos del proyecto.

---

## 📊 Pruebas y Resultados
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

### Estadísticas del Proyecto:
| Números | Operaciones Máximas |
|---------|---------------------|
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
├── 📂 src         # Código fuente del programa
├── 📂 include     # Archivos de cabecera
├── 📄 Makefile    # Archivo para la compilación
└── 📄 README.md   # Este documento
```

---

## 🤝 Contribución
Este proyecto fue desarrollado como parte del programa 42. Si deseas aportar ideas o mejoras, siéntete libre de abrir un issue o un pull request.

---

## 📜 Licencia
Este proyecto se distribuye bajo la licencia MIT. Consulta el archivo [LICENSE](./LICENSE) para más detalles.
