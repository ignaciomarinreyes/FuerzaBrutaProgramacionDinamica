#include "ReadFile.h"

ReadFile::ReadFile(string folder) {
    path = folder;
}

int* ReadFile::ReadFolder(){ 
    
    ifstream myfile;
    myfile.open(path.c_str());    
    
    if (myfile.is_open()) {
        getline(myfile,line); 
        
        size = stoi(line);
        int* vector = new int[size];        
        int i = 0;
        
        while(getline(myfile,line)){
            vector[i] = stoi(line);
            i++;
        }
        
        myfile.close();
        return vector;
    }
    
    cout << "Unable to open file ->" << "fichVect.txt" << '\n'; 
    return NULL;
}

int ReadFile::getSize() {
    return size;
}




