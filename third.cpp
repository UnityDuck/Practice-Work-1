#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Функция для проверки простоты числа
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для вычисления F(N)
int calculateF(int N) {
    std::vector<int> primeDivisors;

    // Находим все простые делители, оканчивающиеся на 7
    for (int i = 2; i < N; i++) {
        if (N % i == 0 && isPrime(i) && i % 10 == 7) {
            primeDivisors.push_back(i);
        }
    }

    if (primeDivisors.empty()) {
        return 0;
    }

    // Вычисляем среднее арифметическое
    int sum = 0;
    for (int divisor : primeDivisors) {
        sum += divisor;
    }

    return sum / primeDivisors.size(); // Целая часть
}

int main() {
    std::vector<std::pair<int, int>> results;

    // Перебираем числа в порядке убывания от 749999 до 1
    for (int N = 749999; N >= 1 && results.size() < 5; N--) {
        int F = calculateF(N);

        if (F != 0 && F % 111 == 0) {
            results.push_back({N, F});
        }

        // Прогресс
        if (N % 50000 == 0) {
            std::cout << "Проверено до: " << N << std::endl;
        }
    }

    // Вывод результатов
    std::cout << "Число\tF(N)" << std::endl;
    for (const auto& result : results) {
        std::cout << result.first << "\t" << result.second << std::endl;
    }

    return 0;
}
