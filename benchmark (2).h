#ifndef __BENCHMARK__
#define __BENCHMARK__
#include <iostream>
#include <Math.h>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

class Benchmark {
private:
	static const string DEFAULT_FILE_BIAS;
	static const int NUM_TEST_FUNC;

	static const int MAX_SUPPORT_DIM;
	static const double PIx2;
	// Instance variables
	double * m_biases;
public:
	Benchmark();

	~Benchmark();

	// Basic functions

	static double schwefel_102(double * x, int length);
	static double rosenbrock(double * x, int length);
	static double ackley(double * x, int length);
	static double rastrigin(double * x, int length);
	static double ScafferF6(double x, double y);
	static double EScafferF6(double * x, int length);
	static double weierstrass(double * x, int length);
	static double weierstrass(double * x, int length, double a, double b, int Kmax);

	
	

}; // Benchmark
#endif /* __BENCHMARK__ */ 