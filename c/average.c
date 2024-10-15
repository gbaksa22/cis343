float average (float* num, size_t size) {
    int count = 0;
    float sum = 0;
    for(size_t i=0; i<size; ++i) {
        sum += num[i];
        count += 1
    }
return sum / count;
}