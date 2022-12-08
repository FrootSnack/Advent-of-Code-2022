#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 100000
#define FILE_NAME "input.txt"
#define MAX_LINE_LEN 256
#define MAX_ARG_LEN 32
#define MAX_CHILD_DIRS 128

struct Dir {
    struct Dir* parent;
    int ccount;
    struct Dir** children;
    char name[MAX_ARG_LEN];
    long size;
};

typedef struct Dir Dir; // ugly but necessary

// malloc list of children
void process_ls(Dir* dir, char* dirs[]) {
    if (dir->children != NULL) {
        printf("early return from process_ls()\n");
        return;
    }
    for (int i = 0; dirs[i] != NULL; i++) {
        printf("::%c", dirs[i][0]);
    }

    dir->children = malloc(dir->ccount * sizeof(Dir*));
    for (int i = 0; i < dir->ccount; i++) {
        Dir* child = malloc(sizeof(Dir));
        dir->children[i] = child;
        child->parent = dir;
        child->ccount = 0;
        child->children = NULL;
        strcpy(dir->children[i]->name, dirs[i]);
        child->size = 0;
    }
}

// 
int sum_below_max(Dir root, int max) {
    if (root.size > MAX_DIR_SIZE) {
        return 0;  
    }
    int sum = 0;
    for (int i = 0; i < root.ccount; i++) {        
        if (root.children[i]->size <= MAX_DIR_SIZE) {
            sum += sum_below_max(*root.children[i], max);
        }
    }
    return sum + root.size;
}

// free malloc-ed children from process_ls()
void clean_tree(Dir* root) {
    for (int i = 0; i < root->ccount; i++) {
        clean_tree(root->children[i]);
        free(root->children[i]);
        root->children[i] = NULL;
    }
    free(root->children);
    root->children = NULL;
}

// C file input method learned from https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/

int main() {
    Dir* root = malloc(sizeof(Dir));
    root->parent = NULL;
    // root->name = malloc(sizeof(char) * MAX_ARG_LEN);
    strcpy(root->name, "/");
    root->size = 0;
    root->children = NULL;

    FILE *input_file = fopen(FILE_NAME, "r");
    char buffer[MAX_LINE_LEN];

    while (fgets(buffer, sizeof(buffer), input_file)) {
        printf("\nIn dir %s\n", root->name);
        printf("Line: %s", buffer);
        char* tok = strtok(buffer, " ");
        // discard first token; for commands, always "$"
        tok = strtok(NULL, " ");
        if (!strcmp(tok, "ls\n")) { // if command is ls
            printf("ls detected\n");
            char* dirs[MAX_CHILD_DIRS];
            root->ccount = 0;
            int i = 0;
            long dir_file_size = 0;
            while (fgets(buffer, MAX_LINE_LEN, input_file)) {
                char* ls_tok = strtok(buffer, " ");
                if (!strcmp(ls_tok, "$")) { // if we have reached a command (i.e. ls is over)
                    break;
                }
                if (!strcmp(ls_tok, "dir")) { // if we have a directory
                    ls_tok = strtok(NULL, " ");
                    ls_tok[strcspn(ls_tok, "\n")] = 0; // remove trailing newline char
                    printf("-%s-", ls_tok);
                    strcpy(dirs[i++], ls_tok); // THIS LINE RIGHT HERE OFFICER
                    printf("[%s]\n", ls_tok);
                    root->ccount++;
                } else { // if we have a file
                    dir_file_size += strtol(ls_tok, NULL, 10);
                }
            }
            root->size = dir_file_size;
            printf("dir_file_size: %ld\n", dir_file_size);
            printf("dir preprocessing done\n");
            // recurse up and add size to all parents
            Dir* curr = root;
            while (curr->parent != NULL) {
                curr = curr->parent;
                curr->size += dir_file_size;
            }
            printf("recursion done\n");
            process_ls(root, dirs);
            printf("processing done\n");
        } else if (!strcmp(tok, "cd")) { // if command is cd
            printf("cd detected\n");
            tok = strtok(NULL, " ");
            if (!strcmp(tok, "..\n")) { // if we have cd ..
                printf(".. detected\n");
                root = root->parent;
            } else { // if we have cd [dir]
                printf("dir detected\n");
                for (int i = 0; i < root->ccount; i++) {
                    if (!strcmp(root->children[i]->name, tok)) {
                        root = root->children[i];
                        break;
                    }
                }
            }
        }
    }

    printf("We made it out!");

    printf("%d", sum_below_max(*root, MAX_DIR_SIZE));

    clean_tree(root);

    return 0;
}