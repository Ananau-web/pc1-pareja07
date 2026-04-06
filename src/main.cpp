#include "solution.hpp"
#include <iostream>
#include <vector>

int main() {
    Solution sol;

    // Arreglo de prueba clásico de LeetCode
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << "=== PRUEBA DE ALGORITMOS: MAXIMUM SUBARRAY ===\n";
    
    // Imprimir el arreglo original para contexto
    std::cout << "Arreglo original: { ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "}\n\n";

    // 1. Prueba con el Algoritmo de Kadane (O(N))
    int resultKadane = sol.maxSubArrayKadane(nums);
    std::cout << "[Metodo 1] Algoritmo de Kadane (O(N)):\n";
    std::cout << "-> Suma maxima encontrada = " << resultKadane << "\n\n";

    // 2. Prueba con Divide y Vencerás (O(N log N))
    int resultDivide = sol.maxSubArrayDivideAndConquer(nums);
    std::cout << "[Metodo 2] Divide y Venceras (O(N log N)):\n";
    std::cout << "-> Suma maxima encontrada = " << resultDivide << "\n\n";

    // Comprobación de que ambos métodos dan el mismo resultado
    if (resultKadane == resultDivide) {
        std::cout << "¡Exito! Ambos algoritmos llegaron al mismo resultado.\n";
    } else {
        std::cout << "¡Error! Los resultados difieren. Revisa la logica.\n";
    }

    return 0;
}