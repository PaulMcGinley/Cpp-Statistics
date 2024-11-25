#include <iostream>
// INSERT includes as needed

float GetMean(float values[], int numValues)
{
	// INSERT CODE HERE
	// The mean (average) time taken to level up for that class
	return 0.0f;
}

float GetMedian(float values[], int numValues)
{
	// INSERT CODE HERE
	// The median time taken (time taken by the central sample) to level up for that class
	return 0.0f;
}

float GetMode(float values[], int numValues)
{
	// INSERT CODE HERE
	// The mode (most common amount) of time taken to level up for that class
	return 0.0f;
}

float GetRange(float values[], int numValues)
{
	// INSERT CODE HERE
	// The range (difference between shortest and longest time)
	return 0.0f;
}

float GetVariance(float values[], int numValues, bool isSampled)
{
	// INSERT CODE HERE
	// The variance (which can be used to work out the standard deviation)
	return 0.0f;
}

float GetStandardDeviation(float values[], int numValues, bool isSampled)
{
	// INSERT CODE HERE
	// The standard deviation (the distance from the mean that most samples fall within)
	return 0.0f;
}

float GetMAD(float values[], int numValues)
{
	// INSERT CODE HERE
	// The mean absolute deviation (MAD) (the average difference between a sample  and the mean)
	return 0.0f;
}

float GetSEM(float values[], int numValues, bool isSampled)
{
	// INSERT CODE HERE
	// The standard error of the mean (an estimate of how reliable the mean is, and therefore some other data here)
	return 0.0f;
}

void main()
{
	float levelTimes[] = { 24.0f, 25.0f, 26.5f, 30.0f, 31.0f, 32.0f, 32.5f, 35.0f, 37.0f, 37.0f, 38.5f, 40.0f };
	int numTimes = 12;
	bool sampled = true;

	float mean = GetMean(levelTimes, numTimes);
	float median = GetMedian(levelTimes, numTimes);
	float mode = GetMode(levelTimes, numTimes);
	float range = GetRange(levelTimes, numTimes);
	float variance = GetVariance(levelTimes, numTimes, sampled);
	float standardDeviation = GetStandardDeviation(levelTimes, numTimes, sampled);
	float mad = GetMAD(levelTimes, numTimes);
	float sem = GetSEM(levelTimes, numTimes, sampled);

	std::cout << "---- Data Set ----\n";
	std::cout << "Sample of times to complete the level:";
	for (int i = 0; i < numTimes; ++i)
	{
		if (i % 5 == 0)
			std::cout << "\n";
		std::cout << levelTimes[i] << "\t";
	}
	std::cout << "\n";
	std::cout << "Number of samples:\t" << numTimes << "\n";
	std::cout << "Is data sampled?\t" << (sampled ? "Yes" : "No") << "\n";
	std::cout << "\n";

	std::cout << "---- Statistics Calculations for Data Set ----\n";
	std::cout << "Mean:\t\t\t\t" << mean << "\n";
	std::cout << "Median:\t\t\t\t" << median << "\n";
	std::cout << "Mode:\t\t\t\t" << mode << "\n";
	std::cout << "Range:\t\t\t\t" << range << "\n";
	std::cout << "Variance:\t\t\t" << variance << "\n";
	std::cout << "Standard Deviation:\t\t" << standardDeviation << "\n";
	std::cout << "Mean Absolute Deviation:\t" << mad << "\n";
	std::cout << "Stand error of the mean:\t" << sem << "\n";
}