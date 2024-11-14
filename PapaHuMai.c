#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    int coeff;
    int exp;
    struct polynomial *next;
};

struct polynomial *create_Polynomial(int n, struct polynomial *head)
{
    while (n--)
    {
        int coeff, exp;
        printf("coeff->");
        scanf("%d", &coeff);
        printf("exp->");
        scanf("%d", &exp);

        struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
        new_node->coeff = coeff;
        new_node->exp = exp;
        new_node->next = NULL;

        if (head == NULL || head->exp < exp)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            struct polynomial *temp = head;

            while (temp->next != NULL && temp->next->exp > exp)
            {
                temp = temp->next;
            }
            if (head->exp == exp)
            {
                head->coeff += coeff;
                free(new_node);
            }
            else if (temp->next != NULL && temp->next->exp == exp)
            {

                temp->next->coeff += coeff;
                free(new_node);
            }
            else
            {

                new_node->next = temp->next;
                temp->next = new_node;
            }
        }
    }
    return head;
}


void display(struct polynomial *head)
{
    while (head != NULL)
    {
        printf("%dx^%d +", head->coeff, head->exp);
        head = head->next;
    }
}

struct polynomial *add_polynomial(struct polynomial *head1, struct polynomial *head2)
{
    struct polynomial *head_add = NULL, *current = NULL;
    struct polynomial *temp1 = head1, *temp2 = head2;

    // Traverse both lists and merge them into a new list
    while (temp1 != NULL && temp2 != NULL)
    {
        struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
        if (temp1->exp == temp2->exp)
        {
            new_node->exp = temp1->exp;
            new_node->coeff = temp1->coeff + temp2->coeff;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            new_node->exp = temp1->exp;
            new_node->coeff = temp1->coeff;
            temp1 = temp1->next;
        }
        else
        {
            new_node->exp = temp2->exp;
            new_node->coeff = temp2->coeff;
            temp2 = temp2->next;
        }

        new_node->next = NULL;

        if (head_add == NULL)
        {
            head_add = new_node;
            current = head_add;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }

    // If there are remaining nodes in list 1
    while (temp1 != NULL)
    {
        // add_elements_poly(&head_add, temp1->exp, temp1->coeff);
        struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
        new_node->coeff = temp1->coeff;
        new_node->exp = temp1->exp;
        new_node->next = NULL;
        if (head_add == NULL)
        {
            head_add = new_node;
            current = head_add;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        temp1 = temp1->next;
    }

    // If there are remaining nodes in list 2
    while (temp2 != NULL)
    {
        struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
        new_node->coeff = temp2->coeff;
        new_node->exp = temp2->exp;
        new_node->next = NULL;
        if (head_add == NULL)
        {
            head_add = new_node;
            current = head_add;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        temp2 = temp2->next;
    }

    return head_add;
}

struct polynomial *add_same_polynomial(struct polynomial *head1, int n)
{
    while (n--)
    {
        int coeff, exp;
        printf("coeff->");
        scanf("%d", &coeff);
        printf("exp->");
        scanf("%d", &exp);

        struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
        new_node->coeff = coeff;
        new_node->exp = exp;
        new_node->next = NULL;

        if (head1 == NULL || head1->exp < exp)
        {
            new_node->next = head1;
            head1 = new_node;
        }
        else
        {
            struct polynomial *temp = head1;
            while (temp->next != NULL && temp->next->exp > exp)
            {
                temp = temp->next;
            }
            if (head1->exp == exp)
            {
                head1->coeff += coeff;
                free(new_node);
            }
            else if (temp->next != NULL && temp->next->exp == exp)
            {
                temp->next->coeff += coeff;
                free(new_node);
            }
            else
            {
                new_node->next = temp->next;
                temp->next = new_node;
            }
        }
    }
    return head1;
}

struct polynomial *mult_polynomial(struct polynomial *head1, struct polynomial *head2) {
    struct polynomial *head_mult = NULL;

    // Iterate over each term of the first polynomial
    for (struct polynomial *temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
        // Iterate over each term of the second polynomial
        for (struct polynomial *temp2 = head2; temp2 != NULL; temp2 = temp2->next) {
            // Create a new node for the product of terms
            struct polynomial *new_node = (struct polynomial *)malloc(sizeof(struct polynomial));
            new_node->coeff = temp1->coeff * temp2->coeff;
            new_node->exp = temp1->exp + temp2->exp;
            new_node->next = NULL;

            // Insert or update in the result polynomial
            if (head_mult == NULL || head_mult->exp < new_node->exp) {
                // Insert at the head
                new_node->next = head_mult;
                head_mult = new_node;
            } else {
                struct polynomial *temp = head_mult;
                // Find the correct position or the existing term with the same exponent
                while (temp->next != NULL && temp->next->exp > new_node->exp) {
                    temp = temp->next;
                }

                if (temp->exp == new_node->exp) {
                    // Update existing term
                    temp->coeff += new_node->coeff;
                    free(new_node);
                } else if (temp->next != NULL && temp->next->exp == new_node->exp) {
                    // Update existing term
                    temp->next->coeff += new_node->coeff;
                    free(new_node);
                } else {
                    // Insert new node
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
            }
        }
    }

    return head_mult;
}


int main()
{
    struct polynomial *head = NULL, *head2 = NULL, *new_add = NULL, *new_mult=NULL;

    head = create_Polynomial(5, head);
    display(head);
    printf("\n");
    head2 = create_Polynomial(6, head2);
    display(head2);
    printf("\nAdd: ");
    printf("\n");
    new_add = add_polynomial(head, head2);
    display(new_add);
    // new_add = add_same_polynomial(head, 6);
    // display(new_add);

    printf("\nMult: ");
    new_mult =mult_polynomial(head, head2);
    display(new_mult);
}