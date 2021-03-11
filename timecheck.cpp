#include <iostream>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::string;

using chronoReturn = std::chrono::duration<long int, std::ratio<1, 1000000> >;

chronoReturn measureTime(string path);

int main(int argc, char** argv) {

  if (argc < 2) {
    cout << "Missing file to check. \nTry: ./timecheck <fileToCheck.cpp> \n";
    exit(1);
  }

  // save file name
  string fileName = argv[1];
  cout << "File to check: " << fileName << '\n';

  // checking if it is '*.cpp' file
  size_t commaPosition = fileName.find_last_of('.');
  string extension;
  if (commaPosition == string::npos || fileName.substr(commaPosition) != ".cpp") {
    cout << "Inappropriate file type. Exiting..\n";
    exit(2);
  }

  // cut extension from file name 
#ifdef linux
  string fileOut = fileName.erase(commaPosition) + ".out";
#else 
  string fileOut = fileName.erase(commaPosition) + ".exe";
#endif

  // build code for compiling file
  string path = "g++ ";
  path += argv[1];
  path += " -o ";
  path += fileOut;
  cout << "Compiling time: " << measureTime(path).count() << " microseconds\n";

  // build code for execution
#ifdef linux 
  fileOut = "./" + fileOut;
#else  
  fileOut = ".\\" + fileOut;
#endif
  
  cout << "Executing time: " << measureTime(fileOut).count() << " microseconds\n";

  // remove executable file
#ifdef linux 
  string removeFile = "rm " + fileOut;
#else 
  string removeFile = "del /f " + fileOut;
#endif

  system(removeFile.c_str());

  return 0;
}

chronoReturn measureTime(string path) {
  auto start = high_resolution_clock::now();
  system(path.c_str());
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return duration;
}
