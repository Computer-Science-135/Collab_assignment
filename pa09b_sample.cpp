/// @file pa09b_sample.cpp
/// @author James Pristas
/// @date 4/20/23
/// @brief pa09b Partial sample solution
/// @note This program is a sample program that produces a Mandelbrot image and
/// and is to be used as a basis for the pa09b assignment.

#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <cctype>
#include <string>


using namespace std;

const int MAX_ITERATIONS = 160; // Maximum number of iterations
const int MAX_COLOR = 255;      // Maximum value for the image RGB triplet

/**
 * Scaling struct.
 * Holds the values for the current real and imaginary axis range.
 * The values are initialized based on 1) No scaling requested and default
 * values are loaded or 2) Scaling requested and values based on the specific
 * grid location are loaded.
*/
struct scale_t {

   double xmin;                         // negative real axis limit
   double xmax;                         // positive real axis limit
   double ymin;                         // negative imaginary axis limit
   double ymax;                         // positive real axis limit

};

/**
 * Color gradient palette struct.
 * This is used to declare an array that hold the 160 color triplets that are
 * used to assign colors to the individual pixels representing a point on the
 * complex plane that displays the Mendelbrot set.
*/
struct gradient_t {

    unsigned short red_grad = 0;        // red intensity    0-255
    unsigned short green_grad = 0;      // green intensity  0-255
    unsigned short blue_grad = 0;       // blue intensity   0 -255
};

/**
 * RGB triplet struct.
 * There is one triplet (RGB) for each pixel in the image.
 * Each color has a possible range of intensity from 0-255 and
 * the mix of the color triplets creates the pixels rendered color.
*/
struct pixel_t {

    unsigned short red = 0;             // red intensity    0-255
    unsigned short green = 0;           // green intensity  0-255
    unsigned short blue = 0;            // blue intensity   0-255
};

/**
 * Image file struct.
 * Contains the RGB pixel data array, color gradient palette, image maximum size,
 * the image height and width derived from the command line input for image
 * size, and a value for the number of colors selected by the user.
 * This image is a square so the image size entered by the user defines both
 * the height and width of the final image (a square image).
*/
struct image_t {

    static const unsigned short MAX_PIX_GRAD = 160;
    static const unsigned short MAX_DIMENSION  = 1024;
    unsigned short num_colors;
    unsigned short width;
    unsigned short height;
    gradient_t map[MAX_PIX_GRAD];
    pixel_t data[MAX_DIMENSION][MAX_DIMENSION];
};


/**
 * Opens the file with the color gradient palette and stores the RGB triplets
 * from the file into the struct array in image.map[][]. There are 160 RGB color
 * triplets in the file.
 *
 * @Param    image       Struct containing the image array and data
 * @Param    COLOR_FILE  File that holds the color palette for the image.
 * @Return   None
 */
void read_gradient_file(image_t& image, const string COLOR_FILE);

/**
 * This function receives a value for number of iterations and generates an
 * RGB color that represents color of that point in the image.
 * @Param    iterations   The number of iterations for the current point.
 * @Param    r, g, b      Color values set for the calling function.
 * @Param    image        The general purpose image struct.
 * @Return   None
 */
void get_color(unsigned short iterations, unsigned short& r, unsigned short& g,
              unsigned short& b, image_t& image);

/**
 * Determines if the complex number representing the current coordinate location
 * on the complex plain is in the Mandelbrot set. The function does this
 * indirectly by sending back the number of iterations to the calling program.
 * @Param    c     The complex number representing the real and imaginary number
 *                 that defines the coordinate location of the point being
 *                 calculated in the complex plain.
 * @Return   None
 */
unsigned short mandelbrot(const complex<double>& c);

/**
 * Calculates the value of the real and imaginary parts of the point to be
 * analyzed from the image size and the specified limits of the complex plain
 * real and imaginary axis. This function is responsible for sending c to the
 * Mandelbrot function and populating the image array based on a number of key
 * parameters. This function is where the Gride and Axis are added and it is
 * where the scaling functions is called to determine the gride coordinates of
 * the seleced grid location, when requested.
 * @Param   image        The main image struct
 * @Param   GRID_SELECT  Determines if the gride should be added to the image.
 * @Param   scale        Holds the complex plain real and imaginary limits.
 * @Return   None
 */
