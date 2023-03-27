/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node *solve(Node<int> *first, Node<int> *second){
      // if only one node is present in the linked list
      if (first -> next == NULL){
          first -> next = second;
          return first;
      }
    
    Node<int> *curr1 = first;
    Node<int> *next1 = first -> next;
    Node<int> *curr2 = second;
    Node<int> *next2 = second -> next;
    
    while (next1 != NULL && curr2 != NULL){
        if ((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
           else {
               curr1 = curr1 -> next;
               next1 = next1 -> next;
               
               if (next1 == NULL){
                  curr1 -> next = curr2;
                  return first;
               }
           }
    }
       return first;
}

Node<int>* sortedMerge(Node<int>* head1, Node<int>* head2)  
{  
   if (head1 == NULL)
       return head2;
       
       if (head2 == NULL)
          return head1;
          
          if (head1 -> data <= head2 -> data)
             return solve(head1,head2);
              
              else 
             return solve(head2,head1);
}  
