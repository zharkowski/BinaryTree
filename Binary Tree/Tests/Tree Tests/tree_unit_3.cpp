#include "tree_unit_3.hpp"

using namespace std;

/*
 UNIT 3: Тестирование вывода дерева в строку в соответствии с обходом
 
 Список тестов:
 Тест 1: Вывод по обходу ЛПК
 Тест 2: Вывод по обходу ПЛК
 */

void run_tree_unit_3(){
    cout<<"[TREE CLASS TESTING] UNIT 3 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> tr;
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(-5);
        tr.add_node(1);
        tr.add_node(6);
        
        string s = tr.post_order_to_str();
        if (s == "[[[][1]-5][3]2][6]5") test_ok = true;
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> tr;
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(-5);
        tr.add_node(1);
        tr.add_node(6);
        
        string s = tr.reverse_post_order_to_str();
        if (s == "[6][[3][[1][]-5]2]5") test_ok = true;
        
        test_result(test_ok);
    }
    
    if (test_id == 2 && test_ok == true) {
        cout<<"\n[TESTING] Unit 3 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 3 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
