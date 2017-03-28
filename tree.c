#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�������ڵ㶨��
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}BTNode,*BiTree;

//�����������
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

//�������������
void preOrder(BiTree root)
{
    if(root==NULL)
	return;
    printf("%-3c",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

//�������������
void infixOrder(BiTree root)
{
    if(root==NULL)
	return;
    infixOrder(root->lchild);
    printf("%-3c",root->data);
    infixOrder(root->rchild);
}

//�������������
void afterOrder(BiTree root)
{
    if(root==NULL)
	return;
    afterOrder(root->lchild);
    afterOrder(root->rchild);
    printf("%-3c",root->data);
}

//���Ҷ�ӽڵ㼰�����
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

//���������
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

//���нڵ����
int countAllNode(BiTree root)
{
    int	allcount=0; 
    if(root==NULL)
	return 0;
    allcount=countAllNode(root->lchild)+countAllNode(root->rchild)+1;
    return allcount;
}

//���ٶ�����
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

//����������
void DestroyleftTree(BiTree *root)
{
    if(*root==NULL)
	return;
    DestroyTree(&(*root)->lchild);
    (*root)->lchild=NULL;
}

//����������
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
