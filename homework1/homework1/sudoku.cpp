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
				std::fstream outfile("sudoku.txt", std::ios::out);
				sudoCreate creater = sudoCreate(num);
				creater.choose(0, 0,&outfile);
				outfile.close();
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
	/*
	TODO:测试getline()函数的用法。
	std::fstream outfile("sudoku.txt");
	int count = 2;
	char line[18];
	while ((count--) > 0) {
		outfile.getline(line,sizeof(line));
		std::cout << line << std::endl;
		int i = 0;
		while (i < 18)
		{
			std::cout << line[i] << "end" << std::endl;
			if (i == 17) {
				std::cout << (line[i] == '\0' )<< std::endl;
			}
			i++;
		}
		std::cout << '\0' << "输出反斜杠0" << std::endl;
	}*/
	return 0;
}



void readAndSolve(char *filepath) {
	FILE* f = fopen(filepath,"r");
	std::fstream result("sudoku.txt",std::ios::out);
	int temp;
	int i = 0;
	while (fscanf(f,"%d",&temp)!=EOF) {
		matrix[i / 9][i % 9] = temp;
		i++;
		if (i == 81) {
			//print(matrix);
			sudoSolver* solver = new sudoSolver(matrix);
			//std::cout << "ok" << std::endl;
			solver->fill(&result);
			if (!solver->getSolved()) {
				std::cout << "no solution" << std::endl;
			}
			delete solver;
			i = 0;
		}
	}
	result.close();
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





