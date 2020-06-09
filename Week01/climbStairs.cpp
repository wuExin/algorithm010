// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

int climbStairs(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	int before1 = 1;
	int before2 = 2;
	int now = 0;
	for (int i = 3; i <= n; i++) {
		now = before1 + before2;
		before1 = before2;
		before2 = now;
	}
	return now;
}


