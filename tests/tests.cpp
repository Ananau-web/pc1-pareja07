#include <iostream>
#include <vector>
#include <cassert>
#include "solution.hpp"

// ---------------------------------------------------------
// PRUEBAS UNITARIAS: Maximum Subarray
// Patrón AAA: Arrange (Preparar), Act (Actuar), Assert (Comprobar)
// ---------------------------------------------------------

void test_caso_normal() {
    // Arrange
    Solution sol;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    // Act
    int resultado = sol.maxSubArray(nums);
    
    // Assert
    assert(resultado == 6);
    std::cout << "[OK] test_caso_normal pasado.\n";
}

void test_todos_negativos() {
    // Arrange
    Solution sol;
    std::vector<int> nums = {-5, -2, -9, -1, -7};
    
    // Act
    int resultado = sol.maxSubArray(nums);
    
    // Assert
    assert(resultado == -1); // El máximo es el menor número negativo
    std::cout << "[OK] test_todos_negativos pasado.\n";
}

void test_un_solo_elemento() {
    // Arrange
    Solution sol;
    std::vector<int> nums = {5};
    
    // Act
    int resultado = sol.maxSubArray(nums);
    
    // Assert
    assert(resultado == 5);
    std::cout << "[OK] test_un_solo_elemento pasado.\n";
}

void test_disenado_por_la_pareja() {
    // Arrange
    // (Requisito de la PC1: Al menos un caso diseñado por la propia pareja)
    Solution sol;
    std::vector<int> nums = {100, -50, 100, -200, 500};
    
    // Act
    int resultado = sol.maxSubArray(nums);
    
    // Assert
    assert(resultado == 500); // El subarreglo es solo {500}
    std::cout << "[OK] test_disenado_por_la_pareja pasado.\n";
}

int main() {
    std::cout << "--- INICIANDO BATERIA DE PRUEBAS ---\n";
    
    test_caso_normal();
    test_todos_negativos();
    test_un_solo_elemento();
    test_disenado_por_la_pareja();

    std::cout << "--- TODAS LAS PRUEBAS PASARON EXITOSAMENTE ---\n";
    return 0;
}