//c++ program to check whether a linked list is palindrome or not

#include <iostream>
using namespace std;

// Defining singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//Function to check if linked list is palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    //Step 1: Find middle using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Step 2: Reverse the second half
    slow->next = reverseList(slow->next);
    ListNode* secondHalf = slow->next;
    ListNode* firstHalf = head;

    //Step 3: Compare both halves
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

//insert a node at the end
void appendNode(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = new ListNode(val);
}

// Main function to test
int main() {
    ListNode* head = NULL;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 2);
    appendNode(head, 1);

    if (isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
