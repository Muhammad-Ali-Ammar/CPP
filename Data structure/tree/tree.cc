
/**************************************************************************/
/* Filename						: Tree.c */
/* Author  	    				: Muhammad (Ali) Ammar */
/* Date 						: Feb 16 2024
 */
/* Version 	 					: V01 */
/**************************************************************************/

/********************************** Includes
 * *********************************************/

#include "tree.hpp"

#include <bits/stdc++.h>

/********************************** Data Type Declarations
 * ****************************/

/********************************** Macros Declarations
 * *******************************/

/********************************** Macros Function Declarations
 * *********************/

/******************************* Software Interfaces Implementation
 * *******************/

/**** Constructor */
template <typename treeDataType>
treeNode<treeDataType>::treeNode() : right(nullptr), left(nullptr) {}

template <typename treeDataType>
treeNode<treeDataType>::treeNode(treeDataType Copy_Data)
    : data(Copy_Data), right(nullptr), left(nullptr) {}

template <typename treeDataType>
treeNode<treeDataType>::~treeNode() {
  if (right != nullptr) {
    delete right;
  }

  if (left != nullptr) {
    delete left;
  }
}

/* Tree Part */
template <typename treeDataType>
Tree<treeDataType>::Tree() : root(nullptr) {}

template <typename treeDataType>
Tree<treeDataType>::~Tree() {
  if (root) delete root;
}

/* tree functions */

template <typename treeDataType>
void Tree<treeDataType>::BST_addNode(treeDataType Copy_Data) {
  nodeNumber++;

  if (root == nullptr) {
    addRootNode(Copy_Data);
  } else {
    treeNode<treeDataType>* newPtr = new treeNode<treeDataType>(Copy_Data);
    treeNode<treeDataType>* currentParent = root;
    bool flag = true;
    while (flag == true) {
      if (Copy_Data <= (currentParent->data)) {
        if (currentParent->left != nullptr) {
          currentParent = currentParent->left;
        } else {
          flag = false;
          currentParent->left = newPtr;
        }

      } else {
        if (currentParent->right != nullptr) {
          currentParent = currentParent->right;
        } else {
          flag = false;
          currentParent->right = newPtr;
        }
      }
    }
  }
}

template <typename treeDataType>
void Tree<treeDataType>::BST_traversePreOrder_recursive() {
  traversePreOrder_recursive(root);
}

template <typename treeDataType>
void Tree<treeDataType>::BST_traverseInOrder_recursive() {
  traverseInOrder_recursive(root);
}

template <typename treeDataType>
void Tree<treeDataType>::BST_traversePostOrder_recursive() {
  traversePostOrder_recursive(root);
}

template <typename treeDataType>
bool Tree<treeDataType>::BST_isDataExisted(treeDataType Copy_Data) {
  treeNode<treeDataType>* ptr = root;
  while (ptr != nullptr) {
    if (ptr->data == Copy_Data) {
      return true;
    } else if (Copy_Data < ptr->data) {
      ptr = ptr->left;
    } else {
      ptr = ptr->right;
    }
  }

  return false;
}

template <typename treeDataType>
bool Tree<treeDataType>::BST_isTreeEmpty() {
  return (this->root == nullptr);
}

template <typename treeDataType>
void Tree<treeDataType>::BST_getMaxData(treeDataType* Address_Result) {
  if (BST_isTreeEmpty() == true) {
    Address_Result = nullptr;
    return;
  }

  else {
    treeNode<treeDataType>* ptr = root;
    while (ptr->right != nullptr) {
      ptr = ptr->right;
    }
    if (Address_Result == nullptr) {
      Address_Result = new treeDataType();
    }
    *Address_Result = ptr->data;
  }
}

template <typename treeDataType>
void Tree<treeDataType>::BST_getMinData(treeDataType* Address_Result) {
  if (BST_isTreeEmpty() == true) {
    Address_Result = nullptr;
    return;
  }

  else {
    treeNode<treeDataType>* ptr = root;
    while (ptr->left != nullptr) {
      ptr = ptr->left;
    }
    if (Address_Result == nullptr) {
      Address_Result = new treeDataType();
    }
    *Address_Result = ptr->data;
  }
}

