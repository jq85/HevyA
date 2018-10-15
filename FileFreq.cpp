#include <fstream>
#include <iostream>
#include "FileFreq.h"

// Constructor.
FileFreq::FileFreq(std::string inputfilename)
  : inputfilename(inputfilename)
{
}

/*
*
*/
void FileFreq::read(std::istream & is)
{
  is.read((char*)&m_char, sizeof(char));
}

/*
*
*/
int FileFreq::findCharInCharArray(char current_char)
{
  int index = -1;
  for (int i = 0; i < 59; i++)
  {
    if(this->cfs.chars[i] == current_char)
    {
      std::cout << "Char in file is: " << current_char << ", and this->cfs.chars[" << i << "] is: " << this->cfs.chars[i] << ", with frequency: " << this->cfs.freqs[i] << std::endl;
      index = i;
      break;
    }
  }

  return index;
}

/*
*
*/
void FileFreq::appendToCharArray(char current_char)
{
  for(int i = 0; i < 29; i++)
  {
    if(this->cfs.chars[i]==NULL)
    {
      this->cfs.chars[i] = current_char;
      this->cfs.freqs[i] = 1;
      break;
    }
  }
}

/*
*
*/
void FileFreq::increaseCharFrequencyCounter(char current_char)
{
  int index = findCharInCharArray(current_char);
  if(index > -1)
  {
    this->cfs.chars[index] = current_char;
    this->cfs.freqs[index]++;
  }
  else if(index == -1)
  {
    appendToCharArray(current_char);
  }
  else
  {
    std::cout << "ERROR" << std::endl;
  }
}

/*
*
*/
void FileFreq::showFrequencies()
{
  for (int i = 0; i < 59; i++)
  {
    std::cout << this->cfs.chars[i] << " : " << this->cfs.freqs[i] << std::endl;
  }
}

/*
*
*/
void FileFreq::readFile()
{
  std::ifstream ifile(this->inputfilename, std::ios_base::in);
  if (ifile.is_open())
  {
      while (!ifile.eof())
      {
          this->read(ifile);
          if (ifile.gcount() == 0)
          {
              break;
          }
          increaseCharFrequencyCounter(this->m_char);
      }
      ifile.close();

      std::cout << "Finished reading the data from the input file." << std::endl;

      showFrequencies();
  }
  else
  {
      std::cerr << "Couldn't open the input file for reading." << std::endl;
  }
}
