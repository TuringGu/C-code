#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class list                           //声明一个抽象类
{
public:
	list *head;                      //表头指针
	list *tail;                      //表尾指针
	list *next;
	int num;
	list()
	{
		head = tail = next = NULL;
	}
	virtual void store(int i) = 0;   //纯虚函数store
	virtual int retrieve() = 0;      //纯虚函数retrieve
};

class queue :public list             //声明公有派生类queue
{
public:
	void store(int i);
	int retrieve();
};

void queue::store(int i)             //定义虚函数store
{
	list *item;
	item = new queue;
	if (!item)
	{
		cout << "Allocation error\n";
		exit(1);
	}
	item->num = i;
	if (tail) tail->next = item;
	tail = item;
	item->next = NULL;
	if (!head) head = tail;
}

int queue::retrieve()                 //定义虚函数retrieve
{
	int i;
	list *p;
	if (!head)
	{
		cout << "list empty\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}

class stack :public list              //声明公有派生类stack
{
public:
	void store(int i);
	int retrieve();
};

void stack::store(int i)              //定义虚函数store
{
	list *item;
	item = new stack;
	if (!item)
	{
		cout << "Allocation error\n";
		exit(1);
	}
	item->num = i;
	if (head) item->next = head;
	head = item;
	if (!tail) tail = head;
}

int stack::retrieve()                  //定义虚函数retrieve
{
	int i;
	list *p;
	if (!head)
	{
		cout << "list empty\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}



//主程序
int main() 
{
	list *p;                           //定义指向抽象类list的指针p
	queue q_ob;
	p = &q_ob;                         //对象指针p指向类queue的对象q_ob
	p->store(1);
	p->store(2);
	p->store(3);
	cout << "queue: ";
	cout << p->retrieve();
	cout << p->retrieve();
	cout << p->retrieve();
	cout << '\n';
	stack s_ob;
	p = &s_ob;                         //对象指针p指向类stack的对象s_ob
	p->store(1);
	p->store(2);
	p->store(3);
	cout << "Stack: ";
	cout << p->retrieve();
	cout << p->retrieve();
	cout << p->retrieve();
	cout << '\n';
		Sleep(40000);
	return 0;
}