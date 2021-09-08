#include "./bintree.h"

BinTreeNode* makeBinTreeNode(char data){
  BinTreeNode *ret;

  if(!(ret = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
     return 0;
  bzero(ret, sizeof(BinTreeNode));
  ret->data = data;
  return ret;
}

BinTree* makeBinTree(BinTreeNode rootNode)
{
  BinTree *ret;

  if(!(ret = (BinTree *)malloc(sizeof(BinTree))))
    return 0;
  //*******ret->pRootNode = &rootNode;
  ret->pRootNode = makeBinTreeNode(rootNode.data);
  printf("root_make: %c\n", ret->pRootNode->data);
  return ret;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
  if (!pBinTree)
    return NULL;
  printf("root_get: %c\n", pBinTree->pRootNode->data);
  

  //Preorder_travrsal(pBinTree);
  return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
  if (!pParentNode)
    return NULL;
  // printf("\nthis is insertLeft parent %c left %c\n", pParentNode->data, element.data);
  // if (pParentNode->pLeftChild == 0)
  pParentNode->pLeftChild = makeBinTreeNode(element.data);
  printf("test:: %c, %c, %c\n", pParentNode->data, pParentNode->pLeftChild->data, element.data);
 
  // printf("this is 43 root");

  // else
    // insertLeftChildNodeBT(pParentNode->pLeftChild, element);
  // printf("\nThis is insertLeftAfter %c\n", pParentNode->pLeftChild->data);
  
  return pParentNode; 
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
  if (!pParentNode)
    return NULL;
  // printf("\nthis is insertRight parent %c right %c\n", pParentNode->data, element.data);
  /*
  pParentNode->pRightChild = &element;
  */
  pParentNode->pRightChild = makeBinTreeNode(element.data);
  // printf("\nThis is insertRightAfter %c\n", pParentNode->pRightChild->data);

  return pParentNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
  // printf("gParent: %c gLeft: %c\n", pNode->data, pNode->pLeftChild->data);
  return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
  // printf("parent %c right %c\n", pNode->data, pNode->pRightChild->data);
  return pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree)
{
  if (!pBinTree)
    return ;
  deleteBinTreeNode(pBinTree->pRootNode);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
  if (pNode == NULL)
    return ;
  deleteBinTreeNode(pNode->pLeftChild);
  deleteBinTreeNode(pNode->pRightChild);

  free(pNode);
}