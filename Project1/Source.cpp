#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <ctime>
using namespace std;
using namespace cv;
int morph_elem = 0;
int morph_size = 1;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 4;
const char* window_name_Open = "Opening";
const char* window_name_Close = "Close";

clock_t start, stop;

Mat img, img2, img3, dst , dst2;
void Morphology_Operations(int, void*);
void Morphology_Operations1(int, void*);


int main(int argc, char const* argv[])
{

     

       img = imread("C:/Users/user/Desktop/Computer Vision/CDNet2014_dynamic background_fall/in000002.jpg");
       cvtColor(img, img2, COLOR_RGB2GRAY);

       double thresh = 128;
       double maxValue = 255;

       threshold(img2, img3, thresh, maxValue, THRESH_BINARY);

      // imshow("視窗", img3);

       start = clock();
       for (int q = 0; q < 100; q++)
           Morphology_Operations(0, 0);
       for (int q = 0; q < 100; q++)
           Morphology_Operations1(0, 0);
       stop = clock();
       cout << "KernelSize:3"<< endl;
       cout <<"Time(ms):" << double(stop - start)*1000 / CLOCKS_PER_SEC << endl;


           waitKey(0);
           return 0;
}

    void Morphology_Operations(int, void*)
    {
        // Since MORPH_X : 2,3,4,5 and 6
        
        int operation = morph_operator + 2;
        Mat element = getStructuringElement(morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
        morphologyEx(img3, dst, operation, element);
       //imshow(window_name_Open, dst);


    }
    void Morphology_Operations1(int, void*)
    {
        // Since MORPH_X : 2,3,4,5 and 6

        int operation = morph_operator + 3;
        Mat element = getStructuringElement(morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
        morphologyEx(img3, dst2, operation, element);
       // imshow(window_name_Close, dst2);

    }

