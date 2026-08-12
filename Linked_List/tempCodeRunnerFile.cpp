Node*DeleteKthNode(int k) {

        Node*prev = NULL;
        Node*curr = head;

        int count = 1;
        while(curr!=NULL) {
            if(count==k) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                count = 1;
            }
            else{
                prev = curr;
                curr = curr->next;
                count++;
            }
        }

        return head;
    }