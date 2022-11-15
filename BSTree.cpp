#include "BSTree.h"

template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;
}

template <class T>
BSTree<T> :: ~BSTree ()
{
   destroy (root);
}

template <class T>
void BSTree<T> :: destroy (node<T> *& r)
{   
   if ( r != NULL )
   {
       destroy (r->left);
       destroy (r->right);
       delete r;
       r = NULL;
   }
}

template <class T>
void BSTree<T> :: destroy ()
{   
   destroy (root);
}

template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
   copy ( root, other.root );
}

template <class T>
const BSTree<T> &  BSTree<T> :: operator= (const BSTree<T> & other)
{
    if ( this != &other )
    {
        if ( root != NULL )
           destroy (root);
        if ( other.root == NULL )
           root = NULL;
        else 
           copy (root, other.root);       
    }

    return *this;
}

template <class T>
void BSTree<T> :: copy (node<T> *& nroot, node<T> *croot  )
{
    if ( croot == NULL )
       nroot = NULL;
    else 
    {
        nroot = new node<T>;
        nroot->info = croot->info;
        copy (nroot->left, croot->left);
        copy (nroot->right, croot->right);
    }   
}

template <class T>
bool BSTree<T> :: isEmpty ()
{
   return root == NULL;
} 

template <class T>
void BSTree<T> :: preOrder ()
{
    preOrder (root);    
}

template <class T>
void BSTree<T> :: preOrder (node<T> *p )
{
   if ( p != NULL )
   {
      cout<<p->info<<" ";
      preOrder (p->left);
      preOrder (p->right);
   }
}

template <class T>
void BSTree<T> :: postOrder ()
{
   postOrder (root);
}

template <class T>
void BSTree<T> :: postOrder (node<T> *p )
{
   if ( p != NULL )
   { 
      postOrder (p->left);
      postOrder (p->right);
      cout<<p->info<<" ";
   }
}

template <class T>
void BSTree<T> :: inOrder ()
{
   inOrder (root); 
}

template <class T>
void BSTree<T> :: inOrder (node<T> *p )
{ 
   if ( p != NULL )
   {
      inOrder (p->left);
      cout<<p->info<<" ";
      inOrder (p->right);
   }
}

template <class T>
void BSTree<T> :: insertItem (T item )
{
    node<T> *p;
    node<T> *trail;
    node<T> *temp;

    temp = new node<T>;
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;

    if ( root == NULL )
       root = temp;
    else
    {
       p = root;

       while ( p != NULL )
       {
          trail = p;

          if ( p->info == item )
          {
             cout<<"ERROR: DUPLICATES ARE NOT ALLOWED";
             delete temp;
             return;
          }
          else if ( p->info > item )
             p = p->left;
          else 
             p = p->right;   
       }

       if ( trail->info  > item )
          trail->left = temp;
       else 
          trail->right = temp;   
    }   
}

template <class T>
bool BSTree<T> :: searchItem (T item )
{
    node<T> *p = root;
    bool found = false;

    while ( p != NULL && !found )
    {
       if ( item == p->info )
          found = true;
       else if ( item > p->info )
          p = p->right;
       else 
          p = p->left;       
    }

    return found; 
}

template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem (root, item);
}

template <class T>
void BSTree<T> :: deleteItem (node<T> *&p, T item )
{
    if ( p == NULL )
       cout<<"ITEM NOT THERE";
    else if ( item < p->info )   
       deleteItem (p->left, item);
    else if ( item > p->info )
       deleteItem (p->right, item);
    else 
       deleteNode (p);      
}

template <class T>
void BSTree<T> :: deleteNode (node<T> *& p )
{
   node<T> *q = p;

   if ( p->right == NULL )
   {
      p = p->left;
      delete q;
   }
   else if ( p->left == NULL )
   {
      p = p->right;
      delete q;
   }

   else 
   {
      q = p->left;
      node<T> *trail = NULL;

      while ( q->right != NULL )
      {
         trail = q;
         q = q->right;
      }

      p->info = q->info;

      if ( trail == NULL )
         p->left = q->left;
       else 
         trail->right = q->left;

       delete q;     
   }
}

