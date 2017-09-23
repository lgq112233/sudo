#pragma once
#include <fstream>
class sudoCreate
{
public:
	sudoCreate(int num);
	~sudoCreate();
	int  choose(int index, int increment,std::fstream *outfile);
	/*void print(int matrix[9][9]);*/
private:
	int num;
	int count;
	int matrix[9][9];
};

