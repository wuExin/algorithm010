// Array.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>


int MaxArea(std::vector<int> data) {
	int i = 0, j = data.size() - 1;
	int maxArea = 0;
	for (; i < j;)
	{
		int minHieght = data.at(i) < data.at(j) ? data.at(i++) : data.at(j--);
		maxArea = maxArea < (j - i + 1) * minHieght ? (j - i + 1) * minHieght : maxArea;
	}
	return maxArea;
}