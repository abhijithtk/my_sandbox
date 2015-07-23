
void rotateLeftByReverse(int *arr, int n, int d) {
    if (d > n)
        d = d-n;
    reverseArrayRecursive(arr, 0, d-1);
    reverseArrayRecursive(arr, d, n-1);
    reverseArrayRecursive(arr, 0, n-1);
}

void rotateRightByReverse(int *arr, int n, int d) {
    if (d > n)
        d = d-n;
    reverseArrayRecursive(arr, n-d, n-1);
    reverseArrayRecursive(arr, 0, n-d-1);
    reverseArrayRecursive(arr, 0, n-1);
}

void reverseArrayRecursive(int *arr, int beg, int end) {
    if (beg > end)
        return;
    swapElement(arr, beg, end);
    reverseArrayRecursive(arr, ++beg, --end);
}
