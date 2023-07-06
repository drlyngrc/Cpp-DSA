#include <iostream>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;
};

class Queue{
	private:
		ListNode *head, *tail;
	
	public:
		Queue(){
			head = NULL;
			tail = NULL;
		}
		
		void enqueue (int value){
			ListNode *temp = new ListNode;
			temp->data = value;
			temp->next = NULL;
			
			if(tail == NULL){
				head = temp;
			} else {
				tail->next = temp;
			}
			tail = temp;
		}
	
		int dequeue (){
			if(head == NULL){
				throw runtime_error("Cannot delete. Empty.");
			}
			
			ListNode *old_head = head;
			int front_element = head->data;
			
			if(head == tail){
				head = NULL;
				tail = NULL;
			} else {
				head = head->next;
			} 
			
			delete old_head;
			return front_element;
		} 
		
		int peek(){
			if(head == NULL){
				throw runtime_error("Cannot peek. Empty");
			}
			
			return head->data;
		}
		
		int get_index(int value){
			ListNode *current = head;
			
			for(int i = 0; current != NULL; i++){
				if(current->data == value){
					return i;
				}
				
				current = current->next;
			}
			return -1;
		}
		
		void print(){
			cout << "[";
			
			if(head != NULL){
				cout <<  head->data;
				ListNode *current = head->next;
				
				while(current != NULL){
					cout << " " << current->data;
				}
			}
			
			cout << "]" << endl;
		}
};

int main(){
	Queue q;

	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(1);
	
	cout << "QUEUE \n";
	q.print();
	
	//DEQUEUE
	q.dequeue();
	q.dequeue();
	
	cout << "UPDATED \n";
	q.print();
	return 0;
}
