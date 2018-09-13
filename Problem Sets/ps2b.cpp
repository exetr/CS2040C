#include <bits/stdc++.h>
using namespace std;

class LinkedList {
    struct Node {
        char c;
        Node* next;
    };

    public:
        Node* head;

        //constructor
        LinkedList() {
            head = NULL;
        }

        void insertNode(int pos, char c) {
            //insert data into new temp node
            Node* temp = new Node();
            temp->c = c;
            temp->next = NULL;
            

            //if linked list is empty
            if ((head == NULL) && (pos == 0)) {
                head = temp;
            }
            //else if insert at start of linked list
            else if (pos == 0) {
                temp->next = head;
                //head->next = temp;
                head = temp;
            } else {
                int i = 1;
                Node* prev = head;

                //loop to desired node before point of insertion
                while ((prev->next != NULL) && (i != pos)) {
                    prev = prev->next;
                    i++;
                }
                if (i == pos) {
                    Node* current = prev->next;
                    prev->next = temp;
                    temp->next = current;
                } else {
                    prev->next=temp;
                }
            }
        }

        void deleteFirst() {
            Node* temp = new Node();
            temp = head;
            head = head->next;
            delete temp;
        }

        void deleteLast() {
            Node* current = new Node();
            Node* prev = new Node();
            current = head;
            while (current->next != NULL) {
                prev = current;
                current = current->next;
            }
            prev->next = NULL;
            delete current;
        }

        void deleteNode(int x) {
            Node* current = new Node();
            Node* prev = new Node();
            current = head;
            for (int i=0; i<x-1; i++) {
                prev=current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
        }

        void printList() {
            if (head==NULL) {
                cout << "linked list is empty" << endl;
            } else {
                Node* current = head;
                while(current!=NULL) {
                    cout << current->c;
                    current = current->next;
                }
                cout << endl;
            }
        }
};

int main() {
    /* LinkedList* text = new LinkedList();
    text->insertNode(0, 'a');
    text->insertNode(0, 'b');
    text->insertNode(2, 'c');
    text->insertNode(3, 'd');
    text->insertNode(4, 'e');
    text->printList(); */

    unsigned int tc;
    cin >> tc;
    cin.ignore(100, '\n');

    for (int i=0; i<tc; i++) {
        char c;
        int curPos = 0;
        int endPos = 0;
        LinkedList* output = new LinkedList();

        for (c=getchar(); c != '\n';) {
            if (c == '<') {
                if (curPos == 0) {
                    ; //do nothing
                } else {
                    if ((curPos-1) == 0 ) {
                        output->deleteFirst();
                    } else if (curPos == endPos) {
                        output->deleteLast();
                    } else {
                        output->deleteNode(curPos);
                    }

                    curPos--;
                    endPos--;
                }
            } else if (c == '[') {
                curPos = 0;
            } else if (c == ']') {
                curPos = endPos;
            } else {
                //cout << curPos << endl;
                output->insertNode(curPos, c);
                curPos++;
                endPos++;
            }
            c = getchar();
        }

        output->printList();
    }

    return 0;
}