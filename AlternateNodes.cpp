#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}  

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void printl() {
        Node* temp = head;  
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;  
    }

    void alterlist() {

        Node* temp=head;
        Node* subh = temp->next;
        Node* dup = subh;

        while (temp->next != nullptr && dup->next != nullptr) {
            temp->next = dup->next;
            temp = temp->next;
            dup->next = temp->next;
            dup = dup->next;
        }
        temp->next = subh;
    }
};

int main() {
    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);
    list1.insertAtEnd(6);
    list1.insertAtEnd(7);

    list1.printl();

    list1.alterlist();

    list1.printl();

    return 0;
}
