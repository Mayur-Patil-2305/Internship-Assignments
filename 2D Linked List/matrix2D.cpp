//============================================================================
// Name        : 2Dlinked list.cpp
// Author      : mayur
// Version     :
// Copyright   : Copyright by MaNikRuTa PICT group
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"matrixconversionlinkedlist.cpp"

int main() {
	matrix_conversion_linkedlist o;
    // 2D matrix
    int ch,choice;
    do{
    	cout<<"\n\n**********************************************\n";
    	cout<<"Menu\n1.Create(2-D Matrix)\n2.Conversion(2D Matrix to 2D Linked List)\n3.Perimeter() : Computes the perimeter of\n\t\t the element forming Square\n4.Diagonal() : Addition Of Diagonals\n5.Transpose() : Transpose(2D Linked List)\n0.Exit\nEnter Your choice : ";
    	cin>>ch;
    	switch(ch){
    	case 1:		//Create(2-D Matrix)
    		cout<<"\n**********************************************\n\n";
    		o.ar();
    		break;
    	case 2:		//Conversion(2D Matrix to 2D Linked List)
        	cout<<"\n**********************************************\n\n";
        	cout<<"\tFor Recursive Conversion     : Press 0"<<endl;
        	cout<<"\tFor Non-Recursive Conversion : Press 1"<<endl;
        	cout<<"\tEnter Your Choice : ";
        	cin>>choice;
        	cout<<"\n**********************************************\n";
        	if(choice==0)
        	{
        		cout<<"Recursive conversion successful\n\n";
        		o.conversion(0,0,0,3,3);
        	}
        	else if(choice==1)
        	{
        		cout<<"Recursive conversion successful\n\n";
        		o.NonRecConv();
        	}
        	else
        	{
        		cout<<"Enter Proper Entry";
        		break;
        	}
            break;
    	case 3:			//Perimeter() : Computes the perimeter of the element forming Square
    		cout<<"\n**********************************************\n\n";
    		o.perimeter();
    		 break;
    	case 4:			//Diagonal() : Addition Of Diagonals
   	      	cout<<"\n**********************************************\n\n";
           	cout<<"1)	Right Diagonal Addition = "<<o.addition(1,1)<<endl;
   	   		cout<<"2)	Left Diagonal Addition  = "<<o.addition(1,0)<<endl;
   	   		cout<<"3)	Addition Of Matrix      = "<<o.addition(0,0);
   	  		break;

    	case 5:			//Transpose() : Transpose(2D Linked List)
        	cout<<"\n**********************************************\n\n";
        	o.conversion(1,0,0,3,3);
            break;
    	case 0:
        	cout<<"\n**********************************************\n\n";
        	cout<<"\tProgram ends";
    	}
    }while(ch!=0);
    return 0;
}
