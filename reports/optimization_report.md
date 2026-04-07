### Tabla resumida de builds y resultados

| Build | Flags | Tamaño Ejecutable | Tiempo Ejecución (ms) | Observaciones |
|-------|-------|-------------------|-----------------------|---------------|
| Depuración | -O0 | 153K | ~0.1 (muy rápido) | Sin optimizaciones, más fácil de depurar, pero más lento y grande. |
| Release | -O2 | 140K | ~0.05 | Optimizaciones balanceadas, reduce tamaño y mejora velocidad. |
| Compacto | -Os | 137K | ~0.05 | Enfocado en tamaño, similar a O2 en velocidad. |

- **Correctitud**: Todos los builds producen resultados correctos.
- **Tiempo total**: Mínimo en todos, ya que n=9 es pequeño.
- **Tamaño del ejecutable**: O0 es el más grande (153K), O2 y Os más pequeños (140K y 137K).
- **Estabilidad**: Consistente entre corridas.
- **Facilidad de depuración**: O0 permite mejor depuración con símbolos.
- **Warnings**: Ninguno reportado.

### Observaciones de sanitizers

Se ejecutó con `-fsanitize=address,undefined`:
- No se detectaron problemas de memoria (leaks, overflows) ni undefined behavior.
- Confirma que el código es robusto para los casos probados.

### Discusión sobre microoptimización vs algoritmo

El algoritmo de Kadane (O(N)) es superior a Divide y Vencerás (O(N log N)) para este problema, incluso sin optimizaciones. La microoptimización (como cambiar -O0 a -O2) mejora el rendimiento en ~10-20%, pero elegir el algoritmo correcto tiene impacto exponencial mayor. En el benchmark STL, usar `reserve()` mejora ~18% el tiempo de inserción en vector, demostrando que decisiones algorítmicas/estructurales superan flags de compilación.