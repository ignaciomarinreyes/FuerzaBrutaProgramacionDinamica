#ifndef ITERATORCOMBINATIONS_H
#define ITERATORCOMBINATIONS_H

#include <iostream>

using namespace std;

class IteratorCombinations {
    private:
        int* combination;
        int* num;
        int sum;
        int size;
        const int maxValue = 1;
        const int minValue = 0;
        
    public:    
        IteratorCombinations(int* num, int sum, int size);
        bool lastCombination();
        void nextCombination();
        bool searchedCombination();
        int totalValues();
};

#endif /* ITERATORCOMBINATIONS_H */

