#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *mythread1(void *vargp);
void *mythread2(void *vargp);

int main(){

    pthread_t tid1, tid2;
    pthread_create(&tid1,NULL,mythread1,NULL);
    pthread_create(&tid2,NULL,mythread2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    exit(0);

}

void *mythread1(void *vargp)
{

    int i;
    printf("thread\n");

    for(int i=1;i<10;i++)
    {
        printf("i=%d\n",i);
    }
    printf("exit from the thread1\n");
    return NULL;
}

void *mythread2(void *vargp)
{

    int j;
    printf("thread\n");

    for(int j=1;j<10;j++)
    {
        printf("j=%d\n",j);
    }
    printf("exit from the thread2\n");
    return NULL;
}
