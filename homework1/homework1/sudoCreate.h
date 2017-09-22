#pragma once


class sudoCreate
{
public:
	sudoCreate(int num);
	~sudoCreate();
	int  choose(int index, int increment);
	void print(int matrix[9][9]);
private:
	int num;
	int count;
	int matrix[9][9];
};

