#include "../include/linked_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

node_t   *list_create(void *data)
{
  node_t *head = malloc(sizeof(node_t));
  head->data = data;
  head->next = NULL;
  return head;
}

void  list_destroy(node_t **head, void (*fp)(void *data))
{
  node_t *pointer, pointer2;
  
  if (*head == NULL)
    return;
  pointer = *head;
  while(pointer != NULL)
  {
    fp(pointer->data);
    pointer2 = pointer->next;
    free(pointer);
    pointer = pointer2;
  }

  (*head) = NULL;
}

void  list_push(node_t *head, void *data)
{
  if (head == NULL)
    return;
  while (head->next)
    head = head->next;
  head->next = malloc(sizeof(node_t));
  head = head->next;
  head->next = NULL;
  head->data = data;
}

void  list_unshift(node_t **head, void *data)
{
  node_t *pointer;
  
  pointer = *head;
  *head = malloc(sizeof(node_t));
  (*head)->next = pointer;
  (*head)->data = data;
}

void  *list_pop(node_t **head)
{
    node_t* prev;
    void *data;

    prev = NULL;
    if (head == NULL)
      exit(-1);
    prev = (*head);
    data = prev->data;
    (*head) = (*head)->next;
    free(prev);
    return data;
}

node_t* getNth(node_t* head, int n) {
    int counter;

    counter = -1;
    while (++counter < n && head)
      head = head->next;
    return head;
}

void  *list_shift(node_t **head)
{
  void *r;
node_t *pointer;
 
  pointer = *head;
  if (*head == NULL)
    return NULL;
  (*head) = (*head)->next;
  r = pointer->data;
  free(pointer->data);
  free(pointer);
  return r;
}

void  *list_remove(node_t **head, int pos)
{
  void *data;
  node_t *prev, *elm;

  if (pos == 0) 
    return list_pop(head);
  else
  {
     prev = getNth(*head, pos-1);
     elm  = prev->next;
     data = elm->data;
     prev->next = elm->next;
     free(elm);
     return data;
    }
}


void  list_print(node_t *head)
{
  while(head)
  {
    printf("%p ", (char*)head->data);
    head = head->next;
  }
  printf("\n");
}

void  list_visitor(node_t *head, void (*fp)(void *data))
{
  while(head)
  {
    fp(head->data);
    head = head->next;
  }
}
