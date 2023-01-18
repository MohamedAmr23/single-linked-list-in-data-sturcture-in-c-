#include<iostream>
using namespace std;
class linked_list {
	struct node {
		int data;
		node* next;
	};
		node* head = NULL;
public:
	void append(int value) {
		node* k = new node;
		k->data = value;
		k->next = NULL;
		if (head == NULL) {
			head = k;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = k;
		}
	}
	void remove(int value) {
		if (head == NULL) {
			return;
	}
		node* temp,*pre;
		pre = head;
		temp = head;
		if (temp->data == value) {
			head = temp->next;
			delete temp;
			return;
		}
		while (temp != NULL&&temp->data!=value) {
			pre = temp;
			temp = temp->next;
		}if (temp == NULL) {
			return;
		}
		else {
			pre->next = temp->next;
			delete temp;
		}
	};
	void insert_at_pos(int value,int pos){
		node* k = new node;
		k->data = value;
		k->next = NULL;
		if (pos == 0) {
			k->next = head;
			head = new node;
			return;
		}
		node* temp=head;
		for (int i = 0; i < pos - 1; i++) {
			if (temp->next == NULL) {
				break;
			}
			temp = temp->next;

		}
		k->next = temp->next;
		temp->next = k;
	
	}
	void delete_at_pos(int pos) {
		if (head == NULL) {
			return;

			if (pos == 0) {
				node* temp = head;
				head = head->next;
				delete temp;
			}
			
			else {
				node* temp=head;
				for (int i = 0; i < pos - 1; i++) {
					if (temp->next == NULL) {
						break;
					}
					temp = temp->next;
				}
				if (temp->next == NULL) {   //delete element >linked list
					return;
				}
				node* temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
			}
		}



	}
	void display() {
		node* temp = head;
		while (temp->data != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

	}
};
int main() {
	linked_list s;
	s.append(5);
	s.append(4);
    s.remove(4);
	s.display();


	return 0;
}