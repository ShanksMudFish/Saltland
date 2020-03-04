#include <stdio.h>
#include <stdlib.h>

struct Vector {
int capacidad;
int cuantos_hay;
int *datos;
};

int agrandar ( struct Vector *vector){
int *otro = NULL;
if(vector==NULL){
return -1;//vector es null
}else{
otro = (int *) malloc (sizeof(int) * 2 * vector -> capacidad);
if(otro==NULL){
return -2;//no hay memoria
}
for(int i = 0 ; i < vector ->cuantos_hay ; i++){
*(vector -> datos + i) = *(otro + i);//al obtener la direccion de memoria tendriamos la del primero, entonces le sumamos i para que solo vaya recorriendo
//en otras palabras es como tener 0+0,0+1,0+2... etc
}
free(vector -> datos);
vector -> capacidad = vector -> capacidad * 2;
vector -> datos = otro;
//Solo actualizamos los datos de vector
return 0;//salio bien el proceso
}
}

int hay_espacio(struct Vector *vector){

if(vector==NULL){
return 1;//como es nulo, no hay espacio, por lo tanto regresamos un 1;
}
if(vector->cuantos_hay < vector->capacidad){
return 0;//Hay espacio para agregar
}else{
return 1;//No hay espacio
}
}

int agregar ( struct Vector *vector, int dato){

if(vector==NULL){
return -1;//El vector es nulo
}
if(hay_espacio(vector)==1){
if(agrandar(vector)!=0){
return -2;//No hay espacio
}
}
*(vector->datos + vector->cuantos_hay + 1) = dato;
return 0;//Todo salio bien
vector->cuantos_hay = vector->cuantos_hay + 1 ;//Aqui no se usa el asterisco porque cuantos_hay ya es una variable

}

int mostrar( struct Vector *vector){

if(vector == NULL){
return -1;//El vector es nulo
}
for(int i = 0 ; i < vector->cuantos_hay ; i++){
printf("%d",*(vector->datos + i));
}
printf("\n");

}

int iniciar(struct Vector *vector){

if(vector==NULL){
return -1;
}
vector->datos = (int *) malloc (sizeof (int));
if(vector->datos==NULL){
return -2;//No hay memoria
}
vector->cuantos_hay = 0;
vector->capacidad = 1;
return 0;
}

int main (void){

int n = 0;
struct Vector vector;//se tiene que inicializar el vector porque si no truena xd
iniciar(&vector);
printf("\nDame el valor de n\n");
scanf("%d",&n);
for (int i = 0 ; i <= n ; i++){
agregar(&vector, i);
mostrar(&vector);
}
return 0;
}
