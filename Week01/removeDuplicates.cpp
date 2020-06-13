// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>


int removeDuplicates(std::vector<int>& nums) {
	int num = nums.size();
	int j = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[j] != nums[i]) {
			int temp = nums[j + 1];
			nums[j + 1] = nums[i];
			nums[i] = temp;
			j++;
		}
	}
	return j+1;
}