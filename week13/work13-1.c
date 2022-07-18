// 必須課題 13-1

#include <stdio.h>
#include <stdlib.h>
#include </Users/yanofuki/puroenn2/week12/print_tree.c>

struct node *new_node(int key) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    p->key = key;
    p->parent = NULL;
    p->right = NULL;
    p->left = NULL;

    return p;
}

/* 全てのnodeのメモリを開放する関数 */
void free_tree(struct node *node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int insert(int key, struct node *root) {
    static int count;
    struct node n[10];

    n[count] = *new_node(key);
    *root = n[0];

    // n[0]->left = *new_node(0);
    // n[0]->right = new_node(0);
    // n[0]->parent = NULL;

    // print_tree(root);
    // free_tree(root);

    // n[count] = new_node(key);
    // if (n[count]->key < n[count - 1]->key) {
    //     n[count - 1]->left = n[count];
    //     n[count]->parent = n[count - 1];
    // } else if (n[count]->key > n[count - 1]->key) {
    //     n[count - 1]->right = n[count];
    //     n[count]->parent = n[count - 1];
    // }
    

    return 1;
}


int main(void)
{
    int key;
    struct node *root = new_node(0), *n[10];

    // printf("挿入するキーを入力して下さい：");
    // scanf("%d", &key);
    // insert(key, root);

    // n[0] = new_node(key);
    // root = n[0];

    // n[0]->left = new_node(0);
    // n[0]->right = new_node(0);
    // n[0]->parent = NULL;

    // printf("挿入するキーを入力して下さい：");
    // scanf("%d", &key);
    // insert(key, root);

    //n[1] = new_node(key);
    // if (n[1]->key < n[0]->key) {
    //     n[0]->left = n[1];
    //     n[1]->parent = n[0];
    // } else if (n[1]->key > n[0]->key) {
    //     n[0]->right = n[1];
    //     n[1]->parent = n[0];
    // } else {
    //     printf("その値はすでに存在します。\n");
        // print_tree(root);
        // free_tree(root);
    //     return 0;
    // }

    // n[1]->left = new_node(0);
    // n[1]->right = new_node(0);    

    

    for (int i = 0; i < 3; i++) {
        printf("挿入するキーを入力して下さい：");
        scanf("%d", &key);

        if (key > 0) {
            if (insert(key, root) == 1) {
                print_tree(root);
            } else {
                printf("その値はすでに存在します。\n");
                print_tree(root);
            }
        } else {
            printf("正でない数値が入力されたので終了します。\n");
            free_tree(root);
            return 0;
        }
    }

    return 0;
}
