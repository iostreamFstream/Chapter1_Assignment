#include <iostream>
#include <string>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>
#include<numeric>
#include "input.h"
using namespace std;

//ASSIGNMENT 1
//08/20/2024
//OSCAR GALLARDO
//BRISSA HOKE
//GIOVANNI JIMENEZ

char menuOption();
void DisplayArray(vector<int>& array1);
int Findminimum(vector<int>& array1);
int Findmedian(vector<int> array1);
double FindMeanAbsoluteDeviation(vector<int> array1);
double FindSkewnessPopulation(vector<int> array1);
double FindSkewnessSample(vector<int> array1);
double FindCoefficientOfVariationPopulation(vector<int> array1);
double FindCoefficientOfVariationSample(vector<int> array1);
int findMode(vector<int> dataSet);
float midRange(vector<int> dataSet);
float rootMeanSquare(vector<int> dataSet);


int main()
{

	int size = 0;

	string file1 = "unknown";

	int choice = 0;

	fstream datafile;

	int input1 = 0;

	vector<int> data2;

	do
	{

		switch (menuOption())
		{
		case '0':
		{

			data2.clear();

			exit(0);

		}
		break;

		case '1'://for case 1 we the user will be able to choose to calculate their data inputs based
		{//////////on sample calculations or population calculations

			cout << endl;

			cout << "\n\t\tDATA SET OPTION IS CURRENTLY SET FOR SAMPLE!";

			cout << endl;
			//choice variable will hold the user input of 0 or 1. 0 will be for sample calculations
			//1 will be for population calculations
			choice = inputInteger("\n\t\tSELECT THE DATA SET OPTION (0-SAMPLE OR 1-POPULATION): ", 0, 1);

			if (choice == 0)//if choice == 0 all sample in the rest of program will be calculated
			{/////////////////based on sample based equations

				cout << endl;

				cout << "\n\t\tTHE DATA SET WILL NOW BE SET TO SAMPLE!!";

			}
			else//if choice == 0 all sample in the rest of program will be calculated
			{/////based on population based equations

				cout << endl;

				cout << "\n\t\tTHE DATA SET WILL NOW BE SET TO POPULATION!!";

			}

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case '2'://for case 2 the user will have the chance to input data into our vector object
		{//////////we will use a switch function to switch between all 3 choices

			data2.clear();

			char option1 = inputChar("\n\t\tCHOOSE AN OPTION (M) - MANUAL, (R) - RANDOM, (F) - FILE, OR (X) - RETURN: ", static_cast<string>("MRFX"));

			cout << endl;

			switch (option1)//switch function will be used to switch between all 3 choices
			{
			case 'M'://for case M the user will be able to manually input data into our vector
			{

				size = inputInteger("\n\t\tSPECIFY THE SIZE OF THE ARRAY: ", 3, 200);//user will choose size data array

				for (int i = 0; i < size; i++)
				{
					cout << "\n\t\tPLEASE ENTER INTEGER " << i + 1 << ": ";

					input1 = inputInteger("", 1, 100);

					data2.push_back(input1);


				}

				sort(data2.begin(), data2.end());

				cout << "\n\t\tDATA SET CONTAINS " << size << " DATA POINT(S)!";
				cout << endl;

				DisplayArray(data2);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'R':
			{

				srand(time(0));

				size = inputInteger("\n\t\tSPECIFY THE SIZE OF THE ARRAY: ", 3, 200);

				for (int i = 0; i < size; i++)
				{

					input1 = rand() % 100 + 1;

					data2.push_back(input1);

				}

				sort(data2.begin(), data2.end());

				cout << "\n\t\tDATA SET CONTAINS " << size << " DATA POINT(S)!";
				cout << endl;

				DisplayArray(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'F':
			{

				cout << endl;

				file1 = inputString("\n\t\tENTER THE NAME OF THE FILE FOR ANALYSIS: ", true);

				datafile.open(file1, ios::in);

				if (datafile.fail())
				{

					cout << "\n\t\tSORRY THIS FILE DOES NOT EXIST!! TRY AGAIN!!";

					cout << endl;
					cout << endl;

					system("pause");

					break;

				}

				while (!datafile.eof())
				{

					datafile >> input1;

					data2.push_back(input1);


				}

				sort(data2.begin(), data2.end());

				cout << "\n\t\tDATA SET CONTAINS " << data2.size() << " DATA POINT(S)!";
				cout << endl;

				DisplayArray(data2);

				datafile.close();

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'X':
			{

				cout << endl;

				system("pause");

				break;

			}
			break;


			}



		}
		break;

		case 'A'://for case A we will calculate the minimum integer of our integer data set
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << endl;

			cout << "\n\t\tMINUMUM: " << Findminimum(data2);

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'B':////IN CASE B WE WILL CALCULATE THE MAXIMUM NUMBER IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			//data is sorted so we can just take the last element in the array using the back() method.
			cout << "\n\t\tMAXIMUM: " << data2.back();

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'C'://IN CASE C WE WILL CALCULATE THE RANGE FOUND IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////BRISSA PUT YOUR CODE HERE FOR RANGE --- SAMPLE AND POPULATION CALCULATIONS ARE THE SAME



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'D'://for case D we will calculate the size of our integer data set
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << endl;
			//size function will be called and we will output the result
			cout << "\n\t\tSIZE: " << data2.size() << " DATA INTEGERS";

			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'E'://IN CASE E WE WILL CALCULATE THE SUM OF THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			//We can use the accumulate function from the numeric header
			//be sure to #include<numeric> 
			cout << "\n\t\tSUM: " << accumulate(data2.begin(), data2.end(), 0);


			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'F'://IN CASE F WE WILL CALCULATE THE MEAN OF THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////BRISSA PUT YOUR CODE HERE FOR MEAN ---
			////THE WEBSITE SHOWS 2 DIFFERENT CALCULATIONS FOR MEAN FOR SAMPLE AND POPULATION BUT THEY BOTH
			///GIVE THE SAME ANSWER SO YOU DON'T NEED TO DO 2 DIFFERENT FUNCTIONS


			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'G':
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << endl;

			cout << "\n\t\tMEDIAN: " << Findmedian(data2);

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'H'://IN CASE H WE WILL CALCULATE THE MODE OF THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << "\n\t\tMODE: " << findMode(data2);

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'I'://FOR CASE I WE WILL CALCULATE THE STANDARD DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////BRISSA PUT YOUR CODE HERE FOR STANDARD DEVIATION
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'J'://IN CASE J WE WILL CALCULATE THE VARIANCE OF THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////GIOVANNI PUT YOUR CODE HERE FOR VARIANCE
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'K'://FOR CASE K WE WILL CALCULATE THE MID RANGE FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			cout << "\n\t\tMID RANGE: " << midRange(data2);


			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'L'://FOR CASE L WE WILL CALCULATE THE QUARTILE FOR THE INTEGERS IN OUR DATA ARRAY///
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////BRISSA PUT YOUR CODE HERE FOR QUARTILE --- SAMPLE AND POPULATION CALCULATIONS ARE THE SAME


			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'M'://FOR CASE M WE WILL CALCULATE THE INTERQUARTILE RANGE FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////GIOVANNI PUT YOUR CODE HERE FOR INTERQUARTILE RANGE --- SAMPLE AND POPULATION CALCULATIONS ARE THE SAME


			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'N'://FOR CASE N WE WILL CALCULATE THE OUTLIERS FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////GIOBANNI PUT YOUR CODE HERE FOR OUTLIERS --- SAMPLE AND POPULATION CALCULATIONS ARE THE SAME


			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'O'://FOR CASE O WE WILL CALCULATE THE SUM OF SQUARES FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////BRISSA PUT YOUR CODE HERE FOR SUM OF SQUARES
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;


		case 'P'://FOR CASE P WE WILL CALCULATE THE MEAN ABSOLUTE DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << "\n\t\tMEAN ABSOLUTE DEVIATION: " << FindMeanAbsoluteDeviation(data2);

			cout << endl;
			cout << endl;

			system("pause");


		}
		break;


		case 'Q'://FOR CASE Q WE WILL CALCULATE THE ROOT MEAN SQUARE FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			cout << "\n\t\tRoot Mean Square: " << rootMeanSquare(data2);

			cout << endl;
			cout << endl;

			system("pause");

		}
		break;


		case 'R'://FOR CASE R WE WILL CALCULATE THE STD ERROR OF THE MEAN FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////BRISSA PUT YOUR CODE HERE FOR STD ERROR OF THE MEAN
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");

		}
		break;


		case 'S'://FOR CASE S WE WILL CALCULATE THE SKEWNESS FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////****THIS ONE IS FOR ME I'LL FINISH IT SOON



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;


		case 'T'://FOR CASE T WE WILL CALCULATE THE KURTOSIS FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////GIOVANNI PUT YOUR CODE HERE FOR KURTOSIS
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'U'://FOR CASE U WE WILL CALCULATE THE KURTOSIS EXCESS FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////BRISSA PUT YOUR CODE HERE FOR KURTOSIS EXCESS
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");

		}
		break;


		case 'V'://FOR CASE V WE WILL CALCULATE THE COEFFICIENT OF VARIATION FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////****THIS ONE IS FOR ME I'LL FINISH IT SOON



			cout << endl;
			cout << endl;

			system("pause");

		}
		break;

		case 'W'://FOR CASE W WE WILL CALCULATE THE RELATIVE STANDARD DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////BRISSA PUT YOUR CODE HERE FOR RELATIVE STD DEVIATION
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case 'X'://FOR CASE X WE WILL CALCULATE THE FREQUENCIES FOR THE INTEGERS IN OUR DATA ARRAY
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}

			if (choice == 1)
			{

				///put population calculation here

			}
			else
			{

				//put sample calculation here



			}


			////GIOVANNI PUT YOUR CODE HERE FOR FREQUENCIES
			////2 DIFFERENT FUNCTIONS NEEDED FOR SAMPLE AND POPULATION



			cout << endl;
			cout << endl;

			system("pause");


		}
		break;

		case '3':
		{

			if (data2.empty())
			{

				cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!!";

				cout << endl;
				cout << endl;

				system("pause");

				break;

			}


			////BRISSA PUT YOUR CODE HERE FOR CASE 3




			cout << endl;
			cout << endl;

			system("pause");


		}
		break;


		}


	} while (true);

	return EXIT_SUCCESS;

	system("pause");

}

