#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Data
{
private:
	int N = 100;	int CHRO_LENGTH = 16;
	double crossover_rate = 0.7;
	double mutation_rate = 0.001;

	int offspring1_Idx;	int offspring2_Idx;

	vector<string> chromo_Population;		// randomly하게 get한 chromosome 저장.
	vector<double> express_rangeOfchromo;	// 범위 내의 chromosome으로 저장한 집합
	vector<double> chromo_fitness;			// fitness를 계산한 chromosome을 저장.
	vector<double> fitness_rate;			// 적합도 비율을 저장.

	double Total_fitness =0;

public:
	int Get_N();	int Get_chroLength();
	double Get_crossover_rate();
	double Get_mutation_rate();

	void set_off1Idx(int index);
	void set_off2Idx(int index);
	int get_off1Idx();
	int get_off2Idx();

	void add_chromo(string chromosome);
	void set_chromo(string chromosome, int index);
	void Add_chromofitness(double each_fitness);
	void Set_chromofitness(double each_fitness, int index);
	void add_rangeOfchromo(double num);
	void set_rangeOfchromo(double num, int index);
	void add_fitness_rate(double each_rate);
	void Set_Totalfitness(double each_fitness);

	string get_chromo(int index);

	double get_chromofitness(int index);
	double get_rangeOfchromo(int index);
	double get_fitnessrate(int index);
	double Get_fitness(double num);
	double get_Totalfitness();
	
	void Clear();
};