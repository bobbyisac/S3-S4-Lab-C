#include <stdio.h>

void main()
{
    int h,ht=5,w,wid=4,a,b; //intialization
    for (h=1;h<=ht;h++)//for vertical limb
    {
        printf("L\n");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=40000;b++);
    }
    for (w=1;w<=wid;w++)//for horizontal limb
    {
        printf("L");
        for (a=1;a<=3200;a++)//animated loop
            for(b=1;b<=40000;b++);
    }
}
