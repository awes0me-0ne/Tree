#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

//木
TREE make_tree(){
  return NULL;
}

//セル
TCellP make_new_cell(int data){
  TCellP new_cell=(TCellP)malloc(sizeof(TCellP));
  new_cell->data=data;
  new_cell->right=NULL;
  new_cell->left=NULL;
  return new_cell;
}

//nodeの左に挿入
TREE left_insert(TREE tree,TCellP node,TCellP new_node){
  TREE result;
  if(tree==NULL){
    result=new_node;
  }else{
    result=tree;
    node->left=new_node;
  }
  return result;
}

//nodeの右子に挿入
TREE right_insert(TREE tree,TCellP node,TCellP new_node){
  TREE result;
  if(tree==NULL){
    result=new_node;
  }else{
    result=tree;
    node->right=new_node;
  }
  return result;
}

//node の左子にsub結合
TREE left_join(TREE tree,TCellP node,TREE sub){
  TREE result;
    if(tree==NULL){
    result=sub;
  }else{
    result=tree;
    node->left=sub;
  }
  return result;
}

//node の右子にsub結合
TREE right_join(TREE tree,TCellP node,TREE sub){
  TREE result;
    if(tree==NULL){
    result=sub;
  }else{
    result=tree;
    node->right=sub;
  }
  return result;
}

TREE remove_left(TREE tree,TCellP node){
  if(tree==NULL){
    return NULL;
  }else{
    if(node->left==NULL&&node->right==NULL){
      node=NULL;
    }
  }
  return tree;
}

//空かテスト
int is_empty(TREE tree){
  if(tree==NULL){
    return NODATA;
  }else{
    return EXISTDATA;
  }
}

//行きがけ
void print_pre_order(TREE tree){
  if(tree==NULL){
    return;
  }else{
    printf("[");
    printf("%4d",tree->data);
    print_pre_order(tree->left);
    print_pre_order(tree->right);
    printf("]");
  }
}

//通りがけ
void print_mid_order(TREE tree){
  if(tree==NULL){
    return;
  }else{
    printf("[");
    print_mid_order(tree->left);
    printf("%4d",tree->data);
    print_mid_order(tree->right);
    printf("]");
  }
}

//帰りがけ
void print_pos_order(TREE tree){
  if(tree==NULL){
    return;
  }else{
    printf("[");
    print_pre_order(tree->left);
    print_pre_order(tree->right);
    printf("%4d",tree->data);
    printf("]");
  }
}
