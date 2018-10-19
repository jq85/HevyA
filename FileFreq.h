#include <iostream>

class FileFreq
{
public:
  FileFreq(std::string inputfilename);
  void readFile();

private:
  static const unsigned int ASCII_SIZE = 128;
  struct char_frequencies {
    unsigned int length;
    unsigned char character[ASCII_SIZE];
    unsigned int frequency[ASCII_SIZE];
    unsigned short relative_frequency[ASCII_SIZE];
  };
  char_frequencies charfrequencies = {ASCII_SIZE, {""}, {0}};
  std::string inputfilename;
  char m_char;
  void read(std::istream & is);
  int findCharInCharArray(char current_char);
  void increaseCharFrequencyCounter(char current_char);
  void showFrequencies();
  void appendNewCharToCharArray(char current_char);
  bool file_exists(const std::string &name);
  void calculateRelativeFrequency();
};
