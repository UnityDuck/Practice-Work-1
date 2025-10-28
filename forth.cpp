#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int S, N;
    std::cin >> S >> N;

    std::vector<int> files(N);
    for (int i = 0; i < N; i++) {
        std::cin >> files[i];
    }

    // Сортируем файлы по возрастанию
    std::sort(files.begin(), files.end());

    int sum = 0;
    int maxUsers = 0;

    // Находим максимальное количество пользователей
    for (int i = 0; i < N; i++) {
        if (sum + files[i] <= S) {
            sum += files[i];
            maxUsers++;
        } else {
            break;
        }
    }

    // Ищем максимальный размер файла при условии максимального количества пользователей
    int maxFileSize = 0;

    // Перебираем все файлы как кандидаты на максимальный размер
    for (int i = 0; i < N; i++) {
        // Пробуем собрать набор из maxUsers файлов, включающий files[i]
        int currentSum = files[i];
        int count = 1;

        // Добавляем самые маленькие файлы, кроме текущего
        for (int j = 0; j < N && count < maxUsers; j++) {
            if (j == i) continue; // пропускаем текущий файл

            if (currentSum + files[j] <= S) {
                currentSum += files[j];
                count++;
            }
        }

        // Если набрали нужное количество пользователей и files[i] в наборе
        if (count == maxUsers) {
            if (files[i] > maxFileSize) {
                maxFileSize = files[i];
            }
        }
    }

    std::cout << maxUsers << " " << maxFileSize << std::endl;

    return 0;
}
