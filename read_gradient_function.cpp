/// Mandelbrot color gradient file import function
void read_gradient_file(image_t& image, const string COLOR_FILE){

        // Get the number of triplets in the file. This is the first value
    int color_count;

    ifstream fin;

        // File specified by the user as a command line argument
    fin.open(COLOR_FILE);

    fin >> color_count;

        // Load the contents of the color gradient palette file.
    for (int i = color_count-1; i >= 0; i--){

        fin >> image.map[i].red_grad;
        fin >> image.map[i].green_grad;
        fin >> image.map[i].blue_grad;
    }
}
