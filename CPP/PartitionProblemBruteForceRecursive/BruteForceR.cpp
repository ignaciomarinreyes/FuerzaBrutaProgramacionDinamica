#include "BruteForceR.h"

BruteForceR::BruteForceR(int* num, int size) {
    this->num = num;
    this->n = size;
}

void BruteForceR::printVector() {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " | ";
    }
    cout << endl;
}

void BruteForceR::getResult() {
    cout << "Results: " << sum << endl;    
}

void BruteForceR::printResult() {
    if(found){
        cout << "\nVector can be partitioned" << endl;
        BruteForceR::getResult();
    }else{
        cout << "\nVector can not be partitioned" << endl;
    }
}

void BruteForceR::printTime(long timeMS, long timeNS, string scale) {
    printf("For %d elements -> Taken time: ", n); 
    float print = (float) ((timeMS == 0)? timeNS/1e9 : timeMS/1e3);
    if(scale.empty()){
        printf("%.8f s.\n", print);
    }else{
        if(scale == "ns"){
            cout << timeNS << " " << scale << '.' << endl;
        }else if(scale == "ms"){
            cout << timeMS << " " << scale << '.' << endl;
        }else{
            printf("%.8f s.\n", print);
        }
    }
}

int BruteForceR::add() {
    for (int i = 0; i < n; i++) sum += num[i];
        
    return sum;
}

bool BruteForceR::canPartition() {
    int sum = add();
    return (sum % 2 == 0);
}

void BruteForceR::canPartitionRecursiveAux(){
    sum /= 2;
    combination = new bool[n];
    BruteForceR::canPartitionRecursive(sum, n-1);
}

void BruteForceR::canPartitionRecursive(int sum, int size) {
    if (size == 0){
        searchedCombination();
    } else {
        combination[size]=true;
        canPartitionRecursive(sum, size - 1);
        combination[size]=false;
        canPartitionRecursive(sum, size - 1); 
       }
    }
    
void BruteForceR::searchedCombination() {
    int actualSum=0;        
    for (int i = 0; i < n; i++) {
        if (combination[i] == true){
            actualSum += num[i];
        }    
    }
    if (actualSum == sum){
        found = true;
    }     
}

