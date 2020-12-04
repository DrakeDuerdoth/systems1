#include "headers.h"

int isNil(const struct TreeNode*nodePtr)
{
  return(nodePtr->value_ == 0);
}


static void leftRotate(struct TreeNode**rootPtrPtr,
	       struct TreeNode*nodePtr)
{
  struct TreeNode* newParent = nodePtr->rightPtr_;

  nodePtr->rightPtr_= newParent->leftPtr_;

  if  ( isNil(newParent->leftPtr_) )
    newParent->leftPtr_->parentPtr_= nodePtr;

  newParent->parentPtr_= nodePtr->parentPtr_;

  if  ( isNil(nodePtr->parentPtr_) )
    *rootPtrPtr = newParent;
  else
    if  ( nodePtr == nodePtr->parentPtr_->leftPtr_ )
      nodePtr->parentPtr_->leftPtr_= newParent;
    else
      nodePtr->parentPtr_->rightPtr_= newParent;

  newParent->leftPtr_= nodePtr;
  nodePtr->parentPtr_= newParent;
}


static void rightRotate(struct TreeNode**rootPtrPtr,
		struct TreeNode*nodePtr
		)
{
  struct TreeNode*newParent= nodePtr->leftPtr_;

  nodePtr->leftPtr_= newParent->rightPtr_;

  if  ( isNil(newParent->rightPtr_) )
    newParent->rightPtr_->parentPtr_= nodePtr;

  newParent->parentPtr_= nodePtr->parentPtr_;

  if  ( isNil(nodePtr->parentPtr_) )
    *rootPtrPtr= newParent;
  else
    if  ( nodePtr == nodePtr->parentPtr_->rightPtr_ )
      nodePtr->parentPtr_->rightPtr_= newParent;
    else
      nodePtr->parentPtr_->leftPtr_= newParent;

  newParent->rightPtr_= nodePtr;
  nodePtr->parentPtr_= newParent;
}


static void treeInsert(struct TreeNode*nilPtr,
	       struct TreeNode**rootPtrPtr,
	       unsigned int value
	       )
{
  struct TreeNode*runsParent= nilPtr;
  struct TreeNode*run= *rootPtrPtr;

  while  (run != nilPtr)
    {
      runsParent  = run;

      if  (value == run->value_)
	{
	  run->count_++;
	  return;
	}

      if  (value < run->value_)
	run = run->leftPtr_;
      else
	run = run->rightPtr_;
    }

  struct TreeNode*created =
    run     = (struct TreeNode*)
    malloc(sizeof(struct TreeNode));

  run->value_= value;
  run->count_= 1;
  run->parentPtr_= runsParent;
  run->leftPtr_= nilPtr;
  run->rightPtr_= nilPtr;

  if  (runsParent == nilPtr)
    *rootPtrPtr= run;
  else
    if  (value < runsParent->value_)
      runsParent->leftPtr_= run;
    else
      runsParent->rightPtr_= run;

  run->isBlack_= 0;

  while  ( (run != *rootPtrPtr)  &&  !run->parentPtr_->isBlack_ )
    {
      struct TreeNode*parent          = run->parentPtr_;
      struct TreeNode*grandParent     = parent->parentPtr_;

      if  ( parent == grandParent->leftPtr_ )
	{
	  struct TreeNode*rightAunt = grandParent->rightPtr_;

	  if  ( !rightAunt->isBlack_ )
	    {
	      parent->isBlack_= 1;
	      rightAunt->isBlack_= 1;
	      grandParent->isBlack_= 0;
	      run = grandParent;
	    }
	  else
	    {

	      if  ( run == parent->rightPtr_ )
		{
		  run = parent;
		  leftRotate(rootPtrPtr,run);
		}

	      run->parentPtr_->isBlack_= 1;
	      run->parentPtr_->parentPtr_->isBlack_= 0;
	      rightRotate(rootPtrPtr, run->parentPtr_->parentPtr_ );
	    }

	}
      else
	{
	  struct TreeNode*leftAunt = grandParent->leftPtr_;

	  if  ( !leftAunt->isBlack_ )
	    {
	      parent->isBlack_= 1;
	      leftAunt->isBlack_= 1;
	      grandParent->isBlack_= 0;
	      run = grandParent;
	    }
	  else
	    {

	      if  ( run == parent->leftPtr_ )
		{
		  run = parent;
		  rightRotate(rootPtrPtr,run);
		}
	      run->parentPtr_->isBlack_= 1;
	      run->parentPtr_->parentPtr_->isBlack_= 0;
	      leftRotate(rootPtrPtr, run->parentPtr_->parentPtr_ );
	    }

	}

    }

  //  II.C.  Update tree as a whole:
  (*rootPtrPtr)->isBlack_= 1;

  //  III.  Finished:
}


struct TreeNode* countWithTree()
{
  unsigned int i;
  unsigned int j;
  struct TreeNode*nilPtr= (struct TreeNode*)
    malloc(sizeof(struct TreeNode));
  struct TreeNode*rootPtr= nilPtr;

  nilPtr->value_= 0;
  nilPtr->isBlack_= 1;
  nilPtr->count_= 0;
  nilPtr->leftPtr_= nilPtr;
  nilPtr->rightPtr_= nilPtr;
  nilPtr->parentPtr_= nilPtr;

  for  (i = 2;  i < maximum;  i++)
    for  (j = 2;  j < maximum-1;  j++)
      {
	unsigned int value= gcd(i,j);

	treeInsert(nilPtr,&rootPtr,value);
      }

  return(rootPtr);
}


void printTree(const struct TreeNode*nodePtr
	      )
{
  if(isNil(nodePtr)) return;
  printTree(nodePtr->leftPtr_);
  printf("%d", nodePtr->value_);
  printTree(nodePtr->rightPtr_);
}


void disposeOfTree(struct TreeNode*nodePtr
		  )
{
  if  ( isNil(nodePtr) )
    return;

  disposeOfTree(nodePtr->leftPtr_);
  disposeOfTree(nodePtr->rightPtr_);
  free(nodePtr);
}
