#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
    char data[100];
    int reference[200];
    struct node *next;
};

typedef struct node *llist;

llist createList() {
return NULL;
}

void printList(llist l){
    if(l == NULL) {
        printf("List is empty");
        return;
    }
    while(l->next != NULL){
        for(int i = 0; i < strlen(l->data); i++) {
            printf("%c", l->data[i]);
        }
        for(int i = 0; l->reference[i] != 0; i++){
        printf("%d, ", l->reference[i]);
        }
        l = l->next;
        printf("\n");
    }
    for(int i = 0; i < strlen(l->data); i++) {
            printf("%c", l->data[i]);
    }
    for(int i = 0; l->reference[i] != 0; i++){
        printf("%d, ", l->reference[i]);
    }
    return;
}


llist addAtEnd(const llist l, char s[], int c){
    printf("Addatend");
    llist t = malloc(sizeof(struct node));
    for(int i = 0; i < strlen(s); i++){
        t->data[i] = s[i];
    } 
    t->data[strlen(s)] = '\0';
    for(int i = 0; i < sizeof(t->reference) / sizeof(t->reference[0]); i++){
        t->reference[i] = 0;
    }
    t->reference[0] = c;
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
/*
char sToLower(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] <= 90 && s[i] >= 65){
            s[i] = (s[i] + 32);
        }
    }
    return s;
}
*/

int scmp(char s1[], char s2[]){
    //printf("scmp");
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
    

llist checkIfInList(llist s, char str[], int lineCount){
    //printf("CheckInList");
    llist temp = s;
    int jCheck = 0;
    if(s == NULL){
        return addAtEnd(s, str, lineCount);
    }
        while(temp->next != NULL){
            if(scmp(temp->data, str) == 0){
                for(int j = 0; temp->reference[j] != 0; j++){
                    if(temp->reference[j] == lineCount){
                        return s;
                    }
                    jCheck++;
                }
                temp->reference[jCheck] = lineCount;
                return s;
            }
        temp = temp->next;
        }
        if(scmp(temp->data, str) == 0){
            for(int j = 0; temp->reference[j] != 0; j++){
                if(temp->reference[j] == lineCount){
                    return s;
                }
                jCheck++;
            }
            temp->reference[jCheck] = lineCount;
            return s;
        }
        addAtEnd(s, str, lineCount);
        return s;
    }


int main (){
    FILE *file;
    char filename[100];
    char line[200];
    const char *delimiters = " \t\n\r-,.?!@0123456789";
    
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

    int lineCount = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        /*
        while(referenceList->data != file){
            addAtEnd(referenceList, line, lineCount);
        }
            */
    char *token = strtok(line, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        referenceList = checkIfInList(referenceList, token, lineCount);
        // Subsequent calls: pass NULL to continue tracking the same string
        token = strtok(NULL, delimiters);
        }
    lineCount++;
    }

    printList(referenceList);

    fclose(file);
    return 0;
    }