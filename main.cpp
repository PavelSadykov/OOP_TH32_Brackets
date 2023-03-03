//
//  main.cpp
//  ООП ДЗ 32 Алгоритм подсчета скобок
//
//  Created by Павел on 21.02.2023.
//
#include <utility>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <unistd.h>
 #include <string>
 #include <vector>
 #include <stdio.h>
 #include <memory>
 #include <cstdlib>
 #include <map>

int Find2Pos( char line[], const char c);
void check_brackets(char line[]);
void search_inputError(char line[],int Pos1, int Pos2, int secondPos1, int secondPos2);

int main(int argc, const char * argv[]) {
    std::cout << "Введите строку,\nиспользуя пары круглых скобок \n-> ";
    char line[]{};
    int n=100;
    int getline(char line[], int n);
    std::cin.getline(line,n);
    std::cout<<"Введена строка : \n   "<<line<<std::endl;
    check_brackets(line);
    return 0;
}
void search_inputError(char line[],int Pos1, int Pos2, int secondPos1, int secondPos2){
// ПРОВЕРКА КОРРЕКТНОГО ВВОДА ДАННЫХ
    int counter=0;
     for (int i = 0; i < strlen(line); i++){//проверка на парность скобок
       switch(line[i]){
         case '(': counter++; break;
         case ')': counter--; break;
       }}
               if(counter!=0){
                   std::cout<<"счетчик пар - "<<counter<<std::endl;
                   std::cout<<"НЕКОРРЕКТНЫЙ ВВОД ДАННЫХ - введены непарные скобки !!! \n\n";
                   exit(0);
               }
         if(secondPos1>0 || secondPos2>0){// проверка на лишние  парные скобки
             if(Pos2>secondPos1 || Pos2>secondPos2){
         std::cout<<"НЕКОРРЕКТНЫЙ ВВОД ДАННЫХ - введены лишние скобки !!! \n\n";
         exit(0);
         }}}


int Find2Pos(char line[], const char c){//функция вычисления второго вхождения
    int pos = 0, count=0;
        for(int i=0;i< strlen(line);i++){
            if(line[i]== c )
                count++;
            if(count == 2){
                pos=i;
            break;
            }}
    return pos;
}

void check_brackets(char line[]){
    int secondPos1=0,secondPos2=0,Pos1=0, Pos2=0, counter=0,num =0;
    char *pd1,*pd2;
    char ch1='(', ch2=')';

    std::cout<<"\n\ВЫВОД ДАННЫХ "<<std::endl;
    std::cout<<"Длина строки "<< strlen(line)<<std::endl;
        secondPos1=Find2Pos(line, '(');
    secondPos2=Find2Pos(line, ')');
    // Позиции 1 и 2  вхождения скобки (
    pd1 = strchr( line, ch1 );
    Pos1 = (int)(pd1 - line );
    if ( pd1 != NULL ){
          //printf( "Позиция 1-го вхождения  %c  : %d\n", ch1, Pos1 );
          //std::cout <<"Позиция 2-го вхождения  (  : " <<secondPos1<<std::endl;
    }else{
        std::cout<<"НЕКОРРЕКТНЫЙ ВВОД ДАННЫХ - отсутствуют парные скобки !!! \n\n";
        exit(0);
    }

   
        pd2 = strchr( line, ch2 );
        Pos2 = (int)(pd2 - line );
    if ( pd2 != NULL ){
       //printf( "Позиция 1-го вхождения  %c  : %d\n",ch2, Pos2 );
    //std::cout <<"Позиция 2-го вхождения  )  : " <<secondPos2<<std::endl;
    }else{
        std::cout<<"НЕКОРРЕКТНЫЙ ВВОД ДАННЫХ - отсутствуют парные скобки !!! \n\n";
        exit(0);
    }
        
    // дополнительная проверка корректного  ввода данных
    search_inputError(line, Pos1, Pos2,  secondPos1,  secondPos2);
       
        std::map<int,int>myMap;
        int Key=0, Val=0;
        for(int i = 0; i < strlen(line); i++){
                if(line[i] == ch1){
                Key = i;
            }
            if(line[i] == ch2){
                Val = i;
                myMap.insert(std::pair<int, int>(Key, Val));
            }}
      //  for(auto it = myMap.begin(); it != myMap.end(); it++) {
       //        std:: cout << it->first << " " << it->second <<"\n";
       //     }
        
    for(auto it = myMap.begin(); it != myMap.end(); it++) {
        num  =    ( it->second )-((it->first)+1);
        std::cout<<"количество элементов в паре скобок : "<<num<<std::endl;
        counter++;
        }
 std::cout<<"Количество пар скобок : "<<counter<<std::endl;
 std::cout<<std::endl;
    
}
        
    
