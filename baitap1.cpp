// a b c d e f lan luot bang 1 2 3 4 5 6
#include <stdio.h>
#define V 6

void macDinh(int a[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            a[i][j] = 0;
        }
    }
}

void canhDoThi(int x, int y, int a[][V])
{
    a[x][y] = 1;
    a[y][x] = 1;
}
void print(int a[][V])
{
    // printf("0: ");
    // for (int i = 0; i < V; i++)
    // {
    //     printf("%d ", i);
    // }
    printf("\n");
    for (int i = 0; i < V; i++)
    {
        // printf("%d: ", i);
        for (int j = 0; j < V; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void ghiFile(int a[][V])
{
    FILE *f;
    f = fopen("input_1.txt", "w");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }
    // fprintf(f, "0: ");
    // for (int i = 0; i < V; i++)
    // {
    //     fprintf(f, "%d ", i);
    // }
    // fprintf(f, "\n");
    for (int i = 0; i < V; i++)
    {
        // fprintf(f, "%d: ", i);
        for (int j = 0; j < V; j++)
        {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
void docFile(int a[V][V])
{
    FILE *f;
    // int a[V + 1][V + 1];
    f = fopen("input_1.txt", "r");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            fscanf(f, "%d", &a[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
}
int main()
{

    int a[V][V];
    // macDinh(a);
    // canhDoThi(1, 2, a);
    // canhDoThi(1, 4, a);
    // canhDoThi(1, 5, a);
    // canhDoThi(2, 3, a);
    // canhDoThi(2, 5, a);
    // canhDoThi(2, 6, a);
    // canhDoThi(3, 4, a);
    // canhDoThi(3, 6, a);
    // canhDoThi(4, 5, a);
    // canhDoThi(5, 6, a);
    // ghiFile(a);
    docFile(a);
    print(a);
    return 0;
}