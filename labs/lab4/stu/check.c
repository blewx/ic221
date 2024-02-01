#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
  //TODO: Complete the program 

  if(argc == 1){
   fprintf(stderr,"ERROR: require credit card number\n");
    return 1;
  }
  int argLen = strlen(argv[1]);
  if(argLen != 16){
    fprintf(stderr,"ERROR: Invalid credit card number: Bad Length\n");
    return 1;

  }
  for(int i =0; i < argLen; i++){
    if(argv[1][i] > 71 || argv[1][i] < 48){
      fprintf(stderr,"ERROR: Invalid credit card number: Bad number '%c'\n",argv[1][i]);
      return 1;
    }
  }

  //Declare the card number and take it in from the user
  int cardNumber[16];
  for(int i =0; i < argLen; i++){
    char num[2];
    num[0] = argv[1][i];
    num[1] = '\0';
    cardNumber[i] = atoi(num);
  }
  
  int sum = 0; // sum thats gathered through the for loop
  for(int i = 0; i < argLen; i ++){
    if(i %2 == 0){
      int temp = cardNumber[i] * 2;
      if(temp >= 10){
         cardNumber[i] = temp % 10 + temp /10; // Adds both numbers together
      }
      else{
        cardNumber[i] = temp;
      }
    }
    sum += cardNumber[i];
  }
  
  if(sum % 10 == 0){
    printf("VALID\n");
  }
  else{
    fprintf(stderr,"INVALID\n");
    return 2;
  }

  return 0;



  //ERROR string for you to use to pass automated tests (print stderrr!)
  //  -- "ERROR: require credit card number\n"
  //  -- "ERROR: Invalid credit card number: Bad Length\n"
  //  -- "ERROR: Invalid credit card number: Bad number '%c'\n"

  // OUTPUT strinsg for you to use to pass automated tests
  //  --  printf("VALID\n");
  //  -- printf("INVALID\n");

  // RETURN values to use
  //  -- return 0 : valid credit card number
  //  -- return 1 : error occured
  //  -- return 2 : invalid credit card number


}
