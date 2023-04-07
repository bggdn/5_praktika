#include <windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


struct Date {
	unsigned short day;
	unsigned short month;
	short year;
};


class clDate
{
private:
	unsigned short day = 0;
	unsigned short month = 0;
	short year = 0;
public:
	clDate() { std::cout << "Struct " << this << "\n"; }
	//3 int
	clDate(unsigned short _day, unsigned short _month, short _year)
	{ 
		day = _day; month = _month; year = _year;
		std::cout << "Struct " << this << "\n";
	}
	//struct
	clDate(Date strct)
	{ 
		day = strct.day; month = strct.month; year = strct.year; 
		std::cout << "Struct " << this << "\n";
	}
	//clDate (copy)
	clDate(clDate* date) 
	{ 
		day = date->day; month = date->month; year = date->year;
		std::cout << "Struct " << this << "\n";
	}

	//seters
	void setDay(unsigned short _day) { if (_day > 0 && _day < 31) day = _day; else std::cout << "DAY ERROR\n"; }
	void setMonth(unsigned short _month) { if (_month > 0 && _month < 13) month = _month; else std::cout << "MONTH ERROR\n"; }
	void setYear(short _year) { year = _year; }
	void setDate(unsigned short _day, unsigned short _month, short _year) {
		setDay(_day); setMonth(_month); setYear(_year);
	}
	void setDate_struct (Date strct) { day = strct.day; month = strct.month; year = strct.year; }


	//geters
	unsigned short int getDay() { return day; }
	unsigned short int getMonth() { return month; }
	short int getYear() { return year; }
	struct Date getDate_struct() 
	{ 
		Date date ; 
		date.day = day;
		date.month = month;
		date.year = year;
		return date;
	}

	//destruct
	~clDate() { std::cout << "Destruct " << this << "\n"; };


};


int main()
{
	clDate date1;
	clDate date2(1, 2, 3);
	Date date = { 1,2,3 };
	clDate date3(date);

	clDate DC;

}