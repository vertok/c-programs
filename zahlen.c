#include <stdio.h>
 
int* union_set(int* f1, int* l1, int* f2, int* l2, int* ds){
    int* p = ds;
    while((f1 != l1) && (f2 != l2)){
        if(*f1 < *f2)
            *p++ = *f1++;
        else {
            if(*f1 == *f2)
                ++f1;
            *p++ = *f2++;
        }
    }
 
    while(f1 != l1)
        *p++ = *f1++;
    while(f2 != l2)
        *p++ = *f2++;
    return p;
}
 
int main(void){
    int* p, *e;
    int  sa[] = { 1, 3, 4, 5, 8 };
    int  sb[] = { 0, 1, 2, 5, 6, 7, 8, 9 };
    int  sc[sizeof(sa)+sizeof(sb)];
 
    e = union_set(sa, sa + sizeof(sa)/sizeof(sa[0]), 
                  sb, sb + sizeof(sb)/sizeof(sb[0]), sc);
    for(p = &sc[0]; p != e; ++p)
        printf("%d ", *p);
        printf("\n");
    return 0;
}