/*********************************************************/
/*    File:         sort.c                               */
/*                                                       */
/*    Description:  This file contains source code for   */
/*                  a program written in C which sorts   */
/*                  text files.  It is a demonstration   */
/*                  of LISP-like list procedures.        */
/*                                                       */
/*    Version Date     History                           */
/*    1.00    14SEP88  Original                          */
/*********************************************************/
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
/*********************************************************/
/*    typedefs                                           */
/*********************************************************/
 
typedef void   *POINTER;      /* General purpose pointer */
 
typedef struct                /* A CONS is two pointers  */
   {
   POINTER  car;
   POINTER  cdr;
   } CONS;
typedef CONS    *LIST;        /* A LIST is a pointer to  */
                              /* a CONS                  */
 
 
/*********************************************************/
/*    return codes at the program level                  */
/*********************************************************/
 
#define  RET_NORMAL  0  /* Normal return code            */
#define  RET_IOERR   2  /* I/O Error                     */
#define  RET_MEMERR  3  /* Memory allocation error       */
 
/*********************************************************/
/*    Manifest Constants                                 */
/*********************************************************/
 
#define  LINESIZE 500   /* size of local buffer          */
                        /* lines larger then this will   */
                        /* read as multiple lines        */
 
 
/*********************************************************/
/*    Prototypes                                         */
/*********************************************************/
 
LIST     reverse(LIST  lst);
LIST     merge(LIST lst1,LIST lst2,int (*compare)());
LIST     sort(LIST lst,int (*compare)());
CONS     *cons(POINTER a,POINTER b);
LIST     cpush(CONS *z,LIST *lst);
LIST     push(POINTER item,LIST *lst);
CONS     *cpop(POINTER *lst);
POINTER  pop(POINTER  *lst);
LIST     outputlist(LIST lst,FILE *stream);
int      string_compare(char *a,char *b);
char     *getaline(FILE *stream);
 
 
/*********************************************************/
/*    main     sort program                              */
/*                                                       */
/*    Reads lines of text from stdin, sorts them, and    */
/*    outputs the result to stdout.                      */
/*********************************************************/
int main(void)
{
 
   LIST mylist=NULL;       /* List of text records as    */
                           /* read from stdin            */
 
   char  *lp;              /* pointer to duplicate string*/
 
   while  ( (lp = getaline(stdin)) != NULL )
      push(lp,&mylist);
   outputlist(sort(mylist,string_compare),stdout);
 
   return RET_NORMAL;
}
 
 
/*********************************************************/
/*    getaline         get a line of text                */
/*                                                       */
/*    Returns a pointer to a line of text read from      */
/*    stream.  Returns NULL if end of file.  Exits       */
/*    on error.                                          */
/*********************************************************/
char *getaline(FILE *stream)
{
   char  line[LINESIZE];   /* input buffer               */
   char  *lp;              /* points to strdup buffer    */
 
   if (fgets(line,LINESIZE,stream) != NULL)
      {
      if ( (lp = strdup(line)) != NULL)
         return lp;        /* normal return              */
      else
         exit(RET_MEMERR); /* strdup could not malloc    */
      }
   else
      {
      if (feof(stream))
         return NULL;      /* end of file                */
      else
         exit(RET_IOERR);  /* I/O error in fgets         */
      }
}
 
/*********************************************************/
/*    string_compare    compares strings                 */
/*                                                       */
/*    Returns TRUE value if string a is ordered after    */
/*    string b. Returns  FASE if string a is equal to    */
/*    or ordered before string b.                        */
/*********************************************************/
int string_compare(char *a,char *b)
{
   return strcmp(a,b) > 0;
}
 
/*********************************************************/
/*    push          push an item onto a list             */
/*                                                       */
/*    Uses cons to create a CONS and sets its car cell   */
/*    to item.  Its cdr is set to *lst.  *lst is set to  */
/*    point to the CONS created.  A pointer to the CONS  */
/*    is also returned.                                  */
/*********************************************************/
LIST push(POINTER item,LIST *lst)
{
   return *lst = cons(item,*lst);
}
 
