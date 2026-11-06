#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node {
    char data[100];
    int reference[50];
    struct node *next;
};

typedef struct node *llist;

llist createList() {
return NULL;
}
/*
void printList(llist l){
    if(l == NULL) {
        printf("List is empty");
        return;
    }
    while(l->next != NULL){
        printf("%d ", l->data);
        l = l->next;
    } 
    printf("%d ", l->data);
    return;
}
*/

llist addAtEnd(const llist l, char s[], int c[]){
    printf("Addatend");
    llist t = malloc(sizeof(struct node));
    for(int i = 0; i < strlen(s); i++){
        t->data[i] = s[i];
    } 
    for(int i = 0; i < sizeof(c); i++){
        t->reference[i] = c[i];
    }
    t->next = NULL;

    if(l == NULL) {
        return t;
    } 
    
    llist temp = l;
    
     
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = t;

    return l;
}

char sToLower(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] <= 90 && s[i] >= 65){
            s[i] = (s[i] + 32);
        }
    }
    return s;
}

int scmp(char s1[], char s2[]){
    printf("scmp");
    int length = 0;

    if(strlen(s1) > strlen(s2)){
        length = strlen(s1);
    } else {
        length = strlen(s2);
    }
    for(int i = 0; i < length; i++){
        if(s1[i] == s2[i]){
        } else if (s1[i] > s2[i]){
            return 1;
        }
        else if (s1[i] < s2[i]){
            return -1;
        }
    }
    return 0;
}
    

void checkIfInList(llist s, char str[], int lineCount){
    printf("CheckInList");
    if(s == NULL){
        addAtEnd(s, str, lineCount);
        return;
    }
        while(s->next != NULL){
            if(scmp(s->data, str) == 0){
                for(int j = 0; s->reference[j] != 0; j++){
                     s->reference[j] = lineCount;
                     return;
                }
            }
        s = s->next;
        }
        addAtEnd(s, str, lineCount);
        return;
    }


int main (){
    FILE *file;
    char filename[100];
    char line[200];
    const char *delimiters = " \t\n\r-,.?!@";
    
    /*
    printf("Enter the filename: ");
    scanf("%s", filename);
    */

    printf("Enter the filename: ");
    if (fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    } else {
        printf("File opened successfully.\n");
        }
    }

    llist referenceList = createList();

    int lineCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        /*
        while(referenceList->data != file){
            addAtEnd(referenceList, line, lineCount);
        }
            */
    char *token = strtok(line, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        sToLower(token);
        checkIfInList(referenceList, token, lineCount);
        // Subsequent calls: pass NULL to continue tracking the same string
        token = strtok(NULL, delimiters);
        }
    lineCount++;
    }


    fclose(file);
    return 0;
    }