void generate_mandelbrot(image_t& image, const bool GRID_SELECT,
                         scale_t& scale);

/**
 * Saves the image in a file.
 * @Param   image        The main image struct
 * @Param   OUTPUT_FILE  The Mandelbrot image is written to this file
 * @Return   None
 */
void save_image(image_t& image, const string OUTPUT_FILE);

/**
 * Opens and reads in the file containing the coordinates for the real and
 * imaginary limits into a local struct. This is read in as minimum and maximum
 * values for x and y. The functions determines if scaling has been requested. If
 * scaling is not requested, the function stores the default values in the scale
 * struct. If scaling has been requested, the function prompts the user for the
 * grid location of interest. This is entered as a row and column.
 * @Param   scale        The struct that holds the selected coordinates.
 * @Param   SCALE_SEL    Tells the function to apply scaling or to use the
 *                       default.
 * @Return   None
 */
void get_xy(scale_t& scale, const bool SCALE_SEL);


/// The main program
int main(int argc, char** argv) {

       // Declare image at type image_t.
    image_t image;

      // Declare scale as type scale_t
    scale_t scale;

    bool x_fail = false;

    /// ******** Start Command line inputs ******** ///

       // Verify that at least 5 arguments are present
       // If less than 5, set the failure flag and end the program.
    if (argc != 7){

            // Missing argument error message
        cerr << "Error: Incorrect number of arguments" << endl;
        x_fail = true;
    }
    else {

            // User input for image size.
        const unsigned short IMAGE_SIZE\
                             = static_cast<unsigned short>(atoi(argv[1]));

            // Number of colors requested
        image.num_colors = static_cast<unsigned short>(atoi(argv[2]));

            // Grid on: 1 = True, o = False
        const bool GRID_SEL = static_cast<unsigned short>(atoi(argv[3]));

            // Scaling(zoom) selection 1 = True, 0 = False
        const bool SCALE_SEL = static_cast<unsigned short>(atoi(argv[4]));

            // Use color palette selection in this file
        const string STR2(argv[5]);
        const string COLOR_FILE = STR2;

            // Final image output file
        const string STR3(argv[6]);
        const string OUTPUT_FILE = STR3;

    /// ******** End command line inputs ********///

            // Save the working image size
        image.width = IMAGE_SIZE;
        image.height = IMAGE_SIZE;


            // Call to retrieve the scaling block coordinates
            // or the default value.
        get_xy(scale, SCALE_SEL);

            // get the color palette
        read_gradient_file(image, COLOR_FILE);

            // Create the Mandelbrot image
        generate_mandelbrot(image, GRID_SEL, scale);

            // Save the image to a file
        save_image(image, OUTPUT_FILE);
    }

    return(static_cast<int>(x_fail));
}

    /// Deterimin the real and imaginary axis range
void get_xy(scale_t& scale, const bool SCALE_SEL) {

       // Default real and imaginary axix range
    const double XMIN_FULL = -2.0;
    const double XMAX_FULL = 1.0;
    const double YMIN_FULL = -1.5;
    const double YMAX_FULL = 1.5;


        // If scaling is not selected, get the default
        // values for the real and imaginary axis range.

        // The scale select is disabled until the student adds the scale
        // select code. The default scaling will be initialized.
    if (!SCALE_SEL || SCALE_SEL) {

        scale.xmin = XMIN_FULL;
        scale.xmax = XMAX_FULL;
        scale.ymin = YMIN_FULL;
        scale.ymax = YMAX_FULL;
    }
}

    /// New Mandelbrot image function
