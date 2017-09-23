#include "stdafx.h"
#include "CppUnitTest.h"
#include "../homework1/stdafx.h"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCanInsert)
		{
			/*
			1.有没有填
			2.如果没有填，看这一行和这一列有没有相同的数字
			3.如果这一行和这一列都没有相同的数字，就返回1，其他情况返回0
			所用矩阵：
			0 0 0 0 0 0 0 3 9
			0 0 0 0 0 1 0 0 5
			0 0 3 0 5 0 8 0 0
			0 0 8 0 9 0 0 0 6
			0 7 0 0 0 2 0 0 0
			1 0 0 4 0 0 0 0 0
			0 0 9 0 8 0 0 5 0
			0 2 0 0 0 0 6 0 0
			4 0 0 7 0 0 0 0 0
			因为生成算法这里不检查一个九宫格里的重复性。
			*/

			/*
			这里一开始一直调试的时候c读不到数，原来是因为puzzle.txt是个空文件
			而且这里调试时用的puzzle.txt是来自homework1/Debug里的，具体原因还很模糊
			不过现在先不管了。
			*/
			int matrix[9][9] = {0};
			char c;
			std::fstream infile("puzzle.txt",std::ios::in);
			for (int i = 0; i < 81; i++) {
				infile >> c;
				matrix[i / 9][i % 9] = c - '0';
			}
			//选择一个已经填的位置
			Assert::AreEqual(sudo::canInsert(2,2,3,matrix),0);
			//如果没填，看这一行和这一列
			Assert::AreEqual(sudo::canInsert(1,7,3,matrix),0);
			Assert::AreEqual(sudo::canInsert(1,0,1,matrix),0);
			Assert::AreEqual(sudo::canInsert(6,8,5,matrix),0);
			//如果可以填
			Assert::AreEqual(sudo::canInsert(0,0,2,matrix),1);
			infile.close();
		}

		TEST_METHOD(TestPrint)
		{
			/*
			判断是否以正确的格式写入对应的文件，格式要求：
			1.数与数之间用空格分开
			2.终局与终局之间空一行
			3.每一行的末尾没有空格
			测试办法：
			每次读取一行，判断对应的格式要求是否到位，因为文件写入也是循环写入的
			所以这里取前两个终局作为样本判断。

			终于把这个单元测试写好了。。
			遇到的问题：1.文件的位置2.每生成一个终局都会产生两个换行，保证下一个终局在
			上个终局的最后一行的下下一行开始生成。不过问题中没有对于最后一个终局后有几个
			换行符的规定。就不测这里了。
			*/
			int matrix[9][9] = { 0 };
			int count = 2;
			char c;
			std::fstream outfile("puzzle.txt", std::ios::in);
			std::fstream infile("temp.txt", std::ios::out);
			for (int i = 0; i < 81; i++) {
				outfile >> c;
				matrix[i / 9][i % 9] = c - '0';
			}
			sudo::print(matrix, &infile);
			for (int i = 0; i < 81; i++) {
				outfile >> c;
				matrix[i / 9][i % 9] = c - '0';
			}
			sudo::print(matrix, &infile);
			//选择puzzle.txt作为读入文件，读入两个矩阵
			//把这两个矩阵用print函数存入temp.txt
			/*while (count-->0) {
				for (int i = 0; i < 81; i++) {
					outfile >> c;
					int temp = c - '0';
					matrix[i / 9][i % 9] = temp;
				}
				sudo::print(matrix, &infile);
			}*/
			infile.close();
			outfile.close();
			//读入temp.txt，每次读一行，判断是否符合格式
			std::fstream outfile2("temp.txt", std::ios::in);
			char line[18] = {0};
			while (count-->0)
			{
				int i = 0;
				while (i < 9)
				{
					outfile2.getline(line,sizeof(line));	
					for (int j = 0; j < 8; j++) {
						//每个数字后面跟一个空格
						//知道问题所在了，第二个终局后面有两个换行
						Assert::AreEqual(line[j*2]>='0'&&line[j*2]<='9',true);
						Assert::AreEqual(line[j*2+1]==' ',true);
					}
					//最后一个数字后没有空格，所以就遇到换行符直接结束，所以最后一个字符是'\0'
					Assert::AreEqual(line[16]>='0'&&line[16]<='9',true);
					Assert::AreEqual(line[17]=='\0',true);
					i++;

				}
				outfile2.getline(line, sizeof(line));
				Assert::AreEqual(line[0]=='\0',true);
				//因为每两个终局之间有一个空行，所以会一开始就读入'\n'，这时line[0]=='\0'
			}
			outfile2.close();
			//最后把临时文件删掉
			remove("temp.txt");

		}
		TEST_METHOD(Test)
		{

		}
	};
}