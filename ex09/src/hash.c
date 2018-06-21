#include "hash.h"
#include <stddef.h>
#include <stdlib.h>
#include "../../ex07/include/linked_list.h"

hashtable_t     *hash_create(unsigned int size)
{
  hashtable_t *new_table;
  unsigned int i;

  if (size <= 0)
    return NULL;

  new_table = malloc(sizeof(hashtable_t));
  new_table->table = malloc(size * sizeof(node_t*));
  i = -1;
  while (++i < size)
    new_table->table[i] = NULL;
  new_table->size = size;
  return new_table;
}

void    hash_destroy(hashtable_t *ht, void (*fp)(void *data))
{
  unsigned int i;
  node_t *ptr;

  i = -1;
  while (++i < ht->size)
  {
    if (ht->table[i] != NULL)
    {
      ptr = ht->table[i];
      list_destroy(&(ptr), fp);
    }
  }
  free(ht->table);
  free(ht);
}

unsigned int    hash_func(char *key)
{
  unsigned int res;

  if (key == NULL)
    return 0;
  res = 0;
  while(*key != '\0')
  {
    res += *key;
    key++;
  }
  return res;
}

void    hash_set(hashtable_t *ht, char *key, void *ptr, void (*fp)(void *data))
{
  int i;

  i = hash_func(key) % ht->size;
  fp(ptr);
  if (ht->table[i] == NULL)
    ht->table[i] = list_create(ptr);
  else
    list_push(ht->table[i], ptr);
}

void    *hash_get(hashtable_t *ht, char *key)
{
  int i;
  node_t *ptr;

  i = hash_func(key) % ht->size;
  if (ht->table[i] == NULL)
    return NULL;
  ptr = ht->table[i];
  return ptr->data;
}
