#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 10; i++) {
        int num = std::rand() % 100; 
        std::cout << num << std::endl;
    }

    return 0;
}
