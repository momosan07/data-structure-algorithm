#pragma once
#include <iostream>
#include "stdafx.h"
#include "LinkList.h"
using namespace std;
int main() {
	LinkList<int> l;
	l.testAdd();
	l.testFind();
	l.testDel();
	l.testRemove();
	cout << "删除所有奇数或偶数个位置上的数" << endl;
	l.testdelOddorEven();
	return 0;
}