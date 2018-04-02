#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <set>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <overseer/Manager.hpp>
#include <overseer/Hashtable.hpp>
#include <overseer/File.hpp>

const unsigned int DIM = 550;

namespace fs = std::experimental::filesystem;
using namespace overseer; //temporary

uint64 identify(std::string filename);
int main()
{
    Hashtable dataset;
    const std::string path("C:/users/gavin/pictures");
    for (auto& d : fs::recursive_directory_iterator(path))
    {
        const auto& file_ext = d.path().filename().extension().string();
        if (file_ext == ".png" || file_ext == ".jpg" || file_ext == ".jpeg")
        {
            const auto& file_path = d.path().string();
            const auto& file_name = d.path().filename().string();
            File f(file_name, file_path);
            f.id_ = identify(file_path);
            dataset.insert(f);
        }
    }
    const auto& dups = dataset.getDups();
   
    for (auto& dup : dups)
    {
        for (auto& file : dup.second)
        {
            const auto& file_path = file.second.file_path_;
            const auto& file_name = file.second.file_name_;
            std::cout << file_path << std::endl;
            cv::Mat image = cv::imread(file_path, CV_LOAD_IMAGE_UNCHANGED); // Read the file
            if (!image.empty())
            {
                if (file_name == "testcopy.jpg")
                    std::cout << 'a';
                resize(image, image, cv::Size(DIM, DIM), 0, 0, CV_INTER_AREA);
                cv::namedWindow(file_name, cv::WINDOW_AUTOSIZE);// Create a window for display.
                cv::imshow(file_name, image);                   // Show our image inside it.
                cv::waitKey(0);
                cv::destroyWindow(file_name);
            }
        }
    }
    return 0;
}


uint64 identify(std::string filename)
{
    cv::Mat image;
    image = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE); // Read the file
    if (image.empty())
        return 7000;
    resize(image, image, cv::Size(8, 8), 0, 0, CV_INTER_AREA);
    int nRows = 8;
    int nCols = 8;
    uchar* p;

    //compute mean value of shrunken image
    int mean = 0;
    for (int i = 0; i < nRows; ++i)
    {
        p = image.ptr<uchar>(i);
        for (int j = 0; j < nCols; ++j)
        {
            mean += p[j];
        }
    }
    mean /= 64;
    //set bits
    uint64 id = 0;
    for (int i = 0; i < nRows; ++i)
    {
        p = image.ptr<uchar>(i);
        for (int j = 0; j < nCols; ++j)
        {
            if (p[j] < mean)
                id |= 1;
            id <<= 1;
        }
    }
    return id;
}