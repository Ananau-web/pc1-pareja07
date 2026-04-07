#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    // ---------------------------------------------------------
    // ENFOQUE 1: Algoritmo de Kadane (El Óptimo)
    // Complejidad: Tiempo O(N), Espacio O(1)
    // ---------------------------------------------------------
    int maxSubArrayKadane(const std::vector<int>& nums) {
        int max_global = nums[0]; 
        int max_local = nums[0];  

        for (size_t i = 1; i < nums.size(); i++) {
            // Decisión de Kadane: ¿Me uno al subarreglo anterior o empiezo uno nuevo?
            max_local = std::max(nums[i], max_local + nums[i]);
            
            // Actualizamos el récord global si el local lo superó
            if (max_local > max_global) {
                max_global = max_local;
            }
        }

        return max_global;
    }

    // ---------------------------------------------------------
    // ENFOQUE 2: Divide y Vencerás (El Recursivo)
    // Complejidad: Tiempo O(N log N), Espacio O(log N)
    // ---------------------------------------------------------
    int maxSubArrayDivideAndConquer(const std::vector<int>& nums) {
        // Hacemos una copia local si necesitamos pasarla por referencia no constante, 
        // o adaptamos las funciones privadas para aceptar const std::vector<int>&
        return DivideyVenceras(nums, 0, nums.size() - 1);
    }

    // ---------------------------------------------------------
    // Función principal requerida por LeetCode
    // ---------------------------------------------------------
    int maxSubArray(std::vector<int>& nums) {
        // Aquí puedes cambiar cuál quieres ejecutar.
        // Para LeetCode, Kadane es la mejor opción.
        return maxSubArrayKadane(nums); 
    }

private:
    // Nota: Cambié a const std::vector<int>& por buena práctica, ya que no modificamos el arreglo
    int DivideyVenceras(const std::vector<int>& nums, int left, int right) {
        // Caso base: solo un elemento
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;

        // 1. Buscar en la izquierda, 2. Buscar en la derecha
        int left_sum = DivideyVenceras(nums, left, mid);
        int right_sum = DivideyVenceras(nums, mid + 1, right);
        
        // 3. Buscar el subarreglo que cruza el centro
        int cross_sum = maxCrossingSum(nums, left, mid, right);

        // Retornar el máximo de los tres casos
        return std::max({left_sum, right_sum, cross_sum});
    }

    int maxCrossingSum(const std::vector<int>& nums, int left, int mid, int right) {
        // Suma hacia la izquierda desde el medio
        int sum = 0;
        int left_part = std::numeric_limits<int>::lowest();
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            if (sum > left_part) left_part = sum;
        }

        // Suma hacia la derecha desde el medio
        sum = 0;
        int right_part = std::numeric_limits<int>::lowest();
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            if (sum > right_part) right_part = sum;
        }

        return left_part + right_part;
    }
};