#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    struct Node {
        char c;
        Node* next;
        Node* prev;
    };

    public:
        Node* head;
        Node* tail;
        Node* active;
        int size;

        LinkedList() {
            head = NULL;
            tail = NULL;
            active = NULL;
            size = 0;

            Node* dummy = new Node();
            dummy->c = '~';
            dummy->next = NULL;
            dummy->prev = NULL;
            head = dummy;
            tail = dummy;
            active = dummy;
        }

        void operation(char c) {
            if (c == '<') {
                if (size == 0 | active->c == '~') {
                    //do nothing
                } else {
                    deleteNode();
                }
            } else if (c == '[') {
                active = head;
            } else if (c == ']') {
                active = tail;
            } else {
                insertNode(c);
            }
        }

        //insert after 'active' pointer
        void insertNode(char c) {
            Node* working = new Node();
            working->c = c;
            working->prev = active;
            if (active->next == NULL) {
                //insert at the back
                working->next = NULL;
                active->next = working;
                tail = working;
                active = working;
            } else {
                //insert between dummy head and tail node
                Node* before = active;
                Node* after = active->next;
                working->next = after;
                after->prev = working;
                before->next = working;
                working->prev = before;
                active = working;
            }
            size++;
        }

        void deleteNode() {
            Node* current = active;
            if (active->next == NULL) {
                //delete node at end of list
                Node* before = active->prev;
                before->next = NULL;
                tail = before;
                active = before;
                delete current;
            } else {
                //delete node between dummy head and tail node
                current->prev->next = current->next;
                current->next->prev = current->prev;
                active = current->prev;
                delete current;
            }
            size--;
        }

        void printList() {
            if (head == NULL) {
                //cout << "linked list is empty" << endl;
            } else {
                Node* current = head;
                current = current->next;
                while(current != NULL) {
                    cout << current-> c;
                    current = current->next;
                }
                cout << endl;
            }
        }

};

int main() {
    unsigned int tc;
    cin >> tc;
    cin.ignore(100, '\n');

    for (int i=0; i<tc; i++) {
        char c;
        LinkedList* output = new LinkedList();

        for(c=getchar(); c != '\n';) {
            output->operation(c);
            c = getchar();
        }
        output->printList();
    }
    cout << "By submitting this source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the code that I wrote and can prove it to Lab TA if asked." << endl;
}