typedef struct city
{
    int adj[100][100];
    int vtx;
}city;

void create(city *c);
void dis(city *c);
void DFS(city *c,char x);
qll *BFS(city *c,char x);