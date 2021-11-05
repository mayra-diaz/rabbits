/*
 * The rabbit interface provides lists of rabbits and associated counts.
 *
 * You may NOT modify this file. Any changes you make to this file will not
 * be used when grading your submission.
 */

#ifndef RABBIT_H
#define RABBIT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "list.h"

typedef struct rabbit {
  char* breed;
  int count;
  struct list_elem elem;
} rabbit_t;

typedef struct list rabbit_list_t;

/* Initialize a rabbit list. */
void init_rabbits(rabbit_list_t* rlist);

/*
 * Insert a rabbit breed with count=1, if not already present; increment count if
 * present.
 */
rabbit_t* add_rabbit(rabbit_list_t* rlist, char* word);

/* Get the total count of rabbits in a rabbit list. */
size_t total_rabbits(rabbit_list_t* rlist);

/* Get the total count of rabbits breeds in a rabbit list. */
size_t total_breeds(rabbit_list_t* rlist);

/* Find a breed in a rabbit list. */
rabbit_t* find_rabbit(rabbit_list_t* rlist, char* breed);


/* Print rabbit breed count to a file. */
void fprint_rabbits(rabbit_list_t* rlist, FILE* outfile);

/* Sort a rabbit list using the provided comparator function. */
void rabbit_sort(rabbit_list_t* rlist, bool less(const rabbit_t*, const rabbit_t*));

#endif /* RABBIT_H */
