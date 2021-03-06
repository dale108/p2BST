// Author: Dale Berg, CPSC 2430 02
// Filename: BSTx.h
// Assignment: p2, template BST
// Date: 5/7/2019

// Purpose: This is the extra credit file for p2. Everything is identical except
// the additional extra credit functions - tests for the extra credit functions
// are included in p2x.cpp.

#ifndef BST_H
#define BST_H

#include <string>
#include<iostream>
#include<queue>
#include <sstream>
using namespace std;

template <typename T>
class BST {
public:
   // constructor for tmeplate BST
   // pre:
   // post: constructs new template BST object with node set to null
   BST(); // done

   // destroctor for BST
	// pre: BST exists
	// post: The tree is destroyed
   ~BST(); // done

   // copy constructor
   // pre: BST object passed in
   // post: values from BST passed as an argument copied to current BST object
   BST(const BST &); // done

   // overloaded assignment operator.
   //pre: Right hand side of assignment operator is BST object of same data type
   //post: Bst object on left side of assignment operator becomes copy of
   // BST object on the right side of operator.
	BST& operator=(const BST &);

   //inserts node at correct place in BST hierarchy
   //pre: element to be added passed as an argument.
   //post: new node with with value passed as argument added to BST.
	void insert(T); // done


	bool contains(T); // done
   //returns boolean value representing whether or not the tree contains the
   // value passed as argument.
   //pre: Value to be searched for in BST
   //post: Boolean value representing whether the element passed as an argument
   // is an element in the tree.

   // Removes an element from the tree
	//pre: Pass in valu of element to be remo e from tree.
	//post:
	void remove(T); // done

   // Checks if the tree is empty
	//post: Returns boolean value representing if the tree has 1 or more values.
   // A newly instatiated tree, which has not been added to is an empty tree.
   bool empty(); // done

   // Returns the number of nodes in the binary search tree.
	//post: returns integer number of nodes in the tree.
   int size();  // done

   // Returns the number of nodes in the tree which have no child nodes.
   //post: returns integer number of nodes in the tree with no children.
   int getLeafCount(); // done

   // returns the height of the tree, where height is defined as the longest
   // path from the root to any leaf node.
	//post: returns integer height of tree.
   int getHeight(); // done

   // Takes a template element (T) and finds the level of the tree on which that
   // element is located.
	//pre: Template (T) argument of element to be found.
	//post: returns integer representing which level of the tree contains
   // element value passed as argument.
   int getLevel(T); // done


   // Gets a string of all the values in the tree, in "in order" sequence.
   //post: returns a string representation of all values in the tree in
   // inorder sequence, seperated by spaces, as a string.
   string getInOrderTraversal(); // done


   // Creates and returns string of values in pre order sequence.
   //pre:
   //post: returns a string representation of all values in the tree seperated
   // by spaces in preorder sequence as a string.
   string getPreOrderTraversal(); // done

   // Creates and returns string of values in post order sequence.
   //pre:
   //post: returns a string representation of all values in the tree seperated
   // by spaces in preorder sequence as a string.
   string getPostOrderTraversal(); // done

   // Given a T value, returns a stirng of all values which are ancestors
   //to the node containing that value.
	//pre: A vaild T element is passed, which is the same data type as was
   // declared in the initialization of the tree.
	//post: returns a stirng representation of the data fields of all nodes
   // which are ancestors to the node containing the vlaue of the argument passed
   string getAncestors(T); // done

   // Creates and returns a string of values contained in the tree, by order
   // of level. The value at the root will be appended first, followed by
   //post: returns a string representation of all values in the tree seperated
   // by spaces in preorder sequence as a string.
   string getLevelOrder(); // EC function!

   // determines and returns the width of the tree. Width is defined by the
   // level with the greatest number of nodes.
   //post: returns an integer representing the horizontal width of the tree
   // at it's widest point.
   int getWidth(); // EC function!

private:
   struct Node {
      T value;
      Node *left;
      Node *right;

      // private by default
      Node( T );
   };

   Node* root;

private:

   //***************************
   // PRIVATE HELPER FUNCTIONS *
   //***************************

