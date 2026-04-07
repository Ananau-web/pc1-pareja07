 #### Integrantes

- Rydell Jonel Mosquera Huayhua

- Joel Gustavo Carhuarica Aguilar
#### Competencia del curso Problema asignado

Diseñar, implementar, analizar y sustentar el Maximum Subarray de arreglos, justificando formalmente su correctitud, complejidad y pertinencia práctica.


#### Enlace al enunciado de LeetCode
<a href="https://leetcode.com/problems/maximum-subarray/"

#### Especificación breve del problema
Desarrollar un algoritmo que calcule la maxima suma de un arreglo mediante el metodo "Divide y Venceras". El programa solicita de las librerias <vector>,<limits>,<algorithm> que contienen herramientas ya programadas.

#### Entrada y salida
**Entrada**: Un conjunto de n números enteros almacenados en un vector.

**Salida**: Un valor entero que representa la máxima suma posible de cualquier subarreglo contiguo dentro del vector de entrada.

#### Tamaño de entrada relevante
El algoritmo está diseñado para procesar un vector de tamaño N, donde 1≤N≤10⁵. Para este rango, el enfoque de Kadane es el más óptimo, ya que mantiene una complejidad lineal O(N) y un uso de memoria constante O(1).

##### Descripción de la solución
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
1. Progreso del Bucle: En el algoritmo de Kadane, el índice de iteración i sigue una progresión monótona creciente, lo que garantiza que el algoritmo recorra el espacio de búsqueda de forma exhaustiva y termine al alcanzar el límite n.
2. Convergencia Recursiva: En el enfoque de Divide y Vencerás, la longitud del segmento procesado (right−left+1) es monótonamente decreciente en cada nivel de recursión. Esto asegura la convergencia hacia el caso base, evitando recursiones infinitas.
3. Complejidad: Las funciones de costo computacional de ambos métodos son monótonas respecto al tamaño de la entrada, lo que permite una predicción estable del rendimiento del sistema ante el crecimiento de los datos.

#### Complejidad temporal
La solución óptima implementada (Kadane) presenta una complejidad temporal de O(n), lo que garantiza un rendimiento escalable incluso ante volúmenes masivos de datos. Por otro lado, la variante de Divide y Vencerás posee una complejidad de O(nlogn), siendo una alternativa académicamente robusta pero computacionalmente más costosa que la primera."

##### Complejidad espacial
El Algoritmo de Kadane es óptimo en términos de memoria, presentando una complejidad espacial de O(1), ya que opera in-place y solo requiere un número constante de variables auxiliares. Por el contrario, la solución de Divide y Vencerás tiene una complejidad de O(logn), derivada del uso de la pila de recursión necesaria para procesar las subdivisiones del arreglo.

##### Mejor, peor y promedio cuando aplique
- Para el algoritmo de Kadane no hay diferencias significativa entre los casos al igual que Divide y Venceras.
Mejor, Peor y Promedio(Kadane): Todos son O(n).
Mejor, Peor y Promedio(Divide y Venceras): Todos son O(nlogn).

#### Ubicación aproximada en la jerarquía de crecimiento del curso
En la jerarquía de crecimiento asintótico, la solución óptima implementada (Kadane) se ubica en la categoría lineal O(n), lo cual representa el límite inferior de complejidad para problemas que requieren la lectura completa de los datos. La solución alternativa de Divide y Vencerás se posiciona ligeramente por encima, en la categoría O(nlogn), siendo ambas significativamente superiores a las soluciones triviales de orden cuadrático.

#### Alternativa ingenua o menos eficiente
La solución ingenua consiste en un enfoque de fuerza bruta con una complejidad de O(n²). Este método utiliza bucles anidados para iterar sobre todos los pares posibles de índices (inicio y fin) y calcular sus sumas de forma exhaustiva. Aunque es funcional para arreglos pequeños, se vuelve computacionalmente costosa e ineficiente para valores de n superiores a 10⁴, siendo superada ampliamente por el Algoritmo de Kadane (O(n)) y el enfoque de Divide y Vencerás (O(nlogn)) implementados en este proyecto

#### Discusión breve de robustez, degeneración y reutilización
El sistema demuestra una alta robustez al procesar arreglos con valores negativos extremos gracias a la correcta inicialización de límites. Su principal punto de degeneración potencial es el manejo de vectores vacíos, lo cual es fácilmente mitigable. Finalmente, la estructura modular basada en la clase Solution y el uso de contenedores estándar facilitan su reutilización y escalabilidad en otros módulos de software que requieran análisis de secuencias numéricas.

#### Instrucciones para compilar
- Para VS Code:
El código actual es una clase. Para que funcione, necesitamos un archivo que tenga la función main.

[text](src/main.cpp).

#### Instrucciones para ejecutar
Si preferimos usar la interfaz gráfica:

1.Asegúrarse de tener el archivo .cpp abierto.

2.Método rápido: hacer click en el icono "Play" (Triángulo) en la esquina superior derecha de la pantalla.

3.Selección de compilador: Si te pregunta, elige g++.exe o cl.exe (dependiendo de cuál instalaste).

4.Ver el resultado: Se abrirá automáticamente una pestaña llamada "Terminal" en la parte inferior de VS Code donde aparecerá el mensaje: La suma maxima es: 6.

#### Instrucciones para correr tests
1. Pasos para correr los tests

1.1.Guarda el archivo con el código anterior.

1.2.Compila: ```bash
g++ -std=c++11 -o test_suite main.cpp
1.3.Ejecuta:
En Windows: .\test_suite.exe
En Linux/Mac: ./test_suite

#### Breve descripción del benchmark realizado
La inclusión de este benchmark justifica que para aplicaciones de alto rendimiento o procesamiento de grandes volúmenes de datos (N>106), la eficiencia no solo depende de la complejidad asintótica del algoritmo (como Kadane), sino también de una correcta interacción con las estructuras de datos de la STL para minimizar la latencia de memoria.
#### Tabla resumida de builds y resultados

  

### Observaciones de sanitizers

  

### Resumen de cobertura

  

### Resumen de profiling

  

### Discusión sobre microoptimización vs algoritmo

  

### Qué se usó de Copilot y cómo se valido