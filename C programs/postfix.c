#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 20

void push(int *stack,int *top,int n)
{
    (*top)++;
    stack[*top]=n;

}

int pop (int *stack, int *top)
{
    int elem;
    elem=stack[*top];
    (*top)--;
    return elem;
}

int getval(char ch)
{
    int elem;
    printf("Enter val for %c:",ch);
    scanf("%d",&elem);
    return elem;
}
void main()
{
    char pf[size]="abc*+",ch;
    int result,p,top=-1,op1,op2,stack[size],val;
    for(p=0;pf[p]!='\0';p++)
    {
        ch=pf[p];
        if(isalpha(ch))
        {
            val=getval(ch);
            push(stack,&top,val);
        }
        else
        {
            if(ch=='*')
            {
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                result=(op2*op1);
                push(stack,&top,result);
            }
            else if(ch=='+')
            {
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                result=(op2+op1);
                push(stack,&top,result);
            }
            else if(ch=='-')
            {
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                result=(op2-op1);
                push(stack,&top,result);
            }
            else if(ch=='/')
            {
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                result=(op2/op1);
                push(stack,&top,result);
            }

        }
    }
    printf("Result is:%d",result);

}
