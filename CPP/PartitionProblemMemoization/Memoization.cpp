#include "Memoization.h"

Memoization::Memoization(int* num, int size) {
    this->num = num;
    this->n = size;       
}

void Memoization::printVector() {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " | ";
    }
    cout << endl;
}

void Memoization::getResult() {
    cout << "Results: " << sum << endl;
    
    string set1 = "{";
    string set2 = "{";
    int x = n;
    int curr = sum;
    
    while (x > 0 && curr >= 0){
            
            if (mp[x-1][curr] == '1'){ 
                x--;
                set1 += to_string(num[x]) + ", ";                
            }else if (mp[x-1][curr-num[x-1]] == '1'){ 
                x--; 
                curr -= num[x]; 
                set2 += to_string(num[x]) + ", "; 
            } 
        }
    
    set1 = set1.substr(0, set1.length()-2) + '}';
    set2 = set2.substr(0, set2.length()-2) + '}';
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;
}

void Memoization::printResult() {
    if(found == '1'){
        cout << "\nVector can be partitioned" << endl;
        Memoization::getResult();
    }else{
        cout << "\nVector can not be partitioned" << endl;
    }
}

void Memoization::printTime(long timeMS, long timeNS, string scale) {
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

int Memoization::add() {
    for (int i = 0; i < n; i++) sum += num[i];
    return sum;
}

bool Memoization::canPartition() {
    int sum = add();
    return (sum % 2 == 0);
}

void Memoization::canPartitionAux() {
    sum /= 2; 
    mp = new char*[n+1];    
    
    for(int a = 0; a <= n; a++) mp[a] = new char[sum+1];
    
    for(int i=0; i <= n; i++) mp[i][0] = '1';

    for(int s=1; s <= sum ; s++) mp[0][s] = '0';    
    
    found = Memoization::canPartitionMemo(n, sum);
}

char Memoization::canPartitionMemo(int i, int s) {
    if(mp[i][s] != '\0'){
        return mp[i][s];
    }
    
    if(s <= 0) return '1';
    
    if(i == 0) return '0';
    
    char result;
    if(s < num[i-1]){
        result = Memoization::canPartitionMemo(i-1, s);
    }else{
        result = Memoization::canPartitionMemo(i-1, s) |
                Memoization::canPartitionMemo(i-1, s-num[i-1]);
    }
    
    mp[i][s] = result;
    
    return result;
}




