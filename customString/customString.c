/*Alex Sluborski
CIS 190 
Lab 7 
10/26/18
*/
#include "customString.h"
#include <stdio.h>
#include <string.h> //strlen() function 2
#include <ctype.h>

//function to compare strings 
void stringCompare(char *string1, char *string2)
{
// indexes through both strings
 for(int i=0 ; (string1[i] != '\0')||(string2[i] != '\0') ; i++) //for loop and checking null 
   { if (string1[i] == string2[i]) // if equal strings (index)
     {    printf("1");       }    // prints 1 for match
     else if (string1[i] != string2[i]) // if does not equal strings
     {    printf("0");  // 0 for no match   
     }

   }
   }
//function to reverse string
void reverseString(char *string)
{
int size = strlen(string); // get length of string
for (int i =0; i < size/2; i++) // divide size by 2 
{
//swap chr at index(i) and char at index size -i-1
char a = string[i];
string[i]=string[size-i-1];
string[size-i-1] = a;
}


}


// compare string function with case 
void stringCompareCase(char *string1, char *string2){
 for(int i=0 ; (string1[i] != '\0') || (string2[i] != '\0') ; i++)     // using \0 to represent null char, checking for null chars

   { if ((isalpha(string1[i]) != 0) && (isalpha(string2[i]) != 0)) // checks if passed char is alphabetic
     {    if (string1[i] == string2[i])
             printf("1");    // if alphabetic matches 1 
         else if ((string1[i] - string2[i]) == ('A' - 'a'))
             printf("1");         
         else if (string1[i] != string2[i])
             printf("0");      // if not matches 0          
     }
     else
     {    if (string1[i] == string2[i])
             printf("1");                  // if matches, then 1 
         else if (string1[i] != string2[i])
             printf("0");     // or 0

     }

   }

}