#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>


int main(){
    char input[256];
    char output[256];

    int fifo1 = open("fifo1",O_WRONLY);
    int fifo2 = open("fifo2",O_RDONLY);

    if(fifo1 == -1  || fifo2 == -1){
        perror("ERROR OPENING FIFOS");
        exit(1);
    }

    printf("ENTER MSG:");
   scanf("%255[^\n]",input);

   //write input to fifo1
   write(fifo1,input,strlen(input)+1); //null character determination 
                                      //easy for reciver to know end of string
    
    read(fifo2,output,sizeof(output));
    printf("PROCESSED OUTPUT FRO PROCESS2: \n%s\n",output);

    close(fifo1);
    close(fifo2);

    return 0;

}