void generate_mandelbrot(image_t& image, const bool GRID_SELECT,
                         scale_t& scale) {

        // Get the values for the real and imaginary axis limits
    double xmin = scale.xmin;
    double xmax = scale.xmax;
    double ymin = scale.ymin;
    double ymax = scale.ymax;

        // Local variables that hold the colors initialized by the get_color()
        // function.
    unsigned short red;
    unsigned short green;
    unsigned short blue;

        // The real (a) and imaginary (b) numbers that are derived from the
        // current selected image map pixel as it applies the a position on the
        // complex plain. This becomes the point of interest that is sent, as a
        // complex number the the mandelbrot() function.
    double a;
    double b;

        // Initialize the local constants for Width and Height of the image.
    const unsigned short WIDTH = image.width;
    const unsigned short  HEIGHT = image.height;

        // Declare  variable that will be assigned the value for the number
        // of iterations calculated for the current point on the complex
        // plain. This is returned by the mandelbrot() program.
    unsigned short iterations;

       // The main image loop.
       // This loop process every pixel in the image by transforming the pixel
       // location, in the image map, to a point on the complex plan. This means
       // that every pixel will have a corresponding complex number that defines
       // a location on the complex plain. This complex number is then sent to
       // the mendalbrot() program to determine if the complex number is in the
       // Mandelbrot set. This is determined by the value of the number of
       // iterations returned by the mandelbrot() program. The number of
       // iterations returned is passed to the get_color() function to assign
       // a color to the point based on whether it is in the Mandelbrot set or
       // not. Once the color of the point is determined, it is loaded into the
       // image pixel array and then the loop repeats for the next pixel until
       // all of the image map has been filled.
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            a = xmin + (static_cast<double>(x)/WIDTH) * (xmax-xmin);
            b = ymin + (static_cast<double>(y)/HEIGHT) * (ymax-ymin);

                // Initialize the complex number for the current point
            complex<double>c(a, b);

                // Call the mandelbrot() function and pass the complex number.
                // A value for the number of iterations for that point is
                // returned.
            iterations = mandelbrot(c);

                // Call the get_color() function and send it the number of
                // iterations for the current point. The functions initializes
                // the three reference parameters for the RGB color for the
                // current point.
            get_color(iterations, red, green, blue, image);

                // Load the color for the current pixel.
            image.data[y][x].red = red;
            image.data[y][x].green = green;
            image.data[y][x].blue = blue;

               // If a grid is selected, This logic should add a 10 X 10 Grid
               // and real and imaginary axis to the image.
            if (GRID_SELECT){

                // Student Grid and Axis code goes here.
            }
        }
    }
}

  /// Define a function to calculate the Mandelbrot set
unsigned short mandelbrot(const complex<double>& c)
{
        // The complex number z, is initialized to the origin of the complex
        // plain/
    complex<double> z = {0, 0};

        // This is the counter for the number of iterations, n
    unsigned short n = 0;

        // Iterates through the Mandelbrot function until one of two things
        // happens.
        //
        // 1) The maximum number of iterations is hit before the value of z
        //    became larger than 2  and the evaluation stops.
        //    This means the point did NOT diverge, and is in the Mandelbrot
        //    set.
        //
        // 2) The value of z became larger than 2, before reaching the maximum
        //    number of iterations and the evaluation is stopped.
        //    The value of z diverged from the origin, and is not in the
        //    Mandelbrot set.

    while (abs(z) <= 2 && n < MAX_ITERATIONS) {
        z = z * z + c;
        n++;
    }
    if (n == MAX_ITERATIONS) {

        n = 0;
    }
    return n;
}

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


       // sort out any iterations that are outside the range for the purpose ofdeleteee
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
   /// Saves the final image pixel map to the file specified in the command line
   /// argument.
void save_image (image_t& image, const string OUTPUT_FILE) {

  ofstream outFile;

    outFile.open(OUTPUT_FILE);
    outFile << "P3" << endl;
    outFile << image.width << " " << image.height << endl;
    outFile << MAX_COLOR << endl;
    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            outFile << image.data[j][i].red << " " << image.data[j][i].green
                    << " " << image.data[j][i].blue << " ";
        }
        outFile << endl;
    }
    outFile.close();
}



