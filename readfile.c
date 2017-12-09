#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct struct_ // простая структура с 3 полями стандартных типов
{
  int x_int;
  float x_float;
  char x_char[20];
};
 
struct mainStruct_ // наша главная структура
{
  int x_int;
  float x_float;
  char x_char[20];
  struct_* pointerStruct_; // вложенная структура с указателям!
};
 
void InitializationStruct(mainStruct_* testStruct); // инициализация структуры 
void PrintStruct(mainStruct_* testStruct); // вывод на экран
void WriteInFile(mainStruct_* testStruct); // запись в файл
void ReadThisFileWhileNotEOF(mainStruct_* testStruct); // читать из файл 
void ClearStruct(mainStruct_* testStruct); // очистка структуры
 
void main(void)
{
  mainStruct_ *testStruct = (mainStruct_*)malloc(sizeof(mainStruct_)); // выделяем память для нашей структуры
  testStruct->pointerStruct_ = (struct_*)malloc(sizeof(struct_));  // и вложенную в ее структуру
 
  InitializationStruct(testStruct);   // инициализируем нашу структуру
  WriteInFile(testStruct);  // Дописываем ее в файл (если файл не существует, то создаем новый)
 
  printf("\nRead file while not EOF:\n");
  ReadThisFileWhileNotEOF(testStruct); // пробуем считать данные из файла
 
  free(testStruct->pointerStruct_);   // высвобождаем память
  free(testStruct);
  printf("End programm.");
  getch();
}
 
void InitializationStruct(mainStruct_* testStruct) // инициализируем структуру
{
  testStruct->x_int = 10;
  testStruct->x_float = 20.00;
  strcpy(testStruct->x_char, "30");
  testStruct->pointerStruct_->x_int = 40;
  testStruct->pointerStruct_->x_float = 50.00;
  strcpy(testStruct->pointerStruct_->x_char, "60");
}
 
void PrintStruct(mainStruct_* testStruct) // выводим структуру на консоль
{
  printf("Test console:\n");
  printf("%d\n", testStruct->x_int);
  printf("%.2lf\n", testStruct->x_float);
  printf("%s\n", testStruct->x_char);
  printf("%d\n", testStruct->pointerStruct_->x_int);
  printf("%.2lf\n", testStruct->pointerStruct_->x_float);
  printf("%s\n", testStruct->pointerStruct_->x_char);
}
 
void WriteInFile(mainStruct_* testStruct) // записываем в файл структуру
{
  FILE *f;
  f = fopen("phonebook.txt", "a"); // открываем на дозапись
  // при помощи  fwrite записываем нашу главную  (и вложенную) структуру в файл
  fwrite(testStruct, sizeof(mainStruct_) + sizeof(struct_), 1, f);
  fclose(f);
}
 
void ReadThisFileWhileNotEOF(mainStruct_* testStruct) // читаем пока не достигнут конец файла
{
  FILE *f;
  f = fopen("phonebook.txt", "r");  // открывем на чтение!
  while(!feof(f))  // пока !feof
  {
    ClearStruct(testStruct); // очищаем структуру
    fread(testStruct, sizeof(mainStruct_) + sizeof(struct_), 1, f); // считываем из файла струкуру
 
    if(feof(f))
    {
      printf("End file.\n");
      break;
    }
    PrintStruct(testStruct); // выводим ее на экран
  }
  fclose(f);
}
 
void ClearStruct(mainStruct_* testStruct) // очищаем структуру
{
  testStruct->x_int = 0;
  testStruct->x_float = 0.00;
  strcpy(testStruct->x_char, " ");
  testStruct->pointerStruct_->x_int = 0;
  testStruct->pointerStruct_->x_float = 0.00;
  strcpy(testStruct->pointerStruct_->x_char, " ");
}
