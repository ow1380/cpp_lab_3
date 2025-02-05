﻿#include <iostream>

using namespace std;

// создаю переменные здесь, чтобы потом ими пользоваться и в функциях
int cups[32];   // массив для хранения граммовок чашечек (размер 32 по условию)
int n;  // для хранения количества чашечек
int min_diff = 2147483647; // устанавливаю разницу на макс знач int чтобы потом можно было находить меньшее

// функция подсчета минимальной разницы между порциями
// передаю в функцию настоящий индекс (переменной, на которой мы сейчас находимся), получающиеся суммы порции Маши и Пети
void find_min_diff(int index, int sum_M, int sum_P) {

    if (index == n) {   // в случае, если мы дошли до конца массива чашечек
        int diff = abs(sum_M - sum_P);    // считаю разницу между суммами порций
        if (diff < min_diff) { // если разница меньше минимальной на данный момент
            min_diff = diff;   // обновляю минимальную разницу на новое значение
        }
        return; // завершаю выполнение функции
    }

    // рекурсивно добавляем текущую чашку сначала в первую порцию, потом во вторую
    find_min_diff(index + 1, sum_M + cups[index], sum_P); // добавляю в порцию Маши
    find_min_diff(index + 1, sum_M, sum_P + cups[index]); // добавляем в порцию Пети
}

int main() {
    cout << "Cups num:";
    cin >> n; // ввожу количество чашек

    cout << "\nCups weight:";
    for (int i = 0; i < n; ++i) // считываю граммовки всех чашек столько раз, сколько чашечек
        cin >> cups[i];

    find_min_diff(0, 0, 0); // вызываю функцию поиска минимальной разницы

    cout << "\n";
    cout << min_diff; // вывожу минимальную разницу

    return 0;
}
