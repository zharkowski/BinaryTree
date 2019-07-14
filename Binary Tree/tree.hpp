#ifndef three_hpp
#define three_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    
    Node();
    Node(const T);
};

template <typename T>
class Tree{
private:
    Node<T>* root;
    
    void remove_subtree(Node<T> *);     //вспомогательная функция для удаления поддерева
    Node<T>* merge(Node<T>*, Tree<T> &);    //вспомогательная функция для merge
    void print(Node<T>*, int);              //вспомогательная функция для print
    int get_depth(Node<T>*, int);           //вспомогательная функция для get_depth
    
public:
    Tree();
//    Tree(Node<T> &rt);
//    Tree(Tree<T> &tr);
    ~Tree();
    
    void add_node(T);           //добаление элемента в дерево
    void remove_node(T);        //удаление элемента из дерево по значению
    void remove_node(Node<T>*); //удаление элемента из дерево по узлу
    void clear_node(Node<T>*);
    
    string post_order_to_str(Node<T>* x);           //обход левый-правый-корень, начиная с x
    string post_order_to_str();                     //обход левый-правый-корень, начиная с корня
    string reverse_post_order_to_str(Node<T>* x);   //обход правый-левый-корень, начиная с x
    string reverse_post_order_to_str();             //обход правый-левый-корень, начиная с корня
    
    Node<T>* find_node(T);          //находит узел по значению
    bool is_in_tree(T);             //проверка элемента на вхождение
    Node<T>* find_min_node(Node<T>*);
    Node<T>* find_max_node(Node<T>*);
    
    Node<T>* copy_node(Node<T>*, Tree<T>&);     //копирует узел
    Tree<T> copy_tree();                        //копирует дерево
    Tree<T> copy_tree(Node<T>*);
    Node<T>* get_root();
    
    void remove_subtree(T val);       //удаляет поддерево по значению
    
    typedef bool (*where_func)(T);
    Node<T>* where(where_func, Node<T>*, Tree<T>&); //вспомогательная функция для where
    Tree<T> where(where_func wf);
    
    Tree<T> merge(Tree<T> &sec_tree);       //прибавляет второе дерево к первому (слияние)
    
    typedef T (*map_func)(T);
    void  map(Node<T> *, map_func);                //вспомогательная функция для map
    void map(map_func mf);
    
    void print();
    int get_depth(); //находит глубину дерева
};

#include "tree.cpp"

#endif /* three_hpp */
