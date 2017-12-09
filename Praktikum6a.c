#include <stdio.h>

int main()
{
 // zu sortierendes array
 char name[][10]={"Moritz","Max","Bolte","Hans","Huckebein","Helene","Antonius","Boeck","Maecke","Lempel"};
 int i,j,k; //hilfsvatiablen zum zählen
 printf("\n"); 
 printf("--------------------------------\n");
 printf("-----------SIMPELSORT-----------\n");
 printf("--------------------------------\n");
 printf("\n");
 printf("Vor dem Sortieren:\n");

 for(i=0;i<=9;i++)
  printf("%d: %s\n",i+1,name[i]);
 printf("\n");
 printf("\n");
 
 for(i=0;i<9;i++) 
   for(j=i+1;j<=9;j++)
   {
    for(k=0;name[i][k]==name[j][k]&&name[i][k];k++);
    if((name[i][k])>(name[j][k]))
      {
        char temp;
	for(k=0;k<=9;k++)
	{
	  temp=name[i][k];
	  name[i][k]=name[j][k];
	  name[j][k]=temp;
	}
      }
   }
//Ausgabe
  printf("Nach demm Sortieren:\n");
  for(i=0;i<=9;i++)
    printf("%d: %s\n",i+1,name[i]);
  printf("\n");
  printf("ENDE\n");
  return 0;
}