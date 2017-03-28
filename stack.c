#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int SElemType;//SElemType���͸���ʹ���������

/* ��ջ�ṹ */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

/* ����һ����ջ */
int InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
    {
	return 0;
    }
    S->top=NULL;
    S->count=0;
    return 1;
}

/* ��S��Ϊ��ջ */
int ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p=S->top;
    while(p)
	{
	    q=p;
	    p=p->next;
	    free(q);

	}
    S->count=0;
}

/* �ж�S�Ƿ�Ϊ��ջ */
int IfEmptyStack(LinkStack S)
{
   if(S.count==0)
   {
	return 1;
   }
   else
   {
	return 0; 
   }
}

/* ����ջ�ĳ��� */
int GetStacklength(LinkStack S)
{
    return S.count;
}

/* ��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ����ҷ���1�����򷵻�0 */
int GetStackTopElem(LinkStack S,SElemType *e)
{
    if(S.top==NULL)
    {
	return 0;
    }
    else
    {
	*e=S.top->data;
    }
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
int Push(LinkStack *S,SElemType e)
{
    LinkStackPtr new;
    new=(LinkStackPtr)malloc(sizeof(StackNode));
    if(!new)
    {
	return 0;
    }
    new->data=e;
    new->next=S->top;
    S->top=new;
    S->count++;
    return 1;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������1�����򷵻�0 */
int Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;
    if(IfEmptyStack(*S))
    {
	return 0;
    }
    *e=S->top->data;
    p=S->top;
    S->top=S->top->next;
    free(p);
    S->count--;
    return 1;
}

int StackTraverse(LinkStack S)  
{  
        LinkStackPtr p;  
	p=S.top;  
	while(p)  
	{  
	    printf("%5d",p->data);  
	    p=p->next;  
	}  
	printf("\n");  
	return 1;  
}

int main()
{
    int i,n,e;
    printf("\nplease input the length of the Stack:");
    scanf("%d",&n);
    LinkStack s;
    if(InitStack(&s))
    {
	for(i=1;i<=n;i++)
	    {    
		Push(&s,i);
    
	    }
    }
    printf("\nthe elements of the Stack are:");
    StackTraverse(s);
    Pop(&s,&e);
    printf("\npop the top element\n");
    printf("\nthe poped element is:%d\n",e);
    printf("\nIs the Stack empty? %d(1:yes 0:no)\n",IfEmptyStack(s));
    GetStackTopElem(s,&e);
    printf("\nthe top stack element is %d\n",e);
    printf("\nthe length of the Stack is %d\n",GetStacklength(s));
    ClearStack(&s);
    printf("\nafter clear,is the Stack empty? %d(1:yes 0:no)\n",IfEmptyStack(s));
    
    return 0; 

}
