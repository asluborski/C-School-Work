/* Alex Sluborski
CIS 190 Lab 6 part 2
10/11/18
*/

#include <stdio.h>
#include <stdlib.h>
//defines buffer
#define BUFFER 256
int digitCount(int n);
int digitSum(int n);
int largestDigit(int n, int largest);
int main(){
char string[BUFFER]; // creates string of bug
int num;
do{ 
printf("Enter a number greater than 0\n"); // input number greater than 0
fgets(string,BUFFER,stdin); // scanner 
num = atoi(string); // converts string to int 
}while (num < 1); // do while loop for checking negative values
printf("Value entered: %d\n", num);
int length = digitCount(num); //gets digit count
printf("Length of %d is %d\n",num,length); 
int sum = digitSum(num); // gets sum
printf("Sum of digits: %d\n,",sum);
int large = largestDigit(num,0); // gets largest digit, returns as 0 
printf("Largest digits: %d\n",large);
return 0;
}

//recursive function w/pass by value for length of number
int digitCount(int n)
{
if(n == 0)
{
return 0; // if n= 0, just returns 0
}
else {
return 1+digitCount(n/10); // returns function recursively, counting digits place to determine length
// and increments
}
}

int digitSum(int n)
{
if(n ==0) // if n=0, return 0
return 0;
return ((n%10)+ digitSum(n/10)); // returns function recursively, counting digits place and 
// using modulos operator to figure out the sum
}


int largestDigit(int n, int largest){
if (n==0) // if n = 0 return largest (set as zero in main)
{
return largest;
}
else
{
if(largest <(n%10)) // checks condition for largest digit
   largest = n%10; // finds digit
   return largestDigit(n/10,largest); // returns function recursively  with finding largest value
}
}
