#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int d;
   struct noeud *prec;
}noeud;

void empiler(noeud **p, int d){
    noeud *nv;
    nv=(noeud *)malloc(sizeof(noeud));
    if(nv==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        nv->d=d;
        nv->prec=*(p);
        *(p)=nv;
    }

}

void depiler(noeud **p){
    noeud *temp;
    if(*p==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        temp=*p;
        *p=(*p)->prec;
        free(temp);
    }
}
void afficher(noeud**p){
    noeud *temp=*p;
    if(temp==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->d);
            temp=temp->prec;
            printf("\n");
        }
    }
}
void main(){
    noeud *p=NULL;
    printf("empilement:\n");
    empiler(&p,10);
    empiler(&p,20);
    empiler(&p,30);
    afficher(&p);
    printf("depilement:\n");
    depiler(&p);
    afficher(&p);
}

