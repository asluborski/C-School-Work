/*Alex Sluborski
CIS 190 
Lab 9 Part 2
11/30/18*/


#include <stdio.h>

#include <stdlib.h>

int main()

{

int *ptr = (int *)malloc(sizeof(int) * 2); //malloc pointer

int *ptr1 = (int *)malloc(sizeof(int) * 2); // malloc pointer

int i, n1 = 1, n2 = 1; //initilize n1 and n2 is 1 in start

printf("Entered as many array as you want to add and press q for exit\n"); //output msg

for (i = 0; i > -1; i++)

	{

	ptr = realloc(ptr, sizeof(int) * n1);

	printf("Enter the value array1[%d]=", i); //output msg

		if (scanf("%d", &*(ptr + i)) == 1) // if equal to 1 

			{

				n1 = n1 + 1; // inrement by 1 

			}

	else

		{

		n1 = n1 - 1; // else decrement

		break;

		}

}

printf("Enter as many array as you want to add and press q for exit\n"); //enter for array 2 

for (i = 0; i > -1; i++)

{

	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF) // prevent char

	ptr1 = realloc(ptr1, sizeof(int) * n2); // reallocate

	printf("Enter the value array2[%d]=", i); //output msg

	if (scanf("%d", &*(ptr1 + i)) == 1)

		{

			n2 = n2 + 1; // increment by 1 

		}

	else

	{

		n2 = n2 - 1; // decrement by 1

		break;

	}

}

// if array 1 greater than array 2 
if (n1 > n2)

	{

		for (i = 0; i < n2 + n1; i++)

			{

				int num1 = (i < n1) ? *(ptr + i) : *(ptr1 + (i - n1)); // add new elements

				int num2 = (i < n2) ? *(ptr1 + i) : *(ptr + (i - n2));

				printf("The position %d =%d and %d \n", i, num1, num2); //output msg

			}

	}

	else // else if array 2 greater than array 2
		
	{

		for (i = 0; i < n2 + n1; i++)

		{

			int num1 = (i < n2) ? *(ptr1 + i) : *(ptr + (i - n2)); // add new elements

	 		int num2 = (i < n1) ? *(ptr + i) : *(ptr1 + (i - n1));

			printf("The position %d =%d and %d \n", i, num1, num2); //output msg

		}

	}

getchar();

return 0;

}

