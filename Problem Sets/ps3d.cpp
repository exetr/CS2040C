#include <bits/stdc++.h>
using namespace std;

const int PQMAXSIZE = 1000000;
const int UMMAXSIZE = 600000;

struct Patient {
    int dilation;
    int position;
    string name;
};

/* 
Pri0rityQu3u3 Implementation
 */
class PQ {
    private:
        Patient *maxh34p;
        //Patient maxh34p[PQMAXSIZE];
        int maxsize;
        int size;
    
    public:
        PQ() {
            size = 0;
            maxsize = PQMAXSIZE;
            maxh34p = new Patient[maxsize];
        }

        void swap(Patient *x, Patient *y) {
            Patient temp = *x;
            *x = *y;
            *y = temp;
        }

        int parent(int i) { return (i-1)/2;}
        int left(int i) { return (2*i + 1);}
        int right(int i) { return (2*i + 2);}
        bool empty() { return size==0;}
        Patient top() { return maxh34p[0];}

        void push(Patient p) {
            //check if array is at capacity
            if(size < maxsize) {
                //insert new object at end of array
                size++;
                int i = size-1;
                maxh34p[i] = p;            
                //bubble up if child > parent
                bool sorted = false;
                while(i != 0 && sorted == false) {
                    if (maxh34p[i].dilation > maxh34p[parent(i)].dilation) {
                        swap(&maxh34p[i], &maxh34p[parent(i)]);
                        i = parent(i);
                    } else if (maxh34p[i].dilation == maxh34p[parent(i)].dilation) {
                        if(maxh34p[i].position < maxh34p[parent(i)].position) {
                            swap(&maxh34p[i], &maxh34p[parent(i)]);
                            i = parent(i);
                        } else {
                            //maxh34p[i].position > maxh34p[parent(i)].position
                            //this variable will never be equal
                            //child is of lesser priority than parent
                            sorted = true;
                        }
                    } else {
                        //maxh34p[i].dilation < maxh34p[parent(i)].dilation
                        //child is of lesser priority than parent
                        sorted = true;
                    }
                }
            } else { cout << "die: array overcapacity" << endl;}   
        }

        void h34pify(int root) {
            //get left child of root
            int child = left(root);
            //if there is a left child
            if(child < size) {
                //get right child
                int Rchild = right(root);
                //if there is right child
                if(Rchild < size) {
                    //check if right child has higher priority
                    if(maxh34p[Rchild].dilation > maxh34p[child].dilation) {
                        //if right child has larger dilation (higher priority), choose right
                        child = Rchild;
                    } else if(maxh34p[Rchild].dilation == maxh34p[child].dilation) {
                        //if dilation is equal
                        if(maxh34p[Rchild].position < maxh34p[child].position) {
                            //if right child has smaller position (higher priority), choose right
                            child = Rchild;
                        }
                    }
                }

                //check if root is smaller than l/r child
                if(maxh34p[root].dilation < maxh34p[child].dilation) {
                    //if child has larger dilation (higher priority), swap
                    swap(&maxh34p[root], &maxh34p[child]);
                    h34pify(child);
                } else if(maxh34p[root].dilation == maxh34p[child].dilation) {
                    //if dilation is equal
                    if(maxh34p[root].position > maxh34p[child].position) {
                        //if child has smaller position (higher priority), swap
                        swap(&maxh34p[root], &maxh34p[child]);
                        h34pify(child);
                    }
                }
            }
        }

        void pop() {
            if(!empty()) {
                maxh34p[0] = maxh34p[size];
                size--;
                h34pify(0);
            }
        } 
};

/* 
Un0rd3r3dM4p Implementation
 */
struct Node {
    string key;
    int dilation;
    int position;
    Node* next;
    Node* prev;
};

//hashing algorithm for key
int hashstring(string name) {
    int result = 0;
    for(auto &c : name) {
        result = ((result*26)% UMMAXSIZE + (c-'A'+1)) % UMMAXSIZE;
    }
    return result;
}

//Doubly linked li5t for each index in hash array
class DLL {
    private:
        Node* head;
        Node* tail;
        int size;
    
