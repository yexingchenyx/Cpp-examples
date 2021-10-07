BASE FUNCTION(my_stats, max)(BASE* a, int n) {
    BASE max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}