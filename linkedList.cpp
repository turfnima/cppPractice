//2018-10-27
//by Xiaozhi Li
// my linked list practice
//single linked list version
//this list holds only a int

//each node has to have a next
#include<iostream>
#include<stdlib.h>
#include<time.h>

class ListNode {
public:
	int val;
	ListNode* next;
	//constructor
	ListNode() {
		//val = -1; want to see what happens. #question
		next = nullptr;
	}
	ListNode(int v) {
		val = v;
		next = nullptr;
	}

	//#question when do you need destructors?
	~ListNode() {
		
	}
};
//each list has to have a head
class List {
public:
	ListNode *head;
	//constructor
	List() {
		head = nullptr;
	}
	//add delete change search.

	//add
	void push_back(ListNode * node) {
		//if head is null
		if (!head)
		{
			head = node; return;
		}
		else if (!head->next) {
			head->next = node; return;
		}
		else {
			ListNode * p = new ListNode();
			p = head;
			while (p->next) {
				p = p->next;
			}
			p->next = node;
		}
		
	}
	//print all the vals of nodes from this list
	//head and nullptr added for better looking
	void printAll() {
		if(!head){
			std::cout << "\nList is empty";
		}
		else {
			ListNode *it = head;
			std::cout << "head=>";
			while (it) {
				std::cout << it->val << "->";
				it=it->next;
			}
			std::cout << "nullptr" << std::endl;
		}
		std::cout << "\nfinished printing nodes from the list\n";
		return;
	}
	//a generator that randomly generates <nums> number of integers 
	//from <leftbound> to <range>, step size 1
	//then they are all pushed back to the list
	void generator(int leftbound, int range,int nums) {
		//initialize rand seed
		srand(time(NULL));
		
		for (int i = 0; i < nums; i++) {
			ListNode* p = new ListNode();
			 p->val= rand() % range + leftbound;
			 push_back(p);
		}
	}
	//erase only the first node from the list
	void eraseFirst() {
		if (!head)  
			return;
		if (!head->next) { 
			delete(head); 
			head = nullptr;
			return; 
		}
		ListNode * p = head;
		head = head->next;
		delete(p);
		return;
	}
	//erase all nodes from the list
	void eraseAll() {
		if (!head)
			return;
		ListNode *p = head;
		while (head) {
			head = head->next;
			delete(p);
			p = head;
		}
	}
	
	//search
	//search if int n is held at the list, return the ptr at that node
	ListNode * searchN(int n) {
		if (!head) return nullptr;
		ListNode *target = new ListNode(), *p = new ListNode();
		p = head;
		
		while (p) {
			if (p->val == n) {
				return p;
			}
			p = p->next;
		}
		//p is nullptr after loop
		return p;
	}
	//set the value of node p to n
	//set only changes the first encounter of value n  
	void set(ListNode* p, int n) {
		if (p == nullptr) return;//std::cout << "cant change nullptr\n";
		else if (p->val == n) return;
		else{
			p->val = n;
			return;
		}

	}
	
};

int main() {
	//test printALL and generator
	std::cout << "test printALL and generator\n";
	List l;
	l.generator(0, 20, 7);	
	l.printAll();

	//test erase
	std::cout << "test erase\n";
	l.eraseFirst();
	l.printAll();
	//test erase all
	l.eraseAll();
	l.printAll();

	//test add
	std::cout << "test add\n";
	ListNode *k = new ListNode(55);
	l.push_back(k);
	l.printAll();
	l.eraseFirst();
	//test search
	std::cout << "\ntest seach\n";
	l.generator(1, 20, 7);
	l.printAll();
	for (int i = 1; i < 20; i++) {
		if (l.searchN(i) == nullptr) std::cout << i << "-F ";
		else
			std::cout << i << "-T ";
	}

	//test set
	//set only changes the first encounter of value n
	std::cout << "\n\ntest set\n";
	l.printAll();
	for (int i = 0; i < 11; i++) {
		l.set(l.searchN(i), 0);
	}
	l.printAll();
	//for keep the console window from closing
	getchar();
	return 0;
}