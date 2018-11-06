/*Alex Sluborski
Homework 3 Part 1 
11/2/18/
*/


#include<stdio.h>

void towerOfHaHa ( int num,int n); // function prototype

int main() {

int n;

// asks user for number of disks 
printf("Enter number of Disks:"); 

scanf("%d", &n);

towerOfHaHa(n,n); // calls towerOfHaHa function 

}

void towerOfHaHa ( int num,int n) {
// odd and even 

if ( num == 1 ) { // if num 1 

printf("Move %d from Tower 1 to Tower 2\n", n-num+1); // moves disks from tower 1 to tower 2 

return ; // returns 

}

printf("Move %d from Tower 1 to Tower 3\n", n-num+1); //moves disks left over in tower 1 to tower 3 

towerOfHaHa(num-1,n); // recursive call 

printf("Move %d from Tower 3 to Tower 2\n", n-num+1);  // moves disks from tower 3 to 2 


}