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

#include "hw8_header.h"


bool probabilityHandler(const int probability)
{
  int number = rand() % 101;

  if(probability == 0)
  {
    return false;
  }
  else if (probability >= number)
  {
    return true;
  }
  else
  {
    return false;
  }

  return false;
}

void readLine(ifstream &in, char line[])
{
  in.getline(line, MAX_LINE_LENGTH, '\n');

  return;
}

void readSentence(ifstream &in, char line[])
{
  in.getline(line, MAX_LINE_LENGTH, '.');
  int lineLength = strlen(line);

  if((line[0] = ' '))
  {
    for(int i = 0; i < lineLength; i++)
    {
      line[i] = line[i+1];
    }
    line[strlen(line)] = '\0';
  }

  return;
}

void indexedLine(ifstream &in, char line[], const bool isHeader,
                 int searchIndex)
{
  if(isHeader)
  {
    searchIndex--;
  }

  for (int currentLine = 0; currentLine <= searchIndex; currentLine++)
  {
    readLine(in, line);
  }

  return;
}

int file_CountLines(ifstream &in, const bool isHeader)
{
  int lines = 0;
  char line[MAX_LINE_LENGTH] = {'\0'};

  if (isHeader)
  {
    in >> lines;
    return lines;
  }

  while(in.getline(line, MAX_LINE_LENGTH, '\n'))
  {
      lines++;
  }

  return lines;
}

int file_CountSentences(ifstream &in)
{
  int sentences = 0;
  char curLine[MAX_LINE_LENGTH];
  while (in.getline(curLine,MAX_LINE_LENGTH,'.'))
  {
    sentences++;
  }

  return sentences;
}

int lineScorer(const char line[])
{
  int lineScore = 0;
  int wordScore = 0;
  int lineLength = strlen(line);

  for (int i = 0; i < lineLength; i++)
  {
    char curLetter = tolower(line[i]);
    int charScore = 0;

    switch(curLetter)
    {
      case 'e':
      case 'a':
      case 'i':
      case 'o':
      case 'n':
      case 'r':
      case 't':
      case 'l':
      case 's':
      case 'u':
      {
        charScore += EAIONRTLSU_POINTS;
        break;
      }
      case 'd':
      case 'g':
      {
        charScore += DG_POINTS;
        break;
      }
      case 'b':
      case 'c':
      case 'm':
      case 'p':
      {
        charScore += BCMP_POINTS;
        break;
      }
      case 'f':
      case 'h':
      case 'v':
      case 'w':
      case 'y':
      {
        charScore += FHVWY_POINTS;
        break;
      }
      case 'k':
      {
        charScore+= K_POINTS;
        break;
      }
      case 'x':
      case 'j':
      {
        charScore += XJ_POINTS;
        break;
      }
      case 'q':
      case 'z':
      {
        charScore += QZ_POINTS;
        break;
      }
      default:
      {
        break;
      }
    }

    if (probabilityHandler(CHANCE_OF_DOUBLE_CHAR_SCORE))
    {
      charScore *= 2;
    }
    else if (probabilityHandler(CHANCE_OF_TRIPLE_CHAR_SCORE))
    {
      charScore *= 3;
    }

    wordScore += charScore;

    if(isspace(line[i]))
    {
      if(probabilityHandler(CHANCE_OF_DOUBLE_WORD_SCORE))
      {
        wordScore *= 2;
      }
      else if(probabilityHandler(CHANCE_OF_TRIPLE_WORD_SCORE))
      {
        wordScore *= 3;
      }

      lineScore += wordScore;
      wordScore = 0;
    }
  }

  return lineScore;
}

void prefixHandler(ifstream &in, int &score)
{
    resetFileState(in, PREFIXES);

    char curLine[MAX_LINE_LENGTH];

    int prefix_lines = file_CountLines(in, false);

    resetFileState(in, PREFIXES);

    const int PICKED_PREFIX = (rand() % prefix_lines);


    indexedLine(in, curLine, false, PICKED_PREFIX);

    cout << curLine << " ";
    score += lineScorer(curLine);

    return;
}

int whitespaceCounter(const char sentence[])
{
  int whitespace = 0;
  int sentenceLength = strlen(sentence);
  for (int i = 0; i < sentenceLength; i++)
  {
    if (isspace(sentence[i]))
    {
      whitespace++;
    }
  }
  return whitespace;
}

