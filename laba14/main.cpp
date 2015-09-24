#include <iostream>    // База даних продуктів
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
using namespace std; 
struct products 
{ char name[40];
  char ktovaru[14];
  char kilkist[10];
  };
FILE * f_products;
const char file_name[]="C:desktop";
int input_products()
{struct products a;
	cout<<"Введіть параметри товару"<<endl;
	cout<<"Назва продукту "; gets(a.name);
	cout<<"Код товару "; gets(a.ktovaru);
	cout<<"Кількість продукту "; gets(a.kilkist);
	fseek(f_products,0,2);
	fwrite(&a,sizeof(a),1,f_products);
	return 0;
}
int print_products(struct products a)
{
	cout<<"Назва продукту "<<a.name<<endl;
	cout<<"Код продукту "<<a.ktovaru<<endl;
	cout<<"Кількість продукції "<<a.kilkist<<endl<<endl;
	return 0;
}
int search_kod()
{char kod[14];
 struct products a;
 int p,r;
 	p=0;
	cout<<"Номер продукту для пошуку = ";
	gets(kod);
	fseek(f_products,0,0);
	while (!feof(f_products))
	{
		r=fread(&a,sizeof(a),1,f_products);
		if (r<1) break;
		if (strcmp(a.ktovaru, kod) == 0) 
		{
			print_products(a);
			p++;
		}
	}
	if (p==0) cout<<"Такого продукта не знайдено"<<endl; 
	else cout<<endl<<"Знайдено "<<p<<" продуктів"<<endl<<endl;
        return p;
}
int search_name()
{char name_products[30];
 struct products a;
 int p,r;
 	p=0;
	cout<<"Назва предмета для пошуку = ";
	gets(name_products);
	fseek(f_products,0,0);
	while (!feof(f_products))
	{
		r=fread(&a,sizeof(a),1,f_products);
		if (r<1) break;
		if (strcmp(a.name, name_products)== 0)
		{
			print_products(a);
			p++;
		}
	}
	if (p==0) cout<<"Такого продукта не знайдено"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" продуктів"<<endl<<endl;
        return p;
}
int show_all()
{
 struct products a;
 int p,r;
 	p=0;
	fseek(f_products,0,0);
	while (!feof(f_products))
	{
		r=fread(&a,sizeof(a),1,f_products);
		if (r<1) break;
		print_products(a);
		p++;
}
	cout<<endl<<"Знайдено "<<p<<" продуктів"<<endl<<endl;
        return p;
}

int clear_file()
{
	fclose(f_products);
	if ((f_products=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"Неможливо створити файл запису бази данних продуктів !"<<endl;
 		return -1;
	}
	return 0;
}

int main() 
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	char c;
 	if ((f_products=fopen(file_name,"rb+"))==NULL)
 	{
 	if ((f_products=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"Неможливо створити файл бази данинних продуктів !"<<endl;
 		return -1;
	}
		cout<<"Створено новий файл бази данних продукту !"<<endl;
 	}
 	do
 	{
 		cout<<"Виберіть режим роботи"<<endl;
 		cout<<"1 - Ввід продукту"<<endl;
 	    cout<<"2 - Пошук за кодом"<<endl;
		cout<<"3 - Пошук за назвою"<<endl;
        cout<<"8 - Показати всю базу"<<endl;
        cout<<"9 - Очистка бази даних"<<endl;
    	cout<<"0 - Вихід"<<endl;
 		c=getch();
 		switch(c)
 		{
		    case '0': cout<<"Роботу завершено"<<endl; fclose(f_products); return 0;
 		 	case '1': input_products(); break;
 	 		case '2': search_kod(); break;
		    case '3': search_name(); break;
  		 	case '8': show_all(); break;
   			case '9': clear_file(); break;
 	 	}
 	} while (1);	

}


