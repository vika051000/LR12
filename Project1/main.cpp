#include "Header.h"
#include <conio.h>
#include<iostream>
using namespace std;

template <typename T>
Deque<T>::Deque()
{
	head = tail = nullptr;
	count = 0;
}


template <typename T>
Deque<T>::Deque(T a)
{
	head = tail = new Node<T>;
	head->prev = tail;
	head->next = tail;
	head->data = a;
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}

template <typename T>
int Deque<T>::GetSize()
{
	return count;
}

template <typename T>
void Deque<T>::pushFront(const T a)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = a;
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = tail->next = newNode;
		head = newNode;
	}
	count++;
};

template <typename T>
void Deque<T>::pushBack(const T a)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = a;
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = head->prev = newNode;
		tail = newNode;
	}
	count++;
};

template <typename T>
void Deque<T>::popFront(T& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = head->data;
		Node<T>* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		else
		{
			head->prev = tail;
			tail->next = head;
		}
		count--;
	}
};

template <typename T>
void Deque<T>::popBack(T& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = tail->data;
		Node<T>* temp = tail;
		tail = tail->prev;
		if (tail == nullptr) {
			head = nullptr;
		}
		else
		{
			tail->next = head;
			head->prev = tail;
		}
		count--;
	}
};

template <typename T>
void Deque<T>::peekFront(T& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = head->data;
	}
}

template <typename T>
void Deque<T>::peekBack(T& a)
{
	if (head == nullptr)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = tail->data;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int dsize;
	double b;
	bool flag = true;
	cout << "������� ������ ����\n";
	cin >> dsize;
	Deque<double>* a;
	a = new Deque<double>(dsize);
	while (flag)
	{
		cout << "1. �������� ������� � ������ ����\n";
		cout << "2. �������� ������� �� ������ ����\n";
		cout << "3. �������� ������� � ����� ����\n";
		cout << "4. �������� ������� �� ����� ����\n";
		cout << "5. ���������� ������� � ����� ����\n";
		cout << "6. ���������� ������� �� ����� ����\n";
		cout << "7. �����\n";
		switch (_getch())
		{
		case '1':
			cout << "�������� �������: ";
			cin >> b;
			a->pushFront(b);
			cout << "������� �������� � ������" << endl;
			break;
		case '2':
			try
			{
				a->popFront(b);
				cout << "���������� ������� " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "��� ����\n";
			}
			break;
		case '3':
			cout << "�������� �������: ";
			cin >> b;
			a->pushBack(b);
			cout << "������� �������� � ����� " << endl;

			break;
		case '4':
			try
			{
				a->popBack(b);
				cout << "���������� ������� " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "��� ����\n";
			}
			break;
		case '5':
			try
			{
				a->peekFront(b);
				cout << "���������� ������� " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "��� ����\n";
			}
			break;
		case '6':
			try
			{
				a->peekBack(b);
				cout << "���������� ������� " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "��� ����\n";
			}
			break;
		case '7':
			flag = false;
			break;

		}
	}

}