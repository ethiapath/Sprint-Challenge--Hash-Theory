#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  // YOUR CODE HERE
  HashTable *ht = create_hash_table(16);
  for (int i = 0; i < length; i++)
  {
    int weight = weights[i];

    // if compliment has been stored
    int compliment_i = hash_table_retrieve(ht, weight);
    // hash_table_insert(ht, limit - weight, i);

    printf("compliment %d, weight: %d \n", compliment_i, weight);
    if (weights[compliment_i] + weight == limit)
    {
      // return answer
      Answer * ans = malloc(sizeof(Answer));
      ans->index_1 = i;
      ans->index_2 = compliment_i;
      return ans;
    }
    else
    {
      // store comp with index
      // key is weight comp, value is index
      hash_table_insert(ht, limit - weight, i);
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif