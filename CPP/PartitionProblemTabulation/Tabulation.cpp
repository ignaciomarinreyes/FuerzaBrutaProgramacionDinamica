#include "Tabulation.h"

Tabulation::Tabulation(int* num, int size) {
    this->num = num;
    this->n = size;
}

void Tabulation::printVector() {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " | ";
    }
    cout << endl;
}

void Tabulation::getResult() {
    cout << "Results: " << sum << endl;
    
    string set1 = "{";
    string set2 = "{";
    int x = n;
    int currSum = sum;
    
    while (x > 0 && currSum >= 0){
         
        if (dp[x-1][currSum]){ 
            x--;
            set1 += to_string(num[x]) + ", ";                
        }else if (dp[x-1][currSum - num[x-1]]){ 
            x--; 
            currSum -= num[x]; 
            set2 += to_string(num[x]) + ", "; 
        } 
    } 
    
    set1 = set1.substr(0, set1.length()-2) + '}';
    set2 = set2.substr(0, set2.length()-2) + '}';
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;
}

void Tabulation::printResult() {
    if(found){
        cout << "\nVector can be partitioned" << endl;
        Tabulation::getResult();
    }else{
        cout << "\nVector can not be partitioned" << endl;
    }
}

void Tabulation::printTime(long timeMS, long timeNS, string scale) {
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

int Tabulation::add() {
    for (int i = 0; i < n; i++) sum += num[i];
        
    return sum;
}

bool Tabulation::canPartition() {
    int sum = add();
    return (sum % 2 == 0);
}

void Tabulation::canPartitionTab() {
    sum /= 2;
    
    dp = new bool*[n+1];
    for (int i = 0; i <= n; i++) dp[i] = new bool[sum+1];

    for(int i=0; i <= n; i++) dp[i][0] = true;

    for(int s=1; s <= sum ; s++) dp[0][s] = false;

    for(int i=1; i <= n; i++) {
        for(int s=1; s <= sum; s++) {
            
            if (s < num[i-1]) {  
                dp[i][s] = dp[i-1][s];
            }else{
                dp[i][s] = dp[i-1][s] || dp[i-1][s-num[i-1]];
            }
        }
    }
    found = dp[n][sum]; 
}

