#include "solution.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>  

int main() {
    Solution sol;

    // ====================================================================
    // PARTE 1: PRUEBA DE CORRECTITUD (Caso clásico de LeetCode)
    // ====================================================================
    std::cout << "====================================================\n";
    std::cout << "  PARTE 1: PRUEBA DE CORRECTITUD (N = 9) \n";
    std::cout << "====================================================\n";
    
    std::vector<int> nums_small = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Arreglo original: { ";
    for (int num : nums_small) {
        std::cout << num << " ";
    }
    std::cout << "}\n\n"; //

    int resKadaneSmall = sol.maxSubArrayKadane(nums_small);
    int resDivideSmall = sol.maxSubArrayDivideAndConquer(nums_small);
    
    std::cout << "[Metodo 1] Kadane            -> Resultado = " << resKadaneSmall << "\n";
    std::cout << "[Metodo 2] Divide y Venceras -> Resultado = " << resDivideSmall << "\n";
    
    if (resKadaneSmall == resDivideSmall) {
        std::cout << "-> ¡Exito! Ambos algoritmos coinciden en el caso base.\n\n";
    }
