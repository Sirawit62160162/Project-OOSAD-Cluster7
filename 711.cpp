#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<sstream>
using namespace std;
class seven11{
	private:
		class node{
			public:
				string group;
				string name;
				int price;
				int num;
				node *link; 
		};
		node *head,*temp,*tail;
		node *headBill,*tempBill,*tailBill;
		double money;
	public:
		seven11(){
			head = NULL;
			tail = NULL;
			headBill = NULL;
			tailBill = NULL;
		}
		bool fileProduct(){
			string group,name,s_price,s_num,filein;
			int price,num;
			stringstream s1,s2;
			ifstream data;
			data.open("product.dat",ios::in);
			if(data.fail()){
				return false;
			}else{
				while(getline(data,filein)){
					group = filein.substr(0,filein.find(','));
				        filein.erase(0,filein.find(',')+1);
					name = filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);
					s_price = filein.substr(0,filein.find(','));
					    filein.erase(0,filein.find(',')+1);	
					s_num = filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);
					s1 << s_price;
					s1 >> price;
					s2 << s_num;
					s2 >> num;
					s1.clear();
					s2.clear();		
					addProduct(group,name,price,num);
				}
			}
		}	
		void addProduct(string group,string name,int price,int num){
			if(head==NULL){
				head = new node;
				head->group = group;
				head->name = name;
				head->price = price;
				head->num = num;
				tail = head;
				tail->link = NULL;
			}else{
				temp = new node;
				temp->group = group;
               	temp->name = name;
            	temp->price = price;
            	temp->num = num;
               	tail->link = temp;
              	tail = temp;
				tail->link = NULL;
			}
		}
		void showProduct(string p){
			int i=1;
			temp = head;
			if(head == NULL){
		        	cout<< "the list is empty" << endl;
			}else{
				while(temp != NULL){
					if(temp->group == p){
						cout << i <<" " << temp->name << " " << temp->price << " " << temp->num << endl; 
   	                	temp=temp->link;
   	                	i++;
					}else{
						temp=temp->link;
					}
				}
				cout << "================================================" << endl;
			}
		}
		int getprice(string name){
			if(head == NULL){
		        	cout<< "the list is empty" << endl;
			}else{
				temp = head;
				while(temp != NULL){
					if(temp->name == name){
						return temp->price;
					}else{
						temp=temp->link;
					}
				}
			}
		}
		void calculate(int price){				
			
			
			
			
			
		}
		void setBill(string name,int num,int price){
			if(headBill==NULL){
				headBill = new node;
				headBill->name = name;
				headBill->price = price;
				headBill->num = num;
				tailBill = headBill;
				tailBill->link = NULL;
			}else{
				tempBill = new node;
               	tempBill->name = name;
            	tempBill->price = price;
            	tempBill->num = num;
               	tailBill->link = tempBill;
              	tailBill = tempBill;
				tailBill->link = NULL;
			}
		}
		void printBill(){
			int i=1;
			tempBill = headBill;
			if(headBill == NULL){
		        	cout<< "the list is empty" << endl;
			}else{
				while(tempBill != NULL){
						cout << i << " " << tempBill->name << " " << tempBill->price << " " << tempBill->num << endl; 
   	                	tempBill=tempBill->link;
						i++;
				}
			}
		}
};


