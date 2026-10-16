#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data)
{
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Find the smallest node in a subtree
struct Node* findMin(struct Node* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
        return NULL;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node has no left child
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Node has no right child
        if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Calculate height of the tree
int height(struct Node* root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight
                    ? leftHeight : rightHeight);
}

// Count total nodes
int countNodes(struct Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Display tree using inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main()
{
    struct Node* root = NULL;
    int choice, data;

    do
        {
        printf("\n\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Height of Tree\n");
        printf("4. Total Number of Nodes\n");
        printf("5. Display Tree (Inorder)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);

                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    root = deleteNode(root, data);
                    printf("Deletion operation completed.\n");
                }
                break;

            case 3:
                printf("Height of tree: %d\n", height(root));
                break;

            case 4:
                printf("Total number of nodes: %d\n",
                       countNodes(root));
                break;

            case 5:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
