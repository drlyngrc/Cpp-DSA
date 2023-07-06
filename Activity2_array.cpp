#include <iostream>

using namespace std;

int add(string array[], int n, string key, int capacity){
	if (n >= capacity)
	return n;
		
	array[n] = key;
	
	return (n + 1);	
}

int search_dup(string array[], int n, string key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (array[i] == key) {
            cout << " String found at index " << i << endl;
            found = true;
            
     	   } 
    }

	if (!found) {
    cout << " String not found!" << endl;
	}
	
    return -1;
}

int search(string array[], int n, string key){
	int i;
	for(int i = 0; i < n; i++){
		if (array[i] == key){
			return i;
		}
	}
	return -1;
}


int del(string array[], int n, string key){
    while (true) {
    	int position = search(array, n, key);
    	
		if (position == -1){
			return n;
		}
		
		n--;
		for (int i = position; i < n; i++){
			array[i] = array[i + 1];
		}
	}
}


int main(){
	string array[15] = {};
	string key, choice;
	int n = 0;
	int i;
	int capacity = 15;
	
	cout << " Enter 10 strings: \n";
	for (i = 0; i < 10; ++i ){
		cout << " " << i + 1 << " string: ";
		cin >> key;
		n = add(array, n, key, capacity);
	}
	
	do{
		cout << "\n MAIN MENU " << endl;
		cout << " a. ADD " << endl;
		cout << " b. DELETE " << endl;
		cout << " c. DISPLAY " << endl;
		cout << " d. SEARCH " << endl;
		cout << " e. EXIT " << endl;
		cout << "\n Choose a letter: ";
		cin >> choice;
		
		if (choice == "a" || choice == "A"){
			if (n < capacity){
					cout << " Enter string: ";
					cin >> key;
					n = add(array, n, key, capacity);
				} else{
					cout << "\n Array is already full." << endl;
				}
				cout << " \nArray of strings: " << endl;
				for(i = 0; i < n; i++){
					cout << " " << array[i] << " ";
				}
				cout << "\n";
			
		} else if (choice == "b" || choice == "B"){
			cout << " Enter string: ";
			cin >> key;
			n = del(array, n, key);
				
			cout << " \nArray of strings: " << endl;
			for(int i = 0; i < n; i++){
				cout << " " << array[i] << " ";
			}
			cout << "\n";
			
		} else if (choice == "c" || choice == "C"){
			cout << " \nArray of strings: " << endl;
			for(int i = 0; i < n; i++){
				cout << " " << array[i] << " ";
			}
			cout << "\n";
			
		} else if (choice == "d" || choice == "D"){
			cout << " Enter strings: ";
				cin >> key;
				int position = search_dup(array, n , key);
				
				cout << " \nArray: " << endl;
				for(int i = 0; i < n; i++){
					cout << " " << array[i] << " ";
				}
				cout << "\n";
			
		} else if (choice == "e" || choice == "E"){
			cout << "\n Exiting the program. " << endl;
			break;
		} else {
			
		}
		 
	} while (choice != "e" || choice != "E");
	
	return 0;
}