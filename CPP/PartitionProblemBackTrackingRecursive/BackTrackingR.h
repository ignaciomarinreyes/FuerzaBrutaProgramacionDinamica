#ifndef BACKTRACKINGR_H
#define BACKTRACKINGR_H

#include <string>
#include <iostream>

using namespace std;

class BackTrackingR{
    private:
        int* num;
        int n;
        int sum = 0;
        bool found;
        void getResult();
        int add();
        bool canPartitionRecursive(int n, int s);
    public:
        BackTrackingR(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMillis, long timeNano, string scale);
        bool canPartition();
        void canPartitionRecursiveAux();
};

#endif /* BACKTRACKINGR_H */