// template <typename treeDataType>
// void Tree<treeDataType>::BST_getMinData(
//     treeNode<treeDataType>** Address_Result) {
//   if (BST_isTreeEmpty() == true) {
//     Address_Result = nullptr;
//     return;
//   }

//   else {
//     treeNode<treeDataType>* ptr = root;
//     while (ptr->left != nullptr) {
//       ptr = ptr->left;
//     }

//     *Address_Result = ptr;
//   }
// }

template <typename treeDataType>
int Tree<treeDataType>::BST_getHeight_recurise() {
  return (getHeight_recurise(this->root));
}

template <typename treeDataType>
void Tree<treeDataType>::BST_traverseBreadthFirst() {
  if (this->root == nullptr) return;

  queue<treeNode<treeDataType>*> qu;
  qu.push(this->root);

  while (qu.empty() == false) {
    treeNode<treeDataType>* tempNode = qu.front();
    if (tempNode->left != nullptr) qu.push(tempNode->left);
    if (tempNode->right != nullptr) qu.push(tempNode->right);

    cout << tempNode->data << " ";
    qu.pop();
  }
}

template <typename treeDataType>
bool Tree<treeDataType>::BST_isTreeBST_recursive() {
  return (isTreeBST(this->root));
}

template <typename treeDataType>
bool Tree<treeDataType>::BST_isTreeBST_Method2_recursive() {
  // it's for int only
  return (isTreeBST_Method2(this->root, INT_MIN, INT_MAX));
}

template <typename treeDataType>
void Tree<treeDataType>::BST_getInorderSuccessor(treeDataType Copy_Data,
                                                 treeDataType* Address_Result) {
  if (this->root == nullptr) {
    *Address_Result = INT_MIN;
    return;
  }

  treeNode<treeDataType>* curretNode = root;
  treeNode<treeDataType>* anncesstor = nullptr;

  while (curretNode != nullptr) {
    if (curretNode->data > Copy_Data) {
      anncesstor = curretNode;
      curretNode = curretNode->left;
    } else if (curretNode->data < Copy_Data) {
      curretNode = curretNode->right;

    } else {
      // i got the node :

      // case 1, it has right
      if (curretNode->right != nullptr) {
        treeNode<treeDataType>* tempRoot = root;
        root = curretNode->right;
        BST_getMinData(Address_Result);
        root = tempRoot;
      }

      // case 2 , no right
      else {
        if (anncesstor == nullptr)
          *Address_Result = INT_MIN;
        else
          *Address_Result = anncesstor->data;
      }

      return;
    }
  }
}

// template <typename treeDataType>
// void Tree<treeDataType>::BST_FindNode(treeDataType Copy_Data,
//                                       treeDataType** Address_Result) {
//   treeNode<treeDataType>* ptr = root;
//   while (ptr != nullptr) {
//     if (ptr->data == Copy_Data) {
//       *Address_Result = ptr;
//       return;
//     } else if (Copy_Data < ptr->data) {
//       ptr = ptr->left;
//     } else {
//       ptr = ptr->right;
//     }
//   }
//   *Address_Result = nullptr;
// }

template <typename treeDataType>
void Tree<treeDataType>::Task3_Microsoft(treeDataType Copy_LeafId) {
  vector<treeNode<treeDataType>*> v;
  v.push_back(this->root);

  for (int i = 0; i < v.size(); ++i) {
    treeNode<treeDataType>* tempNode = v[i];

    if (tempNode == nullptr) continue;
    v.push_back(tempNode->left);
    v.push_back(tempNode->right);

    if (tempNode->left != nullptr && tempNode->left->data == Copy_LeafId) {
      /* I got the Node now */

      treeNode<treeDataType>* parentNode =
          ((i - 1) / 2 >= 0) ? v[(i - 1) / 2] : nullptr;
      int parentIdx = (i - 1) / 2;

      treeNode<treeDataType>* graendparent =
          (parentNode == nullptr || (parentIdx == 0)) ? nullptr
                                                      : v[(parentIdx - 1) / 2];

      p_Task3_Microsoft(tempNode->left, tempNode, parentNode, graendparent);
      root = tempNode->left;
      return;
    }

    else if (tempNode->right != nullptr &&
             tempNode->right->data == Copy_LeafId) {
      /* I got the Node now */

      treeNode<treeDataType>* parentNode =
          ((i - 1) / 2 >= 0) ? v[(i - 1) / 2] : nullptr;
      int parentIdx = (i - 1) / 2;

      treeNode<treeDataType>* graendparent =
          (parentNode == nullptr || (parentIdx == 0)) ? nullptr
                                                      : v[(parentIdx - 1) / 2];
      root = tempNode->right;
      p_Task3_Microsoft(tempNode->right, tempNode, parentNode, graendparent);

      return;
    }
  }
}

