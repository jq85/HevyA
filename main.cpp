#include "FileFreq.h"

/*
* Character frequency in file counter.
* charset=ISO-8859-1
*/
int main(int argc, char *argv[])
{
  int ret_val = -1;
  //Take second argument as input file name:
  FileFreq *ff = new FileFreq(argv[1]);

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
  // ret_val = ff->writeResultsToOutputFile();

  // std::cout << "\n\t" << ret_val << "\n";

  return ret_val;
}
