/*Alex Sluborski
Homework 2 Part 1
10/18/18 */

#include <stdio.h>
#include <math.h>
//function declarations 
void sumAverage(int *num, int*sum, float *average, int*integerNum);
void squareRoot(float *Rootanswer, int *num);
void lessThan20(int *num, int *lessAnswer);
void Between(int *num, int *betweenAnswer);
int main()
{
int num; // number variable
int sum = 0, integerNum = 0; // sum and number of numbers variable
int go =0; // use in do while loop for stopping input and continuing program 
float average, Rootanswer; // average of numbers and squareroot answer
int betweenAnswer = 0, lessAnswer = 0; //between 10 and 90 variable, less than 20 variable

printf("Enter a number: (Input 0 to stop entering)\n"); // asks for user input
// do while loop for stopping input and program continuation for all integers
do{
// read input
scanf("%d",&num);

//exit if 0 is entered
if(num == 0)
{
	go = 0; // exits 
}
else{
go = 1; // continues

// call function that calculates the square root
squareRoot(&Rootanswer, &num);

//print squareroot
printf("The square root of integer %d is %.2f\n",num,Rootanswer);

// call function that calculates sum and average
sumAverage(&num,&sum,&average,&integerNum);
// call function for num less than 20 
lessThan20(&num,&lessAnswer);
// call function for num between 10 and 90
Between(&num,&betweenAnswer);
}
}while(go);

//print out answers
printf("The number of integers is: %d\n",integerNum);
printf("The sum of the integers is %d\n",sum);
printf("The average of the integers is: %.2f\n",average);
printf("At least one number was <20:");
if(lessAnswer){
printf("True!\n");
}
else{
printf("False!\n");
}
printf("Numbers between 10 and 90: \n");
if(betweenAnswer==integerNum){
printf("True!\n");
}
else{
printf("False!\n");
}
return 0;
}


//This function calculates the averages and sum of the integers
void sumAverage(int *num, int *sum, float *average, int *integerNum)
{
*sum = *sum + *num; // gets sum of numbers
*integerNum = *integerNum +1; // number of integers + 1
*average = (*sum)/(*integerNum); // gets average by dividing sum and number of integers
}

//This function calculates the square root of each integer
void squareRoot(float *Rootanswer,int *num){
*Rootanswer = sqrt(*num); //sqrt function calculates and stores answer in int answer;
}

// This function checks if any integer is less than 20
void lessThan20 (int *num, int *lessAnswer){
if(*num <20) // if number less than 20 
	*lessAnswer = *lessAnswer +1; // answer + 1 for each number
}

// This function checks for numbers between 10 and 90
void Between(int *num, int *betweenAnswer){
if (*num >=10 && *num<=90) // if between 10 and 90 
	*betweenAnswer = *betweenAnswer +1; // adds 1 to answer and stores answer
}
