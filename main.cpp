#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

void set(float **array, int n);

void show(float **array, int n);

void kill(float **array, int n);

float **matrix(int n);

float mnorm(float **array, int n);

float fabsolute(float number);

float maximum(const float *array, int n);

int main() {
    cout << "Введіть розмір масиву: ";
    int n;
    cin >> n;
    float **mA = matrix(n);
    float **mB = matrix(n);
    set(mA, n);
    set(mB, n);
    show(mA, n);
    show(mB, n);

    cout << "Знаходження М-норма першого масиву" << endl;
    float mNormA= mnorm(mA, n);
    cout << mNormA << endl;
    cout << "Знаходження М-норма другого масиву" << endl;
    float mNormB= mnorm(mB, n);
    cout << mNormB << endl;

    cout << "Середнє арифметичне: " << (mNormA+mNormB)/2;

    kill(mA, n);
    kill(mB, n);
    return 0;
}

void set(float **array, int n) {
    random_device rd;
    mt19937 mersenne(rd());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(*(array + i) + j) = (float) ((float) (mersenne() % 100) * 0.99);
        }
    }
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
        if (*(array+i) > maximum)
            maximum = *(array+i);
    }
    return maximum;
}

