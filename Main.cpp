#include <iostream>
#include <map>

float GetMean(float values[], int numValues)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float mean = 0.0f;

	float sumOfValues = 0.0f;

	// Loop through all the values and add them together
	for (int i = 0; i < numValues; ++i)
	{
		sumOfValues += values[i];
	}

	// Divide the total by the number of values to get the mean
	// Cast the number of values to a float to ensure the output is a float
	mean = sumOfValues / static_cast<float>(numValues);

	return mean;
}

float GetMedian(float values[], int numValues)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float median = 0.0f;

	// Determine if the number of values is even.
	// If it is, the median is the average of the two middle values.
	const bool isEven = numValues % 2 == 0;
	// If it is odd, the median is the middle value.
	const bool isOdd = !isEven;

	if (isEven)
	{
		// Get the two middle values
		const int rightIndex = numValues / 2; // Right index of the two middle values
		const int leftIndex = rightIndex - 1; // Left index of the two middle values

		median = (values[leftIndex] + values[rightIndex]) / 2.0f;
	}

	if (isOdd)
	{
		// Get the single middle value
		const int middleIndex = numValues / 2;

		median = values[middleIndex];
	}

	return median;
}

float GetMode(float values[], int numValues)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float mode = 0.0f;

	// Create a map to store the count of each value <value[i], count>
	std::map<float, int> occuranceMap;

	// Loop through all the values and count occurrences
	for (int i = 0; i < numValues; ++i)
	{
		occuranceMap[values[i]]++;
	}

	// Tracks the highest frequency of the values
	int highestCount = 0;
	// Loop through the map to find the value with the highest count
	for (const auto& pair : occuranceMap)
	{
		// Check if this value occurs more frequently
		if (pair.second > highestCount)
		{
			highestCount = pair.second;	// Update the max count to this value
			mode = pair.first;		// Update the mode to this value
		}
	}

	return mode;
	// This will only return the first mode found if there are multiple modes
}

float GetRange(float values[], int numValues)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float range = 0.0f;

	float min = values[0]; // Set the minimum to the first value as a starting point
	float max = values[0]; // Set the maximum to the first value as a starting point

	// Loop through all the values and check if they are the new minimum or maximum
	for (int i = 1; i < numValues; ++i)
	{
		// If the value is less than the current minimum, set it as the new minimum
		if (values[i] < min)
			min = values[i];

		// If the value is greater than the current maximum, set it as the new maximum
		if (values[i] > max)
			max = values[i];
	}

	// Calculate the range
	range = max - min;

	return range;
}

float GetVariance(float values[], int numValues, bool isSampled)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float variance = 0.0f;

	// Calculate the mean using this handy wee fella I made earlier
	const float mean = GetMean(values, numValues);

	float sumOfSquares = 0.0f;

	// Loop through all the values and add the square of the difference between the value and the mean
	for (int i = 0; i < numValues; i++)
	{
		// Calculate the difference between the value and the mean
		const float difference = values[i] - mean;

		// Add the square of the difference to the variance
		sumOfSquares += difference * difference;
	}

	// If sampled, divide by (numValues - 1), else divide by numValues
	// "Bessel's correction"
	const int denominator = isSampled ? (numValues - 1) : numValues;

	// Calculate the variance
	variance = sumOfSquares / static_cast<float>(denominator);

	return variance;
}

float GetStandardDeviation(float values[], int numValues, bool isSampled)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float standardDeviation = 0.0f;

	// Get the variance
	const float variance = GetVariance(values, numValues, isSampled);

	// Calculate the standard deviation
	standardDeviation = std::sqrt(variance);

	return standardDeviation;
}

float GetMAD(float values[], int numValues)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}

	float mad = 0.0f;

	// Get the mean
	const float mean = GetMean(values, numValues);

	// Calculate the sum of absolute deviations from the mean
	float deviationSum = 0.0f;

	// Loop through all the values and add the absolute difference between the value and the mean
	for (int i = 0; i < numValues; i++)
	{
		deviationSum += std::fabs(values[i] - mean); // Absolute difference
	}

	// Calculate the mean absolute deviation by dividing by the number of values
	mad = deviationSum / static_cast<float>(numValues);

	return mad;
}

float GetSEM(float values[], int numValues, bool isSampled)
{
	if (numValues == 0)
	{
		std::cout << "Error: Empty values array.\n";
		return 0.0f;
	}
	
	float sem = 0.0f;

	// Get the standard deviation
	const float standardDeviation = GetStandardDeviation(values, numValues, isSampled);

	// Calculate the SEM (Standard Error of the Mean)
	sem = standardDeviation / std::sqrt(static_cast<float>(numValues));

	return sem;
}

int main()
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
