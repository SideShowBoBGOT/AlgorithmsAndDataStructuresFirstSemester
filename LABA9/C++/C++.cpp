#include <iostream>
using namespace std;
int enter_n();
void show_2d_arr(int**matrix, int n);
int** fill_arr(int** matrix, int n);
double diag_avg(int** matrix, int const n);
int** gen_2d_arr(int n);
int** make_null(int** matrix, int const n, double avg);
int main()
{
    srand(time(NULL));
    int n = enter_n();
    int** matrix = gen_2d_arr(n);
    matrix = fill_arr(matrix, n);
    cout << "Initial matrix" << endl<<endl;
    show_2d_arr(matrix, n);
    double avg = diag_avg(matrix, n);
    matrix = make_null(matrix, n, avg);
    cout <<endl<< "Final matrix" << endl<<endl;
    show_2d_arr(matrix, n);
    cout <<endl<<"Avg: " <<avg << endl << endl;
    system("pause");
}
int enter_n() {
    int n = 0;
    while (n <= 0) {
        printf("Enter n: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            printf("n e N");
        }
    }
    return n;
}
int** gen_2d_arr(int n) {
    int** matrix =new int*[n];
    for (int i = 0;i < n;i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}
int** fill_arr(int** matrix, int n) {
    for (int j = 0;j < n;j++) {
        for (int i = 0;i < n;i++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}
void show_2d_arr(int** matrix, int n) {
    for (int i = 0;i < n;i++) {
        int* one_d_arr = matrix[i];
        for (int j = 0;j < n;j++) {
            printf("%d\t", one_d_arr[j]);
        }
        printf("\n");
    }
}
double diag_avg(int** matrix, int const n) {
    int *diag_els = new int[n];
    int i = 0;
    for (int j = n-1, k=0; j >=0; j--, k++)
    {
        if (i == 0) {
            while (i < n) {
                if (i == n - j - 1) {
                    diag_els[k] = matrix[i][j];
                }
                i++;
            }
        }
        else {
            i--;
            while (i >= 0) {
                if (i == n - j - 1) {
                    diag_els[k] = matrix[i][j];
                }
                i--;
            }
            i++;
        }
    }
    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl << diag_els[i] << "\t";
        avg += diag_els[i];
    }
    return avg /= n;
}
int** make_null(int** matrix, int const n, double avg) {
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0) {
            while (i < n) {
                if (i < j) {
                    if (matrix[i][j] < avg) {
                        matrix[i][j] = 0;
                    }
                }
                i++;
            }
        }
        else {
            i--;
            while (i >= 0) {
                if (i < j) {
                    if (matrix[i][j] < avg) {
                        matrix[i][j] = 0;
                    }
                }
                i--;
            }
            i++;
        }
    }
    return matrix;
}