/*********************************************************/
/*    cons          create a CONS                        */
/*                                                       */
/*    Uses malloc to allocate a CONS and set its         */
/*    car cell to a and its cdr cell to b.  Exits if     */
/*    malloc fails!                                      */
/*********************************************************/
CONS *cons(POINTER a,POINTER b)
{
   CONS  *z;
   z = (CONS *) malloc(sizeof(CONS));
   if (z == NULL) exit(RET_MEMERR);
   z->car = a;
   z->cdr = b;
   return z;
}  
 
 
/*********************************************************/
/*    pop         pop an item off a list                 */
/*                                                       */
/*    Uses cpop to pop a CONS off lst.  Return NULL      */
/*    if lst is empty.  free the CONS and return the     */
/*    car cell of the CONS.                              */
/*********************************************************/
POINTER  pop(LIST  *lst)
{
   POINTER  item;
   CONS     *z;
 
   z = cpop(lst);
   if(z == NULL) return NULL; /* list is empty           */
 
   item = z->car;             /* get what cons pointed to*/
 
   free(z);                   /* release the cons        */
 
   return item;
}
 
/*********************************************************/
/*    cpop         pop a CONS off a list                 */
/*                                                       */
/*    if *lst is empty return NULL, else set *lst to the */
/*    the car cell of the first CONS on *lst and return  */
/*    a pointer to the first CONS on *lst.               */
/*********************************************************/
CONS    *cpop(LIST *lst)
{
   LIST  rvalue;
   rvalue = *lst;
   if (rvalue != NULL)
      *lst = rvalue->cdr;
   return rvalue;
}
 
/*********************************************************/
/*    outputlist   output each item in a list            */
/*                                                       */
/*    start with the first item in the list, output it   */
/*    to stream assuming it is a string, repeat for each */
/*    item in the list.  Return lst.                     */
/*********************************************************/
LIST outputlist(LIST lst,FILE *stream)
{
   CONS *acons;
   LIST  l=lst;
 
   while ( acons=cpop(l) != NULL )
      fputs( (char *) acons->car,stream);
   return lst;
}
 
 
/*********************************************************/
/*    cpush      cons push                               */
/*                                                       */
/*    Adds a CONS to the head of a list                  */
/*    modify the cdr cell of *z to point to *lst.  set   */
/*    *lst to point to the CONS z and return a pointer   */
/*    to the CONS.                                       */
/*********************************************************/
LIST cpush(CONS *z,LIST *lst)
{
   z->cdr = *lst;
   return *lst = z;
}
 
/*********************************************************/
/*    reverse      reverse a list                        */
/*                                                       */
/*    distructively modify the cdr cells of the CONS     */
/*    which make up lst so that a new list is created    */
/*    which is the reverse of the original list.         */
/*    return the new list.                               */
/*********************************************************/
LIST  reverse(LIST  lst)
{
   LIST  rlst=NULL;
 
   while (lst != NULL) cpush(cpop(&lst),&rlst);
   return rlst;
}
 
/*********************************************************/
/*    split      split a list in half                    */
/*                                                       */
/*    Find the mid CONS in lst.  set its cdr cell to     */
/*    NULL.  return the remainder of lst, i.e. a pointer */
/*    to the next CONS after the mid CONS.               */
/*********************************************************/
LIST split(LIST lst)
{
   LIST tail=lst->cdr;
 
   if ( (lst == NULL) || (tail == NULL) )
      return lst;
 
   while( (tail != NULL) && ( (tail=tail->cdr) != NULL) )
      {
        lst = lst->cdr;
        tail = tail->cdr;
      }
   tail = lst->cdr;
   lst->cdr=NULL;
   return tail;
}
 
/*********************************************************/
/*    sort        sort a list                            */
/*                                                       */
/*    If cmp is a two argument ordering procedure,       */
/*    sort the items in lst based on cmp and             */
/*    return the results                                 */
/*********************************************************/
LIST  sort( LIST lst,int (*cmp)())
{
   LIST lst2;
 
   if ((lst == NULL) || (lst->cdr == NULL)) return lst;
 
   lst2 = split(lst);
   return merge(sort(lst,cmp),sort(lst2,cmp),cmp);
}
 
 
/*********************************************************/
/*    merge        merge two lists                       */
/*                                                       */
/*    If cmp is a two argument ordering procedure,       */
/*    merge the items in l1 and l2 based on cmp and      */
/*    return the results                                 */
/*********************************************************/
LIST  merge(LIST l1,LIST l2,int (*cmp)())
{
   LIST  rlst=NULL;
 
   while ( (l1 != NULL) && (l2 != NULL) )
      cpush((cmp(l2->car,l1->car) ? cpop(&l1) : cpop(&l2)), &rlst);
 
   while ( l1 != NULL ) cpush(cpop(&l1),&rlst);
   while ( l2 != NULL ) cpush(cpop(&l2),&rlst);
 
   return reverse(rlst);
}