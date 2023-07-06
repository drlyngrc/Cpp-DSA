//LALONGISIP, DARLYNE GRACE M. 
//CS 1302
//QUEUE

#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

class Queue {
	private:
	    node *front, *back;
	    
	public:
	    Queue() {
	        front = NULL;
	        back = NULL;
	    }
	    
	    void enqueue_start(int value) {
	        node *temp = new node;
	        temp->data = value;
	        temp->next = front;
	        front = temp;
	
	        cout << "Value added successfully.\n\n";
	    }
	    
	    void dequeue() {
	        node *current = new node;
	        node *previous = new node;
	        current = front;
	        while (current->next != NULL) {
	            previous = current;
	            current = current->next;
	        }
	        back = previous;
	        previous->next = NULL;
	        delete current;
	        
	        cout << "Value deleted successfully. \n\n";
	    }
	    
	    
	    void search(int value){
			node *temp = front;
			int index = 1;
			bool foundDuplicate = false;
			 
			
			while(temp != NULL){	
				if (temp->data == value){
					foundDuplicate = true;
					cout << "Value found at position: " << index << "\n";
					cout << "\n";
				}
				temp = temp->next;
				index++;
			}	
			if(!foundDuplicate){
				cout << "Value not found.\n\n";
			}
		}
	    
	    void displayList() {
	        node *temp = new node;
	        temp = front;
	
	        cout << "QUEUE:" << endl;
	        int index = 1;
	        while (temp != NULL) {
	            cout << "[" << index << "]" << temp->data << endl;
	            temp = temp->next;
	            index++;
	        }
	        cout << endl;
	    }
	    
	    void identify(){
	    	if (front ==NULL){
	    		cout << "EMPTY! \n\n";
	    		return;
			}
			
			int largest = front->data;
			node *temp = front->next;
			while(temp != NULL){
				if (temp->data > largest){
					largest = temp->data;
				}
				temp = temp->next;
			}
			
			cout << "Largest integer is "<< largest << ".\n\n";
		}
	    
};


int main(){
	int value;
	char choice;
	
	Queue queue;
	
	do{
		cout << "MAIN MENU \n";
		cout << "[a] Add Element \n";
		cout << "[b] Delete Element \n";
		cout << "[c] Search Element \n";
		cout << "[d] Display Element \n";
		cout << "[e] Identify the largest integer \n";
		cout << "[f] Exit \n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		
		switch (choice){
			case 'a':
				cout << "Enter value: ";
				cin >> value;
				queue.enqueue_start(value);
				break;
			case 'b':
				queue.dequeue();
				break;
			case 'c':
				cout << "Enter value: ";
				cin >> value;
				queue.search(value);
				break;
			case 'd':
				queue.displayList();
				break;
			case 'e':
				queue.identify();
				break;
			case 'f':
				cout << "Exiting the program. \n";
				exit(0);
			default:
				cout << "Invalid choice. Please try again. \n";
		}
		
		
	} while (choice != 'f');
	return 0;
}
