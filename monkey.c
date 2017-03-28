#include <stdio.h>
#include <stdlib.h>

typedef struct node//定义链表节点类型
{
    int data;
    struct node *next;
}linklist;

void List(int n,int k,int m)
{
    int i ,total;
    linklist *head, *p, *s, *q;
/*  printf("请输入猴子总数:");// 读入问题条件
    scanf("%d", &n);
    printf("请输入开始计数的猴子位置:");
    scanf("%d", &k);
    printf("请输入循环数:");
    scanf("%d", &m);*/
    head = (linklist*)malloc(sizeof(linklist));   // 创建循环链表，头节点也存信息
#if 1    
    p = head;
    p->data = 1;
    p->next = p;
      for (i = 2; i <= n; i++) //初始化循环链表
    {
        s = (linklist*)malloc(sizeof(linklist));
        s->data = i;
        s->next = p->next;
        p->next = s;
        p = p->next;
    }
    p = head;
    for (i = 1; i < k; i++)   //找到第 k 个节点
    {
        p = p->next;
    }
    total = n;         // 保存节点总数
    printf("\nthe eliminated monkeys are:");
    q = head;
    while (total != 1)    // 只剩一个节点时停止循环
    {
        for (i = 1; i < m; i++)     // 报数过程，p指向要删除的节点
        {
            p = p->next;
        }
        printf("[%d] ", p->data);   // 打印要删除的节点序号
        while (q->next != p)    // q 指向 p 节点的前驱
        {
            q = q->next;
        }
        q->next = p->next;   // 删除 p 节点
        s = p;        // 保存被删除节点指针
        p = p->next;  // p 指向被删除节点的后继
        free(s);     // 释放被删除的节点
        total--;     // 节点个数减一
    }
    printf("\nthe monkeyking is number [%d] \n", p->data);// 打印最后剩下的节点序号
    free(p);
#endif
}

int main()
{
    printf("\n------------------------------------\n");
    int num1,num2,num3;
    printf("please input the total number of monkeys:");// 读入问题条件
    scanf("%d", &num1);
    printf("please input the beginning location of the monkey:");
    scanf("%d", &num2);
    printf("please input the recurring number:");
    scanf("%d", &num3);
    List(num1,num2,num3);   
    return 0; 
}
