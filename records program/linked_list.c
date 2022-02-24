
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2019

 
 
 
 
 Copyright 2019 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// DEFINE



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
head - head of linked list
person - the data of the new person

output
head - head of linked list

return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL
2. person is not NULL

*/

ListNode *insertToList(ListNode **head, PersonInfo *person)
{
   //
  ListNode *newNode = NULL;
  ListNode *curr = NULL;

  //allocating memory for new node and copying person info into the new node
  curr = *head;
  newNode = malloc(sizeof(ListNode));
  newNode->person = *person;
  newNode->next = NULL;

  //check if head is null
  if (curr == NULL){
    *head = newNode;
  }
  //if head is not null, connect the old head to new node and make head pointer point to new node
  else{
    newNode->next = *head;
    *head = newNode;
  }
  
  return *head;
  

}


/************************************************************************/
/*
Purpose: find the first node in the list with the input family name and insert a new node containing the 
person data into the list.

If there is no node that matches that given family name then the operation is considered a failure.  

Input
head - head of list
familyName - the family name that must be used to find the first matching recrod
person - the person record to insert into the list as new node


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

Assumptions:
familyName is not NULL
person is not NULL

*/


ListNode *insertAfter(ListNode *head, char *familyName, PersonInfo *person)
{
	// add code
  
  ListNode *prev,*curr,*newNode;
  prev = NULL;
  curr = head;
  newNode = NULL;

  //find the first matching family name in the list
  while(curr != NULL){
    if (strcmp(curr->person.familyName, person->familyName) == 0){
      break;
    }
    prev = curr;
    curr = curr->next;
  }
  //if name is not in list return null
  if (strcmp(curr->person.familyName,person->familyName) != 0){
    return NULL;
  }

  newNode = malloc(sizeof(ListNode));
  newNode->person = *person;
  newNode->next = NULL;

  //check if list is empty/head is null
  if (prev == NULL){
    head = newNode;
    return head;
  }
  //connect previous node to new node and connect new node to next node
  else{
    prev->next = newNode;
    newNode->next = curr;
    return newNode;
  }

  


}


/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
person - person data that is stored in the list


return
0 if node was deleted
1 if node was not deleted or list is empty

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty
2. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteFromList(ListNode **head, PersonInfo *person)

{
	// add code
  ListNode *curr = NULL;
  curr = *head;

  //check if head is null
  if (curr == NULL){
    return 1;
  }
  //copying deleted person data into person
  *person = curr->person;
  //setting the head pointer to the next node, deleting the old head
  *head = curr->next;
  //free(person);
  free(curr);
  return 0;


}


/************************************************************************/

/*
Purpose: delete the first node with the matching family name
Input
head - the head of the list
familyName - family name of person

output
head - the head of the list
person - data of the person in the node


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

Assumptions
1. familyName is not NULL
2. Function has to be robuse enough to handle cases where head is NULL or the list is empty
3. If person is NULL then the person information stored in the node is not required to the output

*/


