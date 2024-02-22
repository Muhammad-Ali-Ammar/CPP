/**************************************************************************/
/* Filename						: Tree.c */
/* Author  	    				: Muhammad (Ali) Ammar */
/* Date 						: Feb 16 2024
 */
/* Version 	 					: V01 */
/******************************************************************/

/********************************** Includes
 * *********************************************/

#include <bits/stdc++.h>

#include "tree.cc"

/********************************** Data Type Declarations
 * ****************************/

using namespace std;
/********************************** Macros Declarations
 * *******************************/

/********************************** Macros Function Declarations
 * *********************/

/******************************* Software Interfaces Implementation
 * *******************/
int main() {
  Tree<int> t1;
  t1.BST_addNode(7);
  t1.BST_addNode(9);
  t1.BST_addNode(4);
  t1.BST_addNode(3);
  t1.BST_addNode(8);
  t1.BST_addNode(5);
  t1.BST_addNode(2);

  t1.BST_deleteNode(5);
  t1.BST_traverseBreadthFirst();
}

/**************************** Private Software Interface Implementation
 * **************/
