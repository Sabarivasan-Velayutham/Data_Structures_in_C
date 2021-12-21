struct numberADT
{
	int arr[100];
	int size;
};

void init(struct numberADT *N);
void sort(int arr[],int size);
void insertElements (struct numberADT *N, int x[]);
int lsearchElement(struct numberADT *N, int key);
int bsearchElement(struct numberADT *N, int key);
void display(struct numberADT *N);
int secondElement(struct numberADT *N, int key);
int frequency(struct numberADT *N,int key);
void isSame(struct numberADT *N1,struct numberADT *N2);
void difference(struct numberADT *N,int ans[10][2], int key,int *x);

