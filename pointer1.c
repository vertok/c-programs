#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
int *ptr;
  char *s1 = "Hallo, ";
  
	char *s2 = "Welt!";
        int *i;
        s1=malloc(strlen(s1)+strlen(s2));
	char *s3 = strcat(s1, s2);
        printf("%s\n",s3);
   return EXIT_SUCCESS;
}