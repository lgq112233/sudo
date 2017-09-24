#pragma once
#include<iostream>
#include <fstream>


class sudo
{
private:
	int m[9][9];
	public:
		sudo();
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
		static void print( int matrix[9][9],FILE* fp) {
			/*控制台的sudoku.exe的生成的文件的位置和ide里运行生成文件的位置不一样！*/
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					fprintf(fp,"%d",matrix[i][j]);
					if (j != 8)
						fprintf(fp, " ");
					//行末无空格！！
					//std::cout << matrix[i][j] << " ";
				}
				fprintf(fp, "\n");
				//std::cout << std::endl;
			}
			fprintf(fp, "\n");
			//std::cout << std::endl;
		}




};



