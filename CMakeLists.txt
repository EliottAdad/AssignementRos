cmake_minimum_required(VERSION 3.10)

project(ImageLoggerProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)

include_directories(
    include 
    ${OpenCV_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIRS}
)

add_executable(test_IMAGE src/test_IMAGE.cpp src/image.cpp )
#add_executable(test_IMAGELOGGER src/test_IMAGELOGGER.cpp src/Image.cpp src/ImageLogger.cpp src/ImageLogReader.cpp)
target_link_libraries(test_IMAGE ${OpenCV_LIBS} ${Boost_LIBRARIES})
#target_link_libraries(test_IMAGELOGGER ${OpenCV_LIBS} ${Boost_LIBRARIES})

