#include <stdio.h>
#include <math.h>
float Function(float x) {
     //use log() for log, log10() for ln, M_E for e,exp(x) for e^x.
    return x*x*x-4;
}
float regulaFalsiMethod(float a, float b, float tolerance, float (*func)(float)) {
    float m;
    printf("Iteration No.\t a\t b\t m=(a*(f(b)-b*f(a))/f(b)-f(a))\t f(m)\n");
    int iteration = 1;
    while ((b - a) >= tolerance) {
        m = (a * (*func)(b) - b * (*func)(a)) / ((*func)(b) - (*func)(a));
        float Result = (*func)(m);
        printf("%d\t\t %.4f\t %.4f\t %.4f\t\t\t\t %.4f\n", iteration, a, b, m, Result);
        if (Result == 0.0)
            break;
        if ((*func)(m) < 0)
            a = m;
        else
            b = m;
        iteration++;
    }
    return m;
}
int main() {
    float a, b, tolerance, root;
    printf("Enter the first interval (a, b):\n ");
    scanf("%f %f", &a, &b);
    printf("Enter the error tolerance: ");
    scanf("%f", &tolerance);
    root = regulaFalsiMethod(a, b, tolerance, Function);
    printf("Root: %.4f\n", root);
    return 0;
}
