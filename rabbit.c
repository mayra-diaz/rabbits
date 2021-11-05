/*
 * Implementation of the rabbit interface using Pintos lists.
 *
 * You may modify this file, and are expected to modify it.
 */


#include "rabbit.h"

void init_rabbits(rabbit_list_t* wclist) { 
  /* TODO */
  list_init(wclist);
}

size_t total_rabbits(rabbit_list_t* wclist) {
  /* TODO */
  struct list_elem *iter;
  rabbit_t *rabbit;
  size_t count = 0;
  for (iter = list_begin(wclist); iter != list_end(wclist);
       iter = list_next(iter)){
    rabbit = list_entry(iter, rabbit_t, elem);
    count = count + rabbit->count;
  }
  return count;
}

size_t total_breeds(rabbit_list_t* rlist) {
    /* TODO */
  return list_size(rlist);
}

rabbit_t* find_rabbit(rabbit_list_t* wclist, char* word) {
  /* TODO */
  if(list_empty(wclist)){
    return NULL;
  }
  struct list_elem* iter;
  rabbit_t *rabbit;
  for (iter = list_begin(wclist); iter != list_end(wclist);
       iter = list_next(iter)){
    rabbit = list_entry(iter, rabbit_t, elem);
    if (strcmp(rabbit->breed, word) == 0) {
      return rabbit;
    }
  }
  return NULL;
}

rabbit_t* add_rabbit(rabbit_list_t* wclist, char* word) {
  /* TODO */
  rabbit_t *r = find_rabbit(wclist, word);
  if (r == NULL){
    rabbit_t* r = (rabbit_t*) malloc(sizeof(rabbit_t));
    r->breed = malloc(strlen(word)+1);
    
    strncpy(r->breed, word, sizeof(word));
    
    r->count = 1;
    list_push_back(wclist, &r->elem);
  }
  else
    r->count = r->count + 1;
  return r;
}

void fprint_rabbits(rabbit_list_t* wclist, FILE* outfile) { 
  /* TODO */
  return;
}

static bool less_list(const struct list_elem* ewc1, const struct list_elem* ewc2, void* aux) {
  /* TODO */
  return false;
}

void rabbit_sort(rabbit_list_t* wclist,
                    bool less(const rabbit_t*, const rabbit_t*)) {
  list_sort(wclist, less_list, less);
}
