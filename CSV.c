#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
int n,i;
float x,y,z;
char line[256];
FILE *f=fopen("datei.csv", "r");
if (f == NULL)
{
    exit(1);
}
fscanf (f, "%s", line); 
int tok = strtok(line, ";");
while(i<=tok)
{
    
