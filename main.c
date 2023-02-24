#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Node.h"
#include "Queue.h"

int main(int argc, char **argv) {
  // NodePtr headPtr = NULL;
  // NodePtr tailPtr = NULL;
// For struct Queue
  Queue  q;
  q.headPtr=NULL;
  q.tailPtr=NULL;
  q.size=0;

  int i, x, customer=0;

  for(i = 1; i < argc; i++){
    if(strcmp(argv[i], "x") == 0){
      int cash;
      printf("Customer no: %d\n", ++customer);
      x = dequeue_struct(&q);

      if(x != 0) {
        printf("You have to pay %d\n", x);
        do {
          printf("Cash: ");
          scanf("%d", &cash);
        } while(cash < x);

        printf("Thank you\n");
        if(cash > x) {
          printf("Change is: %d\n", cash-x);
        }
      } else {
        printf("Thank you\n");
      }
    } else {
      // enqueue(&headPtr, &tailPtr, atoi(argv[i]));
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
      printf("My order is %d\n", atoi(argv[i]));
      i++;
    }
  }

  printf("==============================\n");
  int count_q = count_queue(&q);
  if(count_q == 1) {
    printf("There is %d ppl left in the queue.", count_q);
  } else if(count_q > 1) {
    printf("There are %d ppl left in the queue.", count_q);
  }

  for(NodePtr temp; q.headPtr != NULL; q.headPtr = q.headPtr->nextPtr) {
    temp = q.headPtr;
    free(temp);
  }

  return 0;
}
