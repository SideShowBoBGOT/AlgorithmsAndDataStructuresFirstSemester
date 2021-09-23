#include<stdio.h>
#include<math.h>
int main()
{
    double number;
    printf("Enter 3digit integer: ");
    scanf_s("%lf", &number);
    double hundreds = floor(number/100);
    double dozens = floor(((number / 100 - hundreds) * 10));
    double ones = (((number / 100 - hundreds) * 10) - dozens) * 10;
    double average = (hundreds + dozens + ones) / 3;
    printf("Dozens: %lf\n", dozens);
    printf("Ones: %lf\n", ones);
    printf("Average: %lf\n", average);
    system("pause");
    return 0;
}


