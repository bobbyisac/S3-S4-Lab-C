#include <stdio.h>

void main()
{
    int w,wid=10,h,ht=5,a,b;//initialization
    for (w=1;w<=wid;w++)//for upper horizontal limb
    {
        printf("[");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=40000;b++);
    }
    for (h=1;h<=ht;h++)//for vertical limb
    {
        printf("[\n");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=40000;b++);
    }
    for (w=1;w<=wid;w++)//for lower horizontal limb
    {
        printf("[");
        for (a=1;a<=3200;a++) //  animated loop
            for(b=1;b<=40000;b++);
    }
}
