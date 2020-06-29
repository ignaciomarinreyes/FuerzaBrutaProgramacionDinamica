#include "IteratorCombinations.h"

IteratorCombinations::IteratorCombinations(int* num, int sum, int size) {
    this->size = size;
    this->combination = new int[size]; 
    this->num = num;
    this->sum = sum;
}

bool IteratorCombinations::lastCombination() {
    for(int i = 0; i < size; i++){
        if(combination[i] == 0) return false;
    }
    return true;
}

bool IteratorCombinations::nextCombination() {
    for(int i = 0; i < size; i++){
        if(combination[i] == maxValue){
            combination[i] = minValue;
        }else{
            combination[i] = maxValue;
            if(isValidCombination()){
                return true;
            }else{
                combination[i] = minValue;
            }
        }
    }
    return false;
}

bool IteratorCombinations::searchedCombination() {
    int actSum = totalValues();
    return (totalVal == sum);
}

bool IteratorCombinations::isValidCombination() {
    return (totalValues() <= sum);
}

int IteratorCombinations::totalValues() {
    this->totalVal = 0;
    for(int i = 0; i < size; i++){
        if(combination[i] == 1){
            this->totalVal += num[i];
        }
    }
    return this->totalVal;
}

