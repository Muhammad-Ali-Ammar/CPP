/**************************************************************************/
/* Filename						: Tree.h */
/* Author  	    				: Muhammad (Ali) Ammar */
/* Date 						: Feb 16 2024
 */
/* Version 	 					: V01 */
/**************************************************************************/

#ifndef _TREE_HPP_
#define _TREE_HPP_

/********************************** Includes
 * *********************************************/
#include <bits/stdc++.h>

using namespace std;

/********************************** Macros Declarations
 * *******************************/

/********************************** Macros Function Declarations
 * *********************/

/********************************** Data Type Declarations
 * ****************************/

template <typename treeDataType>
class treeNode {
 public:
  treeDataType data;
  treeNode* right;
  treeNode* left;

  /* constructor*/
  treeNode();
  treeNode(treeDataType Copy_Data);

  ~treeNode();
};

template <typename treeDataType>
class Tree {
 private:
  treeNode<treeDataType>* root;
  int nodeNumber = 0;

  void addRootNode(treeDataType Copy_Data);
  void traverseInOrder_recursive(
      treeNode<treeDataType>* currentNode);  // left root right
  void traversePostOrder_recursive(
      treeNode<treeDataType>* currentNode);  // left  right root
  void traversePreOrder_recursive(
      treeNode<treeDataType>* currentNode);  // root left  right

  int getHeight_recurise(treeNode<treeDataType>* currentNode);
  bool isTreeBST(treeNode<treeDataType>* currentNode);

  treeNode<treeDataType>* deleteNode(treeNode<treeDataType>* currentNode,
                                     treeDataType Copy_Data);

  bool isTreeBST_Method2(treeNode<treeDataType>* currentNode,
                         treeDataType Copy_MinBoundary,
                         treeDataType Copy_MaxBoundary);

  bool isSubTreeOperation(
      treeNode<treeDataType>* currentNode, treeDataType Copy_Data,
      function<bool(treeDataType first, treeDataType second)> op);

  void p_Task3_Microsoft(treeNode<treeDataType>* childNode,
                         treeNode<treeDataType>* currNode,
                         treeNode<treeDataType>* parentNode,
                         treeNode<treeDataType>* graendparent);

  int p_Task4_Microsft(treeNode<treeDataType>* currentNode);

 public:
  /* constructor */
  Tree();
  ~Tree();

  /* tree functions */
  void BST_addNode(treeDataType Copy_Data);

  bool BST_isDataExisted(treeDataType Copy_Data);
  bool BST_isTreeEmpty();

  void BST_getMaxData(treeDataType* Address_Result);
  void BST_getMinData(treeDataType* Address_Result);
  // void BST_getMinData(treeNode<treeDataType>** Address_Result);

  void BST_deleteNode(treeDataType Copy_Data);

  void BST_traverseInOrder_recursive();    // left root right
  void BST_traversePostOrder_recursive();  // left right root
  void BST_traversePreOrder_recursive();   // root, left, right
  void BST_traverseBreadthFirst();         // level first

  int BST_getHeight_recurise();  // O(N)
  bool BST_isTreeBST_recursive();
  bool BST_isTreeBST_Method2_recursive();

  void BST_getInorderSuccessor(treeDataType Copy_Data,
                               treeDataType* Address_Result);

  // void BST_FindNode(treeDataType Copy_Data, treeDataType** Address_Result);

  /*
    vector as queue
    3 steps after you find the node

  */
  void Task3_Microsoft(treeDataType Copy_LeafId);
  int Task4_Microsoft();
};

/********************************** Software Interfaces Declarations
 * *******************/

#endif