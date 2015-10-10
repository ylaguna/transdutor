#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char palavra[200];
char* v[200];
int index_s = 0;

void e0(int);
void e1(int);
void e2(int);
void aceita();
void rejeita();
int isNumber(char);
int isLetter(char);

char* iniciaStr();




typedef struct schar{
  char c;
  schar* next;
} schar;
typedef struct str{
  int size;
  schar* first;
} str;


int main(){
  printf("Informe a palavra a ser Transduzida\n");
  gets(palavra);
  e0(0);


}


void aceita(){
  printf("aceita");
  system("pause");
  //free(string);
  exit(0);
}

void rejeita(){
  printf("rejeita");
  system("pause");
  //free(string);
  exit(0);
}

int isNumber(char c){
  return ( (int)c >= 48 && (int)c <= 57 );

}

int isLetter(char c){
  return ( (int)c >= 65 && (int)c <= 122 );
}


// controller
void e0(int idx){
  if( isLetter(palavra[idx]) ){
    iniciaStr();
    e1(idx+1);
  }
  if( isNumber(palavra[idx]) ){
    e2(idx+1);
  }
  if(palavra[idx] == ' '){
    e0(idx+1);
  }
  if(palavra[idx] == '\0'){
    aceita();
  }
  else{
    rejeita();
  }
}


// variavel
void e1(int idx){
  if( isLetter(palavra[idx]) ){
    e1(idx+1);
  }
  if( isNumber(palavra[idx]) ){
    e1(idx+1);
  }
  if(palavra[idx] == ' ' || palavra[idx] == '\0'){

    e0(idx+1);
  }
  else{
    rejeita();
  }
}


// numeral
void e2(int idx){
  if( isLetter(palavra[idx]) ){
    rejeita();
  }
  if( isNumber(palavra[idx]) ){
    e2(idx+1);
  }
  if(palavra[idx] == ' '){

    e0(idx+1);
  }
  else{
    rejeita();
  }
}


str* iniciaStr(){
  str string;

  string.size = 0;

}




