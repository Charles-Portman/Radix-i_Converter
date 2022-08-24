#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Charles Portman"
#define YEAR "2022"

void Dec2RadixI(int decValue, int radValue, char * str, int size){
    int k = 0;
    int t;
    int d = decValue;
    char base_chars[] = "0123456789abcdef";
    while (d != 0)
    {
            //find the radix digit at k
            t = d%radValue;
            d = d - t;
            d = d/radValue;
            //printf("%d",t);
            //convert the radix digit to char and put into str array
            str[size-k-1] = base_chars[t];
            k = k + 1;
    }

}
int main()
{
    //Display Startup message
    printf("*****************************\n");
    printf("%s\n",TITLE);
    printf("Written by: %s\n",AUTHOR);
    printf("Date: %s\n",YEAR);
    printf("*****************************\n");
    //Get decimal number an initial time
    printf("Enter a decimal number: ");
    int decValue;
    int radValue;
    scanf("%d",&decValue);
    //Check if exit condition to continue
    while (decValue > -1) {
        if (decValue == 0)
        {
            printf("The number you have entered is %d\n",decValue);
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d",&radValue);
            printf("The radix you have entered is %d\n",radValue);
            printf("The log2 of the number is 0\n");
            if (radValue == 0)
            {
                printf("The integer result of the number divided by %d is 0\n",radValue);
                printf("The remainder is 0\n");
                printf("The radix-%d value is 0\n");
            }
            else
            {
                printf("The integer result of the number divided by %d is %d\n",radValue,decValue/radValue);
                printf("The remainder is %d\n",decValue%radValue);
                printf("The radix-%d value is 0\n",radValue);
            }
        }
        else
        {
            printf("The number you have entered is %d\n",decValue);
            //Get the radix number
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d",&radValue);
            printf("The radix you have entered is %d\n",radValue);
            //Print the log2 of the number
            printf("The log2 of the number is %.2f\n",log(decValue)/log(2));
            //Print the number divided by the radix
            if (radValue == 0)
            {
                printf("The integer result of the number divided by %d is 0\n",radValue);
                printf("The remainder is 0\n");
                printf("The radix-%d value is 0\n");
            }
            else
            {
                printf("The integer result of the number divided by %d is %d\n",radValue,decValue/radValue);
                printf("The remainder is %d\n",decValue%radValue);
                //get the radix i value and print
                //int size = 16;
                int size = log(decValue)/log(radValue)+1;
                char arr[size];
                //char *pnt = *arr;
                Dec2RadixI(decValue,radValue,arr,size);
                printf("The radix-%d value is ",radValue);
                for (int k =0;k<size;k++)
                {
                    printf("%c",arr[k]);
                }
                printf("\n");
            }
        }
        //Get decimal number
        printf("Enter a decimal number: ");
        scanf("%d",&decValue);
    }
    //exit condition met print exit and end
    {
        printf("EXIT");
    }
    return 0;
}
