// Benchmark.cpp
//

#include "stdafx.h"
#include "Benchmark.h"
//const string Benchmark::DEFAULT_FILE_BIAS = "/Users/esteban/Documents/git/jmetalcpp/data/cec2005CompetitionResources/supportData/fbias_data.txt";
const int Benchmark::NUM_TEST_FUNC = 25;

const int Benchmark::MAX_SUPPORT_DIM = 100;
const double Benchmark::PIx2= 3.141592653589793 * 2.0;
/*
* Default constructor
*/
Benchmark::Benchmark(){}

/*
* Destructor
*/
Benchmark::~Benchmark() {
	delete[] m_biases;
}




/**
* Schwefel's problem 1.2
*/
double Benchmark::schwefel_102(double * x, int length) {
	double prev_sum, curr_sum, outer_sum;
	curr_sum = x[0];
	outer_sum = (curr_sum * curr_sum);
	for (int i = 1; i < length; i++) {
		prev_sum = curr_sum;
		curr_sum = prev_sum + x[i];
		outer_sum += (curr_sum * curr_sum);
	}
	return (outer_sum);
}
/**
* Rosenbrock's function
*/
double Benchmark::rosenbrock(double * x, int length) {
	double sum = 0.0;
	for (int i = 0; i < (length - 1); i++) {
		double temp1 = (x[i] * x[i]) - x[i + 1];
		double temp2 = x[i] - 1.0;
		sum += (100.0 * temp1 * temp1) + (temp2 * temp2);
	}
	return (sum);
}

/**
* Ackley's function
*/
double Benchmark::ackley(double * x, int length) {
	double sum1 = 0.0;
	double sum2 = 0.0;
	for (int i = 0; i < length; i++) {
		sum1 += (x[i] * x[i]);
		sum2 += (cos(PIx2 * x[i]));
	}
	return (-20.0 * exp(-0.2 * sqrt(sum1 / ((double)length))) - exp(sum2 / ((double)length)) + 20.0 + exp(1));
}
/**
* Rastrigin's function
*/
double Benchmark::rastrigin(double * x, int length) {
	double sum = 0.0;
	for (int i = 0; i < length; i++) {
		sum += (x[i] * x[i]) - (10.0 * cos(PIx2 * x[i])) + 10.0;
	}
	return sum;
}
/**
* Scaffer's F6 function
*/

double Benchmark::ScafferF6(double x, double y) {
	double temp1 = x*x + y*y;
	double temp2 = sin(sqrt(temp1));
	double temp3 = 1.0 + 0.001 * temp1;
	return (0.5 + ((temp2 * temp2 - 0.5) / (temp3 * temp3)));
}
/**
* Expanded Scaffer's F6 function
*/
double Benchmark::EScafferF6(double * x, int length) {
	double sum = 0.0;
	for (int i = 1; i < length; i++) {
		sum += ScafferF6(x[i - 1], x[i]);
	}
	sum += ScafferF6(x[length - 1], x[0]);
	return (sum);
}

/**
* Weierstrass function
*/
double Benchmark::weierstrass(double * x, int length) {
	return (weierstrass(x, length, 0.5, 3.0, 20));
}
double Benchmark::weierstrass(double * x, int length, double a, double b, int Kmax) {
	double sum1 = 0.0;
	for (int i = 0; i < length; i++) {
		for (int k = 0; k <= Kmax; k++) {
			sum1 += pow(a, k) * cos(PIx2 * pow(b, k) * (x[i] + 0.5));
		}
	}
	double sum2 = 0.0;
	for (int k = 0; k <= Kmax; k++) {
		sum2 += pow(a, k) * cos(PIx2 * pow(b, k) * (0.5));
	}
	return (sum1 - sum2*((double)(length)));
}
