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
void docFile2(int a[][V])
{
    FILE *f;
    f = fopen("input2_1.txt", "r");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }
    char arr[20];
    for (int i = 0; i < V; i++)
    {
        fgets(arr, 10, f);
        printf("%s", arr);
        int x[10];
        int r = 0;
        for (int j = 0; j < 9; j++)
        {

            if (arr[j] != '\t' && arr[j] != '\n' && arr[j] != ' ')
            {
                x[r] = arr[j] - '0';
                r++;
            }
        }
        for (int j = 1; j < r - 1; j++)
        {
            a[x[0]][x[j]] = 1;
        }
        printf("\n");
    }
    fclose(f);
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
    f = fopen("output2_1.txt", "w");
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
    fprintf(f, "\n");
    fprintf(f, "Danh sach canh: \n");
    fprintf(f, "Dau\tCuoi\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                fprintf(f, "%d\t%d\n", i, j);
            }
        }
    }
    fprintf(f, "Bac cua dinh: \n");
    for (int i = 0; i < V; i++)
    {
        int p = 0;
        for (int j = 0; j < V; j++)
        {
            if (a[i][j] == 1)
            {
                p++;
            }
        }
        fprintf(f, "Bac cua dinh %d la %d\n", i, p);
    }
    fclose(f);
}
int main()
{
    int a[V][V];
    macDinh(a);
    docFile2(a);
    ghiFile(a);
    print(a);
    return 0;
}