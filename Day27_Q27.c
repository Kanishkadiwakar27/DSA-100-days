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

// Function to get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Advance longer list
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse together
    while (head1 && head2) {
        if (head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1; // No intersection
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    struct Node* head1 = createList(arr1, n);
    struct Node* head2 = createList(arr2, m);

    int result = findIntersection(head1, head2);
    if (result == -1) printf("No Intersection");
    else printf("%d", result);

    return 0;
}
