#pragma once
#include <fstream>
class sudoCreate
{
public:
	sudoCreate(int num);
	~sudoCreate();
	int  choose(int index, int increment,FILE* fp);
	void print(int matrix[9][9]);
	bool canFill(int i,int j,int num);
	void fillin(int i, int j, int num);
	void erase(int i,int j,int num);
private:
	int num;
	int count;
	int matrix[9][9];
	bool line[9][9];
	bool column[9][9];
	static const int numarray[9] ;
};

