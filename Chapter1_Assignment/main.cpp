#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>
#include <numeric>
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
double Findmedian(vector<int> array1);
double FindMeanAbsoluteDeviation(vector<int> array1);
double FindSkewness(vector<int> array1, bool isPop);
double FindCoefficientOfVariation(vector<int> array1, bool isPop);
string findMode(vector<int> dataSet);
double midRange(vector<int> dataSet);
double rootMeanSquare(vector<int> dataSet);
string frequencyOfDataSet(vector<int> dataSet);
double findKurtosis(vector<int> dataSet, bool isPop);
double variance(vector<int> dataSet, bool isPop);
int findRange(vector<int> dataSet);
double findMean(vector<int> dataSet);
double findStandardDeviation(vector<int> dataSet, bool isPop);
double* findQuartiles(vector<int> dataSet);
double findSumOfSquares(vector<int> dataSet);
double findSTDErrorOfMean(vector<int> dataSet, bool isPop);
double findKurtosisExcess(vector<int> dataSet, bool isPop);
double findRelativeSTDDeviation(vector<int> dataSet, bool isPop);
void displayData(vector<int> dataSet, bool isPop);
void printDataToFile(vector<int> dataSet, bool isPop);
double findIQR(vector<int> dataSet);
vector<int> findOutliers(vector<int> dataSet);


