#include "tree.hpp"

using namespace std;

template <typename T>
Node<T>::Node(){
    data = NULL;
    left = nullptr;
    right = nullptr;
}

template <typename T>
Node<T>::Node(const T x){
    data = x;
    left = nullptr;
    right = nullptr;
}

template <typename T>
Tree<T>::Tree() {
    root = nullptr;
}

template <typename T>
Tree<T>::~Tree() {
//    remove_subtree(root);
}

template <typename T>
void Tree<T>::add_node(T x){
    Node<T>* n = new Node<T>(x);
    Node<T>* ptr;
    Node<T>* ptr1 = nullptr;

    n->left = 0;
    n->right = 0;
    n->parent = 0;
    ptr = root;
    while (ptr != 0) {
        ptr1 = ptr;
        if (x < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    n->parent = ptr1;
    if (ptr1 == 0)
        root = n;
    else{
        if(x < ptr1->data )
            ptr1->left=n;
        else
            ptr1->right=n;
    }
}

template <typename T>
void Tree<T>::remove_node(Node<T>* x){
    if (root == nullptr || x == nullptr) return;
    if (x == root)
    {
        if (x->left && x->right) {
            Node<T> *max_node = find_max_node(x->left);
            x->data = max_node->data;
            remove_node(max_node);
            return;
        }
        else if (x->left) {
            root = x->left;
        }
        else if (x->right) {
            root = x->right;
        }
        else {
            root = nullptr;
        }
        free(x);
        clear_node(x);
    }
    else
    {
        if (x->left && x->right){
            Node<T> *max_node = find_max_node(x->left);
            x->data = max_node->data;
            remove_node(max_node);
            return;
        }
        else if (x->left){
            if (x == x->parent->left) x->parent->left = x->left;
            else x->parent->right = x->left;
        }
        else if (x->right){
            if (x == x->parent->right) x->parent->right = x->right;
            else x->parent->left = x->right;
        }
        else{
            if (x == x->parent->left) x->parent->left = nullptr;
            else x->parent->right = nullptr;
        }
        free(x);
        clear_node(x);
    }
}

template <typename T>
void Tree<T>::remove_node(T val){
    Node<T>* n = find_node(val);
    remove_node(n);
}

template <typename T>
void Tree<T>::clear_node(Node<T> *n){
    n = nullptr;
    return;
}

template <typename T>
string Tree<T>::post_order_to_str(Node<T>* x) {
    stringstream ss;
    if (x != 0){
        if (x->left != NULL || x->right != NULL) ss<<"[";
        ss<<this->post_order_to_str(x->left);
        if (x->left != NULL || x->right != NULL) ss<<"][";
        ss<<this->post_order_to_str(x->right);
        if (x->left != NULL || x->right != NULL) ss<<"]";
        ss<<x->data;
    }
    string s = ss.str();
    return s;
}

template <typename T>
string Tree<T>::post_order_to_str() {
    return post_order_to_str(root);
}

template <typename T>
string Tree<T>::reverse_post_order_to_str(Node<T>* x) {
    stringstream ss;
    if (x != 0){
        if (x->left != NULL || x->right != NULL) ss<<"[";
        ss<<this->reverse_post_order_to_str(x->right);
        if (x->left != NULL || x->right != NULL) ss<<"][";
        ss<<this->reverse_post_order_to_str(x->left);
        if (x->left != NULL || x->right != NULL) ss<<"]";
        ss<<x->data;
    }
    string s = ss.str();
    return s;
}

template <typename T>
string Tree<T>::reverse_post_order_to_str() {
    return reverse_post_order_to_str(root);
}

template <typename T>
Node<T>* Tree<T>::find_node(T val){
    Node<T>* current_node = root;
    
    while(current_node != nullptr){
        if (val < current_node->data) current_node = current_node->left;
        else if (val > current_node->data) current_node = current_node->right;
        else if (val == current_node->data){
            return current_node;
            break;
        }
        if (current_node == nullptr) return nullptr;
    }
    return nullptr;    
}

template <typename T>
bool Tree<T>::is_in_tree(const T val){
    if (find_node(val) == NULL) return false;
    else return true;
}

template <typename T>
Node<T>* Tree<T>::find_min_node(Node<T> *n){
    Node<T>* current_node = n;
    while (current_node->left != nullptr)
        current_node = current_node->left;
    
    return current_node;
}

template <typename T>
Node<T>* Tree<T>::find_max_node(Node<T> *n){
    Node<T>* current_node = n;
    while (current_node->right != nullptr)
        current_node = current_node->right;
    
    return current_node;
}

template <typename T>
Node<T>* Tree<T>::copy_node(Node<T> *node_to_copy, Tree<T> &new_tree){
    if (node_to_copy != nullptr)
    {
        new_tree.add_node(node_to_copy->data);
        copy_node(node_to_copy->left, new_tree);
        copy_node(node_to_copy->right, new_tree);
    }
    return new_tree.root;
}

template <typename T>
Tree<T> Tree<T>::copy_tree(){
    Tree<T> new_tree;
    Node<T>* n = root;
    copy_node(n,new_tree);
    
    return new_tree;
}

template <typename T>
Tree<T> Tree<T>::copy_tree(Node<T> *node_to_copy){
    Tree<T> new_tree;
    copy_node(node_to_copy, new_tree);
    return new_tree;
}

template <typename T>
Node<T>* Tree<T>::get_root(){
    return root;
}

template <typename T>
void Tree<T>::remove_subtree(Node<T> *n){
    if (n != nullptr)
    {
        remove_subtree(n->left);
        remove_subtree(n->right);
        remove_node(n);
    }
}

template <typename T>
void Tree<T>::remove_subtree(const T val){
    Node<T>* n;
    n = find_node(val);
    remove_subtree(n);
}

template <typename T>
Node<T>* Tree<T>::where(where_func wf, Node<T>* n, Tree<T> &new_tree) {
    if (n != nullptr)
    {
        if (wf(n->data))
        {
            new_tree.add_node(n->data);
        }
        where(wf, n->left, new_tree);
        where(wf, n->right, new_tree);
    }
    return new_tree.root;
}

template <typename T>
Tree<T> Tree<T>::where(where_func wf){
    Tree<T> new_tree;
    Node<T>* n = root;
    where(wf, n, new_tree);
    
    return new_tree;
}

template <typename T>
Node<T>* Tree<T>::merge(Node<T> *n, Tree<T> &new_tree){
    if (n != nullptr)
    {
        new_tree.add_node(n->data);
        merge(n->left, new_tree);
        merge(n->right, new_tree);
    }
    return new_tree.root;
}

template <typename T>
Tree<T> Tree<T>::merge(Tree<T> &sec_tree){
    Tree<T> new_tree;
    new_tree = copy_tree(root);
    Node<T> *n = sec_tree.root;
    merge(n, new_tree);
    return new_tree;
}

template <typename T>
void Tree<T>::map(Node<T> *n, map_func mf){
    if (n != nullptr)
    {
        n->data = mf(n->data);
        map(n->left, mf);
        map(n->right, mf);
    }
}
template <typename T>
void Tree<T>::map(map_func mf){
    map(root, mf);
}

template <typename T>
void Tree<T>::print(Node<T>* n, int level){
    
    if (n != nullptr){
        print(n->right, level + 1);
        for (int i = 0; i < level; i++) cout<<"   ";
        cout<<n->data<<endl;
        print(n->left, level + 1);
    }
}

template <typename T>
void Tree<T>::print(){
    if (root == nullptr) cout<<"\nTree is empty.\n\n";
    else{
        print(root, get_depth());
        cout<<endl;
    }
}

template <typename T>
int Tree<T>::get_depth(){
    int length = 0;
    return get_depth(root,length);
}

template <typename T>
int Tree<T>::get_depth(Node<T> *n, int depth){
    if (n == nullptr)
        return depth;
    return max(get_depth(n->left, depth + 1), get_depth(n->right, depth + 1));
}
