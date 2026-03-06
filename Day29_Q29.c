#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL) head = temp;
        else tail->next = temp;
        tail = temp;
    }
    return head;
}

// Function to rotate list right by k
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0) return head;

    // Connect last node to head to form circular list
    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    // Find new head: (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);

    struct Node* head = createList(arr, n);
    head = rotateRight(head, k % n, n); // handle k >= n
    printList(head);

    return 0;
}
