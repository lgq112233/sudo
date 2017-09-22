#pragma once
#include<iostream>
#include <fstream>


class sudo
{
private:
	int m[9][9];
	public:
		sudo(int matrix[9][9]);
		~sudo();
		static int canInsert(int row, int col, int num,int matrix[9][9]) {
			//判断这个位置还没填入数字
			if (matrix[row][col] != 0)
				return 0;
			//行和列
			for (int j = 0; j < 9; j++) {
				if (matrix[j][col] == num || matrix[row][j] == num) {
					return 0;
				}
			}
			return 1;

		}
		static int canInsertInGrid(int i, int j, int num,int matrix[9][9]) {
			int index = (i / 3) * 3 + j / 3;
			int gridindex = (i % 3) * 3 + j % 3;
			int row, col;
			for (int k = 0; k < 9; k++) {
				row = (index / 3) * 3 + (k / 3);
				col = (index % 3) * 3 + (k % 3);
				if (matrix[row][col] == num) {
					return 0;
				}
			}
			return 1;
		}

		static void print( int matrix[9][9]) {
			std::fstream outfile;
			outfile.open("sudoku.txt", std::ios::app);
			/*控制台的sudoku.exe的生成的文件的位置和ide里运行生成文件的位置不一样！*/
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					outfile << matrix[i][j] << " ";
					//std::cout << matrix[i][j] << " ";
				}
				outfile << std::endl;
				//std::cout << std::endl;
			}
			outfile << std::endl;
			outfile.close();
			//std::cout << std::endl;
		}




};



