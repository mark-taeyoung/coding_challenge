/**
 * 138. Copy List with Random Pointer
 * */

//  Iterative Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* preHead = new Node(-11111);
        Node* curr = head;
        Node* newCurr = preHead;
        unordered_map<Node*, Node*> originalToCopied;
        
        while (curr) {
            Node* newNode = new Node(curr->val);
            originalToCopied[curr] = newNode;
            newCurr->next = newNode;
            newCurr = newCurr->next;
            curr = curr->next;
        }
        
        Node* newHead = preHead->next;
        delete(preHead);
        newCurr = newHead;
        curr = head;
        
        while (curr) {
            if (curr->random) {
                newCurr->random = originalToCopied[curr->random];
            }
            newCurr = newCurr->next;
            curr = curr->next;
        }
        
        return newHead;
    }
};


//  Recursive Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> originalToCopied;
        return helper(head, originalToCopied);
    }
    
    Node* helper(Node* curr, unordered_map<Node*, Node*>& originalToCopied) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (originalToCopied.find(curr) == originalToCopied.end()) {
            Node* newNode = new Node(curr->val);
            originalToCopied[curr] = newNode;
            newNode->next = helper(curr->next, originalToCopied);
            newNode->random = helper(curr->random, originalToCopied);
        }
    
        return originalToCopied[curr];
    }
};