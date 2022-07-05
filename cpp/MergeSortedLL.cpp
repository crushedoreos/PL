#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int a) {
            val = a;
            next = NULL;
        }
};


void insertNode(ListNode *&head, int val)
{	
    ListNode* newNode = new ListNode(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
	
}


void Print(ListNode *head)
{

cout<<"\nPrinting "<<endl;
 while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;

    }
return;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
   if(l1==NULL)
     return l2;
  if(l2==NULL)
    return l1;

 if(l1->val > l2->val)
  {
    swap(l1,l2);
   }

ListNode *res = l1;

while(l1!=NULL && l2!=NULL)
{
  ListNode *temp = NULL;

	   while(l1!=NULL && l2!=NULL && l1->val<=l2->val)
   	   {
		temp = l1;
		l1 = l1->next;
	    }

	temp->next = l2;
	swap(l1,l2);
}

return res;
}

int main()
{
ListNode *head1 = NULL;
ListNode *head2 = NULL;
insertNode(head1,3);
insertNode(head1,4);
insertNode(head1,8);
insertNode(head1,10);
Print(head1);
insertNode(head2,5);
insertNode(head2,7);
insertNode(head2,9);
Print(head2);
ListNode *head = NULL;
head = merge(head1, head2);

Print(head);

return 0;

}
