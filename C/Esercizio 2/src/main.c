#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/edit_distance_dyn/edit_distance_dyn.h"

#define MAX_W_LEN 64

/**
 * Check if the char is a special character or not
 * Returns 1 for true and 0 for false
 *
 * @param c
 * @return
 */
int is_special_char(char c){
  // return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))? 0 : 1;
  if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return 0;
  else return 1;
} //is_special_char

/**
 * Returns lower version of the char
 *
 * @param c
 * @return
 */
char to_lowercase(char c){
  // return c + (c >= 65 && c <= 90)? 32 : 0;
  if(c >= 65 && c <= 90) return c + 32;
  else return c;
} //to_lowercase

/**
 * Read word of a file-text and save it in a pointer
 *
 * @param str
 * @param str_len
 * @param f
 */
void read_word(char *str, int str_len, FILE *f){
  memset(str, 0, sizeof((str_len + 1) * sizeof(char)));
  int toRet_pos = 0;
  char c;
  while(str_len--){
    if((c = fgetc(f)) == EOF) break;
    if(is_special_char(c)) break;
    str[toRet_pos++] = to_lowercase(c);
  }
  str[toRet_pos] = '\0';
} //read_word

/**
 * Main function that tries to correct a sentence
 * through a dictionary
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
  if(argc < 2){
    printf("Inserisci nome del file di testo.\n");
    return 1;
  } else if(argc < 3){
    printf("Inserisci nome del file contenente il dizionario.\n");
    return 1;
  }

  FILE *phrase, *dict;
  if((phrase = fopen(argv[1], "r")) == NULL){
    printf("Non sono riuscito ad aprire il file di testo.\n");
    return 1;
  }else if((dict = fopen(argv[2], "r")) == NULL){
    printf("Non sono riuscito ad aprire il file dizionario.\n");
    fclose(phrase);
    return 1;
  }

  char phrase_w[MAX_W_LEN], dict_w[MAX_W_LEN];
  while(!feof(phrase)){
    read_word(phrase_w, MAX_W_LEN, phrase);
    if(phrase_w[0] == '\0') continue;

    int min_edit_dist = MAX_W_LEN, correct_ws_pos = 0;
    char correct_ws[MAX_W_LEN][MAX_W_LEN];

    while(!feof(dict)){
      read_word(dict_w, MAX_W_LEN, dict);

      int e_dist = edit_distance_dyn(phrase_w, dict_w);
      if(e_dist < min_edit_dist){
        correct_ws_pos = 0;
        memset(correct_ws, 0, 4096);
        min_edit_dist = e_dist;
      }
      if(min_edit_dist == e_dist){
        strcpy(correct_ws[correct_ws_pos++], dict_w);
      }
    }

    printf("%s --(%d passaggi)--> ", phrase_w, min_edit_dist);
    for(int x = 0; x < MAX_W_LEN; x++) printf("%s ", correct_ws[x]);
    printf("\n\n");

    rewind(dict);
    memset(correct_ws, 0, 4096);
  }

  fclose(phrase);
  fclose(dict);
  return 0;
} //main
