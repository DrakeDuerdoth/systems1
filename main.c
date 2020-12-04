#include "headers.h"

const int TEXT_LEN = 256;

unsigned int maximum= 10000;

unsigned int gcd (unsigned int a,unsigned int b)
{
  if  (a < b)
    {
      unsigned int temp= a;

      a = b;
      b = temp;
    }

  unsigned int mult = a/b;
  unsigned int remain = a - mult*b;

  return( (remain == 0) ? b : gcd(b,remain) );
}


int main()
{
  int choice;

    do
      {
	char text[TEXT_LEN];

	printf("Which would you like:\n"
	          "(1) Count with linked-list,\n"
	          "(2) Count with binary tree\n"
	          "Your choice: ");
	fgets(text,TEXT_LEN,stdin);
	choice = strtol(text,NULL,10);
      }
    while  ((choice < 1) || (choice > 2));

    switch  (choice)
      {
      case 1 :
	{
	  struct ListNode* list= countWithList();

	  printList(list);
	  disposeOfList(list);
	}
	break;

      case 2 :
	{
	  struct TreeNode* tree= countWithTree();

	  printTree(tree);
	  disposeOfTree(tree);
	}
	break;

      default :
	break;
      }

    return(EXIT_SUCCESS);
}