//Precondition: none
//Postcondition: Char menuOption() has been created to display our program
//Once we run program menu will appear
char menuOption()
{

	system("cls");

	cout << "\n\tDESCRIPTIVE STATISTICS ARE BRIEF DESCRIPTIVE COEFFICIENTS THAT SUMMARIZE A GIVEN DATA SET,";
	cout << "\n\tWHICH CAN BE EITHER A REPRESENTATION OF THE ENTIRE POPULATION OR A SAMPLE OF A POPULATION.";
	cout << "\n\tDESCRIPTIVE STATISTICS ARE BROKEN DOWN INTO MEASURES OF CENTRAL TENDENCY AND MEASURE OF";
	cout << "\n\tVARIABILITY(SPREAD). MEASURES OF CENTRAL TENDENCY INCLUDE THE MEAN, THE MEDIAN, AND MODE. WHILE";
	cout << "\n\tMEASURES OF VARIABILITY INCLUDE STANDARD DEVIATION, VARIANCE, MINIMUM, AND MAXIMUM VARIABLES,";
	cout << "\n\tKURTOSIS, AND SKEWNESS";

	cout << "\n";
	cout << "\n";

	cout << "\n\tCMPR131 - CHAPTER 1: DESCRIPTIVE STATISTICS - BY - OSCAR GALLARDO - BRISSA HOKE - GIOVANNI JIMENEZ - (08/20/2024)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> SELECT DATA SET OPTION";
	cout << "\n\t\t2> SELECT DATA INPUT OPTION, STORE DATA INTO A SORTED ARRAY AND DISPLAY THE DATA SET";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> MINIMUM                                        M> INTERQUARTILE RANGE";
	cout << "\n\t\tB> MAXIMUM                                        N> OUTLIER";
	cout << "\n\t\tC> RANGE                                          O> SUM OF SQUARES";
	cout << "\n\t\tD> SIZE                                           P> MEAN ABSOLUTE DEVIATION";
	cout << "\n\t\tE> SUM                                            Q> ROOT MEAN SQUARE";
	cout << "\n\t\tF> MEAN                                           R> STD ERROR OF THE MEAN";
	cout << "\n\t\tG> MEDIAN                                         S> SKEWNESS";
	cout << "\n\t\tH> MODE                                           T> KURTOSIS";
	cout << "\n\t\tI> STANDARD DEVIATION                             U> KURTOSIS EXCESS";
	cout << "\n\t\tJ> VARIANCE                                       V> COEFFICIENT OF VARIATION";
	cout << "\n\t\tK> MID RANGE                                      W> RELATIVE STANDARD DEVIATION";
	cout << "\n\t\tL> QUARTILE                                       X> FREQUENCIES";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t3> DISPLAY ALL RESULTS(OPTION A....X) AND WRITE OUT TO A TEXTFILE";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> EXIT";
	cout << "\n\t" << string(100, char(205));


	return inputChar("\n\t\tOPTION: ", static_cast<string>("0123ABCDEFGHIJKLMNOPQRSTUVWX"));

	system("pause");

}

