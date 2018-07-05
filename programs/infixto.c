#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 20

int push2(int stack[size],int *top, int elem)
{
    (*top)++;
    stack[*top]=elem;
    return 0;
}

int pop2(int stack[size],int *top)
{
    int elem;
    elem=stack[(*top)];
    (*top)--;
    return elem;
}

float getval(char ch)
{
    float elem;
    printf("\nEnter value of %c:",ch );
    scanf("%f",&elem);
    return elem;
}


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
        break;
    case '*':
    case '/':
        return 2;
        break;
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
    printf("The postfix expression is : ");
    for(p=0;p<pos;p++)
    {
        printf("%c",postfix[p]);
    }
    postfix[p]=NULL;
    top=-1;
    int stk[size];
    for(p=0;postfix[p]!='\0';p++)
    {
        ch=postfix[p];
        if(isalpha(ch))
        {
            val=getval(ch);
            push2(stack, &top, val);
        }
        else
        {
            if(ch=='*')
            {
                op2=pop2(stack, &top);
                op1=pop2(stack, &top);
                result=op1*op2;
                push2(stack, &top, result);
            }
            else if(ch=='/')
            {
                op2=pop2(stack, &top);
                op1=pop2(stack, &top);
                result=op1/op2;
                push2(stack, &top, result);
            }
            else if(ch=='+')
            {
                op2=pop2(stack, &top);
                op1=pop2(stack, &top);
                result=op1+op2;
                push2(stack, &top, result);
            }
            else if(ch=='-')
            {
                op2=pop2(stack, &top);
                op1=pop2(stack, &top);
                result=op1-op2;
                push2(stack, &top, result);

            }
        }
    }
    printf("Result is: %f",result);

    return 0;
}
