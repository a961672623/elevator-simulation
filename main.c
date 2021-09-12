#include "stdelevator.h"
#include <stdio.h>

int main() {

  // S1
  //   struct passenger **passengers = generatePassengers(1);
  //   struct passenger *current = passengers[0];
  //   while (current != NULL) {
  //     printf("passenger: %d\n", current->toFloor);
  //     current = current->next;
  //   }

  // S2
  //     struct passenger **passengers = generatePassengers(2);
  //     struct passenger *current1 = passengers[0];
  //     struct passenger *current2 = passengers[1];
  //     int totalNum = 0;
  //     while (current1 != NULL) {
  //       printf("passenger: %d\n", current1->toFloor);
  //       current1 = current1->next;
  //       totalNum += 1;
  //     }
  //     printf("==============\n");
  //     while (current2 != NULL) {
  //       printf("passenger: %d\n", current2->toFloor);
  //       current2 = current2->next;
  //       totalNum += 1;
  //     }
  //     printf("totalNum: %d\n", totalNum);

  // S3
  //     struct passenger **passengers = generatePassengers(3);
  //     struct passenger *current1 = passengers[0];
  //     struct passenger *current2 = passengers[1];
  //     int totalNum = 0;
  //     while (current1 != NULL) {
  //       printf("passenger: %d\n", current1->toFloor);
  //       current1 = current1->next;
  //       totalNum += 1;
  //     }
  //     printf("==============\n");
  //     while (current2 != NULL) {
  //       printf("passenger: %d\n", current2->toFloor);
  //       current2 = current2->next;
  //       totalNum += 1;
  //     }
  //     printf("totalNum: %d\n", totalNum);

  // S4
  //   struct passenger **passengers = generatePassengers(4);
  //   struct passenger *current1 = passengers[0];
  //   struct passenger *current2 = passengers[1];
  //   struct passenger *current3 = passengers[2];
  //   int totalNum = 0;
  //   while (current1 != NULL) {
  //     printf("passenger: %d\n", current1->toFloor);
  //     current1 = current1->next;
  //     totalNum += 1;
  //   }
  //   printf("==============\n");
  //   while (current2 != NULL) {
  //     printf("passenger: %d\n", current2->toFloor);
  //     current2 = current2->next;
  //     totalNum += 1;
  //   }
  //   printf("==============\n");
  //   while (current3 != NULL) {
  //     printf("passenger: %d\n", current3->toFloor);
  //     current3 = current3->next;
  //     totalNum += 1;
  //   }
  //   printf("totalNum: %d\n", totalNum);

  for (int i = 1; i < 100; i++) {
    maxFloor1 = 10;
     struct passenger **passengers = generatePassengers(3);
    struct passenger *current1 = passengers[0];
    struct passenger *current2 = passengers[1];
    int totalNum = 0;
    while (current1 != NULL) {
      printf("passenger: %d\n", current1->toFloor);
      current1 = current1->next;
      totalNum += 1;
    }
    printf("==============\n");
    while (current2 != NULL) {
      printf("passenger: %d\n", current2->toFloor);
      current2 = current2->next;
      totalNum += 1;
    }
    printf("totalNum: %d\n", totalNum);
  }

  return 0;
}