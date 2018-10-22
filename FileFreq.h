#include <iostream>
#include <limits.h>

class FileFreq
{
public:
  FileFreq(std::string inputfilename);
  FileFreq(std::string inputfilename, std::string outputfilename);
  int parseFile();
  unsigned int getTotalNumberOfUniqueChars();
  unsigned long getTotalNumberOfChars();
  int writeResultsToOutputCsvFile();
  // void getRelativeFrequencies(float *relativeFrequency[]);

private:
  static const unsigned int ASCII_SIZE = 128;
  struct file_characters {
    unsigned int totalNumberOfUniqueChars;
    unsigned long totalNumberOfChars;
    unsigned char character[ASCII_SIZE];
    unsigned long absoluteFrequency[ASCII_SIZE];
    float relativeFrequency[ASCII_SIZE];
  };
  file_characters characters = {0, 0, {""}, {0}, {0}};
  std::string inputfilename;
  std::string outputfilename;
  char m_char;
  void read(std::istream & is);
  int findCharInCharArray(char current_char);
  void increaseCharFrequencyCounter(char current_char);
  void printRelativeFrequencies();
  void appendNewCharToCharArray(char current_char);
  bool file_exists(const std::string &name);
  void calculateRelativeFrequencies();
};
