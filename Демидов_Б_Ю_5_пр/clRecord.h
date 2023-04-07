#pragma once
#include <string>
#include "clDate.h"
#include <fstream>



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

	clRecord(string _name, string _type, string _area, unsigned short _eff, struct Date _date)
	{
		name = _name; type = _type; area = _area; eff = _eff; date.setDate_struct(_date);
	}

	clRecord(FILE *textFile) 
	{
			unsigned short day;
			unsigned short month;
			short year;
			fscanf_s(textFile, "%s", name, sizeof(name));
			fscanf_s(textFile, "%s", type, sizeof(type));
			fscanf_s(textFile, "%s", area, sizeof(area));
			fscanf_s(textFile, "%hu", &eff);
			fscanf_s(textFile, "%hu", &day);
			fscanf_s(textFile, "%hu", &month);
			fscanf_s(textFile, "%hd", &year);
			date.setDate(day, month, year);
		
	}

	clRecord(struct Record rec) { name = rec.name; type = rec.type; area = rec.area; eff = rec.eff; date.setDate_struct(rec.date); }

	void writeFile(FILE* textFile) 
	{
		fprintf(textFile, "%s %c %s %d %d %d %d \n", \
			name, \
			type, \
			area, \
			eff, \
			date.getDay(), date.getMonth(), date.getYear());
	}

	//getters
	string getName() { return name; }
	string getType() { return type; }
	string getArea() { return area; }
	unsigned short getEff() { return eff; }
	clDate getDate() { return date; }


};