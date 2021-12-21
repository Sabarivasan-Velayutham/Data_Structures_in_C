struct graph
{
 int no;
 int D[10][10];
 int P[10][10];
};

void init(struct graph * G,int n);
void DistanceMatrix(struct graph * G,int start,int end,int cost);
void FloydWarshall(struct graph *G);
void printPath(struct graph * G,int source,int desti);
void Print(struct graph * G);