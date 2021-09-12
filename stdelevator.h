#include <stdio.h>
struct passenger {
  int toFloor;
  struct passenger *next;
};

struct passenger **generatePassengers(int scenario);

struct passenger *current, *head, *tail;

int maxFloor1, maxFloor2;