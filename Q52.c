/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 */
typedef struct node {
    struct node* prev;
    int val;
    struct node* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->val  = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

static int listLength(MyLinkedList* obj) {
    int count = 0;
    MyLinkedList* temp = obj->next;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= listLength(obj)) return -1;

    MyLinkedList* temp = obj->next;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newnode->val  = val;
    newnode->next = obj->next;
    newnode->prev = obj;

    if (obj->next != NULL)
        obj->next->prev = newnode;

    obj->next = newnode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* temp = obj;
    while (temp->next != NULL)
        temp = temp->next;

    MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newnode->val  = val;
    newnode->next = NULL;
    newnode->prev = temp;
    temp->next    = newnode;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int len = listLength(obj);
    if (index > len) return;
    if (index <= 0) { myLinkedListAddAtHead(obj, val); return; }
    if (index == len) { myLinkedListAddAtTail(obj, val); return; }

    MyLinkedList* temp = obj->next;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    MyLinkedList* newnode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newnode->val  = val;
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev       = newnode;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int len = listLength(obj);
    if (index < 0 || index >= len) return;

    MyLinkedList* temp = obj->next;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* temp = obj;
    while (temp != NULL) {
        MyLinkedList* next = temp->next;
        free(temp);
        temp = next;
    }
}