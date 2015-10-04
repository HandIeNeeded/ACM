int a[N], b[N]; //b[N] -> tmp a[N] -> data
//Inv1 < Inv2 >

LL Merge_Sort(int l,int r) {
    if(l >= r) return 0; 
    int mid = l + r >> 1;
    LL Inv1 = 0, Inv2 = 0;
    if(l <= mid) Inv2 += Merge_Sort(l, mid);
    if(r > mid) Inv2 += Merge_Sort(mid + 1, r);

    for (int i = l, j = mid + 1, k = l; k <= r; k++) {
        if (j > r || i <= mid && a[i] < a[j]) {
            b[k] = a[i++];
            Inv1 += r - j + 1;
        }
        else if (j > r || i <= mid && a[i] == a[j]) {
            b[k] = a[i++];
        }
        else {
            b[k] = a[j++];
            Inv2 += mid - i + 1;
        }
    }

    REPP(i, l, r) a[i] = b[i];
    return Inv2;
}
