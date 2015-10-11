//
//  third.c
//  
//
//  Created by Hunter Betz on 9/12/15.
//
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int value;
    struct node *next;
    
};

struct node *root;

void insert(struct node *, int);
void print_list(struct node *, int);
void delete(struct node **, int);

int main(int argc, char *argv[]) {
    
    
    root = (struct node *) malloc(sizeof(struct node));
    root->next = NULL;
    root->value = 0;
    
    struct node *pointer;
    pointer = root;
    
    
    FILE *file;
    char lines[1000];
    //int nums[1000];
    
    file = fopen(argv[1], "r");
    
    if (!file) {
        
        printf("error\n");
        return 0;
        
    }
    
    char task;
    int value;
    int line = 0;
    int max = 0;
    
    while (fgets(lines, sizeof lines, file) != NULL) {
        
        sscanf(lines, "%c %d", &task, &value);
        
        if (task == 'i') {
            if (line == 0) {
                root->value = value;
            } else {
                insert(root, value);
            }
            
        } else if (task == 'd') {
            
            delete(&root, value);
            
        }
        
        
        line++;
        if (value > max) {
            max = value;
        }

    }
    
    /*for (int i = 0; i < 1000; i++) {
        
        if (nums[i] > -1) {
            
            printf("%d ", nums[i]);
            
        }
        
    }*/
    print_list(root, max + 1);
    fclose(file);
    
    
    return 0;
}


void insert(struct node *root, int val) {
    
    struct node *pointer = root;
    
    //moves to the end of list
    while (pointer->next != NULL) {
        
        pointer = pointer->next;
        
    }
    
    //inserts node at end of list
    pointer->next = malloc(sizeof(struct node));
    pointer = pointer->next;
    pointer->value = val;
    pointer->next = NULL;
    
    return;
}

void print_list(struct node *root, int n) {
    
    int *sort_array;
    struct node *current = root;
    
    sort_array = (int *)malloc(sizeof(int) * n);
    
    int i;
    
    for (i = 0; i < n; i++) {
        sort_array[i] = -1;
    }
    
    while (current != NULL) {
        sort_array[current->value] = current->value;
        current = current->next;
    }
    
    for (i = 0; i < n; i++) {
        if(sort_array[i] >= 0) {
            printf("%d\n", sort_array[i]);
        }
    }
    
    free(sort_array);

    
}

void delete(struct node **root, int value) {
    
    struct node *pointer;
    struct node *temp = NULL;
    
    pointer = *root;
    
    if (pointer->value == value) {
        pointer = (*root)->next;
        free(*root);
        *root = pointer;
        
        return;
    }
    
    while (pointer->next->value != value) {

        pointer = pointer->next;
        
    }
    
    temp = pointer->next;
    pointer->next = temp->next;
    free(temp);
    
    
}

