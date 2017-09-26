#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class list                           //����һ��������
{
public:
	list *head;                      //��ͷָ��
	list *tail;                      //��βָ��
	list *next;
	int num;
	list()
	{
		head = tail = next = NULL;
	}
	virtual void store(int i) = 0;   //���麯��store
	virtual int retrieve() = 0;      //���麯��retrieve
};

class queue :public list             //��������������queue
{
public:
	void store(int i);
	int retrieve();
};

void queue::store(int i)             //�����麯��store
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

int queue::retrieve()                 //�����麯��retrieve
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

class stack :public list              //��������������stack
{
public:
	void store(int i);
	int retrieve();
};

void stack::store(int i)              //�����麯��store
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

int stack::retrieve()                  //�����麯��retrieve
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



//������
int main() 
{
	list *p;                           //����ָ�������list��ָ��p
	queue q_ob;
	p = &q_ob;                         //����ָ��pָ����queue�Ķ���q_ob
	p->store(1);
	p->store(2);
	p->store(3);
	cout << "queue: ";
	cout << p->retrieve();
	cout << p->retrieve();
	cout << p->retrieve();
	cout << '\n';
	stack s_ob;
	p = &s_ob;                         //����ָ��pָ����stack�Ķ���s_ob
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