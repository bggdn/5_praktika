#include <windows.h>
#include "clRecord.h"

using namespace std;



void printDate(clDate date, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (date.getDay() > 9) {
		cout << date.getDay();
	}
	else {
		cout << "0" << date.getDay();
	}
	cout << ".";
	if (date.getMonth() > 9) {
		cout << date.getMonth();
	}
	else {
		cout << "0" << date.getMonth();
	}
	cout << ".";
	cout << date.getYear();
	cout.width(delta); cout << " ";
}

void Draw(clRecord* records) {
	cout << endl;	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(90);  cout << left << "|�������������������� ��������"; cout << "|" << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| ������������ ";
	cout << left << "| ��� ";
	cout << left << "| �������� ������� (��) ";
	cout << left << "| ����������� (�/��) ";
	cout << left << " | ���� ������ �������� ";
	cout << "|" << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(14); cout << left << records[i].getName();
		cout << left << "|"; cout.width(5); cout << left << records[i].getType();
		cout << left << "|"; cout.width(23); cout << left << records[i].getArea();
		std::cout.precision(2);
		cout << left << "|"; cout.width(21); cout << left << fixed << records[i].getEff();
		cout << left << "|";
		printDate(records[i].getDate(), 24);
		cout << "|" << endl;
	}
	cout.width(91); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(90);  cout << left << "|����������: � - ��������, � - ������� "; cout << "|" << endl;
	cout.width(91); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[10];

	records[0] = { "���", "�", "0013000", 45, {03,03,2022}};
	records[1] = { "������", "�", "0008000", 17, {03,04,2022}};
	records[2] = { "���", "�", "0025650", 24, {04,03,2022}};

	//����� ��������
	clDate date1;
	clDate date2(1, 2, 3);
	Date date = { 1,2,3 };
	clDate date3(date);

	clDate DC;
	return 0;
}