// C++ Program to check if a Linked list contains a cycle

#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

bool hasCycle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* head1 = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = two;
    cout<<"Linked list 1:"<<endl;
    if(hasCycle(head1)){
        cout<<"Result: Cycle detected"<<endl;
    }else{
        cout<<"Result: No cycle detected."<<endl;
    }
    cout<<endl;
    Node* ten = new Node(10);
    Node* twenty = new Node(20);
    Node* thirty = new Node(30);
    Node* head2 = ten;
    ten->next = twenty;
    twenty->next = thirty;
    cout<<"Linked list 2:"<<endl;
    if(hasCycle(head2)){
        cout<<"Result: Cycle detected"<<endl;
    }else{
        cout<<"Result: No cycle detected."<<endl;
    }
    return 0;
}