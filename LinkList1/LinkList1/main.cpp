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
	cout << "ɾ������������ż����λ���ϵ���" << endl;
	l.testdelOddorEven();
	return 0;
}