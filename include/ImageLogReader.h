#include <Header.h>
#include <Image.h>
#ifndef IMAGELOGREADER_H
#define IMAGELOGREADER_H
class ImageLogReader {
public :
    ImageLogReader(std::string path) ; 
    
    Image read(Header h) ;
    std::vector<Header> view() ; 
    ~ImageLogReader() ;
private :
    void load() ;
    std::string file_path ; 
    std::fstream file ; 
    std::vector<Header> index ;
} ;
#endif
