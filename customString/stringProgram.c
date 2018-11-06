/*Alex Sluborski
CIS 190 
Lab 7 
10/26/18
*/

#include "customString.h"
#include <stdio.h>

int main()
{
//creates string 

char string1[20];
printf("Enter first string:");
scanf("%s",string1);
//creates 2nd string 
char string2[20];
printf("Enter second string:");
scanf("%s", string2);
printf("Compare strings:");
stringCompare(string1,string2); // calls compare function
reverseString(string1); // calls reverse function
printf("\nReversed string1: %s\n",string1);
reverseString(string2);
printf("Reversed string2:%s\n",string2);
stringCompareCase(string1,string2); //calls compare case function 
return 0;

}
