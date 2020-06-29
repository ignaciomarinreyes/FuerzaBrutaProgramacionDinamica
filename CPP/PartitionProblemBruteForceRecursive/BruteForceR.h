#ifndef BRUTEFORCER_H
#define BRUTEFORCER_H

#include <string>
#include <iostream>

using namespace std;

class BruteForceR{
    private:
        int* num;
        bool* combination;
        int n;
        int sum = 0;
        bool found;
        void getResult();
        int add();
        void canPartitionRecursive(int sum, int size);
        void searchedCombination();
    public:
        BruteForceR(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMillis, long timeNano, string scale);
        bool canPartition();
        void canPartitionRecursiveAux();
};

#endif /* BRUTEFORCER_H */

