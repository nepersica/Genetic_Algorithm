#pragma once
#include "Data.h"
#include "Make_descendant.h"
#include <string>

using namespace std;

class Chromosome
{
public:
	void Make_Chromosomes();
	string Random_bit(int chro_length);
	double ExpressInRange(string chromo, Data &data);
	void Calculate_FitnessRate(Data &data);
	double bin2dec(string chromo);
	void Print(Data &data, ofstream &outfile);
};
