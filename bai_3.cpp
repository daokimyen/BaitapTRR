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
void docFile2()
{
    FILE *f;
    f = fopen("input1_1.txt", "r");
    if (f == NULL)
    {
        printf("loi file");
        return;
    }
    for (int i = 0; i < V; i++)
    {
        int c;
        while ((c = fgetc(f)) != '\n')
        {
            // int m, n;
            // fscanf(f, "%d %d \n", &m, &n);
            // a[m][n] = 1;
            printf("%d", c);
        }
        if (c = '\n')
        {
            continue;
        }
    }

    fclose(f);
}
int main()
{
    docFile2();
    return 0;
}