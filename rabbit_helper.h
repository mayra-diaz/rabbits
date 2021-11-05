#ifndef RABBIT_HELPERS_H
#define RABBIT_HELPERS_H

#include <ctype.h>
#include <stdio.h>

#include "rabbit.h"
/*
 * Returns true if the first entry has a lower count than the second entry,
 * breaking ties according to alphabetical order.
 */
bool less_count(const rabbit_t* r1, const rabbit_t* r2);

/*
 * Returns true if the first entry comes before the second entry in
 * alphabetical order.
 */
bool less_word(const rabbit_t* r1, const rabbit_t* r2);

#endif /* RABBIT_HELPERS_H */