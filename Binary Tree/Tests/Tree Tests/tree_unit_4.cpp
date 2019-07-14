#include "tree_unit_4.hpp"

using namespace std;

/*
 UNIT 4: Тестирование удаления поддерева и поиска на вхождение элемента
 
 Список тестов:
 Тест 1: Извлечение поддерева из дерева
 Тест 2: Поиск на вхождение элемента
 */

void run_tree_unit_4(){
    cout<<"[TREE CLASS TESTING] UNIT 4 :\n\n";
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
        
        tr.remove_subtree(-5);
        
        Node<double>* current_node = tr.get_root();
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
        
        if (tr.is_in_tree(3) && !tr.is_in_tree(10)) test_ok = true;
        
        test_result(test_ok);
    }
    
    if (test_id == 2 && test_ok == true) {
        cout<<"\n[TESTING] Unit 4 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 4 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}
