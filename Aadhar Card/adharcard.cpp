/*
 * adharcard.cpp
 *
 *  Created on: 15-Jun-2019
 *      Author: mayur
 */

#include "adharcard.h"

adharcard::adharcard() {
	// TODO Auto-generated constructor stub
}

void adharcard::initializer(){				//Initializing the Indexes NULL of Hash Table
	for(int i=0;i<10;i++)
		table[i].next=NULL;
}

void adharcard::Add_Entry(){				//Adding Entry for New Aadhar Card entry
	user *temp=new user();
	temp->Black_List=false;
	int a=rand();
	temp->Aadhar_Id[0]=a%1000000;
	int b=rand();
	temp->Aadhar_Id[1]=b%1000000;
	cout<<"Aadhar ID : "<<temp->Aadhar_Id[0]<<temp->Aadhar_Id[1];
	cout<<"\nEnter First Name : ";
	cin>>temp->First_Name;
	cout<<"Enter Guardian's Name : ";
	cin>>temp->Guardian_Name;
	cout<<"Enter Last Name : ";
	cin>>temp->Last_Name;
	temp->Phone_No[0]=0;
	temp->Phone_No[1]=0;
	int hash=b%10;
	if(table[hash].next==NULL)				//Placing New Aadhar ID in Hash Table with chaining
		table[hash].next=temp;
	else{									//collision handled using linked organization
		temp->next=table[hash].next;
		table[hash].next=temp;
	}											//Hash Table With Chaining
}
void adharcard::display(){						//Displaying the List

	for(int i=0;i<10;i++){
		user *temp=table[i].next;				//Jump to a'th index of Hash table
		while(temp!=NULL)						//traversing of linked list
		{
			if(temp->Black_List)
				cout<<setw(16)<<"Blocked User|"<<setw(12);
			else
				cout<<setw(28);
			cout<<temp->First_Name<<" |"<<setw(15);
			cout<<temp->Guardian_Name<<" |"<<setw(15);
			cout<<temp->Last_Name<<" |"<<setw(9);
			cout<<temp->Aadhar_Id[0]<<temp->Aadhar_Id[1]<<" |"<<setw(13);
			if(temp->Phone_No[0]!=0){
				cout<<temp->Phone_No[0]<<temp->Phone_No[1]<<" |"<<endl;
			}
			else
				cout<<setw(10)<<"-"<<setw(10)<<"|"<<endl;
			temp=temp->next;
		}
	}
}
void adharcard::Delete_Entry(int adhar_No[],string F_name){							//Deleting an Entry

	int a=adhar_No[1];
	a=a%10;
	user *temp=table[a].next;					//Jump to a'th index of Hash table
	if(temp==NULL){
		cout<<"User With Provided Information Does Not Exists Data-Base:";
		return;
	}
		//if user found and node is
		//first node of hash table in chain

	else if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1] && temp->First_Name.compare(F_name)==0){
		user *deletingNode=temp;
		table[a].next=temp->next;
		cout<<"User Information Deleted Successfully";
		delete(deletingNode);					//memory deallocated
		return;
	}
	else{	//	for remaining cases search the node and deleting node
		user *temp2=temp->next;					//second pointer for back tracking
		while(temp2!=NULL)
		{
			if(temp2->Aadhar_Id[0]==adhar_No[0] && temp2->Aadhar_Id[1]==adhar_No[1] && temp2->First_Name.compare(F_name)==0){
				user *deletingNode=temp2;
				temp->next=temp2->next;
				cout<<"User Information Deleted Successfully";
				delete(deletingNode);			//memory deallocated
				return;
			}
			temp=temp->next;
			temp2=temp2->next;
		}
		if(temp2==NULL)
			cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
	}
}
void adharcard::Update_Entry(int adhar_No[],string F_name){					//Updating Entry
																			//only if User is Not Black-listed...
	int a=adhar_No[1];
	a=a%10;
	user *temp=table[a].next;
	while(temp!=NULL){
		if(temp->Black_List){
			cout<<"User Is Blocked";
			return;
		}
		//searching non blocked user by it's Aadhar ID and Name
		else if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1] && temp->First_Name.compare(F_name)==0){
			cout<<"\n\tEnter New Data :"<<endl;
			cout<<"\tEnter First Name : ";
			cin>>temp->First_Name;
			cout<<"\tEnter Guardian's Name : ";
			cin>>temp->Guardian_Name;
			cout<<"\tEnter Last Name : ";
			cin>>temp->Last_Name;
			cout<<"\nInformation Updated Successfully"<<endl;
			return;
		}
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
}

