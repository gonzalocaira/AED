
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

class Nodo{
    public:
        int data;
        int degree;
        Nodo *p;
        Nodo *child;
        Nodo *sibling;
        Nodo(){};
        Nodo(int data_,int degree_){
            data=data_;
            degree=degree_;
            p=child=sibling=NULL;
        }
};

class BinomialHeap{
    private:
        Nodo *head;
        static void linkBinomialTrees(Nodo *x,Nodo *y){
            y->p = x;
            y->sibling = x->child;
            x->child = y;

            // increase the degree of x
            x->degree += 1;
	}
    public:
        BinomialHeap(){
            head=NULL;
        }
        Nodo findMin(){
            int min = 999999;
            Nodo *aux1= head;
            Nodo *auxMin=NULL;
            while(aux1 != NULL){
                if(aux1->data < min){
                    min = aux1->data;
                    auxMin=aux1;
                }
                aux1 = aux1->sibling;
            }
            return *auxMin;
        }
        void createSampleHeap3() {
		

	}
    void createSampleHeap1() {
		// B0
		Nodo *Nodo1 = new Nodo( 5, 0);
		head = Nodo1;

		// B1
		Nodo *Nodo2 = new Nodo( 17, 1);
		Nodo *Nodo3 = new Nodo( 27, 0);
		Nodo2->child = Nodo3;
		Nodo3->p = Nodo2;

		// link B0 and B1
		Nodo1->sibling = Nodo2;

		// B3
		Nodo *Nodo4 = new Nodo(12, 3);
		Nodo *Nodo5 = new Nodo(18, 2);
		Nodo *Nodo6 = new Nodo(16, 1);
		Nodo *Nodo7 = new Nodo( 15, 0);
		Nodo *Nodo8 = new Nodo(23, 1);
		Nodo *Nodo9 = new Nodo(30, 0);
		Nodo *Nodo10 = new Nodo( 22, 0);
		Nodo *Nodo11 = new Nodo( 25, 0);
		Nodo4->child = Nodo5;
		Nodo5->p = Nodo4;
		Nodo6->p = Nodo4;
		Nodo7->p = Nodo4;
		Nodo5->child = Nodo8;
		Nodo5->sibling = Nodo6;
		Nodo6->child = Nodo10;
		Nodo6->sibling = Nodo7;
		Nodo8->p = Nodo5;
		Nodo9->p = Nodo5;
		Nodo10->p = Nodo6;
		Nodo8->child = Nodo11;
		Nodo8->sibling = Nodo9;
		Nodo11->p = Nodo8;

		// link B1 and B3
		Nodo2->sibling = Nodo4;
        
    }
    void createSampleHeap2() {
		// B0
		Nodo * Nodo1 = new Nodo ( 5, 0);
		head = Nodo1;

		// B2
		Nodo * Nodo2 = new Nodo( 6, 2);
		Nodo * Nodo3 = new Nodo (12, 1);
		Nodo * Nodo4 = new Nodo (34, 0);
		Nodo * Nodo5 = new Nodo (33, 0);
		Nodo2->child = Nodo3;
		Nodo3->p = Nodo2;
		Nodo4->p = Nodo2;
		Nodo3->child = Nodo5;
		Nodo3->sibling = Nodo4;
		Nodo5->p = Nodo3;

		// link B0 and B1
		Nodo1->sibling = Nodo2;

		// B3
		Nodo * Nodo6 = new Nodo( 1, 3);
		Nodo * Nodo7 = new Nodo ( 2, 2);
		Nodo * Nodo8 = new Nodo ( 12, 1);
		Nodo * Nodo9 = new Nodo(6, 0);
		Nodo * Nodo10 = new Nodo ( 4, 1);
		Nodo * Nodo11 = new Nodo (13, 0);
		Nodo * Nodo12 = new Nodo( 18, 0);
		Nodo * Nodo13 = new Nodo ( 7, 0);
		Nodo6->child = Nodo7;
		Nodo7->p = Nodo6;
		Nodo8->p = Nodo6;
		Nodo7->p = Nodo6;
		Nodo7->child = Nodo10;
		Nodo7->sibling = Nodo8;
		Nodo8->child = Nodo12;
		Nodo8->sibling = Nodo9;
		Nodo10->p = Nodo7;
		Nodo11->p = Nodo7;
		Nodo12->p = Nodo8;
		Nodo10->child = Nodo13;
		Nodo10->sibling = Nodo11;
		Nodo13->p = Nodo10;

		// link B1 and B3
		Nodo2->sibling = Nodo6;
	}
    void createSampleHeap33() {
		// B1
		Nodo * Nodo1 = new Nodo(29, 1);
		Nodo * Nodo2 = new Nodo(33, 0);
		Nodo1->child = Nodo2;
		Nodo2->p = Nodo1;
		head = Nodo1;

		// B2
		Nodo * Nodo3 = new Nodo(21, 2);
		Nodo * Nodo4 = new Nodo(23, 1);
		Nodo * Nodo5 = new Nodo(78, 0);
		Nodo * Nodo6 = new Nodo(50, 0);
		Nodo3->child = Nodo4;
		Nodo4->p = Nodo3;
		Nodo5->p = Nodo3;
		Nodo4->child = Nodo6;
		Nodo4->sibling = Nodo5;
		Nodo6->p = Nodo4;

		// link B1 and B2
		Nodo1->sibling = Nodo3;

	}
    void insert(int data) {
		BinomialHeap h;
		Nodo *p = new Nodo(data, 0);
		h.setHead(p);
		merge(h);
	}
    void printHeap() {
		Nodo *currPtr = head;
		while (currPtr != nullptr) {
			cout<<"L ["<<currPtr->degree<<"]"<<endl;
			cout<<"Son "<<pow(2, currPtr->degree)<<" nodos en el arbol"<<endl;
			cout<<"El orden de nivel transversal "<<endl;
			queue<Nodo *> q;
			q.push(currPtr);
			while (!q.empty()) {
				Nodo *p = q.front();
				q.pop();
				cout<<p->data<<" ";

				if (p->child != nullptr) {
					Nodo *tempPtr = p->child;
					while (tempPtr != nullptr) {
						q.push(tempPtr);
						tempPtr = tempPtr->sibling;
					}
				} 
			}
			currPtr = currPtr->sibling;
			cout<<endl<<endl;
		}
	}
    // returns the head pointer
	Nodo * getHead() {
		return head;
	}

