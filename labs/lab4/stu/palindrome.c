#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check1(char * str);
int check2(char * str1);

int check1(char *str){
  //TODO: Complete by iterating from front-to-back and back-to-front
  //      to check for a palindrome
  int len = strlen(str);
  //create new flipped string
  for(int i = 0; i < len/2; i++){
    if(str[i] != str[len -1 -i]){
      return 0;
    }
  }
  return 1;
}

int check2(char *str1){
  char str2[1024]; //string to copy to
  
  //TODO: Complete by copying str1 to str2, backwards, and then
  //      checking that str1 and str2 are the equal using strcmp()
  int len = strlen(str1);
  //create new flipped string
  for(int i = len - 1, k = 0; i >= 0; i--, k++){
    str2[k] = str1[i];
  }
  str2[len] = '\0';
  //check to see if it's not a palindrome
  if(strcmp(str1,str2) == 0 ){
    return 1;
  }
  return 0;

}

int main(int argc, char * argv[]){

  char str[1024];

  printf("Enter a string:\n");

  scanf("%1023s",str);

  if(check1(str)){
    printf("Palindrome according to check 1\n");
  }else{
    printf("NOT a palindrome according to check 1\n");
  }
   

  if(check2(str)){
    printf("Palindrome according to check 2\n");
  }else{
    printf("NOT a palindrome according to check 2\n");
  }
  return 0; 
}
