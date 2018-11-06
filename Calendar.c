/*
Alex Sluborski
CIS 190-HW1
9/7/18
*/

/* This program asks the user for a year and prints out a calendar for each month
for the entire year */

#include <stdio.h>
#include <stdlib.h>   
//define true and false as 1 and 0 
#define TRUE 1   
#define FALSE 0

int main()
{
    int year; // year variable
    int first_Day; // variable for first day of a year
    int leap_Year; // variable for leap year
    
    //asks user for the year for calendar to be printed
    printf("Enter year\n");
    scanf ("%d", &year);
    
    //calculates first day of the year
    first_Day =(year+((year - 1)/ 4)-((year - 1)/ 100)+((year - 1)/ 400))%7;
    
    
    
   
   int days_in_month; // num of days in month
   int day; // day in month counter
   int month; //month variable
   
   printf ("                   %d", year);
   //print each month and days in month with switch statement in for loop for each 
   //month
     for ( month = 1; month <= 12; month++ ) {
          switch ( month ) { 
              
          case 1:
               printf("\n\nJanuary" );
               days_in_month = 31;
               break;
          case 2:
               printf("\n\nFebruary" );
               //calculates leap year and days of february
               if((year% 4==0 && year%100 != 0) || (year%400==0))
                    days_in_month = 29;
                else
                    days_in_month = 28;
               break;
          case 3:
               printf("\n\nMarch" );
               days_in_month = 31;
               break;
          case 4:
               printf("\n\nApril" );
               days_in_month = 30;
               break;
          case 5:
               printf("\n\nMay" );
               days_in_month = 31;
               break;
          case 6:
               printf("\n\nJune" );
               days_in_month = 30;
               break;
          case 7:
               printf("\n\nJuly" );
               days_in_month = 31;
               break;
          case 8:
               printf("\n\nAugust" );
               days_in_month = 31;
               break;
          case 9:
               printf("\n\nSeptember" );
               days_in_month = 30;
               break;
          case 10:
               printf("\n\nOctober" );
               days_in_month = 31;
               break;
          case 11:
               printf("\n\nNovember" );
               days_in_month = 30;
               break;
          case 12:
               printf("\n\nDecember" );
               days_in_month = 31;
               break;
        }
        //print days of calendar
          printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
          //goes to correct position of first days in calendar
          for ( day = 1; day <= 1 + first_Day * 5; day++ )
               printf(" " );
               //print dates for month
          for ( day = 1; day <= days_in_month; day++ ) {
               printf("%2d", day );
               //if first day before saturday move to the next day in the same week
               if ( ( day + first_Day ) % 7 > 0 ) 
                    printf("   " );
               else  //skip to start with sunday
                    printf("\n " );
          }
          //set first day for next month to begin
          first_Day = ( first_Day + days_in_month ) % 7;
     }
    return 0;
}