#include <iostream>    // ���� ����� ��������
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
	cout<<"������ ��������� ������"<<endl;
	cout<<"����� �������� "; gets(a.name);
	cout<<"��� ������ "; gets(a.ktovaru);
	cout<<"ʳ������ �������� "; gets(a.kilkist);
	fseek(f_products,0,2);
	fwrite(&a,sizeof(a),1,f_products);
	return 0;
}
int print_products(struct products a)
{
	cout<<"����� �������� "<<a.name<<endl;
	cout<<"��� �������� "<<a.ktovaru<<endl;
	cout<<"ʳ������ ��������� "<<a.kilkist<<endl<<endl;
	return 0;
}
int search_kod()
{char kod[14];
 struct products a;
 int p,r;
 	p=0;
	cout<<"����� �������� ��� ������ = ";
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
	if (p==0) cout<<"������ �������� �� ��������"<<endl; 
	else cout<<endl<<"�������� "<<p<<" ��������"<<endl<<endl;
        return p;
}
int search_name()
{char name_products[30];
 struct products a;
 int p,r;
 	p=0;
	cout<<"����� �������� ��� ������ = ";
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
	if (p==0) cout<<"������ �������� �� ��������"<<endl;
	else cout<<endl<<"�������� "<<p<<" ��������"<<endl<<endl;
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
	cout<<endl<<"�������� "<<p<<" ��������"<<endl<<endl;
        return p;
}

int clear_file()
{
	fclose(f_products);
	if ((f_products=fopen(file_name,"wb+"))==NULL)
 	{
 		cout<<"��������� �������� ���� ������ ���� ������ �������� !"<<endl;
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
 		cout<<"��������� �������� ���� ���� �������� �������� !"<<endl;
 		return -1;
	}
		cout<<"�������� ����� ���� ���� ������ �������� !"<<endl;
 	}
 	do
 	{
 		cout<<"������� ����� ������"<<endl;
 		cout<<"1 - ��� ��������"<<endl;
 	    cout<<"2 - ����� �� �����"<<endl;
		cout<<"3 - ����� �� ������"<<endl;
        cout<<"8 - �������� ��� ����"<<endl;
        cout<<"9 - ������� ���� �����"<<endl;
    	cout<<"0 - �����"<<endl;
 		c=getch();
 		switch(c)
 		{
		    case '0': cout<<"������ ���������"<<endl; fclose(f_products); return 0;
 		 	case '1': input_products(); break;
 	 		case '2': search_kod(); break;
		    case '3': search_name(); break;
  		 	case '8': show_all(); break;
   			case '9': clear_file(); break;
 	 	}
 	} while (1);	

}


