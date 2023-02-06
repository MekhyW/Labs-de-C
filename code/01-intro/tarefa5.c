int process_pixel(int level, int multiply) {
    int new_level = level * multiply;
    if (new_level > 255) {
        return 255;
    }
    return new_level;
}
