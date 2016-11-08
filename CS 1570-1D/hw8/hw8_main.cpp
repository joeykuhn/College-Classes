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
        //////////
        // Copying the filename into the interjections variable for modular
        // handling of parameters and readability.
        //////////
        strcpy(interjections,CANDIDATE1_INTERJECTIONS);
        strcpy(sentences,CANDIDATE1_SENTENCES);

        //////////
        // Handling of the printing, scoring, and formatting of the prefix
        // if the probably of CHANCE_OF_PREFIX successed.
        /////////
        if(probabilityHandler(CHANCE_OF_PREFIX))
        {
          prefixHandler(curFile, candidate1Score);
        }

        //////////
        // Handling of the printing, scoring, and formatting of the main
        // sentence of the answer including partitioning of the random files
        // and interjections on probability
        //////////
        sentenceHandler(curFile, sentences, candidate1Score, interjections);

        //////////
        // adding the current answer score of the question to global variable
        // for persistance to outout the correct overall winner.
        //////////
        candidate1TotalScore +=  scoreHandler(question, candidate1Score);

        /////////
        // Outputting the score of the current answer.
        //////////
        cout << "The score of this answer was: " << candidate1Score << endl
             << endl;

        //////////
        // Reseting the current candidate score for the next iteration of
        // question
        //////////
        candidate1Score = 0;
      }
      else if(candidate == 2)
      {
        //////////
        // Copying the filename into the interjections variable for modular
        // handling of parameters and readability.
        //////////
        strcpy(interjections,CANDIDATE2_INTERJECTIONS);
        strcpy(sentences,CANDIDATE2_SENTENCES);

        //////////
        // Handling of the printing, scoring, and formatting of the prefix
        // if the probably of CHANCE_OF_PREFIX successed.
        //////////
        if(probabilityHandler(CHANCE_OF_PREFIX))
        {
          prefixHandler(curFile, candidate2Score);
        }

        //////////
        // Handling of the printing, scoring, and formatting of the main
        // sentence of the answer including partitioning of the random files
        // and interjections on probability
        //////////
        sentenceHandler(curFile, sentences, candidate2Score, interjections);

        //////////
        // adding the current answer score of the question to global variable
        // for persistance to outout the correct overall winner.
        //////////
        candidate2TotalScore += scoreHandler(question, candidate2Score);

        //////////
        // Outputting the score of the current answer.
        //////////
        cout << "The score of this answer was: " << candidate2Score << endl
             << endl;

         //////////
         // Reseting the current candidate score for the next iteration of
         // question
         //////////
        candidate2Score = 0;
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
