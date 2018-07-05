#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 20

int push(char stack[size],int *top, char elem)
{
    (*top)++;
    stack[*top]=elem;
    return 0;
}

char pop(char stack[size],int *top)
{
    int elem;
    elem=stack[(*top)];
    (*top)--;
    return elem;
}

int getpr(char ch)
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

int main()
{
    char postfix[size],ch,infix[size]="((a+b)*c-d/e)",stack[size];
    int p, top=-1,pos=0;
    float result,op1,op2,val;

    for(p=0;infix[p]!='\0';p++)
    {
        ch=infix[p];
        if(ch=='(')
            push(stack,&top,ch);
        else if(ch==')')
        {
            ch=pop(stack,&top);
            while(ch!='(')
            {
                postfix[pos]=ch;
                pos++;
                ch=pop(stack,&top);
            }
        }
        else if(isalpha(ch))
        {
            postfix[pos]=ch;
            pos++;
        }
        else
        {
            if(ch=='*'||ch=='+'||ch=='-'||ch=='/')
            {
                while(getpr(ch)<=getpr(stack[top]))
                {
                    postfix[pos]=pop(stack,&top);
                    pos++;
                }
                push(stack,&top,ch);
            }
        }
    }
    for(p=0;p<pos;p++)
    {
        printf("%c",postfix[p]);
    }
    return 0;
}
