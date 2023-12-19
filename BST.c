#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

void create()
{
    node *temp;
    node *new = (node *)malloc(sizeof(node));
    new->right = NULL;
    new->left = NULL;

    if (new == NULL)
    {
        printf("Memory allocation fail");
    }
    else
    {
        printf("Enter data:");
        scanf("%d", &new->data);

        if (root == NULL)
        {
            root = new;
        }
        else
        {
            temp = root;
            while (1)
            {
                if (temp->data >= new->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void search(node *root)
{
    int num, f = 0;

    printf("Enter the number you want to search:");
    scanf("%d", &num);

    if (root == NULL)
    {
        printf("\nTree is bald\n");
    }
    while (root != NULL)
    {
        if (root->data == num)
        {
            f = 1;
            break;
        }
        else
        {
            if (num < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }

    if (f == 1)
    {
        printf("\nFound!\n");
    }
    else
    {
        printf("\nNot Found!\n");
    }
}

int height(node *p)
{
    int x, y;
  
    if (p == NULL)
        return 0;

    x = height(p->left);

    y = height(p->right);

    return x > y ? x + 1 : y + 1;
}

node *InSucc(node *p)
{
    while (p && p->left != NULL)

        p = p->left;

    return p;
}

node *InPre(node *p)
{
    while (p && p->right != NULL)

        p = p->right;

    return p;
}

node *delete(node *p, int k)
{
    struct node *q;

    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL && p->data == k)
    {
        if (p == root)

            root = NULL;

        free(p);

        return NULL;
    }
    if (k < p->data)
    {
        p->left = delete (p->left, k);
    }
    else if (k > p->data)
    {
        p->right = delete (p->right, k);
    }
    else
    {
        if (height(p->left) > height(p->right))

        {

            q = InPre(p->left);

            p->data = q->data;

            p->left = delete (p->left, q->data);
        }
        else
        {

            q = InSucc(p->right);

            p->data = q->data;

            p->right = delete (p->right, q->data);
        }
    }
    return p;
}

int main()
{
    int n, choice, i;
    char a;

    do
    {
        printf("Enter your choice :: \n1.Create\n2.Postorder\n3 Preorder\n4.Inorder.\n5.Search\n6.Delete\n7.exit\n ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the nodes yuou want to create:");
            scanf("%d", &n);

            for (int i = 1; i <= n; i++)
            {
                create();
            }
            break;

        case 2:
            postorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            search(root);
            break;
        case 6:
  
            printf("enter the number you want to delete :");
            scanf("%d", &i);
            delete (root, i);
            break;
        case 7:
            exit(0);
        default:
            printf("!!!ENTER A VALID NUMBER!!!");
        }

    } while (choice != 7);

    return 0;
}