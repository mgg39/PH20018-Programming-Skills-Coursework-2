#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

typedef struct particle
{
    //initialized to empty type 0
    int type;

} particle;

//initializes all location in the array to an empty spot
void InitializeArray(particle** arr_particle, int lx, int ly)
{
    for (int x = 0; x < lx; x++)
    {
        for (int y = 0; y < ly; y++)
        {
            arr_particle[x][y].type = 0;
        }
    }
}

//inputs particles into our grid
void InputRandomCoordinates(particle** arr_particle, int lx, int ly, int N)
{
    int numb_part = 0;

    while (numb_part < N)
    {
        int xp = (rand() % lx);
        int yp = (rand() % ly);

        //fills in empty slots -> this ensures there is no 2 part in the same spot as it will skip occupied spots
        if (arr_particle[xp][yp].type == 0)
        {

            arr_particle[xp][yp].type = 1;
            numb_part++;
        }
    }
}

void PrintGrid(particle** arr_particle, int lx, int ly)
{
    for (int y = 0; y < ly; y++)
    {
        printf("\n");

        for (int x = 0; x < lx; x++)
        {
            if (arr_particle[x][y].type != 0)
            {
                
                    printf(" X"); 

            }
            else { printf(" ."); }
        }
    }
}

int main()
{
    int lx, ly, N, n_grids, fraction;

    printf("Enter number of rows (Ly): ");
    scanf("%d", &ly);

    printf("Enter number of columns (Lx): ");
    scanf("%d", &lx);

    printf("Enter number of particles randomly distributed through the grid (N): ");
    scanf("%d", &N);

    printf("Enter how many grids you would like to print: ");
    scanf("%d", &n_grids);

    srand(time(NULL) + lx);

    for (int i = 0; i < n_grids; i++)
    {
        printf("\n");

        if (ly * lx <= N)
        {
            printf("Too many particles for this grid size.");
            exit(-1);
        }

        particle** arr_particle;
        arr_particle = malloc(lx * sizeof(*arr_particle));
        for (int arr = 0; arr < lx; arr++)
        {
            arr_particle[arr] = malloc(ly * sizeof(particle));
        }

        InitializeArray(arr_particle, lx, ly);

        InputRandomCoordinates(arr_particle, lx, ly, N);

        PrintGrid(arr_particle, lx, ly);

        for (int i = 0; i < lx; i++)
        {
            free(arr_particle[i]);
        }
        free(arr_particle);

        printf("\n");
    }
    return 0;
}