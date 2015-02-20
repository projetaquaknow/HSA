#include "Problem.h"

Problem::Problem(){
}


int Problem::dimension() const{
	return _dimension;

}
void Problem::setDimension(int dimension){
	this->_dimension=dimension;
}

Benchmark Problem::getBenchmark(){
	return *benchmark;
}


void Problem::choose(int id){
    switch(id){
    case 1: //Rosenbrock
        LowerLimit =-30;
        UpperLimit = 30;
        benchmark->rosenbrock(NULL,30);
        break;
    case 2: //Rastrigin
        LowerLimit = -5.12;
        UpperLimit = 5.12;
        benchmark->rastrigin(NULL,30);
        break;
    case 3: //Ackley
        LowerLimit = -5;
        UpperLimit = 5;
        benchmark->ackley(NULL,30);
        break;
    case 4: //Schwefel
        LowerLimit = -500;
        UpperLimit = 500;
        benchmark->schwefel_102(NULL,30);
        break;
    case 5: //Schaffer
        LowerLimit = -100;
        UpperLimit = 100;
        benchmark->ScafferF6(NULL,30);
        break;
    case 6: //Weierstrass
        LowerLimit = -5.12;
        UpperLimit = 5.12;
        benchmark->weierstrass(NULL,30);
        break;
    }

}

ostream& operator<< (ostream& os, const Problem& pbm){
	
}

istream& operator>> (istream& is, Problem& pbm){
	
}
