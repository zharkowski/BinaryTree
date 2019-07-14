#include "tree_unit_5.hpp"

using namespace std;

/*
 UNIT 5: Тестирование map, where и merge
 
 Список тестов:
 Тест 1: map
 Тест 2: where (результат функции равен истине только когда число положительно)
 Тест 3: merge
 */

bool check_values(double db){
    if (db > 0) return true;
    else return false;
}

double square(double db){
    return db*db;
}

void run_tree_unit_5(){
    cout<<"[TREE CLASS TESTING] UNIT 5 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double>::map_func mf = square;
        Tree<double> tr;
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(-5);
        tr.add_node(1);
        tr.add_node(6);
        
        tr.map(mf);
        
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 25){
            current_node = current_node->right;
            if (current_node->data == 36 && current_node->left == nullptr && current_node->right == nullptr){
                current_node = current_node->parent->left;
                if (current_node->data == 4){
                    current_node = current_node->right;
                    if (current_node->data == 9 && current_node->left == nullptr && current_node->right == nullptr) {
                        current_node = current_node->parent->left;
                        if (current_node->data == 25 && current_node->left == nullptr){
                            current_node = current_node->right;
                            if (current_node->data == 1 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                        }
                    }
                }
            }
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 2
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double>::where_func wf = check_values;
        Tree<double> tr;
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(-5);
        tr.add_node(-1);
        tr.add_node(6);
        
        Tree<double> new_tree = tr.where(wf);
        
        Node<double>* current_node = new_tree.get_root();
        if (current_node->data == 5){
            current_node = current_node->right;
            if (current_node->data == 6 && current_node->left == nullptr && current_node->right == nullptr){
                current_node = current_node->parent->left;
                if (current_node->data == 2 && current_node->left == nullptr){
                    current_node = current_node->right;
                    if (current_node->data == 3 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                }
            }
        }
        
        test_result(test_ok);
    }
    
    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> first_tr;
        first_tr.add_node(5);
        first_tr.add_node(2);
        first_tr.add_node(3);
        first_tr.add_node(1);
        
        Tree<double> second_tr;
        second_tr.add_node(7);
        second_tr.add_node(0);
        second_tr.add_node(-2);
        second_tr.add_node(4);
        
        Tree<double> tr = first_tr.merge(second_tr);
        
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 5){
            current_node = current_node->right;
            if (current_node->data == 7 && current_node->left == nullptr && current_node->right == nullptr){
                current_node = current_node->parent->left;
                if (current_node->data == 2){
                    current_node = current_node->right;
                    if (current_node->data == 3 && current_node->left == nullptr){
                        current_node = current_node->right;
                        if (current_node->data == 4 && current_node->left == nullptr && current_node->right == nullptr){
                            current_node = current_node->parent->parent->left;
                            if (current_node->data == 1 && current_node->right == nullptr){
                                current_node = current_node->left;
                                if (current_node->data == 0 && current_node->right == nullptr){
                                    current_node = current_node->left;
                                    if (current_node->data == -2 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 5 testing SUCCESSEDED.\n\n\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 5 testing FAILED on TEST #"<<test_id<<".\n\n\n";
        cout<<"----------------------------------------"<<"\n\n\n";
    }
}
