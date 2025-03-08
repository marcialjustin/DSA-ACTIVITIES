//Insert at the end
Node *insertAtEnd( tring data,
Node *head){
    if(head == NULL){ // if the linked list is empty
        Node *newNode = createNode(data); //create node
        head = newNode; // assign new node as head
        cout << "A new node has been inserted at the end \n"<< endl; // print out message
        return head;
    }
    Node *temp = new Node; //create a temporary node
    temp *head; //assign temporary node as head
    
    while(temp-›link |= NULL){ // traverse until end is found ie. link == NULL
    temp = temp->link;
    }
    Node *newNode = createNode(data); // create new node
    temp-›link = newNode; // link the new node to the last element
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

int main(){
    Node *head = createNode("Santuary by Joji");
    
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    
    
    return 0;
}

//Insert at the beginning
Node *insertAtBeginning(tring data, Node *head){
    Node *newNode = createNode(data); //create new node
    newNode->link = head; //Link the head to the new node newNode-›head

    head = newNode; //set new node as head

    cout << "A new node has been inserted at the beginning \n" <<endl; //Output confirmation

    return head;
 }
 
 //Insert at the after a given node
string insertAfter(String after, string data, Nade *head){
    Node *temp = new Node; // create temporary node
    temp = head; // assign temporary node as head

    while(temp->songName.compare(after) != 0){ // search for the node 
        if(temp == NULL){// if no such node exist, break and return error message
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data); //create new node
    newNode-›link = temp-›link; // assign the link of the new node to the node after the given node 
    temp->link = newNode; //link new node to the given node

    return "An new node has been added after " + after + "\n"; // return confimation message
}

//Delete at the End
string deleteAtEnd(Node *head){
   if(head == NULL){ //check if linked list is empty
   return "The linked list is empty \n";
   }
   
   if(head->link == NULL){ //check if linked list only have one node
        delete head;
        return "The head has been deleted \n";
   }
   
   Node*temp = new Node; //create temporary node
   temp = head; // assign temporary node as head
   
   while(temp->link->link != NULL){ //traverse until the second to the last node is found
        temp = temp->link;
   }
   
   temp->link = NULL; //disconnect the tail to the linked list
   
   return "A node has been deleted at the end \n";
   
}

Node *deleteFromBeginning(Node *head){
   if (head == NULL){
         cout << "The linked list is empty \n" <<endl;
         return NULL;
   }
   
   if(head->link == NULL){
        delete head;
   }
   
   head = head->link;
   
   cout <<"A node has been delete from the beginning \n" << endl;
   
   return head;
}