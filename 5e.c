#include "stdio.h"
#include "gripss.h"

int main() {
int a,x,l;
  char func[200];
            for(int k=0;k<=9;k++){  
			if(k%2==0){
                            plot("f(x)=2*a*x)/l",   -10, 10, -10, 10); 
                            }
			else{ 
                            plot("f(x)=2*a*(l-x)/l",-10, 10, -10, 10);  
                            
                            };}
  plot(func, -10, 10, -10, 10);
  return 0;
}