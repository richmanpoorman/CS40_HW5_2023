#include <stdio.h>
#include <stdlib.h>

/*Phase 1*/

/* Compares our input value to the input value at address
   0x401d50. Extracted by using print (char *) 0x401d50
*/

const char *phase1 = "I was born with someone waiting to see me.";

void phase_1(char *input)
{
        char *str = phase1;
        if (strings_not_equal(input, str) != 0){
            explode_bomb();
        }
}


/*Phase 2*/

/* the solution to pass this algorithm is to
   calculates factorial value for the first 6 
   numbers e.g. 1!, 2!, 3!, 4!, 5!, 6! 
*/

void phase_2(int numbers[6])
{
        if (numbers[0] != 1){
            explode_bomb();
        }

        int i = 2;
        int factorial = 1;
        /*Factorial solution: 1, 2, 6, 24, 120, 720*/
        while (i < 7)
        {
            if (factorial != numbers[i - 2])
            {
                explode_bomb();
            }
            factorial *= i;
            i++;
        }
}

/*Phase 6*/

/* takes value of node0 and passes it to
   fun6 which sorts the linkedlist in 
   largest to smallest order. Our node0
   needs to be at the 3rd spot.
*/

typedef struct Node {
    struct Node* next;
    int value;
} Node;


void phase_6(int input) {
    int value = strtol(input, NULL, 10);
    node0 = (Node*)malloc(sizeof(Node));
    node0->value = input;
    node0->next = NULL;
    int result = fun6(node0)->next->next;

    if (result != value) {
        explode_bomb();
    }
}

Node* fun6(Node* rdi) {
    Node* r8 = rdi->next;
    rdi->next = NULL;

    if (r8 == NULL) {
        return rdi; 
    }

    if (value > rdi->value) {
        rdi->next = r8;
        return rdi; 
    }

    Node* rdx = rdi;
    Node* rcx = r8;

    while (rcx != NULL) {
        if (value <= rcx->value) {
            rdx->next = r8;
            r8->next = rcx;
            return rdi; 
        }

        rdx = rdx->next;
        rcx = rcx->next;
    }

    rdx->next = r8; 
    return rdi;
}



