/*
Programmers: Kevin Schoonover and Joey Kuhn
Teacher: Dr. Leopold
Section: 1D
Date: 11/06/2016
Description: This function simulates a debate between two presidential
             candidates by reading five different files in order to get inputs.
             The overview of the program is first the program reads in user
             input for a question and then generates a random candidate response
             based off of probability of interjections inbetween sentences
             splices. Then, outputs the results and scores the result based on
             length of question and caculation on randomized reponse
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

//////////
// Initialization of the constants which contain the file names of each file
// for the candidates
//////////
const char CANDIDATE1_INTERJECTIONS[50] = {"candidate1_interjections.dat"};
const char CANDIDATE1_SENTENCES[50] = {"candidate1_sentences.dat"};
const char CANDIDATE2_INTERJECTIONS[50] = {"candidate2_interjections.dat"};
const char CANDIDATE2_SENTENCES[50] = {"candidate2_sentences.dat"};
const char PREFIXES[50] = {"prefix_expressions.dat"};

//////////
// Initialization of the variables which hold the probabilties for eahc event
// happening with the program
//////////
const int CHANCE_OF_DOUBLE_CHAR_SCORE = 3;
const int CHANCE_OF_TRIPLE_CHAR_SCORE = 2;
const int CHANCE_OF_DOUBLE_WORD_SCORE = 5;
const int CHANCE_OF_TRIPLE_WORD_SCORE = 2;
const int CHANCE_OF_PREFIX = 50;
const int INTERJECTION_CHANCE = 25;

//////////
// Initialization of the variables which declares the points that each letter
// notified in the variable names accounts for
//////////
const int EAIONRTLSU_POINTS = 1;
const int DG_POINTS = 2;
const int BCMP_POINTS = 3;
const int FHVWY_POINTS = 4;
const int K_POINTS = 5;
const int XJ_POINTS = 8;
const int QZ_POINTS = 10;

//////////
// Initialization of the variables which state how many partitions the program
// can make when randomly choosing sentences from each candidate
//////////
const int MIN_PARTITIONS = 2;
const int MAX_PARTITIONS = 4;

//////////
// Inilization of the variables which handle the logistics of the program
// I.E. how many questions are asked in total and how long a line length
// coudl possibly be in characters.
//////////
const int MAX_LINE_LENGTH = 1000;
const int NUM_QUESTIONS = 8;
//////////
// @Pre: Probability must have a value between zero and one hundred
// @Post: Probabilityhandler will return true if the probability paramater is
//        greater than or equal to a random number generated between 0 and 100
// @Desc: Given a probablity, the function determines whether or not to return
//        true or false based on chance.
//////////
bool probabilityHandler(const int probability);

//////////
// @Pre: In must be a opened file with data in it to read and line must be of
//       length MAX_LINE_LENGTH. The input stream must not have lines greater
//       than MAX_LINE_LENGTH characters.
// @Post: The function passes the line it read up to a \n character by reference
//        or the first MAX_LINE_LENGTH characters it reads.
// @Desc: readLine reads a line in the ifstream in and returns the line it read
//        by reference.
//////////
void readLine(ifstream &in, char line[]);

//////////
// @Pre: in must be an opened file with data in it to read and line must be
//       of length MAX_LINE_LENGTH. The inputstream must not have lines greater
//       than
//       MAX_LINE_LENGTH characters
// @Post: The function passes the sentence it read up to a '.' character by
//        reference or the first MAX_LINE_LENGTH characters it reads
// @Desc: This function returns the first sentence it reads (ending in a .) by
//        reference.
//////////
void readSentence(ifstream &in, char line[]);

//////////
// @Pre: in must be an opened file with data in it to read, line must be of
//       length MAX_LINE_LENGTH, searchIndex must be from 0 to
//       amountOfLinesInInputStream-1 and the input stream cannot have lines
//       greater than MAX_LINE_LENGTH characters in length
// @Post: The function will return the line which it read up to (specified by)
//        searchIndex where 0 equals line one.
// @Desc: This function will read up to the index line specified in searchIndex
//        (0 being line 1) and will return its value by reference. If the file
//        has a header (tells the function how many lines are in the function)
//        the function accounts for it as specified as isHeader (i.e the header
//        line is not counted as index 0, the next line is).
//////////
void indexedLine(ifstream &in, char line[], const bool isHeader,
                int searchIndex);

//////////
// @Pre: in must be an open inputstream and the lines of the input stream
//       cannot be greater than MAX_LINE_LENGTH characters in length
// @Post: The function returns the amount of lines within a file
// @Desc: The function iterates throught the function counting how many lines
//        are in the inputstream, if there is a header file in the input stream
//        the function simply returns what is specified in the header.
//////////
int file_CountLines(ifstream &in, const bool isHeader);

//////////
// @Pre: in must have an open inputstream and the lines of the input stream
//       cannot be greater than MAX_LINE_LENGTH characters in length.
// @Post: The function returns the number of sentences in the file.
// @Desc: The function getlines through the function, stopping at every period
//        and counting it until it reaches the end of the file.
//////////
int file_CountSentences(ifstream &in);

//////////
// @Pre: line should contain at least one alphabetic character
// @Post: linescorer returns a value equal to the sum of the words multiplied
//        by a possible 2 or 3. each word's points are equal to each character
//        in the word times a possible 2 or 3.
// @Desc: Gets the points for all the characters, multiplying each of them
//        by their possible bonus, adds them together, and then multiplies
//        the word by it's possible bonus.
//////////
int lineScorer(const char line[]);

//////////
// @Pre: PREFIXES must be a valid filename to open a stream into and srand
//       should be seeded
// @Post: a random prefix has been selected and output to the screen, and
//        the points of the prefix has been added to the total score of the
//        candidate who calls the function
// @Desc: finds a random prefix from the file and outputs it.
//        then adds that prefix's score to that candidates total.
//////////
void prefixHandler(ifstream &in,int &score);

//////////
// @Pre: LowerBound must be less than upperBound.
// @Post: The function returns a random number between lowerBound
//        and upperBound.
// @Description: The function takes in lowerBound and upperBound and then
//               returns the number that is between those two parameters.
//////////
int myrand(const int minValue, const int maxValue);

//////////
// @Pre: The sentence array should have atleast one whitespace in it
// @Post: whitespaceCounter returns the number of spaces in the sentences array.
// @Desc: The function iterates throgh the array and counts the number of
//        whitespaces within the array.
//////////
int whitespaceCounter(const char sentence[]);

//////////
// @Pre: partitions must be less than partition and partitions cannot be
//       equal to zero.
// @Post: The function has cut down sentence into the length equal to
//        the number of whitespaces/partitions + 1 and returns by reference
//        a fragment shifted over the number of partition it is on
// @Desc: handles the general partitioning of the sentence by cutting it into
//        the right pieces and scoring it appropriately.
//////////
void partitionHandler(char sentence[], const int partitions,
                      const int partition, int & candScore);

//////////
// @Pre: fileName must be a vald file name in the same directory as the program
// @Post: interjectionHandler iterates through the entire file specifed in
//        fileName and returns a random line number from the file. Moreover,
//        it scores the interjction that it returns into the respective
//        canddiate score.
// @Desc: This function handles the formatting, output, and scoring of
//        interjection specified in the fileName file.
//////////
void interjectionHandler(ifstream& in, const char fileName[], int &candScore);

//////////
// @Pre: file must be a valid file name in the same directory of the program.
// @Post: the function resets the state of the input stream by closing the
//        stream, re-opening the stream at the specific file specifed in
//        fileName and clears the bitflags.
// @Desc: The function resets the ifstream with the file name specified
//        by fileName
//////////
void resetFileState(ifstream &in, const char file[]);

//////////
// @Pre: sentenceFile should be the fileName of the sentences file of the
//       specific candidate located in the same directory as the program.
//       candScore should be the score of the specific candidate associated
//       with the sentences file, and interjectionsFile must be a valid file
//       name in the same directroy as the program
// @Post: The main sentence of the candidates answer (interjections and
//        partitioned sentences) are properly formatted and output to
//        the user.
// @Desc: The function properly handles the partitionHandler to output the
//        partitioned sentences and interjectionsHandler in the correct
//        semantic order
//////////
void sentenceHandler(ifstream& in, const char sentenceFile[], int &candScore,
                     const char interjectionsFile[]);

//////////
// @Pre:  q should be the user's question and score should be the respective
//        candidates score that the question is pointed to. q must have a 
//        length > 0
// @Post: The function returns the score and also passess score by reference
//        in order to ensure proper ooutput handling of the total persistant
//        value and the tmeporary per-question value of score.
// @Desc: The function takes the user question and divides the amount of
//        charaters in the user question by the score and returns the quotient.
//////////
int scoreHandler(const char q[], int &score);

//////////
// @Pre: in must be an opened stream, index mustbe >= 0 and the sentences
//       should not be greater than MAX_LINE_LENGTH.
// @Post: The function returns the indexed sentence (index 0 is line 1)
//        specified in parameter. If isHeader is true, index 0 is line 2
//        (skipping header).
// @Desc: the function returns the indexed sentence from the file specified
//        in the in stream.
//////////
void indexedSentence(ifstream &in, const int index,
                     const bool isHeader, char sentence[]);

//////////
// @Pre: startWord must be >= 0 and startWord must be less than endWord
// @Post: The function returns the sentence spliced betwteen startWord
//       (indexed by 0) and the end word
// @Desc: The function takes a sentences and splices the sentence between
//        the startWord and endWord using index 0
//////////
void wordSplice(char sentence[], const int startWord, const int endWord);

//////////
// @Pre: None
// @Post: the first null index in sentence is converted to
//        either a period, an exclamation point, or a question mark,
//        based on chance.
// @Desc: Decides with what punctuation a sentence will end.
//////////
void punctHandler(char sentence[]);

//////////
// @Pre: None
// @Post: Whoever has the lower score has been output to the screen as the
//        winner
// @Desc: The function comapres scand1Score and cand2Score and outputs the
//        winner being whoever has the least score between the tw.
//////////
void declareWinner(const int cand1Score, const int cand2Score);

#endif
