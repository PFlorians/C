#include <stdio.h>
#include <stdlib.h>
#define INF 99999
#define V 5

void printMatrix(int param[][V], int p[][V])
{
    int i, j;
    printf("Vysledna matica\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(p[i][j]!=-1 && param[i][j]!=INF)
            {
                printf("(%d):%d ", p[i][j], param[i][j]);
            }
        }
        printf("\n");
    }
}
void predecessors(int graph[][V], int p[][V])
{
    //int p[V][V];
    int i, j;
    for(i=0;i<V;i++)
    {
        for (j=0;j<V;j++)
        {
            if(graph[i][j]!=0 && graph[i][j]!=INF)
            {
                p[i][j]=i;
            }
            else
            {
                p[i][j]=-1;
            }
        }
    }
    //return p;
}
void floydWarshall(int graph[][V])
{
    int i, j, k, dist[V][V];
    int p[V][V];
    predecessors(graph, p);

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];//dist(u,v) <- w(u, v)
        }
    }
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    printf("plati [%d][%d]->(%d) (%d, %d)\n", i, j, dist[i][j], dist[i][k], dist[k][j]);
                    dist[i][j]=dist[i][k]+dist[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
    printMatrix(dist, p);
}
int main()
{
    /*int graph[V][V]={{0, 3, INF, 5, INF, INF, INF, INF, INF},
                     {INF, 0, 2, INF, INF, INF, 1, INF, INF},
                     {INF, INF, 0, -1, INF, 10, INF, INF, INF},
                     {INF, INF, INF, 0, 9, INF, INF, INF, INF},
                     {INF, INF, INF, INF, 0, 2, INF, INF, INF},
                     {INF, INF, INF, INF, INF, 0, INF, INF, 1},
                     {INF, INF, INF, INF, INF, INF, 0, 8, INF},
                     {INF, INF, INF, INF, INF, INF, INF, INF, 0}};*/
    /*int graph[V][V] = {{0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };*/
    int graph[V][V]={{0, 5, INF, 2, INF},
                     {INF, 0, 2, INF, INF},
                     {3, INF, 0, INF, 7},
                     {INF, INF, 4, 0, 1},
                     {1, 3, INF, INF, 0}
                    };
        floydWarshall(graph);
    return 0;
}
