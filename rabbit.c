/*
 * Implementation of the rabbit interface using Pintos lists.
 *
 * You may modify this file, and are expected to modify it.
 */

#include "rabbit.h"
#include "rabbit_helper.h"

void init_rabbits(rabbit_list_t *wclist)
{
  /* TODO */
  list_init(wclist);
}

size_t total_rabbits(rabbit_list_t *wclist)
{
  /* TODO */
  struct list_elem *iter;
  rabbit_t *rabbit;
  size_t count = 0;
  for (iter = list_begin(wclist); iter != list_end(wclist);
       iter = list_next(iter))
  {
    rabbit = list_entry(iter, rabbit_t, elem);
    count = count + rabbit->count;
  }
  return count;
}

size_t total_breeds(rabbit_list_t *rlist)
{
  /* TODO */
  return list_size(rlist);
}

rabbit_t *find_rabbit(rabbit_list_t *wclist, char *word)
{
  /* TODO */
  if (list_empty(wclist))
  {
    return NULL;
  }
  struct list_elem *iter;
  rabbit_t *rabbit;
  for (iter = list_begin(wclist); iter != list_end(wclist);
       iter = list_next(iter))
  {
    rabbit = list_entry(iter, rabbit_t, elem);
    if (strcmp(rabbit->breed, word) == 0)
    {
      return rabbit;
    }
  }
  return NULL;
}

rabbit_t *add_rabbit(rabbit_list_t *wclist, char *word)
{
  /* TODO */
  rabbit_t *r = find_rabbit(wclist, word);
  if (r == NULL)
  {
    rabbit_t *r = (rabbit_t *)malloc(sizeof(rabbit_t));
    r->breed = malloc(strlen(word) + 1);

    strncpy(r->breed, word, sizeof(word));

    r->count = 1;
    list_push_back(wclist, &r->elem);
  }
  else
    r->count = r->count + 1;
  return r;
}

void fprint_rabbits(rabbit_list_t *wclist, FILE *outfile)
{
  /* TODO */
  if (outfile == stdout)
  {
    if (list_empty(wclist))
    {
      return;
    }
    struct list_elem *iter;
    rabbit_t *rabbit;
    for (iter = list_begin(wclist); iter != list_end(wclist);
         iter = list_next(iter))
    {
      rabbit = list_entry(iter, rabbit_t, elem);
      printf("%s ", rabbit->breed);
    }
    printf("\n");
  }
  return;
}

static bool less_list(const struct list_elem *ewc1, const struct list_elem *ewc2, void *aux)
{
  /* TODO */
  //printf("less list %s - %s\n", list_entry(ewc1, rabbit_t, elem)->breed, list_entry(ewc2, rabbit_t, elem)->breed);
  //printf("%d\n", list_entry(ewc1, rabbit_t, elem) < list_entry(ewc2, rabbit_t, elem));
  //return list_entry(ewc1, rabbit_t, elem) < list_entry(ewc2, rabbit_t, elem);

  rabbit_t *r1 = list_entry(ewc1, rabbit_t, elem);
  rabbit_t *r2 = list_entry(ewc2, rabbit_t, elem);
  if (aux == less_count)
    return r1->count < r2->count || (r1->count == r2->count && strcmp(r1->breed, r2->breed) < 0);
  else
    return strcmp(r1->breed, r2->breed) < 0;
  //return aux(r1, r2);
}

void rabbit_sort(rabbit_list_t *wclist,
                 bool less(const rabbit_t *, const rabbit_t *))
{
  list_sort(wclist, less_list, less);
}
