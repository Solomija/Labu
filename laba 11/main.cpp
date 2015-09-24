#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define n 100

FILE*file;

struct shipment {
	char name [25];
	char number [25];
	char surname [25];
} st;

void input (shipment st);
void output (shipment st);
void  name(shipment st);
void menu();

int main(int argc, char *argv[]) {	
	setlocale (LC_ALL, "ukrainian");
	
	menu();
}

void menu(){
	
	int k;
	
	cout << "______________________ \n";
	cout << "Виберiть операцiю: \n";
	cout << "______________________ \n";
	cout << "0 - вихiд \n";
	cout << "1 - введення даних  \n";
	cout << "2 - виведення даних  \n";
	cout << "______________________ \n";
	
	while (3){
		cin >> k;
		
		switch (k){
			case 1: input(st); break;
			case 2: output(st); break;
			case 0: exit(3);
		}
	}
}

void input (shipment st){
	file = fopen ("Text.txt", "a+");
	
	cout << "______________________ \n";
	
	cout << "Назва: ";
	cin >> st.name;
	cout << "кількість: ";
	cin >> st.number;
	cout << "Прізвище: ";
	cin >> st.surname;
	
	fwrite(&st, sizeof(shipment), 1, file);
	
	fclose(file);
	cout << "\n";
	cout << "|Запит виконано|\n";
	cout << "\n";
	menu();
}

void output(shipment st){
	file = fopen ("Text.txt", "ab+");
	
	int c;
	
	cout << "___________________________________________________\n";
	
	while ((c = fread (&st, sizeof(shipment), 1, file)) != NULL) {
		cout << "Назва - " << st.name
		<< ", Кiлькiсть - " << st.number 
		<< ", Прізвище - "	<< st.surname << "\n";
	}
	
	fclose(file);
	
	cout << "___________________________________________________\n";
	
	cout << "\n";
	cout << "|Запит виконано|\n";
	cout << "\n";
	menu();

}


