// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node{
    int data;
     Node* next;
};

 void creation(Node **head,int data){
    Node *newnode = new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;

    
}
void PRINTINGREVERSE(Node * head){
     Node * temp = head;
    while(temp!=NULL){
        
        cout<<temp->data<<" ";
        temp=temp->next;
    
}

}

    Node* MergeSortedList(Node* lst1, Node* lst2) 
{ 
	Node* result = NULL; 

	// Base Cases
	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 

	// recursively merging two lists
	if (lst1->data <= lst2->data) { 
		result = lst1; 
		result->next = MergeSortedList(lst1->next, lst2); 
	} 
	else { 
		result = lst2; 
		result->next = MergeSortedList(lst1, lst2->next); 
	} 
	return result; 
} 

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void SplitList(Node* source, Node** front, Node** back) 
{ 
	Node* ptr1; 
	Node* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 

	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 

	// ptr2 is at the midpoint.
	*front = source; 
	*back = ptr2->next; 
	ptr2->next = NULL; 
} 


// Merge Sort
void MergeSort(Node** thead) 
{ 
	Node* head = *thead; 
	Node* ptr1; 
	Node* ptr2; 

  // Base Case
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	// Splitting list
	SplitList(head, &ptr1, &ptr2); 

	// Recursively sorting two lists.
	MergeSort(&ptr1); 
	MergeSort(&ptr2); 

	// Sorted List.
	*thead = MergeSortedList(ptr1, ptr2); 
} 


int main() {
    Node* head = NULL;

   int a[] = {213,21,3,3142,8,344,464,2,23,56};

for(auto i:a)
creation(&head,i);

//PRINTING ORIGINAL LL  " LL = lINKED LIST"
cout<<"Original Linked List \n";
PRINTINGREVERSE(head);
MergeSort(&head);
cout<<"\nsorted\n";
PRINTINGREVERSE(head);

    return 0;
}
