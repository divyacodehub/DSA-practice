class Solution {
public:

    // LeetCode submission code only
    // Node class and main() provided by platform
    
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        Node* curr = head;

        while(curr != NULL) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        curr = head;

        while(curr != NULL) {
            if(curr->random != NULL)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        Node* original = head;
        Node* copy = head->next;
        Node* copyHead = head->next;

        while(original != NULL && copy != NULL) {
            original->next = copy->next;
            original = original->next;

            if(original != NULL) {
                copy->next = original->next;
                copy = copy->next;
            }
        }

        return copyHead;
    }
};