//Precondition: We will input vector object into this function
//Postcondition: After running program DisplayArray function should display all data in our vector
void DisplayArray(vector<int>& array1)
{

	cout << "\t\t[  ";

	for(int i = 0; i < array1.size(); i++)//we will use for loop to loop through all data in our vector
	{

		cout << array1[i];//using cout we will output all data in vector
		cout << ", ";

	}

	cout << " ]";

}

//Precondition: We will input vector object into this function
//Postcondition: After running this function the function will find and return the smallest integer in our data set
int Findminimum(vector<int>& array1)
{

	int minNumber;

	minNumber = array1[0];

	for (int i = 1; i < array1.size(); i++)
	{

		if (array1[i] < minNumber)
		{

			minNumber = array1[i];

		}

	}

	return minNumber;

}

//Precondition: We will input vector object into this function
//Postcondition: After this function the function will return the median number in our integer data set
int Findmedian(vector<int> array1)
{

	int median = 0;

	int input1 = 0;

	int input2 = 0;

	if (array1.size() % 2 != 0)
	{

		input1 = (array1.size() / 2);

		median = array1[input1];

		return median;

	}
	else
	{

		input1 = (array1.size() - 1) / (2);

		input2 = array1.size() / 2;

		median = ((array1[input1] + array1[input2]) / (2));

		return median;

	}

}

