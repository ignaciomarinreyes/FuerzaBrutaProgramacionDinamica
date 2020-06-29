#ifndef PARSERARGS_H
#define PARSERARGS_H

#include <getopt.h>
#include <chrono>
#include <iostream>
#include "longOptions.h"
#include "ReadFile.h"
#include "Memoization.h"

using namespace std;

class ParserArgs {
    private:
        int argc;
        char** args;       
        string fichero;
        string scale = "s";
        void print();
        int option_index = 0; 
        string usage  = "\nusage: *.exe [-h][-f PathDir [-di][-do][-dt [s|ms|ns]]]"; 
        string message = "\nPartition problem is to determine whether a given set"
                         "\ncan be partitioned into two subsets such that the sum"
                         "\nof elements in both subsets is same.\n"
                         "For further information, use the option '-h'.\n";
        string input  = " -i,--input         Display input data"; bool bInput =  false;
        string output = " -o,--output        Display output data"; bool bOutput =  false;
        string time   = " -t,--time          Display taken time in seconds or ([--time=[ns | ms | s]])"; bool bTime =  false;
        string folder = " -f,--file <arg>    Read elements from a file"; bool bFolder =  false;
        string help   = " -h,--help          Display help usage"; bool bHelp =  false;
    public:
        ParserArgs(int argcA, char** argsA);
        void parseArg();
        void fileOption(string fich);
        void error(string error);
};

#endif /* PARSERARGS_H */

