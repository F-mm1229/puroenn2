// 必須課題13-1

#include <stdio.h>
#include <stdlib.h>
#include </Users/yanofuki/puroenn2/week12/print_tree.c>

/* 全てのnodeのメモリを開放する関数 */
void free_tree(struct node *node) {
    if(node != NULL){
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

struct node *new_node(int key) {
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));

    p->key = key;
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;

    return p;
}

/* 要素を挿入する関数 */
int insert(int key, struct node *root){
    struct node *p;
    p = root;

    if (p->key == 0) {
        p->key = key;
        p->left = new_node(0);
        p->right = new_node(0);
    } else if (key == p->key) {
        printf("その値はすでに存在します。\n");
        return 0;
    } else if (key < p->key) {
        insert(key, p->left);
    } else if (key > p->key) {
        insert(key, p->right);
    } else {
        return 0;
    }

    return 1;
}

int main(void){
    int key;
    struct node *root = new_node(0);

    for(int i = 0; i < 10; i++){
        printf("挿入するキーを入力して下さい：");
        scanf("%d", &key);

        if (key > 0) {
            if (insert(key, root) == 1){
                print_tree(root);
            } else {
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