	// setter for head
	void setHead(Nodo *head) {
		this->head = head;
	}
    void merge(BinomialHeap h1) {
		Nodo * curr1 = getHead();
		Nodo * curr2 = h1.getHead();
		Nodo * curr3 = nullptr;
		Nodo * temp = nullptr;

		if (curr1->degree <= curr2->degree) {
			curr3 = curr1;
			curr1 = curr1->sibling;
		} else {
			curr3 = curr2;
			curr2 = curr2->sibling;
		}

		temp = curr3;

		// merge two heaps without taking care of trees with same degree
		// the roots of the tree must be in accending order of degree from
		// left to right
		while(curr1 != nullptr && curr2 != nullptr) {
			if (curr1->degree <= curr2->degree) {
				curr3->sibling = curr1;
				curr1 = curr1->sibling;
			} else {
				curr3->sibling = curr2;
				curr2 = curr2->sibling;
			}

			curr3 = curr3->sibling;
		}

		if (curr1 != nullptr) {
			// copy all the remaining trees of heap1
			while(curr1 != nullptr) {
				curr3->sibling = curr1;
				curr1 = curr1->sibling;
				curr3 = curr3->sibling;
			}
		}

		if (curr2 != nullptr) {
			// copy all the remaining trees of heap2
			while(curr2 != nullptr) {
				curr3->sibling = curr2;
				curr2 = curr2->sibling;
				curr3 = curr3->sibling;
			}
		}


		// scan the merged list and repeatidly merge binomial trees with same degree
		curr3 = temp;
		Nodo * prev = nullptr;
		Nodo * next = curr3->sibling;

		while (next != nullptr) {
			// if two adjacent tree roots have different degree or 3 consecutive roots have same degree
			// move to the next tree
			if ((curr3->degree != next->degree )|| (next->sibling != nullptr && curr3->degree == next->sibling->degree)) {
				prev = curr3;
				curr3 = next;
			} else {
				// otherwise repeatdly merge binomial trees with same degree
				if (curr3->data <= next->data) {
					curr3->sibling = next->sibling;
					BinomialHeap::linkBinomialTrees(curr3, next);
				} else {
					if (prev == nullptr) {
						temp = next;
					} else {
						prev->sibling = next;
					}

					BinomialHeap::linkBinomialTrees(next, curr3);
					curr3 = next;
				}
			}

			next = curr3->sibling;
		}

		setHead(temp);
	}
    Nodo * deleteMin() {
		Nodo * curr = head;
		Nodo * prevMin = nullptr;
		// find the root with minimum key
		Nodo * minPtr = nullptr;
		Nodo * prevPtr = nullptr;
		int min = 999999;

		while (curr != nullptr) {
			if (curr->data <= min) {
				min = curr->data;
				prevMin = prevPtr;
				minPtr = curr;
			}
			prevPtr = curr;
			curr = curr->sibling;
		}

		// delete the Nodo  pointed by minPtr
		if (prevMin != nullptr && minPtr->sibling != nullptr) {
			prevMin->sibling = minPtr->sibling;
		} else if (prevMin != nullptr && minPtr->sibling == nullptr) {
			prevMin->sibling = nullptr;
		}

		// remove parent reference from all its child
		Nodo * childPtr = minPtr->child;
		while (childPtr != nullptr) {
			childPtr->p = nullptr;
			childPtr = childPtr->sibling;
		}

		// reverse the order 
		stack<Nodo *> s;
		childPtr = minPtr->child;
		while (childPtr != nullptr) {
			s.push(childPtr);
			childPtr = childPtr->sibling;
		}

		curr = s.top();
		Nodo * temp = curr;
		s.pop();

		while (!s.empty()) {
			curr->sibling = s.top();
			s.pop();
			curr = curr->sibling;
		}

		curr->sibling = nullptr;

		BinomialHeap h;
		h.setHead(temp);

		// merge 
		merge(h);

		// return the min root
		return minPtr;
	}
    

};
int main(){
    BinomialHeap heap1;
	BinomialHeap heap2;
	BinomialHeap heap3;
	heap1.createSampleHeap2();
	heap2.createSampleHeap33();
	heap1.merge(heap2);
	heap1.printHeap();
	heap1.deleteMin();
    cout<<"------------------"<<endl;
	heap1.printHeap();
    return 0;
}