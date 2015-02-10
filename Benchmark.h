#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <Math.h>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

class Benchmark {
private:
    static const double PIx2;
    double * m_biases;
public:
    Benchmark();
    Benchmark(string file_bias);
    ~Benchmark();
    static double SchafferF6(double x, double y);
};
#endif
