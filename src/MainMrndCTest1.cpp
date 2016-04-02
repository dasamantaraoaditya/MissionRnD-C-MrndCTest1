/*
Do Read All questions carefully ,before writing any Code .
Make sure you submit the Code you have written through tool ,
before the submit window Closes .

*****************

Note : Make sure your MSBuild Suceeds before you submit ,or else It will lead to 0 marks .
->If you are stuck on a question or a particular Test case
is failing , Do Solve the Next question .As long as you click on submit at correct time,
your submissions are safe .

**************
There are only Sample Test Cases provided .Your code will also be graded
using Test cases on our end ,So Do think about testcases in all possible ways .

Your score will totally be based on the number of TestCases your programs
have passed on our end ,so if your code just passes sample cases
and fails all testcases at our end ,you will get you 0 marks .

******************
You can fill in the Helper Functions and make use of it
if you want to test from MainMrndCTest1.cpp
******************
All the Best .
*/

#include "FunctionHeadersMrndCTest1.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
//Start of Helper Functions

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

void addNode(struct node **head, int data){
    //Adds a node to head ,Modifies *head if SLL is null
	struct node * cur = createNode(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct node *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}

void printSll(struct node *head,int len){
	int i = 0;
	while (head != NULL){
		printf("%2d ",head->data);
		head = head->next;
		i++;
		if (i >= len){
			break;
		}
	}
}

void make_it_circular(struct node *head){
	//Makes a Normal SLL circular ,Make Last->next=head;

}

//End of Helper Functions

int main(){

	//Test Sequences

	//Test Circular Linked Lists

    //Test Between Days
	/*
	int dates[2][8] = { { 0, 2, 0, 4, 2, 0, 1, 6 }, { 0, 4, 0, 4, 2, 0, 1, 6 } };

	struct node *date1head = NULL, *date2head = NULL;
	for (int i = 7; i >= 0; i--){
	addNode(&date1head, dates[0][i]);
	addNode(&date2head, dates[1][i]);
	}

	int days = between_days(date1head, date2head);
	printf("Total Days - %d\n",days);
	*/
	//Test Concat4 Strings
}
