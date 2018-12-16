/*Alex Sluborski
CIS 190 
Lab 9 Part 1
11/30/18*/


#include <errno.h>      

#include <stdio.h>      

#include <stdlib.h>     

#include <string.h>     
#include <ctype.h>      

//this function returns 1, if string holds a number; otherwise, it

//returns 0 

int isNumber(char *string) {

    char* to_convert = string;

    char* p = to_convert;

    errno = 0;

   

    // using strtol to check whether given string is properly

     // converted to int

    long val = strtol(to_convert, &p, 10);

    // conversion failed (INVAL, RANGE) 

    if (errno != 0)

        return 0;

       

    // conversion failed (no characters consumed) 

    if (to_convert == p)

        return 0;

       

    // conversion failed

    if (*p != 0)

        return 0;

       

    return 1;

}

// this function returns 1, if given string holds a double; otherwise, it returns 0

int isDouble(char *string) {

    char* to_convert = string;

    char* p = to_convert;

    errno = 0;

    // using strtod() to check string for double

  

    long val = strtod(to_convert, &p);

    

    if (errno != 0)

        return 0;

       

    

    if (to_convert == p)

        return 0;

       

    

    if (*p != 0)

        return 0;

       

    return 1;

}

// this function returns 1, if given string holds a single character; otherwise, it

// returns 0 

int isChar(char *string) {

    // checking length of the string 

    if (strlen(string) == 1 && !isdigit(string[0])) {

        return 1;

    }

   

    // returning 0, if failed 

    return 0;

}

// this function prints array elements of type int

void printNumbers(int * array, int size) {

    int i = 0;

    printf("Integer list: ");

    for (; i < size; ++i) {

        printf("%d", array[i]);

        if ((i+1) != size) {

            printf(", ");

        }

    }

    printf("\n");

}

// this function prints array elements of type string(char-array)

void printStrings(char** array, int size) {

    int i = 0;

    printf("String list: ");

    for (; i < size; ++i) {

        printf("%s", array[i]);

        if ((i+1) != size) {

            printf(", ");

        }

    }

    printf("\n");

}

// this function prints array elements of type double 

void printDoubles(double * array, int size) {

    int i = 0;

    printf("Double list: ");

    for (; i < size; ++i) {

        printf("%lf", array[i]);

        if ((i+1) != size) {

            printf(", ");

        }

    }

    printf("\n");

}

// this function prints array elements of type char 

void printChars(char * array, int size) {

    int i = 0;

    printf("Character list: ");

    for (; i < size; ++i) {

        printf("%c", array[i]);

        if ((i+1) != size) {

            printf(", ");

        }

    }

    printf("\n");

}

int main() {

    // declare array pointers with NULL

    char * charArray = NULL;

    int * intArray = NULL;

    double * doubleArray = NULL;

    char ** stringArray = NULL;

   

    //maintains index of each array

    int length[4] = {0, 0, 0, 0};

   

    // hold user input

    char buffer[512];

   

    // take input 

    while (1) {

        

        printf("Enter your input:(q to quit) ");

        scanf("%[^\n]", buffer);
       if( !strcmp(buffer,"q") || !strcmp(buffer,"Q")){
       printf("Thanks for using");
        break ;
		}
        printf("\n");

       

        // clearing out newline 

        getchar();

       

        //checking for number type

        if (isNumber(buffer)) {

            if (intArray == NULL) {

                // allocating memory for the first int

                intArray = (int *)malloc((length[0] + 1) * sizeof(int));

               

                // storing element in the memory 

                intArray[length[0]] = atoi(buffer);

               

                // incrementing the index 

                length[0] += 1;

            }

            else {

                // increasing the memeory to hold next element 

                intArray = (int *)realloc(intArray, (length[0] + 1) * sizeof(int));

               

                //storing element

                intArray[length[0]] = atoi(buffer);

               

				//increment index
				
                length[0] += 1;

            }

        }

        // check for double

        else if (isDouble(buffer)) {

            if (doubleArray == NULL) {

					//allocate memory
                doubleArray = (double *)malloc((length[1] + 1) * sizeof(double));

               

                //store in mem

                doubleArray[length[1]] = atof(buffer);

               

                 //increment

                length[1] += 1;

            }

            else {

               //increase mem

                doubleArray = (double *)realloc(doubleArray, (length[1] + 1) * sizeof(double));

                // store in mem

                doubleArray[length[1]] = atof(buffer);

               

                 //increment

                length[1] += 1;

            }           

        }

        else if (isChar(buffer)) {

            if (charArray == NULL) {

                //allocate for first element char

                charArray = (char *)malloc((length[2] + 1) * sizeof(char));

               

                //store in mem

                charArray[length[2]] = buffer[0];

               

                // increment

                length[2] += 1;

            }

            else {

                //increase mem

                charArray = (char *)realloc(charArray, (length[2] + 1) * sizeof(char));

               

                //store in mem

                charArray[length[2]] = buffer[0];

               

                 // increment

                length[2] += 1;

            }           

        }

        else {

            if (stringArray == NULL) {

                //allocate memory for string(char-array) need 2d 
                //rows and cols

                stringArray = (char**)malloc((length[3] + 1) * sizeof(char *));

                stringArray[length[3]] = (char *)malloc(strlen(buffer) * sizeof(char));

               

                //store element

                strcpy(stringArray[length[3]], buffer);

               

                // increment

                length[3] += 1;

            }

            else {

                //increase mem 

                stringArray = (char**)realloc(stringArray, (length[3] + 1) * sizeof(char *));

                stringArray[length[3]] = (char *)malloc(strlen(buffer) * sizeof(char));

               

                //store in mem

                strcpy(stringArray[length[3]], buffer);

               

                // increment

                length[3] += 1;

            }

        }

       

        //print arrays

        printStrings(stringArray, length[3]);

        printNumbers(intArray, length[0]);

        printDoubles(doubleArray, length[1]);

        printChars(charArray, length[2]);

       

        printf("\n");

    }

   

    return 0;

}

