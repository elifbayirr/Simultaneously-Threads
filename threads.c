#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // for strlen func.
#include <unistd.h>
#include <pthread.h>   // for pthread_exit,pthread_create and pthread_join functions.

void show(const char *data){   // a code block for thread will begin control in this function
    int i = 0;
    for(i;i<5;i++){
    // write to STDOUT
    write(STDOUT_FILENO,data,strlen(data));
    sleep (lrand48()%3);
    }
}

void*A (void *arg)		
{
    show("A1");		// thread A has 3 code blocks a1,a2,a3
    show("A2");
    show("A3");
    
    pthread_exit (0);
}

void*B (void *arg)			
{
    show("B1");		// thread B has 4 code blocks b1,b2,b3,b4
    show("B2");
    show("B3");
    show("B4");
    
    pthread_exit (0);
}

void*C (void *arg)			// thread C has 3 code blocks c2,c2,c3
{				
    show("C1");
    show("C2");
    show("C3");
    
    pthread_exit (0);
}

int main (int argc, char*argv[])
{
    pthread_t thread_1,thread_2,thread_3;	 // threads identifiers	
    
    pthread_create (&thread_1, NULL, A , (void *)&thread_1);    // create the thread
    pthread_create (&thread_2, NULL, B , (void *)&thread_2);
    pthread_create (&thread_3, NULL, C , (void *)&thread_3);
    
    pthread_join (thread_1, (void**)&thread_1);     // wait for the thread to exit
    pthread_join (thread_2, (void**)&thread_2);
    pthread_join (thread_3, (void**)&thread_3);
    
    return 0;
}
