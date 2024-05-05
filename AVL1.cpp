
/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation. :-Dictionary using BST*/

/*A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Height balance tree and find the complexity for finding a keyword.  :- AVL*/




#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class dict{
 char word[20],mean[50];
 dict* left, * right;
 int ht;


 public :
  dict* create(dict* root);
  dict* insert(dict* root, char word[], char mean[]);

  void display(dict*);
  int height(dict*);
  dict* rotateright(dict*);
  dict* rotateleft(dict*);

  int BF(dict*);

  dict* deletion(dict*,char*);
  dict* RR(dict* T);
  dict* LL(dict* T);
  dict* RL(dict* T);
  dict* LR(dict* T);

  
};


dict* dict::create(dict* root){

  int n,i;
  char w[20], m[50];
  cout<<"Enter total Number of words:";
  cin>>n;

 for(i=0;i<n;i++){
 cout<<"Enter word "<<i+1;
 cin>>w;

cout<<"Enter meaning";
cin>>m;

 root=insert(root,w,m);

}

return root;

}


dict* dict::insert(dict* root,char w[], char m[]){

  if(root==NULL){
   root=new dict;
   strcpy(root->word,w);
   strcpy(root->mean,m);
   root->left=NULL;
   root->right=NULL;
   return root;

  }

    else{
      if(strcmp(w, root->word) > 0){
         root->right=insert(root->right,w,m);
           if(BF(root)==-2){
               if(strcmp(w,root->word) > 0)
                    root=RR(root);
               else
                    root=RL(root);
             
             }


        }
 
      else{

         if(strcmp(w,root->word) < 0){

             root->left=insert(root->left,w,m);
             if(BF(root)==2){
                 if(strcmp(w,root->word) < 0)
                     root=LL(root);
                 else
                     root=LR(root);


               }
             }

          }


    }

   root->ht=height(root);
   return root;

}


void dict::display(dict* root){
   if(root!=NULL){
      display(root->left);
      cout<<"word is "<<root->word<<"-"<<root->mean;
      display(root->right);

     }

}




int dict::height(dict* root){
  int lh,rh;

 if(root==NULL)
   return 0;
 
 if(root->left==NULL)
   lh=0;
 else
   lh= 1+root->left->ht;


 if(root->right==NULL)
   rh=0;
 else
   rh= 1+root->right->ht;

if(lh>rh){
   return(lh);
 }
else{
   return(rh);
 }


}



dict* dict::rotateright(dict* x){

  dict* y;
  y= x->left;
  x->left=y->right;
  y->right=x;

 x->ht=height(x);
 y->ht=height(y);

 return(y);


}


dict* dict::rotateleft(dict* x){
  dict* y;
  y=x->right;
  x->right=y->left;
  y->left=x;

  x->ht=height(x);
  y->ht=height(y);
 
  return(y);

}


int dict::BF(dict* root){
  int lh,rh;
  if(root==NULL)
    return 0;
  
  if(root->left==NULL)
    lh=0;
  else
    lh= 1+root->left->ht;

  if(root->right==NULL)
    rh=0;
  else
    rh= 1+root->right->ht;

  int z=lh-rh;
  return(z);


}




dict* dict::deletion(dict* T, char* w){
  dict* p;
  if(T==NULL){
   cout<<"Word not found";
   return T;
  }


  else if(strcmp(w,T->word) > 0){
   T->right=deletion(T->right,w);

   if(BF(T)==2){
     if(BF(T->left) >=0)
       T=LL(T);
     else
       T=LR(T);

  }
     

  }

 else if(strcmp(w,T->word) < 0){
   T->left=deletion(T->left,w);

   if(BF(T)==2){{
      if(BF(T->right) <=0)
         T=RR(T);
      else
         T=RL(T);

   }
 

  }

else{
   if(T->right!=NULL){

    p=T->right;
    while(p->left!=NULL)
      p=p->left;
    strcpy(T->word,p->word);
    strcpy(T->mean,p->mean);
    T->right=deletion(T->right,p->word);
  
   if(BF(T)==2){
      if(BF(T->left) >=0)  
         T=LL(T);
      else
          T=LR(T);

   }

   }
 
 else
      return(T->left);

  
}

T->ht=height(T);
 return(T);

}





dict* dict::RR(dict* T){
   T=rotateleft(T);
   return(T);

}

dict* dict::LL(dict* T){
   T=rotateright(T):
   return(T);

}


dict* dict::LR(dict * T){
 T->left=rotateleft(T->left);
 T=rotateright(T);
 return(T);
}


dict* dict::RL(dict* T){
 T->right=rotateright(T->right);
 T=rotateleft(T);
 return(T);

}




int main(){
  int ch;
  dict d, * root;

  root=NULL;	
  char w[20], m[50];
  cout<<"Dictionary";
  do{
   cout<<"Menu";
   cout<<"1.create \n 2.Insert \n 3.Delete \n 4.display \n 5.exit";
   cout<<"Enter your choice";
   cin>>ch;

  switch(ch){

  case 1: root=d.create(root);
          break;
  case 2: cout<<"Enter word:";
          cin>>w;
          cout<<"enter meaning :";
          cin>>m;
         root=d.insert(root,w,m);
          break;
 case 3: cout<<"Enter word to delete :";
          cin>>w;
         root=d.deletion(root,w);
         break;
 case 4: d.display(root);
        break;
 case 5 : break;
 default : cout<<"Invalid choice ";


  }


  }while(ch!=5);
    
   return 0;
}
