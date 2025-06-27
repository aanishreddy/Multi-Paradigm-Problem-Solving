#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float mean(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

float median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void mode(int arr[], int n) {
    int maxCount = 0;
    int modeCount = 0;
    int count, i, j;

    printf("Mode(s): ");
    for (i = 0; i < n; ++i) {
        count = 1;
        for (j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) count++;
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    for (i = 0; i < n; ++i) {
        count = 1;
        for (j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) count++;
        }

        if (count == maxCount) {
            int alreadyPrinted = 0;
            for (j = 0; j < i; ++j) {
                if (arr[j] == arr[i]) {
                    alreadyPrinted = 1;
                    break;
                }
            }
            if (!alreadyPrinted)
                printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int data[] = {1, 3, 3, 6, 7, 8, 9};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));
    mode(data, n);

    return 0;
}
