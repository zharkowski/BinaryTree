#include "tree_unit_1.hpp"

using namespace std;

/*
 UNIT 1: Тестирование создания дерева и добавления элементов
 
 Список тестов:
 Тест 1: Добавление одного элемента
 Тест 2: Добавление пяти элементов
 Тест 3: Создание пустого дерева
 */

void run_tree_unit_1(){
    cout<<"[TREE CLASS TESTING] UNIT 1 :\n\n";
    int test_id = 0;
    bool test_ok = true;
    
    //TEСТ 1
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> tr;
        tr.add_node(5);

        if (tr.get_root()->data == 5 && tr.get_root()->left == nullptr && tr.get_root()->left == nullptr) test_ok = true;
        else test_ok = false;
        
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
        
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 5 && current_node->right == nullptr){
            current_node = current_node->left;
            if (current_node->data == 2){
                current_node = current_node->right;
                if (current_node->data == 3 && current_node->left == nullptr && current_node->right == nullptr){
                    current_node = current_node->parent->left;
                    if (current_node->data == -5 && current_node->left == nullptr){
                        current_node = current_node->right;
                        if (current_node->data == 1 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                    }
                }
            }
        }
        else test_ok = false;
        
        test_result(test_ok);
    }
    
    //TEСТ 3
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> tr;
        
        if (tr.get_root() == NULL) test_ok = true;
        else test_ok = false;
        
        test_result(test_ok);
    }
    
    if (test_id == 3 && test_ok == true) {
        cout<<"\n[TESTING] Unit 1 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 1 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}

