<<<<<<< HEAD
# AssignementRos
This is an assignement to test the capabilities of the candidates of multinnov intern candidates.
The assingement will be live coding and it's purpose will be to assess the programming awareness and 
thought process of the candidates in a live situation. 
The assignement's duration is 2h to code a logging system for sensor data.

# Setup 
The candidate will need to have a debian system like ubuntu (or any variation of it) , debian or any other "apt" enabled system , with a graphical interface (not  server).
Any other linux system is fine as long as the assignements dependancies can be installed or built from source(although thas would take a lot of time). 
The dependancies are : 
 - C++ STL (11)
 - OpenCV library ( > 4.1)
 - Boost (> 1.7)

 To install the dependancies with apt 
 ```bash
 sudo apt install libopencv-dev
 sudo apt install libboost-all-dev
 sudo apt install cmake 
 ```
## Assignement : 
    You are working on a time constrained and computing power constrained system . 
    You are given a set of image sensor that can give you a graysclale image stream to be processed for a robotic application.
    Your mission is to store all sensor's datas in a single file in a for a faster recovery later on since you don't have enough computing  power to  process them in real time.
    You will structure your work into 3 parts. 
        1- Image representation.
            Code a simple class called Image  that has the following members : 
             - The width of the image (uint32_t)
             - The height of the image (uint32_t)
             - The timestamp of the image (uint64_t)
             - The name of the sensor (char* or std::string)
             - An array of vector to store the datas of the image. It should be a contigous array of uint8_t since your grascale values are encoded on a byte.
             - An accessor method to read the value of a pixel from indexes .  
             - A setter method to write the values of a pixel from indexex. 
             - A **serialize** method to turn the image data structure into a bytestream
             - A **deserialize** method fill the data structure from a bytestream.
        
        2 - Code a Header data structure that contains 
                * The timestamp of an image
                * The name of the sensor
                * The stream position of the image's data in the stream. 
        
        3 - Image Logger representation : 
            Since you succeeded in coding an image representation and a serialization and deserialization method , you can move to writing all the image into a single contigous file.
            For that purpose you will write an ImageLogger class that has the purpose of reading and writing a the datas bytestreams into a file with the following members : 
            - A file member (std::fstream) to handle read and write operations 
            - A vector constaining a list of headers that will act like an index for us.
            - A load method that reads a log file to form an index from it if the log file exists, and if not, the index remains empty.
            - A write method that writes image data into a log file. 
            
        4  - An Image Reader class that reads the serialize datas back to an image : 
            - A read method that reads a file provided a  Header.
            - A readAll method that returns the index for a quick walkthough of the datas without actually having them in memory. 
        
    Test will be ready for each of the components you code.
    Good luck !!

 
<<<<<<< HEAD
(Assignement for intern v1.0)
=======
    
=======
# AssignementRos
>>>>>>> 06c8787 (Initial commit)
>>>>>>> 4dd1775 (Initial commit)
