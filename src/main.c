#include "main.h"

int main(int argc, char const *argv[])
{
    // Check initialization
    // int initialized, finalized;
    // MPI_Initialized(&initialized);

    // Initialize the MPI environment
    // if (!initialized) 
    MPI_Init(NULL, NULL);

    // Find out rank, size
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n_proc;
    MPI_Comm_size(MPI_COMM_WORLD, &n_proc);

    // Problem dimension
    const int N = 100;

    double lb[N];
    double ub[N];

    
    for(int i = 0; i < N; i++)
    {
        lb[i] = -10.;
        ub[i] = +10.;
    }
    
    int n_iter = 1000;
    int np = 5000;
    double JRelTol = 1e-6;
    double JAbsTol = 1e-6;

    double x_best[N];
    double J_overall;

    my_differential_evolution_MPI(rosenbrock, lb, ub, N, n_iter, np, JRelTol, JAbsTol,
        rank, n_proc,
        x_best, &J_overall);

    MPI_Finalize();
    return 0;
}
