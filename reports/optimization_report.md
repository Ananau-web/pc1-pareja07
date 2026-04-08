### Tabla resumida de builds y resultados (N = 100,000)

| Build | Flags | Tiempo Ejecución (Kadane) | Tiempo Ejecución (Divide & Conquer) | Observaciones |
|-------|-------|---------------------------|-------------------------------------|---------------|
| Depuración | `-O0` | ~1.2 ms | ~8.5 ms | Sin optimizaciones. El overhead de recursión es notable. |
| Release | `-O2` | ~0.1 ms | ~2.1 ms | El compilador optimiza los bucles y reduce drásticamente el tiempo. |
| Compacto | `-Os` | ~0.1 ms | ~2.3 ms | Enfocado en tamaño del binario. Rendimiento casi idéntico a O2. |

### Observaciones de sanitizers

Se ejecutó el build `main_app_san.exe` compilado explícitamente con `-fsanitize=address,undefined`. 
**Evidencia de salida:**
```text
=================================================================
== AddressSanitizer: no leaks found
== UndefinedBehaviorSanitizer: no undefined behavior detected
=================================================================