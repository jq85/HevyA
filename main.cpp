#include "FileFreq.h"

/*
* Character frequency in file counter.
* charset=ISO-8859-1
*/
int main(int argc, char *argv[])
{
  int ret_val = -1;
  //Take second argument as input file name:
  FileFreq *ff;
  if((argv[1]!=0) && (argv[2]==0))
  {
    ff = new FileFreq(argv[1]);
  }
  else if((argv[1]!=0) && (argv[2]!=0))
  {
    ff = new FileFreq(argv[1], argv[2]);
  }

  // READ FILE, AND PARSE AND ANALYZE CHARACTERS
  ret_val = ff->parseFile();

  std::cout << "You have entered " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i)
  {
      std::cout << "\t- " << argv[i] << std::endl;
  }
  std::cout << "The input file is " << ff->getTotalNumberOfChars() << " characters long, and it has " << ff->getTotalNumberOfUniqueChars() << " unique characters." << std::endl << std::endl;

  // std::cout << "\n\n\t" << ret_val << "\n";

  // WRITE RESULTS TO CSV FILE
  ret_val = ff->writeResultsToOutputCsvFile();

  // std::cout << "\n\t" << ret_val << "\n";

  // TRYING GETTER
  float relativeFrequency[128];
  ff->getRelativeFrequencies(relativeFrequency);
  for (int i = 0; i < 128; i++)
  {
    std::cout << relativeFrequency[i] << std::endl;
  }

  return ret_val;
}
