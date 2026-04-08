# 🔬 Máximo Subarreglo Contiguo - Proyecto PC1

#### 👥 Integrantes (Pareja 07)
- Rydell Jonel Mosquera Huayhua
- Joel Gustavo Carhuarica Aguilar

#### 🎯 Competencia del curso y Problema asignado
Diseñar, implementar, analizar y sustentar el *Maximum Subarray* de arreglos, justificando formalmente su correctitud, complejidad y pertinencia práctica. 

*Nota de la industria: Este problema es un clásico en entrevistas técnicas de empresas como Amazon. Demuestra la capacidad de optimizar soluciones que ingenuamente tendrían una complejidad polinómica (donde el número de bucles anidados define una complejidad O(N^k)), llevándolas a una complejidad lineal óptima.*

#### 🔗 Enlace al enunciado de LeetCode
[LeetCode - Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

---

## 1. Especificación del Problema

* **Especificación breve:** Desarrollar un algoritmo que calcule la máxima suma de un subarreglo contiguo. La solución implementa el enfoque de "Divide y Vencerás" y el "Algoritmo de Kadane". El programa utiliza las librerías estándar `<vector>`, `<limits>` y `<algorithm>`.
* **Entrada:** Un conjunto de `N` números enteros almacenados en un vector.
* **Salida:** Un valor entero que representa la máxima suma posible de cualquier subarreglo contiguo dentro del vector de entrada.
* **Tamaño de entrada relevante:** El algoritmo procesa un vector de tamaño `N`, donde `1 ≤ N ≤ 10^5`. Para este rango, el enfoque de Kadane es el más óptimo, ya que mantiene una complejidad lineal O(N) y un uso de memoria constante O(1).
* **Descripción de la solución:** Aunque ambos métodos llegan al mismo resultado, el Algoritmo de Kadane es el preferido para este problema por su eficiencia superior en tiempo y su uso mínimo de memoria, ya que no requiere llamadas recursivas ni estructuras de datos adicionales.

---

## 2. Argumentos Teóricos y Correctitud

#### Justificación de determinismo y factibilidad
* **Determinismo:** El resultado es idéntico en cada ejecución para una misma entrada, ya que las comparaciones y sumas siguen un flujo lógico fijo sin componentes aleatorios.
* **Factibilidad:** La solución es viable para sistemas reales debido a su baja complejidad computacional. El uso de memoria es mínimo y los recursos de hardware actuales superan con creces los requisitos del algoritmo.

#### Argumento de finitud
El algoritmo es finito porque todas sus estructuras de control tienen un punto de terminación definido. El método iterativo (Kadane) recorre el arreglo un número exacto de veces igual al tamaño de la entrada (`N`), mientras que el método recursivo reduce el espacio de búsqueda a la mitad en cada paso hasta alcanzar el caso base, evitando ciclos infinitos.

#### Argumento de correctitud
El algoritmo es correcto porque agota todas las posibilidades de formación de subarreglos:
* En la **versión iterativa**, se aplica programación dinámica que asegura el cálculo del máximo local en cada índice.
* En la **versión recursiva**, se aplica un esquema de exhaustividad dividiendo el problema (izquierda, derecha y cruce), asegurando que el subarreglo óptimo sea capturado en alguno de los tres escenarios.

#### Invariante y Monotonicidad (Kadane)
* **Propiedad Invariante:** *"Al inicio de cada iteración i, la variable `max_global` contiene la suma del subarreglo máximo encontrado en el intervalo `nums[0...i-1]`, mientras que `max_local` contiene la suma del subarreglo máximo que termina estrictamente en la posición `i-1`."*
  1. **Inicialización:** Antes de la primera iteración (`i=1`), ambas variables se inicializan con `nums[0]`. Es correcto ya que, en un arreglo de un solo elemento, el subarreglo máximo y el que termina en esa posición son el mismo.
  2. **Mantenimiento:** Durante la iteración `i`, se calcula el nuevo `max_local` comparando el elemento actual `nums[i]` con la suma acumulada `max_local + nums[i]`. Luego, `max_global` se actualiza solo si este nuevo valor supera al récord anterior.
  3. **Terminación:** El bucle finaliza cuando `i = nums.size()`. Según el invariante, `max_global` ha comparado todos los "máximos locales", garantizando que el valor retornado sea la suma máxima absoluta.
* **Monotonicidad:** El progreso del algoritmo avanza de forma estrictamente incremental a través de los índices del arreglo, evaluando decisiones de retención o descarte de sumas de manera unidireccional.

---

## 3. Análisis Experimental: Compilación y Optimización

El código fue sometido a distintas banderas de compilación en GCC utilizando un arreglo masivo (`N = 1,000,000`). Se incluyeron las banderas `-Wall -Wextra -Wpedantic` para garantizar la calidad en C++17.

#### Tabla Comparativa de Builds

| Build | Comando / Banderas principales | Tamaño Relativo (Exe) | Tiempo Kadane | Tiempo D&C |
| :--- | :--- | :--- | :--- | :--- |
| **Depuración** | `-O0 -g -Wall -Wextra...` | El más grande (~150 KB) | ~1.2 ms | ~25.0 ms |
| **Depurable Opt.** | `-Og -g -Wall -Wextra...` | Intermedio (~120 KB) | ~0.5 ms | ~12.0 ms |
| **Release** | `-O2 -DNDEBUG` | Intermedio (~130 KB) | ~0.1 ms | ~2.1 ms |
| **Compacto** | `-Os` | El más pequeño (~40 KB) | ~0.1 ms | ~2.3 ms |

**Observaciones de los criterios evaluados:**
1. **Correctitud:** El Invariante se mantuvo sólido en todos los niveles; el compilador no alteró la lógica.
2. **Tiempo total:** El salto de `-O0` a `-O2` representó una aceleración superior a 10x gracias a la vectorización y el *loop unrolling*.
3. **Tamaño del ejecutable:** `-O0` generó el binario más pesado (con símbolos de depuración). `-Os` logró el más liviano al sacrificar el desenrollado de bucles.
4. **Estabilidad:** La variación de tiempo entre ejecuciones fue inferior al 5%.
5. **Depuración:** Perfecta en `-O0` y `-Og` (lectura línea a línea). Casi imposible en `-O2` y `-Os` debido al *function inlining*.
6. **Warnings:** Cero warnings. El código demostró inicialización segura y compatibilidad total con C++17.

---

## 4. Resumen de Cobertura (`gcov`)

Utilizamos `gcov` con la bandera `-b` para medir la cobertura de líneas y ramas (condiciones lógicas).

* 🔍 **Diagnóstico Inicial (32%):** Inicialmente, `gcov` arrojó 32.26% de cobertura de líneas y 28% de ramas. Nuestra prueba solo llamaba a la función envoltorio, ejecutando por defecto Kadane e ignorando el enfoque de Divide y Vencerás.
* 🛠️ **Solución Implementada:** Modificamos `tests.cpp` para que los *asserts* hicieran llamadas explícitas a ambos métodos bajo arreglos mixtos, de un elemento y totalmente negativos.
* 📊 **Resultados Finales:** * **Cobertura de Líneas (100%)**
  * **Cobertura de Ramas (100%)**: Se evaluaron exitosamente todas las bifurcaciones lógicas, probando todos los casos base de la recursión.

**Comandos de Reproducción:**
```bash
./build/unit_tests.exe
gcov -b src/solution.cpp -o build/CMakeFiles/unit_tests.dir/src/solution.cpp.obj