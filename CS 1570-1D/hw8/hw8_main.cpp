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

int main()
{
  //////////
  // Seeding the random number generator
  //////////
  srand(time(NULL));

  //////////
  // Initialization of the stream which handles all file I/O for the program
  //////////
  ifstream curFile;

  //////////
  // Initialization of the variables to store the current interjections and
  // sentences file
  //////////
  char interjections[50];
  char sentences[50];

  //////////
  // Initialization of the variaable to store the user's question for use
  // in the total score
  //////////
  char question[1000];

  //////////
  // Variable initialization for the scoring aspects of each candiddate
  // including score for each individual question and the total score
  // of every question.
  //////////
  int candidate1Score = 0;
  int candidate2Score = 0;
  int candidate1TotalScore = 0;
  int candidate2TotalScore = 0;

  for (int qAsked = 1; qAsked <= NUM_QUESTIONS; qAsked++)
  {
      //////////
      // Question handler for the candidates to decide who the candidate is
      // addressed t.
      //////////
      int candidate = (qAsked % 2 == 0) ? 2 : 1;
      cout << "Question for candidate " << candidate << ": ";

      //////////
      // User input for the question to save later for scoring purposes.
      //////////
      cin.getline(question, MAX_LINE_LENGTH, '\n');

      //////////
      // Proper handling for the different candidates for modular approach to
      // file I/O regardless of the question nuber.
      //////////
      if(candidate == 1)
      {
        strcpy(interjections, CANDIDATE1_INTERJECTIONS);
        strcpy(sentences, CANDIDATE1_SENTENCES);
        candidateHandler(interjections, sentences, curFile,
                                      candidate1Score, question, candidate1TotalScore);
      }
      else if(candidate == 2)
      {
        strcpy(interjections, CANDIDATE2_INTERJECTIONS);
        strcpy(sentences, CANDIDATE2_SENTENCES);
        candidateHandler(interjections, sentences, curFile,
                                       candidate2Score, question, candidate2TotalScore);
      }
  }

  //////////
  // Determine the winner after all iterations of questions and outputting the
  // final score of each candidate
  //////////
  declareWinner(candidate1TotalScore, candidate2TotalScore);

  //////////
  // Obligatory end
  //////////
  return 0;
}
