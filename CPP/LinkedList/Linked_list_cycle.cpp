#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int val) : data(val), next(nullptr) {} // explicit constructor
};

// Function to check if linked list contains a cycle
bool hasCycle(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // cycle detected
            return true;
        }
    }

    return false; // no cycle
}

Node* starting_of_cycle(Node* head){//returns the pointer at the starting of the linked list cycle(ASSUMING THAT THE CYCLE DOES EXIST)
    if(head == nullptr || head->next == nullptr){
        return head ;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head ;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow ;
}

int main() {
    // Linked list 1 (with cycle)
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = two; // cycle here

    cout << "Linked list 1:" << endl;
    cout << "Result: " << (hasCycle(one) ? "Cycle detected" : "No cycle detected") << endl;

    // Linked list 2 (no cycle)
    Node* ten = new Node(10);
    Node* twenty = new Node(20);
    Node* thirty = new Node(30);

    ten->next = twenty;
    twenty->next = thirty;

    cout << "\nLinked list 2:" << endl;
    cout << "Result: " << (hasCycle(ten) ? "Cycle detected" : "No cycle detected") << endl;

    // Optional: free memory for non-cyclic list
    delete thirty;
    delete twenty;
    delete ten;

    return 0;
}
