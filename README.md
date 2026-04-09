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

El código fue sometido a distintas banderas de compilación en GCC utilizando un arreglo masivo (`N = 1,000,000`). Se incluyeron las banderas `-Wall -Wextra -Wpedantic` para garantizar la calidad estricta del código.

#### Tabla Comparativa de Builds (Tiempos empíricos reales)

| Build | Comando de Optimización | Tiempo Kadane | Tiempo D&C | Observaciones |
| :--- | :--- | :--- | :--- | :--- |
| **Depuración** | `-O0` | 5.736 ms | 93.993 ms | Sin optimizaciones. El *overhead* de la pila de recursión es masivo. |
| **Release** | `-O2` | 2.345 ms | 37.645 ms | Aceleración drástica. El compilador vectoriza y desenrolla bucles (*loop unrolling*). |
| **Compacto** | `-Os` | 1.530 ms | 51.785 ms | Prioriza tamaño del binario. Curiosamente, en Kadane fue el más rápido (1.53 ms), posiblemente por un mejor encaje en la memoria Caché L1. |
| **Profiling** | `-O2 -pg` | 0.000 ms | 50.997 ms | Compilado para `gprof`. Kadane se ejecutó en una fracción tan minúscula que no alcanzó a marcar un milisegundo completo. |

**Conclusión del Experimento (Microoptimización vs Algoritmo):**
Los datos demuestran empíricamente que la correcta elección algorítmica es superior a cualquier herramienta. El Algoritmo de Kadane compilado sin optimizaciones (`-O0` tardando ~5.7 ms) supera aplastantemente al enfoque de Divide y Vencerás compilado con máxima velocidad (`-O2` tardando ~37.6 ms). El compilador no puede salvar a un algoritmo con una complejidad asintótica pesada como $O(N \log N)$.

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
```
## 5. Resumen de Profiling y Análisis de Rendimiento (`gprof`)

**Nota metodológica:** Al intentar realizar el profiling inicial con un arreglo básico de 9 elementos, los tiempos de ejecución en `gprof` arrojaban sistemáticamente `0.00s`. Esto ocurre porque la resolución de la herramienta es de 0.01 segundos, y un procesador moderno ejecuta una complejidad $O(N \log N)$ para N=9 de forma casi instantánea. *(Nota: Durante la ejecución en MinGW/Windows, es común observar el mensaje `BFD: Dwarf Error`, el cual es un bug visual de consola que no afecta los resultados).*

Para obtener un análisis real, inyectamos una carga masiva aleatoria de 1,000,000 de elementos y ejecutamos los comandos de `gprof`.

**📊 Resultados del Análisis bajo Carga Masiva**
La tabla de `gprof` arrojó resultados contundentes:
* **`Solution::DivideyVenceras`:** Concentró el **66.67%** del tiempo total de ejecución medible.
* **`Solution::maxSubArrayKadane`:** Concentró el **0.00%** (se ejecutó en una fracción inferior a 0.01s).

**Conclusiones Empíricas:**
1. **¿Qué función concentra más tiempo?** Las funciones correspondientes al enfoque de "Divide y Vencerás" concentran casi la totalidad del tiempo de CPU medible. Kadane es imperceptible para el sistema de medición.
2. **¿Coincide con la complejidad?** Sí, coincide absolutamente. Confirma empíricamente que $O(N)$ es órdenes de magnitud más eficiente en la práctica que $O(N \log N)$ para entradas masivas.
3. **Cuello de Botella:** El verdadero cuello de botella en sistemas de alto rendimiento es el *overhead* (sobrecarga) generado por la pila de llamadas (Call Stack) en la recursividad. La iteración plana (*in-place*) de Kadane aprovecha al máximo la **localidad de caché** del procesador.

---

## 6. Benchmarks Básicos y Microoptimización

Para cumplir con el requisito de experimentación, diseñamos dos microexperimentos utilizando la librería `<chrono>` de C++:

#### A. Comparación Algorítmica (Kadane vs. Divide y Vencerás)
Inyectamos un arreglo de $N = 1,000,000$ de elementos y medimos los tiempos:
* **Resultado empírico:** Kadane finalizó en **~1.2 ms**, mientras que el enfoque recursivo tardó **~25.0 ms**.
* **Microoptimización vs Algoritmo:** Comprobamos que Kadane $O(N)$ compilado sin optimizaciones (`-O0`) supera aplastantemente al enfoque recursivo $O(N \log N)$ compilado con máxima optimización (`-O2`). El compilador no puede salvar a un algoritmo con mala complejidad asintótica.

#### B. Microexperimento de Estructuras de Datos (`reserve`)
En `bench/benchmark.cpp`, evaluamos el impacto de la asignación dinámica de memoria comparando el tiempo de inserción de $10^7$ elementos en un `std::vector`.
* **Resultado empírico:** El tiempo de inserción estándar (sin pre-asignación) fue de **~112.6 ms**. Al utilizar el método `.reserve(N)`, el tiempo se redujo a **~91.5 ms**.
* **Conclusión:** El uso de `reserve()` hizo que la ejecución fuera un **23% más rápida (1.23x)**. A nivel de ingeniería, la eficiencia real requiere tanto de un algoritmo matemático óptimo como de buenas prácticas de programación (pre-asignación) para evitar reubicaciones costosas en la memoria RAM y Caché.

---

## 7. Video de Sustentación

En el siguiente enlace de Google Drive se encuentra el video de nuestra exposición, donde sustentamos la teoría algorítmica, los resultados de Profiling (`gprof`), la cobertura de código (`gcov`) y los benchmarks ejecutados:

🎥 **[Ver Video de Sustentación en Google Drive](https://drive.google.com/file/d/17aSlEtIWU3Ajv4umyjnmywm0v2VYSUlL/view?usp=sharing)**