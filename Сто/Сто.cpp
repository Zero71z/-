#include <iostream>
#include <cstdlib>
#include <ctime>

//Константное значение размера матрицы
const int MATRIX_SIZE = 4;
using namespace std;
//вывод матрицы на экран
void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Проверка результата
bool checkPuzzle(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != 100 || colSum != 100) {
            return false;
        }
    }
    return true;
}
// Работа с матрицей пользователем
void solvePuzzle() {
    //Вводим начальное задание
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
     {7, 8, 4, 9},
     {9, 4, 2, 4},
     {9, 7, 7, 4},
     {3, 3, 2, 8}
    };
    //объявляем начальное задание пользователю
    cout << "Исходная матрица:" << endl;
    char choice;

    do {
        //выводим матрицу
        printMatrix(matrix);

        int userDigit, rowIndex, colIndex;  //Объявляем переменные
        char direction;

        //Пользователь вводит значение для подстановки
        cout << "Введите цифру для подстановки: ";
        while (!(cin >> userDigit)) {
            cout << "Ошибка: Введите корректное число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //Пользователь вводит координаты в матрице куда будет подставлять вписанное значение
        cout << "Введите индекс строки для подстановки (от 0 до 3): ";
        while (!(cin >> rowIndex) || rowIndex < 0 || rowIndex >= MATRIX_SIZE) {
            cout << "Ошибка: Введите корректный индекс строки (от 0 до 3)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        cout << "Введите индекс столбца для подстановки (от 0 до 3): ";
        while (!(cin >> colIndex) || colIndex < 0 || colIndex >= MATRIX_SIZE) {
            cout << "Ошибка: Введите корректный индекс столбца (от 0 до 3)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //Пользователь выбирает с какой стороны поставить цифру
        cout << "Выберите сторону (l - слева, r - справа): ";
        while (!(cin >> direction) || (direction != 'l' && direction != 'L' && direction != 'r' && direction != 'R')) {
            cout << "Ошибка: Введите 'l' или 'r'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        //Если пользователь выбирает подставить слева, то мы сначала доводим значение изначальной переменной до десятков, а потом прибавляем введенное значение.
        if (direction == 'l' || direction == 'L') {
            matrix[rowIndex][colIndex] = userDigit * 10 + matrix[rowIndex][colIndex];
        }//Если выбор подставить справа, то всё что выше, только наоборот
        else if (direction == 'r' || direction == 'R') {
            matrix[rowIndex][colIndex] = matrix[rowIndex][colIndex] * 10 + userDigit;
        }
        //Выводим полученную матрицу 
        cout << "Получившаяся матрица:" << endl;
        printMatrix(matrix);

        //Спрашиваем у пользователя, нужно ли продолжить решение или подвести итоги
        cout << "Продолжить (Y/N)? ";
        cin >> choice;

        cin.clear();  // проверяем на ошибки и востанавливаем поток в случае чего
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очищаем

    } while (choice == 'y' || choice == 'Y');
    //Если он отвечает Y (да), то цикл начинается с начала, а значение сохраняется в матрице
    //Если пользователь ответил N (или что угодно иное) то цикл закрывается и происходит проверка решения
    if (checkPuzzle(matrix)) {
        cout << "Головоломка пройдена!" << endl;
    }
    else {
        cout << "Головоломка не решена." << endl;
    }
}
//Точка входа в программу
int main() {
    setlocale(LC_ALL, "Russian");
    solvePuzzle();
    return 0;  //завершаем выполнение функции
}