//Precondition: We will input vector object into this function
//Postcondition: 
double FindMeanAbsoluteDeviation(vector<int> array1)
{

	int calculate = 0;

	int count = 0;

	int absCount = 0;

	double MAD = 0.00;

	int sum = accumulate(array1.begin(), array1.end(), 0);

	double mean = sum / (array1.size());

	for (int i = 0; i < array1.size(); i++)
	{

		calculate = array1[i] - mean;

		count += calculate;

	}

	absCount = abs(count);

	MAD = absCount / array1.size();

	return MAD;

}

//Precondition: We will input vector object into this function
//
double FindSkewnessPopulation(vector<int> array1)
{



}

//Precondition: We will input vector object into this function
//
double FindSkewnessSample(vector<int> array1)
{




}

//Precondition: We will input vector object into this function
//
double FindCoefficientOfVariationPopulation(vector<int> array1)
{




}

//Precondition: We will input vector object into this function
//
double FindCoefficientOfVariationSample(vector<int> array1)
{




}

int findMode(vector<int> dataSet)
{
	unordered_map<int, int> hash;
	for (int i = 0; i < dataSet.size(); i++)
		hash[dataSet[i]]++;

	int max_count = 0, res = -1;
	for (auto i : hash)
	{
		if (max_count < i.second)
		{
			res = i.first;
			max_count = i.second;
		}
	}

	return res;
}

float midRange(vector<int> dataSet)
{
	float midRange = (static_cast<float>(dataSet[0]) + static_cast<float>(dataSet.back())) / 2;
	return midRange;
}

float rootMeanSquare(vector<int> dataSet)
{
	int square = 0;
	float mean = 0.0, root = 0.0;

	for (int i = 0; i < dataSet.size(); i++)
		square += pow(dataSet[i], 2);

	mean = (square / (float)(dataSet.size()));

	root = sqrt(mean);

	return root;
}