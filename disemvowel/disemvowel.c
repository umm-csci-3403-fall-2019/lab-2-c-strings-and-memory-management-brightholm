#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

//Declare a list of all vowels
const char* all_vowels = "aeiouAEIOU";


int is_vowel(char inp_char){
  int vowel_status = 0;
  int j=0;
  for(j=0;all_vowels[j] != '\0';j++){
    if (all_vowels[j] == inp_char){
      vowel_status = 1;
      break;
    }
  }
  return vowel_status;
}

char *disemvowel(char *str) {
  char *disemvoweled_string;
  int i;
  int vowel_count = 0;
  int str_length = strlen(str);
    //in this loop, get a count of consonants
  for(i=0; str[i] != '\0';i++){
    if (is_vowel(str[i]) == 1){
      vowel_count++;
    }
  }


  //declare a newstring of consonant count +1 size
  int pos_in_disemvoweled=0;

  disemvoweled_string = (char*) calloc(str_length - vowel_count, sizeof(char));

  for(i=0; str[i] != '\0';i++){
    if (is_vowel(str[i]) == 0){
      disemvoweled_string[pos_in_disemvoweled]=str[i];
      pos_in_disemvoweled++;
    }
  }

  return (char*) disemvoweled_string;
}
