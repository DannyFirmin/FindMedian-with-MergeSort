#include <iostream>
#include <fstream>

long long y[500000000];

void merge(long long A[], long long p, long long q, long long r) {
    long long n1 = q - p + 1;
    long long n2 = r - q;

    auto *L = new long long[n1];
    auto *R = new long long[n2];

    for (long long i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    for (long long j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    long long i = 0;
    long long j = 0;
    long long k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }
    delete[]L;
    delete[]R;
}

void mergeSort(long long A[], long long p, long long r) {
    if (p < r) {
        long long q = p + (r - p) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

long long findMedian(long long A[], long long yMax, long long n) {
    mergeSort(A, 0, n - 1);
    long long y_r = A[n / 2];
    return y_r;
}


int main(int argc, char *argv[]) {
    // Start reading data
    std::cout << "Loading txt data, please wait..." << std::endl;
    std::ifstream f(argv[1]);
    long long skip[1];
    long long yMax, xMax, n;
    f >> yMax >> xMax >> n;
    for (long long i = 0; i < n; i++) {
        f >> skip[0] >> y[i];
    }
    f.close();
    std::cout << "Data loading done, starts finding the best rail position" << std::endl;
    // finish reading data

    // My algorithms start
    long long y_r = findMedian(y, yMax, n); // put result in y_r
    // My algorithms end

    std::cout << "The best light rail position (yr) is: " << y_r << std::endl;
    return 0;
}



