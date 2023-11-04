#include <stdlib.h>
#include <stdio.h>

struct node {
        const char *person;
        const char *footwear;
        struct node *left, *right;
};
typedef struct node *Tree;

static struct node rt = {
        "Townsend",
        "Saucony",
        NULL,
        NULL
};

static struct node ms = {
        "Sheldon",
        "Freeds",
        NULL,
        &rt
};
static struct node y = {
        "Temp",
        "Fake",
        NULL,
        NULL
};

static struct node x = {
        "Temp",
        "Fake",
        &y,
        NULL
};

static struct node lx = {
        "Ramsey",
        "Birkenstocks",
        &ms,
        &x
};

static int counter = 0;
void static exploreTree(Tree curr) {
        if (curr == NULL) {
                return;
        }

        exploreTree(curr -> left);
        counter++;
        exploreTree(curr -> right);

}

int main() {
        counter = 0;
        exploreTree(&lx);
        printf("%i\n", counter);
}