typedef struct
{
	long regno;
	char name[20];
	float mark1;
	float mark2;
	float mark3;
	float total;
	char result;
}student;

typedef struct
{
	student arr[100];
	int n;
}listADT;


void input(student *s);
void display(listADT l);
void initialise(listADT *l);

void insertFront(listADT *l,student s); //To insert a record in front of the list
void insertEnd(listADT *l,student s); //To insert a record at the end of the list
void insertRegNo(listADT *l, student s, int regNum); //To insert a record after a regno

listADT searchName(listADT l, char name[]); //To list the details of students based on name of the student
void Delete(listADT *l, int regNum); //To delete a record given a register number
void computeResult(listADT *l); //Calculate the Total and update the Result field about whether he / she is passed or not
student* listResult(listADT l); //List the students who have passed
int listClass(listADT l); //Returns the no of students who have scored first class marks
