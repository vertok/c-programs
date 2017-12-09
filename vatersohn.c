#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 4

int main()
{
    int c, ret;
    pid_t pid[N];
    char *a[N]={"Yeah","asdf zu kurz","af ds","qas"};
    for(c=0; c<N; c++) {
        pid[c] = fork();
         if(pid[c]>0)
             printf("du wirst geboren um was schoenes zu tun!\n");
                    ret=wait(NULL);

        if(pid[c] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pid[c] == 0) {/*Sohn*/
            printf("PID des Sohnes %i= %i\n", c+1, getpid());
            return 0/*exit(EXIT_SUCCESS)*/;}
                            printf("%s\n",a[c]);

            

    }

    /*for(c=0; c<N; c++)  { 

        ret=wait(NULL);
                printf("\n%c",a[c]);

        if(ret == -1) {
            perror("wait");
        exit(EXIT_FAILURE);}
    }*/
    return 0;
   // exit(EXIT_SUCCESS);

}