#include "BackTrackingIt.h"

BackTrackingIt::BackTrackingIt(int* num, int size) {
    this->num = num;
    this->n = size;
}

void BackTrackingIt::printVector() {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " | ";
    }
    cout << endl;
}

void BackTrackingIt::getResult() {
    cout << "Results: " << sum << endl;    
}

void BackTrackingIt::printResult() {
    if(found){
        cout << "\nVector can be partitioned" << endl;
        BackTrackingIt::getResult();
    }else{
        cout << "\nVector can not be partitioned" << endl;
    }
}

void BackTrackingIt::printTime(long timeMS, long timeNS, string scale) {
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

int BackTrackingIt::add() {
    for (int i = 0; i < n; i++) sum += num[i];
        
    return sum;
}

bool BackTrackingIt::canPartition() {
    int sum = add();
    return (sum % 2 == 0);
}

void BackTrackingIt::canPartitionIterator() {
    sum /= 2;    
    IteratorCombinations* it = new IteratorCombinations(num, sum, n);
    while(!it->lastCombination() && it->nextCombination()){
        if(it->searchedCombination()) found = true;
    }
    delete(it);
}

