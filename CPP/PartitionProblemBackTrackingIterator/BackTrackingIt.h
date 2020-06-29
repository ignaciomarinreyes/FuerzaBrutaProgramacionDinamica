#ifndef BACKTRACKINGIT_H
#define BACKTRACKINGIT_H

#include <string>
#include <iostream>
#include "IteratorCombinations.h"

using namespace std;

class BackTrackingIt{
    private:
        int* num;
        int n;
        int sum = 0;
        bool found;
        void getResult();
        int add();
    public:
        BackTrackingIt(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMillis, long timeNano, string scale);
        bool canPartition();
        void canPartitionIterator();
};

#endif /* BACKTRACKINGIT_H */

