/*Alex Sluborski
 CIS 190 Lab 5 Part 1
 10/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCardName(int drawn);
int drawCard();
int determineWinner(int dealer, int player);
void playGame();
int input(); //PUT YOUR INPUT TYPE HERE
int cardValue(int card);
//play the game here
int main(){
playGame();// main one function 

return 0;
}


void playGame()
{
   srand( time(NULL)); // random seed 
   int playerCard; // card var
   int dealerCard; // card var
   int playerScore = 0; // score
   int dealerScore = 0;   
   int value = 0;
   int userInput;
   char c;   
   do
   {
       printf("Welcome to blackjack!\n");
       playerCard = drawCard(); // draws card for player
       printf("YOUR CARDS : \n");       
       printCardName(playerCard); // prints player card
       value = cardValue(playerCard); 
       playerScore += value; // adds value into score
       playerCard = drawCard(); // draws second card
       printCardName(playerCard);
       value = cardValue(playerCard);
       playerScore += value;
       printf("YOUR CURRENT SCORE : %d\n",playerScore); // prints player score

       if(playerScore == 21)
           printf("Blackjack! You Win\n"); // if 21, blackjack ( first tow turns)
       else
       {
           play:       // else plays
           userInput = input();       
           switch(userInput) // user hit or stay 
           {
               case 1:
               playerCard = drawCard();
               printCardName(playerCard);
               value = cardValue(playerCard);
               playerScore += value;  
               printf("YOUR CURRENT SCORE : %d\n",playerScore);
               if(playerScore > 21)
               // busts player if score over 21 
               {
                   printf("Player busted! Computer wins!\n");
                   //end game
                   break;
               }
               goto play;                                 
               case 2:
               while(dealerScore <= 16) // dealer score after stay, hits until over 16
               {
                   dealerCard = drawCard();
                   printCardName(dealerCard);
                   value = cardValue(dealerCard);
                   dealerScore += value;
                   printf("%d\n",dealerScore);
                   }
                   
                   if(dealerScore == 21){
                       printf("Dealer Blackjack!\n");
                       }
                   if(dealerScore > 21){
                       printf("Dealer Busted!\n");
                       }
             determineWinner(dealerScore,playerScore);   
           
           }
       }
       scanf("Do You Want To Continue Playing (Y/N) ?? %c", &c);       
   }while(c == 'y' || c =='Y');       // do while loop to continue play9ing
   }                      

//draw a card here

int drawCard()
// draws a random card from 1-13 
{
   int drawnCard;
   drawnCard = rand() % 13 +1 ;
   return drawnCard;
}

// gets value of card
// gets the actual value of the card (J Q K = 10 )

int cardValue(int card)
{
   int value = 0;
   if(card >= 2 && card <= 10)
       value = card;
   else if(card >= 11 && card <= 13)
       value = 10;
   else
   { /* card is an ace */
   
       printf("Make ace 1 or 11?");
       scanf("%d", &value);
       	if(value !=1 || value!=11){
       		printf("Incorrect input,retry");
       		scanf("%d",&value);
       	}
   }
   
   return value;
}

//print the cards name that you drew

void printCardName(int drawn)
{
   switch(drawn)
   // switch case prints out card name 
   {
       case 1:   printf("Ace\n");
               break;
       case 2:   printf("2\n");
               break;
       case 3:   printf("3\n");
               break;
       case 4:   printf("4\n");
               break;
       case 5:   printf("5\n");
               break;
       case 6:   printf("6\n");
               break;
       case 7:   printf("7\n");
               break;
       case 8:   printf("8\n");
               break;
       case 9:   printf("9\n");
               break;
       case 10:printf("10\n");
               break;
       case 11:printf("Jack\n");
               break;
       case 12:printf("Queen\n");
               break;
       case 13:printf("King\n");
               break;
       default:printf("??\n");
               break;
   }
   //use a switch statement to determine the card name
   return;
}

int determineWinner(int dealer, int player)
// determines winner depending on score conditions 
{
   int winner;
   if(player == 21)
   {
       printf("Blackjack");  
       winner = player;       
   }
   else if(dealer == 21)
   {
       printf("Blackjack");   
       winner = dealer;
   }
   else if (player > dealer)
   {
       printf("You won!");
   }
   else if (player < dealer)
   {
       printf("Dealer won!");
   }
   else
   {
       printf("We have tied.");
   }
   return winner;       
}

//get player input here

//REPLACE (your Input type here) WITH WHAT KIND OF INPUT YOU WISH TO USE

int input()
{ // asks player to hit or stay
   int playerInput;
   printf("Would you like to hit(1) or stay(2)?\n");
   scanf("%d",&playerInput);
   return playerInput;
}