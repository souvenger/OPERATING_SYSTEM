// calculating e^x , x and n (no. of terms)
#include <stdio.h>
int main()
{
    int n;
    double x;
    scanf("%d", &n);
    scanf("%lf", &x);
    double sum = 1.00;
    double temp = 1;
    // e^x
    for (int i = 1; i <= n; i++)
    {
        temp = (temp * x * 1.00) / (i * 1.0);
        sum += temp;
    }
    printf("%.8lf\n", sum);
}