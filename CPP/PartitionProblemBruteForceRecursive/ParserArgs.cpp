#include "ParserArgs.h"

ParserArgs::ParserArgs(int argcA, char** argsA) {
    argc = argcA;
    args = argsA;
    if(argc <= 1) ParserArgs::error("ERROR! No arguments\n");
}

void ParserArgs::print(){       
    cout << usage << endl;
    cout << message << endl;
    cout << input << endl; 
    cout << output << endl; 
    cout << time << endl; 
    cout << folder << endl;   
    cout << help << endl;
}

void ParserArgs::parseArg(){
    int opt;
    while ((opt = getopt_long(argc,args,"hf:iot::",long_options,&option_index)) != -1){
        switch(opt) {
            case '0': break;
            case 'h':
                bHelp = true; break;
            case 'f': 
                bFolder = true; fichero = optarg; break;
            case 'i':
                bInput = true; break;
            case 'o':
                bOutput = true; break;
            case 't':
                bTime = true; if(optarg) scale = optarg; break;  
            case '?': 
                if(optopt == 'f') ParserArgs::error(""); break;
            default: ParserArgs::error("ERROR! Wrong option\n");
        }
    }
    
    if(bHelp){
        ParserArgs::print(); 
        exit(0);
    }
    
    if(bFolder){
        ParserArgs::fileOption(fichero);    
    }else{
        ParserArgs::error("ERROR! File not selected\n");
    }
}

void ParserArgs::fileOption(string fich){
    
    ifstream myfile;
    myfile.open(fich.c_str());    
    
    if(myfile.is_open()){
        myfile.close();
        
        ReadFile* file = new ReadFile(fich);
        int* vector = file->ReadFolder();
        int size = file->getSize();
        
        BruteForceR* recBF = new BruteForceR(vector, size);
        
        if(bInput){
            cout << "Vector is : " << endl; 
            recBF->printVector();
        }
        
        if (!recBF->canPartition()){
            cout << "Sum of the elements is odd.." << endl;
            exit(1);
        }
            
        auto startTM = chrono::steady_clock::now();
        recBF->canPartitionRecursiveAux();
        auto endTM = chrono::steady_clock::now();
        
        if(bOutput){
            recBF->printResult();
        }
            
        if(bTime){
            long timeMS = chrono::duration_cast<chrono::milliseconds>(endTM - startTM).count();
            long timeNS = chrono::duration_cast<chrono::nanoseconds>(endTM - startTM).count();
            recBF->printTime(timeMS, timeNS, scale);
        }
        
        delete (recBF);
        delete (file); 
    }else{
        cout << "Unable to open file -> fichVect.txt" << endl; 
        exit(1);
    }  
}

void ParserArgs::error(string error){
    fprintf(stderr, error.c_str());
    ParserArgs::print();
    exit(1);
}




