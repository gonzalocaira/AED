
#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <iterator>

using namespace std;
template<class T>
class SingleNode{
	public:
		typedef SingleNode<T>* Single;
		Single parent;
		Single child;
		Single sibling;
		T data;
		int degree;
	public:
		SingleNode(T _data): parent(0), child(0), sibling(0), degree(0), data(_data) {};
};

template<class T>
class Binomial_Heap{
	typedef SingleNode<T>* Single;
	private:
		Single root;
		int length(Single node);
	public:
		Single min;
		Binomial_Heap(): root(0), min(0) {};
		Single make_Heap(T x);
		Single merge(Single node1);
		Single mergeSort(Single node1, Single node2);
		void Insert(T x);
		void Union_Heap(Single node1, Single node2);
		void Binomial_link(Single p_child, Single p_parent);
		void printSiblings();
		Single decrease_key(Single node, T x);
		Single delete_key(Single node);
		void find_min();
		void balance(Single ptr);
		Single get_min();
		void graph_image();
		void graph_child();
};
template<class T>
SingleNode<T>* Binomial_Heap<T>::decrease_key(SingleNode<T>* node,T x){
	node->data=x;
	while(node->parent){
		if (node->data < node->parent->data)
			std::swap(node->data, node->parent->data);
		else
			break;
		node = node->parent;
	}
	return node;
}
template<class T>
SingleNode<T>* Binomial_Heap<T>::get_min(){
	SingleNode<T>* ptr = root;
	SingleNode<T>* children = min->child;
	if (children){
		if (ptr != min){
			while(ptr->sibling != min)
				ptr = ptr->sibling;
			Union_Heap(ptr,children);
		}
		else
			root = children;
		while(children->sibling){
			children->parent = NULL;
			children = children->sibling;
		}
		children->parent = NULL;
		Union_Heap(children,min->sibling);
		ptr = min;
		merge(root);
		balance(root);
	}
	else
		root = root->sibling;
	find_min();
	return ptr;
}
template<class T>
SingleNode<T>* Binomial_Heap<T>::delete_key(SingleNode<T>* node){
	min = decrease_key(node, min->data-1);
	return get_min();
}
template<class T>
void Binomial_Heap<T>::find_min(){
	SingleNode<T>* ptr = root;
	min = ptr;
	if (ptr){
		while(ptr->sibling){
			ptr = ptr->sibling;
			if (ptr->data < min->data)
				min = ptr;
		}
	}
}
template<class T>
int Binomial_Heap<T>::length(SingleNode<T>* node){
	int c = 0;
	while(node){
		++c;
		node = node->sibling;
	}
	return c;
}
template<class T>
SingleNode<T>*  Binomial_Heap<T>::make_Heap(T x) {
	return new SingleNode<T>(x);
}
template<class T>
void Binomial_Heap<T>::Insert(T x){
	SingleNode<T>* newNode = make_Heap(x);
	if (!root){
		root = newNode;
		min = newNode;
	}
	else{
		Union_Heap(newNode, root);
		root = newNode;
		balance(root);
	}
	if (x < min->data)
		min = newNode;
	//std::cout << x << std::endl;
}
template<class T>
SingleNode<T>* Binomial_Heap<T>::merge(SingleNode<T>* node1){
	if (node1->sibling == NULL)
		return node1;
	int len = length(node1)/2;
	int i=1;
	SingleNode<T>* ptr=node1;
	SingleNode<T>* node2 = node1->sibling;
	while(i!=len){
		ptr=node2;
		node2=node2->sibling;
		++i;
	}
	ptr->sibling = NULL;
	node1 = merge(node1);
	node2 = merge(node2);
	return mergeSort(node1,node2);
}
template<class T>
SingleNode<T>* Binomial_Heap<T>::mergeSort(SingleNode<T>* node1, SingleNode<T>* node2){
	SingleNode<T>** ptr = 0;
	ptr = &root;
	while((node1) && (node2)){
		if (node1->degree < node2->degree){
			*ptr = node1;
			node1 = node1->sibling;
		}
		else {
			*ptr = node2;
			node2 = node2->sibling;
		}
		ptr = &(*ptr)->sibling;
	}
	while(node1){
		*ptr = node1;
		node1 = node1->sibling;
		ptr = &(*ptr)->sibling;
	}
	while(node2){
		*ptr = node2;
		node2 = node2->sibling;
		ptr = &(*ptr)->sibling;
	}
	return root;
}
template<class T>
void Binomial_Heap<T>::Binomial_link(SingleNode<T>* p_child, SingleNode<T>* p_parent){
	if (p_parent->sibling == p_child)
		p_parent->sibling = p_child->sibling;
	p_child->sibling = p_parent->child;
	p_child->parent = p_parent;
	p_parent->child = p_child;
	++p_parent->degree;
}
template<class T>
void Binomial_Heap<T>::Union_Heap(SingleNode<T>* node1, SingleNode<T>* node2){
	node1->sibling = node2;
}
template<class T>
void Binomial_Heap<T>::balance(SingleNode<T>* ptr){
	while (ptr->sibling != NULL){
		if (ptr->degree == ptr->sibling->degree){
			if (ptr->data < ptr->sibling->data)
				Binomial_link(ptr->sibling,ptr);
			else{
				if (ptr == root)
					root = ptr->sibling;
				Binomial_link(ptr,ptr->sibling);
				ptr = ptr->parent;
			}
		}
		else{
			ptr = ptr->sibling;
		}
	}
}
template<class T>
void Binomial_Heap<T>::printSiblings(){
	SingleNode<T>* ptr = root;
	SingleNode<T>* ptr2;
	while(ptr){
		std::cout << ptr->data << std::endl;
		ptr2=ptr;
		while(ptr2->child){
			ptr2=ptr2->child;
			std::cout << ptr2->data << std::endl;
		}
		ptr=ptr->sibling;
	}
}

template<class T>
void Binomial_Heap<T>::graph_image(){
	string title = "Heap";
	ofstream file("Heap.dot");
	file<<"digraph {\n";
	SingleNode<T>* ptr = root;
	SingleNode<T>* ptr2;
	SingleNode<T>* ptr3;
	while(ptr){
		file<<ptr->data<<endl;
		//std::cout << ptr->data << std::endl;
		ptr2=ptr;
		ptr3=ptr2;
		while(ptr2->child){
			ptr2=ptr2->child;
			ptr3=ptr3->sibling;
			//file<<aux->m_Dato<<"->"<<(*it)->m_Dato<<";\n";
			file<<ptr2->data<<endl;
			file<<ptr3->data<<endl;
			//std::cout << ptr2->data << std::endl;
		}
		ptr=ptr->sibling;
	}

	file<<"}";
	file.close();
	string comando = "dot -Tpdf " + title + ".dot -o" + title + ".pdf";
	const char * ejecutable  =  comando.c_str();
	system(ejecutable);	
}


int main(){
    Binomial_Heap<int> A;
	A.Insert(3);
	A.Insert(5);
	A.Insert(6);
	A.Insert(7);
	A.Insert(1);
	A.Insert(9);
	A.Insert(10);
	A.Insert(11);
	A.Insert(15);
	A.Insert(16);
	A.Insert(18);
	A.Insert(21);
	//A.printSiblings();
	A.graph_image();
    return 0;
}