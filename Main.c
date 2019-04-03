#include<stdio.h>
#include<time.h>
#include "tree.h"

int main(){
  TREE tree1,tree2,tree3;
  FILE *fp1,*fp2,*fp3;
  int num=5;

  /*data用意*/
  srand(time(NULL));

  fp1=fopen("Tree1Data","w");
  make_data_file(fp1,num);
  fclose(fp1);
  fp2=fopen("Tree2Data","w");
  make_data_file(fp2,num);
  fclose(fp2);
  fp3=fopen("Tree3Data","w");
  make_data_file(fp3,num);
  fclose(fp3);

  /*data読み込み*/
  fp1=fopen("Tree1Data","r");
  tree1=make_rand_tree(fp1);
  fclose(fp1);
  fp2=fopen("Tree2Data","r");
  tree2=make_rand_tree(fp2);
  fclose(fp2);
  fp3=fopen("Tree3Data","r");
  tree3=make_rand_tree(fp3);
  fclose(fp3);

  /*出力*/
  printf("行きがけの順で表示\n");
  print_pre_order(tree1);
  printf("\n");
  printf("通りがけの順で表示\n");
  print_mid_order(tree1);
  printf("\n");
  printf("帰りがけの順で表示\n");
  print_pos_order(tree1);
  printf("\n");

  TCellP node1,node2;
  printf("左に部分木結合\n");
  node1=tree1;
  while(node1->left!=NULL){
    node1=node1->left;
  }

  tree1=left_insert(tree1,node1,tree2);
  print_mid_order(tree1);
  print("\n");
  
  printf("右に部分木結合\n");
  node2=tree1;
  while(node2->right!=NULL){
    node2=node2->right;
  }

  tree1=right_insert(tree1,node2,tree3);
  print_mid_order(tree1);
  print("\n");

  return 0;
}
