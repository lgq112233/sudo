#include "stdafx.h"
#include "sudoSolver.h"
#include "sudo.h"

extern int index[9][9];
extern int gridindex[9][9];

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


sudoSolver::~sudoSolver()
{
}
void sudoSolver:: solve(int arrayindex) {

	if (this->solved == true)
		return;
	if (arrayindex > maxempty - 1) {
		this->solved = true;
		sudo::print(this->matrix);
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
			matrix[i][j] = k;
			this->line[i][k] = false;
			this->column[j][k] = false;
			this->grid[index[i][j]][k] = false;

			solve(arrayindex + 1);
			matrix[i][j] = 0;
			this->line[i][k] = true;
			this->column[j][k] = true;
			this->grid[index[i][j]][k] = true;
			//std::cout << index << std::endl;
			//注意是index==maxempty-1
		}
	}

}
bool sudoSolver::canFill(int i, int j, int num)
{
	return line[i][num] && column[j][num] && grid[index[i][j]][num];
}
bool sudoSolver::getSolved() {
	return this->solved;
}
/*void sudoSolver:: print(int matrix[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}*/
