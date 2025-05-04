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
    std::cout << "\n--- Таблица y = sqrt(5 - x^3) ---\n";

    std::cout << "Введите a, b и шаг h: ";
    double a = 0.0, b = 0.0, h = 0.0;
    std::cin >> a >> b >> h;

    std::cout << "\n   x\t     y\n";
    std::cout << "-----------------------\n";

    const double EPS = 1e-9;
    for (double x = a; x <= b + EPS; x += h) {
        std::cout << x << "\t";
        try {
            double y = calculateFunction(x);
            std::cout << y;
        }
        catch (const std::domain_error& e) {
            std::cout << e.what();
        }
        std::cout << "\n";
    }

    return 0;
}