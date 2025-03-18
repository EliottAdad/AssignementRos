#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <stdint.h>
#include <vector>
#include <cstring>

#define SIZE_SENSOR_NAME 100

class Image {
protected:
  char sensor[SIZE_SENSOR_NAME];
  uint64_t timestamp;
  uint32_t w;
  uint32_t h;
  //std::vector<uint8_t> data;
  uint8_t* data;
  
public:
  Image(uint32_t w, uint32_t h);
  ~Image();
  uint32_t getWidth() const;
  void setWidth(uint32_t w);
  uint32_t getHeight() const;
  void setHeight(uint32_t h);
  uint64_t getTimestamp() const;
  void setTimestamp(uint64_t timestamp);
  char* getSensor();
  void setSensor(std::string sensor);
  uint8_t* getData();
  uint8_t getDataFromIndex(unsigned int i) const;
  void setDataFromIndex(unsigned int i, uint8_t data);
  std::vector<uint8_t> toBytestream() const;
  void fillFromBytestream(std::vector<uint8_t> bytestream);
};


#endif /* IMAGE_H_ */
