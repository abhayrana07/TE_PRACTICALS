#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    char input[256];
    char output[256];

    int fifo1=open("fifo1",O_RDONLY);
    int fifo2=open("fifo2",O_WRONLY);

    if(fifo1 == -1 || fifo2 == -1){
        perror("ERROE OPENING FIFOS");
        exit(1);
    }

    read(fifo1,input,sizeof(input));
    //count characters,word ,lines
    int char_count=0,word_count,line_count=0;
    for (int i=0;input[i]!='\0';i++){
        char_count++;
        if(input[i]==' ' ||input[i]=='\n') word_count++;
        if(input[i]=='\n')line_count++;
    }

    //prepare output using snprintf to format it in a string
    snprintf(output,sizeof(output),"Characters:%d\nWords:%d\nLines:%d\n",char_count,word_count,line_count);

    write(fifo2,output,strlen(output)+1);

    close(fifo1);
    close(fifo2);



    return 0;

}
