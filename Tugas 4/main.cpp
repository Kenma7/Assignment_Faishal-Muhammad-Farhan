#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(int data) {
        if (head == nullptr) {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node;
            temp->next->data = data;
            temp->next->next = nullptr;
        }
    }

    void reverse() {
        stack<Node*> s;
        Node* temp = head;
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->next;
        }
        head = s.top();
        temp = head;
        s.pop();
        while (!s.empty()) {
            temp->next = s.top();
            s.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << ",";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    for (int i = 1; i <= 10; ++i) {
        list.addNode(i);
    }

    cout << "\nOutput Data\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Original list: ";
    list.display();

    list.reverse();

    cout << "Reversed list: ";
    list.display();

    cout << "===================================================================\n";
    cout << "Program ini dibuat oleh : Faishal Muhammad Farhan (2310631170135) \n";
    cout << "===================================================================\n";
    return 0;
}

