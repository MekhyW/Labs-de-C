int process_pixel(int level, int add) {
    int new_level = level + add;
    if (new_level > 255) {
        return 255;
    }
    return new_level;
}