int main()
{

	//
	int size = 0;

	//
	string file1 = "unknown";

	//
	int choice = 0;

	//
	fstream datafile;

	//
	int input1 = 0;

	//
	vector<int> data2;

	do
	{

		char menuChoice = menuOption();
		switch (menuChoice)
		{
		case '0'://
		{
			//
			data2.clear();

			//
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

			//
			data2.clear();

			//
			char option1 = inputChar("\n\t\tCHOOSE AN OPTION (M) - MANUAL, (R) - RANDOM, (F) - FILE, OR (X) - RETURN: ", static_cast<string>("MRFX"));

			cout << endl;

			switch (option1)//switch function will be used to switch between all 3 choices
			{
			case 'M'://for case M the user will be able to manually input data into our vector
			{

				//
				size = inputInteger("\n\t\tSPECIFY THE SIZE OF THE ARRAY: ", 3, 200);//user will choose size data array

				//
				for (int i = 0; i < size; i++)
				{
					cout << "\n\t\tPLEASE ENTER INTEGER " << i + 1 << ": ";

					//
					input1 = inputInteger("", 1, 100);

					//
					data2.push_back(input1);


				}

				//
				sort(data2.begin(), data2.end());

				//
				cout << "\n\t\tDATA SET CONTAINS " << size << " DATA POINT(S)!";
				cout << endl;

				//
				DisplayArray(data2);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'R'://
			{
				//
				srand(time(0));

				//
				size = inputInteger("\n\t\tSPECIFY THE SIZE OF THE ARRAY: ", 3, 200);

				//
				for (int i = 0; i < size; i++)
				{
					//
					input1 = rand() % 100 + 1;

					//
					data2.push_back(input1);

				}

				//
				sort(data2.begin(), data2.end());

				//
				cout << "\n\t\tDATA SET CONTAINS " << size << " DATA POINT(S)!";
				cout << endl;

				//
				DisplayArray(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'F'://
			{

				cout << endl;

				//
				file1 = inputString("\n\t\tENTER THE NAME OF THE FILE FOR ANALYSIS: ", true);

				//
				datafile.open(file1, ios::in);

				//
				if (datafile.fail())
				{

					cout << "\n\t\tSORRY THIS FILE DOES NOT EXIST!! TRY AGAIN!!";

					cout << endl;
					cout << endl;

					system("pause");

					break;

				}

				while (!datafile.eof())//
				{
					//
					datafile >> input1;

					//
					data2.push_back(input1);

				}

				//
				sort(data2.begin(), data2.end());

				//
				cout << "\n\t\tDATA SET CONTAINS " << data2.size() << " DATA POINT(S)!";
				cout << endl;

				//
				DisplayArray(data2);

				//
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

		default :

		//if the data set is empty when the user attempts to make calculations
		if (data2.empty())
		{
			//if data set is empty we will call out an error so that the user can return to main menu in order to add data to our vector
			cout << "\n\t\tSORRY NO DATA HAS BEEN INPUTTED TO ANALYZE, GO TO OPTION 2 AND TRY AGAIN!";

			cout << endl;
			cout << endl;

			system("pause");


		}
		else

			switch(menuChoice)
			{
			case 'A'://for case A we will calculate the minimum integer of our integer data set
			{
				
				cout << endl;

				//we will call our Findminimum function and output the results
				cout << "\n\t\tMINUMUM: " << Findminimum(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'B':////IN CASE B WE WILL CALCULATE THE MAXIMUM NUMBER IN OUR DATA ARRAY
			{

				//data is sorted so we can just take the last element in the array using the back() method.
				cout << "\n\t\tMAXIMUM: " << data2.back();

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'C'://IN CASE C WE WILL CALCULATE THE RANGE FOUND IN OUR DATA ARRAY
			{

				cout << "\n\t\tRange : " << findRange(data2);



				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'D'://for case D we will calculate the size of our integer data set
			{

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

				cout << "\n\t\tMean : " << findMean(data2);


				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'G'://for case G we will calculate the median of our data set
			{

				cout << endl;

				//we will call the Findmedian function and output our results
				cout << "\n\t\tMEDIAN: " << Findmedian(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'H'://IN CASE H WE WILL CALCULATE THE MODE OF THE INTEGERS IN OUR DATA ARRAY
			{

				cout << endl;

				cout << findMode(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'I'://FOR CASE I WE WILL CALCULATE THE STANDARD DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
			{


				cout << "\n\t\tStandard Deviation : " << findStandardDeviation(data2, choice);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'J'://IN CASE J WE WILL CALCULATE THE VARIANCE OF THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tVariance of Sample: " << variance(data2, choice);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'K'://FOR CASE K WE WILL CALCULATE THE MID RANGE FOR THE INTEGERS IN OUR DATA ARRAY
			{


				cout << "\n\t\tMID RANGE: " << midRange(data2);


				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'L'://FOR CASE L WE WILL CALCULATE THE QUARTILE FOR THE INTEGERS IN OUR DATA ARRAY///
			{

				cout << "\n\t\tQuartiles : ";
				double* quartPtr = findQuartiles(data2);

				//if the function returns as NULL, this will be displayed as Unknown
				if (quartPtr[0] == NULL)
					cout << "Unknown";
				else
				{
					double quartiles[3] = {NULL};
					for (int i = 0; i < 3; i++)
						quartiles[i] = *(quartPtr + i);
			
					for (int i = 0; i < 3; i++)
					{

						cout << quartiles[i];
						if (i != 2)
							cout << ", ";
					}

				}

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'M'://FOR CASE M WE WILL CALCULATE THE INTERQUARTILE RANGE FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tINTERQUARTILE RANGE: " << findIQR(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'N'://FOR CASE N WE WILL CALCULATE THE OUTLIERS FOR THE INTEGERS IN OUR DATA ARRAY
			{


				//
				vector<int> outliers = findOutliers(data2);

				if (outliers.size() == 0)
				{
					cout << "\n\t\tUNKOWN";
					cout << endl;
					cout << endl;
					system("pause");
					break;
				}

				string allOutliers = "[";

				for (auto it : outliers)
				{
					allOutliers += " " + to_string(it) + ",";
				}
				allOutliers += "]";
				cout << "\n\t\tOUTLIERS: " << allOutliers;

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'O'://FOR CASE O WE WILL CALCULATE THE SUM OF SQUARES FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tSum of Squares : " << findSumOfSquares(data2);


				cout << endl;
				cout << endl;

				system("pause");


			}
			break;


			case 'P'://FOR CASE P WE WILL CALCULATE THE MEAN ABSOLUTE DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tMEAN ABSOLUTE DEVIATION: " << FindMeanAbsoluteDeviation(data2);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;


			case 'Q'://FOR CASE Q WE WILL CALCULATE THE ROOT MEAN SQUARE FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tRoot Mean Square: " << rootMeanSquare(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;


			case 'R'://FOR CASE R WE WILL CALCULATE THE STD ERROR OF THE MEAN FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tStandard Error of the Mean : " << findSTDErrorOfMean(data2, choice);



				cout << endl;
				cout << endl;

				system("pause");

			}
			break;


			case 'S'://FOR CASE S WE WILL CALCULATE THE SKEWNESS FOR THE INTEGERS IN OUR DATA ARRAY
			{

				

				//we will call the FindSkewnessPopulation function and output the result
				cout << "\n\t\tSKEWNESS: " << FindSkewness(data2, choice);


				cout << endl;
				cout << endl;

				system("pause");


			}
			break;


			case 'T'://FOR CASE T WE WILL CALCULATE THE KURTOSIS FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tKurtosis: " << findKurtosis(data2, choice);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'U'://FOR CASE U WE WILL CALCULATE THE KURTOSIS EXCESS FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tKurtosis Excess : ";
				double kurtExcess = findKurtosisExcess(data2, choice);
				

				if (kurtExcess == -1.0)
					cout << "Unknown";
				else
					cout << kurtExcess;


				cout << endl;
				cout << endl;

				system("pause");

			}
			break;


			case 'V'://FOR CASE V WE WILL CALCULATE THE COEFFICIENT OF VARIATION FOR THE INTEGERS IN OUR DATA ARRAY
			{

				

				//we will call the FindSCoefficientOFVariationSample function and output the result
				cout << "\n\t\tCOEFFICIENT OF VARIATION: " << FindCoefficientOfVariation(data2, choice);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case 'W'://FOR CASE W WE WILL CALCULATE THE RELATIVE STANDARD DEVIATION FOR THE INTEGERS IN OUR DATA ARRAY
			{

				cout << "\n\t\tRelative Standard Deviation : " << findRelativeSTDDeviation(data2, choice);

				cout << endl;
				cout << endl;

				system("pause");


			}
			break;

			case 'X'://FOR CASE X WE WILL CALCULATE THE FREQUENCIES FOR THE INTEGERS IN OUR DATA ARRAY
			{
			
				//
				cout << frequencyOfDataSet(data2);

				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			case '3'://for case 3 we will ouput all calculations to a text file
			{

				displayData(data2, choice);
				printDataToFile(data2, choice);


				cout << endl;
				cout << endl;

				system("pause");

			}
			break;

			}
		}

	} while (true);

	return EXIT_SUCCESS;

	system("pause");

}

//Precondition: none
//Postcondition: Char menuOption() has been created to display our program
//Once we run program this menu will appear
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

	int minNumber;//minNumber variable will hold the smallest number in our data set

	minNumber = array1[0];//we will set minNumber equal to the first integer in our data set

	for (int i = 1; i < array1.size(); i++)//we will use the for loop to loop through all integers in our data set
	{

		if (array1[i] < minNumber)//if statement will be used to compare all integers in order to find the smallest integer
		{

			minNumber = array1[i];//once smallest integer is found we will set it equal to minNumber

		}

	}

	return minNumber;//we will return minNumber

}

//Precondition: We will input vector object into this function
//Postcondition: After this function the function will return the median number in our integer data set
double Findmedian(vector<int> array1)
{

	double median = 0.00;//variable median will hold the median of our data set

	double index1 = 0.00;//variable index1 will hold the index of our data with an odd number of integers

	double index2 = 0.00;//variable index2 will hold the index of our data with an even number of integers

	if (array1.size() % 2 != 0)//if our data set has an odd number of integers then this will calculation will be called
	{

		index1 = (array1.size() / 2.00);//we will divide the size of our data set by 2

		median = array1[index1];//we will find the integer at index1

		return median;//we will return median

	}
	else//if our data set has even number of integers then this calculation will be called
	{

		index1 = ((array1.size()) / (2.00)) - 1;//we will divide the size of our data set minus 1 by 2

		index2 = array1.size() / 2.00;//we will divide the size of our data set by 2

		median = ((array1[index1] + array1[index2]) / (2.00));//we will add the integer located at index1 with index2 and divide the sum by 2

		return median;//we will return median

	}

}

//Precondition: We will input vector object into this function
//Postcondition: After calling this function the function will return the mean absolute deviation of the integers in our data set
double FindMeanAbsoluteDeviation(vector<int> array1)
{

	double calculate = 0.00;//variable calculate will hold the absolute value of all integers in our data subtracted by the mean

	double count = 0.00;//variable count will hold the sum of the absolute value of all integers in our data subtracted by the mean

	double MAD = 0.00;//variable MAD will hold the mean absolute deviation of our data set

	double sum = accumulate(array1.begin(), array1.end(), 0);//we will calculate the sum of all the integers in our data set

	//mean will calculate the mean of our data set by dividing sum by the size of our array
	double mean = sum / (array1.size());

	for (int i = 0; i < array1.size(); i++)//using this for loop we will loop through all of the integers in our data set
	{

		calculate = abs(array1[i] - mean);//we will take the absolute value of the integers in our data set subtracted by the mean

		count += calculate;//we will add all the results from our variable calculate

	}

	//we will divide count by the size of our array in order to get the mean absolute deviation
	MAD = count / array1.size();

	//we will return the mean absolute deviation
	return MAD;

}


//Precondition: We will input vector object into this function
//Postcondition: After calling out this function our program will return the skewness of our data set based on sample calculation
double FindSkewness(vector<int> array1, bool isPop)
{

	double sum1 = 0.00;//sum1 variable will hold the sum of all integers of our data set subtracted by the mean of our data set

	double calculate = 0.00;///calculate variable will hold subtraction of the integers in our data set by the mean of our data set and divided by the standard deviation

	double calculate3 = (array1.size() - 1) * (array1.size() - 2);//calculate variable will hold subtraction of the integers in our data set

	double skewness1 = 0.00;//variable skewness will hold the skewness of our data set

	double std1 = findStandardDeviation(array1, isPop);//we will calculation the standard deviation

	double std2 = pow(findStandardDeviation(array1, isPop), 3);//

	double sum2 = accumulate(array1.begin(), array1.end(), 0);//we will calculate the sum of the integers in our data set

	if(isPop)
	{
		
		for (int i = 0; i < array1.size(); i++)//for loop will loop through all of the integers in our data set
		{

			calculate = pow((array1[i] - findMean(array1)), 3);//we will subtract the integers of our data set by the mean and raise it to power of 3

			sum1 += calculate;//we will add all numbers calculated from our calculate variable

		}

		skewness1 = (sum1) / (array1.size() * std2);//we will calculate skewmess of the population calculation

		return skewness1;//we will return skewness
	
	}
	else
	{
		
		for (int i = 0; i < array1.size(); i++)//for loop will loop through all of the integers in our data set
		{

			calculate = pow(((array1[i] - findMean(array1)) / (std1)), 3);//we will subtract the integers of our data set by the mean, we will divide this value by the standard deviation and raise it to power of 3

			sum1 += calculate;//we will add all numbers calculated from our calculate variable

		}

		skewness1 = (array1.size() / calculate3) * (sum1);//we will calculate skewness of the sample calculation

		return skewness1;//we will return skewness
	
	}

}


//Precondition: We will input vector object into this function
//Postcondition: After calling out this function our program will return the coefficient of variation of our data set
//////////////// based on sample calculation
double FindCoefficientOfVariation(vector<int> array1, bool isPop)
{

	double cv1 = 0.00;//

	double sum1 = accumulate(array1.begin(), array1.end(), 0);//

	double mean = sum1 / (findMean(array1));//

	cv1 = findStandardDeviation(array1, isPop) / findMean(array1);//

	return cv1;//

}

//Precondition: vector<int>
//Postcondition: returns the number in the data set that occurs most frequently
string findMode(vector<int> dataSet)
{

	int mode1 = dataSet[0];

	int num1 = dataSet[0];

	int frequency1 = 0;

	int count1 = 1;

	string noMode;

	string mode;

	int dataInt = 0;

	for(int i = 1; i < dataSet.size(); i++)
	{
	
		if(num1 == dataSet[i])
		{
			
			frequency1++;
		
		}
		else
		{
			
			if(frequency1 > count1)
			{
				
				count1 = frequency1;
				mode1 = num1;
			
			}

			frequency1 = 1;

			num1 = dataSet[i];
		
		}
	
	}

	if(count1 > 1)
	{
		
		mode = "\n\t\tMODE: " + to_string(mode1);

		return mode;
	
	}
	else
	{
		
		cout << "\t\tMODE:   ";

		for (int i = 0; i < dataSet.size(); i++)//we will use for loop to loop through all data in our vector
		{

			dataInt = dataSet[i];

			noMode += to_string(dataInt) + " ";//using cout we will output all data in vector

		}

		return noMode;
	
	}

}

//Precondition vector<int>
//Postcondition: Returns the mid range of the data set.
double midRange(vector<int> dataSet)
{
	float midRange = (static_cast<float>(dataSet[0]) + static_cast<float>(dataSet.back())) / 2;
	return midRange;
}

//Precondition: vector<int>
//Postcondition: returns the Root Mean Square of the dataset.
double rootMeanSquare(vector<int> dataSet)
{
	int square = 0;
	float mean = 0.0, root = 0.0;

	for (int i = 0; i < dataSet.size(); i++)
		square += pow(dataSet[i], 2);

	mean = (square / (float)(dataSet.size()));

	root = sqrt(mean);

	return root;
}

//Precondition: Vector<int>
//Postcondition: returns the variance of a SAMPLE data set.
double variance(vector<int> dataSet, bool isPop)
{
	double sum = accumulate(dataSet.begin(), dataSet.end(), 0.0);
	double mean = sum / dataSet.size();
	double sqDifference = 0.0;

	if(isPop)
	{
	
		for (int i = 0; i < dataSet.size(); i++)
			sqDifference += pow(dataSet[i] - findMean(dataSet), 2);

		return sqDifference / dataSet.size();
	
	}
	else
	{
	
		for (int i = 0; i < dataSet.size(); i++)
			sqDifference += pow(dataSet[i] - findMean(dataSet), 2);

		return sqDifference / (dataSet.size() - 1);
	
	}


	for(int i = 0; i < dataSet.size(); i++)
		sqDifference += pow(dataSet[i] - mean,2);

		return sqDifference / (dataSet.size() - 1);
	
}


//Precondition: Vector<int>
//Postcondition: Displays a frequency table of every index in the data set.
string frequencyOfDataSet(vector<int> dataSet)
{
	map<int, int> frequencyMap;

	for (int i = 0; i < dataSet.size(); i++)
		frequencyMap[dataSet[i]]++;

	string strFrequency = "\n\n\t\tFrequency Table: \n";
	strFrequency += "\t\tVALUE: \t\tFREQUENCY:\t\tFREQUENCY %:\n";
	strFrequency += "\t\t" + string(60, '=') + "\n";

	for (auto& i : frequencyMap)
	{
		strFrequency += "\t\t" + to_string(i.first) + " \t\t\t " + to_string(i.second) + " \t\t\t" + to_string(static_cast<float>(i.second) / static_cast<float>(dataSet.size()) * 100) + "%\n";
	}

	return strFrequency;
}


//Precondition: Vector<int>
//Postcondition: Returns the Kurtosis of a SAMPLE data set.
double findKurtosis(vector<int> dataSet, bool isPop)
{
	double kurtosis = 0.0;

	double sum1 = 0.00;

	double sum2 = accumulate(dataSet.begin(), dataSet.end(), 0);

	double calculate1 = 0.00;

	double calculate2 = (dataSet.size()) * (dataSet.size() + 1);

	double calculate3 = (dataSet.size() - 1) * (dataSet.size() - 2) * (dataSet.size() - 3);

	double calculateFinal = calculate2 / calculate3;

	double std1 = pow(findStandardDeviation(dataSet, isPop), 4);

	double std2 = findStandardDeviation(dataSet, isPop);

	if(isPop)
	{
		
		for(int i = 0; i < dataSet.size(); i++)
		{
			
			calculate1 = pow((dataSet[i] - findMean(dataSet)), 4);
		
			sum1 += calculate1;
		
		}

		kurtosis = (sum1) / (dataSet.size() * std1);

		return kurtosis;
	
	}
	else
	{
		
		for (int i = 0; i < dataSet.size(); i++)
		{

			calculate1 = pow(((dataSet[i] - findMean(dataSet)) / (std2)), 4);

			sum1 += calculate1;

		}

		kurtosis = (sum1) * calculateFinal;

		return kurtosis;
	
	}

}

//IQR:PROTOTYPE:
//
//
double findIQR(vector<int> dataSet)
{

	//Calcuation is Quartile 3 minus Quartile 1
	double* Ptr1 = findQuartiles(dataSet);

	//if the function returns as NULL, this will be displayed as Unknown
	if (Ptr1[0] == NULL)
		cout << "Unknown";
	else
	{
		double quartiles[3] = { NULL };
		for (int i = 0; i < 3; i++)
			quartiles[i] = *(Ptr1 + i);

		return quartiles[2] - quartiles[0];

	}

}


//Precondition: vector<int>
//Postcondition: returns a vector containing all the outliers in the dataSet
vector<int> findOutliers(vector<int> dataSet)
{
	vector<int> outliers;
	if (dataSet.size() < 4)
		return outliers;

	double IQR = findIQR(dataSet);

	double* quartiles = findQuartiles(dataSet);

	double upperLimit = quartiles[2] + 1.5 * IQR;

	double lowerLimit = quartiles[0] - 1.5 * IQR;

	for (auto it : dataSet)
	{
		if (it > upperLimit || it < lowerLimit)
			outliers.push_back(it);
	}

	return outliers;
}



//pre: data set is needed
//post: returns the range of the data set
int findRange(vector<int> dataSet)
{
	return dataSet.back() - dataSet.front();
}

//pre: data set is needed
//post: returns the mean of the data set
double findMean(vector<int> dataSet)
{
	double sum = accumulate(dataSet.begin(), dataSet.end(), 0.0);

	return sum / static_cast<double>(dataSet.size());
}

//pre: data set is needed and if it is sample or population
//post: returns the standard deviation of the data set based on wether it is sample or population
double findStandardDeviation(vector<int> dataSet, bool isPop)
{
	double sum = 0.0;
	double size = static_cast<double>(dataSet.size());

	for (int i = 0; i < dataSet.size(); i++)
		sum += pow(static_cast<double>(dataSet[i]) - findMean(dataSet), 2.0);
	if (isPop) // equation for population option
		sum /= size;

	else // equation for sample option
		sum /= (size - 1.0);

	double answer = sqrt(sum);

	return answer;
}

//pre: : needs the data set
//post: returns a pointer to a sized 3 array containing the data set's quartiles or a "NULL" if the data set is size 3 or less
double* findQuartiles(vector<int> dataSet)
{

	double quartiles[3] = {NULL};

	//if the data set is less than or equal to 3, this will return the array without calculations
	if (dataSet.size() <= 3)
		return quartiles;

	vector<int> firstHalf;
	vector<int> secondHalf;
	double median = Findmedian(dataSet);

	quartiles[1] = median;
	if (dataSet.size() % 2 == 0) //if the array size is even
	{
		for (int i = 0; i < (dataSet.size() / 2); i++)
			firstHalf.push_back(dataSet[i]);

		for (int i = (dataSet.size() / 2); i < dataSet.size(); i++)
			secondHalf.push_back(dataSet[i]);

		double median2 = Findmedian(firstHalf);
		double median3 = Findmedian(secondHalf);

		quartiles[0] = median2;
		quartiles[2] = median3;

	}
	else //if the array size is odd
	{
		for (int i = 0; i < (dataSet.size() / 2); i++)
			firstHalf.push_back(dataSet[i]);

		for (int i = (dataSet.size() / 2) + 1; i < dataSet.size(); i++)
			secondHalf.push_back(dataSet[i]);

		double median2 = Findmedian(firstHalf);
		double median3 = Findmedian(secondHalf);

		quartiles[0] = median2;
		quartiles[2] = median3;

	}

	return quartiles;
}

//pre: needs the data set
//post: returns the sum of squares of the data set
double findSumOfSquares(vector<int> dataSet)
{
	double mean = findMean(dataSet);
	double sum = 0;
	for (int i = 0; i < dataSet.size(); i++)
		sum += pow(static_cast<double>(dataSet[i]) - findMean(dataSet), 2.0);

	return sum;
}

//pre: needs the data set and wether the calculations are population or sample
//post: returns the standard error of mean of the data set
double findSTDErrorOfMean(vector<int> dataSet, bool isPop)
{
	double size = static_cast<double>(dataSet.size());
	double answer = findStandardDeviation(dataSet, isPop) / sqrt(size);

	return answer;
}

//pre: needs the data set and wether the calculations are population or sample
//post: returns the kurtosis excess of the data set
double findKurtosisExcess(vector<int> dataSet, bool isPop)
{

	//if the data set is less than or equal to 3, this will return the array without calculations
	if (dataSet.size() <= 3)
		return -1.0;

	double kurtosis = 0.0;
	kurtosis = findKurtosis(dataSet, isPop);

	if (isPop)
		return kurtosis - 3;
	else
	{
		double size = static_cast<double>(dataSet.size());
		double subtract = pow(size - 1, 2) * 3;
		subtract /= (size - 2) * (size - 3);
		return kurtosis - subtract;
	}

}

//pre: needs the data set and wether the calculations are population or sample
//post: returns the relative standard deviation of the data set
double findRelativeSTDDeviation(vector<int> dataSet, bool isPop)
{
	double answer = (findStandardDeviation(dataSet, isPop) * 100) / findMean(dataSet);
	return answer;
}

//pre: needs the data set and wether the calculations are population or sample
//post: displays the data set and its subsequent calculations
void displayData(vector<int> dataSet, bool isPop)
{
	cout << "\tDescriptive statistics summarize certain aspects of a sample data set using numeric calculations.";
	cout << "\n\n\tData set contains " << dataSet.size() << " data point(s):\n";

	//displaying the data set elements
	 DisplayArray(dataSet);

	//displaying all calculations
	 cout << "\n\n\n\t\tMinimum = " << Findminimum(dataSet)
		 << "\n\n\t\tMaximum = " << dataSet.back()
		 << "\n\n\t\tRange = " << findRange(dataSet)
		 << "\n\n\t\tSize = " << dataSet.size()
		 << "\n\n\t\tSum = " << accumulate(dataSet.begin(), dataSet.end(), 0)
		<< "\n\n\t\tMean = " << findMean(dataSet)
		<< "\n\n\t\tMedian = " << Findmedian(dataSet)
		<< "\n\n\t\t" << findMode(dataSet);

	cout << "\n\n\t\tStandard Deviation = " << findStandardDeviation(dataSet, isPop)
		<< "\n\n\t\tVariance = " << variance(dataSet, isPop);

	cout << "\n\n\t\tMid Range = " << midRange(dataSet)
		<< "\n\n\t\tQuartiles = ";

	double* quartPtr = findQuartiles(dataSet);
	if (quartPtr[0] == NULL)
		cout << "Unknown";
	else
	{
		double quartiles[3] = {0.0,0.0,0.0};
		for (int i = 0; i < 3; i++)
			quartiles[i] = *(quartPtr + i);

		for (int i = 0; i < 3; i++)
		{
			cout << quartiles[i];
			if (i != 2)
				cout << ", ";
		}

	}

	cout << "\n\n\t\tInterquartile Range = " << findIQR(dataSet)
	   	<< "\t\tOutliers = ";

	vector<int> outliers = findOutliers(dataSet);

	if (outliers.size() == 0)
	{
		cout << "\t\tUNKOWN";
		cout << endl;
		cout << endl;
	
	}
	else
	{
		
		string allOutliers = "[";

		for (auto it : outliers)
		{
			allOutliers += " " + to_string(it) + ",";
		}
		allOutliers += "]";
		cout << "\t\tOUTLIERS: " << allOutliers;
	
	}

	cout << "\n\n\t\tSum of Squares = " << findSumOfSquares(dataSet)
		<< "\n\n\t\tMean Absolute Deviation = " << FindMeanAbsoluteDeviation(dataSet)
		<< "\n\n\t\tRoot Mean Square = " << rootMeanSquare(dataSet)
		<< "\n\n\t\tStd Error of Mean = " << findSTDErrorOfMean(dataSet, isPop)
		<< "\n\n\t\tSkewness = " << FindSkewness(dataSet, isPop);

	cout << "\n\n\t\tKurtosis = " << findKurtosis(dataSet, isPop);
	cout << "\n\n\t\tKurtosis Excess = " << findKurtosisExcess(dataSet, isPop)
		<< "\n\n\t\tCoefficient of Variation = " << FindCoefficientOfVariation(dataSet, isPop);
	cout << "\n\n\t\tRelative Standard Deviation = " << findRelativeSTDDeviation(dataSet, isPop) << "%"
		<< frequencyOfDataSet(dataSet);

}

//pre: takes the data set and whether it calculates based on population or sample
//post: creates an output file with the data set and its calculations
void printDataToFile(vector<int> dataSet, bool isPop)
{

	ofstream outFile;
	string fileName;

	cout << "\n\n\n\tEnter a output file name : ";
	cin >> fileName;

	outFile.open(fileName, ios::out);

	// writing the information onto the file
	outFile << "\tDescriptive statistics summarize certain aspects of a sample data set using numeric calculations.";
	outFile << "\n\n\tData set contains " << dataSet.size() << " data point(s): ";

	//displaying the data set elements
	for (int i = 0; i < dataSet.size(); i++)
	{
		outFile << dataSet[i];
		if (i != dataSet.size() - 1)
			outFile << ", ";

	}

	//displaying all calculations
	outFile << "\n\n\n\t\tMinimum = " << Findminimum(dataSet)
		<< "\n\n\t\tMaximum = " << dataSet.back()
		<< "\n\n\t\tRange = " << findRange(dataSet)
		<< "\n\n\t\tSize = " << dataSet.size()
		<< "\n\n\t\tSum = " << accumulate(dataSet.begin(), dataSet.end(), 0)
		<< "\n\n\t\tMean = " << findMean(dataSet)
		<< "\n\n\t\tMedian = " << Findmedian(dataSet)
		<< "\n\n\t\tMode = " << findMode(dataSet);

	outFile << "\n\n\t\tStandard Deviation = " << findStandardDeviation(dataSet, isPop)
		<< "\n\n\t\tVariance = " << variance(dataSet, isPop);

	outFile << "\n\n\t\tMid Range = " << midRange(dataSet)
		<< "\n\n\t\tQuartiles = ";
	double* quartPtr = findQuartiles(dataSet);
	if (quartPtr[0] == NULL)
		outFile << "Unknown";
	else
	{
		double quartiles[3] = { 0.0,0.0,0.0 };
		for (int i = 0; i < 3; i++)
			quartiles[i] = *(quartPtr + i);

		for (int i = 0; i < 3; i++)
		{
			outFile << quartiles[i];
			if (i != 2)
				outFile << ", ";
		}

	}

	outFile << "\n\n\t\tInterquartile Range = " << findIQR(dataSet)
		<< "\n\n\t\tOutliers = ";

	vector<int> outliers = findOutliers(dataSet);

	if (outliers.size() == 0)
	{
		outFile << "\n\t\tUNKOWN";
		cout << endl;
		cout << endl;

	}
	else
	{
		
		string allOutliers = "[";

		for (auto it : outliers)
		{
			allOutliers += " " + to_string(it) + ",";
		}
		allOutliers += "]";
		outFile << "\n\n\t\tOUTLIERS: " << allOutliers;
	
	}

	outFile << "\n\n\t\tSum of Squares = " << findSumOfSquares(dataSet)
		<< "\n\n\t\tMean Absolute Deviation = " << FindMeanAbsoluteDeviation(dataSet)
		<< "\n\n\t\tRoot Mean Square = " << rootMeanSquare(dataSet)
		<< "\n\n\t\tStd Error of Mean = " << findSTDErrorOfMean(dataSet, isPop)
		<< "\n\n\t\tSkewness = " << FindSkewness(dataSet, isPop);

	outFile << "\n\n\t\tKurtosis = " << findKurtosis(dataSet, isPop);
	outFile << "\n\n\t\tKurtosis Excess = " << findKurtosisExcess(dataSet, isPop)
		<< "\n\n\t\tCoefficient of Variation = " << FindCoefficientOfVariation(dataSet, isPop);
	outFile << "\n\n\t\tRelative Standard Deviation = " << findRelativeSTDDeviation(dataSet, isPop) << "%" 
		<< frequencyOfDataSet(dataSet);
	cout << endl;

	cout << "\n\t\tYOUR DATA HAS BEEN WRITTEN TO " << fileName << " DATA FILE!!";

	cout << endl;

	outFile.close();

}