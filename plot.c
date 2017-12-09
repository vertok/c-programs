#include "stdio.h"
#include "gripss.h"

int main() {
  char func[200];
  int a=3,l=2;
 // plot("f(x) = -(2*3*x*(-1)^(x))/(2*abs(x))", -10, 10, -10, 10);
  plot("f(x) = -(2*3*(-1)^(x))/(2)", -10, 10, -10, 10);; 
  //printf("Bitte Funktion in der Form f(x) = x^2 + 4 * sin(x) angeben:\n");
  //scanf("%s",func);
  //plot(func, -10, 10, -10, 10);
  return 0;
}