template <typename treeDataType>
int Tree<treeDataType>::Task4_Microsoft() {
  return p_Task4_Microsft(this->root);
}

template <typename treeDataType>
void Tree<treeDataType>::BST_deleteNode(treeDataType Copy_LeafId) {
  this->root = deleteNode(this->root, Copy_LeafId);
}

/**************************** Private Software Interface Implementation
 * ***************/

template <typename treeDataType>
void Tree<treeDataType>::addRootNode(treeDataType Copy_Data) {
  treeNode<treeDataType>* ptr = new treeNode<treeDataType>(Copy_Data);

  this->root = ptr;
}

template <typename treeDataType>
void Tree<treeDataType>::traverseInOrder_recursive(
    treeNode<treeDataType>* currentNode) {  // left root right

  if (currentNode == nullptr) return;
  traverseInOrder_recursive(currentNode->left);
  cout << currentNode->data << endl;

  traverseInOrder_recursive(currentNode->right);
}

template <typename treeDataType>
void Tree<treeDataType>::traversePreOrder_recursive(
    treeNode<treeDataType>* currentNode) {  // root left  right

  if (currentNode == nullptr) return;
  cout << currentNode->data << endl;
  traverseInOrder_recursive(currentNode->left);
  traverseInOrder_recursive(currentNode->right);
}
template <typename treeDataType>
void Tree<treeDataType>::traversePostOrder_recursive(
    treeNode<treeDataType>* currentNode) {  // left  right root

  if (currentNode == nullptr) return;
  traverseInOrder_recursive(currentNode->left);
  traverseInOrder_recursive(currentNode->right);
  cout << currentNode->data << endl;
}

template <typename treeDataType>
int Tree<treeDataType>::getHeight_recurise(
    treeNode<treeDataType>* currentNode) {
  int local_Left = 0;
  int local_Right = 0;
  if (currentNode == nullptr) return -1;

  local_Left = 1 + getHeight_recurise(currentNode->left);
  local_Right = 1 + getHeight_recurise(currentNode->right);

  return max(local_Left, local_Right);

  /*
    return 1+max( getHeight_recurise(currentNode->left),
    getHeight_recurise(currentNode->right));

  */
}

template <typename treeDataType>
treeNode<treeDataType>* Tree<treeDataType>::deleteNode(
    treeNode<treeDataType>* currentNode, treeDataType Copy_Data) {
  if (currentNode == nullptr) return currentNode;

  if (currentNode->data < Copy_Data)
    currentNode->right = deleteNode(currentNode->right, Copy_Data);
  else if (currentNode->data > Copy_Data)
    currentNode->left = deleteNode(currentNode->left, Copy_Data);

  else {
    /* it's the required Node */

    /////////////////////////////////////////////////////////////////////////
    // case, it's a leaf
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
      // delete currentNode;
      return nullptr;
    }

    /////////////////////////////////////////////////////////////////////////
    // case 2
    else if (currentNode->left == nullptr) {
      treeNode<treeDataType>* tempNode = currentNode->right;
      // delete currentNode; // delete in the next line by destructor
      return tempNode;
    }

    else if (currentNode->right == nullptr) {
      treeNode<treeDataType>* tempNode = currentNode->left;
      // delete currentNode; // delete in the next line by destructor
      return tempNode;
    }

    /////////////////////////////////////////////////////////////////////////
    // case 3 ,it has 2 childs
    else {
      treeNode<treeDataType>* tempRoot = root;
      root = currentNode->right;  // just modify the root to get the min of
                                  // the new tree = subtree
      BST_getMinData(&(currentNode->data));
      root = tempRoot;  // return the root to the original
      currentNode->right = deleteNode(currentNode->right, currentNode->data);
    }
  }
  return currentNode;
}

