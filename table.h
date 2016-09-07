#ifndef _TABLE_H
#define _TABLE_H

#include <stddef.h>

typedef void* table_t;
typedef int(*cmp_func)(void*, void*, size_t);
typedef unsigned long(*hash_func)(void*, size_t);
                      /*arg,    key,   keylen, data */
typedef int(*iter_func)(void *, void*, size_t, void*);

table_t table_new(hash_func h, cmp_func c);

int table_insert(table_t, void *key, size_t keylen, void *data);

int table_get(table_t, void *key, size_t keylen, void **dataptr);

int table_remove(table_t, void *key, size_t keylen);

int table_iter(table_t, iter_func, void*);

void *table_fetch_key(table_t, void *key, size_t keylen);
void *table_fetch_val(table_t, void *key, size_t keylen);

#endif
