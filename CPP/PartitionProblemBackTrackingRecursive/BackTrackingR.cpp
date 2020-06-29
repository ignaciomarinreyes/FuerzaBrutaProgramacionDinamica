#include "BackTrackingR.h"

BackTrackingR::BackTrackingR(int* num, int size) {
    this->num = num;
    this->n = size;
}

void BackTrackingR::printVector() {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " | ";
    }
    cout << endl;
}

void BackTrackingR::getResult() {
    cout << "Results: " << sum << endl;    
}

void BackTrackingR::printResult() {
    if(found){
        cout << "\nVector can be partitioned" << endl;
        BackTrackingR::getResult();
    }else{
        cout << "\nVector can not be partitioned" << endl;
    }
}

void BackTrackingR::printTime(long timeMS, long timeNS, string scale) {
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

int BackTrackingR::add() {
    for (int i = 0; i < n; i++) sum += num[i];
        
    return sum;
}

bool BackTrackingR::canPartition() {
    int su = add();
    return (su % 2 == 0);
}

void BackTrackingR::canPartitionRecursiveAux(){
    sum /= 2;
    found = BackTrackingR::canPartitionRecursive(n-1, sum);
}

bool BackTrackingR::canPartitionRecursive(int n, int s) {
    if (s <= 0) return true;

    if(n < 0) return false;

    if(s < num[n]){
        return BackTrackingR::canPartitionRecursive(n-1, s);
    }else{
        return (BackTrackingR::canPartitionRecursive(n-1, s) |
                BackTrackingR::canPartitionRecursive(n-1, s-num[n]));
    }
        
}


