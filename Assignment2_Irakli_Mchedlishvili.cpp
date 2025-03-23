//the task is following:
/*Write a program to read an arbitrary-length list of scores between 1 and 99 from a text file named
scores.txt. After reading the scores, your program must analyze all of them, determine the average score
and print statistics about the number of scores less than or equal to that average and the number of scores
above it. The following is a sample output of the program:
*/
//main working principle:
/*I am going to calculate sum at first and then calculate the average.
I dont know how to create an int array that will be infinite, therefore, after calculating the mean,
I am going to re-run the loop and compare each score to the mean.

I made this code so that in the file, it should only be the numbers in the specific order. 
one line should contain only one score and nothing else (except'\n') 
I made this on purpose to be neat*/

#include <iostream> //includes iostream library
#include <fstream>//includes fstream library
using namespace std;//we no longer have to write std::before the functions in loop after writing this

int main()//code begins
{
	ifstream score;//I named the object "score"
	char c = '\n';//declared char variable which we will use to get the data from the file
	score.open("C:\\Users\\acer\\Desktop\\scores.txt");//opens the file I have placed in desktop. (I couldn't do otherwise)
	if (score.fail()) {//user will be notifyed that there was an error opening a file by using this if.
		cout << "Error opening file";
		return -1;//it will end the code
	}
	int n = 0;//n defines how many scores does a file contains
	int sum = 0;//we calculate sum at first to then calculate the mean  value
	int a = 0;//a is one score during one loop. it will constantly change.

	//right now I will just write the do-while loop to calculate the sum. 
	do {
		score >> a;//gets the value of a.
		n++;//it tracks which score is it
		if (a < 1 || a>99) {//i just added this so that it would match the given requirements of the task.
			cout << "the score number " << n << "doesnt satisfy the requirements. correct it and run the program again";
			return -1;
		}
		if (c != '\n') {//i just added this so that it would match the given requirements of the task.
			if(n-1==0)
				cout << "the score number " << 1 << "doesnt satisfy the requirements. correct it and run the program again";
			else
				cout << "the score number " << n - 1 << "doesnt satisfy the requirements. correct it and run the program again";

			return -1;
		}//this is overthinking but it will be important if we will use this program for the actual users. there was an error calculating it wrongly but this if statement finally fixes it. if there is a question about it I will be happy to explain.
		sum += a;//adds a to the sum during every loop so to get the total sum
	} while (score.get(c));
	score.close();//closed the file. I will open it again
	double mean = sum / n;//finally, we calculate the average 

	//right now, since we know the average, we run the while loop one more time to determine which is greater and chich is not.
	int below = 0, above = 0;//below will be the scores that is less or equal to the average. above will be the number of the scores, greater than the mean.
	score.open("C:\\Users\\acer\\Desktop\\scores.txt");//opened again
	do {
		score >> a;//gets the value of a for the line.
		if (a <= mean)
			below++;
		else
			above++;

	} while (score.get(c));

	cout << "Average: " << mean << endl;//outputs average
	cout << "Below average: " << below << endl;//outputs how many is less
	cout << "Above average" << above << endl;//outputs how many is more

	score.close();//closed again
	return 0;
}
