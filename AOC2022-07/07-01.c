#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 100000
#define FILE_NAME "input.txt"
#define MAX_LINE_LEN 256
#define MAX_ARG_LEN 32
#define MAX_CHILD_DIRS 128

typedef struct {
    Dir* parent;
    int ccount;
    Dir** children;
    char* name;
    int size;
} Dir;

void process_ls(Dir* dir, char* dirs[]) {
    if (dir->children == NULL) {
        dir->children = malloc(dir->ccount * sizeof(Dir*));
        for (int i = 0; i < dir->ccount; i++) {
            dir->children[i] = malloc(sizeof(Dir));
            strcpy(dir->children[i]->name, dirs[i]);
        }
    }
}

// god the size part is going to be harder than I thought
int get_sum_largest(Dir* root) {
    int sum = 0;
    for (int i = 0; i < root->ccount; i++) {
        
        if (root->children[i]->size <= MAX_DIR_SIZE) {
            sum += root->children[i]->size;
        }
    }
    return sum;
}

void clean_tree(Dir* root) {
    for (int i = 0; i < root->ccount; i++) {
        clean_tree(root->children[i]);
        free(root->children[i]);
        root->children[i] = NULL;
    }
    free(root->children);
    root->children = NULL;
}

int main() {
    Dir root;
    root.name = "/";
    root.size = 0;
    FILE *input_file = fopen(FILE_NAME, "r");
    char buffer[MAX_LINE_LEN];

    while (fgets(buffer, MAX_LINE_LEN, input_file)) {
        char* tok = strtok(buffer, " ");
        // discard first token; for commands, always "$"
        tok = strtok(NULL, " ");
        if (!strcmp(tok, "ls")) { // if command is ls
            char* dirs[MAX_CHILD_DIRS];
            root.ccount = 0;
            int i = 0;
            do {
                // handling here for files and directories
            } while (fgets(buffer, MAX_LINE_LEN, input_file));
            process_ls(&root, dirs);
        } else if (!strcmp(tok, "cd")) { // if command is cd
            tok = strtok(NULL, " ");
            if (!strcmp(tok, "..")) { // if we have cd ..
                root = *root.parent;
            } else { // if we have cd [dirname]
                for (int i = 0; i < root.ccount; i++) {
                    if (!strcmp(root.children[i], tok)) {
                        root = *root.children[i];
                        break;
                    }
                }
            }
        }
    }

    printf("%d", get_sum_largest(&root));

    clean_tree(&root);

    return 0;
}