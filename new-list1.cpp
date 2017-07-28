//Turfnima
//list practice
//2017 7 13

//first decide the purpose of the code:
/*a list of nodes, with add, delete, modify

add:
	pushBack----------------------------------------------------------------check
	random generate---------------------------------------------------------check
	pushFront---------------------------------------------------------------!negative
print:
	printList---------------------------------------------------------------check


modify:
	change the data to another value----------------------------------------check
	drop the node with wanted value-----------------------------------------check
	reverse the list--------------------------------------------------------check
	reorder the list

delete:
	search------------------------------------------------------------------check
	delete------------------------------------------------------------------check
	removeall---------------------------------------------------------------check

in addition:
	destructor--------------------------------------------------------------check
	+ overload
	[] overload
	abstract class
	copy constructor

data type:
	we start with int data, then we practice the abstract


*/
#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	//the value stored
	int val;
	//the next node in the list
	Node* next;
	
	//constructor
	Node() {
		val = -1;
		next = nullptr;
	}

	Node(int v) {
		val = v;
		next = nullptr;
	}
	//copy constructor
	Node(Node &k) {

		val = k.val;
		next = k.next;
	}
	void setVal(int v) {
		val = v;
	}
	int getVal() {
		return val;
	}

	//destructor
	~Node() {
		delete next;
	}
};

class List {
public:
	Node* head;
	Node* tail;
	int numOfNodes;

	//constructor
	List() {
		head = tail = nullptr;
		numOfNodes = 0;
	}
	List(Node* n) {
		//exception alert
		//if n is null

		head = tail = n;
		n->next = nullptr;
	}

	void pushFront(Node* n);
	void addVal(int v);
	void deleteVal(int v);
	int searchVal(int v);
	void random_store(int nums, int variance);
	void pushBack(int v);
	void printList();
	void reverseAll();
	void reverseAll2();
	void remove_all(int v);
	Node* return_Nth_Node(int n);
	
};
//reverse all nodes.
//using 2 nodes
void List::reverseAll() {
	if (!head || !head->next) return;
	tail = head;
	Node*p1 = head;
	Node*p2 = p1->next;
	p1->next = nullptr;
	Node*r;
	while (p2) {
		r = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = r;
	}
	//at end p2 is nullptr
	//p1 is the last node
	//the new head.
	head = p1;
}
//return a node at Nth position
//what happens if we cant find it? we cannot return an empty node
//but we have to return something, so call that nodeX.
//if n is smaller than 0, return nodeX;
//if n is 0 return head.
//if n is 1 return head->next
//if n is n return (Node* return_Nth_Node (n-1)->next)
// if we cannot find the node, return nodeX
Node* List:: return_Nth_Node(int n) {
	//figure out what nodeX is first
	Node* nodeX = new Node();
	return nodeX;
}

//reverse all, another method
//starting from second node, insert the node between first and second.
void List::reverseAll2() {
	Node*p;
	Node*q;
	p = head->next;
	while (p->next) {
		q = p->next;
		p->next = q->next;
		q->next = head->next;
		head->next = q;
	}
	p->next = head;
	head = p->next->next;
	p->next->next = nullptr;
}


//remove all appearance of int v

void List:: remove_all(int v) {
	//if we saw v in the first node
	
	if (!head) return;
	else {
		//this deals with all continuous node since head that has same val v
		while (head->val == v&& head) {
			Node*p = head;
			head = head->next;
			p->next = nullptr;
			delete p;
		}
		//now we know head is either nullptr or head has a val !=v
		if (!head) return;
		else {
			Node*p = head;
			//notice we want to position p before any actual node we want to delete.
			while (p->next) {
				
				if (p->next->val == v) { 
					Node*k = p->next;
					p->next = p->next->next;
					k->next = nullptr;
					delete k;
					//since p->next has been deleted,
					//now p->next is pointing to the next node in line
					//hence we dont make any moves.
				}
				else {
					//p->next is not what we want, move along
					p = p->next;
				}
			}//while loop ends

		}
		return;
	}
	//if first node is not v
	//if v is the last node
}


//because it is declared under List class
//we have to declare it as class_type List:: function_name()

//any call using a List object is simply: list_object.function_name()
void List:: random_store(int nums, int variance) {
	if (nums < 0) { nums = 0 - nums; }
	if (variance < 0) { variance = 0 - variance; }
	int n;
	for (int i = 0; i < nums; i++) {
		n = rand() % variance;
		this->pushBack(n);
	}
	return;
}

