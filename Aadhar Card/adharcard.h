/*
 * adharcard.h
 *
 *  Created on: 15-Jun-2019
 *      Author: mayur
 */

#ifndef ADHARCARD_H_
#define ADHARCARD_H_
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

 struct user{		//user structure
	bool Black_List;
	int Aadhar_Id[2];
	string First_Name;
	string Guardian_Name;
	string Last_Name;
	int Phone_No[2];
	user *next;
};
 struct h{			//For Array of Hashing table with chaining property
	user *next;
};

class adharcard {
private:
	h table[10];		//Array of Hashing table
public:					//Required Functions
	adharcard();
	void Phone_No_Allocation(int [],string);
	void initializer();
	void Add_Entry();
	void display();
	void Delete_Entry(int [],string);
	void Update_Entry(int [],string);
	void Search_Entry(int [],string);
	void Black_List(int [],string);
	void Is_Black_List(int []);
	virtual ~adharcard();
};

#endif /* ADHARCARD_H_ */
