#include "UI.hpp"

int cin_int(){
    int N;
    while (true) {
        cout<<flush;//очистка потока
        if ((cin >> N).good()) return N;
        if (cin.fail()) {
            cin.clear();//очищает флаг ошибки, но часть введенной строки при этом остается
            cout << "Invalid input.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропустить все символы в потоке до \n, после этого можно начинать считывать новое значение
    }
}

double cin_double(){
    double N;
    while (true) {
        cout<<flush;//очистка потока
        if ((cin >> N).good()) return N;
        if (cin.fail()) {
            cin.clear();//очищает флаг ошибки, но часть введенной строки при этом остается
            cout << "Invalid input.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//пропустить все символы в потоке до \n, после этого можно начинать считывать новое значение
    }
}

bool db_check_values(double db){
    if (db > 0) return true;
    else return false;
}

bool com_check_values(Complex com){
    if (com > Complex(0)) return true;
    else return false;
}

double db_square(double db){
    return db*db;
}

Complex com_square(Complex com){
    return com*com;
}

void run_UI(){
    Tree<double>::map_func db_mf = db_square;
    Tree<Complex>::map_func com_mf = com_square;
    Tree<double> dbTree;
    Tree<Complex> comTree;
    int type = 0;
    
    int menu_item = 0;
    while (menu_item != 12){
        cout<<"\nPress\n";
        cout<<" 1.  to add item in tree\n";
        cout<<" 2.  to remove item\n";
        cout<<" 3.  to print tree\n";
        cout<<" 4.  use map function (square)\n";
        cout<<" 5.  use where function (remove all non-positive)\n";
        cout<<" 6.  merge\n";
        cout<<" 7.  remove subtree\n";
        cout<<" 8.  search for a value\n";
        cout<<" 9.  post-order traversal (LEFT-RIGHT-ROOT) \n";
        cout<<" 10. reverse post-order traversal (RIGHT-LEFT-ROOT) \n";
        cout<<" 11. to run tests\n";
        cout<<" 12. to exit\n";
        menu_item = cin_int();
        
        switch (menu_item) {
            case 1:
            {
                cout<<endl<<"Select type of tree:\n";
                cout<<" 1. Real\n";
                cout<<" 2. Complex\n";
                type = cin_int();
                
                while (type != DOUBLE && type != COMPLEX){
                    cout<<endl<<"Incorrect type."<<endl;
                    cout<<endl<<"Select type of tree:\n";
                    cout<<" 1. Real\n";
                    cout<<" 2. Complex\n";
                    type = cin_int();
                }
                
                if (type == DOUBLE) {
                    cout<<"\nEnter value:\n";
                    dbTree.add_node(cin_double());
                }
                else {
                    double re = 0;
                    double im = 0;
                    cout<<"\nEnter real part of value:\n";
                    re = cin_double();
                    cout<<"\nEnter imaginary part of value:\n";
                    im = cin_double();
                    comTree.add_node(Complex(re,im));
                }
            }
                break;
                
            case 2:
            {
                if (type == DOUBLE) {
                    cout<<"\nEnter value you want to remove:\n";
                    double val = cin_double();
                    dbTree.remove_node(val);
                }
                else if (type == COMPLEX){
                    cout<<"\nEnter value you want to remove:\n";
                    cout<<"\n Enter real part:\n";
                    double re = cin_double();
                    cout<<"\n Enter imaginary part:\n";
                    double im = cin_double();
                    comTree.remove_node(Complex(re,im));
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 3:
            {
                if (type == DOUBLE) {
                    cout<<"\nYour tree:\n";
                    dbTree.print();
                }
                else if (type == COMPLEX){
                    cout<<"\nYour tree:\n";
                    comTree.print();
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 4:
            {
                if (type == DOUBLE) {
                    dbTree.map(db_mf);
                }
                else if (type == COMPLEX){
                    
                    comTree.map(com_mf);
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 5:
            {
                if (type == DOUBLE) {
                    Tree<double>::where_func wf = db_check_values;
                    dbTree = dbTree.where(wf);
                }
                else if (type == COMPLEX){
                    Tree<Complex>::where_func wf = com_check_values;
                    comTree = comTree.where(wf);
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 6:
            {
                if (type == 0) cout<<"\nTree doesn't exist\n";
                else{
                    int menu_item = 0;
                    Tree<double> sec_dbTree;
                    Tree<Complex> sec_comTree;
                    cout<<"\nEnter second three:\n";
                    cout<<"Do you want to enter new item?\n";
                    while (menu_item != 2) {
                        cout<<" 1.Yes\n";
                        cout<<" 2.No\n";
                        menu_item = cin_int();
                        while (menu_item != 1 && menu_item != 2) {
                            cout<<"Incorrect input.\n";
                            menu_item = cin_int();
                        }
                        if (menu_item == 1) {
                            if (type == DOUBLE) {
                                cout<<"\nEnter value:\n";
                                sec_dbTree.add_node(cin_double());
                            }
                            else{
                                double re = 0;
                                double im = 0;
                                cout<<"\nEnter real part of value:\n";
                                re = cin_double();
                                cout<<"\nEnter imaginary part of value:\n";
                                im = cin_double();
                                sec_comTree.add_node(Complex(re,im));
                            }
                        }
                    }
                    
                    if (type == DOUBLE) dbTree = dbTree.merge(sec_dbTree);
                    else comTree = comTree.merge(sec_comTree);
                }
            }
                break;
                
            case 7:
            {
                if (type == DOUBLE) {
                    cout<<"\nEnter value:\n";
                    dbTree.remove_subtree(cin_double());
                }
                else if (type == COMPLEX){
                    cout<<"\nEnter value:\n";
                    double re = 0;
                    double im = 0;
                    cout<<"\nEnter real part of value:\n";
                    re = cin_double();
                    cout<<"\nEnter imaginary part of value:\n";
                    im = cin_double();
                    comTree.remove_subtree(Complex(re,im));
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 8:
            {
                if (type == DOUBLE) {
                    cout<<"\nEnter value you want to check:\n";
                    if (dbTree.is_in_tree(cin_double())) cout<<"\nValue enters the tree\n";
                    else cout<<"\nValue doesn't enter the tree\n";
                }
                else if (type == COMPLEX){
                    cout<<"\nEnter value you want to check:\n";
                    double re = 0;
                    double im = 0;
                    cout<<"\nEnter real part of value:\n";
                    re = cin_double();
                    cout<<"\nEnter imaginary part of value:\n";
                    im = cin_double();
                    if (comTree.is_in_tree(Complex(re,im))) cout<<"\nValue enters the tree\n";
                    else cout<<"\nValue doesn't enter the tree\n";
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 9:
            {
                if (type == DOUBLE) {
                    cout<<dbTree.post_order_to_str();
                }
                else if (type == COMPLEX){
                    cout<<comTree.post_order_to_str();
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 10:
            {
                if (type == DOUBLE) {
                    cout<<dbTree.reverse_post_order_to_str();
                }
                else if (type == COMPLEX){
                    cout<<comTree.reverse_post_order_to_str();
                }
                else cout<<"\nTree doesn't exist\n";
            }
                break;
                
            case 11:
            {
                run_all_tests();
            }
                break;
                
            case 12:
                break;
        
            default:
                cout<<"Invalid command\n\n";
                break;
        }
    }
}
