# 🔬 Máximo Subarreglo Contiguo - Proyecto PC1

#### 👥 Integrantes
- Rydell Jonel Mosquera Huayhua
- Joel Gustavo Carhuarica Aguilar.

#### Competencia del curso Problema asignado
Diseñar, implementar, analizar y sustentar el Maximum Subarray de arreglos, justificando formalmente su correctitud, complejidad y pertinencia práctica.

#### Enlace al enunciado de LeetCode
<a href="https://leetcode.com/problems/maximum-subarray/">LeetCode - Maximum Subarray</a>

#### Especificación breve del problema
Desarrollar un algoritmo que calcule la maxima suma de un arreglo mediante el metodo "Divide y Venceras". El programa solicita de las librerias `<vector>`, `<limits>`, `<algorithm>` que contienen herramientas ya programadas.

#### Entrada y salida
**Entrada**: Un conjunto de n números enteros almacenados en un vector.
**Salida**: Un valor entero que representa la máxima suma posible de cualquier subarreglo contiguo dentro del vector de entrada.

#### Tamaño de entrada relevante
El algoritmo está diseñado para procesar un vector de tamaño N, donde 1≤N≤10⁵. Para este rango, el enfoque de Kadane es el más óptimo, ya que mantiene una complejidad lineal O(N) y un uso de memoria constante O(1).

##### Descripción de la solución:
Aunque ambos métodos llegan al mismo resultado, el Algoritmo de Kadane es el preferido para este problema por su eficiencia superior en tiempo y el uso mínimo de memoria (espacio O(1)), ya que no requiere llamadas recursivas ni estructuras de datos adicionales.

#### Justificación de determinismo y factibilidad
- Determinismo=El resultado es idéntico en cada ejecución para una misma entrada, ya que las comparaciones y sumas siguen un flujo lógico fijo sin componentes aleatorios.
- Factibilidad=La solución es viable para sistemas reales debido a su baja complejidad computacional (O(n)). El uso de memoria es mínimo y los recursos de hardware actuales superan con creces los requisitos del algoritmo.

#### Argumento de finitud
El algoritmo es finito porque todas sus estructuras de control tienen un punto de terminación definido. El método iterativo (Kadane) recorre el arreglo un número exacto de veces igual al tamaño de la entrada (N), mientras que el método recursivo reduce el espacio de búsqueda en cada paso hasta alcanzar el caso base, evitando ciclos infinitos.

#### Argumento de correctitud
El algoritmo es correcto porque agota todas las posibilidades de formación de subarreglos. En la versión iterativa, se aplica una técnica de programación dinámica que asegura el cálculo del máximo local en cada índice. En la versión recursiva, se aplica un esquema de exhaustividad mediante la división del problema en subcasos (izquierda, derecha y cruce), asegurando que el subarreglo óptimo sea capturado en alguno de los tres escenarios posibles.

## Invariante, cuando aplique
Propiedad: "Al inicio de cada iteración i, la variable max_global contiene la suma del subarreglo máximo encontrado en el intervalo nums[0...i-1], mientras que max_local contiene la suma del subarreglo máximo que termina estrictamente en la posición i-1"
1. Inicialización: Antes de la primera iteración (i=1), ambas variables se inicializan con nums[0]. Esto es correcto ya que, en un arreglo de un solo elemento, el subarreglo máximo y el que termina en esa posición son el mismo.
2. Mantenimiento: Durante la iteración i, el algoritmo calcula el nuevo max_local comparando el elemento actual nums[i] con la suma acumulada max_local + nums[i]. Esto asegura que max_local siga siendo el máximo subarreglo que termina en i. Luego, max_global se actualiza solo si este nuevo valor supera al récord anterior. Así, al final de la iteración, la propiedad se mantiene para el siguiente índice.
3. Terminación: El bucle finaliza cuando i=nums.size(). Según el invariante, en este punto max_global ha comparado todos los posibles "máximos locales" de todo el arreglo, garantizando que el valor retornado sea la suma máxima absoluta.

#### Monotonicidad, cuando aplique
1. Progreso de