#ifndef READFILE_H
#define READFILE_H

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReadFile 
{
    private:
        string path;
        string line;
        int size;
    public:
        ReadFile(string folder);
        int* ReadFolder();
        int getSize();
};

#endif /* READFILE_H */

