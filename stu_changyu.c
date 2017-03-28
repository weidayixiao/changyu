#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int num;
	char name[10];
	struct node *prior,*next;
}Node;

Node *creat_list()
{	
	printf("\n------------------------------------\n");
	Node *head,*p1,*p2;
	int n,i;
	head=(Node *)malloc(sizeof(Node));
	head->prior=head;
	head->next=head;
	p1=head;
	printf("please input the length of list:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
//		printf("please input the number of student%d\n ",i+1);
		p2=(Node *)malloc(sizeof(Node));
		printf("input name of student:");
//		printf("input name of student:");
		scanf("%s",p2->name);
		printf("input num of  student:");
		scanf("%d",&(p2->num));
		p1->next=p2;
		p2->prior=p1;
		p2->next=head;
		head->prior=p2;
		p1=p1->next;
		

	}
	return head;//返回链表	
}
#if 1
int printf_list(Node *head)
{
    printf("\n------------------------------------\n");
    Node *p = head;
    if(p->next == head)
{	
	return 0;	
}
	p=p->next;
   while(p->next != head)
    {
        printf("%s %d\n", p->name,p->num);
        p = p->next;
    }
    printf("%s %d\n", p->name,p->num);	
    printf("\n");
}
#endif
#if 0
void printf_list(Node *q)
{
	printf("the list of student's information are as following:\n");
	Node *p;
	int i;
	p=q;
	p=p->next;
	while(p!=q)
	{
		printf("%s,%d\n",p->name,p->num);
		p=p->next;
	}	


}
#endif
#if 1
void sort_list(Node **head)
{	
	printf("\n------------------------------------\n");	
	printf("the sort of the list is as following:\n");
	Node *p1,*p2,tmp;
	p1=*head;
	p1=p1->next;
while(p1->next!=*head)
{
	p2=p1->next;
	while(p2!=*head)
	{	
		if(p1->num > p2->num)
		{
			tmp.num=p1->num;
			p1->num=p2->num;
			p2->num=tmp.num;
			strcpy(tmp.name,p1->name);
			strcpy(p1->name,p2->name);
			strcpy(p2->name,tmp.name);
		}
		p2=p2->next;

	}
	p1=p1->next;	
}	
	p1=NULL;
}
#endif
#if 1
void del_list(Node *head)
{	
	printf("\n------------------------------------\n");
	printf("delete the odd number of the list:\n");
	Node *ps,*del;
	ps=head;
	ps=ps->next;
while (ps!=head)
{
	if((ps->num)%2)
	{
		ps->prior->next=ps->next;
		ps->next->prior=ps->prior;
		del=ps->next;
		free(ps);
		ps=del;	
	}
	else
	{
		ps=ps->next;

	}
}
	ps=NULL;
	del=NULL;	
}




#endif
int main()
{
	Node *l;
	l=creat_list();
	printf("creat list success\n");
	printf_list(l);
	sort_list(&l);
	printf_list(l);
	del_list(l);
	printf_list(l);
	return 0;
}
