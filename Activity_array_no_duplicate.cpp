#include <iostream>

using namespace std;

int find(int arr[], int n, int key){
	int i;
	for(int i = 0; i < n; i++){
		if (arr[i] == key){
			return i;
		}
	}
	return -1;
}

int insert(int arr[], int n, int key, int capacity){
	if (n >= capacity)
	return n;
		
	arr[n] = key;
	
	return (n + 1);	
}

int del(int arr[], int n, int key){
	int position = find(arr, n, key);
	
	if (position == -1){
		cout << "Not found!" << endl;
		return n;
	}
	
	int i;
	for (i = position; i < n - 1; i++){
		arr[i] = arr[i + 1];
	}
	
	return n - 1;
}


int main(){
	int arr[15] = {};
	string choice;
	int n = 0;
	int i, key;
	int capacity = 15;
	
	cout << " Enter 5 integers: ";
	for (i = 0; i < 5; ++i ){
		cin >> key;	
		n = insert(arr, n, key, capacity);
	}
	
	
	do {
		cout << " \nMAIN MENU " << endl;
		cout << " 1. Add " << endl;
		cout << " 2. Delete " << endl;
		cout << " 3. Search " << endl;
		cout << " 4. Exit " << endl; 
		cout << " Enter choice: ";
		cin >> choice;
		
		if(choice == "1"){
				if (n < capacity){
					cout << " Enter an integer: ";
					cin >> key;
					n = insert(arr, n, key, capacity);
				} else{
					cout << " Array is full." << endl;
				}
				cout << " \nArray: " << endl;
				for(i = 0; i < n; i++){
					cout << " " << arr[i] << " ";
				}
				cout << "\n";
		} else if (choice == "2"){
				cout << " Enter an integer: ";
				cin >> key;
				n = del(arr, n ,key);
				
				cout << " \nArray: " << endl;
				for(int i = 0; i < n; i++){
					cout << " " << arr[i] << " ";
				}
				cout << "\n";
		} else if (choice == "3"){
				cout << " Enter an integer: ";
				cin >> key;
				int position = find(arr, n , key);
				if (position == -1){
					cout << " Element Not Found!" << endl;
				} else {
					cout << " Element Found at Index: " << position << endl;;
				}
				cout << " \nArray: " << endl;
				for(int i = 0; i < n; i++){
					cout << " " << arr[i] << " ";
				}
				cout << "\n";
		} else if (choice == "4"){
				cout << " Exiting the program." << endl;
		} else{
				cout << " Invalid! Try again." << endl;		
		}
		
		
	} while (choice != "4");
	
	return 0;
}