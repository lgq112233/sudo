#include "stdafx.h"
#include "CppUnitTest.h"
#include "../homework1/stdafx.h"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern int* matrixarray[1000000];
extern int array[8];
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

		
		TEST_METHOD(TestCreate)
		{
			sudoCreate creater = sudoCreate(10);
			//creater.choose(0,0,fp);
			creater.generateMatrix(array, 0, 8);
		}
	};
}