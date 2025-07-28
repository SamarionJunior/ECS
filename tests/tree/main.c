#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
  int content;
  struct node* root;
  struct node** leaf;
  int lengthLeaf;
} Nodes;

typedef struct node Node;

void initiliazeTree(Node *node, int content){
  node->content = content;
  node->root = NULL;
  node->leaf = NULL;
  node->lengthLeaf = 0;
}

bool setLeaf(Node *node, Node *leaf){
  if(node == NULL){
    return false;
  }

  Node **aux;
  node->lengthLeaf++;
  
  aux = node->leaf == NULL ?
    malloc(sizeof(Node*)*node->lengthLeaf) :
    realloc(node->leaf, sizeof(Node*)*node->lengthLeaf);
  
  if(aux == NULL){
    return false;
  }

  node->leaf = aux;
  node->leaf[node->lengthLeaf - 1] = leaf;

  return true;
}

void freeTree(Node *node){
  if(node->leaf != NULL){
    for (size_t i = 0; i < node->lengthLeaf; i++){
      freeTree(node->leaf[i]);
    }
    free(node->leaf);
  }
}

bool printTree(Node *node, int nivel){
  if(node == NULL){
    return false;
  }

  for (size_t i = 0; i < nivel; i++){
    printf("  ");
  }
  printf("Content: %d\n", node->content);
  for (size_t i = 0; i < nivel; i++){
    printf("  ");
  }
  printf("LengthChilds: %i\n", node->lengthLeaf);
  
  if(node->leaf == NULL){
    return true;
  }

  int subnivel = nivel + 1;

  for (size_t i = 0; i < node->lengthLeaf; i++){
    printTree(node->leaf[i], subnivel);
  }

  return true;
}

int main(int argc, char const *argv[]){

  Node root, n1, n2, n3, n4, n5, n6;
  initiliazeTree(&root, 0);
  // printTree(&root);
  initiliazeTree(&n1, 1);
  initiliazeTree(&n2, 2);
  initiliazeTree(&n3, 3);
  initiliazeTree(&n4, 4);
  initiliazeTree(&n5, 5);
  initiliazeTree(&n6, 6);
  // printTree(&leaf);
  setLeaf(&n1, &n3);
  setLeaf(&n1, &n4);
  setLeaf(&n2, &n5);
  setLeaf(&n2, &n6);
  setLeaf(&root, &n1);
  setLeaf(&root, &n2);
  printTree(&root, 0);
  freeTree(&root);
  // printf("root.content: %d\n", root.content);
  // printf("root.childs: %p\n", root.leaf);
  // printf("root.childs: %p\n", *(root.leaf));
  // printf("root.legnthChilds: %i\n", root.lengthLeaf);
  
  return 0;

}