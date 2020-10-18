#include <iostream>
using namespace std;
struct Node{
		int Data;
		Node *link,*alink;
		Node(int data){
			Data = data;
			link = NULL;
			alink = NULL;
		}
};

class StackLink {
	private :
		Node *top,*head,*tail;
		int count,Pop,co,cou;
	public :
		StackLink( ){
			top = NULL;
			count = 0;
		}
		
		~StackLink( ){
			for(Node * tmp = top; tmp != NULL; top = top->link){
				delete tmp;
				tmp = NULL;		
			}
			top = NULL;
		}
		
		push( int value ){
			if(count==0){
				Node *tmp = new Node(value);
				head = tmp;
				tail = tmp;
				top = tail;
			}else{
				Node *tmp = new Node(value);
				tmp->alink = tail;
				tail->link = tmp;
				tail = tmp;
				top = tail;
			}
			count++;
			cou = count-1;
		}
		
		int pop( ){
			if(count>0){
				Pop = tail->Data;
				delete  tail->link;
				tail = tail->alink;
				top = tail;
			}
			count--;
		}
		
		show( ){
			Node *temp = head;
			if(isEmpty()==1){
				if(count==0){
					cout << "-" << endl << endl << "Size :" << size() << endl
					<< "Top :" << "None" << endl
					<< "Pop :" << Pop << endl << endl
					<< "Is Empty." << endl << endl;
					count = 0;
				}else{
					cout << "-" << endl << endl << "Size :" << "0" << endl
					<< "Top :" << "None" << endl
					<< "Pop :" << "None" << endl << endl
					<< "Is Empty." << endl << endl;
					count = 0;
				}
			}else{
				for(int i=0;i<count;i++){
					cout << temp->Data;
					cout << " ";
					temp = temp->link;
				}
				cout << endl << endl << "Size :" << size() << endl
				<< "Top :" << top->Data << endl;
				if(co == 0 || cou<count){
					cout << "Pop :None" << endl << endl;
				}else{
					cout << "Pop :" << Pop << endl << endl;
				}
				co++;
			}
		}
		
		bool isEmpty( ){
			if(count<=0){
				return true;
			}else{
				return false;
			}
		}
		
		int size( ){
			return count;
		}
		
};

int main(void){
	StackLink * obj_stackLink = new StackLink( );
	obj_stackLink->push(5);
	obj_stackLink->push(10);
	obj_stackLink->push(3);
	obj_stackLink->push(1);
	obj_stackLink->push(7);
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->push(9);
	obj_stackLink->push(8);
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->push(8);
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->pop();
	obj_stackLink->pop();
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->push(8);
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->show();
	
	obj_stackLink->push(8);
	obj_stackLink->push(4);
	obj_stackLink->show();
	
	obj_stackLink->pop();
	obj_stackLink->show();
}
