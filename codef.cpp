#include <iostream>
#include <math.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int value) {
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

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    int getMax() {
        int maxVal = 0;
        Node* temp = head;
        while (temp) {
            maxVal = max(maxVal, temp->data);
            temp = temp->next;
        }
        return maxVal;
    }

    void radixSort() {
        int maxVal = getMax();
        int numDigits = 0;
        while (maxVal > 0) {
            maxVal /= 10;
            numDigits++;
        }

        for (int digit = 1; digit <= numDigits; digit++) {
            LinkedList bins[10];

            Node* curNode = head;
            while (curNode) {
                int digitVal = (curNode->data / (int)pow(10, digit - 1)) % 10;
                bins[digitVal].append(curNode->data);
                curNode = curNode->next;
            }

            head = nullptr;
            for (int i = 0; i < 10; i++) {
                Node* binNode = bins[i].head;
                while (binNode) {
                    append(binNode->data);
                    binNode = binNode->next;
                }
            }
        }
    }
};

int main() {
    LinkedList ll;
    ll.append(170);
    ll.append(45);
    ll.append(75);
    ll.append(90);
    ll.append(802);
    ll.append(24);
    ll.append(2);
    ll.append(66);

    cout << "Before sorting:" << endl;
    ll.printList();
    ll.radixSort();
    cout << "\nAfter sorting:" << endl;
    ll.printList();

    return 0;
}




