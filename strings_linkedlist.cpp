#include <iostream>

using namespace std;

struct node {
	string data;
	node *next;	
};

class list {
	private:
		node *head, *tail;
	
	public:
		list (){
			head = NULL;
			tail = NULL;
		}
		
		void add_start(string text){
			node *temp = new node;
			temp->data = text;
			temp->next = head;
			head = temp;
			
			cout << "   *Added successfully.*\n\n";
		}
		
		void add_last(string text){
			node *temp = new node;
			temp->data = text;
			temp->next = NULL;
			
			if (head == NULL){
				head = temp;
			} else {
				node *current = head;
				while (current->next != NULL){
					current = current->next;
				}
				current->next = temp;
			}
			cout << "   *Added successfully.*\n\n";
		}
		
		void add_anywhere(int index, string text){
			node *temp = new node;
			temp->data = text;
			temp->next = NULL;
			
			if (index == 1) {
			    temp->next = head;
			    head = temp;
			} else {
			    node *current = head;
			    for (int i = 1; i < index - 1; i++) {
			        if (current == NULL) {
			            cout << "   Invalid position.\n";
			            delete temp;
			            return;
			        }
			        current = current->next;
			    }
			    if (current == NULL) {
			        cout << "   Invalid position. \n";
			        delete temp;
			        return;
			    }
			    temp->next = current->next;
			    current->next = temp;
			}
			cout << "   *Added successfully.*\n\n";
		}
		
		void del_start(){
			node *temp = new node;
			temp = head;
			head = head->next;
			delete temp;
			
			cout << "   *Deleted successfully.*\n\n";
		}
		
		void del_last(){
			node *current = new node;
			node *previous = new node;
			current = head;
			while(current->next != NULL){
				previous = current->next;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			delete current;
			
			cout << "   *Deleted successfully.*\n\n";
		}
		
		void del_anywhere(int index){
			node *current = new node;
			node *previous = new node;
			current = head;
			if (index == 1){
				head = current->next;
			} else {
				for (int i = 1; i < index; i++){
					previous = current;
					current = current->next;
				}
				previous->next = current->next;
			}
			
			delete current;
			cout << "   *Deleted successfully.*\n\n";
		}
		
		/*void del_string(string text){
			node *current = head;
			node *previous =  NULL;
			
			while (current != NULL){
				if (current->data ==  text){
					if (previous == NULL){
						head = current->next;
						delete current;
						cout << "   *Deleted successfully.*\n\n";
						return;
					} else {
						previous->next = current->next;
						delete current;
						cout << "   *Deleted successfully.*\n\n";
						return;
					}
				}
				previous = current;
				current = current->next;
			}
			cout << "   Not found in the linked list.\n";
		}
		*/
		
		
		void del_dup_string(string text){
			node *current =  head;
			node *previous = NULL;
			bool found = false;
			
			while (current != NULL){
				if (current->data == text){
					if (previous == NULL){
						head = current->next;
						delete current;
						current = head;
						found = true;
					} else {
						previous->next = current->next;
						delete current;
						current = previous->next;
						found = true;
					}
				} else {
					previous = current;
					current =  current->next;
				}
			}
			if(found){
				cout << "   *Deleted successfully.*\n\n";
			} else {
				cout << "   Not found in the linked list.\n";
			}
		}
		
		void display(){
			node *temp = new node;
			temp = head;
			
			cout << "   LINKED LIST \n";
			if (temp == NULL){
				cout << "   Empty.\n";
				return;
			}
			
			while (temp != NULL) {
	            cout << "   [" << temp->data << "]";
	            temp = temp->next;
			}
			cout << "\n";
		}
		
		int search(string text){
			node *temp = new node;
			temp = head;
			int index = 1;
			while (temp != NULL){
				if (temp->data == text){
					return index;
				}
				temp = temp->next;
				index++;
			}
			return -1;
		}
		
		void duplicate_check(string text){
			node *temp = head;
			int index = 1;
			bool foundDuplicate = false;
			 
			
			while(temp != NULL){	
				if (temp->data == text){
					foundDuplicate = true;
					cout << "   Text found at position: " << index << "\n";
				}
				temp = temp->next;
				index++;
			}	
			if(!foundDuplicate){
				cout << "   Text not found.";
			}
		}
};


int main(){
	string text, action, action1;
	int index;
	list list;
	
	while (true){
		cout << "\n   MAIN MENU \n";
		cout << "   [a] ADD\n";
		cout << "   [b] DELETE\n";
		cout << "   [c] SEARCH\n";
		cout << "   [d] DISPLAY\n";
		cout << "   [e] EXIT\n";
		cout << "   Choose action: ";
		cin >> action;
		cout << "\n";
		
		if (action == "a"){
			cout << "   Enter string to add: ";
			cin >> text;
			cout << "\n   At what position:\n";
                cout << "   [a] Start\n";
                cout << "   [b] End\n";
                cout << "   [c] Any position\n";
                cout << "   Enter your choice: ";
                cin >> action1;
                if (action1 == "a"){
                	list.add_start(text);	
				} else if (action1 == "b" ){
					list.add_last(text);
				} else if (action1 == "c"){
					cout << "\n   At what position: ";
					cin >> index;
					list.add_anywhere(index, text);
				} else {
					cout << "   Invalid choice. \n";
				} 
		} else if (action == "b"){
			list.display();
			cout << "\n   From what position:\n";
                cout << "   [a] Start\n";
                cout << "   [b] End\n";
                cout << "   [c] Any position\n";
                cout << "   [d] Specific string\n";
                cout << "   Enter your choice: ";
                cin >> action1;
                if (action1 == "a"){
                	list.del_start();	
				} else if (action1 == "b" ){
					list.del_last();
				} else if (action1 == "c"){
					cout << "\n   From what position: ";
					cin >> index;
					list.del_anywhere(index);
				} else if (action1 == "d"){
					cout << "   Enter string to delete: ";
					cin >> text;
					list.del_dup_string(text);
				} else {
					cout << "   Invalid choice. \n";
				} 
		} else if (action == "c"){
			cout << "   Enter string to search: ";
			cin >> text;
			list.duplicate_check(text);
			cout << "\n";
		} else if (action == "d"){
			list.display();
		} else if (action == "e"){
			cout << "   Exiting the program.\n";
			exit(0);
		} else {
			cout << "  Invalid action.";
		}
	}
	
	return 0 ;
}



