#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Image.h" // Ensure this matches your actual header file name

void testImageClassWithRealImage(const std::string& imagePath) {
    cv::Mat imgMat = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (imgMat.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return;
    }
    
    uint32_t width = imgMat.cols, height = imgMat.rows;
    std::cout << "Image width "<< width << " Height "<<height << std::endl ; 
    Image img(width, height);
    img.setSensorName("SomeRandomSensor") ; 
    img.setTimestamp(1231251287) ; 
    // Copy image data into Image class
    for (uint32_t i = 0; i < height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            img.set(i, j, imgMat.at<uint8_t>(i, j));
        }
    }
    
    // Test serialization
    std::vector<uint8_t> serializedData = img.serialize();
    std::cout << "Serialized data size: " << serializedData.size() << std::endl;

    // Test deserialization
    Image newImg(width, height);
    bool deserializationSuccess = newImg.deserialize(serializedData);
    if (deserializationSuccess) {
        std::cout << "Deserialization successful with Header " << newImg.getWidth() << "  " << newImg.getHeight() <<"  "<< newImg.getSensorName() <<"  "<< newImg.getTimestamp() <<std::endl;
    } else {
        std::cout << "Deserialization failed." << std::endl;
    }
    
    // Validate that deserialized data matches original
    cv::Mat newImgMat(height, width, CV_8UC1);
    for (uint32_t i = 0; i < height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            newImgMat.at<uint8_t>(i, j) = newImg.get(i, j);
        }
    }
    
    // Display images
    cv::imshow("Original Image", imgMat);
    cv::imshow("Deserialized Image", newImgMat);
    cv::waitKey(0);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return 1;
    }
    
    testImageClassWithRealImage(argv[1]);
    return 0;
}
