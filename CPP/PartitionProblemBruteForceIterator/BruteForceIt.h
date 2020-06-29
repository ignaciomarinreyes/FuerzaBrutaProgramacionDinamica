#ifndef BRUTEFORCEIT_H
#define BRUTEFORCEIT_H

#include <string>
#include <iostream>
#include "IteratorCombinations.h"

using namespace std;

class BruteForceIt{
    private:
        int* num;
        int n;
        int sum = 0;
        bool found;
        void getResult();
        int add();
    public:
        BruteForceIt(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMillis, long timeNano, string scale);
        bool canPartition();
        void canPartitionIterator();
};

#endif /* BRUTEFORCEIT_H */

