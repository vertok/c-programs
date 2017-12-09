#include <stdio.h>
 //Spalten, Reihen, ich nutze hier die globale Variablen 
int ematrixp(int m[3][3]){ //die Funktion prüft ob es eine Einheitsmatrix ist
                          int str = 3,stb=3;
                          int i,j,r=1;        // aber sie arbeitet nicht korrekt! 
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
                 {1,1,0},
                 {0,0,1}};
 printf("%d \n", ematrixp(m));//0-falls keine Einheitsmatrix, 1- falls Einheitsmatrix

    return 0;
}