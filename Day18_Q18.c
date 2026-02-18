int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;  // Handle cases where k > n

    // Print rotated array
    for(int i = n - k; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for(int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
