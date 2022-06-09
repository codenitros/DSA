// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1


Node* meregTwo(Node* a, Node* b){
    Node* newHead = new Node(0);
    Node* res = newHead;
    
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            newHead->bottom = a;
            a=a->bottom;
        }else{
            newHead->bottom = b;
            b=b->bottom;
        }
        newHead=newHead->bottom;
    }
    
    if(!a)newHead->bottom=b;
    else newHead->bottom=a;
    return res->bottom;
}


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(!root || !root->next)return root;
    
    root->next = flatten(root->next);
    
    root = meregTwo(root, root->next);
    
    return root;
    
}

