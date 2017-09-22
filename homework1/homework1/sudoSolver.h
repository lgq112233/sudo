#pragma once
class sudoSolver
{
public:
	sudoSolver(int matrix[9][9]);
	~sudoSolver();
	 void solve(int index);
	 bool canFill(int i,int j,int num);
	 /*void print(int matrix[9][9]);*/
	 bool getSolved();
private:
	int matrix[9][9];
	int rchoice[81];
	int cchoice[81];
	bool line[9][9];
	bool column[9][9];
	bool grid[9][9];
	int maxempty;
	bool solved;
};

