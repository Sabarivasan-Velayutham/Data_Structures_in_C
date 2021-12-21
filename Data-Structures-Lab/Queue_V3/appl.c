// 3.	Insert queue with the following contents 
//       (J1,2), (J2,4), (J3,8), (J4,5), (J5,2), (J6,7), (J7,4), (J8,3) (J9,6) & (J10,6)
// 4.	Insert the job into the queue whichever is empty. If it is not empty, insert the job into the queue whichever is having minimum average time
// 5.	Display the jobs waiting in both the queues along with their CPU burst time.
//1,3,6,9,10
//2,4,5,7,8

#include "impl.h"
#include <stdlib.h>

int main (void)
{
    struct Queue *q1 = (struct Queue *) malloc(sizeof( struct Queue)) ;
    struct Queue *q2= (struct Queue *) malloc(sizeof( struct Queue)) ;
    init(q1, 5) ;
    init(q2, 5) ;
    struct Job j ; 

    int list[][2] = {{1,2},{2,4},{3,8},{4,5},{5,2},{6,7},{7,4},{8,3},{9,6},{10,6}} ; 

    for (int i=0;i<10;i++)
    {
        j.no = list[i][0] ;
        j.cputime = list[i][1] ;

        if (isEmpty(q1) || isEmpty(q2) )
        { 
            if (isEmpty(q1))
            {
                enqueue(q1, j) ; 
                q1 -> avg =  list[i][1] ;
            }
            else
            {
                enqueue(q2, j) ; 
                q2 -> avg = list[i][1] ;
            }
        }

        else
        {
            if (q1 -> avg <= q2 -> avg)
            {
                if (isFull(q1))
                {
                    enqueue(q2, j) ; 
                    q2 -> avg +=  list[i][1] ;
                }
                else
                {
                    enqueue(q1, j) ; 
                    q1 -> avg +=  list[i][1] ;
                }
            }

            else 
            {
                if (isFull(q2))
                {
                    enqueue(q1, j) ; 
                    q1 -> avg +=  list[i][1] ;
                }
                else
                {
                    enqueue(q2, j) ; 
                    q2 -> avg +=  list[i][1] ;
                }
            }
        }

    }

    printf("\nQueue 1 : ") ; 
    display(q1) ; 
    printf("\n======================================") ; 
    printf("\nQueue 2 : ") ;
    display(q2) ; 
}