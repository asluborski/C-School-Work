/*Alex Sluborski
CIS 190 
Homework 4 Part 2 
11/17/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexicon.h"

// gets char based off tele numbers
char* get_charset(int n) {
  switch(n) {
  case 1:
    return "";
    break;
  case 2:
    return "abc";
    break;
  case 3:
    return "def";
    break;
  case 4:
    return "ghi";
    break;
  case 5:
    return "jkl";
    break;
  case 6:
    return "mno";
    break;
  case 7:
    return "pqrs";
    break;
  case 8:
    return "tuv";
    break;
  case 9:
   return "wxyz";
    break;
  default:
    return "";
  }
}

// returns length of char
int get_char_count(int n) {
  switch(n) {
  case 1:
    return 0;
    break;
  case 2:
    return 3;
    break;
  case 3:
    return 3;
    break;
  case 4:
    return 3;
    break;
  case 5:
    return 3;
    break;
  case 6:
    return 3;
    break;
  case 7:
    return 4;
    break;
  case 8:
    return 3;
    break;
  case 9:
   return 4;
    break;
  default:
    return 0;
  }
}

// Returns the char at index 
char get_alphabet_letter(int n) {
  static char* alphabet = "abcdefghijklmnopqrstuvwxyz"; // abc string 
  return alphabet[n];
}

 // gets completions  
void find_completion(char* prefix, int alphabet_location) {

// iterate prefix 
  if(lex_has_word(prefix)) {
    printf("Suggestion: %s\n",prefix);
  }

  //add every char in abc until valid prefix 
  int i = 0;
  for(i = alphabet_location; i < 26; ++i) {

    // append char to string 
    if(i == 0) {
      char tmp[2];
      tmp[0] = get_alphabet_letter(i);
      strcat(prefix, tmp);
    } else { 
       //change the char 
      prefix[strlen(prefix)-1] = get_alphabet_letter(i);
    }


    
    // if prefix found in lexicon, call completion function
    if(lex_has_prefix(prefix)) {
      return find_completion(prefix, 0);
    }
  }
}


// Finds all the combinations
void match(char** map, int set_count, char temp[], int iter) {


// char pulled from subset
  if(iter == set_count) {
    
    char* new = calloc(strlen(temp), sizeof(*new));
    strcpy(new, temp);

    if(lex_has_prefix(new)) {
      
      find_completion(new, 0);
      free(new);
     }

    return;
  }

  int i;
  // For each character in the ith charset 
  for(i = 0; i < strlen(map[iter]); ++i) { 
    temp[iter] =  map[iter][i]; //store char temp
    match(map, set_count, temp, iter+1);
  }
}

void list_completions(char* sequence, int index, int len) {

  //allocate space for characters
  char** charmap = calloc(len, sizeof *charmap);

  int i;
  for(i = 0; i < len; ++i) {
    // allocate space for string  
    charmap[i] = calloc(len, sizeof *(charmap[i]));
    // Set it equal to character set assoicated with the number in the sequence 
    charmap[i] = get_charset((sequence[i] - '0')); 
  }

  // temp holds prefixes
  char temp[len];
  temp[len] = 0;
  match(charmap, len, temp, 0); 

  //free charmap
  free(charmap);
}


int main(void) {
  //load lexicon 
  int status = lex_load("words.txt");
  if(status) {
    printf("Enter a sequence of the digits pressd:\n");
    char* sequence; //= "72547";
    scanf("%s", sequence);
    list_completions(sequence, 0, strlen(sequence));
  } else {
    puts("Failed to load lexicon");
  }
  return 0;
}
