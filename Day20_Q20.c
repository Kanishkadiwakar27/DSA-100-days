#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long sum = 0;
    int count = 0;

    // Using simple array as hashmap (assuming sum range is manageable)
    // For competitive programming, normally use unordered_map in C++
    
    long long prefix[MAX] = {0};
    int size = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            count++;

        for(int j = 0; j < size; j++) {
            if(prefix[j] == sum)
                count++;
        }

        prefix[size++] = sum;
    }

    printf("%d", count);

    return 0;
}