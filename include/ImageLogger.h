#include "Header.h"
#include "Image.h"
#ifndef IMAGELOGGER_H
#define IMAGELOGGER_H

class ImageLogger {
public :
ImageLogger(std::string path )  ; 
bool write(Image* img) ;
~ImageLogger() ; 

private :
std::string file_path ;
std::ofstream file ; 
} ; 
#endif