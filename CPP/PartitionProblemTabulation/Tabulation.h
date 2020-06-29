#ifndef TABULATION_H
#define TABULATION_H

#include <string>
#include <iostream>

using namespace std;

class Tabulation{
    private:
        int* num;
        bool** dp;
        int n;
        int sum = 0;
        bool found;
        void getResult();
        int add();
    public:
        Tabulation(int* num, int size);
        void printVector();
        void printResult();
        void printTime(long timeMillis, long timeNano, string scale);
        bool canPartition();
        void canPartitionTab();
};

#endif /* TABULATION_H */