int deleteNodeByName(ListNode **head, char *familyName, PersonInfo *person)
{
	// add code
  ListNode *prev, *curr;
  prev = NULL;
  curr = *head;
  
  //finding matching family name
  while (curr != NULL){
    if (strcmp(curr->person.familyName, familyName) == 0){
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL){
    return 1;
  }

  //if first item, set head pointer to the next node, deleting the old head
  if (prev == NULL){
    *head = curr->next;
    *person = curr->person;
    //free(person);
    free(curr);
  }
  else{
    //connecting nodes around the deleted node
    prev->next = curr->next;
    *person = curr->person;
    //free(person);
    free(curr);
  }


  return 0;
  


}
/************************************************************************/
/*
Purpose: deletes all nodes from the list

input
head - the head of the list

output
head - the head of the list

return
none

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/


void deleteList(ListNode **head)
{
	// add code
  ListNode *curr,*temp;
  temp = NULL;
  curr = *head;

  //deleting nodes one by one, using temp to not access node that was already deleted
  while(curr != NULL){
    temp = curr->next;
    free(curr);
    curr = temp;
  }

  if(curr == NULL){
  }
  //*head = NULL;
  //free(*head);


}



/************************************************************************/
/*
Purpose: search for the first node with the matching familyName
Input
head - the head of the list
familyName - family name of person

Output
person - a copy of the person record in the node

return
a pointer to the node that was found.
NULL - if no node was found or list empty


Assumptions
1. familyName is not NULL
2. person can be NULL.  If person is NULL then no coping of the person record is required. 

*/


ListNode *searchByName(ListNode *head, char *familyName, PersonInfo *person)
{
	// add code
  ListNode *curr,*prev;

  prev = NULL;
  curr = head;

  //search for family name in list
  while (curr != NULL){
    if (strcmp(curr->person.familyName, familyName) == 0){
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL){
    return NULL;
  }
  else{
    *person = curr->person;
    
    return(curr);
  }

}



/************************************************************************/
/*
Purpose: prints all the records in the list according to their type a student or an employee

input
head - the head of the list
*/


void printList(ListNode *head)
{
  ListNode *curr;
  curr = head;

  //printing
  printStudents(curr);
  printEmployees(curr);


}

/************************************************************************/
/*
Purpose: prints all the students in the list

input
head - the head of the list

Output 
None

Return
None
*/


void printStudents(ListNode *head)
{
	// add code
  ListNode *curr;

  curr = head;
  //going through list, check if student, then print
  while(curr != NULL){
    if(curr->person.empOrStudent == STUDENT_TYPE){
      //printStudent(curr->person);
      printf("%-16s %-16s %8d %5.2f %3d %3d \n", curr->person.firstName, curr->person.familyName, curr->person.id,
	     curr->person.stu.gpa, curr->person.stu.numCompletedCourses, curr->person.stu.numRequiredCourses);
    }
    curr = curr->next;
  }



}
/************************************************************************/
/*
Purpose: prints all the employees in the list

input
head - the head of the list

Output
None

Return
None
*/


void printEmployees(ListNode *head)
{
	// add code
  ListNode *curr;
  //PersonInfo *p;

  curr = head;
  //go through list, check if employee, then print
  while(curr != NULL){
    if (curr->person.empOrStudent == EMPLOYEE_TYPE){
      //p = curr->person;
      printf("%-16s %-16s %8d %4d %7.2f \n", curr->person.firstName, curr->person.familyName, curr->person.id,
	     curr->person.emp.yearsOService, curr->person.emp.salary);
    }
    curr = curr->next;
  }
  

}


/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


unsigned int listSize(ListNode *head)
{
	// add code
  ListNode *curr;
  unsigned int count;

  count = 0;
  curr = head;
  //going through list, increasing count
  while (curr != NULL){
    count++;
    curr = curr->next;   
  }

  return count;

}




/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL


*/
int copyList(ListNode *head, ListNode **newListHead)

{
  ListNode *prev,*curr,*newCurr,*newPrev;
  
  prev = NULL;
  curr = head;
  newCurr = *newListHead;

  //*newListHead = malloc(sizeof(ListNode));
  *newListHead = head;

  //copies info from list to new list
  while (curr != NULL){
    prev = curr;
    curr = curr->next;
    newCurr = prev;
    newCurr->next = curr;
  }
  if (curr == NULL){
    return 1;
  }
  curr->next = NULL;
  return 0;


 
}
/************************************************************************/
/*
Purpose: copies the list
input
head - the head of the list

output
newListHead - the header of the newly created list

return
0 if successful
1 if failed

Assumptions:
1. newListHead is not NULL

*/
int copyListRecursive(ListNode *head, ListNode **newListHead)
{
  //ListNode *curr;
  //curr = head;
  if (head == NULL){
    return 1;
  }

  head = *newListHead; //copying head to the new head
  
  copyListRecursive(head->next, &(*newListHead)->next); //recursively copying next nodes
  return 0;

  

}

/************************************************************************/
/*
Purpose: removes all the nodes that have student data from the list
input
head - the head of the list

output
head the modified list

return
0 if successful
1 if failed

Assumptions
1. Function has to be robuse enough to handle cases where head is NULL or the list is empty

*/

int removeStudents(ListNode **head)

{
   
  ListNode *curr,*prev;
  prev = NULL;
  curr = *head;
  if (curr == NULL){
    return 1;
  }
  //check if student, if student then remove and free
  while(curr != NULL){
    if (curr->person.empOrStudent == STUDENT_TYPE){
      if(curr == *head){
	//*head = curr->next;
	//	free(curr);
	//curr = *head;
      }
      // prev->next = curr->next;
      // free(curr);
      //curr = prev->next;
    }
    prev = curr;
    curr = curr->next;
  }

  //free(curr);

  return 0;
  
  

}

void generalTraverse(ListNode *head, void(*printStudentPtr)(PersonInfo *person)){
  ListNode *p = NULL;
  PersonInfo *tempPerson = NULL;

  //traversing through list, printing students
  for (p = head; p!= NULL; p = p->next){
    *tempPerson = p->person;
    printStudentPtr(tempPerson);
  }
}

void printStudentPtr(PersonInfo *person){
  //check if student, then print
  if (person->empOrStudent == STUDENT_TYPE){
    printf("%-16s %-16s %8d %4d %7.2f \n", person->firstName, person->familyName, person->id,
	   person->emp.yearsOService, person->emp.salary);
  }
  
}
					

