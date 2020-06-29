#ifndef MEMOIZATION_H
#define MEMOIZATION_H

#include <iostream>
#include <string>

using namespace std;

class Memoization {
    private:
        int* num;
        char** mp;
        int n;
        int sum = 0;
        char found;
        void getResult();
        int add();
        char canPartitionMemo(int i, int s);
    public:
        Memoization(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMS, long timeNS, string scale);
        bool canPartition();
        void canPartitionAux();
};

#endif /* MEMOIZATION_H */

