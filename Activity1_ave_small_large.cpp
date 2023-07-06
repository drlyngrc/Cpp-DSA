//Create a program that have the ff. output:

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int integers = 0;
	int sum = 0;
	int largest = INT_MIN;
	int smallest = INT_MAX;
	char letter;

	do{
		cout << " MAIN" << endl;
		cout << " a. Average" << endl;
		cout << " b. Largest" << endl;
		cout << " c. Smallest" << endl;
		cout << " d. Exit" << endl;
		cout << " Choose letter: ";
		cin >> letter;
	
		if (letter == 'a'){
			cout << " Enter 10 integers: " << endl;
			for (int i = 0; i < 10; ++i){
				cout << " " << i + 1 << ": ";
				int num;
				cin >> num;
				sum += num;
				++integers;
			}
			double average = static_cast<double>(sum) /integers;
			cout << " Average: " << average << endl;
			system("pause");
			system("cls");
		} else if (letter == 'b'){
			largest = INT_MIN;       
			cout << " Enter 10 integers: " << endl;
			for (int i = 0; i < 10; ++i){
				cout << " " << i + 1 << ": ";
				int num;
				cin >> num;
			
				if (num > largest){
					largest = num;
				}
			}
			cout << " Largest: " << largest << endl;
			system("pause");
			system("cls");
		} else if (letter == 'c'){
			smallest = INT_MAX;
			cout << " Enter 10 integers: " << endl;
			for (int i = 0; i < 10; ++i){
				cout << " " << i + 1 << ": ";
				int num;
				cin >> num;
			
				if (num < smallest){
					smallest = num;
				}
			}
			cout << " Smallest: " << smallest << endl;
			cout << " Thankyou!" << endl;
			cout << " System exiting." << endl;
			exit[0];
			system("pause");
			system("cls");
		} else if (letter == 'd'){
		} else{
			cout << " Invalid! Please try again.";
			system("pause");
			system("cls");
		}	
	} while (letter != 'd');
	return 0;
}

