#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char palavra[200];

void e0(int);
void e1(int);
void e2(int);
void aceita();
void rejeita();
int main(){
  printf("Informe a palavra a ser testada\n");
  gets(palavra);
  e0(0);
}


void aceita(){
  printf("aceita");
  exit(0);
}

void rejeita(){
  printf("rejeita");
  exit(0);
}

void e0(int idx){
  if(palavra[idx] == 'a'){
    e1(idx+1);
  }
  if(palavra[idx] == '0'){
    e2(idx+1);
  }
  if(palavra[idx] == 'e'){
    e0(idx+1);
  }
  if(palavra[idx] == '\0'){
    aceita();
  }
  else{
    rejeita();
  }
}

void e1(int idx){
  if(palavra[idx] == 'a'){
    e1(idx+1);
  }
  if(palavra[idx] == '0'){
    e1(idx+1);
  }
  if(palavra[idx] == 'e'){
    e0(idx+1);
  }
  else{
    rejeita();
  }
}

void e2(int idx){
  if(palavra[idx] == 'a'){
    rejeita();
  }
  if(palavra[idx] == '0'){
    e2(idx+1);
  }
  if(palavra[idx] == 'e'){
    e0(idx+1);
  }
  else{
    rejeita();
  }
}