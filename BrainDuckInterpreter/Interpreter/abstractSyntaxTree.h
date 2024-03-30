/**
 * @file abstractSyntaxTree.h
 * @brief Header file containing declarations for abstract syntax tree functions.
 */
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

 /** @struct TOKEN
  *  @brief Represents a token in the abstract syntax tree.
  * @warning This is a temporary struct for unit testing. It must be removed during integration.
  * 
  */
typedef struct {
    int i; /**< Integer value of the token. */
    char c; /**< Character value of the token. */
} TOKEN;

/** @struct TREENODE
 *  @brief Represents a node in the abstract syntax tree.
 */
typedef struct treeNode {
    TOKEN token; /**< Token associated with the node. */
    int value; /**< Value associated with the node. */
    struct treeNode* left; /**< Pointer to the left child node. */
    struct treeNode* right; /**< Pointer to the right child node. */
} TREENODE, * PTREENODE;

/**
 * @brief Creates a new tree node with the given token.
 * @param t The token for the new node.
 * @return Pointer to the newly created node.
 */
PTREENODE createNode(TOKEN t);

/**
 * @brief Adds a new node with the given token to the tree.
 * @param n Pointer to the root node of the tree.
 * @param t The token to be added.
 * @return Pointer to the root node of the modified tree.
 */
PTREENODE addNode(PTREENODE n, TOKEN t);

/**
 * @brief Retrieves the pointer to the left child node of the given node.
 * @param pt Pointer to the node.
 * @return Pointer to the left child node.
 */
PTREENODE getLeftTreeNodePtr(PTREENODE pt);

/**
 * @brief Retrieves the pointer to the right child node of the given node.
 * @param pt Pointer to the node.
 * @return Pointer to the right child node.
 */
PTREENODE getRightTreeNodePtr(PTREENODE pt);

/**
 * @brief Prints the abstract syntax tree in in-order traversal.
 * @param node Pointer to the root node of the tree.
 * @return Boolean indicating whether the passed node Pointer was not NULL.
 */
bool printAST(PTREENODE n);

/**
 * @brief Removes a node from the tree.
 * @param tn Pointer to the node to be removed.
 * @return Pointer to the root node of the modified tree.
 */
PTREENODE removeNode(PTREENODE tn);

/**
 * @brief Calculates the size of the tree.
 * @param tn Pointer to the root node of the tree.
 * @return The size of the tree.
 */
int getTreeSize(PTREENODE tn);

/**
 * @brief Destroys the abstract syntax tree and deallocates memory.
 * @param n Pointer to the root node of the tree.
 */
void destroyAST(PTREENODE n);
