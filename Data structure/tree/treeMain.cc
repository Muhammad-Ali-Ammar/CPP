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
  t1.BST_addNode(15);
  t1.BST_addNode(10);
  t1.BST_addNode(8);
  t1.BST_addNode(12);

  int x;
  t1.BST_getInorderSuccessor(15, &x);
  cout << x << endl;
}

/**************************** Private Software Interface Implementation
 * **************/
