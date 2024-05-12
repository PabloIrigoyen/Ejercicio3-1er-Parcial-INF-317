#include "stdio.h"
#include "omp.h"

float mul(float a, float b) {
    float res = 0;
    #pragma omp parallel for reduction(+:res)
    for (int i = 0; i < b; i++) {
        res += a;
    }
    return res;
}

float div(float a, float b) {
    float res = 0;
    while (a >= b) {
        #pragma omp parallel
        {
            #pragma omp critical
            {
                a -= b;
                res++;
            }
        }
    }
    return res;
}
int main() {
    float n1, n2;
    printf("Ingrese el primer número: ");
    scanf("%f", &n1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &n2);
    
    printf("Multiplicación: %.2f\n", mul(n1, n2));
    printf("División: %.2f\n", div(n1, n2));

    return 0;
}
