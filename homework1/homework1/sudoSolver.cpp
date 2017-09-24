#include "stdafx.h"
#include "sudoSolver.h"
#include "sudo.h"

extern int index[9][9];
extern int gridindex[9][9];

void sudoSolver::fill(FILE* fp)
{
	this->solve(0, fp);
}

sudoSolver::sudoSolver(int matrix[9][9])
{
	//一开始忘了初始化maxempty了
	this->maxempty = 0;
	this->solved = false;
	for(int i=0;i<9;i++)
		for (int j = 0; j < 9; j++) {
			int num = matrix[i][j];
			this->matrix[i][j] = num;
			if (num != 0) {
				this->line[i][num - 1] = false;
				this->column[j][num - 1] = false;
				this->grid[index[i][j]][num - 1] = false;
			}
			else {
				this->line[i][num-1] = this->column[i][num-1] = this->grid[i][num-1] = true;
			}
		}
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < 81; i++) {
			if (this->matrix[i / 9][i % 9] != 0)
				continue;
			int row = i/9;
			int col = i%9;
			int count = 0;
			int num = 0;
			for (int j = 1; j <= 9; j++) {
				if (canFill(row, col, j))
				{
					count += 1;
					num = j;
				}
			}
			if (count == 1)
			{
				fillin(row, col, num);
				flag = true;
			}
		}
	}
	for (int i = 0; i < 81; i++) {
		int num = matrix[i / 9][i % 9];
		if (num == 0) {
			this->rchoice[maxempty] = i/9;
			this->cchoice[maxempty++] = i%9;
		}
	}
}




sudoSolver::~sudoSolver()
{
}
void sudoSolver:: solve(int arrayindex,FILE* fp) {

	if (this->solved == true)
		return;
	if (arrayindex > maxempty - 1) {
		this->solved = true;
		sudo::print(this->matrix,fp);
		return;
	}
	int i = rchoice[arrayindex];
	int j = cchoice[arrayindex];
//	print(this->matrix);
	for (int k = 1; k <= 9; k++) {
		if (canFill(i, j, k)) {
			this->fillin(i, j, k);
			solve(arrayindex + 1,fp);
			this->erase(i, j, k);
		}
	}

}
void sudoSolver::fillin(int i, int j, int num)
{
	this->matrix[i][j] = num;
	this->line[i][num-1] = false;
	this->column[j][num-1] = false;
	this->grid[index[i][j]][num-1] = false;
}
void sudoSolver::erase(int i,int j,int num)
{
	this->matrix[i][j] = 0;
	this->line[i][num-1] = true;
	this->column[j][num-1] = true;
	this->grid[index[i][j]][num-1] = true;
}
bool sudoSolver::canFill(int i, int j, int num)
{
	return matrix[i][j]==0&&line[i][num-1] && column[j][num-1] && grid[index[i][j]][num-1];
}
bool sudoSolver::getSolved() {
	return this->solved;
}
 void sudoSolver:: print(int matrix[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
 
