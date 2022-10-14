// a b c d e f lan luot bang 0 1 2 3 4 5
#include <stdio.h>
#define V 5

void docFile(int a[V][V])
{
    FILE *f;
    f = fopen("input_2.txt", "r");
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
void dsKe(int a[][V])
{
    printf("Dinh\tList\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t", i);
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
void dsCanh(int a[][V])
{
    printf("Dau\tCuoi\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                printf("%d\t%d", i, j);
                printf("\n");
            }
        }
    }
}
void ghiFile1(int a[][V])
{
    FILE *f;
    f = fopen("input2_1.txt", "w");
    if (f == NULL)
    {
        printf("Loi file");
        return;
    }
    fprintf(f, "Dinh\tList\n");
    for (int i = 0; i < V; i++)
    {
        fprintf(f, "%d\t", i);
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                fprintf(f, "%d ", j);
            }
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
void ghiFile2(int a[][V])
{
    FILE *f;
    f = fopen("input2_2.txt", "w");
    if (f == NULL)
    {
        printf("Loi file");
        return;
    }
    fprintf(f, "Dau\tCuoi\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                fprintf(f, "%d\t%d", i, j);
                fprintf(f, "\n");
            }
        }
    }
    fclose(f);
}
int main()
{
    int a[V][V];
    docFile(a);
    dsKe(a);
    printf("\n");
    dsCanh(a);
    ghiFile1(a);
    ghiFile2(a);
    return 0;
}