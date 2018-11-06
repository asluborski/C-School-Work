/* Alex Sluborski
CIS 190 Lab 6 part 1
10/11/18
*/

#include <stdio.h>
#include <stdlib.h>
//defines buffer
#define BUFFER 256

//function declarations
void digitCount(int *num,int *answer);
void digitSum(int *num, int*answer);
void largestDigit(int *num, int*answer);
int main(){
char string[BUFFER]; // creates string of bugger 
int num;
do{
printf("Enter a number greater than 0\n"); // input number greater than 0
fgets(string,BUFFER,stdin); // scanner 
 num = atoi(string); // converts string to int
}while (num < 1); // do while loop for checking negative values

printf("Value entered: %d\n", num);
int length; // count of digits variable
digitCount(&num,&length);
printf("Length of %d is: %d\n",num,length); // prints length
int digSum; // sum variable
digitSum(&num,&digSum);
printf("sum of digits: %d\n",digSum); // prints sum
int largest; // largest digit variable
largestDigit(&num,&largest); 
printf("Largest digit: %d\n",largest); // prints largest digit

return 0;
}

// function for length of number
void digitCount(int *num, int *answer){
int a = *num; //creates temp var for num
int count = 0; // counter variable

while(a!=0) //while a does not equal zero
{
count++; //increments count 
a/=10; // divides by 10 (digits place)
} 
*answer = count;
}

//function for sum of all digits 
void digitSum(int *num, int*answer){
int a = *num;
int sum = 0;
while(a!=0){
sum +=a%10;   // sum modulus operator equation
a /=10; // divides by digits place
}
*answer = sum; // gets sum 
}

//function to find largest digit in number
void largestDigit(int *num, int*answer){
int a =*num;
int value = 0;

while(a!=0) // while a does not equal 0 
{
int b = a %10;  /// modulus equation
if(b > value) // if b greater than value 
value = b;
a/=10; // get digits place for b 
}
*answer = value; // gets largest digit
}