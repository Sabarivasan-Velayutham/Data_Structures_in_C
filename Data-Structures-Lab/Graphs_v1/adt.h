typedef struct city
{
    int adj[100][100];
    int vtx;
}city;

void create(city *c);
void dis(city *c);
void DFS(city *c,char x);
void BFS(city *c,char x);