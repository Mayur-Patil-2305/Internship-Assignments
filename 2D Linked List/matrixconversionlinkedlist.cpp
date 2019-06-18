/*
 * matrixconversionlinkedlist.cpp
 *
 *  Created on: 18-Jun-2019
 *      Author: mayur
 */

#include "matrixconversionlinkedlist.h"

matrix_conversion_linkedlist::matrix_conversion_linkedlist() {
	// TODO Auto-generated constructor stub

}

void matrix_conversion_linkedlist::ar()							//Get inputs For Matrix
{
	int n=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			n++;
			cout<<n<<")\tarray["<<i<<"]["<<j<<"] = ";
			cin>>arr[i][j];
		}
}
Node *getnode(int dt)											//Creating Node
{
	Node *temp=new Node();
	temp->data=dt;
	temp->right=NULL;
	temp->down=NULL;
	return temp;
}

Node *NRconstruct(Node *head,int arr[][3])	 					//Non-Recursion Construction
{																//Traversing the Node Non-Recursively for i and j...
	Node *p=head;
	Node *head2=new Node();
	p->down=head2;
	Node *q=new Node();
	q=head2;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			Node *temp1=getnode(arr[i][j]);		//first node
			Node *temp2=getnode(arr[i+1][j]);	//down node
			if(j==0){							//first pair of node of j=0
				p->data=arr[i][j];
				head2->data=arr[i+1][j];
			}
			else{
				p->right=temp1;
				head2->right=temp2;
				p=p->right;
				head2=head2->right;
				p->down=head2;
			}
		}
		//For Backtracking Pair of node to i++ th and j=0 th position...
		if(i<1){
			p=q;							//backtrack main pointer to down position
			Node *temp3=new Node();			//new node for down pointer of new pair
			head2=temp3;
			q=temp3;
			p->down=head2;					//linking of pairs;
		}
	}
	return head;
}

Node* Rconstruct(int arr[3][3],int trans_bit, int i, int j,int m, int n)	//Recursive Construction
{
    // return if i or j is out of bounds

    if (i > n - 1 || j > m - 1)

        return NULL;

    // create a new node for current i and j

    // and recursively allocate its down and

    // right pointers

    Node * temp = new Node();

    temp->data = arr[i][j];
    if(trans_bit==0)		//transpose bit
    {
        temp->right = Rconstruct(arr,0, i, j + 1, m, n);
        temp->down  = Rconstruct(arr,0, i + 1, j, m, n);
    }
    else
    {
    	temp->right  = Rconstruct(arr,1, i + 1, j, m, n);
    	temp->down 	 = Rconstruct(arr,1, i, j + 1, m, n);
    }
    return temp;
}

void matrix_conversion_linkedlist::conversion(int trans_bit,int i,int j,int m,int n){				//Recursive Conversion
	Node *temp=Rconstruct(arr,trans_bit,i,j,m,n);
	head=temp;
	display(temp);
}
void matrix_conversion_linkedlist::NonRecConv(){													//Non-Recursive Conversion
	Node *Newhead=new Node();
	head=NRconstruct(Newhead,arr);
	display(head);
}
void matrix_conversion_linkedlist::display(Node* head)											//Display the Matrix...
{

    // pointer to move right

    Node* Rp;

    // pointer to move down

    Node* Dp = head;

    // loop till node->down is not NULL
    cout<<"\t";
    while (Dp)
    {
        Rp = Dp;
        // loop till node->right is not NULL

        while (Rp)
        {
            cout << Rp->data<<" - > "<<setw(5);
            Rp = Rp->right;
        }
        cout <<" NULL\n\t";
        Dp = Dp->down;
    }
    for(int i=0;i<3;i++)
    	cout<<"NULL"<<setw(10);
}

void matrix_conversion_linkedlist::perimeter(){
	int i=0,j=0,add=0;
    // pointer to move right
	Node* Rp;

    // pointer to move down

    Node* Dp = head;

    // loop till node->down is not NULL
    cout<<"\t";
    while (Dp)
    {
    	j=0;
        Rp = Dp;
        // loop till node->right is not NULL

        while (Rp)
        {
        	if(i!=1 || j!=1)
        		add=add+Rp->data;
        	Rp = Rp->right;
            j++;
        }
        Dp = Dp->down;
        i++;
    }
    Node *temp=head;
    Node *r=temp->down;
    Node *p=temp;
    Node *q=r;
    int add2=0;
    for(i=0;i<2;i++){
    	for(j=0;j<2;j++){
    		add2=temp->data+r->data+temp->right->data+r->right->data;
    		temp=temp->right;
    		r=r->right;
    		cout<<"\n\tPerimeter Of "<<i+j+1<<" Square Is : "<<add2;
    	}
    	p=p->down;
    	temp=p;
    	q=q->down;
    	r=q;
    }
    cout<<"\n\tPerimeter Of Outer Largest Square : "<<add<<endl;
}

int matrix_conversion_linkedlist::addition(int diagonal,int right)								//Addition of Diagonals
{
    // pointer to move right
	int add=0,rightDig=0,leftDig=0,i=0,j=0;
    Node* Rp;
    // pointer to move down

    Node* Dp = head;
    // loop till node->down is not NULL
    while (Dp) {
        Rp = Dp;
        j=0;
        // loop till node->right is not NULL
        while (Rp) {
        	if(i==j)
        	{
        		rightDig+=Rp->data;
        	}
        	if((i+j)==2)
        	{
        		leftDig+=Rp->data;
        	}

            add+=Rp->data;
            Rp = Rp->right;
            j++;
        }
        i++;
        Dp = Dp->down;
    }
    if(diagonal==1 && right==1)
    	return rightDig;
    if(diagonal==1 && right==0)
    	return leftDig;
    return add;
}

matrix_conversion_linkedlist::~matrix_conversion_linkedlist() {
	// TODO Auto-generated destructor stub
}
