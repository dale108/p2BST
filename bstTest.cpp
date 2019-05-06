
#include"BST.h"
#include<iostream>
#include<queue>
#include<sstream>
#include<cstdlib>
#include<math.h> // need this for isnan() function

using namespace std;

template<typename T>
BST<T>::BST() {
   root = nullptr;
}

template<typename T>
BST<T>::BST(const BST& other) {
      root = copyTree(other.root);
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

   return 1 + max(leftHeight, rightHeight); // + 1 for root
}

template<typename T>
int BST<T>::getLeafCount() {
   int counter = 0;
   return countLeaves(root, counter);
}

template<typename T>
int BST<T>::getLevel( T element ) {
   int counter = 0;
   return getLevel(root, element, counter);
}

template<typename T>
int BST<T>::getLevel(Node* root, T element, int& counter) {
   if(root != nullptr) {
      ++counter;
      if( element < root->value ) {
         getLevel(root->left, element, counter);
      }
      else if( element > root->value ) {
         getLevel(root->right, element, counter);
      }
         if( element == root->value) {
         } ///// what is this doing????
      }
   return counter;
}

template<typename T>
string BST<T>::getLevelOrder() {
   if( root != nullptr ) {
      ostringstream ss;
      queue<Node *> que;
      que.push(root);
      while( que.empty() == false ) {
         Node* temp = que.front();
         ss << temp->value << " ";
         //cout << temp->value << endl;
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
      getPostOrderTraversal(root->left);
      getPostOrderTraversal(root->right);
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

template< typename T>
int BST<T>::getWidth() {

   Node* curr = root;

   if( curr == nullptr ) {
      return 0;
   }

   queue<Node *> q;
   q.push(curr);

   int level = 0;
   int max = INT_MIN;

   bool isDone = false;

   while(!isDone) {

      int nodeCount = q.size();

      if(nodeCount == 0) {
         isDone = true;
         continue;
         //break;
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


template< typename T>
void BST<T>::remove( T element ) {
   Node* curr = root;
   remove(curr, element);
}

template <typename T>
void BST<T>::remove( Node *&curr, T element ) {
   if( curr != nullptr) {
      if(curr->value > element) {
         remove(curr->left, element);
      }
      else if(curr->value < element ) {
         remove(curr->right, element);
      }
      else deleteNode(curr);
   }
}

template <typename T>
void BST<T>::deleteNode(Node*& ptr) {
   Node* curr = nullptr;
   if(ptr != nullptr) {
      if(ptr->right == nullptr) {
         curr = ptr;
         ptr = ptr->left;
         delete curr;
      }
      else if(ptr->left == nullptr) {
         curr = ptr;
         ptr = ptr->right;
         delete curr;
      }
      else {
         curr = ptr->right;
         while( curr->left != nullptr ) {
            curr = curr->left;
         }
         curr->left = ptr->left;
         curr = ptr;
         ptr = ptr->right;
         delete curr;
      }
   }
}

template<typename T>
int BST<T>::size() {
   int counter = 0;
   return countNodes(root, counter);
}

int main() {

   mary
gene
bea
jen
sue
pat
uma

BST<string> s;
s.insert("gene");
s.insert("bea");
s.insert("jen");
s.insert("sue");
s.insert("pat");
s.insert("uma");
cout << s.getPreOrderTraversal() << endl;

}
