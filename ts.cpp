#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    float smallestNormalizedFloat = std::numeric_limits<float>::min();
    std::cout << "Smallest normalized positive float: " << smallestNormalizedFloat << std::endl;

    // Example usage
    float underflowTest = smallestNormalizedFloat / 2.0f; // This operation may result in a denormalized number or underflow
    std::cout << "Result of division by 2: " << underflowTest << std::endl;
    
    return 0;
}
