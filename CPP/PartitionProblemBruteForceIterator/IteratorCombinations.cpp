#include "IteratorCombinations.h"

IteratorCombinations::IteratorCombinations(int* num, int sum, int size) {
    this->size = size;
    this->combination = new int(size); 
    this->num = num;
    this->sum = sum;
}

bool IteratorCombinations::lastCombination() {
    for(int i = 0; i < size; i++){
        if(combination[i] == 0) return false;
    }
    return true;
}

void IteratorCombinations::nextCombination() {
    for(int i = 0; i < size; i++){
        if(combination[i] == maxValue){
            combination[i] = minValue;
        }else{
            combination[i] = maxValue;
            return;
        }
    }
}

bool IteratorCombinations::searchedCombination() {
    int actSum = totalValues();
    return (actSum == sum);
}

int IteratorCombinations::totalValues() {
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(combination[i] == 1){
            sum += num[i];
        }
    }
    return sum;
}

