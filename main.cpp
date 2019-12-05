#include <iostream>
#include <iomanip>
#include <random>

using namespace std;


void show(float **array, int n);//Показ матриці

int getN(); //введеня розміру матриці користувачем

void kill(float **array, int n);//Очищення пам'яті

float **matrix(int n);//Створення і задання матриці

float mnorm(float **array, int n);//Знаходження М-норма

float fabsolute(float number);//Знаходження модуля числа

float maximum(const float *array, int n);//Знаходження максимального значення

int main() {
    int n = getN();//Розмір матриці введений користувачем
    float **mA = matrix(n);//Вказівник на першу матрицю
    float **mB = matrix(n);//Вказівник на другу матрицю
    show(mA, n);
    show(mB, n);

    cout << "Знаходження М-норма першого масиву" << endl;
    float mNormA = mnorm(mA, n);//М-норм першої матриці
    cout << mNormA << endl;
    cout << "Знаходження М-норма другого масиву" << endl;
    float mNormB = mnorm(mB, n);//М-
    cout << mNormB << endl;

    cout << "Середнє арифметичне: " << (mNormA + mNormB) / 2;

    kill(mA, n);
    kill(mB, n);
    return 0;
}


void show(float **array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(7) << fixed << setprecision(2) << *(*(array + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void kill(float **array, int n) {
    for (int i = 0; i < n; i++)
        delete[]*(array + i);
    delete[]array;
}

float **matrix(int n) {
    float **matrix;
    matrix = new float *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new float[n];

    random_device rd;
    mt19937 mersenne(rd());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(*(matrix + i) + j) = (float) ((float) (mersenne() % 16) - 5);
        }
    }


    return matrix;
}

float mnorm(float **array, int n) {
    auto *sumFabs = new float[n];
    for (int i = 0; i < n; ++i) {
        *(sumFabs + i) = 0;
        for (int j = 0; j < n; ++j) {
            *(sumFabs + i) += fabsolute(*(*(array + i) + j));
        }
        cout << *(sumFabs + i) << " ";
    }
    cout << endl;
    float max = maximum(sumFabs, n);
    delete[]sumFabs;
    return max;
}

float fabsolute(float number) {
    return (number > 0) ? number : number * (-1);
}

float maximum(const float *array, int n) {
    float maximum = *array;
    for (int i = 0; i < n; ++i) {
        if (*(array + i) > maximum)
            maximum = *(array + i);
    }
    return maximum;
}

int getN() {
    cout << "Введіть розмір масиву: ";
    int n;
    cin >> n;
    return n;
}

