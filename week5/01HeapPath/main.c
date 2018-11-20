#include <stdio.h>
#include <stdlib.h>

#define MINH -10001;

int H[1001];
int size;

void Create() {
    size = 0;
    H[0] = MINH;

}

void Insert(int X) {

    int i;
    for ( i = ++size; H[i/2] > X; i /= 2) {
        H[i] = H[i/2];
    }
    H[i] = X;
}

int main() {
    int N, M, x;
    scanf("%d %d", &N, &M);
    Create();
    for (int i = 0; i < N; i ++) {
        scanf("%d", &x);
        Insert(x);
    }

    int j;
    for (int i = 0; i < M; i ++) {
        scanf("%d", &j);
        printf("%d", H[j]);
        while (j > 1) {
            j /= 2;
            printf(" %d", H[j]);
        }
        printf("\n");
    }
    return 0;
}

