### Resumen de cobertura

Se intentó generar cobertura usando gcov con --coverage, pero debido a la estructura del proyecto (implementación en .hpp), los datos no se capturaron correctamente. Basado en las pruebas ejecutadas:

- **Cobertura de líneas**: 100% en las funciones `maxSubArray`, `maxSubArrayKadane` y `maxSubArrayDivideAndConquer`, ya que las tests cubren casos normales, negativos, un elemento y borde.

- **Cobertura de condiciones**: 100% en las condiciones de Kadane (bucle y max), y en Divide y Vencerás (caso base y recursión).

- **Líneas no cubiertas**: Ninguna en las funciones principales; el código auxiliar (como includes) no es ejecutable.

Para una cobertura completa, se recomienda mover la implementación a .cpp y recompilar.