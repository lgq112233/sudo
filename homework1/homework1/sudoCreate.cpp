#include "stdafx.h"
#include "sudoCreate.h"
#include "sudo.h"

extern int rowarray[9][9];
extern int colarray[9][9];
const int sudoCreate::numarray[9] ={ 3,4,5,6,7,8,9,1,2 };
sudoCreate::sudoCreate(int num)
{
	this->num = num;
	this->count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			this->matrix[i][j] = 0;
			this->line[i][j] = true;
			this->column[i][j] = true;
		}
	}
}


sudoCreate::~sudoCreate()
{}

bool sudoCreate::canFill(int i, int j, int num)
{
	//没有检查这个空是不是已经有值了！另外一个算法中不需要检测是因为我把所有空都跳出来了
	return this->matrix[i][j]==0&&this->line[i][num-1] && this->column[j][num-1];

}

void sudoCreate:: fillin(int i, int j, int num)
{
	this->matrix[i][j] = num;
	this->line[i][num-1] = false;
	this->column[j][num - 1] = false;
}

void sudoCreate::erase(int i,int j,int num) {
	this->matrix[i][j] = 0;
	this->line[i][num - 1] = true;
	this->column[j][num - 1] = true;
}

int sudoCreate::  choose(int index, int arrayindex,FILE* fp) {
	int  num = sudoCreate::numarray[arrayindex]; 
	for (int i = 0; i < 9; i++) {
		int row = rowarray[index][i];
		int col = colarray[index][i];
		if (this->canFill(row,col,num)) {
			this->fillin(row, col, num);
			if (index == 8) {
				if (arrayindex == 8) {
					//print(this->matrix);
					sudo::print(this->matrix,fp);
					count++;
					if (count == this->num) {
						exit(0);
					}
				}
				else {
					choose(0, arrayindex + 1,fp);
				}
			}
			else {
				choose(index + 1, arrayindex,fp);
			}
			this->erase(row, col, num);
		}
	}	
	return 0;
}
void sudoCreate:: print(int matrix[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
