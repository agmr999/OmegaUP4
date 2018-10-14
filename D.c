#include <stdio.h>

#include <stdlib.h>



typedef struct arbol arbol;



struct arbol{
	
	int dato;
	
	arbol *izq;
	
	arbol *der;
	
};



arbol *crearnodo(int dato){
	
	arbol *nuevo=NULL;
	
	nuevo=(arbol *)malloc(sizeof(arbol));
	
	nuevo->dato=dato;
	
	nuevo->der=NULL;
	
	nuevo->izq=NULL;
	
	return nuevo;
	
}





void insertarecursivo(arbol **r,int dato){
	if (*r==NULL){
		arbol* nuevo=crearnodo(dato);
		*r=nuevo;
	}
	else{
		arbol *aux= *r;
		if(aux->izq==NULL){
			insertarecursivo(&aux->izq,dato);
		}
		else{
			insertarecursivo(&aux->der,dato);
		}
	}
}


void insertaCompara(arbol **r,int dato, int n,int i,int *arr){	
	if(*r==NULL){
		arbol* nuevo=crearnodo(dato);
		*r=nuevo;
	}
	if((n*2)<=i){
		arbol *aux= *r;
		int a=(2*n);
		int b=2*n+1;
		insertaCompara(&aux->izq,arr[a-1],a,i,arr);
		insertaCompara(&aux->der,arr[b-1],b,i,arr);
	}
}

arbol* inorden(arbol *r,int dato){	
	if(r!=NULL){
		
		inorden(r->izq,dato);
		inorden(r->der,dato);
		}
	}

void preorden(arbol *r){	
	if(r!=NULL){
		printf("%d ",r->dato);
		preorden(r->izq);
		preorden(r->der);
	}
}


arbol* buscarElemento(arbol* r, int elemento){	
	if(r==NULL){
		return NULL;
	}else{
		if(r->dato==elemento){
			return r;
		}else{
				return buscarElemento(r->der,elemento);
				return buscarElemento(r->izq,elemento);
		}
	}
}


int main() {	
	int i,x;
	arbol *raiz=NULL;
	scanf("%d",&i);
	int arr[i];
	for(int a=0;a<i;a++){
		scanf("%d",&x);
		arr[a]=x;
	}
	insertaCompara(&raiz,1,1,i,arr);
	preorden(buscarElemento(raiz,2));
	return 0;
}
