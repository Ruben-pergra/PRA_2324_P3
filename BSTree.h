#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T>
class BSTree {
private:
    int nelem; //Numero de elementos en el ABB
    BSNode<T> *root; //Nodo raíz del ABB

    BSNode<T>* search(BSNode<T>* n, T e) const {
        if (n == nullptr) {
            throw runtime_error("El elemento no se encuentra en el árbol");
        } 
        else if (n->elem < e) {
            return search(n->right, e);
        } 
        else if (n->elem > e) {
            return search(n->left, e);
        } 
        else {
            return n;
        }
    }

    BSNode<T>* insert(BSNode<T>* n, T e) {
        if (n == nullptr) {
            ++nelem;
            return new BSNode<T>(e);
        } 
        else if (n->elem == e) {
            throw runtime_error("El elemento ya existe");
        } 
        else if (n->elem < e) {
            n->right = insert(n->right, e);
        } 
        else {
            n->left = insert(n->left, e);
        }
        return n;
    }

    void print_inorder(ostream &out, BSNode<T>* n) const {
        if (n != nullptr) {
            print_inorder(out, n->left);
            out << n->elem << " ";
            print_inorder(out, n->right);
        } else return;
    }

    BSNode<T>* remove(BSNode<T>* n, T e) {
        if (n == nullptr) {
            throw runtime_error("El elemento no existe");
        } 
        else if (n->elem < e) {
            n->right = remove(n->right, e);
        } 
        else if (n->elem > e) {
            n->left = remove(n->left, e);
        } 
        else {
            if (!n->left) {
                BSNode<T>* temp = n->right;
                delete n;
                --nelem;
                return temp;
            } 
            else if (!n->right) {
                BSNode<T>* temp = n->left;
                delete n;
                --nelem;
                return temp;
            } 
            else {
                T maxVal = max(n->left);
                n->elem = maxVal;
                n->left = remove_max(n->left);
            }
        }
        return n;
    }

    T max(BSNode<T>* n) const {
        if (n == nullptr) {
            throw runtime_error("El nodo es nulo");
        } 
        else if (n->right != nullptr) {
            return max(n->right);
        } 
        else return n->elem;
    }

    BSNode<T>* remove_max(BSNode<T>* n) {
        if (n->right == nullptr) {
            BSNode<T>* temp = n->left;
            delete n;
            return temp;
        } 
        else {
            n->right = remove_max(n->right);
            return n;
        }
    }

    void delete_cascade(BSNode<T>* n) {
        if (n == nullptr) return;
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }

public:
    BSTree() : nelem(0), root(nullptr) {}

    ~BSTree() {
        delete_cascade(root);
    }

    int size() const {
        return nelem;
    }

    T search(T e) const {
        return search(root, e)->elem;
    }

    T operator[](T e) const {
        return search(e);
    }

    void insert(T e) {
        root = insert(root, e);
    }

    friend ostream& operator<<(ostream &out, const BSTree<T> &bst) {
        bst.print_inorder(out, bst.root);
        return out;
    }

    void remove(T e) {
        root = remove(root, e);
    }
};

#endif