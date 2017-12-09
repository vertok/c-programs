#include <stdio.h>
 
 int main(){
 
    int str = 0,stb=0, i=0, j=0;
 
    printf("STRINGS: ");
    scanf("%d",&str);
    printf("STOLBEZ: ");
    scanf("%d",&stb);
 
    int s[str][stb];
 
    for(i=0; i<str; i++){
        for(j=0; j<stb; j++){
            printf("\nENTER S[%d][%d]: ", i, j);
            scanf("%d", &(s[i][j]));
        }
    }
    
    for(i=0;i<str;i++){
        for(j=0;j<stb;j++){
            printf(" S[%d][%d]:  %d\n", i, j, s[i][j]);
    }
}
 
     return 0;
}