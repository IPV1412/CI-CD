#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    int maxRange;
    std::cout << "Ingresa el limite maximo: ";
    std::cin >> maxRange;

    std::vector<int> nums;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        int num = std::rand() % maxRange;
        nums.push_back(num);
        sum += num;
    }

    int min = nums[0];
    int max = nums[0];

    for (int n : nums) {
        if (n < min) min = n;
        if (n > max) max = n;
    }

    std::cout << "Numeros generados: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\nMin: " << min
              << "\nMax: " << max
              << "\nPromedio: " << (sum / 10.0) << std::endl;

    return 0;
}
