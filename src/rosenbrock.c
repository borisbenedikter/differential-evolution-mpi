#include "rosenbrock.h"

double rosenbrock(double *x, const int N) {
    // // Number of variables
    // int N = (int)(sizeof(x) / sizeof(x[0]));

    // printf("%d \n", N);

    // Initialization
    int i = 1;
    double F = 0;

    // Loop
    while (i <= N / 2)
    {
        // Function evaluation
        double F_temp = 100. * pow(pow(x[2 * i - 2], 2) - x[2 * i - 1], 2)
            + pow(x[2 * i - 2] - 1, 2);


        // Sum
        F += F_temp;

        // Update counter
        i++;
    }
    return F;
}