#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    int maxRange;
    std::cout << "Ingresa el limite maximo de los numeros aleatorios: ";
    std::cin >> maxRange;

    for (int i = 0; i < 10; i++) {
        int num = std::rand() % maxRange; 
        std::cout << num << std::endl;
    }

    return 0;
}
