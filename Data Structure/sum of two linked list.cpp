Node* addTwoLists(Node* first, Node* second) {
    Node *t1,*t2,*t3;
    Node *head=new Node(0);
    t3=head;
    t1=first;
    t2=second;
    int carry=0;
    while(t1!=NULL && t2!=NULL)
    {
        t3->next=new Node(0);
        t3=t3->next;
        carry=carry+t1->data + t2->data;
        t3->data=carry%10;
        carry=carry/10;t2=t2->next;
        t1=t1->next;
        
    }
    
    while(t1!=NULL)
    {
        t3->next=new Node(0);
        t3=t3->next;
        carry=carry+t1->data;
        t3->data=carry%10;
        carry=carry/10;
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        t3->next=new Node(0);
        t3=t3->next;
        carry=carry+t2->data;
        t3->data=carry%10;
        carry=carry/10;
        t2=t2->next;
    }
    if(carry!=0)
     {
         t3->next=new Node(carry);
     }
    Node *p=head;
    head=head->next;
    delete p;
    return head;
}