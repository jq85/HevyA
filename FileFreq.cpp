#include <stddef.h>// for NULL identifier
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
    if(this->charfrequencies.character[i] == current_char)
    {
      std::cout << "Char in file is: " << current_char << ", and this->charfrequencies.character[" << i << "] is: " << this->charfrequencies.character[i] << ", with frequency: " << this->charfrequencies.frequency[i] << std::endl;
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
  for(unsigned int i = 0; i < sizeof(this->charfrequencies.character)/sizeof(this->charfrequencies.character[0]); i++)
  {
    if(this->charfrequencies.character[i]==NULL)
    {
      this->charfrequencies.character[i] = current_char;
      this->charfrequencies.frequency[i] = 1;
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
    this->charfrequencies.character[index] = current_char;
    this->charfrequencies.frequency[index]++;
  }
  else if(index == -1)
  {
    appendNewCharToCharArray(current_char);
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
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    std::cout << this->charfrequencies.character[i] << " : " << this->charfrequencies.frequency[i] << std::endl;
  }
}

/*
*
*/
void FileFreq::readFile()
{
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

        showFrequencies();
    }
    else
    {
        std::cerr << "Couldn't open the input file for reading." << std::endl;
    }
  }
  else
  {
    std::cerr << "\n\tFile does not exist." << std::endl;
  }
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
void calculateRelativeFrequency()
{
  
}