   void deleteNodes( Node* root );
   bool contains( Node* root );
   int countLeaves( Node* root, int &counter );
   int countNodes( Node* root, int &counter);
   bool contains( Node* root, T element );
   Node* copyTree( Node* root );
   void deleteNode(Node*& ptr);
   void getAncestors( Node* root, stringstream &ss, T target );
   int getHeight( Node* root );
   int getLevel(Node* root, T element, int& counter, bool& flag);
   Node* insertNode( Node* root, T element );
   Node* inOrderSucessor( Node* root );
   void getPostOrderTraversal(Node* root, stringstream &ss);
   void getPreOrderTraversal(Node* root, stringstream &ss);
   void getInOrderTraversal(Node* root, stringstream& ss);
   typename BST<T>::Node* remove( Node* &root, T element);
};


//*********************
// BIG 4              *
//*********************


template<typename T>
BST<T>::BST() {
   root = nullptr;
}

template<typename T>
BST<T>::BST( const BST& other ) {
      root = copyTree(other.root); // copy uses preorder traversal
}

template<typename T>
BST<T>::Node::Node(T val) {
   left =  nullptr;
   right = nullptr;
   value = val;
}

template<typename T>
BST<T>::~BST() {
   if(root == nullptr) {
      delete root;
   }
   deleteNodes(root);
}

template< typename T>
BST<T>& BST<T>::operator =( const BST<T> &rhs ) {
   if( this != &rhs ) {
      this->deleteNodes(root); // delete nodes uses postporder traversal
      Node* temp = rhs.root;
      root = copyTree(temp);
   }
   return *this;
}

template<typename T>
bool BST<T>::contains( T element ) {
   return contains(root, element);
}

template<typename T>
bool BST<T>::contains( Node* root, T element ) {

   if(root == nullptr) {
      return false;
   }
   if( element < root->value ) {
      return contains(root->left, element);
   }
   else if( element > root->value) {
      return contains(root->right, element);
   }
   return true;
}

// copy tree uses a preorder traversal to make copy of tree
template<typename T>
typename BST<T>::Node* BST<T>::copyTree( Node* root ) {
   if( root ==  nullptr ) {
      return nullptr;
   }
   else {
      Node* copyNode = new Node(root->value);
      copyNode->left = copyTree(root->left);
      copyNode->right = copyTree(root->right);
      return copyNode;
   }
}

// count leaves is helper to getLeafCount
template<typename T>
int BST<T>::countLeaves( Node* root, int &counter ) {

   if(root != nullptr) {
      if((root->right == nullptr) && (root->left == nullptr)) {
         ++counter;
      }
      countLeaves(root->left, counter);
      countLeaves(root->right, counter);
   }
   return counter;
}

// uses preorder traversal with a counter passed by reference to count nodes
// in tree
template<typename T>
int BST<T>::countNodes( Node* root, int &counter) {
   if( root != nullptr )  {
      ++counter;
      countNodes(root->left, counter);
      countNodes(root->right, counter);
   }
   return counter;
}

// uses postorder traversal to delete nodes in tree
template<typename T>
void BST<T>::deleteNodes( Node* root ) {
   if(root != nullptr) {
      deleteNodes(root->right);
      deleteNodes(root->left);
      delete root;
   }
}

template<typename T>
bool BST<T>::empty() {
   if(root == nullptr) {
      return true;
   }
   return false;
}

template<typename T>
string BST<T>::getAncestors( T target ) {
   stringstream ss;
   getAncestors(root, ss, target);
   return ss.str();
}

// build string of ancestors to node by passing stringstream by reference
template<typename T>
void BST<T>::getAncestors( Node* root, stringstream &ss, T target ) {
   // we only want to build onto the string if the root value != target value
   if(root != nullptr) {
      if( root->value > target ) {
         ss << root->value << " ";
         getAncestors(root->left, ss, target);
      }
      else if(root->value < target ) {
         ss << root->value << " ";
         getAncestors(root->right, ss, target);
      }
   }
}

template<typename T>
int BST<T>::getHeight() {
   return getHeight(root);
}

template<typename T>
int BST<T>::getHeight( Node* root ) {
   if(root == nullptr) {
      return 0;
   }

   int leftHeight = getHeight(root->left);
   int rightHeight = getHeight(root->right);
   // want ti return whichever branch is larger, + 1 for root
   return 1 + max(leftHeight, rightHeight);
}

template<typename T>
int BST<T>::getLeafCount() {
   int counter = 0;
   return countLeaves(root, counter);
}

template<typename T>
int BST<T>::getLevel( T element ) {
   int counter = 0;
   bool flag = false;
   int level = getLevel(root, element, counter, flag);
   if( flag ) {
      return level;
   }
   else {
      return -1;
   }
}

