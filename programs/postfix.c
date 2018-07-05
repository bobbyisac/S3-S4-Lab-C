#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 20

int push(int stack[size],int *top, int elem)
{
    (*top)++;
    stack[*top]=elem;
    return 0;
}

int pop(int stack[size],int *top)
{
    int elem;
    elem=stack[(*top)];
    (*top)--;
    return elem;
}

float getval(char ch)
{
    float elem;
    printf("Enter value of %c:",ch );
    scanf("%f",&elem);
    return elem;
}

int main()
{
    int p, top=-1,stack[size];
    float result,op1,op2,val;
    //-------------------------------



    //-------------------------------
    for(p=0;postfix[p]!='\0';p++)
    {
        ch=postfix[p];
        if(isalpha(ch))
        {
            val=getval(ch);
            push(stack, &top, val);
        }
        else
        {
            if(ch=='*')
            {
                op2=pop(stack, &top);
                op1=pop(stack, &top);
                result=op1*op2;
                push(stack, &top, result);
            }
            else if(ch=='/')
            {
                op2=pop(stack, &top);
                op1=pop(stack, &top);
                result=op1/op2;
                push(stack, &top, result);
            }
            else if(ch=='+')
            {
                op2=pop(stack, &top);
                op1=pop(stack, &top);
                result=op1+op2;
                push(stack, &top, result);
            }
            else if(ch=='-')
            {
                op2=pop(stack, &top);
                op1=pop(stack, &top);
                result=op1-op2;
                push(stack, &top, result);

            }
        }
    }
    printf("Result is: %f",result);
    return 0;
}
