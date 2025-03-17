#include <iostream>
#include <fstream>
#ifndef HEADER_H
#define HEADER_H 
struct Header 
{
uint64_t timestamp ; 
std::string sensor_name ; 
size_t  offset_position ; // could be /**std::streamoff*/
} ; 
#endif
