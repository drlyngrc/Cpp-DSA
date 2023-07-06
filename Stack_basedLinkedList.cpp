#include <iostream>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;	
};

class Stack {
	private:
		ListNode *head, *tail;
		
	public:
		Stack(){
			head = NULL;
			tail = NULL;
		}
		
		void push(int value){
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
		
		int pop(){
			if(tail == NULL){
				throw runtime_error("Cannot  delete. Empty \n");
			}
			
			ListNode *old_tail = tail;
			int top_element = tail->data;
			
			if (head == tail){
				head = NULL;
				tail = NULL;
			} else {
				ListNode *current = head;
				
				while(current->next != tail){
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
			}
			delete old_tail;
			rteurn top_element;
		}
		
		int peek (){
			if (tail == NULL){
				throw runtime_error("Cannot peek. Empty. \n");
			} 
			return tail->data;
		}
		
		int get_index(int value){
			ListNode *current = head;
			
			for (int i = 0; current != NULL; i++){
				if(current->data == value){
					return i;
				}
				
				current = current->next;
			}
			
			return -1;
		}
		
		void print(){
			cout << "[";
			
			if (head != NULL){
				cout << head->data;
				ListNode *current = head->next;
				
				while(current != NULL){
					cout << " " << current->data;
					
					current = current->next;
				}
			}
			
			cout << "]" << endl;
		}
};