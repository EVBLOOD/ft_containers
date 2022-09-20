/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree_implemeted.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:06:02 by sakllam           #+#    #+#             */
/*   Updated: 2022/09/20 18:45:45 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <cstdlib>
#include <memory>
#include <iostream>
namespace ft
{
    #define red true
    #define black false
    #define rt 1
    #define l 2
    #define r 3
    template <class T>
        struct RedBlackTree
    {
        typedef T type_name;

        type_name value;
        RedBlackTree *left;
        RedBlackTree *right;
        RedBlackTree *parent;
        int           position;
        bool          color;
        RedBlackTree(type_name value) : value(value), left(NULL), right(NULL), parent(NULL), color(red) {}
    };

    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<RedBlackTree<T> > >
        class R_B_T
    {
        typedef Alloc   alloc;
        typedef T       type_name;
        typedef Compare cmpfun;
        typedef size_t  size_amount;

        public:
        alloc                   ac;
        RedBlackTree<type_name> *head;
        cmpfun                  cmpr;
        size_amount             size;
        
        private:        
        
        R_B_T (const cmpfun& comp = cmpfun(), const alloc& ac = alloc()) :  cmpr(comp), ac(ac) { }
        void swaping(RedBlackTree<type_name> *one, RedBlackTree<type_name> *two)
        {
            type_name   tmp = one->value;
            int         color = one->color;
            one->value = two->value;
            one->color = two->color;
            two->value = tmp;
            two->color = color;
        }
        void    right_rotation(RedBlackTree<type_name> **root, bool coloring = true)
        {
            swaping((*root)->left, *root);
            RedBlackTree<type_name> *tmpA = (*root)->left;
            (*root)->left = (*root)->left->left;
            if ((*root)->left)
            {
                (*root)->left->parent = *root;
                if (coloring)
                    (*root)->left->color = red;
            }
            tmpA->left = tmpA->right;
            if (tmpA->left)
            {
                tmpA->left->parent = tmpA;
                tmpA->left->position = l;
            }
            tmpA->right = (*root)->right;
            if (tmpA->right)
            {
                tmpA->right->position = r;
                tmpA->right->parent = tmpA;
            }
            (*root)->right = tmpA;
            tmpA->position = r;
            tmpA->parent = *root;
            if (coloring)
            {
                (*root)->color = black;
                tmpA->color = red;
            }
        }
        void    left_rotation(RedBlackTree<type_name> **root, bool coloring = true)
        {
            swaping((*root)->right, *root);
            RedBlackTree<type_name> *tmpA = (*root)->right;
            (*root)->right = (*root)->right->right;
            if ((*root)->right)
            {
                (*root)->right->parent = *root;
                (*root)->right->position = r;
                if (coloring)
                    (*root)->right->color = red;
            }
            tmpA->right = tmpA->left;
            if (tmpA->right)
            {
                tmpA->right->parent = tmpA;
                tmpA->right->position = r;
            }
            tmpA->left = (*root)->left;
            if (tmpA->left)
            {
                tmpA->left->position = l;
                tmpA->left->parent = tmpA;
            }
            (*root)->left = tmpA;
            tmpA->position = l;
            tmpA->parent = *root;
            if (coloring)
            {
                (*root)->color = black;
                tmpA->color = red;
            }
        }
        void    balancing(RedBlackTree<type_name> **head, int position)
        {
            if (position == r)
            {
                if ((*head)->right->right && (*head)->right->right->color == red)
                    return left_rotation(head);
                right_rotation(&((*head)->right), false);
                return left_rotation(head);
            }
            if ((*head)->left->left && (*head)->left->left->color == red)
                return right_rotation(head);
            left_rotation(&((*head)->left), false);
            return right_rotation(head);
        }
        RedBlackTree<type_name> *newnode(type_name value)
        {
            RedBlackTree<type_name> *newnode = ac.allocate(1);
            ac.construct(newnode, value);
            return newnode;
        }
        void    insert(RedBlackTree<type_name> **head, RedBlackTree<type_name> *nv, int position)
        {
            if ((*head) == NULL)
            {
                *head = nv;
                nv->position = position;
                if (position == rt)
                    nv->color = black;
                size = size + 1;
                return;
            }
            if (cmpr(nv->value, (*head)->value))
                insert(&((*head)->left), nv, l);
            else if (cmpr((*head)->value, nv->value))
                insert(&((*head)->right), nv, r);
            else
                return;
            if ((*head)->left && (*head)->left->value == nv->value)
                (*head)->left->parent = *head;
            else
                (*head)->right->parent = *head;
            if ((*head)->color == black ||
                    (((*head)->left == NULL || (*head)->left->color == black) && ((*head)->right == NULL || (*head)->right->color == black)))
                return;
            if ((*head)->position == r)
            {
                if ((*head)->parent->left && (*head)->parent->left->color == red)
                {
                    (*head)->parent->left->color = black;
                    if ((*head)->parent->position != rt)
                        (*head)->parent->color = red;
                    (*head)->color = black;
                    return;
                }
                return balancing(&((*head)->parent), r);
            }
            if ((*head)->parent->right && (*head)->parent->right->color == red)
            {
                (*head)->parent->right->color = black;
                if ((*head)->parent->position != rt)
                    (*head)->parent->color = red;
                (*head)->color = black;
                return;
            }
            return balancing(&((*head)->parent), l);
        }
        void    printing(RedBlackTree<type_name> *root, int level)
        {
            if (!root)
                return;
            printing(root->right, level + 1);
            printing(root->left, level + 1);
            std::cout << level << "\t";
            if (root->position == rt)
                std::cout << "position: root ";
            else if (root->position == r)
                std::cout << "position: right ";
            else
                std::cout << "position: left ";
            if (root->color == red)
                std::cout << "color: red ";
            else
                std::cout << "color: black ";
            std::cout << " | the number: " << root->value << "\n";
        }
        type_name thedeepest(RedBlackTree<type_name> *head)
        {
            if (head->right == NULL)
                return head->value;
            return thedeepest(head->right);
        }
        void remove_helper(RedBlackTree<type_name> **head, type_name element)
        {
            if (*head == NULL)
                return;
            if (cmpr(element, (*head)->value))
                remove_helper(&((*head)->left), element);
            else if (cmpr((*head)->value, element))
                remove_helper(&((*head)->right), element);
            else
            {
                RedBlackTree<type_name> *target = *head;
                if (target->left == NULL && target->right == NULL)
                {
                    bool color = target->color;
                    int position = target->position;
                    RedBlackTree<type_name> *parent = (*head)->parent;
                    ac.destroy(*head);
                    ac.deallocate(*head, 1);
                    *head = NULL;
                    if (color == black && position != rt)
                        fix_double_black(&(parent), position);
                    size--;
                    return;
                }
                if (target->left == NULL)
                {
                    type_name value = target->right->value;
                    (*head)->value = value;
                    remove_helper(&((*head)->right), value);
                    return;
                }
                if (target->right == NULL)
                {
                    type_name value = target->left->value;
                    (*head)->value = value;
                    remove_helper(&((*head)->left), value);
                    return;
                }
                type_name value = thedeepest(target->left);
                (*head)->value = value;
                remove_helper(&((*head)->left), value);
            }
        }
        void    deletion_balancing_recoloring(RedBlackTree<type_name> **head, int position, bool each = true)
        {
            if (each)
            {
                if (position == r)
                {
                    if ((*head)->right->right && (*head)->right->right->color == red)
                    {
                        (*head)->right->color = (*head)->color;
                        (*head)->color = black;
                        (*head)->right->right->color = black;
                        return left_rotation(head, false);
                    }
                    (*head)->right->color = red;
                    (*head)->right->left->color = black;
                    right_rotation(&((*head)->right), false);
                    (*head)->right->color = (*head)->color;
                    (*head)->color = black;
                    (*head)->right->right->color = black;
                    return left_rotation(head, false);
                }
                if ((*head)->left->left && (*head)->left->left->color == red)
                {
                    (*head)->left->color = (*head)->color;
                    (*head)->color = black;
                    (*head)->left->left->color = black;
                    return right_rotation(head, false);
                }
                (*head)->left->color = red;
                (*head)->left->right->color = black;
                left_rotation(&((*head)->left), false);
                (*head)->left->color = (*head)->color;
                (*head)->color = black;
                (*head)->left->left->color = black;
                return right_rotation(head, false);
            }
            if (position == r)
            {
                if ((*head)->right->right)
                    return left_rotation(head, false);
                if ((*head)->right->left)
                    right_rotation(&((*head)->right), false);
                return left_rotation(head, false);
            }
            if ((*head)->left->left)
                return right_rotation(head, false);
            if ((*head)->left->right)
                left_rotation(&((*head)->left), false);
            return right_rotation(head, false);
        }
        RedBlackTree<type_name> *nephew(RedBlackTree<type_name> *node, int position)
        {
            if (position == l)
                return node->right;
            return node->left;
        }
        RedBlackTree<type_name> *niece(RedBlackTree<type_name> *node, int position)
        {
          if (position == l)
              return node->left;
            return node->right;
        }
        void fix_case(RedBlackTree<type_name> **sibling, int position)
        {
            if ((nephew(*sibling, position) && nephew(*sibling, position)->color == red)
                || (niece(*sibling, position) && niece(*sibling, position)->color == red))
                return deletion_balancing_recoloring(&((*sibling)->parent), (*sibling)->position);
            if ((*sibling)->color == black)
            {
                (*sibling)->color = red;
                if ((*sibling)->parent->color != black)
                    (*sibling)->parent->color = black;
                else 
                    fix_double_black(&((*sibling)->parent->parent), (*sibling)->parent->position);
                return ;
            }
            if ((*sibling)->color == red)
            {
                (*sibling)->parent->color = red;
                (*sibling)->color = black;
                deletion_balancing_recoloring(&((*sibling)->parent), (*sibling)->position, false);
                if (position == l)
                    return fix_double_black(&((*sibling)->parent->left), l);
                return fix_double_black(&((*sibling)->parent->right), r);
            }
        }
        void fix_double_black(RedBlackTree<type_name> **leaf_parent, int position)
        {
            if (position == rt)
                return;
            if (position == r)
                return fix_case(&((*leaf_parent)->left), r);
            else
                return fix_case(&((*leaf_parent)->right), l);
        }
        bool find_helper(RedBlackTree<type_name> *head, type_name value)
        {
            if (head == NULL)
                return false;
            if (cmpr(value, head->value))
                return find_helper(head->left, value);
            else if (cmpr(head->value, value))
                return find_helper(head->right, value);
            else
                return true;
        }
        void free_helper(RedBlackTree<type_name> *head)
        {
            if (head == NULL)
                return ;
            free_helper(head->right);
            free_helper(head->left);
            ac.destroy(head);
            ac.deallocate(head, 1);            
        }
        RedBlackTree<type_name> *begin_helper(RedBlackTree<type_name> *head)
        {
            if (head->left == NULL)
                return head;
            return begin_helper(head->left);
        }
          RedBlackTree<type_name> *thedeepest_left(RedBlackTree<type_name> *head)
        {
            if (head->left == NULL)
                return head;
            return thedeepest_left(head->left);
        }
        RedBlackTree<type_name> *next(RedBlackTree<type_name> *x, RedBlackTree<type_name> *old)
        {
            if (x == NULL)
                return (NULL);
            if (x->right && old != x->right)
                return thedeepest_left(x->right);
            if (x->position == l)
                    return x->parent;
            return next(x->parent, x);
        }
        RedBlackTree<type_name> *thedeepest_right(RedBlackTree<type_name> *head)
        {
            if (head->right == NULL)
                return head;
            return thedeepest_right(head->right);
        }
        RedBlackTree<type_name> *prev(RedBlackTree<type_name> *x, RedBlackTree<type_name> *old)
        {
            if (x->left && old != x->left)
                return thedeepest_right(x->left);
            if (x->position == r)
                return x->parent;
            return prev(x->parent, x);
        }
        public:
            R_B_T() : head(NULL), size(0) {}
            ~R_B_T()
            {
                return free_helper(head);
            }
            void insert(type_name value)
            {
                return insert(&head, newnode(value), rt);
            }
            void  printing()
            {
                printing(this->head, 0);
            }
            size_amount lengh()
            {
                return size;
            }
            bool find(type_name value)
            {
                return find_helper(head, value);
            }
            void remove(type_name element)
            {
                if (!head)
                    return;
                return remove_helper(&head, element);
            }
            RedBlackTree<type_name> *begin()
            {
                return begin_helper(head);
            }
            RedBlackTree<type_name> *_prev(RedBlackTree<type_name> *x)
            {
                if (x == NULL)
                    return thedeepest_right(head);
                return prev(x, x);
            }
            RedBlackTree<type_name> *_next(RedBlackTree<type_name> *x)
            {
                return next(x, x);
            }
            RedBlackTree<type_name> *end()
            {
                return NULL;
            }
    };
}