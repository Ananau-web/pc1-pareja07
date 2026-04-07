### Resumen de profiling

Se ejecutó profiling usando gprof en el ejecutable `main_app.exe` compilado con `-pg`.

- **Función que concentra más tiempo**: Ninguna función individual concentra tiempo significativo, ya que el programa es muy rápido para el tamaño de entrada pequeño (n=9). El tiempo total es mínimo y no se acumula en ninguna función específica.

- **Coincide con el análisis de complejidad**: Sí, ambos algoritmos (Kadane O(N) y Divide y Vencerás O(N log N)) son eficientes para n pequeño, por lo que no hay cuello de botella detectable.

- **Conclusión**: Para entradas pequeñas, el overhead de profiling no revela diferencias. Para entradas grandes, Kadane sería más eficiente, pero el profiling actual confirma que no hay funciones problemáticas.