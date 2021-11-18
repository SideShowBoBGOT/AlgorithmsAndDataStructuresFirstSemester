#include <iostream>
using namespace std;
int main()
{
    char arr1[10];
    char arr2[10];
    char arr3[10];
    int sum = 0, count = 0;
    for (int i = 0;i < 10;i++) {
        arr1[i] = char(35 + 3 * i);
        arr2[i] = char(56 - 2 * i);
    }
    for (int i = 0;i < 10;i++) {
        for (int k = 0;k < 10;k++) {
            if (35 + 3 * i == 56 - 2 * k) {
                arr3[i] = char(35 + 3 * i);
            }
        }
    }
    for (int i = 0;i < 10;i++) {
        if (int(arr3[i]) > 38) {
            sum += int(arr3[i]);
            count++;
        }
    }
    
    double average = sum / count;
    cout << "Average sum of codes > 38: " << average << endl;
    system("pause");
}


