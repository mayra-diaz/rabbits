/*
 * Implementation of the rabbit comparator functions.
 *
 * You may modify this file, and are expected to modify it.
 */

#include "rabbit_helper.h"

bool less_count(const rabbit_t *r1, const rabbit_t *r2)
{
  /* TODO */
  return r1->count < r2->count || (r1->count == r2->count && strcmp(r1->breed, r2->breed) < 0);
};

bool less_word(const rabbit_t *r1, const rabbit_t *r2)
{
  /* TODO */
  printf("%s vs %s: %d\n", r1->breed, r2->breed, strcmp(r1->breed, r2->breed) < 0);
  return strcmp(r1->breed, r2->breed) < 0;
};