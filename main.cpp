#include <iostream>
#include <stdexcept>   // для std::domain_error
#include <cmath>        // для std::sqrt
#include <iomanip>     // для std::setprecision, std::fixed

// Вычисляет y = sqrt(5 − x^3) или бросает domain_error
double calculateFunction(double x){
    // 1) вычисляем подкоренное выражение
    double expr = 5.0 - x*x*x;
    // 2) если подкоренное выражение отрицательное — бросаем исключение
    if (expr < 0.0) {
        throw std::domain_error("Функция не определена");
    }
    // 3) иначе возвращаем корень
    return std::sqrt(expr);
}

int main() {
    // 4) заголовок табличного вывода
    std::cout << "\n--- Таблица y = sqrt(5 - x^3) ---\n";

    // 5) просим пользователя ввести границы [a, b] и шаг h
    std::cout << "Введите a, b и шаг h: ";
    double a = 0.0, b = 0.0, h = 0.0;
    std::cin >> a >> b >> h;

    // 6) выводим заголовки столбцов
    std::cout << "\n   x\t     y\n";
    std::cout << "-----------------------\n";

    // 7) задаём небольшой EPS, чтобы корректно дойти до b при погрешности
    const double EPS = 1e-9;

    // 8) основной цикл по x от a до b с шагом h
    for (double x = a; x <= b + EPS; x += h) {
        // 9) выводим текущее значение x с тремя знаками после десятичной точки
        std::cout << std::fixed << std::setprecision(3) << x << "\t";
        try {
            // 10) пытаемся вычислить y = calculateFunction(x)
            double y = calculateFunction(x);
            // 11) выводим y, если функция определена
            std::cout << std::fixed << std::setprecision(3) << y;
        }
        catch (const std::domain_error& e) {
            // 12) если было исключение — выводим сообщение
            std::cout << e.what();
        }
        // 13) конец строки для новой пары (x, y)
        std::cout << "\n";
    }

    // 14) завершаем работу программы
    return 0;
}