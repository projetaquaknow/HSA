
#include "Benchmark.h"
//TODO: Cambiar ruta
//const string Benchmark::DEFAULT_FILE_BIAS = Configuration.cec2005SupportDataDirectory + "/fbias_data.txt";
const string Benchmark::DEFAULT_FILE_BIAS = "/Users/esteban/Documents/git/jmetalcpp/data/cec2005CompetitionResources/supportData/fbias_data.txt";
const int Benchmark::NUM_TEST_FUNC = 25;
// For certain functions, some essential data can be calculated beforehand.
// Hence, a maximum supported number of dimensions should be specified.
// Specifiy the number of dimensions here if you need more.
const int Benchmark::MAX_SUPPORT_DIM = 100;
const double Benchmark::PIx2 = 3.141592653589793 * 2.0;
/*
* Default constructor
*/
Benchmark::Benchmark() : Benchmark(DEFAULT_FILE_BIAS) {}
/*
* Constructor
*/
Benchmark::Benchmark(string file_bias) {
m_biases = new double[NUM_TEST_FUNC];
loadRowVectorFromFile(file_bias, NUM_TEST_FUNC, m_biases);
}
/*
* Destructor
*/
Benchmark::~Benchmark() {
delete [] m_biases;
}
double Benchmark::SchafferF6(double * x, double y) {
         double temp1 = x*x + y*y;
double temp2 = sin(sqrt(temp1));
double temp3 = 1.0 + 0.001 * temp1;
return (0.5 + ((temp2 * temp2 - 0.5)/(temp3 * temp3)));
}
