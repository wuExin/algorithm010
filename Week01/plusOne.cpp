// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>


std::vector<int> plusOne(std::vector<int>& digits) {
	for (int i = digits.size() - 1; i >= 0; i--) {
		digits[i]++;
		digits[i] = digits[i] % 10;
		if (digits[i] != 0) {
			return digits;
		}
	}
	/*std::vector<int> data;
	data.push_back(1);
	for (int i = 0; i < digits.size(); i++) {
		data.push_back(digits.at(i));
	}
	return data;
	*/
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}