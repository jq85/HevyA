#include "FileFreq.h"
#include <stddef.h>// for NULL identifier
#include <fstream>
#include <iostream>
#include <stdexcept>

#include <cstdint>
#include <cstring>

// Constructor.
FileFreq::FileFreq(std::string inputfilename)
  : inputfilename(inputfilename), outputfilename("outputfile.txt")
{
  // this->charfrequencies = {ASCII_SIZE, {""}, {0}, {0}};
}

FileFreq::FileFreq(std::string inputfilename, std::string outputfilename)
  : inputfilename(inputfilename), outputfilename(outputfilename)
{
  // this->charfrequencies = {ASCII_SIZE, {""}, {0}, {0}};
}

/*
*
*/
void FileFreq::read(std::istream &is)
{
  is.read((char*)&m_char, sizeof(char));
}

/*
*
*/
int FileFreq::findCharInCharArray(char current_char)
{
  int index = -1;
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    if(this->characters.character[i] == current_char)
    {
      // std::cout << "input char: " << current_char << ", match[" << i << "]: " << this->characters.character[i] << ", abs freq: " << this->characters.absoluteFrequency[i] << ", rel freq: " << this->characters.relativeFrequency[i] << " " << std::endl;
      index = i;
      break;
    }
  }
  return index;
}

/*
*
*/
void FileFreq::appendNewCharToCharArray(char current_char)
{
  for(unsigned int i = 0; i < sizeof(this->characters.character)/sizeof(this->characters.character[0]); i++)
  {
    if(this->characters.character[i]==0)//NOTE: comparing to 0 instead of NULL
    {
      this->characters.totalNumberOfUniqueChars++;
      this->characters.totalNumberOfChars++;
      this->characters.character[i] = current_char;
      this->characters.absoluteFrequency[i] = 1;
      break;
    }
  }
}

/*
*
*/
void FileFreq::increaseCharFrequencyCounter(char current_char)
{
  // char* position = std::find(this->characters.character, /*( this->characters.character + sizeof(this->characters.character) / sizeof(this->characters.character[0]) )*/, current_char);
  int index = findCharInCharArray(current_char);
  if(index > -1)
  {
    this->characters.totalNumberOfChars++;
    this->characters.absoluteFrequency[index]++;
    // std::cout << "abs freq: " << this->characters.absoluteFrequency[index] << ", tot No Chars: " << this->characters.totalNumberOfChars << std::endl;
  }
  else if(index == -1)
  {
    appendNewCharToCharArray(current_char);
  }
}

/*
*
*/
void FileFreq::printRelativeFrequencies()
{
  float tmp = 0;
  std::cout << std::endl << "char, abs freq, rel freq:" << std::endl;
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    if (this->characters.character[i] != 0)
    {
      std::cout << this->characters.character[i] << ", " << this->characters.absoluteFrequency[i] << ", " << this->characters.relativeFrequency[i] << std::endl;
    }
    tmp = tmp + this->characters.relativeFrequency[i];
  }
  // std::cout << "totalNumberOfUniqueChars: " << this->characters.totalNumberOfUniqueChars << std::endl << "totalNumberOfChars: " << this->characters.totalNumberOfChars << ", tmp: " << tmp << std::endl;
}

/*
*
*/
void FileFreq::getRelativeFrequencies(float relativeFrequency[])
{
  std::memcpy(relativeFrequency, this->characters.relativeFrequency, sizeof(float)*128);
}

/*
*
*/
int FileFreq::parseFile()
{
  int ret_val = -1;
  //Check if file exists:
  if(this->file_exists(this->inputfilename))
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
            //transform character to lower case
            this->m_char = tolower(this->m_char);
            //count frequency
            increaseCharFrequencyCounter(this->m_char);
        }
        ifile.close();

        std::cout << "Finished reading the data from the input file." << std::endl;

        calculateRelativeFrequencies();
        printRelativeFrequencies();
        ret_val = 0;//No errors
    }
    else
    {
        std::cerr << "Couldn't open the input file for reading." << std::endl;
        ret_val = -1;
    }
  }
  else
  {
    std::cerr << "\n\tFile does not exist." << std::endl;
    ret_val = -1;
  }
  return ret_val;
}

/*
*
*/
bool FileFreq::file_exists(const std::string &name)
{
  std::ifstream f(this->inputfilename.c_str());
  return f.good();
}

/*
*
*/
void FileFreq::calculateRelativeFrequencies()
{
  for (unsigned int i = 0; i < this->characters.totalNumberOfUniqueChars; i++)
  {
    this->characters.relativeFrequency[i] = ((float)this->characters.absoluteFrequency[i]/(float)this->characters.totalNumberOfChars);
    // std::cout << "abs freq: " << this->characters.absoluteFrequency[i] << ", tot No Chars: " << this->characters.totalNumberOfChars << ", rel freq: " << this->characters.relativeFrequency[i] << std::endl;
  }
}

/*
* NOTE: GETTERS AND SETTERS
*/

/*
*
*/
unsigned int FileFreq::getTotalNumberOfUniqueChars()
{
  return this->characters.totalNumberOfUniqueChars;
}

/*
*
*/
unsigned long FileFreq::getTotalNumberOfChars()
{
  return this->characters.totalNumberOfChars;
}

int FileFreq::writeResultsToOutputCsvFile()
{
  int ret_val = -1;
  std::ofstream ofile(this->outputfilename);
  if (ofile.is_open())
  {
    ofile << "char, abs freq, rel freq" << std::endl;
    for (int i = 0; i < ASCII_SIZE; i++)
    {
      ofile << this->characters.character[i] << ", " << this->characters.absoluteFrequency[i] << ", " << this->characters.relativeFrequency[i] << std::endl;
    }
    ofile.close();
    std::cout << "Finished writing text to the output file." << std::endl;
  }
  else
  {
      std::cerr << "Couldn't open the output file for writing." << std::endl;
  }
  return ret_val;
}
