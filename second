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

// Функция для вычисления M(N)
long long calculateM(long long N) {
    long long sumPrimeDivisors = 0;
    long long sumEvenDivisors = 0;
    int primeCount = 0;
    int evenCount = 0;

    // Простые делители
    long long temp = N;
    for (long long i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            if (isPrime(i)) {
                sumPrimeDivisors += i;
                primeCount++;
            }
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }
    if (temp > 1 && isPrime(temp)) {
        sumPrimeDivisors += temp;
        primeCount++;
    }

    // Четные делители
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i % 2 == 0) {
                sumEvenDivisors += i;
                evenCount++;
            }
            long long divisor2 = N / i;
            if (divisor2 != i && divisor2 % 2 == 0) {
                sumEvenDivisors += divisor2;
                evenCount++;
            }
        }
    }

    // Если количество простых и четных делителей совпадает
    if (primeCount == evenCount && primeCount > 0) {
        return std::abs(sumPrimeDivisors - sumEvenDivisors);
    }

    return -1; // Условие не выполняется
}

int main() {
    std::vector<std::pair<long long, long long>> results;
    long long N = 100000001; // N > 100000000

    while (results.size() < 5) {
        long long M = calculateM(N);
        if (M != -1) {
            results.push_back({N, M});
        }
        N++;

        // Прогресс для больших чисел
        if (N % 1000000 == 0) {
            std::cout << "Проверено до: " << N << std::endl;
        }
    }

    // Вывод результатов
    std::cout << "N\t\tM(N)" << std::endl;
    for (const auto& result : results) {
        std::cout << result.first << "\t" << result.second << std::endl;
    }

    return 0;
}
