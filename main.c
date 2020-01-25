#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

int main(int argc , char* argv[]) {

    node *root=newNode();
    int size=0;
    char *word=NULL;
    char c;
    char *biggerword=NULL;
    int length=0;
    boolean tag = FALSE;

    word =(char*)malloc(1*sizeof(char));
    if (word==NULL){
        printf("no place");
        exit(1);
    }


    if(strcmp(argv[1],"r")==0 &&argc>=2){
        tag=TRUE;
    }

    while ((c=getc(stdin))!=EOF){

        if (c >= 'A' && c <= 'Z' && c != '\t' && c != ' ' && c != '\n' && c != '\0') {
            char a = c + 32;
            c = a;
        }

        if (c >= 'a' && c <= 'z' && c != '\t' && c != ' ' && c != '\n' && c != '\0') {

            if (length == SIZEOFWORD){
                biggerword=(char*)realloc(word, (size+SIZEOFWORD)* sizeof(char)); 
                length+=SIZEOFWORD;

                if( word!=NULL&& biggerword==NULL){
                    free(word);
                    printf("no place");
                    exit(1);
                }
                word =(char*)calloc(length, sizeof(char));
                strcpy(word,biggerword);
                free(biggerword);
            }
            word[length]=c;
            length++;
        }
        if (c == '\t' || c == ' ' || c == '\n' || c == '\0'){
            word[length]='\0';
            insert(&root,word);
            length=0;
        }

    }
    if (tag==FALSE){
        print(root,word,0);
    }
    else{
       
        printR(root,word,0);
    }
    freetree(root);
    free(word);

    return 0;
}