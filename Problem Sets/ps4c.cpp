// write your matric number here: A0174217H
// write your name here: teo chuan kai
// write list of collaborators here: -
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    string value;
    int height = 0;
    //number of nodes under the current one
    //used in calculation of rank of current node
    int size = 0;
};

class BST {
    private:
        Node* root;
        int size;
        
        int height(Node* n) { return n == NULL ? -1 : n->height;}
        string printNode(Node* n) { return n == NULL ? "" : n->value;}
        int getSize(Node* n) { return n == NULL ? 0 : n->size;}

        void inOrder(Node* n) {
            if (n == NULL) {
                return;
            }
            inOrder(n->left);
            cout << rank(n, n->value) << ":" << n->value << " ";
            inOrder(n->right);
        }

        Node* rotateLeft(Node* temp) {
            Node* x = temp->right;
            x->parent = temp->parent;
            temp->parent = x;
            temp->right = x->left;
            if(x->left != NULL) x->left->parent = temp;
            x->left = temp;

            temp->height = max(height(temp->left), height(temp->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

            temp->size = getSize(temp->left) + getSize(temp->right) + 1;
            x->size = temp->size + getSize(temp->right) + 1;
            return x;
        }

        Node* rotateRight(Node* temp) {
            Node* x = temp->left;
            x->parent = temp->parent;
            temp->parent = x;
            temp->left = x->right;
            if(x->right != NULL) x->right->parent = temp;
            x->right = temp;

            temp->height = max(height(temp->left), height(temp->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

            temp->size = getSize(temp->left) + getSize(temp->right) + 1;
            x->size = temp->size + getSize(temp->left) + 1;
            return x;
        }

        Node* getMin(Node* n) {
            if(n == NULL) { return NULL;} 
            else if(n->left == NULL) { return n;} 
            else { return getMin(n->left);}
        }

        Node* getMax(Node* n) {
            if(n == NULL) { return NULL;} 
            else if(n->right == NULL) { return n;} 
            else { return getMax(n->right);}
        }

        Node* search(Node* n, string value) {
            if(n == NULL) { return n;} 
            else if(n->value == value) { return n;} 
            else if(n->value < value) { return search(n->right, value);} 
            else { return search(n->left, value);}
        }

        Node* successorNode(Node* n) {
            if(n == NULL) { return NULL;} 
            else if(n->right != NULL) { return getMin(n->right);}
            else {
                Node* par = n->parent;
                Node* cur = n;
                while((par != NULL) && (par->right == cur)) {
                    cur = par;
                    par = cur->parent;
                }
                return par;
            }
        }
        string successor(Node* n) { return printNode(successorNode(n)); }

        Node* predecessorNode(Node* n) {
            if(n == NULL) { return NULL;}
            else if(n->left != NULL) { return getMax(n->left);}
            else {
                Node* par = n->parent;
                Node* cur = n;
                while((par != NULL) && (par->left == cur)) {
                    cur = par;
                    par = cur->parent;
                }
                return par;
            }
        }
        string predecessor(Node* n) { return printNode(predecessorNode(n)); }

        Node* insert(Node* t, string value) {
            //find point of insertion
            if(t == NULL) {
                t = new Node;
                t->value = value;
                t->parent = t->left = t->right = NULL;
                //t->height = 0;
                //t->size = 0;
            } else if(t->value < value) {
                //value to be inserted > value at current node, go right
                t->right = insert(t->right, value);
                t->right->parent = t;
            } else {
                t->left = insert(t->left, value);
                t->left->parent = t;
            }

            //check height of subtrees & balance & rotate
            int bal = height(t->left) - height(t->right);
            if(bal == 2) {
                //left heavy
                int bal2 = height(t->left->left) - height(t->left->right);
                if(bal2 == 1) {
                    t = rotateRight(t);
                } else {
                    //bal2 == -1
                    t->left = rotateLeft(t->left);
                    t = rotateRight(t);
                }
            } else if(bal == -2) {
                //right heavy
                int bal2 = height(t->right->left) - height(t->right->right);
                if(bal2 == -1) {
                    t = rotateLeft(t);
                } else {
                    //bal2 == 1
                    t->right = rotateRight(t->right);
                    t = rotateLeft(t);
                }
            }

            //recalculate height
            t->height = max(height(t->left), height(t->right)) + 1;
            //recalculate size
            t->size = getSize(t->left) + getSize(t->right) + 1;
            //return updated avl
            return t;
        }

        Node* remove(Node* t, string value) {
            //cannot find item to be deleted
            if(t == NULL) return t;

            //find node to be deleted
            if(t->value == value) {
                //leaf node
                if(t->left == NULL && t->right == NULL) {
                    //delete t;
                    t = NULL; 
                }
                //one right child
                else if(t->left == NULL && t->right != NULL) {
                    Node* temp = t;
                    t->right->parent = t->parent;
                    t = t->right;
                    //delete temp;
                    temp = NULL;
                }
                //one left child
                else if(t->left != NULL && t->right == NULL) {
                    Node* temp = t;
                    t->left->parent = t->parent;
                    t = t->left;
                    //delete temp;
                    temp = NULL;
                }
                //two children, find successor and remove it
                else {
                    string sucVal = successorNode(t)->value;
                    t->value = sucVal;
                    t->right = remove(t->right, sucVal);
                }
            }
            //go right
            else if(t->value < value) { 
                t->right = remove(t->right, value);
            }
            //go left
            else {
                t->left = remove(t->left, value);
            }

            //check height of subtrees & balance & rotate
            if(t != NULL) {
                int bal = height(t->left) - height(t->right);
                if(bal == 2) {
                    //left heavy
                    int bal2 = height(t->left->left) - height(t->left->right);
                    if(bal2 == 1) {
                        t = rotateRight(t);
                    } else {
                        t->left = rotateLeft(t->left);
                        t = rotateRight(t);
                    }
                } else if(bal == -2) {
                    //right heavy
                    int bal2 = height(t->right->left) - height(t->right->right);
                    if(bal2 == -1) {
                        t = rotateLeft(t);
                    } else {
                        t->right = rotateRight(t->right);
                        t = rotateLeft(t);
                    }
                }
                //recalculate height
                t->height = max(height(t->left), height(t->right)) + 1;
                //recalculate size
                t->size = getSize(t->left) + getSize(t->right) + 1;
            }
            //return updated avl
            return t;
        }

        //find the position of the node, where the node will be the kth element
        int rank(Node* n, string value) {
            //if only node
            if(n == NULL) { return 1;}
            //if current node == value, count all lesser than current (all to the left) 
            //add current node (+1)
            else if(n->value == value) { return (getSize(n->left) + 1);}
            //if current node < value, count all lesser than current (all to the left)
            //add current node (+1)
            //recursively call method until matching node is found
            else if(n->value < value) { return (getSize(n->left) + 1 + rank(n->right, value));}
            //if current node > value, consider all lesser than current node (all to left, same level)
            //recursively call method method until relevant is found
            else { return rank(n->left, value);}
        }

    public:
        BST() {
            root = NULL;
            size = 0;
        }

        void insertValue(string value) {
            root = insert(root, value);
            size++;
        }

        void removeValue(string value) {
            root = remove(root, value);
            size--;
        }

        int distance(string START, string END) {
            return (rank(root, END) - rank(root, START));
        }

        void inorder() {
            inOrder(root);
            cout << endl;
        }

};

int query(string START, string END, int gender, BST &maleNames, BST &femaleNames) {
    int ans = 0;
    if(gender == 0) {
        ans += maleNames.distance(START, END);
        ans += femaleNames.distance(START, END);
    } else if (gender == 1) {
        ans += maleNames.distance(START, END);
    } else if (gender == 2) {
        ans += femaleNames.distance(START, END);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int cmd, genderSuitability;
    string babyName, START, END;
    BST maleNames;
    BST femaleNames;
    while(true) {
        cin >> cmd;
        if(cmd == 0) {
            break;
        } else if(cmd == 1) {
            cin >> babyName >> genderSuitability;
            switch(genderSuitability) {
                case 1:
                    maleNames.insertValue(babyName);
                    break;
                case 2:
                    femaleNames.insertValue(babyName);
                    break;
                default:
                    break;
            }
        } else if(cmd == 2) {
            cin >> babyName;
            maleNames.removeValue(babyName);
            femaleNames.removeValue(babyName);
        } else if(cmd == 3) {
            cin >> START >> END >> genderSuitability;
            cout << query(START, END, genderSuitability, maleNames, femaleNames) << endl;
        } else if(cmd == 4) {
            cout << "male: ";
            maleNames.inorder();
            cout << "female: ";
            femaleNames.inorder();
        }
    }
    return 0;
}