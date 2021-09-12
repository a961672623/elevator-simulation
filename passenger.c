#include "stdelevator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generate a random number in [min, max]
int generateRandomInt(int min, int max) { return rand() % (max - min) + min; }

// generate a passengerList sorted by toFloor.
struct passenger *generatePassengerList(int num, int lowestFloor,
                                        int highestFloor) {
  struct passenger *dummy = malloc(sizeof(struct passenger));
  dummy->toFloor = -1;
  dummy->next = NULL;

  for (int i = 0; i < num; i++) {
    struct passenger *newPassenger = malloc(sizeof(struct passenger));
    struct passenger *current = dummy;
    int toFloor = generateRandomInt(lowestFloor, highestFloor);
    newPassenger->toFloor = toFloor;
    while (current->next != NULL && current->next->toFloor < toFloor) {
      current = current->next;
    }
    newPassenger->next = current->next;
    current->next = newPassenger;
  }
  return dummy->next;
}

/*
@params: int scenario: 4 scenarios list in PA.
@return: passengerList[]
*/
struct passenger **generatePassengers(int scenario) {
  srand((unsigned)time(NULL));
  static struct passenger *passengers[3];
  static struct passenger *p1, *p2, *p3;

  switch (scenario) {
    int num1, num2, num3, total;
  case 1:
    printf("scenario 1\n");
    num1 = generateRandomInt(1, 18);
    p1 = generatePassengerList(num1, 1, 20);
    break;
  case 2:
    printf("scenario 2\n");
    total = generateRandomInt(2, 18);
    num1 = generateRandomInt(1, total - 1);
    num2 = total - num1;
    p1 = generatePassengerList(num1, 1, 20);
    p2 = generatePassengerList(num2, 1, 20);
    break;
  case 3:
    printf("scenario 3\n");
    total = generateRandomInt(2, 18);
    num1 = generateRandomInt(1, total - 1);
    num2 = total - num1;
    p1 = generatePassengerList(num1, 1, maxFloor1);
    p2 = generatePassengerList(num2, maxFloor1 + 1, 20);
    break;
  case 4:
    printf("scenario 4\n");
    total = generateRandomInt(3, 18);
    num1 = generateRandomInt(1, total - 2);
    num2 = generateRandomInt(1, total - num1 - 1);
    num3 = generateRandomInt(1, total - num1 - num2);
    p1 = generatePassengerList(num1, 1, 7);
    p2 = generatePassengerList(num2, 8, 14);
    p3 = generatePassengerList(num3, 15, 20);
    break;
  }
  passengers[0] = p1;
  passengers[1] = p2;
  passengers[2] = p3;
  return passengers;
}

// int main() {

// S1
//   struct passenger **passengers = generatePassengers(1);
//   struct passenger *current = passengers[0];
//   while (current != NULL) {
//     printf("passenger: %d\n", current->toFloor);
//     current = current->next;
//   }

// S2
//   struct passenger **passengers = generatePassengers(2);
//   struct passenger *current1 = passengers[0];
//   struct passenger *current2 = passengers[1];
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
//   printf("totalNum: %d\n", totalNum);

// S3
//   struct passenger **passengers = generatePassengers(3);
//   struct passenger *current1 = passengers[0];
//   struct passenger *current2 = passengers[1];
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
//   printf("totalNum: %d\n", totalNum);

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

//   return 0;
// }
