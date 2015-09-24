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
	cout<<"��'�: "; gets(a.name);
	cout<<"�������: "; gets(a.vorname);
	cout<<"������ � ����������: "; gets(a.rating_m);
	cout<<"������ � ������: "; gets(a.rating_f);
	cout<<"������ � �����������: "; gets(a.rating_i);
	fseek(f,0,2);
	fwrite(&a,sizeof(a),1,f);
	return 0;
}

int print_student(struct student a)
{
	cout<<"��'�: "<<a.name<<endl;
	cout<<"�������: "<<a.vorname<<endl;
	cout<<"������ � ����������: "<<a.rating_m<<endl;
	cout<<"������ � ������: "<<a.rating_f<<endl;
	cout<<"������ � �����������: "<<a.rating_i<<endl<<endl;

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
 		cout<<"��������� �������� ���� ������ ���� ������ �������� !"<<endl;
 		return -1;
	}
    return 0;   
}

int search(){
 struct student a;
    int r, k=0;
    char srating[4];
    cout<<"������ ������ ";
    gets(srating);
	fseek(f,0,0);
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if(r<1) break;
		if (strcmp(srating, a.rating_m)==0 || strcmp(srating, a.rating_f)==0 )
	    {	
           cout<<"��'�: "<<a.name<<endl;
           cout<<"�������: "<<a.vorname<<endl;
           cout<<"������ � ����������: "<<a.rating_m<<endl;
           cout<<"������ � ������: "<<a.rating_f<<endl<<endl;
           k++;
        }
        
	}
    if (k==0)
    cout<<"�������� �� ��������"<<endl;
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
 		            cout<<"��������� �������� ����"<<endl;
 		            return -1;
               }
		cout<<"�������� ����� ����"<<endl;
 	   }
 	   do
 	   {	cout<<"*******************************"<<endl;
            cout<<"������� ����� ������"<<endl;
 		    cout<<"1 - ��� ��������"<<endl;
 	        cout<<"2 - ���� ��� ��������"<<endl;
 	        cout<<"3 - ����� �� �������"<<endl;
 	        cout<<"4 - ������� �����"<<endl;
 	        cout<<"0 - �����"<<endl;
 	        cout<<"*******************************"<<endl;
 	        c=getch();
 		switch(c) 
         {
 		    case '0': cout<<"������ ���������"<<endl; fclose(f); return 0;
 		 	case '1': input_student(); break;
 	 		case '2': show_all(); break;
 	 		case '3': search(); break;
 	 		case '4': clear(); break;
 	 		
         }
        } while (1);
 	system ("pause");
}