void adharcard::Search_Entry(int adhar_No[],string Sub_Str){					//Searching for an Entry
	int a;																		//for both blacklisted and non-blacklisted
	if(adhar_No[1]==0){			//Searching user by any Sub-String only
		for(int i=0;i<10;i++){
			user *temp=table[i].next;
			while(temp!=NULL)
			{
				string test=temp->First_Name+temp->Guardian_Name+temp->Last_Name;
				size_t found = test.find(Sub_Str);
				if (found != string::npos){
					if(temp->Black_List)
						cout<<setw(16)<<"Blocked User|"<<setw(12);
					else
						cout<<setw(28);
					cout<<temp->First_Name<<" |"<<setw(15);
					cout<<temp->Guardian_Name<<" |"<<setw(15);
					cout<<temp->Last_Name<<" |"<<setw(9);
					cout<<temp->Aadhar_Id[0]<<temp->Aadhar_Id[1]<<" |"<<setw(13);
					if(temp->Phone_No[0]!=0){
						cout<<temp->Phone_No[0]<<temp->Phone_No[1]<<" |"<<endl;
					}
					else
						cout<<setw(10)<<"-"<<setw(10)<<"|"<<endl;
				}
				temp=temp->next;
			}
		}
		return;
	}
	else if(Sub_Str=="\0"){			//Search user by Aadhar ID only
		a=adhar_No[1];
		a=a%10;
		user *temp=table[a].next;
		while(temp!=NULL){
			if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1]){

				if(temp->Black_List)
					cout<<setw(16)<<"Blocked User|"<<setw(12);
				else
					cout<<setw(28);
				cout<<temp->First_Name<<" |"<<setw(15);
				cout<<temp->Guardian_Name<<" |"<<setw(15);
				cout<<temp->Last_Name<<" |"<<setw(9);
				cout<<temp->Aadhar_Id[0]<<temp->Aadhar_Id[1]<<" |"<<setw(13);
				if(temp->Phone_No[0]!=0){
					cout<<temp->Phone_No[0]<<temp->Phone_No[1]<<" |"<<endl;
				}
				else
					cout<<setw(10)<<"-"<<setw(10)<<"|"<<endl;
				return;
			}
			temp=temp->next;
		}
		if(temp==NULL)
			cout<<"User Not Found In DataBase"<<endl;
		return;
	}
	else{							//Search user by Aadhra ID and Name Both
		a=adhar_No[1];
		a=a%10;
		user *temp=table[a].next;
		while(temp!=NULL){
			if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1]){
				string test=temp->First_Name+temp->Guardian_Name+temp->Last_Name;
				size_t found = test.find(Sub_Str);
				if (found != string::npos){
					cout << "Found"<< endl;
					if(temp->Black_List)
						cout<<"Blocked User\t";
					else
						cout<<"\t\t";
					cout<<temp->First_Name<<"\t";
					cout<<temp->Guardian_Name<<"\t";
					cout<<temp->Last_Name<<"\t";
					cout<<temp->Aadhar_Id[0]<<temp->Aadhar_Id[1]<<endl;
				   	return;
				}
			}
			temp=temp->next;
		}
		if(temp==NULL)
			cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
	}
	return;
}

void adharcard::Black_List(int adhar_No[2],string F_name){				//For Black-listing and removing form black list User
	int a=adhar_No[1];
	a=a%10;
	int press;
	user *temp=table[a].next;
	while(temp!=NULL){
		if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1] && temp->First_Name.compare(F_name)==0){
			if(temp->Black_List){
				//If User is Black Listed and for unblocking
				cout<<"User Is Blocked :\nPress 1. Unblock\nPress 0. Exit\nEnter Your Choice : ";
				cin>>press;
				if(press==1)
					temp->Black_List=false;
				else return;
			}
			else{
				//If User is Not Black Listed and for blocking
				cout<<"User IS Not Blocked :\nPress 1. Block\nPress 0. Exit\nEnter Your Choice : ";
				cin>>press;
				if(press==1)
					temp->Black_List=true;
				else return;
			}
			return;
		}
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
}

void adharcard::Is_Black_List(int adhar_No[]){				//Checking if User is Black-listed...

	int a=adhar_No[1];
	a=a%10;
	user *temp=table[a].next;
	while(temp!=NULL){
		if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1] ){
			if(temp->Black_List){
				cout<<"\nThis Account Is Blocked \nContact Customer Care Team For Unblock/Help : ";
				return;
		}
			else{
				cout<<"\nAccount Is Active/ User IS Not Blocked :";
				return;
			}
		}
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
	return;
}

void adharcard::Phone_No_Allocation(int adhar_No[],string F_name){						//Allocating Phone No
																						//if user is not black-listed...
	int a=adhar_No[1];
	a=a%10;
	user *temp=table[a].next;
	while(temp!=NULL){
		if(temp->Aadhar_Id[0]==adhar_No[0] && temp->Aadhar_Id[1]==adhar_No[1] && temp->First_Name.compare(F_name)==0){
			if(temp->Phone_No[0]==0){
				if(temp->Black_List){
					cout<<"This Account Is Blocked \nUnable To Allocate Phone Number\nContact Customer Care Team For Unblock/Help :";
					return;
				}
				else{
					a=rand();
					a=a%100000;
					temp->Phone_No[0]=a;
					a=rand();
					a=a%100000;
					temp->Phone_No[1]=a;
					cout<<"Contact Number Allocated Is : "<<temp->Phone_No[0]<<temp->Phone_No[1];
					return;
				}
			}
			else{
				cout<<"\nPhone Number Already Allocated To This Aadhar ID\nContact Customer Care Team For Help :";
				return;
			}
		}
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"\nUser With Provided Information Does Not Exists Data-Base:";
	return;
}
adharcard::~adharcard() {
	// TODO Auto-generated destructor stub
}
