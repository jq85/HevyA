#include "FileFreq.h"

/*
* Character frequency in file counter.
* charset=ISO-8859-1
*/
int main(int argc, char *argv[])
{
  FileFreq *ff = new FileFreq(argv[1]);

  ff->readFile();

  std::cout << "You have entered " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i)
  {
      std::cout << argv[i] << std::endl;
  }

  return 0;
}
