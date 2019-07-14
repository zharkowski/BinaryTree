#include "tests.hpp"

using namespace std;

void test_prepare(int *test_id, bool *test_ok){
    (*test_ok) = false;
    (*test_id)++;
    
    cout<<"[TESTING] Test #"<<*test_id<<": ";
}

void test_result(bool test_ok){
    if (test_ok == true){
        cout<<"OK.\n";
    } else {
        cout<<"ERROR.\n";
    }
}

void run_all_tests(){
    run_complex_tests();
    run_tree_tests();
}


void run_complex_tests(){
    run_complex_unit_1();
    run_complex_unit_2();
    run_complex_unit_3();
}

void run_tree_tests(){
    run_tree_unit_1();
    run_tree_unit_2();
    run_tree_unit_3();
    run_tree_unit_4();
    run_tree_unit_5();
}
