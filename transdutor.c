#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int idx = 0;
char palavra[200];
char buffer[200];
int  buffer_size = 0;

char v[200][200];
int index_v = 0;

void e0();
void e1();
void e2();

void rejeita();
int isNumber(char);
int isLetter(char);

void iniciaStr(char);
void addStr(char);
char* retStr();

void iniciaNbr(char);
void addNbr(char);
void retNbr();

void printVars();

int main(){
  printf("Informe a palavra a ser Transduzida\n");
  gets(palavra);
  e0();
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
void e0(){
  if( isLetter(palavra[idx]) ){
    iniciaStr(palavra[idx]);
    idx++;
    e1();
  }
  else if( isNumber(palavra[idx]) ){
    iniciaNbr(palavra[idx]);
    idx++;
    e2();
  }
  else if(palavra[idx] == ' '){
    idx++;
    e0();
  }
  else if(palavra[idx] == '\0'){
    printVars();
  }
  else{
    rejeita();
  }
}


// variavel
void e1(){
  if( isLetter(palavra[idx]) || isNumber(palavra[idx]) ){
    addStr(palavra[idx]);
    idx++;
    e1();
  } else if(palavra[idx] == ' ' || palavra[idx] == '\0'){
    retStr();
    e0(); // voltando com o mesmo idx 
  } else {
    rejeita();
  }
}


// numeral
void e2(){
  if( isLetter(palavra[idx]) ){
    retNbr();
    e0();
  } else if( isNumber(palavra[idx]) ){
    addNbr(palavra[idx]);
    idx++;
    e2();
  } else if(palavra[idx] == ' ' || palavra[idx] == '\0'){
    retNbr();
    e0(); 
  } else {
    rejeita();
  }
}


void iniciaStr(char fchar){
  buffer[0] = fchar;
  buffer[1] = '\0';
  buffer_size = 1;
}

void iniciaNbr(char fchar){
  iniciaStr(fchar);
}


void addStr(char c){
  buffer[buffer_size] = c;
  buffer_size++;
  buffer[buffer_size] = '\0';
}

void addNbr(char c){
  addStr(c);
}

char* retStr(void){
  int i;
  for(i=0; i < index_v; i++){
    if( strcmp ( v[i], buffer ) == 0){
      printf("V(%d) -- ", i);
      return "ok";
    }
  }

  memcpy(v[index_v], buffer, buffer_size);
  printf("V(%d) -- ", index_v);
  index_v++;
  buffer[0] = '\0';
  buffer_size = 0;
  return "new";
}

void retNbr(void){
  printf("N(%s) -- ", buffer);
  buffer[0] = '\0';
  buffer_size = 0;
}

void printVars(void){
  puts("\n------- Vars -------\n");
  int i;
  for(i=0; i < index_v; i++){
    printf("V(%d) = %s\n", i, v[i]);
  }


  system("pause");
}
