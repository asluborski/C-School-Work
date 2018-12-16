/* Alex Sluborski
CIS 190 
Homework 4 Part 1
11/17/18
*/

#include <stdio.h>
#include <stdlib.h>

//prints pyramid
void print_pyramid(int** a, int len) {
  int b, c;
  b=c=0;

  for(; b < len; ++b) {
    for(; c < len; ++c) {
      printf("%d", a[b][c]);
    }
    printf("\n");
  }
}

float calculate_weight(float** pyramid, int row_count, int row, int col) {

  //top of pyramid
  if(row == 0)
    return pyramid[0][0];
 
  //leftmost
  if(col == 0) {
    return pyramid[row][col] + (calculate_weight(pyramid, row_count, row-1, col) / 2.0);
  } 

  // rightmost
  if(col == (row_count -1) ||pyramid[row][col+1] == 0) {
    return pyramid[row][col] + (calculate_weight(pyramid, row_count, row-1, col-1) / 2.0);
  }

  // middle
  return pyramid[row][col] + (calculate_weight(pyramid, row_count, row-1, col-1) / 2.0) + (calculate_weight(pyramid, row_count, row-1, col) / 2.0);

}

int main(void) {
  int row_count;
  printf("How many people are on the bottom row?: ");
  scanf("%d", &row_count);

  printf("Each person's own weight(multiple)\n");
  

  // add to pyramid
  int a, b, item_count = 1;
  float input = 0;
  
//creates pyramid
  float** pyramid = calloc(row_count, sizeof *pyramid);


  // initialize rows of pyramid
  for(a = 0; a < row_count; ++a) {
  
    pyramid[a] = calloc(row_count, sizeof *(pyramid[a]));
  }

  for(a = 0; a < row_count; ++a) {
    //++ for element on top of pyramid
    printf("Row: %d\n", a+1);
    for(b = 0; b < item_count; ++b) {

      	scanf("%f", &input);
      	pyramid[a][b] = input;
      	input = 0;  

    }

    	printf("\n");

   	 ++item_count;
  }


  
  item_count = 1;

  //++ for element on top of pyramid
  
  for(a = 0; a < row_count; ++a) {
    
    for(b = 0; b < item_count; ++b) {
    
    // print recursive calculation 
		printf("%.2f ", calculate_weight(pyramid, row_count, a, b));
    }
    printf("\n");
    ++item_count;
  }
 
}
