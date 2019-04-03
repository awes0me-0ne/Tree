#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

//関数定義
void make_data_file(FILE *fp,int n){
  int i=0;
  int idata;
  for(i=0;i<n;i++){
    idata=(int)rand()%MAX;
    fprintf(fp,"%5d\n",idata);
  }
  return ;
}

TREE make_rand_tree(FILE* fp){
  int idata;
  TREE tree=make_tree();
  fscan(fp,"%d",&idata);
  TCellP new_cell=make_new_cell(idata);
  tree=new_cell;
  TCellP tcell=NULL;//木を移動して探索
  while(fscan(fp,"%d",&idata)!=EOF){
    new_cell=make_new_cell(idata);
    tcell=tree;
    while(1){
      int lr=((int)rand())%2;
      if(lr==0){
	//左を探索
	if(tcell->left==NULL){
	  tcell->left=new_cell;
	  break;
	}else{
	  //右を探索
	  if(tcell->right==NULL){
	    tcell->right=new_cell;
	    break;
	  }else{
	    tcell=tcell->right;
	  }
	}
      }
    }
    return tree;
  }
}
