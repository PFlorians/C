#include <stdio.h>
#include <stdlib.h>
//hlada MST, neorientovany graf O(|E|.log_2(|E|))->len ak porovnavaci sort pouzity predtym, neutriedeny O(|V|^2)
typedef struct edge
{
    int src, dst, w;
}EDGE;
typedef struct graph
{
    int v, e;
    EDGE *hrany;//mnozina hran vrcholy su indexy ale hrana je datovy typ
}GRAPH;
//vyzaduje comparacny triediacy alg.
int main()
{

    return 0;
}