template <typename treeDataType>
bool Tree<treeDataType>::isTreeBST(treeNode<treeDataType>* currentNode) {
  if (currentNode == nullptr) return true;
  bool answer = true;

  /*
   take action, then vist sub tree
  */

  ////////////////////////////////////////
  // you can make it funciton == isLess
  if (currentNode->left != nullptr) {
    if (isSubTreeOperation(
            currentNode->left, currentNode->data,
            [](treeDataType x, treeDataType y) { return x <= y; }) == false)
      return false;
  }
  ////////////////////////////////////////

  ////////////////////////////////////////
  // you can make it funciton == is greater
  if (currentNode->right != nullptr) {
    if (isSubTreeOperation(
            currentNode->right, currentNode->data,
            [](treeDataType x, treeDataType y) { return x > y; }) == false)
      return false;
  }
  ////////////////////////////////////////
  answer &= isTreeBST(currentNode->left);
  answer &= isTreeBST(currentNode->right);

  /*
    emta kol da btrue ?
    if (1 true , 2 true , 3 true , 4 true) .. so
    return (isLess && isGreater && isTreeBST(left)&& isTreeBST(right))

  */
  return answer;
}

template <typename treeDataType>
bool Tree<treeDataType>::isTreeBST_Method2(treeNode<treeDataType>* currentNode,
                                           treeDataType Copy_MinBoundary,
                                           treeDataType Copy_MaxBoundary) {
  if (currentNode == nullptr) return true;

  return (currentNode->data > Copy_MinBoundary &&
          currentNode->data <= Copy_MaxBoundary &&
          isTreeBST_Method2(currentNode->left, Copy_MinBoundary,
                            currentNode->data) &&
          isTreeBST_Method2(currentNode->right, currentNode->data,
                            Copy_MaxBoundary));
}

template <typename treeDataType>
bool Tree<treeDataType>::isSubTreeOperation(
    treeNode<treeDataType>* currentNode, treeDataType Copy_Data,
    function<bool(treeDataType first, treeDataType second)> op) {
  bool answer = true;
  if (currentNode == nullptr) return true;

  if (op(currentNode->data, Copy_Data) == false) return false;  // A

  answer &= isSubTreeOperation(currentNode->left, Copy_Data, op);   // B
  answer &= isSubTreeOperation(currentNode->right, Copy_Data, op);  // C

  return answer;

  /*
    true if A true, B true, C true
    return (A && B && C )
  */
}

template <typename treeDataType>
void Tree<treeDataType>::p_Task3_Microsoft(
    treeNode<treeDataType>* childNode, treeNode<treeDataType>* currNode,
    treeNode<treeDataType>* parentNode, treeNode<treeDataType>* graendparent) {
  /*
    3 steps

    1- child -> node
    2- node-> parent
    3- parent ->grandparent
  */

  childNode->left = currNode;  // 1
  if (currNode->left == childNode) {
    currNode->left = parentNode;
  } else if (currNode->right == childNode) {
    currNode->right = parentNode;
  }

  if (parentNode == nullptr) return;

  if (parentNode->left == currNode) {
    parentNode->left = graendparent;
  } else if (parentNode->right == currNode) {
    parentNode->right = graendparent;
  }
}

template <typename treeDataType>
int Tree<treeDataType>::p_Task4_Microsft(treeNode<treeDataType>* currentNode) {
  int answer = 0;

  if (currentNode == nullptr) return 0;

  /* the four steps first */
  if (currentNode->left != nullptr) {
    if (currentNode->left->left != nullptr) answer++;
    if (currentNode->left->right != nullptr) answer++;
  }
  if (currentNode->right != nullptr) {
    if (currentNode->right->left != nullptr) answer++;
    if (currentNode->right->right != nullptr) answer++;
  }

  answer += p_Task4_Microsft(currentNode->left);
  answer += p_Task4_Microsft(currentNode->right);

  // (void) p_Task4_Microsft(currentNode->left);   // if static int answer
  // (void) p_Task4_Microsft(currentNode->right); // if static int answer

  return answer;
}
