/*
typedef struct Node
{
	char data;
	struct Node *lchild,*rchild;
}BNode,*BiTree;//结点
*/
![二叉树中序遍历参考图.png](https://pic.leetcode-cn.com/27a54951b934d0028f62ea99095d4340b11e3cb0db4b07b0abd063a863c5c0b4-%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%8F%82%E8%80%83%E5%9B%BE.png)

void InorderTraverse(BNode *TB)//中序遍历//传入根节点的地址(左 根 右)
{
	BNode *p=TB;
	BNode *Stack[maxsize];//定义一个栈
	int top=-1;//top游标
	Stack[++top]=p;//将根节点入栈
	while(top!=-1)//判断栈空
	{
		if(p&&p->lchild)
		{
			Stack[++top]=p->lchild;先将根节点左子树全部入栈
			p=p->lchild;
		}
		else
		{
			p=Stack[top--];//出栈
			printf("%c->",p->data);
			if(p->rchild!=NULL)//判断该出栈结点的右子树
				Stack[++top]=p->rchild;
			p=p->rchild;//这里一定要放在if语句外面，不然会出错，自己画图多多尝试，我就是                        这么过来的，哈哈！
		}
//p=p->rchild;需要配合图进行讲解
	}	假如p=p->rchild放在if语句里面那就意味着有的时候右子树为空就不执行，那完蛋啦！
//如果根节点延左边都是左子树，那么在出栈的时候都要经过while，if(判断)，那么就会继续往if里面走啦！不符合我们的要求。自己画图尝试，可能我说的不是很清楚！重在画图理解
}