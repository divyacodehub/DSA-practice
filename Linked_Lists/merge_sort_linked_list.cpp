#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(left != NULL && right != NULL) {
        if(left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if(left != NULL)
        tail->next = left;

    if(right != NULL)
        tail->next = right;

    Node* ans = dummy->next;
    delete dummy;
    return ans;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);

    print(head);

    head = mergeSort(head);

    print(head);

    return 0;
}