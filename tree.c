#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

node* newNode()
{
    node *answer = (node *)malloc(sizeof(node));
    if ( answer)
    {
        int i;
        answer->count = 0;
        for (i = 0; i < LETTERS; i++)
          answer->children[i] = NULL;
    }
    return  answer;
}

void insert(node **root,  char* in)
{
    int i;
    int place;
    int length = strlen(in);
    node *move = *root;
    for (i = 0; i < length; i++)
    {
        place = in[i]-'a';
        if (!move->children[place])
            move->children[place] = newNode();
        move = move->children[place];
        move->letter=in[i];

    }
    
    move->count=move->count+1;
}

int isleaf(node *check){
    boolean flag=FALSE;
    for (size_t i = 0; i < LETTERS; i++)
    {
        if(check->children[i])
            flag=TRUE;
    }
    return flag;
}

void print(node *root, char * str, int place) {
    if(isleaf(root)==FALSE)
    {
        str[place]='\0';
        printf("%s\t%ld\n",str,root->count);
        return;
    }
    if (root->count>0){
        str[place]='\0';
        printf("%s\t%ld\n" , str,root->count);
    }
    for (size_t i = 0; i <LETTERS; i++)
    {
        if(root->children[i]){
            str[place]=root->children[i]->letter;
            print(root->children[i],str,place+1);
        }
    }
}


void printR(node *root, char *str, int place)
{

    for (int i = LETTERS-1;i>=0;i--){
        if (root->children[i]){
            str[place] =root->children[i]->letter;
            printR(root->children[i], str, place + 1);
        }
    }

    if (isleaf(root) == FALSE){
        str[place] ='\0';
        printf("%s\t%ld\n", str, root->count);
        return;
    }

    if (root->count > 0){
        str[place] = '\0';
        printf("%s\t%ld\n", str, root->count);
    }

}

void freetree(node* root) { 
    if (!root) return;  
    for (int i = 0; i < LETTERS; i++){
       freetree(root->children[i]);
    }

    free(root);
}