#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */

float f(float x)
{
    return x * x * x + 2 * x - 1;
}

float secant(float x_current, float x_prev)
{
    return x_current - (x_current - x_prev) * f(x_current) / (f(x_current) - f(x_prev));
}

int main()
{
    float x0 = 1, x1 = 1.6, x_prev = x0, x_current = x1, x_next;
    float tolerance = 0.0001;
    int iteration = 0, max_iterations = 50;
    while (fabs(f(x_current)) > tolerance && iteration < max_iterations)
    {
        x_next = secant(x_current, x_prev);
        x_prev = x_current;
        x_current = x_next;
        iteration++;
        printf("Iteration %d: f(x_n+1)=%.6f, x_n+1=%.6f, x_n %.6f\n", iteration, fabs(f(x_current)), x_current, x_prev);
    }
    printf("\nRoot %.5f after %d iterations\n", x_current, iteration);
    return 0;
}