    public:
        DLL() {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        Node* find(string k) {
            Node* curr = head;
            Node* result = NULL;
            for(int i = 0; i<size; i++) {
                if(curr->key == k) {
                    result = curr;
                    break;
                } else {
                    curr = curr->next;
                }
            }
            return result;
        }

        //insert node at end of DLL
        void push_back(string k, int dilation, int position) {
            //determine properties
            Node * working = new Node();
            working->key = k;
            working->dilation = dilation;
            working->position = position;
            //pointer stuff
            working->next = NULL;
            working->prev = tail;
            if(tail != NULL) {
                tail->next = working;
            }
            tail = working;
            if(head == NULL) {
                head = working;
            }
            size++;
        }

        void remove(string k) {
            Node* working = find(k);
            if(working != NULL) {
                Node* before = working->prev;
                Node* after = working->next;
                //case 1: if last node in DLL
                if((before==NULL) && (after==NULL)) {
                    head = NULL;
                    tail = NULL;
                }
                //case 2: if node to be deleted is at front of DLL
                else if((before==NULL) && (after!=NULL)) {
                    after->prev = NULL;
                    head = after;
                }
                //case 3: if node to be deleted is at end of DLL
                else if((before!=NULL) && (after==NULL)) {
                    before->next = NULL;
                    tail = before;
                }
                //case 4: if node to be deleted is in middle of DLL
                else {
                    before->next = after;
                    after->prev = before;
                }
                //delete node
                delete working;
                size--;
            }
        }
};

class UM {
    private:
        DLL *arr;
        int size;
        //hash<string> hashfunc;

    public:
        UM() {
            arr = new DLL[UMMAXSIZE];
            size = 0;
        }

        Node* getNode(string key) {
            return (arr[hashstring(key)]).find(key);
        }

        bool empty() {
            return size==0;
        }

        void insert(string name, int dilation, int position) {
            (arr[hashstring(name)]).push_back(name, dilation, position);
            size++;
        }

        Node* update(string key, int value) {
            Node* working = getNode(key);
            if(working != NULL) {
                working->dilation += value;
            }
            return working;
        }

        void erase(string key) {
            (arr[hashstring(key)]).remove(key);
            size--;
        }

        bool check(string name, int dilation) {
            Node* working = getNode(name);
            bool result = false;
            if(working != NULL) {
                if(working->dilation == dilation) {
                    result = true;
                }
            }
            return result;
        }
};

class Hospital {
    private:
        PQ q;
        UM m;
        int position;

    public:
        Hospital() {
            position = 1;
        }

        void arriveAtHospital(string name, int dilation) {
            //insert into pq
            q.push({dilation, position, name});
            //insert into um
            m.insert(name, dilation, position);
            position++;
        }

        void updateDilation(string name, int incDilation) {
            //update value inside matching node
            Node* working = m.update(name, incDilation);
            //push new entry into pq
            /* int newDilation = m.getDilation(name);
            int newPosition = m.getPosition(name); */
            q.push({working->dilation, working->position, name});
        }

        void giveBirth(string name) { 
            //delete entry in um
            m.erase(name);
            //patient may still exist in pq
        }

        string query() {
            if(m.empty()) {
                return "The delivery suite is empty";
            } else {
                //if patient at top of q matches entry in p,
                //patient is valid and information is up to date,
                //else, information is out of data and pop from q
                Patient p = q.top();
                bool valid = m.check(p.name, p.dilation);
                while(valid == false) {
                    q.pop();
                    p = q.top();
                    valid = m.check(p.name, p.dilation);
                }
                return p.name;
            }
        }
};

int main() {
    //speed stuff
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //DEBUG
    //freopen("in.txt", "r", stdin);
    //auto start = std::chrono::system_clock::now();
    //END DEBUG

    Hospital h;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int cmd, dilation;
        string name;
        cin >> cmd;
        switch(cmd) {
            case 0:
                cin >> name >> dilation;
                h.arriveAtHospital(name,dilation);
                break;
            case 1:
                cin >> name >> dilation;
                h.updateDilation(name, dilation);
                break;
            case 2:
                cin >> name;
                h.giveBirth(name);
                break;
            case 3:
                cout << h.query() << endl;
                break;
        }
    }
    cout << "By submitting this source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the code that I wrote and can prove it to Lab TA if asked." << endl;
    
    //DEUBG
    //auto end = std::chrono::system_clock::now();
    //cout << "Time = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;
    //END DEUBG

    return 0;
}