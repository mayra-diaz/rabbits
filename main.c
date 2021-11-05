/*
 * Rabbit farmer application.
 *
 * You may modify this file in any way you like, and are expected to modify it.
 * Your solution must read each input file from a separate thread. We encourage
 * you to make as few changes as necessary.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <getopt.h>

#include "rabbit.h"
#include "rabbit_helper.h"

#define MAX_WORD_LEN 64



char* get_word(FILE* infile) {

	char word[MAX_WORD_LEN];
  int num_char = 0;
  char c;
  bool not_alpha = false; // if a not alphabet char is in a word

  c = fgetc(infile);
  
  while (c != EOF) {
    if (!(c == ' ' || c == '\n') && !isalpha(c)) {
      not_alpha = true;
    }

    if (c == ' ' || c == '\n') {
      if (!not_alpha && num_char <= MAX_WORD_LEN && num_char > 1) {
				word[num_char] = '\0';
				return strdup(word);
      }
      not_alpha = false;
      num_char = 0;
    }else {
      word[num_char++] = c;
    }

    // stop readin from stdin
    if (infile == stdin && c == '\n') {
      return NULL;
    }
    c = fgetc(infile);
  }

  return NULL;
}


void add_rabbits(rabbit_list_t* rlist, FILE *infile) {

	char *word;

	while((word = get_word(infile))){
			add_rabbit(rlist, word);
	}

	if (infile != stdin) {
			fclose(infile);
		}      
}

/*
 * main - program.
 */
int main(int argc, char* argv[]) {

	printf("Welcome to the rabbit farm!\n");
	
	FILE* infile = NULL;
	size_t num_rabbits = 0;
	size_t num_breeds = 0;
  /* Create the empty data structure. */
  rabbit_list_t rabbits;

	printf("Starting rabbit list ...\n");
	init_rabbits(&rabbits);

	 if ((argc - optind) < 1) {
    // No input file specified, instead, read from STDIN instead.
    infile = stdin;
  } else {
    // At least one file specified. 
    infile = fopen(argv[argc-1], "r");
  }

	printf("Start counting rabbits ...\n");
	add_rabbits(&rabbits, infile);
	
	num_rabbits = total_rabbits(&rabbits);
	num_breeds = total_breeds(&rabbits);

	printf("The total number of rabbits is: %zu\n", num_rabbits);
	printf("The total number of rabbits breeds is: %zu\n", num_breeds);

	char breed_searched [MAX_WORD_LEN];
	printf("I want to search the breed:\n");
	scanf("%[^\n]", &breed_searched);
	rabbit_t* rabbit_breed_searched = find_rabbit(&rabbits, breed_searched);
	if (rabbit_breed_searched) printf("I found %s breed with %i rabbits.\n", rabbit_breed_searched->breed, rabbit_breed_searched->count);
	else printf("I don't found the rabbit D:\n");

	printf("I will print the rabbits sorted alfabetically\n");
	rabbit_sort(&rabbits, less_word);
  fprint_rabbits(&rabbits, stdout);

	printf("I will print the rabbits sorted by the cuantity of rabbits in each breed\n");
	rabbit_sort(&rabbits, less_count);
  fprint_rabbits(&rabbits, stdout);
  return 0;
}
