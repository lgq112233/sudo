// homework1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "sudoCreate.h"
#include "sudoSolver.h"

#define MAX 1000000

int matrix[9][9] = { 0 };
int index[9][9] = { 0 };
int gridindex[9][9] = { 0 };

void readAndSolve(char* filepath);
void print(int matrix[9][9]);
void init();
int main(int argc,char* argv[])
{
	int num=0;
	char c;
	init();
	while (*++argv != NULL&&**argv == '-')
	{
		switch (*++*argv)
		{
		case'c':
			argv++;
			if (*argv == NULL)
			{
				std::cout << "please input a number" << std::endl;
				exit(0);
			}
			while ((c=*((*argv)++)) != '\0')
			{
				if (c >= '0'&&c <= '9')
				{
					num = num * 10 + c - '0';
					if (num > MAX)
					{
						std::cout << "too big number" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "input error" << std::endl;
					exit(0);
				}
			}
			{
				if (num == 0)
				{
					std::cout << "cannot smaller than 1" << std::endl;
					break;
				}
				sudoCreate creater = sudoCreate(num);
				creater.choose(0, 0);
			}
			break;
		case's':
			argv++;
			if (*argv == NULL)
			{
				std::cout << "please input a filepath" << std::endl;
			}
			readAndSolve(*argv);
			break;
		default:
			break;
		}
	}
	return 0;
}



void readAndSolve(char *filepath) {
	std::fstream question;
	question.open(filepath, std::ios::in);
	char c;

	while (!question.eof()) {
		for (int i = 0; i < 81; i++) {
			question >> c;
			matrix[i / 9][i % 9] = c - '0';
		}
		//print(matrix);
		sudoSolver* solver = new sudoSolver(matrix);
		//std::cout << "ok" << std::endl;
		solver->solve(0);
		if (!solver->getSolved()) {
			std::cout << "no solution" << std::endl;
		}
		delete solver;
	}
}

void print(int matrix[9][9]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void init()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			index[i][j] = (i / 3) * 3 + j / 3;
			gridindex[i][j]= (i % 3) * 3 + j % 3;
		}
	}
}





