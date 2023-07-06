#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

class linked_list {
	private:
	    node *head, *tail;
	public:
	    linked_list() {
	        head = NULL;
	        tail = NULL;
	    }

	    void add_node(int value) {
	        node *temp = new node;
	        temp->data = value;
	        temp->next = NULL;
	
	        if (head == NULL) {
	            head = temp;
	            tail = temp;
	        } else {
	            tail->next = temp;
	            tail = tail->next;
	        }
	    }
	
	    void insert_start(int value) {
	        node *temp = new node;
	        temp->data = value;
	        temp->next = head;
	        head = temp;
	
	        cout << "Value added successfully.\n";
	    }
	
	    void insert_last(int value){
				node *temp = new node;
				temp->data = value;
				temp->next = NULL;
				
				if (head == NULL){
					head = temp;
				} else {
					node *current = head;
					while(current->next != NULL){
						current = current->next;
					}
					current->next = temp;
				}
				cout << " Value added successfully. \n\n";
			}
	
	    void insert_anywhere(int pos, int value) {
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			
			if (pos == 1) {
			    temp->next = head;
			    head = temp;
			} else {
			    node *current = head;
			    for (int i = 1; i < pos - 1; i++) {
			        if (current == NULL) {
			            cout << "Invalid position. Position exceeds the length of the list.\n";
			            delete temp;
			            return;
			        }
			        current = current->next;
			    }
			
			    if (current == NULL) {
			        cout << "Invalid position. Position exceeds the length of the list.\n";
			        delete temp;
			        return;
			    }
			
			    temp->next = current->next;
			    current->next = temp;
			}
			
			cout << "Value added successfully.\n";
	    }
	
	    void del_start() {
	        node *temp = new node;
	        temp = head;
	        head = head->next;
	        delete temp;
	    }
	
	    void del_last() {
	        node *current = new node;
	        node *previous = new node;
	        current = head;
	        while (current->next != NULL) {
	            previous = current;
	            current = current->next;
	        }
	        tail = previous;
	        previous->next = NULL;
	        delete current;
	    }
	
	    void del_anywhere(int pos) {
	        node *current = new node;
	        node *previous = new node;
	        current = head;
	        if (pos == 1) {
	            head = current->next;
	        } else {
	            for (int i = 1; i < pos; i++) {
	                previous = current;
	                current = current->next;
	            }
	            previous->next = current->next;
	        }
			delete current;
	    }
	
	    void display() {
	        node *temp = new node;
	        temp = head;
	        while (temp != NULL) {
	            cout << temp->data << "\t";
	            temp = temp->next;
	        }
	    }
	
	    void displayList() {
	        node *temp = new node;
	        temp = head;
	
	        cout << "Linked List:" << endl;
	        int index = 1;
	        while (temp != NULL) {
	            cout << "[" << index << "]" << temp->data << endl;
	            temp = temp->next;
	            index++;
	        }
	        cout << endl;
	    }
};

int main() {
    int value, pos;
    int n = 0;
    char choice;
    int del_choice;

    linked_list list;

    do {
        cout << "\nMENU" << endl;
        cout << "a. ADD" << endl;
        cout << "b. DELETE" << endl;
        cout << "c. DISPLAY" << endl;
        cout << "d. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter value: ";
                cin >> value;

                cout << "\nAdd to what position:\n";
                cout << "1. Start\n";
                cout << "2. End\n";
                cout << "3. Any position\n";
                cout << "Enter your choice: ";
                cin >> del_choice;
                if (del_choice == 1) {
                    list.insert_start(value);
                    list.displayList();
                } else if (del_choice == 2) {
                    list.insert_last(value);
                    list.displayList();
                } else if (del_choice == 3) {
                    cout << "Enter the position to insert: ";
                    cin >> pos;
                    list.insert_anywhere(pos, value);
                    list.displayList();
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
                break;
            case 'b':
                cout << "Delete from what position:\n";
                cout << "1. Start\n";
                cout << "2. End\n";
                cout << "3. Any position\n";
                cout << "Enter your choice: ";
                cin >> del_choice;
                if (del_choice == 1) {
                    list.del_start();
                    list.displayList();
                } else if (del_choice == 2) {
                    list.del_last();
                    list.displayList();
                } else if (del_choice == 3) {
                    cout << "Enter the position to delete: ";
                    cin >> pos;
                    list.del_anywhere(pos);
                    list.displayList();
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
                break;
            case 'c':
                list.displayList();
                break;
            case 'd':
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'd');

    return 0;
}
