//Copyright (c) 2022 user1687569
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[100] = "Thread_Test";

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if(res != 0)
    {
        perror("Create pthread failed.");
        exit(EXIT_FAILURE);
    }
    printf("Wait pthread to finish!\n");

    res = pthread_join(a_thread, &thread_result);
    if(res != 0)
    {
        perror("Wait pthread to finish failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("pthread has finished, return value is: %s\n", (char *)thread_result);
    printf("The value of message is: %s\n", message);
    exit(EXIT_SUCCESS);
}


void *thread_function(void *arg)
{
    printf("pthread is working, parameter is: %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "pthread has modified.");
    pthread_exit("pthread execution is done.\n");
}

