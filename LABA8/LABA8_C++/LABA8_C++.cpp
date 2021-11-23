

#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    const int rows = 8;
    const int cols = 4;
    double arr[rows][cols];

    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            arr[i][j] = (double)(-10000 + rand() %20000)/1000;
        }
    }
    double temp = 1;
    bool flag = false;
    double *p = nullptr;
    int size = 0;
    int i;
    int j;
    for (i = 0;i < rows;i++) {
        for (j = 0;j < cols;j++) {
            if (arr[i][j] < 0) {
                flag = true;
                temp *= arr[i][j];
            }
        }
        if (flag) {
            if (size == 0) {
                size++;
                p = new double[size];
                *p = temp;
            }
            else {
                size++;
                double* new_p = new double[size];
                for (int k = 0;k < size - 1;k++) {
                    new_p[k] = p[k];
                }
                new_p[size - 1] = temp;
                delete[] p;
                p = new_p;
            }
        }
        flag = false;
        temp = 1;
    }
    temp = 1;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    if (size > 0) {
        cout << endl;
        for (i = 0;i < size;i++) {
            cout << p[i] << "\t";
        }
        cout << endl;
        for (i = 0;i < size;i++) {
            temp = p[i];
            j = i - 1;
            while (j >= 0 && p[j] > temp) {
                p[j + 1] = p[j];
                j--;
            }
            p[j + 1] = temp;
        }           
        cout << endl;
        for (i = 0;i < size;i++) {
            cout << p[i] << "\t";
        }
        cout << endl;
    }
    else {
        cout << "No elements <0" << endl;
    }
    
    system("pause");
}

