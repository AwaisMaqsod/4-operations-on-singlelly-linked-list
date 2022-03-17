#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
			
};
class link_list{
	Node*head;
	public:
	link_list(){
		head=NULL;
	}
	bool Is_empty(){
		return head=NULL;
	}
	Node* Insert_node(int index,int x);
	int find_node(int x);
	int delete_node(int x);
	void display();
		
};
int link_list::delete_node(int x) {
Node* prev_Node	=	NULL;
	Node* current_Node	=	head;
	int current_Index	=	1;
	while (current_Node && current_Node->data != x) {
		prev_Node	=	current_Node;
		current_Node	=	current_Node->next;
		current_Index++;
	}
	if (current_Node) {
		if (prev_Node) {
			prev_Node->next	=	current_Node->next;
			delete current_Node;
		}
		else {
			head		=	current_Node->next;
			delete current_Node;
		}
		return current_Index;
	}
	return 0;
}
int link_list::find_node(int x){
	Node* current_Node=head;
	int current_index	=1;
	while(current_Node && current_Node->data!=x){
		current_Node=current_Node->next;
		current_index++;
	}
	if(current_Node){
		return current_index;
		return 0;
	}
	
}
void link_list::display(){
	int num=0;
	Node*current_Node=head;
	while(current_Node!=NULL          ){//condition of while loop --> if current node is not equal to NULL then print statement of while loop
	cout<<current_Node->data<<endl;
	current_Node=current_Node->next;
	num++;
	}
	cout<<"number of nodes in the list are : "<<num<<endl;
	  	
}
Node*link_list:: Insert_node(int index,int x){
	if(index<0)
	return NULL;
	
	
	int current_index=2;
	Node*current_Node=head;
	while(current_Node!=NULL && index>current_index){
		current_Node=current_Node->next;
		current_index++;
	}
	if(index>0 && current_Node==NULL);
	
	Node*newNode= new Node;
	newNode->data=x;
	
	if(index==0){
		newNode->next=head;
		head=newNode;	
}
else{
	newNode->next=current_Node;
	current_Node=newNode;
}
	
}

int main(){
	link_list l1;
	
//inserting nodes	
	l1.Insert_node(0,4);
	l1.Insert_node(0,3);
	l1.Insert_node(0,2);
	l1.Insert_node(0,1);
	//display
	l1.display();
	
	//searching node by number
	int number;
	cout<<"Enter number you want to search  :"<<endl;
	cin>>number;
    if(l1.find_node(number)>0){
		cout<<number<<" found "<<endl;
	}else{
		cout<<number<<" Not-found "<<endl;
	}	
	//delete node
	int num1;
	cout<<"Enter number you want to delete : "<<endl;
	cin>>num1;
	if(l1.delete_node(num1)>0){
		cout<<num1<<"  deleted    "<<endl;
	}else{
		cout<<num1<<" number   Not-found   "<<endl;
	}
	cout<<"display all values"<<endl;
    l1.display();
	
	return 0;
}
