 /* Alex Sluborski
Homework 3 Part 2 
11/2/18
*/
#include<stdio.h>

//partition function
int partition(double arr[], int low, int high, double pivot);
//matchpairs function
void matchPairs(double nuts[],double bolts[], int low,int high) ;
//printarray function

//this function prints the array
void printArray(double arr[] ,int n) {

int i;

for (i=0;i<n;i++) //for loop to print array of nuts and bolts 

printf("%lf ",arr[i]);

  

printf("\n");

}

int main()

{

int n,i;

printf("Enter n : ");

scanf("%d",&n); // user asks for number of bolts and nuts 

double nuts[n] ; //array nuts

double bolts[n] ; //array bolts

printf("Enter width of n bolts : "); 

for(i=0;i<n;i++){
scanf("%lf",&bolts[i]); // enter width of bolts  for each iteration
}
printf("Enter width of n nuts : "); 

for(i=0;i<n;i++){  // enter width of nuts for each iteration
scanf("%lf",&nuts[i]);
}
  

matchPairs(nuts, bolts, 0, n-1); // calls match pairs function to match bolts and nuts

  

printf("Matched nuts and bolts are : \n");

printArray(nuts,n); // prints matched array

printArray(bolts,n); // prints matched array

}

  
//recursive function of quicksort
void matchPairs(double nuts[],double bolts[], int low,int high)

{

if (low < high)

{
//index partitioning 
int pivot = partition(nuts, low, high, bolts[high]);

partition(bolts, low, high, nuts[pivot]);

  
//seperately sort elements before and after partitioning
matchPairs(nuts, bolts, low, pivot-1);

matchPairs(nuts, bolts, pivot+1, high);

}

}

  

  
// implementation of quicksort partition 
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition(double arr[], int low, int high, double pivot)

{

int i = low,j; // index of pivot

double temp1, temp2;

for ( j = low; j < high; j++)

{

// If current element is smaller than or 
// equal to pivot 
if (arr[j] < pivot){

temp1 = arr[i];

arr[i] = arr[j];

arr[j] = temp1;

i++; // increment index of smaller element 

} else if(arr[j] == pivot){

temp1 = arr[j];

arr[j] = arr[high];

arr[high] = temp1;

j--;

}

}

temp2 = arr[i];

arr[i] = arr[high];

arr[high] = temp2;

  

return i;

}