
#include "BST.h"
#include<iostream>

using namespace std;

template<typename T>
BST<T>::BST() {
   root = nullptr;
}

template<typename T>
BST<T>::~BST() {
   if(root == nullptr) {
      delete root;
   }
   deleteNodes(root);
}

template<typename T>
void BST<T>::deleteNodes( Node* root ) {
   if(root != nullptr) {
      deleteNodes(root->right);
      deleteNodes(root->left);
      delete root;
   }
}

template<typename T>
BST<T>::Node::Node(T val) {
   left =  nullptr;
   right = nullptr;
   value = val;
}

template<typename T>
bool BST<T>::contains( T element ) {
   return contains(root, element);
}

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

template<typename T>
int BST<T>::countNodes( Node* root, int &counter) {
   if( root != nullptr )  {
      ++counter;
      countNodes(root->left, counter);
      countNodes(root->right, counter);
   }
   return counter;
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

template<typename T>
bool BST<T>::empty() {
   if(root == nullptr) {
      return true;
   }
   return false;
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

   return 1 + max(leftHeight, rightHeight); // + 1 for root
}

template<typename T>
int BST<T>::getLeafCount() {
   int counter = 0;
   return countLeaves(root, counter);
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
string BST<T>::getInOrderTraversal() {
   printInOrder(root);
   return "do this";
}

template<typename T>
string BST<T>::getPostOrderTraversal() {
   getPostOrderTraversal(root);
}

template<typename T>
string BST<T>::getPostOrderTraversal(Node* root) {
   if(root != nullptr) {
      getPostOrderTraversal(root->left);
      getPostOrderTraversal(root->right);
      //add value here
   }
   return ""; // this is placeholder.
}

template<typename T>
string BST<T>::getPreOrderTraversal() {
   getPreOrderTraversal(root);
}

template<typename T>
string BST<T>::getPreOrderTraversal(Node* root) {
   if(root != nullptr) {
      //add value here
      getPreOrderTraversal(root->left);
      getPreOrderTraversal(root->right);
   }
   return ""; // place holder
}


template<typename T>
void BST<T>::printInOrder( Node* root ) {

   if(root != nullptr ) {
      printInOrder(root->left);
      cout << root->value << " ";
      printInOrder(root->right);
   }
}

template<typename T>
int BST<T>::size() {
   int counter = 0;
   return countNodes(root, counter);
}

int main() {
   BST<int> b;
   b.insert(22);
   b.insert(25);
   b.insert(13);
   b.insert(80);
   // b.insert(36);
   // b.insert(41);
   // b.insert(7);
   // b.insert(11);
   // b.insert(20);
   b.getInOrderTraversal();

   //"contains" test
   // for(int i = 0; i < 10; ++i) {
   //    cout << "does this contain " << i << " ?: " << b.contains(i) << endl;
   // }

   cout << "this many nodes in tree: " << b.size() << endl;
   cout << "There are this many leaves in the tree: " << b.getLeafCount() <<endl;

   cout << "The height of the tree is: " << b.getHeight() << endl;
}
