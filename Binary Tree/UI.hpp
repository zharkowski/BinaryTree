#ifndef UI_hpp
#define UI_hpp

#define DOUBLE 1
#define COMPLEX 2

#include <stdio.h>
#include <iostream>
#include "tree.hpp"
#include "complex.hpp"
#include "Tests/tests.hpp"

void run_UI();

int cin_int();
double cin_double();

bool check_values(double);
bool check_values(Complex);
double square(double);
Complex square(Complex);

#endif /* UI_hpp */
