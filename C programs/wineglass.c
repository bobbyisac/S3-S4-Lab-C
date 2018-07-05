#include <stdio.h>

void main()
{
    int l,left=40,t,top=1,h,ht=12,w,wid=7,s,sp,d,de;
    for(ht=12;ht<=20;ht++)
    {
        printf("\n");
        wid=(float)3/4*ht;
        for(h=1;h<=(ht-2)/2;h++)
        {
            for(sp=1;sp<=20;sp++)
                printf(" ");
            printf("U");//left most side
            for(sp=1;sp<=wid-2;sp++)//space for the width of the glass
                printf(" ");
            printf("U\n");//right U
        }
        for(sp=1;sp<=20;sp++)
            printf(" ");
        for(w=1;w<=wid;w++)//for middle horizontal
            printf("U");
        printf("\n");
        for(h=1;h<=(ht-2)/2;h++)
        {
            for(sp=1;sp<=20;sp++)
                printf(" ");
            for(sp=1;sp<=wid/2;sp++)//for middle vertical
                printf(" ");
            printf("I\n");
        }
        for(sp=1;sp<=20;sp++)
            printf(" ");
        for(w=1;w<=wid;w++)
            printf("I");
        printf("\n");
        for (d=1;d<=3200;d++)
            for (de=1;de<=45000;de++);
    }
}