//push back val k
void List::pushBack(int v) {
	//the use of tail node tells us where the end of the list is at
	//hence pushing back any node is simple

	Node* p = new Node(v);

	//is head empty?
	if (!head) {
		//if yes, them let head and tail point to p, and p->next become nullptr.
		head = tail = p;
		p->next=nullptr;
	}
	else {
		p->next = nullptr;
		tail->next = p;
		tail = tail->next;
	}
}



//print current list
void List::printList() {
	Node*p = this->head;
	/*if (!p) cout << "nothing to print";
	else {
		string ans="";
		while (p) {
			ans = p->val + " ";
			p = p->next;
		}
		cout << ans;
	}
	return;*/
	if (!p) cout << "nothing in here" << endl;
	else {
		while (p) {
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << endl;
	}
	return;
}

//add node from the front
void List::pushFront(Node* n) {

	//if n is null(seriously?) we return;
	if (n == nullptr) return;

	//if we dont have a node at the beginning
	/*
	why dont we n->next=head->next here?
	because head is already nullptr, it does not have a next.
	*/
	if (head == nullptr) {
		head = n;
		n->next = tail;
	}
	//else
	else {
		//we need to set n->next to head->next first
		//because once we set head to point n its next pointer will be lost in the universe.
		n->next = head->next;
		head = n;
	}
}
	//we add a node with int v in it.
	void List::addVal(int v) {
		Node* a = new Node(v);
		//we create a node, and then use the pushFront
		pushFront(a);

		//housekeeping (hope i did it right)
		delete a;
}

	int List:: searchVal(int v) {
		//if head is nullptr, return -1(a negative index means it doesnt exist)
		if (head == nullptr) return -1;
		else {
			Node*p = head;
			int index = 0;
			while (p) {
				if (p->val == v) return index;
				else {
					p = p->next;
					index++;
				}
			}
			
			//return -2 means it is not in the list
			//but the list is not empty
			return -2;
		}
	}

	//delete the first appearencew of the node with int v.
	void List:: deleteVal(int v) {
		//if the list is empty return
		if (head == nullptr) return;
		//if the list is not empty
		else {
			//a dummy node
			Node* p = this->head;
			//searche the value, return the index
			int i = this->searchVal(v);

			//if the index is negative
			//we cant find this value
			if (i < 0) 
				cout << "we can't find this value" << endl;
			//if the index is 0, the head node is whate we looking for
			//delete p
			else if (i == 0) {
				this->head = head->next; delete p;
			}

			//if the index is not 0
			else {
				//notice here j=1, so the iterator p will always be 1 node ahead of what we are looking at
				//aka p->next is the one we will be deleting.
				for (int j = 1; j < i; j++) {
					p = p->next;
				}
				Node* k = p->next;
				if(p->next->next)p->next = p->next->next;
				else p->next = nullptr;
				//ALERT:we have to set k->next to nullptr, else k will stay in this list and deleting k
				//will give us error
				k->next = nullptr;
				delete k;
				cout << "delete success" << endl;
				return;
			}
		}
		cout << "error!" << endl;
		return;
	}
	

	int main() {
		//some test results.
		List t1,t2;

		t1.pushBack(7);
		t1.pushBack(1);
		t1.pushBack(3);
		t1.pushBack(2);
		cout << "====Print List test:===========" << endl;
		t1.printList();
		cout<<t1.searchVal(1);

		cout <<"==============="<< endl;
		cout << "===test return Nth Node" << endl;
		cout<<"the val is "<<t1.return_Nth_Node(-1)->val<<" if it is -1 then it is correct"<<endl;
		cout << "====Random generating list===========" << endl;
		t2.random_store(40,5);
		cout << "====Delete test===========" << endl;
		t2.printList();
		cout << "===============" << endl;
		t2.deleteVal(4);
		cout << "====Remove all test===========" << endl;
		t2.printList();
		cout << "===============" << endl;
		t2.remove_all(4);
		t2.printList();

		List t3;
		t3.random_store(15,10);
		cout << "t3:" << endl;
		t3.printList();
		cout << "=====reverse==========" << endl;
		t3.reverseAll();
		t3.printList();

		getchar();
		getchar();
		return 0;
	}