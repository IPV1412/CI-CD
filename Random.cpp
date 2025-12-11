#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void generarNumeros(std::vector<int>& nums, int cantidad, int maxRange) {
    nums.clear();
    for (int i = 0; i < cantidad; i++)
        nums.push_back(std::rand() % maxRange);
}

void mostrarEstadisticas(const std::vector<int>& nums) {
    int sum = 0;
    int minV = nums[0], maxV = nums[0];

    for (int n : nums) {
        sum += n;
        if (n < minV) minV = n;
        if (n > maxV) maxV = n;
    }

    std::cout << "Min: " << minV
              << "\nMax: " << maxV
              << "\nPromedio: " << (sum / (double)nums.size()) << "\n";
}

int main() {
    std::srand(std::time(0));

    int cantidad = 10;
    int maxRange = 100;
    std::vector<int> nums;

    int opcion = 0;

    while (opcion != 4) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Generar numeros aleatorios\n";
        std::cout << "2. Mostrar estadisticas\n";
        std::cout << "3. Ordenar numeros\n";
        std::cout << "4. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Cantidad: ";
            std::cin >> cantidad;
            std::cout << "Rango maximo: ";
            std::cin >> maxRange;
            generarNumeros(nums, cantidad, maxRange);
            std::cout << "Numeros generados.\n";
            break;

        case 2:
            if (nums.empty()) {
                std::cout << "Primero genera numeros.\n";
            } else {
                mostrarEstadisticas(nums);
            }
            break;

        case 3:
            if (nums.empty()) {
                std::cout << "No hay numeros generados.\n";
            } else {
                std::sort(nums.begin(), nums.end());
                std::cout << "Numeros ordenados: ";
                for (int n : nums) std::cout << n << " ";
                std::cout << "\n";
            }
            break;
        }
    }

    return 0;
}
