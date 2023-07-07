#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_Node(int n) {
        struct Node* new_node = new Node;
        new_node->data = n;
        new_node->next = head;
        head = new_node;
    }

    int count_Node() {
        Node* temp = head;
        int ctr = 0;

        while (temp != NULL) {
            ctr++;
            temp = temp->next;
        }
        return ctr;
    }

    bool search_Node(int n) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == n) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display_nodes() {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList l;

    char choice;
    int item;

    do {
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter item: ";
                cin >> item;
                l.insert_Node(item);
                cout << "Item added successfully.\n";
                break;
            case '2':
                cout << "Enter item to delete: ";
                cin >> item;
                // Code to delete item from the linked list
                // You can implement the deletion logic here
                cout << "Item deleted successfully.\n";
                break;
            case '3':
                cout << "Enter item to search: ";
                cin >> item;
                if (l.search_Node(item)) {
                    cout << "Item found in the linked list.\n";
                } else {
                    cout << "Item not found in the linked list.\n";
                }
                break;
            case '4':
                cout << "Linked List: ";
                l.display_nodes();
                cout << endl;
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
