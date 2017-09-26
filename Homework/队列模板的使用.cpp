#include<iostream>
using namespace std;
template<class T>
struct quenode                   //定义队列中的各节点类型
{
	T nodedata;
	quenode *next;
};

template<class T>                //函数模板
class queue
{
private:
protected:
	int quesize;                 //定义队列长度
	quenode<T> *head;            //定义队列头
	quenode<T> *tail;            //定义队列尾
	bool allocateerror;
	queue &copy(queue &q);       //队列拷贝函数
public:
	queue();
	queue(queue &q)              //将q赋给当前队列
	{
		head = NULL;
		tail = NULL;
		copy(q);
	}
	~queue()
	{
		clearque();
	}
	bool getallocateerror()
	{
		return allocateerror;
	}
	void push(T &);               //插入函数，将元素插入队尾
	bool pop(T &);                //提取函数，从队头提取元素
	bool isempty()                //判断队列是否为空
	{
		return(quesize == 0) ? true : false;
	}
	void clearque();              //清空队列
	queue &operator=(queue &q)    //定义重载赋值运算符
	{                             //用来进行同类队列之间的复制
		copy(q);
		return *this;
	}
};

template<class T>
queue<T>::queue()                 //定义构造函数
{
	quesize = 0;
	allocateerror = false;
	head = NULL;
	tail = NULL;
}
template<class T>
queue<T>&queue<T>::copy(queue<T>&que)
{                                 //将队列que赋值给当前队列对象
	quenode<T> *p, *q, *r;       
	if (head) clearque();
	quesize = que.quesize;        //传递队列长度
	allocateerror = false;
	head = NULL;
	tail = NULL;
	if (!que.head)                //若队列为空，则返回
		return *this;
	head = new quenode<T>;        //为当前队列头结点分配储存
	if (!head)                    //若分配失败，则返回
	{
		allocateerror = true;
		return *this;
	}
	head->nodedata = que.head->nodedata;//将que队列的头结点内容赋给当前队列头结点
	head->next = NULL;
	tail = head;                  //将队列头和尾均指向此节点
	r = NULL;            
	p = head;                     //p指针指向当前队列头
	q = que.head->next;           //将指向que队列第二个节点的指针赋给q
	while (q)                     //循环进行后序节点间的赋值
	{                             //为节点r分配存储
		r = new quenode<T>;
		if (!r)
		{
			allocateerror = true;
			return *this;
		}
		r->nodedata = q->nodedata;
		r->next = NULL;
		p->next = r;              //将节点r链接到当前队列的链上
		tail = r;                 //队列指针指向r，因为r为最后一个元素
		p = p->next;              //指针后移
		q = q->next;
	}
	return *this;
}

template<class T>
void queue<T>::push(T &x)         //向队尾插入元素
{
	quenode<T> *p;         
	p = new quenode<T>;           //为p节点分配存储
	if (!p)                       //若分配失败，则返回
	{
		allocateerror = true;
		return;
	}
	p->nodedata = x;
	if (tail)
	{
		p->next = NULL;           //若队列非空
		tail->next = p;           //将p节点链接到尾指针tail后
		tail = p;                 //修改队尾指针
	}
	else
	{
		p->next = NULL;           //若队列为空
		tail = p;                 //p节点为队列的头，又为尾
		head = p;
	}
	quesize++;                    //长度加一
}

template<class T>
bool queue<T>::pop(T &x)          //从队头取一节点
{
	quenode<T> *p;
	if (head)                     //若队列非空
	{                             //将队头的数据内容赋给x
		x = head->nodedata;
		p = head;
		head = head->next;        //修改队头指针
		if (head == NULL)         //若队列已删空，则tail也该为NULL
			tail = NULL;
		delete p;                 //删除原头结点
		quesize--;                //长度减一
		return true;
	}
	return false;
}

template<class T>
void queue<T>::clearque()         //将队列清空
{
	T p;
	allocateerror = false;
	while (pop(p));               //循环提取队列中各元素，实现清除
	head = tail = NULL;
}

class staff                       //定义职工类
{
public:
	char name[80];
	int age;
	float salary;
	char sex[8];
	void assign(char *name, int age, float salary, char *sex)
	{
		strcpy_s(staff::name, name);
		staff::age = age;
		staff::salary = salary;
		strcpy_s(staff::sex, sex);
	}
	void print()
	{
		printf("%10s%6d%10.2f%8s\n", name, age, salary, sex);
	}
};

void viewque(queue<staff>&que)    //显示实例化后的队列que中的各元素
{
	int i = 1;
	staff p;
	queue<staff>quecopy(que);
	system("cls");
	while (quecopy.pop(p))        //循环提取队列中各元素
	{
		printf("%2d:", i++);
		p.print();
	}
}

int main()
{
	queue<staff>que;
	staff p;
	p.assign("Chenweilin", 47, 1500, "male");
	que.push(p);
	p.assign("Wangling", 34, 850.5, "male");
	que.push(p);
	p.assign("Zhangdaling", 27, 1200, "male");
	que.push(p);
	p.assign("Fanglibida", 51, 2000, "female");
	que.push(p);
	viewque(que);
	system("pause");
	return 0;
}