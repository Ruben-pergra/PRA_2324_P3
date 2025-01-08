#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;

template <typename T> 
class BSNode {
    public:
        T elem;
		BSNode<T>* right;
		BSNode<T>* left;
	
	
	BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
		this -> elem = elem;
		this -> left = left;
		this -> right = right;
	}

	friend ostream& operator<<(ostream &out, const BSNode<T> &bsn){
		out << "Elemento almacenado: " << bsn.elem;
		return out;
	}
};

#endif