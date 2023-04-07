#pragma once
#include <string>
#include "clDate.h"
#include <fstream>
#include <iostream>



struct Record
{
	string name;
	string type;
	string area;
	unsigned short eff;
	struct Date date;
};


class clRecord
{
private:
	string name;
	string area;
protected:
	unsigned short eff;
	clDate date;
public:
	string type;

	clRecord() { name = "empty"; type = "0"; area = "00000000";  eff = 0; }

	clRecord(FILE *textFile) 
	{
			unsigned short day;
			unsigned short month;
			short year;
			fscanf_s(textFile, "%s", name, sizeof(name));
			fscanf_s(textFile, "%s", type, sizeof(type));
			fscanf_s(textFile, "%s", area, sizeof(area));
			fscanf_s(textFile, "%d", &eff);
			fscanf_s(textFile, "%d", &day);
			fscanf_s(textFile, "%d", &month);
			fscanf_s(textFile, "%d", &year);
			date.setDate(day, month, year);
		
	}

	clRecord(struct Record rec) { name = rec.name; type = rec.type; area = rec.area; eff = rec.eff; date.setDate(rec.date); }

	void writeFile(FILE* textFile) 
	{
		fprintf(textFile, "%s %c %s %d %d %d %d \n", \
			name, \
			type, \
			area, \
			eff, \
			date.getDay(), date.getMonth(), date.getYear());
	}


};