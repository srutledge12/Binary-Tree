// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode * buildUtil(int inArray[], int postArray[], int start, int end, int* pIndex) 
{ 
    // Base case 
    if (start > end)
    { 
        return NULL; 
    }
  
    TreeNode * tr = malloc(sizeof(TreeNode)); 
    tr -> value = postArray[*pIndex];
    tr -> left = NULL;
    tr -> right = NULL;
    (*pIndex = *pIndex - 1); 
  
    if (start == end)
    { 
      return tr; 
    }
  
    int i; 
    for (i = start; i <= end; i++) 
    { 
      if (inArray[i] == tr->value) 
      break; 
    } 
    int iIndex = i;
  
    tr->right = buildUtil(inArray, postArray, iIndex + 1, end, pIndex); 
    tr->left = buildUtil(inArray, postArray, start, iIndex - 1, pIndex); 
  
    return tr; 
} 

Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tree = malloc(sizeof(Tree));
  int pIndex = size - 1; 
  int start = 0;
  int end = size - 1;
  tree -> root = buildUtil(inArray, postArray, start, end, &pIndex); 
  return(tree);
}
#endif

#ifdef TEST_PRINTPATH
int helpPrint(TreeNode * node, int val)
{
  if(node == NULL)
  {
    return(0);
  }
  if(node->value == val)
  {
    printf("%d\n", val);
    return(1);
  }

  else if(helpPrint(node->right, val) == 1)
  {
    printf("%d\n", node->value);
    return(1);
  }

  else if(helpPrint(node->left, val) == 1)
  {
    printf("%d\n", node->value);
    return(1);
  }

  return(0);
}
void printPath(Tree * tr, int val)
{
  helpPrint(tr->root, val);
}


#endif
