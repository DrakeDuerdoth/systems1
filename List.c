#include "headers.h"



static void listInsert(struct ListNode**listPtrPtr,
		       struct ListNode**endPtrPtr,
		       unsigned int value
		       )
{
  struct ListNode* run = *listPtrPtr;

  for  ( ;  run != NULL;  run = run->nextPtr_)
    if  (run->value_ == value)
      {
	run->count_++;
	return;
      }


  struct ListNode* newNodePtr= (struct ListNode*)
                                malloc(sizeof(struct ListNode));

  newNodePtr->value_= value;
  newNodePtr->count_= 1;

  if  (*listPtrPtr == NULL) *listPtrPtr= newNodePtr;
  else(*endPtrPtr)->nextPtr_= newNodePtr;
  *endPtrPtr= newNodePtr;
}


struct ListNode* countWithList()
{
  unsigned int i;
  unsigned int j;
  struct ListNode* toReturn = NULL;
  struct ListNode* endPtr = NULL;

  for  (i = 2;  i < maximum;  i++)
    for  (j = 2;  j < maximum-1;  j++)
      {
	unsigned int value= gcd(i,j);

	listInsert(&toReturn,&endPtr,value);
      }

  return(toReturn);
}


void printList(const struct ListNode*nodePtr
	      )
{
  for  (  ;  nodePtr != NULL;  nodePtr = nodePtr->nextPtr_)
    printf("%5u: %5llu times\n",nodePtr->value_,nodePtr->count_);
}


void disposeOfList(struct ListNode*nodePtr
		  )
{
  struct ListNode* nextPtr;

  for  (  ;  nodePtr != NULL;  nodePtr = nextPtr)
    {
      nextPtr= nodePtr->nextPtr_;
      free(nodePtr);
    }
}
