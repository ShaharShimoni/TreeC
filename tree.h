#define LETTERS ((int)26)
#define SIZEOFWORD 20


typedef struct node{
    char letter;
    long unsigned int count;
    struct node* children [LETTERS];
} node;
void insert(node **root, char* in);
int isleaf(node *check);
void print(node *root, char * str, int place);
void printR(node *root, char *str, int place);
void freetree(node* root);

node* newNode();

typedef enum {
    FALSE=0 ,TRUE=1
} boolean;

