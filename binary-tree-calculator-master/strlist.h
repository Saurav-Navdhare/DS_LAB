#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
//defining structure of the list node
typedef struct _listNode {
  char string[MAX_STR];
  struct _listNode *next;
} LIST_NODE;
//push and print function call
void list_push(LIST_NODE **, char []);
void list_print(LIST_NODE *);

LIST_NODE *list_create_node(char word[])
{
  if (word == NULL) {
    return NULL;
  }

  LIST_NODE *newNode = (LIST_NODE *) malloc(sizeof(LIST_NODE));
  strcpy(newNode->string, word);
  newNode->next = NULL;

  return newNode;
}
//assigning the values to the variables in the list
void list_push(LIST_NODE **list, char word[])
{
  LIST_NODE *newNode = list_create_node(word);
  LIST_NODE *currentNode = *list;

  if (*list == NULL) {
    *list = newNode;
    return;
  }
//taking the input till the next link is NULL value
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
}
//displaying the content of the list
void list_print(LIST_NODE *list)
{
  if (list == NULL) {
    printf("The list is empty.\n\n");
  }
  printf("Item of the list: \n");
  while (list != NULL) {
    printf("    %s\n", list->string);
    list = list->next;
  }
  printf("\n");
}
