/*Alex Sluborski
Homework 2 Part 2
10/18/18 */

#include <stdio.h>

int firstNum =0,secondNum=0,thirdNum =0; // variables for 3 biggest numbers
int firstNumCount = 1, secondNumCount =1, thirdNumCount =1; // count variable for occurences

//function that compares 3 numbers to see which one is biggest
void compareNumbers(int x)

{

    if (x > firstNum) // if x is greater than first number
    {
      thirdNum = secondNum; // make second equal to third

      secondNum = firstNum; // make first equal to second

      firstNum = x; //set x as first number 
}

    else if (x > secondNum) // if x greater than second number
    {
      thirdNum = secondNum; // make second number equal to third

      secondNum = x; // second number is x
    }

    else if (x > thirdNum) // if x is greater than third number
	{

thirdNum = x; // set x equal to third
}

      

}
//read file function
void read_file(const char *filename)

{

FILE *fp = fopen("integers.txt", "r"); //opens file 

int num; //number variable

for(int i=0;i<20;i++) // for loop to go through all 20 integers

{

fscanf(fp, "%d",&num); // scans file for integers and puts in number variable

if(num==firstNum||num==secondNum||num==thirdNum){

// continues program if either nums equal 3 nums
continue;

}

compareNumbers(num); //calls function to compare numbers

}

 


for(int i=0;i<20;i++)// loops through all 20 integers

{


int num;



if(num==firstNum){

firstNumCount++; // counts occurences of first biggest number

}

else if(num==secondNum){

secondNumCount++;  // counts occurences of second biggest number

}

else if(num==thirdNum){

thirdNumCount++; // counts occurences of third biggest number

}

}

fclose(fp); // closes file

}

//void function to print out numbers and occurences
void print(int num,int count)

{

printf("Number:%d , Count:%d\n", num, count);

}

int main()

{

 const char filename[] = "integers.txt"; // sets char filename to integers.txt

read_file(filename); // reads filename

print(firstNum,firstNumCount); // calls print functions

print(secondNum,secondNumCount); // calls print functions

print(thirdNum,thirdNumCount); // calls print functions

  return 0;

}

