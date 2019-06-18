/*
 * matrixconversionlinkedlist.h
 *
 *  Created on: 18-Jun-2019
 *      Author: mayur
 */

#ifndef MATRIXCONVERSIONLINKEDLIST_H_
#define MATRIXCONVERSIONLINKEDLIST_H_
#include <iostream>
#include<iomanip>
using namespace std;

struct Node {

    int data;
    Node* right;
    Node *down;
};

class matrix_conversion_linkedlist {
private:
	Node *head=NULL;
	int arr[3][3];
public:
	matrix_conversion_linkedlist();
	void ar();
	int addition(int ,int );
	void display(Node *);
	void conversion(int,int,int,int,int);
	void NonRecConv();
	void perimeter();
	virtual ~matrix_conversion_linkedlist();
};

#endif /* MATRIXCONVERSIONLINKEDLIST_H_ */
