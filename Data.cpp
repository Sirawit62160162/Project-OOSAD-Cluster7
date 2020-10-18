#include<iostream>
using namespace std;
class QueueArray {
	private :
		       int *arr_queue ;
		       int max;
		       int count;
		       int font;
		       int rear;
		       
    public  :
	           QueueArray(int size){
	           	   arr_queue =new int[size];
	           	   max =size;
	           	   count =0;
	           	   font  =0;
	           	   rear  =0;
	           	   
			   }
			   ~QueueArray(){
			   	   delete [] arr_queue;
			   }
			   void enqueue(int value){
			   	     arr_queue[rear] =value;
			   	     rear++;
			   	     count++;
			   }
			   int dequeue(){
					 arr_queue[font];
					 rear++;
					 count--;
					 if(font == rear ){
					 
						font =0;
						rear =0;
					}
			   }
			   void show(){
			   	   isFull();
			   	   Empty();
					  for(int i=0;i<max;i++){
					  	 cout<<"Output :" <<arr_queue[i]<<endl;
					  }			   	
			   }
			   bool isfull(){
			   	    if(count==max){
			   	    	cout<<"empty" <<endl;
			   	    	  return true;
					   }else {
					   	  return false;
					   }
			   }
			   bool isEmpty(){
			   	    //isFull
			   } 		       
};

int main(){
	 QueueArray* obj_queueArr = new QueueArray(5);
	 obj_queueArr->enqueue(5);
	 obj_queueArr->enqueue(10);
	 obj_queueArr->show();
	 
	 obj_queueArr.enqueue(5);
	 obj_queueArr.enqueue(10);
	 obj_queueArr.show();	
} 
