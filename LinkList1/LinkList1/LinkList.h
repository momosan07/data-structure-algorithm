#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
using namespace std;

template<class T>
class LinkList {
public:
	class LinkListNode {
	public:
		T data;
		LinkListNode* next;
	};
	LinkList();
	void add(T t);
	bool find(T t);
	T    findAsPosition(int postion);
	int  findAsData(T t);
	bool del(int p);
	bool remove(T t);
	void delOddorEven();

	void testAdd();
	void testFind();
	void testDel();
	void testRemove();
	void testdelOddorEven();
private:
	LinkListNode *start;
	int size;
};











template<class T>
LinkList<T>::LinkList() {
	size = 0;
	start = new LinkListNode;
	start->next = nullptr;
}

template<class T>
void LinkList<T>::add(T t) {
	int sizeTmp = size;
	LinkListNode *startTmp = start;
	while (sizeTmp--) {
		startTmp = startTmp->next;
	}
	LinkListNode *tmp = new LinkListNode;
	tmp->data = t;
	tmp->next = nullptr;
	startTmp->next = tmp;
	size++;
}

template<class T>
void LinkList<T>::testAdd() {
	LinkList<int> l;
	l.add(5);
	l.add(7);
	l.add(8);
	int sizeTmp = l.size;
	LinkListNode *startTmp = l.start;
	while (sizeTmp--) {
		startTmp = startTmp->next;
		cout << startTmp->data << endl;
	}
}


template<class T>
bool LinkList<T>::find(T t) {
	int tmpSize = size;
	LinkListNode *startTmp = start;
	while (tmpSize--) {
		startTmp = startTmp->next;
		if (startTmp->data == t) {
			return true;
		}
	}
	return false;
}

template<class T>
T LinkList<T>::findAsPosition(int position) {
	if ((position < 0) || (position > size - 1)) {
		cout << "*** Error when find as Position" << endl;
		exit(0);
	}
	LinkListNode *tmp = start;
	while (position--) {
		tmp = tmp->next;
	}
	return tmp->data;
}

template<class T>
int LinkList<T>::findAsData(T t) {
	if (!find(t)) {
		cout << "*** Error when find as Position" << endl;
		exit(0);
	}
	LinkListNode *tmp = start;
	int position = size;
	while (position--) {
		tmp = tmp->next;
		if (tmp->data == t)
			return size - position - 1;
	}
	return -1;
}

template<class T>
bool LinkList<T>::del(int p) {
	if ((p < 0) || (p > size - 1) || (size == 0))
		return false;
	LinkListNode *tmp = start;
	int sizeTmp = size;

	if (p == 0) {
		LinkListNode *delPtr = start->next;
		start->next = delPtr->next;
		delete delPtr;
		delPtr = nullptr;
		size--;
		return true;
	}

	p--;
	while (p--) {
		tmp = tmp->next;
	}
	LinkListNode *delPtr = tmp->next;
	tmp->next = delPtr->next;
	delete delPtr;
	delPtr = nullptr;
	size--;
	return true;
}

template<class T>
void LinkList<T>::testDel() {
	LinkList<int> l;
	l.add(3);
	l.add(5);
	l.add(7);
	cout << l.del(2) << endl;

}

template<class T>
bool LinkList<T>::remove(T t) {
	if (!find(t))
		return false;
	int p = findAsData(t);
	if (del(p))
		return true;
	return false;
}

template<class T>
void LinkList<T>::testRemove() {
	LinkList<int> l;
	l.add(3);
	l.add(5);
	l.add(7);
	cout << l.remove(3) << endl;
	int sizeTmp = l.size;
	LinkListNode *startTmp = l.start;
	while (sizeTmp--) {
		startTmp = startTmp->next;
		cout << startTmp->data << endl;
	}
}

template<class T>
void LinkList<T>::testFind() {
	LinkList<int> l;
	l.add(3);
	l.add(5);
	l.add(7);
	cout << l.find(7) << endl;
	cout << l.findAsPosition(2) << endl;
	cout << l.findAsData(7) << endl;
}

template<class T>
void LinkList<T>::delOddorEven() {
	int tmpSize = size;
	while(tmpSize >1) {
		del(tmpSize - 1);
		tmpSize -= 2;
	}
}
template<class T>
void LinkList<T>::testdelOddorEven() {
	LinkList<int> l;
	l.add(3);
	l.add(5);
	l.add(8);
	l.add(9);
	l.add(7);
    l.delOddorEven();
	int sizeTmp = l.size;
	LinkListNode *startTmp = l.start;
	while (sizeTmp--) {
		startTmp = startTmp->next;
		cout << startTmp->data << endl;
	}
}
#endif // LINKLIST_H
