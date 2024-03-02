#include <iostream>
#include <vector>
#include <oneapi/tbb/parallel_for.h>

int main() {
    const size_t n = 100000; // Size of the vector
    std::vector<int> data(n);

    // Initialize the vector with some values.
    for (size_t i = 0; i < n; ++i) {
        data[i] = i;
    }

    // Use oneTBB parallel_for to calculate the squares of the numbers in parallel.
    oneapi::tbb::parallel_for(size_t(0), n, [&](size_t i) {
        data[i] = data[i] * data[i];
    });

    // Print the first 10 squares as a sanity check.
    for (size_t i = 0; i < 10; ++i) {
        std::cout << "Square of " << i << " is " << data[i] << std::endl;
    }

    return 0;
}
