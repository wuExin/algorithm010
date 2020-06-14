// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>


void reverse(std::vector<int>& nums, int start, int end) {
	while (start < end) {
		int temp = nums[end];
		nums[end] = nums[start];
		nums[start] = temp;
		start++;
		end--;
	}
}

void rotate(std::vector<int>& nums, int k) {
	if (nums.size() <= 0) {
		return;
	}
	k = k % nums.size();
	reverse(nums, 0, nums.size() - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, nums.size() - 1);
}