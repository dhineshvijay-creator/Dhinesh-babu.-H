#include <stdio.h> 
#include <stdbool.h>
#define CAP 3 // the maximum number of elements
int items[CAP]; // storage for queue
int end = 0; // index of next available position (number of elements)
// returns true if no elements otherwise false bool isEmpty() {
   return end == 0;
}
// returns true if array is at capacity otherwise false bool isFull() {
   return end == CAP;
}
// returns number of elements int size() {
   return end;
}
// add element to the end of the queue void enqueue(int num) {
   if(!isFull())
       items[end++] = num;
}
// removes element from the front of the queue int dequeue() {
   if (!isEmpty()) {
       int num = items[0];
       for (int i=0; i < end; i++)
           items[i] = items[i+1];
        end--;
       return num;
   }
   return -1;
}
int main() {
   // check if queue is empty and print a message if it is
   if(isEmpty())
       printf(''Queue is empty\n'');
   // insert 3 elements (5, 4, 8) to the queue using enqueue operation
   enqueue(5);
   enqueue(4);
   enqueue(8);
   // check if queue is full and print a message if it is
   if(isFull())
       printf(''Queue is full\n'');
   enqueue(3); // should not insert since full
   printf(''Queue size: %d\n'', size());
   // remove 3 elements from the queue using dequeue operation
   for (int i=0; i < CAP; i++)
       printf(''%d '',dequeue());
   printf(''\n'');
   printf(''Queue size: %d\n'', size());
}