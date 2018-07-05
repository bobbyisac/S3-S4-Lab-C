#include <stdio.h>

 void main()
 {
     int w,wid=17,h,ht=21;//initialization
     for (w=1;w<=wid;w++)//for upper horizontal limb
     {
         printf("E");
     }
     for (h=1;h<=((ht-3)/2);h++)//for upper vertical limb
     {
         printf("\nE");
     }
     printf("\n");//to go to next line
     for (w=1;w<=wid;w++)//for middle horizontal limb
     {
         printf("E");
     }
     for (h=1;h<=((ht-3)/2);h++)//for lower vertical limb
     {
         printf("\nE");
     }
     printf("\n");//to go to next line
     for (w=1;w<=wid;w++)//for lower vertical limb
     {
         printf("E");
     }

 }
