#include "FileFreq.h"

/*
* Character frequency in file counter.
* charset=ISO-8859-1
*/
int main(int argc, char *argv[])
{
  //Take second argument as input file name:
  FileFreq *ff = new FileFreq(argv[1]);

  ff->readFile();

  std::cout << "You have entered " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i)
  {
      std::cout << "\t- " << argv[i] << std::endl;
  }
  std::cout << "The input file is " << ff->getTotalNumberOfChars() << " characters long, and it has " << ff->getTotalNumberOfUniqueChars() << " unique characters." << std::endl << std::endl;

  return 0;
}
