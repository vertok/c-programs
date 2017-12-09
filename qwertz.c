#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int count=0;
typedef struct phonebook // Strukturtyp
{
  char name[28+1]; //Strukturkomponenten
  char vorname[28+1];
  char nummer[28+1];
}book;
char vbuf[128];
void putHuman(book* p)
{ 
  printf("%-28s %-28s       %-28s\n",p->name,p->vorname,p->nummer); 
}
//здесь разрешено вводить в имя,фамилию буквы, независимо от большая или маленькая, и дефис(для многосоожных фамилий,имен)
//                     в номер - только цифры(  а так же как первый символ может быть введен "+")
book getHuman(){ // функция ввода человека
  book p;
  int k=0,n=0;
  printf("Фамилия            :"); fgets(p.name,28,stdin);p.name[strlen(p.name)-1]=0; //удаление знака перехода на др. строку в конце
                                if(p.name[0]>=97 && p.name[0]<=122) p.name[0]-=32; //если первая буква маленькая->станет большой
                                for(k=0;k<=strlen(p.name)-1;k++){
                                        if(k!=0 && p.name[k]>=65 && p.name[k]<=90) p.name[k]+=32; //если другие буквы в фамилии большие- становятся маленьки
                                        if((p.name[k]>=33 && p.name[k]<=44) || (p.name[k]>=46 && p.name[k]<=64) || (p.name[k]>=91 && p.name[k]<=96) || (p.name[k]>=123 && p.name[k]<=127))  //проверка, чтобы исключить ввод отличных от букв и тире символов
                                                p.name[k]=1;} // если не буква то делаем из нее пустое место
  printf("Имя                     :");  fgets(p.vorname,28,stdin);p.vorname[strlen(p.vorname)-1]=0;
                                if(p.vorname[0]>=97 && p.vorname[0]<=122) p.vorname[0]-=32;
                                for(k=0;k<=strlen(p.vorname)-1;k++){
                                        if(k!=0 && p.vorname[k]>=65 && p.vorname[k]<=90) p.vorname[k]+=32;
                                        if((p.vorname[k]>=33 && p.vorname[k]<=44) || (p.vorname[k]>=46 && p.vorname[k]<=64) || (p.vorname[k]>=91 && p.vorname[k]<=96) || (p.vorname[k]>=123 && p.vorname[k]<=127))
                                                p.vorname[k]=1;}
  printf("Номер телефона  :"); fgets(p.nummer,28,stdin);p.nummer[strlen(p.nummer)-1]=0;  //с номером тоже идет серия проверок на корректность
                                if (!( p.nummer[0]=='+' || (p.nummer[0] > 47 && p.nummer[0] < 58))) p.nummer[0]=1; // дозволено начинать номер с + или с цифры соответственно
                                for(k=1;k<=strlen(p.nummer)-1;k++){
                                        if(p.nummer[k] <= 47 || p.nummer[k] >= 58) /*и дальше проверяем оставшиеся цифры на то, цифра ли это. и если нет, то номер обрезается до первого неправильного символа ( хотелось бы, чтобы номер остался полностью, без неправильных символов и пробелов, но пока никак, т.к. дальше последует еще поиск по номеру телефона, и если тут чтото изменить, то номер отчего-то не будет отыскиваться)*/
                                                p.nummer[k]=0;} /* собственно тут мы игнорируем все символы за исключением  [0-9]*/
  return p;
}

void sortier(book* a, int c){  //алгоритм сортировки по алфавиту(по фамилии), который сразу после ввода нового элемента структуры будет запускаться     
	book* tmp; //временный элемент структуры "телефонная книга", нужен для сортировки
     int n,m;

for(n=1;n<count;n++)
for(m=0;m<count-n;m++)
{
  int  code=strcmp(a[m+1].name,a[m].name);//собственно дальше идет сама сортировка через strcmp           
 if(code<0)
            {
                tmp=malloc(sizeof(book)); //выделяем память под тмп 
                if(tmp!=NULL){            
		*tmp=a[m];
                a[m]=a[m+1];
                a[m+1]=*tmp;
		free(tmp);} 
                else printf("\nError!"); //если память вдруг не выделена под тмп, выдает здесь ошибку
	    }
            }
}
int main()
{
  book* person;  
  person=malloc(sizeof (book));//выделяем память для нашего человека
  if(person==NULL){printf("нет памяти\n"); exit(1);}
  while(1)
  {
    int i,n,m;book* tmp;
    person[count]=getHuman(); count ++; 
    sortier(person, count);  
    for (i=0;i<count;i++) putHuman(person+i);
    a:printf("ввести еще одного человека? (y/n):");
    fgets(vbuf,128,stdin);
    if(vbuf[0]=='n') 
		    break;
    else if(vbuf[0]=='y'){ person=realloc(person,sizeof(book)*(count+1));// новый человек в книжке- увеличиваем память под него
                           if(person==NULL){
					    printf("нет памяти!\n");
					    exit(1);
					   }
			 }
    else{
	 printf("нужно ввести y или n\n");
	 goto a;
	}
  }
 
char wort[28+1];// номер, по которому будет искать контакт в нашей телефонной книжке
int temp=0,i;
printf("введие номер, по которому будем искать\n");
fgets(wort,28,stdin);wort[strlen(wort)-1]=0;
for(i=0;i<count;i++){
	if(strcmp(person[i].nummer,wort)==0) {printf("%-28s %-28s       %-28s\n",person[i].name,person[i].vorname,person[i].nummer);// тут решается, есть ли вообще пользователь в книжке с таким номером и выводим его данные
						 temp=1;} //ставим тмп на 1, что значит да, пользователь существует
			    }
        if(temp==0)  printf("Пользователь с запрашиваемым номером не найдем\n");
 free(person);// освобождаем память 
 return 0;
}
