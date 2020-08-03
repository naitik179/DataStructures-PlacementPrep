int Solution::hammingDistance(const vector<int> &A) {
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
        int cntBitOne = 0, cntBitZero = 0;
        for(int i = 0; i < inputSize; i++) {
            if (A[i] & (1 << bitPosition)) cntBitOne++;
            else cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod) sum = sum - mod;
    }
    return sum;
}

/*

Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.

 A = [2, 4, 6]

 output = 8
*/