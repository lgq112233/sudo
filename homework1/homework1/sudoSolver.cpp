#include "stdafx.h"
#include "sudoSolver.h"
#include "sudo.h"

extern int index[9][9];
extern int gridindex[9][9];

void sudoSolver::fill(std::fstream *outfile)
{
	this->initprocess();
	this->solve(0, outfile);
}

sudoSolver::sudoSolver(int matrix[9][9])
{
	//一开始忘了初始化maxempty了
	this->maxempty = 0;
	this->solved = false;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			this->line[i][j] = this->column[i][j] = this->grid[i][j] = true;
	for (int i = 0; i<9; i++)
		for (int j = 0; j < 9; j++) {
			this->matrix[i][j] = matrix[i][j];
			int num = matrix[i][j];
			if (num == 0) {
				this->rchoice[this->maxempty] = i;
				this->cchoice[this->maxempty++] = j;
			}
			else {
				this->line[i][num] = this->column[j][num] = this->grid[index[i][j]][num] = false;
			}
		}

}

void sudoSolver::initprocess() {
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < this->maxempty; i++) {
			int row = this->rchoice[i];
			int col = this->cchoice[i];
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
}

sudoSolver::~sudoSolver()
{
}
void sudoSolver:: solve(int arrayindex,std::fstream *outfile) {

	if (this->solved == true)
		return;
	if (arrayindex > maxempty - 1) {
		this->solved = true;
		sudo::print(this->matrix,outfile);
		return;
	}
	int i = rchoice[arrayindex];
	int j = cchoice[arrayindex];
//	print(this->matrix);
	//std::cout << i << " " << j << std::endl;
	for (int k = 1; k <= 9; k++) {
		//std::cout << index << std::endl;
		//std::cout << canInsertInGrid(i, j, k) << canInsert(i, j, k) << std::endl;
		if (canFill(i, j, k)) {
			//std::cout << index << std::endl;
			this->fillin(i, j, k);

			solve(arrayindex + 1,outfile);
			this->erase(i, j, k);
			//std::cout << index << std::endl;
			//注意是index==maxempty-1
		}
	}

}
void sudoSolver::fillin(int i, int j, int num)
{
	this->matrix[i][j] = num;
	this->line[i][num] = false;
	this->column[j][num] = false;
	this->grid[index[i][j]][num] = false;
}
void sudoSolver::erase(int i,int j,int num)
{
	this->matrix[i][j] = 0;
	this->line[i][num] = true;
	this->column[j][num] = true;
	this->grid[index[i][j]][num] = true;
}
bool sudoSolver::canFill(int i, int j, int num)
{
	return line[i][num] && column[j][num] && grid[index[i][j]][num];
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
 
