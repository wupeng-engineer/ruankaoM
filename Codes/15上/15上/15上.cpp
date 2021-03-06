// 15上.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int isPlace(int pos[], int k);

int main() {
	const int N = 4;
	int i, j, count = 1;
	int pos[N + 1];

	//初始化位置
	for (i = 1; i <= N; i++) {
		pos[i] = 0;
	}
	j = 1;
	while (j >= 1) {
		pos[j] = pos[j] + 1;
		//尝试摆放第i个皇后
		while (pos[j] <= N && isPlace(pos, j) == 0) {
			pos[j] = pos[j] + 1;
		}
		//得到一个摆放方案
		if (pos[j] <= N && j == N) {
			printf("方案%d:", count++);
			for (i = 1; i <= N; i++) {
				printf("%d-", pos[i]);
			}
			printf("\n");
		}
		//考虑下一个皇后
		if (pos[j] <= N && j < N) {
			j = j + 1;
		}
		else {//返回考虑上一个皇后
			pos[j] = 0;
			j = j - 1;
		}
	}
	system("pause");
	return 1;
}

int isPlace(int pos[], int k) {
	for (int i = 1; i < k; i++) {
		if (pos[i] == pos[k] || fabs(i - k) == fabs(pos[i] - pos[k])) {
			return 0;
		}
	}
	return 1;
}

// 函数声明
//double getAverage(int arr[], int size);
//
//int main()
//{
//	// 带有 5 个元素的整型数组
//	int balance[5] = { 1000, 2, 3, 17, 50 };
//	double avg;
//
//	// 传递一个指向数组的指针作为参数
//	avg = getAverage(balance, 5);
//
//	// 输出返回值
//	cout << "平均值是：" << avg << endl;
//	system("pause");
//	return 0;
//}
//
//double getAverage(int arr[], int size)
//{
//	int    i, sum = 0;
//	double avg;
//
//	for (i = 0; i < size; ++i)
//	{
//		sum += arr[i];
//	}
//
//	avg = double(sum) / size;
//
//	return avg;
//}