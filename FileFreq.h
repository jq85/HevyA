#include <iostream>

class FileFreq
{
public:
  FileFreq(std::string inputfilename);
  void readFile();

private:
  struct charfreqstr {
    int length;
    char chars[60];
    int freqs[60];
  };
  charfreqstr cfs = {60, {""}, {0}};
  std::string inputfilename;
  char m_char;
  void read(std::istream & is);
  int findCharInCharArray(char current_char);
  void increaseCharFrequencyCounter(char current_char);
  void showFrequencies();
  void appendToCharArray(char current_char);
};
