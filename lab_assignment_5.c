#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){
    //find length of head, finding length of LL/# of nodes
    int len = 0;

    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head){
    //str[i]=abcdef
    //str[i+1]='\0'
    int len = length(head);
    char* str = (char*)malloc((len+1)*sizeof(char));
    int i =0;

    while(head != NULL){
        //allocates each letter to str array
        str[i] = head->letter;
        head = head->next;
        i++;
    }
    //set last char to NULL
    str[i] = '\0';
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){
    //temp=pHead
    //while(temp->next){newNode=c; }
    node* newNode = (node*)malloc(sizeof(node));
    //set char to letter of node
    newNode->letter = c;
    newNode->next = NULL;

    //when head=NULL, set newNode to head
    if(*pHead == NULL){
        *pHead = newNode;
    }

    else{
        node* currNode = *pHead;

        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
    //
    node* curr = *pHead;

    while(curr != NULL){
        //temp = current
        node* temp = curr;
        curr = curr->next;

        //deletes temp node
        free(temp);
    }
    *pHead = NULL;
}

int main(void){
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;

    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0){
        fscanf(inFile, " %d\n", &strLen);

        for (i = 0; i < strLen; i++){
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
    
        deleteList(&head);
        if (head != NULL){
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}