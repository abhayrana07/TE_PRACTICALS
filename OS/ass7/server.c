#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>

int main(){
    void * shared_memory;
    char buff[100];
    int shmid;
    key_t key;

    key = ftok("shmfile", 65);
    shmid=shmget(key,1024,0666|IPC_CREAT);
    printf("KEY OF SHARED MEMORY IS:%d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process is attached at %p \n",shared_memory);
    
    printf("ENTER YOUR MESSAGE: ");
    fflush(stdout);  // Ensures the prompt is printed before user input


    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("You wrote:%s\n",(char*)shared_memory);
    return 0;
}