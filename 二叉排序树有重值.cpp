// 二叉排序树有重值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
typedef struct BitNode 
{
	int data;
	struct BitNode *lchild,*rchild;
	int num;
}BitNode,*BitTree;
class BitSortTree//BST
{
private:
	BitTree root;
	int num;
public:
	BitSortTree(int n);
	BitSortTree(const BitSortTree &T);
	~BitSortTree();
	void creat_BIT(int data[]);
	void insert_BIT(int data);
	int insert_repeat(BitTree &T, int data);//新的插入算法
	//int insert(BitTree &T, int data);
	void search_BIT(int data);
	BitNode *BITsearch(int data);
	void inorder_BIT();
	void inorder(BitTree &T);
	void visit(BitTree T);
};
BitSortTree::BitSortTree(int n)
{
	root = NULL;
	num = n;
}
BitSortTree::~BitSortTree()
{
	free(root);
	root = NULL;
	num = 0;
}
void BitSortTree::creat_BIT(int data[])
{
	int i;
	for (i = 0; i<num; i++)
	{
		insert_BIT(data[i]);
	}
}
void BitSortTree::insert_BIT(int data)
{
	insert_repeat(root, data);
}
/*int BitSortTree::insert(BitTree &T, int data)
{
	if (T == NULL)//如果第一个是空 就是root 遍历到后面 同理
	{
		T = (BitTree)malloc(sizeof(BitNode));
		T->data = data;
		//cout<<data<<"插入成功  ";
		T->lchild = T->rchild = NULL;//very important
		return 1;
	}
	else if (data == T->data)
	{
		cout << "what the fuck two keys r same" << endl;
		return 0;
	}
	else if (data<T->data)//lchild is smallest
	{
		return insert(T->lchild, data);
	}
	else
	{
		return insert(T->rchild, data);
	}
};
*/
int BitSortTree::insert_repeat(BitTree &T, int data)
{
	if (T == NULL)//如果第一个是空 就是root 遍历到后面 同理
	{
		T = (BitTree)malloc(sizeof(BitNode));
		T->data = data;
		T->lchild = T->rchild = NULL;//very important
		T->num = 1;
		return 1;
	}
	else if (data == T->data)//重复节点
	{
		T->num++;
		return 0;
	}
	else if (data<T->data)//lchild is smallest
	{
		return insert_repeat(T->lchild, data);
	}
	else
	{
		return insert_repeat(T->rchild, data);
	}
};
void BitSortTree::search_BIT(int data)
{
	BitTree T;
	T = BITsearch(data);
	if (T == NULL)
	{
		cout << "no this data on this tree" << endl;
	}
	else
	{
		cout << " Bingo! " << endl;
		cout << "一共有"<<T->num<<"个" << endl;
	}
}
BitNode *BitSortTree::BITsearch(int data)
{
	BitTree T = root;
	while (T != NULL&&data != T->data)
	{
		if (data>T->data)
		{
			T = T->rchild;
		}
		else
		{
			T = T->lchild;
		}
	}
	return T;
}
void BitSortTree::inorder_BIT()
{
	//cout<<"inorder_BIT()"<<endl;
	//cout<<"root="<<root->data;
	inorder(root);
}
void BitSortTree::inorder(BitTree &T)
{
	if (T != NULL)
	{
		inorder(T->lchild);
		visit(T);
		//cout<<T->data<<" ";
		inorder(T->rchild);
	}
	//else{cout<<"NULL"<<endl;}
}

void BitSortTree::visit(BitTree T)
{
	cout << T->data << " ";
}
int main(int argc, const char * argv[])
{
	int n; int data[100];
	int data_x;
	//本题错因 树的初始化和num初始化顺序
	//BitSortTree *T=new BitSortTree(n);
	cout << "please input the number of this tree" << endl;
	cin >> n;
	BitSortTree *T = new BitSortTree(n);
	cout << "please input datas that u intend to insert into the tree" << endl;
	for (int i = 0; i<n; i++)
	{
		cin >> data[i];
	}
	T->creat_BIT(data);
	T->inorder_BIT();
	cout << endl;
	cout << "插入新的节点 允许有重复"<< endl;
	cin >> data_x;
	T->insert_BIT(data_x);
	cout << "please input the data which u intend to find" << endl;
	cin >> data_x;
	T->search_BIT(data_x);
	delete T;
	T = NULL;
	_getch();
	return 0;
}


