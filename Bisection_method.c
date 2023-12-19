#include <stdio.h>
#include<math.h>
float Function(float x){
    //use log() for log, log10() for ln, M_E for e,exp(x) for e^x.
    return  x*x*x+4*x*x-10;
}
float bisectionMethod(float a, float b, float tolerance, float (*func)(float)){
    float mid;
    printf("Iteration No.\t a\t b\t c=(a+b)/2\t f(c)\n");
    int iteration = 1;
    while ((b - a) >= tolerance){
        mid = (a + b) / 2;
        float Result = (*func)(mid);
        printf("%d\t\t %.4f\t %.4f\t %.4f\t\t %.4f\n", iteration, a, b, mid, Result);
        if (Result == 0.0)
            break;
        if ((*func)(mid) < 0)
            a = mid;
        else
            b = mid;
        iteration++;
    }
    return mid;
}
int main(){
    float a, b, tolerance, root;
    printf("Enter the first interval (a, b):\n ");
    scanf("%f %f", &a, &b);
    printf("Enter the error tolerance: ");
    scanf("%f", &tolerance);
    root = bisectionMethod(a, b, tolerance, Function);
    printf("Root: %.4f\n", root);
    return 0;
}
