// generatePassengers(secenario={1,2,3,4})

int* countTime(struct passenger *elevator)  // count the times of one elevator, one time
{
    int totalTime = 0;  // total time for this elevator
    int pasNum = 0;     // total number of passengers
    int stopped = 0;    // the number of stopped floors
    current = elevator;
    int currentFloor, nextFloor = 1;
    int ret[2];
    while (current!=NULL)
    {
        nextFloor = current->toFloor;
        totalTime += 3*(nextFloor-currentFloor);
        if (nextFloor > currentFloor)
        {
            stopped += 1;  // because some ajacent passengers may have the same destination,
        }                   // we need to count the number of floors that the elevator stopped.
        currentFloor = nextFloor;
        current = current->next;
        pasNum += 1;
    }
    totalTime += 15*stopped;
    ret[0] = totalTime;
    ret[1] = pasNum;
    return ret; // [total time, passenger numbers]
}

int* timerOne(struct passenger* one)
{
    float avgTimePer, res[2]; 
    int *ret = countTime(one);    // obtain the result of one-time operation (total-time and passengers)
    avgTimePer = (float) ret[0] / (float) ret[1];
    res[0] = (float) ret[0];
    res[1] = avgTimePer;
    return res;
}

// int timerTwo(struct passenger* one, struct passenger* two)
// {}

// int timerTwoOpt(struct passenger* one, struct passenger* two, int maxFloor)
// {}

float analysis(float *totalTime, float *avgTimePer, int runTime)    // analyze the result of 1000 times run
{
    float max, min, avgTotal, avgPer, sumTotal, sumTimePer, ret[4];
    sumTotal = 0;
    sumTimePer = 0;
    max = totalTime[0];
    min = totalTime[0];
    for (int i=0; i<runTime; i++)
    {
        if (*(totalTime+i) > max)
        {
            max = *(totalTime+i);
        }
        if (*(totalTime+i) < min)
        {
            min = *(totalTime+i);
        }
        sumTotal += *(totalTime+i);
        sumTimePer += *(avgTimePer+i);
    }
    avgTotal = sumTotal / runTime;
    avgPer = sumTimePer / runTime;
    ret[0] = max;
    ret[1] = min;
    ret[2] = avgTotal;
    ret[3] = avgPer;

    return ret;
}

void runOne1000(int runTime)    // scenario 1
{
    float *res, *resFinal;
    float totalTime[runTime], avgTimePer[runTime];

    for (int i=0; i<runTime; i++)
    {
        printf("-----run time:(%d/%d)-----\n", i+1, runTime);
        A = generatePassengers(1);  // generate a new list of passengers
        res = timerOne(A);
        totalTime[i] = res[0];
        avgTimePer[i] = res[1];
    }

    resFinal = analysis(totalTime, avgTimePer, int runTime);
    printf("After %d times running, the results are:\n", runTime);
    printf("Maximum Total Time: %.3f\n", resFinal[0]);
    printf("Minimum Total Time: %.3f\n", resFinal[1]);
    printf("Average Total Time: %.3f\n", resFinal[2]);
    printf("Average Time Per Passenger: %.3f\n", resFinal[3]);
}

void runTow1000(int runTime)    // scenario 2
{}

void runTwoOpt1000(int runTime) // scenario 3
{}

void runThree1000(int runTime)  // scenario 4
{}