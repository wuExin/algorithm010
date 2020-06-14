// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>


void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1;
	    int j = n - 1;
	    int k = m + n - 1;
	    while (i >= 0 && j>=0) {
		    A[k--] = A[i] >= B[j] ? A[i--] : B[j--];
	    }
	    while (j >= 0) {
		    A[k--] = B[j--];
	    }
	}