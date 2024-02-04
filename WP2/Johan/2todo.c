#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #### Constants #####
#define MAX 5
// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;
// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================
REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top, *old, *item;

    for (int i = 0; i < MAX; i++)
    {
        nr = rand % 100;
        item->number = number;
        item->next = top;
        item->prev = NULL;
    }

    if (top != NULL)
    {
        item->prev = top
    }
    else
    {
        old = top;
    }

    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
}
