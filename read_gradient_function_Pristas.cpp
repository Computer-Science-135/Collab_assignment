/// Mandelbrot color gradient file import function
/// How can this be improved?
/// Take a look at the for loop
/// A suggested change has been added
void read_gradient_file(image_t& image, const string COLOR_FILE){

        // Get the number of triplets in the file. This is the first value
    int color_count;

    ifstream fin;

        // File specified by the user as a command line argument
    fin.open(COLOR_FILE);

    fin >> color_count;

     // Improved loop
    for (int i = color_count; i < color_count; i++){

        fin >> image.map[i].red_grad;
        fin >> image.map[i].green_grad;
        fin >> image.map[i].blue_grad;
    }




/*
        // Load the contents of the color gradient palette file.
    for (int i = color_count-1; i >= 0; i--){

        fin >> image.map[i].red_grad;
        fin >> image.map[i].green_grad;
        fin >> image.map[i].blue_grad;
    }
*/
}
