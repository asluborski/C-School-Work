/* Alex Sluborski
CIS 190 - HW1 Part 2
10/7/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
int digit1,digit2,digit3; // variable for each digit in num
int num = 0; //actual num or 3 digit value

srand(time(NULL)); //random seed

digit1=rand()%9; //generates random number for digit 1 from 0-9

num = digit1; //adds digit1 to num 

digit2=rand()%9; //generates random number for digit 2 from 0-9

num = num*10+digit2; // adds digit2 to num in second place

digit3=rand()%9; // generates random number for digit 3 from 0-9

num = num*10+digit3; // adds digit3 to num in third place

//makes sure rand prints out unique values for each digit,if not goes through 
//random generator again by comparing the digits to each other

if (digit1 == digit2 || digit1 == digit3){
	if(digit2 == digit1 || digit2 == digit3){
		if(digit3 == digit1 || digit3 == digit2){
			if(digit1 == 0){  //makes sure first digit isnt 0 to prevent two digit length
			digit1=rand()%9; //generates random number for digit 1 from 0-9

			num = digit1; //adds digit1 to num 

			digit2=rand()%9; //generates random number for digit 2 from 0-9

			num = num*10+digit2; // adds digit2 to num in second place

			digit3=rand()%9; // generates random number for digit 3 from 0-9

			num = num*10+digit3; // adds digit3 to num in third place

			}
		}
	}
}

else{
printf("Take 10 guesses to find out the three digit number\n");

int i; //loop counter
int guessNum; //user guess
int guessNumTwo;
int a,b,c; //represents digits 1 2 3

//for loop with 10 guesses
for(i=1;i<=10;i++){
printf("What is your guess?\n");

scanf("%d",&guessNum); //asks user for guess
guessNumTwo=guessNum;

//seperates digits in user guess

c=guessNum%10;
guessNum=guessNum/10;

b=guessNum%10;
guessNum=guessNum/10;

a = guessNum;

//compares digits from guess value to actual value and determines hit or match

if(a==digit1)
printf("Number %d is a hit\n",a);

else if (a==digit2||a==digit3)
printf("Number %d is a match\n",a);

if(b==digit2)
printf("Number %d is a hit\n",b);

else if (b==digit1||b==digit3)
printf("Number %d is a match\n",b);

if(c==digit3)
printf("Number %d is a hit\n",c);

else if (c==digit1||c==digit2)
printf("Number %d is a match\n",c);

if(num==guessNumTwo)
{
printf("Congratulations, you guessed the number %d\n",guessNumTwo);
break;
}

}

return 0;
}
}