int myrand(const int minValue, const int maxValue)
{
  return(rand() % (maxValue-minValue) + minValue);
}

void indexedSentence(ifstream &in, const int index,
                     const bool isHeader, char sentence[])
{
  if(isHeader)
  {
    int temp;
    in >> temp;
  }

  for(int i=0; i <= index; i++)
  {
    readSentence(in, sentence);
  }

  return;
}



void partitionHandler(char sentence[], const int partitions,
                      const int partition, int &candScore)
{
  int wordsNeeded = 0;
  int spaces = whitespaceCounter(sentence);
  wordsNeeded = (spaces/partitions + 1);

  wordSplice(sentence, (wordsNeeded * partition),
             (wordsNeeded * partition) + wordsNeeded - 1);

  if (partitions == partition + 1)
  {
    punctHandler(sentence);
  }

  cout << sentence;
  candScore += lineScorer(sentence);


  return;
}

void wordSplice(char sentence[], const int startWord, const int endWord)
{
  char temp[MAX_LINE_LENGTH];
  int counter = 0;
  int index = 0;
  int sentenceLength = strlen(sentence);

  for(int i = 0; i < sentenceLength; i++)
  {
    if(sentence[i] != '\n')
    {
      if(counter >= startWord && counter <= endWord)
      {
        temp[index] = sentence[i];
        index++;
      }

      if(isspace(sentence[i]))
      {
        counter++;
      }
    }

    sentence[i] = '\0';
  }

  strcpy(sentence, temp);
  sentence[index] = '\0';

  return;
}


void interjectionHandler(ifstream& in, const char fileName[], int& candScore)
{

  resetFileState(in, fileName);

  char interjection[MAX_LINE_LENGTH];
  int interjectionIndex = myrand(2,file_CountLines(in, true)+1);

  indexedLine(in, interjection, true, interjectionIndex);
 // cout << "Interjection Indx: " << interjectionIndex << endl;


  candScore += lineScorer(interjection);
  cout << interjection << " ";

  return;
}

void sentenceHandler(ifstream& in, const char sentenceFile[], int &candScore,
                     const char interjectionsFile[])
{
  char sentence[MAX_LINE_LENGTH];

  int partitions = myrand(MIN_PARTITIONS,MAX_PARTITIONS);


  resetFileState(in, sentenceFile);


  int file_amountOfSentences = file_CountLines(in,true);


  for(int i=0; i < partitions; i++)
  {
    resetFileState(in, sentenceFile);
    indexedSentence(in, myrand(0,file_amountOfSentences-1), true, sentence);

    partitionHandler(sentence, partitions, i, candScore);

    if(i != partitions-1)
    {
      resetFileState(in, interjectionsFile);
      if(probabilityHandler(INTERJECTION_CHANCE))
      {
        interjectionHandler(in, interjectionsFile, candScore);
      }
    }
  }

  cout << endl << endl;

  return;
}

void resetFileState(ifstream &in, const char file[])
{
  in.close();
  in.open(file);
  in.clear();

  return;
}

int scoreHandler(const char q[], int &score)
{
  if(strlen(q) > 0)
  {
    score = score/strlen(q);
    return(score);
  }
  else
  {
    cout << "[Error] Please enter a valid question. This score will not be "
         << "counted." << endl;
  }

  return(0);
}

void punctHandler(char sentence[])
{
  int length = strlen(sentence);
  int punctuation = myrand(0,100);
  if (isalpha(sentence[length]))
  {
    length+= 100;
  }
  if (punctuation < 40)
  {
    sentence[length] = '.';
  }
  else if (punctuation > 70)
  {
    sentence[length] = '!';
  }
  else
  {
    sentence[length] = '?';
  }
  sentence[length+1] = '\0';
  return;
}


void declareWinner(const int cand1Score, const int cand2Score)
{
  if (cand1Score < cand2Score)
  {
    cout << "Candidate 1 is the winner with " << cand1Score << "!" << endl;
    cout << "Candidate 2 had " << cand2Score << '!' << endl;
  }
  else
  {
    cout << "Candidate 2 is the winner with " << cand2Score << "!" << endl;
    cout << "Candidate 1 had " << cand1Score << "!" << endl;
  }
  return;
}
