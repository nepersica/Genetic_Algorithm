#include "Data.h"

void Data::Set_Totalfitness(double each_fitness)
{
	Total_fitness += each_fitness;
}

double Data::get_Totalfitness()
{
	return Total_fitness;
}

int Data::Get_chroLength()
{
	return CHRO_LENGTH;
}

int Data::Get_N()
{
	return N;
}

double Data::Get_crossover_rate()
{
	return crossover_rate;
}

double Data::Get_mutation_rate()
{
	return mutation_rate;
}

void Data::add_chromo(string chromosome)
{
	chromo_Population.push_back(chromosome);
}

string Data::get_chromo(int index)
{
	return chromo_Population[index];
}

void Data::add_fitness_rate(double each_rate)
{
	fitness_rate.push_back(each_rate);
}

double Data::get_fitnessrate(int index)
{
	return fitness_rate[index];
}


void Data::Add_chromofitness(double each_fitness)
{
	chromo_fitness.push_back(each_fitness);
}

void Data::Set_chromofitness(double each_fitness, int index)
{
	chromo_fitness[index] = each_fitness;
}

double Data::get_chromofitness(int index)
{
	return chromo_fitness[index];
}

void Data::add_rangeOfchromo(double rangeOfchromo)
{
	express_rangeOfchromo.push_back(rangeOfchromo);
}

void Data::set_rangeOfchromo(double num, int index)
{
	express_rangeOfchromo[index] = num;
}

double Data::get_rangeOfchromo(int index)
{
	return express_rangeOfchromo[index];
}

double Data::Get_fitness(double num)	// 적합도 함수를 이용하여 적합도 계산하기.
{
	double result;
	result = pow(num, 5) - 4 * pow(num, 4) - 12 * pow(num, 3) + 34 * pow(num, 2) + 11 * num - 30;

	return result;
}

void Data::set_chromo(string chromosome, int index)
{
	chromo_Population[index] = chromosome;
}

void Data::set_off1Idx(int index)
{
	offspring1_Idx = index;
}
void Data::set_off2Idx(int index)
{
	offspring2_Idx = index;
}
int Data::get_off1Idx()
{
	return offspring1_Idx;
}
int Data::get_off2Idx()
{
	return offspring2_Idx;
}

void Data::Clear()
{
	offspring1_Idx = -1;	offspring2_Idx = -1;
	Total_fitness = 0;
	
}