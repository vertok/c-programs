#include <stdio.h>
#include <stdlib.h>

typedef union tpoint{
		struct pair *pt1;
		struct st_elem *pt2;
		int pt3;
	     };	

struct pwt { 
		int t;
		union tpoint p;
	   };
struct pwt root;
struct pair {
		struct pwt car;
		struct pwt cdr;
	    };

int main(){
union tpoint UnionEl;
scanf("%d\n%d",&UnionEl.pt1);
//a.pt3=
//b=&a;
printf("%d\n",UnionEl.pt1);
return 0;
}
