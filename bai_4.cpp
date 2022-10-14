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
void docFile2(int a[V][V])
{
    int arr[V];
    FILE *f;
    f = fopen("input1_2.txt", "r");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }
    for (int i = 0; i < 20; i++)
    {
        int m, n;
        fscanf(f, "%d %d \n", &m, &n);
        a[m][n] = 1;
    }

    fclose(f);
}
void ghiFile(int a[][V])
{
    FILE *f;
    f = fopen("output1_2.txt", "w");
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
    fprintf(f, "Danh sach ke:\n");
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
    fprintf(f, "Bac cua dinh\n");
    for (int i = 0; i < V; i++)
    {
        int x = 0;
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                x++;
            }
        }
        fprintf(f, "Bac cua dinh %d la %d\n", i, x);
    }
}

int main()
{
    int a[V][V];
    macDinh(a);
    docFile2(a);
    ghiFile(a);
    return 0;
}