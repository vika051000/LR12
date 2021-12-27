#include <iostream>
#include "AbstractDeque.h"
using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};

class OverflowException :public exception
{
public:
	OverflowException(const char* msg) :
		exception(msg) {}
};

template <typename T>
struct Node
{
	T data;
	Node* prev, * next;
};

template <typename T>
class Deque: AbstractDeque<T>
{
public:
	Deque();
	Deque(T);
	Deque& operator=(Deque&& other);
	int GetSize();
	void pushFront(const T a);
	void pushBack(const T a);
	void popFront(T& a);
	void popBack(T& a);
	void peekFront(T& a);
	void peekBack(T& a);
private:
	Node<T>* head;
	Node<T>* tail;
	int count;
};