int main(){
	seven11 *seven = new seven11;
	int menu,choseNum;
	string choseName;
	seven->fileProduct();	
	Menu:
	//system("CLS");
	cout << "======= Menu ========" << endl;
	cout << "1. Chose Product Category " << endl;
	cout << "2. Add Product " << endl;
	cout << "3. Delete Product " << endl;
	cout << "4. Register Allmember" << endl;
	cout << "5. Exil" << endl;
	cout << "=====================" << endl;
	cout << "Enter : ";
	cin >> menu;
	switch(menu){
		case 1:
			MenuChose:
			system("CLS");
			do{
			cout << "======= Category ========" << endl;
			cout << "1. Drink " << endl;
			cout << "2. Food" << endl;
			cout << "3. Wares"<< endl;
			cout << "4. Check Bill" << endl;
			cout << "5. Back " << endl;
			cout << "=========================" << endl;
			cout << "Enter : ";
			cin >> menu;
			}while(menu<1||menu>5);
			switch(menu){
				case 1:
						menuDrink:
						system("CLS");
						do{
						cout << "======= Drink ========" << endl;
						cout << "1. Water " << endl;
						cout << "2. Sparkling Water" << endl;
						cout << "3. Tea / Coffee" << endl;
						cout << "4. Intoxicating Drink" << endl;
						cout << "5. Back" << endl;
						cout << "======================" << endl;
						cout << "Enter : ";
						cin >> menu;
						}while(menu<1||menu>5);
						switch(menu){
							case 1:
								seven->showProduct("Water");
								cout << "Enter Name : ";
								cin >> choseName;
								cout << "Enter Num : ";
								cin >> choseNum;
								seven->setBill(choseName,choseNum,seven->getprice(choseName));
								goto menuDrink;
								break;
							case 2:
								seven->showProduct("SparklingWater");
								cout << "Enter Name : ";
								cin >> choseName;
								cout << "Enter Num : ";
								cin >> choseNum;
								seven->setBill(choseName,choseNum,seven->getprice(choseName));
								goto menuDrink;
								break;
							case 3:
								seven->showProduct("Tea/Coffe");
								cout << "Enter Name : ";
								cin >> choseName;
								cout << "Enter Num : ";
								cin >> choseNum;
								seven->setBill(choseName,choseNum,seven->getprice(choseName));
								goto menuDrink;
								break;
							case 4:
								seven->showProduct("IntoxicatingDrink");
								cout << "Enter Name : ";
								cin >> choseName;
								cout << "Enter Num : ";
								cin >> choseNum;
								seven->setBill(choseName,choseNum,seven->getprice(choseName));
								goto menuDrink;
								break;
							case 5:
								goto MenuChose;
								break;
						}
				case 2:
					menuFood:
					system("CLS");
					do{
					cout << "======= Food ========" << endl;
					cout << "1. Ready Meals " << endl;
					cout << "2. Snack" << endl;
					cout << "3. Dry Food" << endl;
					cout << "4. Dessert and Candy" << endl;
					cout << "5. Back" << endl;
					cout << "======================" << endl;
					cout << "Enter : ";
					cin >> menu;
					}while(menu<1||menu>5);
					switch(menu){
						case 1:
							seven->showProduct("readymeal");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuFood;
							break;
						case 2:
							seven->showProduct("snack");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuFood;
							break;
							
						case 3:
							seven->showProduct("dryfood");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuFood;
							break;	
						case 4:
							seven->showProduct("dessertandcandy");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuFood;
							break;
						case 5:
							goto MenuChose;
								break;
						}
				case 3:
					menuWares:
					system("CLS");
					do{
					cout << "======= Wares ========" << endl;
					cout << "1. Household Item " << endl;
					cout << "2. Health / Beauty" << endl;
					cout << "3. Electronic" << endl;
					cout << "4. Back" << endl;
					cout << "======================" << endl;
					cout << "Enter : ";
					cin >> menu;
					}while(menu<1||menu>5);
					switch(menu){
						case 1:
							seven->showProduct("Householditem");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuWares;
							break;
						case 2:
							seven->showProduct("Health/Beauty");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuWares;
							break;
							
						case 3:
							seven->showProduct("Electronic");
							cout << "Enter Name : ";
							cin >> choseName;
							cout << "Enter Num : ";
							cin >> choseNum;
							seven->setBill(choseName,choseNum,seven->getprice(choseName));
							goto menuWares;
							break;	
						case 4:
							goto MenuChose;
								break;
						}
				case 4:
					seven->printBill();
					break;	
				case 5:
					goto Menu;
					break;
			}
			break;


		case 2:
			// Add product
			break;
		
		case 3:
			//Delete product
			break;
			
		case 4:
			
			//Register Allmember
			return 0;
			break;
		case 5:
			
			//Exit
			return 0;
			break;
			
	}
	return 0;
}	
