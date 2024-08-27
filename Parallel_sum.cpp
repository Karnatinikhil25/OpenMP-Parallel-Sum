#include <iostream>
#include <omp.h>

int main() {
    const int size = 1000000;
    int array[size];
    long long sum = 0;

    // Initialize the array with values
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }

    // Start parallel region
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
