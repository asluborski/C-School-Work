/*Alex Sluborski
Homework 2 Part 3
10/18/18
*/

#include <stdio.h>
#include <stdlib.h>

//function that prints 3 largest numbers 
void printer(int* firstNum,int* secondNum,int* thirdNum,int* firstNumCount,int* secondNumCount,
int* thirdNumCount)
{
    printf("The first largest number is %d with number of occurrences %d\n",*firstNum,*firstNumCount);
    printf("The second largest number is %d with number of occurrences %d\n",*secondNum,*secondNumCount);
    printf("The third largest number is %d with number of occurrences %d\n",*thirdNum,*thirdNumCount);
}
//compares integers to find 3 biggest
void compare(int* firstNum,int* secondNum,int* thirdNum,int* firstNumCount,int* secondNumCount,
int* thirdNumCount, int num)
{
    //if num is greater that first largest
    if(num>*firstNum)
    {
        *thirdNum=*secondNum;
        *secondNum=*firstNum;
        *thirdNumCount=*secondNumCount;
        *secondNumCount=*firstNumCount;
        *firstNumCount=1;
        *firstNum=num;
    }
    //num=first largest
    else if(num==*firstNum)
    {
        *firstNumCount=*firstNumCount+1;
    }
        //if num is greater that second largest

    else if(num>*secondNum)
    {
        *thirdNum=*secondNum;
        *thirdNumCount=*secondNumCount;
        *secondNumCount=1;
        *secondNum=num;
    }
// num = second largest
    else if(num==*secondNum)
    {
        *secondNumCount=*secondNumCount+1;
    }
    //if num is greater than third largeest
    else if(num>*thirdNum)
    {
        *thirdNum=num;
        *thirdNumCount=1;
    }
    //if num=3rd largest
    else if(num==*thirdNum)
    {
        *thirdNumCount=*thirdNumCount+1;
    }
}
//read integers one by one from file
void read_ints (const char* file_name)
{
    int firstNum=0,secondNum=0,thirdNum=0,firstNumCount=0,secondNumCount=0,thirdNumCount=0;
FILE* file = fopen ("integers.txt", "r");
int i = 0;

fscanf (file, "%d", &i);
while (!feof (file))
    {
        //compare integers
      compare(&firstNum,&secondNum,&thirdNum,&firstNumCount,&secondNumCount,&thirdNumCount,i);
      fscanf (file, "%d", &i);
    }
 compare(&firstNum,&secondNum,&thirdNum,&firstNumCount,&secondNumCount,&thirdNumCount,i);
fclose (file);
//print the 3 largest numbers 
printer(&largest1,&largest2,&largest3,&counts1,&counts2,&counts3);
}

int main()
{
    char* s[100]; // char of 100
    //input for name of text file (integers.txt)
    printf("Enter the name of file: ");
    scanf("%s",&s);
    //read and prints the 3 largest numbers
    read_ints(s);
return 0;
}