template<typename T>
int BST<T>::getLevel(Node* root, T element, int& counter, bool& flag) {
   if(root != nullptr) {
      ++counter;
      if( element < root->value ) {
         getLevel(root->left, element, counter, flag);
      }
      else if( element > root->value ) {
         getLevel(root->right, element, counter, flag);
      }
         if( element == root->value) {
            flag = true;
         }
      }
   return counter;
}

// EC function
template<typename T>
string BST<T>::getLevelOrder() {
   if( root != nullptr ) {
      ostringstream ss;
      queue<Node *> que;
      que.push(root);

      // while the ques has values, we can pop from front
      while( que.empty() == false ) {
         Node* temp = que.front();
         ss << temp->value << " ";
         que.pop();


         if(temp->left != nullptr ) {
            que.push(temp->left);
         }

         if(temp->right != nullptr ) {
            que.push( temp->right );

         }
      }
      return  ss.str();
   }
   return " "; // empty tree case
}


// All traversals below use stirngstream objects passed by reference to
// build strings of values in respective sequences
template<typename T>
string BST<T>::getInOrderTraversal() {
   stringstream ss;
   getInOrderTraversal( root, ss);
   return ss.str();
}

template<typename T>
void BST<T>::getInOrderTraversal(Node* root, stringstream& ss) {
   if(root != nullptr) {
      getInOrderTraversal(root->left, ss);
      ss << root->value << " ";
      getInOrderTraversal(root->right, ss);
   }
}

template<typename T>
string BST<T>::getPostOrderTraversal() {
   stringstream ss;
   getPostOrderTraversal(root, ss);
   return ss.str();
}

template<typename T>
void BST<T>::getPostOrderTraversal(Node* root, stringstream &ss) {
   if(root != nullptr) {
      getPostOrderTraversal(root->left, ss);
      getPostOrderTraversal(root->right, ss);
      ss << root->value << " ";
   }
}

template<typename T>
string BST<T>::getPreOrderTraversal() {
   stringstream ss;
   getPreOrderTraversal(root, ss);
   return ss.str();
}

template<typename T>
void BST<T>::getPreOrderTraversal(Node* root, stringstream& ss) {
   if(root != nullptr) {
      ss << root->value << " ";
      getPreOrderTraversal(root->left, ss);
      getPreOrderTraversal(root->right, ss);
   }
}

// EC function
template< typename T>
int BST<T>::getWidth() {

   Node* curr = root;

   if( curr == nullptr ) {
      return 0;
   }

   queue<Node *> q;
   q.push(curr);

   int level = 0;
   int max = 0; //INT_MIN

   bool isDone = false;

   while(!isDone) {

      int nodeCount = q.size();

      if(nodeCount == 0) {
         isDone = true;
         continue;
      }

      if( nodeCount >  max ) {
         max = nodeCount;
      }

      while (nodeCount > 0) {
         Node *n = q.front();
         q.pop();
         if( n->left != nullptr) {
            q.push(n->left);
         }
         if(n->right != nullptr) {
            q.push(n->right);
         }
         nodeCount--;
      }

      level++;
   }
   return max;
}


template<typename T>
typename BST<T>::Node* BST<T>::inOrderSucessor( Node* root ) {
   Node* curr = root;
   while(curr->left != nullptr) {
      curr = curr->left;
   }
   return curr;
}

template<typename T>
void BST<T>::insert( T element ) {
   root = insertNode(root, element);
}


template<typename T>
typename BST<T>::Node* BST<T>::insertNode( Node* root, T element ) {

   if( root == nullptr ) {
      return new Node(element);
   }

   if( element < root->value ) {
      root->left = insertNode(root->left, element);
   }
   else if( element > root->value ) {
      root->right = insertNode(root->right, element);
   }

   return root;
}



template<typename T>
void BST<T>::remove( T element ) {
   remove(root, element);
}

template<typename T>
typename BST<T>::Node* BST<T>::remove( Node* &root, T element ) {
   if( root == nullptr) {
      return root;
   }
   if( element < root->value ) {
      root->left = remove( root->left, element );
   }
   else if(element > root->value) {
      root->right = remove( root->right, element );
   }
   else {
      if( root->left == nullptr ) {
         Node* temp = root->right;
         delete root;
         return temp;
      }
      else if( root->right == nullptr ) {
         Node* temp = root->left;
         delete root;
         return temp;
      }

      Node* temp = inOrderSucessor(root->right);

      root->value = temp->value;

      root->right = remove(root->right, temp->value);
   }
   return root;
}

template<typename T>
int BST<T>::size() {
   int counter = 0;
   return countNodes(root, counter);
}

#endif
