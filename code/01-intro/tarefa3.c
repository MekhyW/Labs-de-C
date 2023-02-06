int process_pixel(int level, int threshold) {
    if (level < threshold) {
        return 0;
    }
    return 255;
}
