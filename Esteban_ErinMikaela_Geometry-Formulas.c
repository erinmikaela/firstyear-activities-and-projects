#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    printf("\tMenu \n");
    printf("\tPress 1: Area of Rectangle\n");
    printf("\tPress 2: Area of Triangle\n");
    printf("\tPress 3: Area of Parallelogram\n");
    printf("\tPress 4: Area of Trapezoid\n");
    printf("\tPress 5: Volume of Rectangular Solid\n");
    printf("\t Enter your choice:");
    scanf("%i",&choice);
    switch(choice)
    {
        case 1:
            {
            float length, width;
            float area;
            printf("Finding the area of Rectangle");
            printf("\n   A=l*w\n");
            printf("\n\nEnter the value of length:");
            scanf("%f", &length);
            printf("Enter value of width:");
            scanf("%f", &width);
            area=length*width;
            printf("\nThe area is= %.1f", area); break;
            }
        case 2:
            {
                 float base, height, area;
                 printf("Finding the area of Parallelogram");
                 printf("\n   A=b*h\n");
                 printf("\n\nEnter the value of base:");
                 scanf("%f", &base);
                 printf("Enter the value of height:");
                 scanf("%f", &height);
                 area=base*height;
                 printf("\nThe area is= %.1f", area); break;
            }
        case 3:
            {
                float base1, base2, height, area;
                printf("FInding the area of Trapezoid");
                printf("\n   A=[(b1+b2)/2*h]");
                printf("\n\nEnter the value of");
                printf("\n1st base:");
                scanf("%f", &base1);
                printf("2nd base:");
                scanf("%f", &base2);
                printf("Height:");
                scanf("%f", &height);
                area= ((base1+base2)/2 *height);
                printf("\nThe area is= %.1f", area); break;
            }
        case 4:
            {
               float base, height, area;
               printf("Finding the area of Triangle");
               printf("\n   A=1/2bh");
               printf("\n\nEnter the value of base:");
               scanf("%f", &base);
               printf("Enter the value of height:");
               scanf("%f", &height);
               area= (base*height) /2;
               printf("\nThe area is= %.1f", area);break;
            }
        case 5:
           {
               float length, width, height;
               float volume;
               printf("Finding the volume of a Rectangular Solid");
               printf("\n   V=l*w*h");
               printf("\n\nEnter value of the following");
               printf("\nLength:");
               scanf("%f", &length);
               printf("Width:");
               scanf("%f", &width);
               printf("Height:");
               scanf("%f", &height);
               volume=length*width*height;
               printf("\nThe total volume is= %.1f", volume);break;
           }
        default:
            {
                printf("Invalid Choice\n"); break;
            }

    }
}
