#include <iostream>
#include <stdexcept>   // для std::domain_error
#include <cmath>        // для std::sqrt

// Вычисляет y = sqrt(5 − x^3) или бросает domain_error
double calculateFunction(double x){
    double expr = 5.0 - x*x*x;
    if (expr < 0.0) {
        throw std::domain_error("Функция не определена");
    }
    return std::sqrt(expr);
}

int main() {
    return 0;
}