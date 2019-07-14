#include "tree_unit_2.hpp"

using namespace std;

/*
 UNIT 2: Тестирование удаления числа из дерева
 
 Список тестов:
 Тест 1: Удаление корня из дерева
 Тест 2: Удаление элемента без потомков
 Тест 3: Удаление элемента с одним потомком
 Тест 4: Попытка удаления несуществующего элемента
 
 */

void run_tree_unit_2(){
    cout<<"[TREE CLASS TESTING] UNIT 2 :\n\n";
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

        tr.remove_node(5);

        Node<double>* current_node = tr.get_root();
        if (current_node->data == 3){
            current_node = current_node->right;
            if (current_node->data == 6 && current_node->left == nullptr && current_node->right == nullptr){
                current_node = current_node->parent->left;
                if (current_node->data == 2 && current_node->right == nullptr){
                    current_node = current_node->left;
                    if (current_node->data == -5 && current_node->left == nullptr){
                        current_node = current_node->right;
                        if (current_node->data == 1 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                    }
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
        
        tr.remove_node(1);
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 5 && current_node->right == nullptr){
            current_node = current_node->left;
            if (current_node->data == 2){
                current_node = current_node->right;
                if (current_node->data == 3 && current_node->left == nullptr && current_node->right == nullptr){
                    current_node = current_node->parent->left;
                    if (current_node->data == -5 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
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
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(-5);
        tr.add_node(1);
        
        tr.remove_node(-5);
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 5 && current_node->right == nullptr){
            current_node = current_node->left;
            if (current_node->data == 2){
                current_node = current_node->right;
                if (current_node->data == 3 && current_node->left == nullptr && current_node->right == nullptr){
                    current_node = current_node->parent->left;
                    if (current_node->data == 1 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                }
            }
        }
        else test_ok = false;
        
        test_result(test_ok);
    }
    
    //TEСТ 4
    if (test_ok == true){
        test_prepare(&test_id, &test_ok);
        
        Tree<double> tr;
        tr.add_node(5);
        tr.add_node(2);
        tr.add_node(3);
        tr.add_node(1);
        
        tr.remove_node(10);
        
        Node<double>* current_node = tr.get_root();
        if (current_node->data == 5 && current_node->right == nullptr){
            current_node = current_node->left;
            if (current_node->data == 2){
                current_node = current_node->right;
                if (current_node->data == 3 && current_node->left == nullptr && current_node->right == nullptr){
                    current_node = current_node->parent->left;
                    if (current_node->data == 1 && current_node->left == nullptr && current_node->right == nullptr) test_ok = true;
                }
            }
        }
        else test_ok = false;
        
        test_result(test_ok);
    }
    
    if (test_id == 4 && test_ok == true) {
        cout<<"\n[TESTING] Unit 2 testing SUCCESSEDED.\n\n\n";
    } else {
        cout<<"\n[TESTING] Unit 2 testing FAILED on TEST #"<<test_id<<".\n\n\n";
    }
}

