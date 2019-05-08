// Author: Dale Berg, CPSC 2430 02
// Filename: p2.cpp
// Assignment: p2, template BST
// Date: 5/7/2019

// Purpose: Driver class for Template BST program. This file contains a main as
// well as extensive testing of all BST functionality.

#include"BSTx.h"
#include<fstream>
#include<iostream>

using namespace std;
int main () {

cout << boolalpha; // so that true/false is printed instead of 1/0

cout << "******************************" << endl;
cout << "* INTEGER BINARY SEARCH TREE *" << endl;
cout << "******************************" << "\n" << endl;

cout<< "\n" << endl;

cout << "** CREATE BST **" << endl;
BST<int> intBst;
cout << "# of nodes: " <<  intBst.size() << endl;
cout << "# of leaves: " <<  intBst.getLeafCount() << endl;
cout << "BST height: " << intBst.getHeight() << endl;
cout << "BST empty?" << intBst.empty() << endl;

cout<< "\n" << endl;

string intFileName;
cout << "Enter name of integer file: ";
cin >> intFileName;
int value;
ifstream fileReader;
fileReader.open(intFileName);

if(fileReader.is_open()) {
   cout << "The integer file is open!" << endl;
}
else {
   cout << "Couldn't open integer file " << endl;
}

cout<< "\n" << endl;

cout << "** TEST INSERT **" << endl;
cout << "Inserting in this order: ";
while( fileReader >> value ) {
   cout << value << " ";
   intBst.insert(value);
}
cout << endl;
cout << "Number of nodes: " << intBst.size() << endl;
cout << "Number of leaves: " << intBst.getLeafCount() << endl;
cout << "Height of BST: " << intBst.getHeight() << endl;
cout << "Is the BST empty? " << intBst.empty() << endl;

cout << "\n" << endl;

cout << "** TEST TRAVERSALS **" << endl;
cout << "Pre-order: " << intBst.getPreOrderTraversal() << endl;
cout << "In-order: " <<  intBst.getInOrderTraversal() << endl;
cout << "Post-order: " << intBst.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST LEVEL & ANCESTORS **" << endl;
cout << "level(40): " << intBst.getLevel(40) << ", ancestors(40): " << intBst.getAncestors(40) << endl;
cout << "level(20): " << intBst.getLevel(20) << ", ancestors(20): " << intBst.getAncestors(20) << endl;
cout << "level(50): " << intBst.getLevel(50) << ", ancestors(20): " << intBst.getAncestors(50) << endl;
cout << "level(10): " << intBst.getLevel(10) << ", ancestors(10): " << intBst.getAncestors(10) << endl;
cout << "level(30): " << intBst.getLevel(30) << ", ancestors(30): " << intBst.getAncestors(30) << endl;
cout << "level(60): " << intBst.getLevel(60) << ", ancestors(20): " << intBst.getAncestors(60) << endl;
cout << "level(70): " << intBst.getLevel(70) << ", ancestors(20): " << intBst.getAncestors(70) << endl;

cout << "\n" << endl;

cout << "** TEST CONTAINS **" << endl;
cout << "values in order: " << intBst.getInOrderTraversal() << endl;
cout << "contains(20): "  << intBst.contains(20)  << endl;
cout << "contains(40): "  << intBst.contains(40)  << endl;
cout << "contains(10): "  << intBst.contains(10)  << endl;
cout << "contains(70): "  << intBst.contains(70)  << endl;
cout << "contains(99): "  << intBst.contains(99)  << endl;
cout << "contains(-2): "  << intBst.contains(-2)  << endl;
cout << "contains(59): "  << intBst.contains(59)  << endl;
cout << "contains(43): "  << intBst.contains(43)  << endl;

cout << "\n" << endl;

cout << "** TEST REMOVE ** " << endl;
cout << "values in order: " << intBst.getInOrderTraversal() << endl;
cout << "Removing in this order: 20 40 10 70 99 -2 59 43 " << endl;
intBst.remove(20);
intBst.remove(40);
intBst.remove(10);
intBst.remove(700);
intBst.remove(99);
intBst.remove(-2);
intBst.remove(59);
intBst.remove(43);
cout << "# of nodes: " << intBst.size() << endl;
cout << "# of leaves: " << intBst.getLeafCount() << endl;
cout << "BST height: " <<  intBst.getHeight() << endl;
cout << "BST empty? " << intBst.empty() << endl;
cout << "pre-order: " << intBst.getPreOrderTraversal() << endl;
cout << "in-order: " << intBst.getInOrderTraversal() << endl;
cout << "post-order:" << intBst.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST INSERT (again) **" << endl;
cout << "Inserting in this order: 20 40 10 70 99 -2 59 43" << endl;
intBst.insert(20);
intBst.insert(40);
intBst.insert(10);
intBst.insert(70);
intBst.insert(90);
intBst.insert(-2);
intBst.insert(59);
intBst.insert(43);
cout << "# of nodes: " <<  intBst.size() << endl;
cout << "# of leaves: " << intBst.getLeafCount() << endl;
cout << "BST height: " <<  intBst.getHeight() << endl;
cout << "BST empty? " << intBst.empty() << endl;
cout << "pre-order: " << intBst.getPreOrderTraversal() << endl;
cout << "in-order: " << intBst.getInOrderTraversal()  << endl;
cout << "post-order: " << intBst.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST COPY CONSTRUCTOR **" << endl;
BST<int> cIntBST = intBst;
cout << "# of nodes: " <<  cIntBST.size() << endl;
cout << "# of leaves: " << cIntBST.getLeafCount() << endl;
cout << "BST height: " <<  cIntBST.getHeight() << endl;
cout << "BST empty? " << cIntBST.empty() << endl;
cout << "pre-order: " << cIntBST.getPreOrderTraversal() << endl;
cout << "in-order: " << cIntBST.getInOrderTraversal()  << endl;
cout << "post-order: " << cIntBST.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST OVERLOADED ASSIGNMENT **" << endl;
BST<int> assignmentTree;
assignmentTree = intBst;
cout << "# of nodes: " << assignmentTree.size() << endl;
cout << "# of leaves: " << assignmentTree.getLeafCount() << endl;
cout << "BST height: " << assignmentTree.getHeight() << endl;
cout << "BST empty? " << assignmentTree.empty() << endl;
cout << "pre-order: " << assignmentTree.getPreOrderTraversal() << endl;
cout << "in-order: " << assignmentTree.getInOrderTraversal()  << endl;
cout << "post-order: " << assignmentTree.getPostOrderTraversal() << endl;
cout << "\n" << endl;

cout << "** TEST GET LEVEL ORDER (EC) **" << endl;
cout << "To prove distinction from traversals, pre, post and in are ";
cout << "included below" << endl;
cout << "Level order: " << intBst.getLevelOrder() << endl;
cout << "pre-order: " << intBst.getPreOrderTraversal() << endl;
cout << "in-order: " << intBst.getInOrderTraversal()  << endl;
cout << "post-order: " << intBst.getPostOrderTraversal() << endl;

cout<< "\n" << endl;

cout << "** TEST GET WIDTH **" << endl;
cout << "# of nodes: " << intBst.size() << endl;
cout << "# of leaves: " << intBst.getLeafCount() << endl;
cout << "BST height: " << intBst.getHeight() << endl;
cout << "BST empty? " << intBst.empty() << endl;
cout<< "BST width*: " << intBst.getWidth() << endl;
cout << "pre-order: " << intBst.getPreOrderTraversal() << endl;
cout << "in-order: " << intBst.getInOrderTraversal()  << endl;
cout << "post-order: " << intBst.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "*****************************" << endl;
cout << "* STRING BINARY SEARCH TREE *" << endl;
cout << "*****************************" << endl;

cout << "\n" << endl;

BST<string> stringTree;
cout << "# of nodes: " <<  stringTree.size() << endl;
cout << "# of leaves: " <<  stringTree.getLeafCount() << endl;
cout << "BST height: " << stringTree.getHeight() << endl;
cout << "BST empty?" << stringTree.empty() << endl;

cout << "\n" << endl;

cout << "Enter string file: ";
string stringFileName;
ifstream stringFileReader; // could have reused file reader, but this allows
                           // freedom to check if both files open
cin >> stringFileName;
string str;
stringFileReader.open(stringFileName);
if(stringFileReader.is_open()) {
   cout << "The string file is open!" << endl;
}
else {
   cout << "Couldn't open string file " << endl;
}

cout << "\n" << endl;

cout <<  "** TEST INSERT **" << endl;
cout << "Inserting in this order: ";
while( stringFileReader >> str ) {
   cout << str << " ";
   stringTree.insert(str);
}

cout << "\n" << endl;

cout << "Number of nodes: " << stringTree.size() << endl;
cout << "Number of leaves: " << stringTree.getLeafCount() << endl;
cout << "Height of BST: " << stringTree.getHeight() << endl;
cout << "Is the BST empty? " << stringTree.empty() << endl;

cout << "\n" << endl;

cout << "** TEST TRAVERSALS **" << endl;
cout << "Pre-order: " << stringTree.getPreOrderTraversal() << endl;
cout << "In-order: " <<  stringTree.getInOrderTraversal() << endl;
cout << "Post-order: " << stringTree.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST LEVEL & ANCESTORS **" << endl;
cout << "level(mary): " << stringTree.getLevel("mary") << ", ancestors(mary): " << stringTree.getAncestors("mary") << endl;
cout << "level(gene): " << stringTree.getLevel("gene") << ", ancestors(gene): " << stringTree.getAncestors("gene") << endl;
cout << "level(bea): " << stringTree.getLevel("bea") << ", ancestors(bea): " << stringTree.getAncestors("bea") << endl;
cout << "level(jen): " << stringTree.getLevel("jen") << ", ancestors(jen): " << stringTree.getAncestors("jen") << endl;
cout << "level(sue): " << stringTree.getLevel("sue") << ", ancestors(sue): " << stringTree.getAncestors("sue") << endl;
cout << "level(pat): " << stringTree.getLevel("pat") << ", ancestors(pat): " << stringTree.getAncestors("pat") << endl;
cout << "level(uma): " << stringTree.getLevel("uma") << ", ancestors(uma): " << stringTree.getAncestors("uma") << endl;

cout << "\n" << endl;

cout << "** TEST CONTAINS **" << endl;
cout << "Value in order: " << stringTree.getInOrderTraversal() << endl;
cout << "contains(mary): "  << stringTree.contains("mary")  << endl;
cout << "contains(gene): "  << stringTree.contains("gene")  << endl;
cout << "contains(bea): "  << stringTree.contains("bea")  << endl;
cout << "contains(sue): "  << stringTree.contains("sue")  << endl;
cout << "contains(pat): "  << stringTree.contains("pat")  << endl;
cout << "contains(Gene): "  << stringTree.contains("Gene")  << endl;
cout << "contains(sandy): "  << stringTree.contains("sandy")  << endl;
cout << "contains(marY): "  << stringTree.contains("marY")  << endl;

cout << "\n" << endl;

cout << "** TEST REMOVE **" << endl;
cout << "Removing in this order: gene mary bea uma yan amy ron opal" << endl;
stringTree.remove("gene");
stringTree.remove("mary");
stringTree.remove("bea");
stringTree.remove("uma");
stringTree.remove("yan");
stringTree.remove("amy");
stringTree.remove("ron");
stringTree.remove("opal");
cout << "# of nodes: " << stringTree.size() << endl;
cout << "# of leaves: " << stringTree.getLeafCount() << endl;
cout << "BST height: " << stringTree.getHeight() << endl;
cout << "pre-order: " << stringTree.getPreOrderTraversal() << endl;
cout << "in-order: " << stringTree.getInOrderTraversal() << endl;
cout << "post-order: " << stringTree.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST INSERT (again) **" << endl;
cout << "Inserting in this order: gene mary bea uma yan amy ron opal" << endl;
stringTree.insert("gene");
stringTree.insert("mary");
stringTree.insert("bea");
stringTree.insert("uma");
stringTree.insert("yan");
stringTree.insert("amy");
stringTree.insert("ron");
stringTree.insert("opal");
cout << "# of nodes: " <<  stringTree.size() << endl;
cout << "# of leaves: " << stringTree.getLeafCount() << endl;
cout << "BST height: " <<  stringTree.getHeight() << endl;
cout << "BST empty? " << stringTree.empty() << endl;
cout << "pre-order: " << stringTree.getPreOrderTraversal() << endl;
cout << "in-order: " << stringTree.getInOrderTraversal()  << endl;
cout << "post-order: " << stringTree.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST COPY CONSTRUCTOR **" << endl;
BST<string> cStringTree = stringTree;
cout << "# of nodes: " <<  cStringTree.size() << endl;
cout << "# of leaves: " << cStringTree.getLeafCount() << endl;
cout << "BST height: " <<  cStringTree.getHeight() << endl;
cout << "BST empty? " << cStringTree.empty() << endl;
cout << "pre-order: " << cStringTree.getPreOrderTraversal() << endl;
cout << "in-order: " << cStringTree.getInOrderTraversal()  << endl;
cout << "post-order: " << cStringTree.getPostOrderTraversal() << endl;

cout << "\n" << endl;

cout << "** TEST OVERLOADED ASSIGNMENT **" << endl;
BST<string> stringAssignmentTree;
stringAssignmentTree = stringTree;
cout << "# of nodes: " << stringAssignmentTree.size() << endl;
cout << "# of leaves: " << stringAssignmentTree.getLeafCount() << endl;
cout << "BST height: " << stringAssignmentTree.getHeight() << endl;
cout << "BST empty? " << stringAssignmentTree.empty() << endl;
cout << "pre-order: " << stringAssignmentTree.getPreOrderTraversal() << endl;
cout << "in-order: " << stringAssignmentTree.getInOrderTraversal()  << endl;
cout << "post-order: " << stringAssignmentTree.getPostOrderTraversal() << endl;

cout<< "\n" << endl;

cout << "** TEST GET LEVEL ORDER (EC) **" << endl;
cout << "To prove distinction from traversals, pre, post and in are ";
cout << "included below" << endl;
cout << "Level order: " << stringTree.getLevelOrder() << endl;
cout << "pre-order: " << stringTree.getPreOrderTraversal() << endl;
cout << "in-order: " << stringTree.getInOrderTraversal()  << endl;
cout << "post-order: " << stringTree.getPostOrderTraversal() << endl;

cout<< "\n" << endl;

cout << "** TEST GET WIDTH **" << endl;
cout << "# of nodes: " << stringTree.size() << endl;
cout << "# of leaves: " << stringTree.getLeafCount() << endl;
cout << "BST height: " << stringTree.getHeight() << endl;
cout << "BST empty? " << stringTree.empty() << endl;
cout<< "BST width*: " << stringTree.getWidth() << endl;
cout << "pre-order: " << stringTree.getPreOrderTraversal() << endl;
cout << "in-order: " << stringTree.getInOrderTraversal()  << endl;
cout << "post-order: " << stringTree.getPostOrderTraversal() << endl;

fileReader.close();
stringFileReader.close();

}
