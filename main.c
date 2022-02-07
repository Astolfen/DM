#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE_C 1001
#define MAX_ARRAY_SIZE_AB 501

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void input_unordered_array(int *a) {
    scanf("%d", &a[0]);
    for (int i = 1; i <= a[0]; i++)
        scanf("%d", &a[i]);
}

void output_unordered_array(int *a) {
    for (int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    printf("\n");
}

//v1
void union_unordered_set(const int *a, const int *b, int *c) {
    c[0] = a[0];
    for (int i = 1; i <= a[0]; i++)
        c[i] = a[i];
    for (int i = 1; i <= b[0]; i++) {
        int isTrue = 1;
        int j = 1;
        while (j <= a[0] && isTrue) {
            if (a[j] == b[i])
                isTrue = 0;
            j++;
        }
        if (isTrue == 1) {
            c[0]++;
            c[c[0]] = b[i];
        }
    }

}

//v2
void intersection_unordered_set(const int *a, const int *b, int *c) {
    c[0] = 0;
    for (int i = 1; i <= b[0]; i++) {
        int isTrue = 1;
        int j = 1;
        while (j <= a[0] && isTrue) {
            if (a[j] == b[i])
                isTrue = 0;
            j++;
        }
        if (isTrue == 0) {
            c[0]++;
            c[c[0]] = b[i];
        }
    }
}

//v3
void difference_unordered_set(const int *a, const int *b, int *c) {
    c[0] = 0;
    for (int i = 1; i <= a[0]; i++) {
        int isTrue = 1;
        int j = 1;
        while (j <= b[0] && isTrue) {
            if (b[j] == a[i])
                isTrue = 0;
            j++;
        }
        if (isTrue == 1) {
            c[0]++;
            c[c[0]] = a[i];
        }
    }
}

//v4
void symmetricDifference_unordered_set(const int *a, const int *b, int *c) {
    difference_unordered_set(a, b, c);
    for (int i = 1; i <= b[0]; i++) {
        int isTrue = 1;
        int j = 1;
        while (j <= a[0] && isTrue) {
            if (a[j] == b[i])
                isTrue = 0;
            j++;
        }
        if (isTrue == 1) {
            c[0]++;
            c[c[0]] = b[i];
        }
    }
}

//v6
bool isEqualSet_unordered_set(const int *a, const int *b) {
    if (a[0] != b[0])
        return 0;
    else {
        int count = 0;
        for (int i = 1; i <= a[0]; i++) {
            int isTrue = 1;
            int j = 1;
            while (j <= b[0] && isTrue) {
                if (b[j] == a[i])
                    isTrue = 0;
                j++;
            }
            if (isTrue == 0)
                count++;
        }
        return count == a[0];
    }
}

//v5
//проверяет что A является под множеством B
bool isSubSet_unordered_set(const int *a, const int *b) {
    int count = 0;
    for (int i = 1; i <= a[0]; i++) {
        int isTrue = 1;
        int j = 1;
        while (j <= b[0] && isTrue) {
            if (b[j] == a[i])
                isTrue = 0;
            j++;
        }
        if (isTrue == 0)
            count++;
    }
    return count == a[0];
}

//v7
bool isNotIdenticalEl_InSet_unordered_set(const int *a, const int *b) {
    int count = 0;
    if (a[0] > b[0]) {
        for (int i = 1; i <= a[0]; i++) {
            int isTrue = 1;
            int j = 1;
            while (j <= b[0] && isTrue) {
                if (b[j] == a[i])
                    isTrue = 0;
                j++;
            }
            if (isTrue == 1)
                count++;
        }
        return count == a[0];
    } else {
        for (int i = 1; i <= b[0]; i++) {
            int isTrue = 1;
            int j = 1;
            while (j <= a[0] && isTrue) {
                if (a[j] == b[i])
                    isTrue = 0;
                j++;
            }
            if (isTrue == 1)
                count++;
        }
        return count == b[0];
    }
}

//v8
void union_ordered_array(const int *a, const int *b, int *c) {
    int i = 1;
    int j = 1;
    int count = 0;
    while (i <= a[0] || j <= b[0]) {
        if (j > b[0] || a[i] < b[j] && i <= a[0]) {
            count++;
            c[count] = a[i];
            i++;
        } else {
            count++;
            c[count] = b[j];
            j++;
        }
    }
    c[0] = count;
}

//v9
void intersection_ordered_array(const int *a, const int *b, int *c) {
    int i = 1;
    int j = 1;
    int count = 0;
    while (i <= a[0] && j <= b[0]) {
        if (a[i] == b[j]) {
            count++;
            c[count] = a[i];
            i++;
            j++;
        } else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    c[0] = count;
}

//10
void difference_ordered_array(const int *a, const int *b, int *c) {
    int i = 1;
    int j = 1;
    int count = 0;
    while (i <= a[0]) {
        if (j > b[0] || a[i] < b[j]) {
            count++;
            c[count] = a[i];
            i++;
        } else if (a[i] == b[j]) {
            i++;
            j++;
        } else
            j++;
    }
    c[0] = count;
}

//v11
void symmetricDifference_ordered_array(const int *a, const int *b, int *c) {
    difference_ordered_array(a, b, c);
    int i = 1;
    int j = 1;
    int count = c[0];
    while (i <= b[0]) {
        if (j > a[0] || b[i] < a[j]) {
            count++;
            c[count] = b[i];
            i++;
        } else if (a[i] == b[j]) {
            i++;
            j++;
        } else
            j++;
    }
    c[0] = count;
    qsort(c + 1, c[0], sizeof(int), compare_ints);
}

//v12
bool isSubSet_ordered_array(const int *a, const int *b) {
    int i = 1;
    int j = 1;
    int count = 0;
    if (a[0] > b[0])
        return 0;
    while (i <= a[0]) {
        if (a[i] == b[j]) {
            i++;
            j++;
            count++;
        } else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    return count == a[0];
}

int main() {
    int a[MAX_ARRAY_SIZE_AB];
    int b[MAX_ARRAY_SIZE_AB];
    int c[MAX_ARRAY_SIZE_C];

    input_unordered_array(a);
    input_unordered_array(b);

    //symmetricDifference_ordered_array(a, b, c);

    //output_unordered_array(c);

    printf("%d", isSubSet_ordered_array(a, b));

    return 0;
}
