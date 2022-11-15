#include <iostream>
#include <fstream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
struct node
{
   T info;
   node<T> *left;
   node<T> *right;
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
      // Recursive preorder
      void preOrder(node<T> *); 
      // Recursive inOrder
      void inOrder(node<T> *);
      // Recursive postorder
      void postOrder(node<T> *);
      // Recursive destroy
      void destroy (node<T> *&);

   public:
      // constructor
      BSTree();
      // destructor
      ~BSTree();
      // function called by client to distroy the treee
      void destroy();
      // Copy constructor
      BSTree (const BSTree<T> &);
      // Overloaded =
      const BSTree<T> & operator= (const BSTree<T> &);
      // Copy a tree 
      void copy ( node<T> *&, node<T> *);
      // Check if tree is empty
      bool isEmpty();
      // Insert an item in the tree
      void insertItem (T item);
      // Delete an item from the tree - client calls
      void deleteItem (T item);
      // Recursive delete item
      void deleteItem (node<T> *&, T );
      // Delete node
      void deleteNode (node<T> *& );
      // Search item
      bool searchItem (T item);
      // Print items in preorder - called by client
      void preOrder(); 
      // Print items in sorted order - called by client
      void inOrder();
      // Print items in postorder - called by client
      void postOrder();
};

#endif