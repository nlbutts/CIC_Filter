#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;

uint32_t executeCIC(uint16_t *x, int32_t * y, uint32_t len)
{
    #define N 4
    #define R 10
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
            sigma[0] += x[(i*R)+n];
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


int main()
{
    auto in = "../datain.csv";
    auto out = "../dataout.csv";
    auto x = loadCSV(in);

    vector<int32_t> y(x.size() / 10);

    executeCIC(x.data(), y.data(), y.size());

    saveCSV(out, y);
}