/**
 *Brendan Lewis m263708
 *IC221 Project 1
 *Program that mimics the functionality of wc
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  int badfile = 0;
  int l_selected = 0;
  int w_selected = 0;
  int c_selected = 0; // used as base case in case no options are selected
  int only_one = 1; // changes if the user selects l w c options
  int total_chars = 0;
  int total_lines = 0;
  int total_words = 0;
  FILE* fp = stdin; // file pointer fp that will be used to point at different files
                    // Is initially pointed at stdin so it deals with the case
                    // the user doesn't enter in any files
  for(int i = 1; i < argc || (argc == 1 && i == 1) ; i++){
    if ( argc <= 1 || argv[i][0] == '+'){
      fp = stdin;
    }
    else if(argv[i][0] == '-') {
      if(argv[i][1] == 'l'){
        l_selected = 1;
      }
      else if(argv[i][1] == 'w'){
        w_selected = 1;
      }
      else if(argv[i][1] == 'c'){
        c_selected = 1;
      }
      else{
        fprintf(stderr, "ERROR unknown option '%s' \n", argv[i]);
        return 2;
      }
      only_one = 0;
      fp = NULL; // to ensure no printing happens
    }
    else{
      fopen(argv[i], "r");
      if(access(argv[i],F_OK) == -1){
        fprintf(stderr, "ERROR file '%s' cannot be opened\n", argv[i]);
        badfile = 1;
      }
      else{
      fp = fopen(argv[i],"r");
      }
    }
    // if it is a bad file skip the rest of the code and read the next file
    if(badfile){
      continue;
    }



    if(fp == NULL)
      continue;
    char temp;
    int current_chars = 0;
    int current_lines = 0;
    int current_words = 0;
    int previous_char_is_whitespace = 0;
    int current_char = 0;
    while((temp = fgetc(fp)) != EOF){
      current_chars++;
      if((current_char = isspace(temp))  != 0 && previous_char_is_whitespace == 0 )
        current_words++;
      if(temp == '\n')
        current_lines++;
      previous_char_is_whitespace = current_char;
    }
    total_chars += current_chars;
    total_words += current_words;
    total_lines += current_lines;
    //Lines to print
    if(argc == 1 || (argv[i][0] == '+')){
      printf("-stdin- ");
    }
    else{
      printf("%s ", argv[i]);
    }
    if(only_one){
      printf("%d %d %d", current_lines, current_words, current_chars);
    }
    if(l_selected){
      printf("%d ", current_lines);
    }
    if(w_selected){
      printf("%d ", current_words);
    }
    if(c_selected){
      printf("%d ", current_chars);
    }
    printf("\n");

  }
  
  //Print the total words and chars
  printf("total ");      
  if(only_one){
    printf("%d %d %d", total_lines, total_words, total_chars);
  }
  if(l_selected){
    printf("%d ", total_lines);
  }
  if(w_selected){
    printf("%d ", total_words);
  }
  if(c_selected){
    printf("%d ", total_chars);
  }
  printf("\n"); 


  return 0;
}
