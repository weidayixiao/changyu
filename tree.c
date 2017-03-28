#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//二叉树节点定义
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}BTNode,*BiTree;

//先序构造二叉树
void creatBTree(BiTree *root)
{
    char data;
    scanf("%c",&data);
    if(data == '#')
	*root=NULL;
    else
    {
	*root=(BiTree)malloc(sizeof(BTNode));
	(*root)->data=data;
//	(*root)->lchild=NULL;
//	(*root)->rchild=NULL;
	creatBTree(&(*root)->lchild);
	creatBTree(&(*root)->rchild);
    }
}

//先序遍历二叉树
void preOrder(BiTree root)
{
    if(root==NULL)
	return;
    printf("%-3c",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

//中序遍历二叉树
void infixOrder(BiTree root)
{
    if(root==NULL)
	return;
    infixOrder(root->lchild);
    printf("%-3c",root->data);
    infixOrder(root->rchild);
}

//后序遍历二叉树
void afterOrder(BiTree root)
{
    if(root==NULL)
	return;
    afterOrder(root->lchild);
    afterOrder(root->rchild);
    printf("%-3c",root->data);
}

//输出叶子节点及其个数
int printleaf(BiTree root)
{
    static int count=0;
    if(root==NULL)
	return;
    if(root->lchild == NULL && root->rchild == NULL)
    {	
	printf("%-3c",root->data);
	count++;
    }
    else
	{
	    printleaf(root->lchild);
	    printleaf(root->rchild);
	
	}
    return count;
}

//二叉树深度
int TreeDepth(BiTree root)
{
    int depth=0;
    int leftdepth,rightdepth;
    if(root != NULL)
    {
	leftdepth=TreeDepth(root->lchild);
	rightdepth=TreeDepth(root->rchild);
	depth=(leftdepth >= rightdepth?(leftdepth+1):(rightdepth+1));
    
    }
    return depth;
}

//所有节点个数
int countAllNode(BiTree root)
{
    int	allcount=0; 
    if(root==NULL)
	return 0;
    allcount=countAllNode(root->lchild)+countAllNode(root->rchild)+1;
    return allcount;
}

//销毁二叉树
void DestroyTree(BiTree *root)
{
    BiTree pl,pr;
    if(*root==NULL)
	return;
    pl=(*root)->lchild;
    pr=(*root)->rchild;
    (*root)->lchild=NULL;
    (*root)->rchild=NULL;
    free((*root));
    *root=NULL;
    DestroyTree(&pl);
    DestroyTree(&pr);

}

//销毁左子树
void DestroyleftTree(BiTree *root)
{
    if(*root==NULL)
	return;
    DestroyTree(&(*root)->lchild);
    (*root)->lchild=NULL;
}

//销毁右子树
void DestroyrightTree(BiTree *root)
{
    if(*root==NULL)
	return;
    DestroyTree(&(*root)->rchild);
    (*root)->rchild=NULL;
}

int main()
{
    BTNode *root;
    int depth=0;
    int leafcount=0;

    creatBTree(&root);

    printf("\nPreorder traversal binary tree:\n");
    preOrder(root);

    printf("\ninfixOrder traversal binary tree:\n");
    infixOrder(root);

    printf("\nafterOrder traversal binary tree:\n");
    afterOrder(root);
    
    printf("\nthe leafnode are:\n");
    leafcount= printleaf(root);
    printf("\nthe counts of the binary tree are:%d\n",leafcount);

    depth=TreeDepth(root);
    printf("\nthe depth of the binary tree is:%d\n",depth);

    printf("\nDestroy the tree\n");
    DestroyTree(&root);
    
//   DestroyleftTree(&root);
//   printf("\nDestroy the left tree\n");
#if 0    
    printf("\nthe new tree is\n");
    preOrder(root);
    printf("\n");
#endif
    return 0;
}
