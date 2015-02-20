#ifndef PROBLEM_H
#define PROBLEM_H

#include "Benchmark.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

class Problem
  {
    public:
        Problem();
        ~Problem();

        friend ostream& operator<< (ostream& os, const Problem& pbm);
        friend istream& operator>> (istream& is, Problem& pbm);

        Problem& operator=  (const Problem& pbm);
        bool operator== (const Problem& pbm) const;
        bool operator!= (const Problem& pbm) const;

        //Direction direction () const; //Maximize or Minimize
        int dimension() const;
		void setDimension(int);

		Benchmark getBenchmark();

        double LowerLimit, UpperLimit;

        void choose(int id);
    private:
        int _dimension;
        Benchmark *benchmark;
  };

#endif // PROBLEM_H