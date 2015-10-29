#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int idx = 0;
char palavra[200];
char buffer[200];
int  buffer_size = 0;

char v[200][200];
char *p[200];
int index_v = 0;
int index_p = 0;


void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();
int isNumber(char);
int isLetter(char);

void iniciaStr(char);
void addStr(char);
void copiaChar(char *, char *);
int compString(char*, char*);
char* retStr();

void iniciaNbr(char);
void addNbr(char);
void retNbr();

void printVars();
void printPal();

int main(){
  p[0]= "LET";
  p[1]= "IF";
  p[2]= "ELSE";
  p[3]= "THEN";
  p[4]= "GOTO";
  p[5]= "PRINT";
  p[6]= "READ";
  p[7]= "END";
  p[8]= "OF";
  
  printf("Informe a palavra a ser Transduzida\n");
  gets(palavra);
  e0();
}


int isNumber(char c){
  return ( (int)c >= 48 && (int)c <= 57 );

}

int isLetter(char c){
  return ( ((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122));
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
  else if(palavra[idx] == '%'){
    e6();
  }
  else if(palavra[idx] == ':'){
    e3();
  }
  else if(palavra[idx] == '\0'){
    printVars();
    printPal();
  }
  else{
    e5();
  }
}


// variavel
void e1(){
  if( isLetter(palavra[idx]) || isNumber(palavra[idx]) ){
    addStr(palavra[idx]);
    idx++;
    e1();
  } else {
    retStr();
    e0();
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
  } else {
    retNbr();
    e0();
  }
}
void e3(){
  printf("%c", palavra[idx]);
  idx++;
  if(palavra[idx]=='='){
    e4();
  }
}
void e4(){
  printf("%c", palavra[idx]);
  idx++;
  e0();
}
void e5(){
  printf("%c", palavra[idx]);
  idx++;
  e0();
}

void e6(){
  idx ++;
  if(palavra[idx] == '\0'){
    e0();
  }else {
    e6();  
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

void copiaChar(char * destino, char * origem){
  //&destino = &origem;
}
// Função para comparação de strings, utilizada na linha 154
int compString(char* ch1, char* ch2){
  int i = 0;
  while ( ch2[i] != '\0' ){
        if (ch1[i] == '\0' || ch1[i]>ch2[i] || ch2[i]>ch1[i]){
			return 1;
		}
        i++;
  }

    if (ch1[i] != '\0'){
		return 1;
	}

    return 0;
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
  for(i=0; i < 9; i++){
    if( compString( p[i], buffer ) == 0){
      printf("P(%d)", i);
      return "ok";
    }
  }
  for(i=0; i < index_v; i++){
    if( compString( v[i], buffer ) == 0){
      printf("V(%d)", i);
      return "ok";
    }
  }
  

  memcpy(v[index_v], buffer, buffer_size);
  printf("V(%d)", index_v);
  index_v++;
  buffer[0] = '\0';
  buffer_size = 0;
  return "new";
}

void retNbr(void){
  printf("N(%s)", buffer);
  buffer[0] = '\0';
  buffer_size = 0;
}


void printVars(void){
  puts("\n------- Vars -------\n");
  int i;
  for(i=0; i < index_v; i++){
    printf("V(%d) = %s\n", i, v[i]);
  }

}
void printPal(void){
  puts("\n------- Palavras -------\n");
  int i;
  for(i=0; i < 9; i++){
    printf("P(%d) = %s\n", i, p[i]);
  }


  system("pause");
  exit (0);
}
