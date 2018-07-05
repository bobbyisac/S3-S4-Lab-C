#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 20

void push2(int *stk,int *top,int n)
{
    (*top)++;
    stk[*top]=n;

}

int pop2 (int *stk, int *top)
{
    int elem;
    elem=stk[*top];
    (*top)--;
    return elem;
}
void push(char *stack,int *top,char elem)
{
    (*top)++;
    stack[*top]=elem;

}

char pop (char *stack, int *top)
{
    int elem;
    elem=stack[*top];
    (*top)--;
    return elem;
}

int getpriority(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0;
    }
}
int getval(char ch)
{
    int elem;
    printf("\nEnter val for %c:",ch);
    scanf("%d",&elem);
    return elem;
}
void main()
{
    char inf[size]="((a+b)*c-d/e)",stack[size],pf[size],ch;
    int p,top=-1,pos=0,i;
    for(p=0;inf[p]!='\0';p++)
    {
        ch=inf[p];
        if(ch=='(')
            push(stack,&top,ch);
        else if (ch==')')
        {
            ch=pop(stack,&top);
            while(ch!='(')
            {
                pf[pos]=ch;
                pos++;
                ch=pop(stack,&top);
            }

        }
        else if(isalpha(ch))
        {
            pf[pos]=ch;
            pos++;
        }
        else
        {
            if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
            {
                while(getpriority(ch)<=getpriority(stack[top]))
                {
                    pf[pos]=pop(stack,&top);
                    pos++;
                }
                push(stack,&top,ch);
            }
        }
    }
    printf("The postfix expression is:");
    for(i=0;i<pos;i++)
    {
        printf("%c",pf[i]);
    }
    pf[i]=NULL;
    top=-1;
    int result,op1,op2,stk[size],val;
    for(p=0;pf[p]!='\0';p++)
    {
        ch=pf[p];
        if(isalpha(ch))
        {
            val=getval(ch);
            push2(stk,&top,val);
        }
        else
        {
            op1=pop2(stk,&top);
            op2=pop2(stk,&top);
            if(ch=='*')
            {
                //op1=pop2(stk,&top);
                //op2=pop2(stk,&top);
                result=(op2*op1);
                //push2(stk,&top,result);
            }
            else if(ch=='+')
            {
                //op1=pop2(stk,&top);
                //op2=pop2(stk,&top);
                result=(op2+op1);
                //push2(stk,&top,result);
            }
            else if(ch=='-')
            {
                //op1=pop2(stk,&top);
                //op2=pop2(stk,&top);
                result=(op2-op1);
                //push2(stk,&top,result);
            }
            else if(ch=='/')
            {
                //op1=pop2(stk,&top);
                //op2=pop2(stk,&top);
                result=(op2/op1);
                //push2(stk,&top,result);
            }
            push2(stk,&top,result);

        }
    }
    printf("Result is:%d",result);

}

