// hier sollten Sie am Anfang die Anzahl von Reihen und Spalten eingeben und dann die Elementen von Matrix Stück für Stück eingeben.
#include <stdio.h>

 int main(){

    int str = 0,stb=0, i=0, j=0;
    int matrix[5][5];
    int einheitsmatrix(int m, int s1, int s2){ //prüft ob eine Einheitsmatrix ist
                             int k,i,j;        // die funktionier nicht korrekt!
                            if(s1!=s2) k=1;
                            for(i=0; i<s1; i++){
                            for(j=0; j<s2; j++){
                                if(i==j && m!=1) k=2;
                                    
                                else if(i!=j && m!=0) k=3;                                                                     
                            }}
                         
                          return(k);
                          
                         };
 
    void eingabematrix(int m){       //Fuktion zur Eingabe   
                            //int i,j;    
                            scanf("%d", &matrix[i][j]);  
                                };
    int xBuf=0; //die Variable nutzen wir um zu erkennen, ob eine Matrix die Einheitsmatrix ist oder nicht

    printf("Reihe  *muss <=5 sein*: ");
    scanf("%d",&str);
    printf("Spalte *muss <=5 sein*: ");
    scanf("%d",&stb);
    //if(str!=stb) xBuf=1;//printf("Das ist keine Einheitsmatrix!\n"); //da in Eiheitsmatrix die Anzahl von Spalten ist Gleich die Anzahl von Reihen

    
//else{



                        
                        
    for(i=0; i<str; i++){
        for(j=0; j<stb; j++){
                            printf("Geben Sie bitte [%d][%d] Element von Matrix:\n",i,j);
                            eingabematrix(matrix[i][j]);
                            int x=einheitsmatrix(matrix[str][stb],str,stb);
switch(x) {
    case 0:
            { printf("Das ist eine Einheitsmatrix!\n");}
    break;
    case 1:
            { printf("Die Anzahl von Spalten ist ungleich die Anzahl von Reihen\n");}
    break;
    case 2:
            { printf("Die Elemente der Hauptdiagonale sind verschieden von 1\n");}
    break;
    case 3:
            { printf("Die Elemente der Matrix, die nicht auf der Hauptdiagonale liegen, sind verschieden von 0\n");}
    break;
}           // if(i==j) einheitsmatrix(matrix[i][j]);
                           // if(i!=j) einheitsmatrix(matrix[i][j]);
            

            
            //if(i==j){
                   //      if (matrix[i][j]!=1) xBuf=2; //in Einheitsmatrix die Elemente auf der Diagonale sind gleich 1
                   //     }
               // else{ if(matrix[i][j]!=0) xBuf=3;}; //und die andere Elemente müssen 0 sein, am sonst das ist keine Einheitsmatrix
        }
    }
   printf("\n");
    for(i=0;i<str;i++){ //App gibt die gegebene Matrix zurück
         for(j=0;j<stb;j++){
           // printf(" Matrix[%d][%d]:  %d\n", i, j, matrix[i][j]);
                printf("%d ",matrix[i][j]);
    }
printf("\n");

}
 printf("\n");
int x=einheitsmatrix(matrix[str][stb],str,stb);
switch(x) {
    case 0:
            { printf("Das ist eine Einheitsmatrix!\n");}
    break;
    case 1:
            { printf("Die Anzahl von Spalten ist ungleich die Anzahl von Reihen\n");}
    break;
    case 2:
            { printf("Die Elemente der Hauptdiagonale sind verschieden von 1\n");}
    break;
    case 3:
            { printf("Die Elemente der Matrix, die nicht auf der Hauptdiagonale liegen, sind verschieden von 0\n");}
    break;
        
 //       printf("Das ist keine Einheitsmatrix!\n"); // falls Anzahl von Spalten= Anzahl von Reihen,
 //      else printf("Das ist eine Einheitsmatrix!\n"); // dann prüfen wir die Elemente von Matrix
}

    return 0;
}