// a b c d e f lan luot bang 1 2 3 4 5 6
#include <stdio.h>
#define V 5
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
}
void print(int a[][V])
{

    printf("\n");
    for (int i = 0; i < V; i++)
    {
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
    f = fopen("input_2.txt", "w");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }

    for (int i = 0; i < V; i++)
    {

        for (int j = 0; j < V; j++)
        {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
int main()
{

    int a[V][V];
    macDinh(a);
    canhDoThi(0, 1, a);
    canhDoThi(0, 2, a);
    canhDoThi(0, 4, a);
    canhDoThi(1, 3, a);
    canhDoThi(2, 1, a);
    canhDoThi(3, 4, a);
    canhDoThi(3, 2, a);
    canhDoThi(4, 0, a);
    canhDoThi(4, 3, a);
    ghiFile(a);
    print(a);
    return 0;
}
