// BST.h
// Add documentation

#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

template <typename T>
class BST {
public:
   BST();
	//
	// pre:
	// post:

   ~BST();
	//
	// pre:
	// post:

   BST(const BST &);
   //
   // pre:
   // post

	BST& operator=(const BST &);
   //
   //pre:
   //post:

	void insert(T);
   //
   //pre:
   //post:

	bool contains(T);
   //
   //pre:
   //post:

	void remove(T);
	//
	//pre:
	//post:

   bool empty();
	//
	//pre:
	//post:

   int size();
	//
	//pre:
	//post:

   int getLeafCount();
	//
	//pre:
	//post:

   int getHeight();
	//
	//pre:
	//post:

   int getLevel(T);
	//
	//pre:
	//post:

   string getInOrderTraversal();
	//
	//pre:
	//post:

   string getPreOrderTraversal();
	//
	//pre:
	//post:

   string getPostOrderTraversal();
	//
	//pre:
	//post:

   string getAncestors(T);
	//
	//pre:
	//post:

private:
   struct Node { 
      T value;
      Node *left;
      Node *right;

      Node( T );
   };

   Node* root; 

   void deleteNodes( Node* root );
   bool contains( Node* root );
   int countLeaves( Node* root, int &counter );
   int countNodes( Node* root, int &counter);
   bool contains( Node* root, T element );
   int getHeight( Node* root );
   Node* insertNode( Node* root, T element );
   string getPostOrderTraversal(Node* root);
   string getPreOrderTraversal(Node* root);
   void printInOrder( Node* root );
};



#endif

//*********************
// BIG 4              *
//*********************



//*********************
// PUBLIC FUNCTIONS   *
//*********************



//*********************
// PRIVATE FUNCTIONS  *
//*********************
