#include<iostream>
#include<string.h>
#include<stdio.h>
#include<Windows.h>
#include <conio.h>
using namespace std;

struct student
{
	char name[64];
	char vorname[64];
	char rating_m[4];
	char rating_f[4];
	char rating_i[4];
};
FILE *f;
const char file_name[]="lab12.bin";

int input_student()
{   
    struct student a;
	cout<<"Ім'я: "; gets(a.name);
	cout<<"Прізвище: "; gets(a.vorname);
	cout<<"Оцінка з математики: "; gets(a.rating_m);
	cout<<"Оцінка з фізики: "; gets(a.rating_f);
	cout<<"Оцінка з інформатики: "; gets(a.rating_i);
	fseek(f,0,2);
	fwrite(&a,sizeof(a),1,f);
	return 0;
}

int print_student(struct student a)
{
	cout<<"Ім'я: "<<a.name<<endl;
	cout<<"Прізвище: "<<a.vorname<<endl;
	cout<<"Оцінка з математики: "<<a.rating_m<<endl;
	cout<<"Оцінка з фізики: "<<a.rating_f<<endl;
	cout<<"Оцінка з інформатики: "<<a.rating_i<<endl<<endl;

	return 0;
}

int show_all()
{
 struct student a;
 int p,r;
 	p=0;
	fseek(f,0,0);
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		print_student(a);
		p++;
	}
}

int clear(){
    fclose(f);
	if ((f=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"Неможливо створити файл запису бази данних продуктів !"<<endl;
 		return -1;
	}
    return 0;   
}

int search(){
 struct student a;
    int r, k=0;
    char srating[4];
    cout<<"Введіть оцінку ";
    gets(srating);
	fseek(f,0,0);
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if(r<1) break;
		if (strcmp(srating, a.rating_m)==0 || strcmp(srating, a.rating_f)==0 )
	    {	
           cout<<"Ім'я: "<<a.name<<endl;
           cout<<"Прізвище: "<<a.vorname<<endl;
           cout<<"Оцінка з математики: "<<a.rating_m<<endl;
           cout<<"Оцінка з фізики: "<<a.rating_f<<endl<<endl;
           k++;
        }
        
	}
    if (k==0)
    cout<<"Студентів не знайдено"<<endl;
    return r;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char c;
	if ((f=fopen(file_name,"rb+"))==NULL)
 	  {
        	if ((f=fopen(file_name,"wb+"))==NULL)
               {
 		            cout<<"Неможливо створити файл"<<endl;
 		            return -1;
               }
		cout<<"Створено новий файл"<<endl;
 	   }
 	   do
 	   {	cout<<"*******************************"<<endl;
            cout<<"Виберіть режим роботи"<<endl;
 		    cout<<"1 - Ввід студента"<<endl;
 	        cout<<"2 - Вивід всіх студентів"<<endl;
 	        cout<<"3 - Пошук за оцінкою"<<endl;
 	        cout<<"4 - Очистка файла"<<endl;
 	        cout<<"0 - Вихід"<<endl;
 	        cout<<"*******************************"<<endl;
 	        c=getch();
 		switch(c) 
         {
 		    case '0': cout<<"Роботу завершено"<<endl; fclose(f); return 0;
 		 	case '1': input_student(); break;
 	 		case '2': show_all(); break;
 	 		case '3': search(); break;
 	 		case '4': clear(); break;
 	 		
         }
        } while (1);
 	system ("pause");
}
