#pragma once
#include <fstream>
class sudoSolver
{
public:
	sudoSolver(int matrix[9][9]);
	~sudoSolver();
	 void solve(int index,std::fstream *outfile);
	 bool canFill(int i,int j,int num);
	 static void print(int matrix[9][9]);
	 void initprocess();
	 void fill(std::fstream *outfile);
	 bool getSolved();
	 void fillin(int i,int j,int num);
	 void erase(int i,int j,int num);
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

