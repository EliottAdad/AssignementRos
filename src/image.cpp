#include "image.hpp"


Image::Image(uint32_t w, uint32_t h) {
  this->w=w;
  this->h=h;
  this->data=(uint8_t*)calloc(w*h, sizeof(uint8_t));
}

Image::~Image() {
  //this->data.empty();
  free(this->data);
}

uint32_t Image::getWidth() const {
  return this->w;
}
  
void Image::setWidth(uint32_t w){
  this->w=w;
}

uint32_t Image::getHeight() const {
  return this->h;
}

uint64_t Image::getTimestamp() const{
  return this->timestamp;
}

void Image::setTimestamp(uint64_t timestamp) {
  this->timestamp=timestamp;
}

char* Image::getSensor() {
  return this->sensor;
}

void Image::setSensor(std::string sensor) {
  //this->sensor=sensor.c_str();
  memcpy(this->sensor, sensor.c_str(), SIZE_SENSOR_NAME);
}

uint8_t* Image::getData() {
  return this->data;
}

uint8_t Image::getDataFromIndex(unsigned int i) const {
  return this->data[i];
}

void Image::setDataFromIndex(unsigned int i, uint8_t data) {
  this->data[i]=data;
}

std::vector<uint8_t> Image::toBytestream() const {
  std::vector<uint8_t> answ;
  
  // Push the sensor name
  for (uint8_t ind=0 ; ind<SIZE_SENSOR_NAME ; ind++){
    uint8_t to_add=(uint8_t)this->sensor[ind];
    answ.push_back(to_add);
  }
  
  // Push the timestamp
  for (uint8_t ind=0 ; ind<8 ; ind++){
    uint8_t shft_by=ind *8;
    uint8_t to_add=this->h>>shft_by;
    answ.push_back(to_add);
  }
  
  // Push the width
  for (uint8_t ind=0 ; ind<4 ; ind++){
    uint8_t shft_by=ind *8;
    uint8_t to_add=this->w>>shft_by;
    answ.push_back(to_add);
  }
  
  // Push the height
  for (uint8_t ind=0 ; ind<4 ; ind++){
    uint8_t shft_by=ind *8;
    uint8_t to_add=this->h>>shft_by;
    answ.push_back(to_add);
  }
  
  // Add the data in the end
  for (int j=0 ; j<w*h ; j++){
    answ.push_back(data[j]);
  }
  //answ.insert(answ.end(), this->data.begin(), this->data.end());

  return answ;
}


void Image::fillFromBytestream(std::vector<uint8_t> bytestream) {
  int i(0);
  // Retreives the name of the sensor
  for (int j(0) ; j<SIZE_SENSOR_NAME ; j++){
      this->sensor[j]=(char)bytestream[i];
      i++;
  }
  
  // Retreives the timestamp
  this->timestamp=0;
  for (int j(0) ; j<8 ; j++){
      this->timestamp+=bytestream[i]<<8*j;
      i++;
  }
  
  // Retreives the width
  for (int j(0) ; j<4 ; j++){
      this->w+=bytestream[i]<<8*j;
      i++;
  }
  
  // Retreives the height
  for (int j(0) ; j<4 ; j++){
      this->h+=bytestream[i]<<8*j;
      i++;
  }
  
  // Retreives the data
  for (int j(0) ; j<bytestream.size() ; j++){
      this->data[j]=bytestream[i];
      i++;
  }
}
