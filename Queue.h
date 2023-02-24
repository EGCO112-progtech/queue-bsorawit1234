typedef struct {
  NodePtr headPtr, tailPtr;
	int size;
} Queue;

void enqueue_struct(Queue* q, int x, int y){
  NodePtr new_node = (NodePtr) malloc(sizeof(Node));
  if(new_node) { 
    /*Finish enqueue */
    new_node->order_number = x;
    new_node->qty = y;
    new_node->nextPtr = NULL;

    if(!(q->headPtr)) q->headPtr = new_node;
    else q->tailPtr->nextPtr = new_node;

    q->tailPtr = new_node;
    q->size += 1;
  }
}


int dequeue_struct(Queue *q){
  NodePtr t = q->headPtr;
  int price;

  if(q->size > 0) {
    switch (t->order_number) {
    case 1:
      printf("Ramen\n");
      price = 100;
      break;
    case 2:
      printf("Somtum\n");
      price = 20;
      break;
    case 3:
      printf("KFC\n");
      price = 50;
      break;
    default:
      printf("No Food\n");
      price = 0;
      break;
    }
  }

  if(t) {
    int value = price * q->headPtr->qty;
    q->headPtr = q->headPtr->nextPtr;
    if(!(q->headPtr)) q->tailPtr = NULL;
    free(t);
    q->size -= 1;
    return value;
  }
  printf("The queue is empty\n");
  return 0;
}

int count_queue(Queue *q) {
  NodePtr temp = q->headPtr;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp->nextPtr;
  }
  return count;
}