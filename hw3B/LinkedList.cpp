#include    "LinkedList.h"
using namespace std;

LinkedList::LinkedList(){
   // cout << "Constructing LinkedList…" << endl;
    current_pointer = NULL;
}

LinkedList::~LinkedList(){
  //  cout << "Deleting LinkedList…" << endl;
}

int LinkedList::getSize() const{
    Node*   site = current_pointer;
    int     cnt = 1;  //the first one
    Node* tmp_current_pointer = current_pointer->next;
    while(tmp_current_pointer != site){
        tmp_current_pointer = tmp_current_pointer->next;
        cnt++;
    }
   // cout << "get the size of linked list. Size is: "  << cnt << endl;
    return cnt;
}

bool LinkedList::isEmpty(){
    if(current_pointer == NULL){
       //cout << "Linked list is empty." << endl;
        return true;
    } 
    else{
       // cout << "Linked list is not empty." << endl;
        return false;
    }
}

void LinkedList::clear(){
    while(current_pointer != NULL){
        Node* tmp = current_pointer;
        current_pointer = current_pointer->next;
        delete current_pointer;
    }
   // cout << "Linked list is cleared." << endl;
}

void LinkedList::deleteCurrentNode(){
    Node* tmp = current_pointer;  //tmp is going to deleted
    Node* last = current_pointer->prev;
    current_pointer = current_pointer->next;
    last->next = current_pointer;
    current_pointer->prev = last;
   // cout << "last_x: " << last->pt.x << "\tlast_y: " << last->pt.y << "curr_x: " << current_pointer->pt.x << "curr.y: " << current_pointer->pt.y << endl;
    delete tmp;
    //cout << "This current node is deleted." << endl;
}

void LinkedList::pointToNext(){
    current_pointer = current_pointer->next;
   // cout << "current pointer points to next." << endl;
}

void LinkedList::pointToPrev(){
    current_pointer = current_pointer->prev;
   // cout << "current pointer points to prev." << endl;
}

Point LinkedList::getCurrentPoint() const{
   // cout << "Get current point_x: " << current_pointer->pt.x  << "\tGet current point_y: " << current_pointer->pt.y << endl;
    return current_pointer->pt;
}

void LinkedList::insertToNext(const Point& pt){
    Node* next_newnode = new Node;

    if(current_pointer == NULL){
       // cout << "cur is null." << endl;
        next_newnode->pt = pt;
       // cout << "pt_x: " << next_newnode->pt.x  << "\tpt_y: " << next_newnode->pt.y << endl;
        next_newnode->prev = next_newnode;
        next_newnode->next = next_newnode;
        current_pointer = next_newnode;
      //  cout << "Insert the first node to prev." << endl;
        return;
    }
        
    Node* next_curr = current_pointer->next;
    next_newnode->pt = pt;
  //  cout << "pt_x: " << next_newnode->pt.x  << "\tpt_y: " << next_newnode->pt.y << endl;
    next_newnode->next = next_curr;
    next_newnode->prev = current_pointer;
    next_curr->prev = next_newnode;
    current_pointer->next = next_newnode;

   // cout << "Insert the node to next." << endl;
}

void LinkedList::insertToPrev(const Point& pt){
    Node* prev_newnode = new Node;

    if(current_pointer == NULL){
      //  cout << "cur is null" << endl;
        prev_newnode->pt = pt;
     //   cout << "pt_x: " << prev_newnode->pt.x  << "\tpt_y: " << prev_newnode->pt.y << endl;
        prev_newnode->prev = prev_newnode;
        prev_newnode->next = prev_newnode;
        current_pointer = prev_newnode;
     //   cout << "Insert the first node to prev." << endl;
        return;
    }
    
    Node* prev_curr = current_pointer->prev;
    prev_newnode->pt = pt;
  //  cout << "pt_x: " << prev_newnode->pt.x  << "\tpt_y: " << prev_newnode->pt.y << endl;
    prev_newnode->next = current_pointer;
    current_pointer->prev = prev_newnode;
    prev_newnode->prev = prev_curr;
    prev_curr->next = prev_newnode;
    
  //  cout << "Insert the node to prev." << endl;
}

void LinkedList::display(){
    Node* tmp = current_pointer;
    cout << "--------------------------display--------------------------" << endl;
    cout << "( " << current_pointer->pt.x << ", " << current_pointer->pt.y << ")" ;
    current_pointer = current_pointer->next;
    while(current_pointer != tmp){
        cout << " <=> ( " << current_pointer->pt.x << ", " << current_pointer->pt.y << ")";
        current_pointer = current_pointer->next;
    }
    cout << endl;
}
