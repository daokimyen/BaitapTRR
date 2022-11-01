#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#define MAX 100
#define V 8

using namespace std;
int a[MAX][MAX];

using namespace std;
int chuaxet[MAX];

void docFile(int a[MAX][MAX])
{
    FILE *f;
    f = fopen("input_g2.txt", "r");
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

void Khoi_tao_chuaxet()
{
    for (int i = 0; i < MAX; i++)
    {
        chuaxet[i] = 1;
    }
}

void DFS(int u)
{
    chuaxet[u] = 0;
    cout << u << "->";
    for (int v = 0; v < V; v++)
    {
        if (chuaxet[v] == 1 && a[u][v] == 1)
        {
            DFS(v);
        }
    }
}

void BFS(int u)
{
    // int queue[MAX], dau = 0, cuoi = 0;
    // for (int i = 0; i < MAX; i++)
    //     queue[cuoi] = u;
    // chuaxet[u] = 0;
    // cout << u << "->";

    // while (dau >= cuoi)
    // {
    //     int p = queue[cuoi];
    //     for (int v = 0; v < V; v++)
    //     {
    //         if (chuaxet[v] == 1 && a[p][v] == 1)
    //         {
    //             dau++;
    //             queue[dau] = v;
    //             chuaxet[v] = 0;
    //             cout << v << "->";
    //         }
    //     }
    // }
    vector<int> queue;
    queue.push_back(u);
    chuaxet[u] = 0;
    cout << u << "->";
    while (queue.empty() == false)
    {
        int p = queue.front();
        // int x = queue.pop_back(0);
        for (int v = 0; v < queue.size(); v++)
        {
            if (chuaxet[v] == 1 && a[p][v] == 1)
            {
                queue.push_back(v);
                chuaxet[v] = 0;
                cout << v << "->";
            }
        }
    }
}
int KT_ChuaXet()
{
    for (int i = 0; i < V; i++)
    {
        if (chuaxet[i] == 1)
            return i;
    }
    return -1;
}
// Dem so thanh phan lien thong

int DemSLT()
{
    int slt = 0;
    Khoi_tao_chuaxet();
    while (KT_ChuaXet() != -1)
    {
        int i = KT_ChuaXet();
        DFS(i);
        slt++;
    }
    cout << "\n So lien thong: " << slt;
    return slt;
}

// tim bac cac dinh
int Deg(int i)
{
    int deg = 0;
    for (int j = 0; j < V; j++)
    {
        deg += a[i][j];
    }
    return deg;
}

// Kiem tra do thi Euler

void Test_Euler()
{
    if (DemSLT() == 1)
    {
        // tim bac cua do thi
        int soDinhLe = 0;
        for (int i = 0; i < V; i++)
            if (Deg(i) % 2 != 0)
                soDinhLe++;
        if (soDinhLe == 0)
            cout << "\n Do thi la Euler";
        else if (soDinhLe == 2)
            cout << "\n Do thi la nua Euler";
        else
            cout << "\n Do thi khong phai Euler";
    }
    else
        cout << "\n Do thi khong la Euler";
}

// ham chinh

int main()
{
    // doc ma tran
    docFile(a);
    // Duyet do thi DFS
    Khoi_tao_chuaxet();
    cout << "\n Duyet do thi DFS: ";
    DFS(0);
    // Duyet do thi BFS
    // Khoi_tao_chuaxet();
    // cout << "\n Duyet do thi BFS: ";
    // BFS(0);

    // Dem so lien thong
    // DemSLT();

    // // Kiem tra Euler
    Test_Euler();
    return 0;
}