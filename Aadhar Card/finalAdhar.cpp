/*============================================================================
 	Name        : adhar.cpp
	Author      : MaNikRuTa

** 	Problem
	Statement		:	Aadhar Card Management.	***

	You have been given the responsibility to manage the data of a Aadhar like card.

	Each entry has these mandatory fields:
	Aadhar Id - [Unique, Random]
	First Name -
	Guardian’s Name -
	Last Name -

	You should be able to do the following with the entries:
	- Adding an entry
	- Deleting an entry
	- Updating an entry - (Not Aadhar Id)
	- Searching an entry

	Search by Id or Full name(The user enters their 'full name' or any substring,
	return all the entries that match [in First name, guardian’s name, last name]
	completely or partially)- Blacklist entries/ Remove from Blacklist

	Don't allow users to access the entry, if the entry is blacklisted

	Now, there is a telephone company which uses this data to give unique phone
	numbers to people with non blacklisted Aadhar Id’s.
	Users provide the telephone company with their Aadhar Id & First Name.
	Check the first name against the Aadhar Id in o(1) and return with yes or no.
	If the entry is present, the telephone company allots a unique phone number
	to the recipient.You could use console input or file input or any other means.
	============================================================================*/

#include"adharcard.cpp"

int main() {
	adharcard obj;
	obj.initializer();
	string name;
	int a[2];
	int ch,ch2,ch3;
	cout<<"\n*******************************************************************************************************\n";
	do{
		cout<<"\n\t\t\tMaNikRuTa Telecom\n\n\t1.Adhar Card services\n\t2.Sim card Services\n\t0.Exit\n\tEnter your choice : ";
		cin>>ch;
		cout<<"\n*******************************************************************************************************\n";
		if(ch==1){

			do{
				cout<<"1.Enter\n2.display\n3.Delete\n4.update\n5.Status Of User\n6.Block/Unblock user\n7.Search User\n0.Exit\nEnter Your Choice : ";
				cin>>ch3;
				cout<<"\n========================================================================================================\n";
				switch(ch3){
				case 1:
					obj.Add_Entry();
					cout<<"\n========================================================================================================\n";
					break;
				case 2:
					cout<<setw(30)<<"First Name|"<<setw(17)<<"Parent's Name|"<<setw(17)<<"Surname|"<<setw(17)<<"Aadhar Card|"<<setw(20)<<"Phone Number|"<<endl;
					obj.display();
					cout<<"\n========================================================================================================\n";
					break;
				case 3:
					cout<<"Enter First Name : ";
					cin>>name;
					cout<<"Enter Aadhar ID : "<<endl;
					cout<<"Enter first 6 digits : ";
					while(1){
						cin>>a[0];
						if(a[0]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					cout<<"Enter Last 6 Digits : ";
					while(1){
						cin>>a[1];
						if(a[1]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					obj.Delete_Entry(a,name);
					cout<<"\n========================================================================================================\n";
					break;
				case 4:
					cout<<"Enter Details To Get Updated :"<<endl;
					cout<<"Enter First Name : ";
					cin>>name;
					cout<<"Enter Aadhar ID : "<<endl;
					cout<<"Enter first 6 digits : ";
					while(1){
						cin>>a[0];
						if(a[0]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					cout<<"Enter Last 6 Digits : ";
					while(1){
						cin>>a[1];
						if(a[1]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					obj.Update_Entry(a,name);
					cout<<"\n========================================================================================================\n";
					break;
				case 5:
					cout<<"Enter AadharCard Number To Know Status :"<<endl;
					cout<<"Enter first 6 digits : ";
					while(1){
						cin>>a[0];
						if(a[0]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					cout<<"Enter Last 6 Digits : ";
					while(1){
						cin>>a[1];
						if(a[1]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					obj.Is_Black_List(a);
					cout<<"\n========================================================================================================\n";
					break;
				case 6:
					cout<<"Enter Details To Block/Unblock :"<<endl;
					cout<<"Enter First Name : ";
					cin>>name;
					cout<<"Enter Aadhar ID : "<<endl;
					cout<<"Enter first 6 digits : ";
					while(1){
						cin>>a[0];
						if(a[0]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					cout<<"Enter Last 6 Digits : ";
					while(1){
						cin>>a[1];
						if(a[1]/1000000>0)
							cout<<"Limit Exceeds \nRe-Enter Number";
						else break;
					}
					obj.Black_List(a,name);
					cout<<"\n========================================================================================================\n";
					break;
				case 7:
					cout<<"Enter Details For Searching :"<<endl;
					cout<<"\nSearch By Name or ID :\nPress 1.Sub String\nPress 2.ID\nPress 3.Both Name & ID\nPress 0.Exit\nEnter Your Choice : ";
					cin>>ch2;
					if(ch2==1){
						cout<<"Search (Sub String Allowed): ";
						cin>>name;
						a[0]=0,a[1]=0;
						cout<<setw(30)<<"First Name|"<<setw(17)<<"Parent's Name|"<<setw(17)<<"Surname|"<<setw(17)<<"Aadhar Card|"<<setw(20)<<"Phone Number|"<<endl;
						obj.Search_Entry(a,name);
						break;
					}
					else if(ch2==2){
						cout<<"Enter Aadhar ID : "<<endl;
						cout<<"Enter first 6 digits : ";
						while(1){
							cin>>a[0];
							if(a[0]/1000000>0)
								cout<<"Limit Exceeds \nRe-Enter Number";
							else break;
						}
						cout<<"Enter Last 6 Digits : ";
						while(1){
							cin>>a[1];
							if(a[1]/1000000>0)
								cout<<"Limit Exceeds \nRe-Enter Number";
							else break;
						}
						cout<<setw(30)<<"First Name|"<<setw(17)<<"Parent's Name|"<<setw(17)<<"Surname|"<<setw(17)<<"Aadhar Card|"<<setw(20)<<"Phone Number|"<<endl;
						obj.Search_Entry(a,"\0");
					}
					else if(ch2==3){
						cout<<"Enter Details To Get Updated :"<<endl;
						cout<<"Enter First Name : ";
						cin>>name;
						cout<<"Enter Aadhar ID : "<<endl;
						cout<<"Enter first 6 digits : ";
						while(1){
							cin>>a[0];
							if(a[0]/1000000>0)
								cout<<"Limit Exceeds \nRe-Enter Number : ";
							else break;
						}
						cout<<"Enter Last 6 Digits : ";
						while(1){
							cin>>a[1];
							if(a[1]/1000000>0)
								cout<<"Limit Exceeds \nRe-Enter Number";
							else break;
						}
						cout<<setw(30)<<"First Name|"<<setw(17)<<"Parent's Name|"<<setw(17)<<"Surname|"<<setw(17)<<"Aadhar Card|"<<setw(20)<<"Phone Number|"<<endl;
						obj.Search_Entry(a,name);
					}
					cout<<"\n========================================================================================================\n";
					break;
				}
			}while(ch3!=0);
		}
		else if(ch==2){
			cout<<"Welcome To MaNikRuTa Sim Services\nProvide some details to use services :\n";
			cout<<"Enter First Name : ";
			cin>>name;
			cout<<"Enter Aadhar ID : "<<endl;
			cout<<"Enter first 6 digits : ";
			while(1){
				cin>>a[0];
				if(a[0]/1000000>0)
					cout<<"Limit Exceeds \nRe-Enter Number : ";
				else break;
			}
			cout<<"Enter Last 6 Digits : ";
			while(1){
				cin>>a[1];
				if(a[1]/1000000>0)
					cout<<"Limit Exceeds \nRe-Enter Number";
				else break;
			}
			obj.Phone_No_Allocation(a,name);
			cout<<"\n========================================================================================================\n";
		}
	}while(ch!=0);
	cout<<"\tProgram ends";
	return 0;
}
