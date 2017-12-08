#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include "tclap/CmdLine.h"

using namespace TCLAP;
using namespace std;

uint32_t executeCIC(uint16_t *x, int32_t * y, uint32_t len)
{
    #define N 4
    #define R 32
    static int32_t sigma[N]  = {0};
    static int32_t delta[N]  = {0};
    static int32_t pDelta[N] = {0};

    for (uint32_t i = 0; i < len; i++)
    {
        pDelta[0] = sigma[3];
        pDelta[1] = delta[1];
        pDelta[2] = delta[2];
        pDelta[3] = delta[3];

        for (uint32_t n = 0; n < R; n++)
        {
            int16_t temp = *x++;
            sigma[0] += (temp - 2048);
            sigma[1] += sigma[0];
            sigma[2] += sigma[1];
            sigma[3] += sigma[2];
        }

        delta[1] = sigma[3] - pDelta[0];
        delta[2] = delta[1] - pDelta[1];
        delta[3] = delta[2] - pDelta[2];
        y[i] = delta[3] - pDelta[3];
    }
    return len;
}

vector<uint16_t> loadCSV(std::string file)
{
    cout << "Loading input file:" << file << endl;
    FILE * f = fopen(file.c_str(), "r");
    vector<uint16_t> data;
    if (f)
    {
        int v;
        while (fscanf(f, "%d", &v) != EOF)
        {
            data.push_back(v);
        }
    }

    return data;
}

void saveCSV(std::string file, vector<int32_t> data)
{
    cout << "saving to file:" << file << endl;
    FILE * f = fopen(file.c_str(), "w");
    char str[100];
    for (auto v:data)
    {
        fprintf(f, "%d\n", v);
    }
    fclose(f);
}


int main(int argc, char** argv)
{
    // Wrap everything in a try block.  Do this every time, 
    // because exceptions will be thrown for problems. 
    try {  

    // Define the command line object.
    CmdLine cmd("CIC filter test R=32 N=4 M=1", ' ', "0.1");

    // Define a value argument and add it to the command line.
    ValueArg<string> inputFile("i","input","input file",true,"","string");
    cmd.add( inputFile );
    ValueArg<string> outputFile("o","output","output file",true,"","string");
    cmd.add( outputFile );

    // Parse the args.
    cmd.parse( argc, argv );

    // Get the value parsed by each arg. 
    std::string input = inputFile.getValue();
    std::string output = outputFile.getValue();


    auto x = loadCSV(input);

    vector<int32_t> y(x.size() / 32);

    cout << "Loaded " << x.size() << " Samples" << endl;
    executeCIC(x.data(), y.data(), y.size());

    cout << "Saving data to file." << endl;

    saveCSV(output, y);
    } catch (ArgException &e)  // catch any exceptions
    { cerr << "error: " << e.error() << " for arg " << e.argId() << endl; }
}
