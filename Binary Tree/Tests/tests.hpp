#ifndef tests_hpp
#define tests_hpp

#include <stdio.h>
#include <iostream>
#include "Complex Tests/complex_unit_1.hpp"
#include "Complex Tests/complex_unit_2.hpp"
#include "Complex Tests/complex_unit_3.hpp"
#include "Tree Tests/tree_unit_1.hpp"
#include "Tree Tests/tree_unit_2.hpp"
#include "Tree Tests/tree_unit_3.hpp"
#include "Tree Tests/tree_unit_4.hpp"
#include "Tree Tests/tree_unit_5.hpp"


using namespace std;

void run_all_tests();
void run_complex_tests();
void run_tree_tests();
void test_prepare(int *test_id, bool *test_ok);
void test_result(bool test_ok);

#endif /* tests_hpp */

