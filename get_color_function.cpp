 /// Determine the color of a point on the complex plain based on the number
   /// of iterations on n.
void get_color(unsigned short iterations, unsigned short& red,
              unsigned short& green, unsigned short& blue, image_t& image) {


    const int RANGE_HIGH = 160;   // High range of iterations
    const int RANGE_LOW =  1;     // Low range of iterations
    const int STEP = 1;           // Step for each of the 160 RGB color triplets

    int step_low;                 // Low range for iteration color selection
    int step_high;                // High range for iteration color selection

    bool set = false;             // Flag set true if the iteration was in range


       // sort out any iterations that are outside the range for the purpose of
       // selecting a color. Ideally, it is optimal to have a distinct (one from
       // the next) color for each possible iteration value.
    if (iterations >= RANGE_LOW and iterations <= RANGE_HIGH){

          // initialize the range conditional limits. These variables will be
          // incremented for each color value defined in the image struct.
       step_low = RANGE_LOW;
       step_high = RANGE_LOW + STEP;

           // Loop through the complete color gradient palette.
       for (int i = 0; (i < image.num_colors && set == false); i++) {

              // determine if the current Mandelbrot iteration value is in
              // the current range. If so, assign the color for that index in
              // the array strunct.
            if (iterations >= step_low && iterations <= step_high) {

                   // Assigning  the RGB colors for this Mandelbrot point.
                red = image.map[i].red_grad;
                green = image.map[i].green_grad;
                blue = image.map[i].blue_grad;

                   // Indicates that a color was found for the iteration value.
                set = true;
            }

                // Increment the high and low range of Iteration count.
            step_low = step_low + STEP;
            step_high = step_high + STEP;
        }
    }

        // If the Iteration number is outside the high and low range. Set the
        // color of that point to black. If the number of iterations is zero,
        // that point is inside the Mandelbrot set.
    else {

        red   = 0;    //image.map[1].red_grad;
        green = 0;    //image.map[1].green_grad;
        blue  = 0;    //image.map[1].blue_grad;
    }
}

    /// Read in the 160 color triples from the file specified in the command
    /// line argument.
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
