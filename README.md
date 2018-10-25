

# BRIEFING
BY V., 2018-10-11
Tengo una idea para un programa, a ver que te parece.
No es gran cosa, pero para empezar seguro que nos vale.
El programa acepta como parámetro de entrada el nombre de un documento de texto.
Lo lee y va contando la aparición de cada letra (ojo con las que llevan tilde, que podrían aparecer como diferentes).
Con eso, crea un archivo de texto con las frecuencias relativas de cada letra en el texto original.
Estoy ultimamente mirando cosas de criptografia y teoria de la informacion (digital signal processing y tal) y esto es lo mas basico.
ya me dices

# TASKS
1. [OK] Take text file name as CLI input param.
* [] Improve the class and clean the code.
  * [] Catch exceptions.
  * [] Compare every input character with ASCII values, and discard useless characters.
* [OK] Read file and count frequencies for each character.
  * [OK] Take them all in lower case for reading.
  * [OK] Calculate relative frequencies.
* [OK] Create text file to store relative frequencies for each character in the original text.
* [] Turn it into a dynamic library.

# How to use
Create an instance of the FileFreq class, initializing it with the name of the input file as first parameter, and an optional second parameter for the output file name (including extension .txt, .csv, as you wish); If no second parameter is given the overloaded constructor creates a default output file named "outputfile.txt".

Then call the method *parseFile()* to analyze the absolute and relative frequencies of the characters in the input file, and finally call *writeResultsToOutputCsvFile()* to write the results of the analysis to the output file; the content is in CSV style with one row for every *character, absolute frequency, relative frequency*.

Constructors: FileFreq('inputfile.txt'), FileFreq('inputfile.txt', 'outputfile.csv')
Main methods: parseFile(), writeResultsToOutputCsvFile().
Output file content: rows with: character, absolute frequency, relative frequency.
