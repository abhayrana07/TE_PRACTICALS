#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>

int main(){
    void *shared_memory;
    char buff[100];
    int shmid;
    key_t key;
    key = ftok("shmfile", 65);
    shmid=shmget(key,1024,0666);
    printf("KEY OF SHARED MEMORY IS:%d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process is attached at %p\n ",shared_memory);
    printf("Data read from shared Memory is : %s\n",(char*)shared_memory);
    return 0;

}