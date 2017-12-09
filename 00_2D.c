#include <stdio.h>

int str = 3,stb=3;
int ematrixp(int m[][3]){ //die Funktion prüft ob es eine Einheitsmatrix ist
                            
                          int i,j,r=1;   
                          if(str!=stb) r=0;
                          else{
                          for(i=0; i<str; i++){
                            for(j=0; j<stb; j++){
                                if((i==j) && (m[i][j]!=1)) r=0; 
                                    
                                else if((i!=j) && (m[i][j]!=0)) r=0;                                                                     
                            }}}
                         
                          return r;
                          
                         };
 
 
int main(){

 printf("\n");
 int m [3][3] = {{1,0,0},//unsere Matrix, die geprüft wird
                 {0,1,0},
                 {0,0,1}};
 printf("%d \n", ematrixp(m));//0-falls keine Einheitsmatrix, 1- falls Einheitsmatrix

    return 0;
}
