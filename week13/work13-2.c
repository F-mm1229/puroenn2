// オプション課題 13-2

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

/* 整数値を探索するプログラム */
int member_recursive(int key, struct node *root) {
    struct node *p;
    p = root;

    if (p->key > key) {
        if (p->key == 0) {
            printf("キー%dが見つかりませんでした\n", key);
            return 0;
        }
        member_recursive(key, p->left);
    } else if (p->key < key) {
        if (p->key == 0) {
            printf("キー%dが見つかりませんでした\n", key);
            return 0;
        }
        member_recursive(key, p->right);
    } else if (p->key == key) {
        printf("キー%dが見つかりました\n", key);
        return 0;
    }

    return 0;
}

int main()
{
    struct node *root, *n[10];

    n[0] = new_node(4);
    n[1] = new_node(7);
    n[2] = new_node(9);
    n[3] = new_node(12);
    n[4] = new_node(15);
    n[5] = new_node(18);
    n[6] = new_node(21);
    n[7] = new_node(22);
    n[8] = new_node(25);
    n[9] = new_node(31);

    root = n[5];

    n[0]->left = new_node(0);
    n[0]->right = n[1];
    n[0]->parent = n[2];

    n[1]->left = new_node(0);
    n[1]->right = new_node(0);
    n[1]->parent = n[0];

    n[2]->left = n[0];
    n[2]->right = n[3];
    n[2]->parent = n[5];

    n[3]->left = new_node(0);
    n[3]->right = n[4];
    n[3]->parent = n[2];

    n[4]->left = new_node(0);
    n[4]->right = new_node(0);
    n[4]->parent = n[3];  

    n[5]->left = n[2];
    n[5]->right = n[7];
    n[5]->parent = NULL;

    n[6]->left = new_node(0);
    n[6]->right = new_node(0);
    n[6]->parent = n[7];

    n[7]->left = n[6];
    n[7]->right = n[9];
    n[7]->parent = n[5];

    n[8]->left = new_node(0);
    n[8]->right = new_node(0);
    n[8]->parent = n[9];

    n[9]->left = n[8];
    n[9]->right = new_node(0);
    n[9]->parent = n[7];

    int key;
    printf("探索するキーを入力してください：");
    scanf("%d", &key);
    member_recursive(key, root);

    free(root);

    return 0;
}