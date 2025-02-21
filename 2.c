#include<stdio.h>
#include<stdlib.h>
#include<new.h>

#define CORRECT 1
#define ERROR (-1)




//不带头节点的单链表 即头指针L指向第一个节点
typedef int Elemtype;


typedef struct Node
{
	Elemtype data;
	struct Node * next;//写LNode *next会报错
}*Linlist,LNode;


LNode* search(Linlist L, int i)//返回结构体指针
{
	int j = 1;
	Linlist p;
	p = L;

	while (p && j < i)//循环i-1次，当j=i时循环结束
	{
		p = p->next;
		j++;
	}

	if (!p || j > i)
	{
		return NULL;
	}

	return p;


}
		



int insert(Linlist L, int e, int i)
{
	Linlist p, s;
	p = search(L, i - 1);
	s = (Linlist)malloc(sizeof(LNode));//写new LNode会报错，new时C++编译器中的关键字，new的作用(后接函数类型）：获得一块内存（自动计算所需内存），调用构造函数，返回正确的指针。
	s->next = p->next;
	p->next = s;
	s->data = e;
	return (CORRECT);


}

Linlist creat(int* r, int n)
{
	int j;
	Linlist L, s;
	s = (Linlist)malloc(sizeof(LNode));
	s->data = r[1-1];
	s->next = NULL;
	L = s;
	for (j = 2; j <= n; j++)
	{
		insert(L, r[j - 1], j);
	}
	return (L);

}

int delete(Linlist L, int i)
{
	int e;
	Linlist p,q;
	p = search(L, i-1);
	if (!p)
	{
		return (ERROR);
	}
	q = p->next;
	p->next = p->next->next;
	e = q->data;
	free(q);
	return e;
}

int show(Linlist L)
{
	Linlist p;
	p = L;
	while (p->next)
	{
		printf("%d ", p->data);
		p = p->next;

	}
	printf("%d\n", p->data);
	return (CORRECT);
}

int main()
{
	int r[100], capable, searchpoint,newpoint,newitem, delpoint;
	Linlist L,p;
	scanf("%d", &capable);
	int i;
	for (i = 0; i < capable; i++)
	{
		scanf("%d", &r[i]);

	}
	//创建单链表
	L = creat(r, capable);
	show(L);

	//查找数据
	scanf("%d", &searchpoint);
	p=search(L, searchpoint);
	printf("%d\n", p->data);

	//插入数据
	scanf("%d", &newpoint);
	scanf("%d", &newitem);
	insert(L, newitem, newpoint);
	show(L);

	//删除元素
	scanf("%d", &delpoint);
	delete(L, delpoint);
	show(L);
	

	return 0;
}