/*Alex Sluborski
CIS 190 HW6
12/8/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Beer {
  char beer_name[100];
  int   beer_id;
  int   beer_quantity; 
  float beer_price; 
} Beer; 

//prints beers from structure
void print_beers(Beer** beer2, int beer_count) {
  int i = 0;
  do{

    printf("Name: %s\n", beer2[i]->beer_name);
    printf("ID: %d\n", beer2[i]->beer_id);
    printf("Quantity: %d\n", beer2[i]->beer_quantity);
    printf("Price: %f\n", beer2[i]->beer_price);
    ++i;
    }while(i<beer_count);
  }
}




//reads beer file structure
Beer* read_file(FILE* file) {
    Beer* beer = malloc(sizeof *beer);
    fscanf(file, "%s", &beer2->beer_name);
    fscanf(file, "%d", &beer2->beer_id);
    fscanf(file, "%d", &beer2->beer_quantity);
    fscanf(file, "%f", &beer2->beer_price);
    return beer2;
}
//reads .dat file
Beer** read_file(char* beerfile, int* length) {
  
  FILE* file;

  //opens file for reading
  file = fopen(beerfile, "r");

  if(file == NULL)
    return NULL; 

  //get item count
    int beer_count = 0;

  fscanf(fp, "%d", &beer_count);

  //allocate space
  Beer** beer2 = calloc(beer, sizeof(*beer2));

  
  int i = 0; //read each item 
  do{
   *(beer2 + i) = read_beer(file);
   ++i'
   }while(i < beer_count);
  

  
  *length = beer_count; // store length in counter

  return beer2;
  
}
/*
void selectionSort(int[] array, int startIndex)
{
    if ( startIndex >= array.length - 1 )
        return;
    int minIndex = startIndex;
    for ( int index = startIndex + 1; index < array.length; index++ )
    {
        if (array[index] < array[minIndex] )
            minIndex = index;
    }
    int temp = array[startIndex];
    array[startIndex] = array[minIndex];
    array[minIndex] = temp;
    selectionSort(array, startIndex + 1);
}
*/

//selection sort implementation 
void selection_sort(Beer** beer2, int length, int startIndex) {
  
  if(startIndex >= length-1)
    return;

  int minIndex = startIndex;

  for(int index = startIndex + 1; index < len; ++index) {
    if(beer2[index]->beer_price < beer2[minIndex]->beer_price) {
      minIndex = index;
    }
  }


  if(minIndex != startIndex) {
    Beer temp = *beer2[minIndex];
    *beer2[minIndex] = *beers[startIndex];
    *beer2[startIndex] = temp;
  }

  selection_sort(beer2, length, startIndex+1);
}

void search_beers(Beer** beer2, int id, int counter) {
  // Searches for beers with iteration
  int i = 0;
  do{

     
    if(beer2[i]->beer_id == id) {
      printf("Name: %s\n", beer2[i]->beer_name);
      printf("Quantity: %d\n", beer3[i]->beer_quantity
      printf("Price: %f\n", beer2[i]->beer_price);
      ++i;
      return;
    }
    }while(i < counter);
  

  // if not found
  printf("Beer not in inventory.");
  return;
}

//prints invoice
void print_invoice(Beer** beer2, int length) {
  int i;
  float total_cost = 0; 
  printf("Beer Inventory Invoice");

  

  // print info for every beer along with price
  for(i = 0; i < length; ++i) {
    printf("Name: %s, QTY: %d, Price: %f, Cost: $%.2f\n", beers[i]->name,
	   beers[i]->quantity, beers[i]->price, (beers[i]->quantity * beers[i]->price));
    total_cost += (beers[i]->quantity * beers[i]->price);  
  }

  // Print the total cost 
  printf("Total cost of beers: %f\n", total_cost);

}

int main(void) {

  //read file
  int len; 
  Beer** beer2 = read_file("beer.dat", &len);

  while(1) {
    //menu
    int selection = 0;
    printf("1. Search for a beer by ID\n");
    printf("2. Display Inventory\n"); 
    printf("3. Invoice\n");

    
    printf("Enter your selection (-1 to exit): ");
    scanf("%d", &selection);

    // break out if -1 
    if(selection == -1) {
      break;
    }

    
    int id_number = 0; // id

    switch(selection) {
    case 1:
      // search for the beers 
      printf("Please enter the ID number of the beer: \n");
      scanf("%d", &id_number);
      search_beers(beer2, id, counter);
      break;
    case 2:
      // sort the beers 
      selection_sort(beer2, length, 0);
      print_beers(beer2, beer_count);
      break;
    case 3:
      // Print out an invoice 
      print_invoice(beer2,length );
      break;
    default:
      printf("Invalid input!");
      break;
    }
  }
}
