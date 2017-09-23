#include "stdafx.h"
#include "sudoCreate.h"
#include "sudo.h"

sudoCreate::sudoCreate(int num)
{
	this->num = num;
	this->count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}


sudoCreate::~sudoCreate()
{}

int sudoCreate::  choose(int index, int increment,std::fstream *outfile) {
	//print(this->matrix);
	int  num = 3 + increment;
	int row, col;
	num = num > 9 ? num % 9 : num;
	for (int i = 0; i < 9; i++) {
		row = (index / 3) * 3 + (i / 3);
		col = (index % 3) * 3 + (i % 3);
		if (sudo::canInsert(row, col, num,this->matrix)) {
			this->matrix[row][col] = num;
			if (index == 8) {
				if (increment == 8) {
					//搜索成功打印结果
					sudo::print(this->matrix,outfile);
					count++;
					if (count == this->num) {
						exit(0);
					}
				}
				else {
					choose(0, increment + 1,outfile);
				}
			}
			else {
				choose(index + 1, increment,outfile);
			}
			this->matrix[row][col] = 0;	//恢复矩阵
		}
	}
	return 0;
}
/*void sudoCreate:: print(int matrix[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}*/

