#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


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
	clDate(unsigned short _day, unsigned short _month, short _year) { 
		day = _day; month = _month; year = _year;
	}
	clDate(Date strct) { day = strct.day; month = strct.month; year = strct.year; }

	//сетеры
	void setDay(unsigned short _day) { day = _day; }
	void setMonth(unsigned short _month) { month = _month; }
	void setYear(short _year) { year = _year; }
	void setDate(unsigned short _day, unsigned short _month, short _year) {
		setDay(_day); setMonth(_month); setYear(_year);
	}
	void setDate_struct (Date strct) { day = strct.day; month = strct.month; year = strct.year; }


	//гетеры
	unsigned short int getDay() { return day; }
	unsigned short int getMonth() { return month; }
	short int getYear() { return year; }
	struct Date getDate_struct() 
	{ 
		Date date; 
		date.day = day;
		date.month = month;
		date.year = year;
		return date;
	}






};


int main()
{
	;
}