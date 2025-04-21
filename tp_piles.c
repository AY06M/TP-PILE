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
int taille(noeud**p){
    noeud *temp=*p;
    int i=0;
    if(temp==NULL){
        printf("Erreur \n");
        return 0;
    }
    else{
        
        while(temp!=NULL){
            i++;
            temp=temp->prec;
        }
    }
    return i;
}
void inserermillieu(noeud **p, int d, int pos){
    noeud *temp=*p;
    noeud *nv=NULL;
    nv=(noeud *)malloc(sizeof(noeud));
    if(nv==NULL){
        printf("Erreur \n");
        return;
    }
    else{
        nv->d=d;
        if(pos==0){
            nv->prec=*p;
            *p=nv;
        }
        else{
            for(int i=0;i<pos-1 && temp!=NULL;i++){
                temp=temp->prec;
            }
            if(temp!=NULL){
                nv->prec=temp->prec;
                temp->prec=nv;
            }
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
    printf("taille: %d\n",taille(&p));
    printf("depilement:\n");
    depiler(&p);
    afficher(&p);
    printf("taille: %d\n",taille(&p));
    inserermillieu(&p,40,1);
    printf("inserer millieu:\n");
    afficher(&p);
}

