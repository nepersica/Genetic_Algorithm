#include "Chromosome.h"
#include <random>
#include <Windows.h>
#include <fstream>

void Chromosome::Make_Chromosomes()
{
	Data data; ofstream outfile("Genetic_Algorithm_Output.txt");

	for (int i = 0; i < data.Get_N(); i++)	// 16비트의 바이너리를 가진 chromosome 100개 생성하기
		data.add_chromo(Random_bit(data.Get_chroLength()));

	int t = 0;
	while(t != 200)	// Generation
	{
		for (int i = 0; i < data.Get_N(); i++)	// 원하는(-7.0 ~ 7.0) 범위의 실수로 나타내주기.(디코딩)
			data.add_rangeOfchromo(ExpressInRange(data.get_chromo(i), data));

		double Total_fitness = 0;
		for (int i = 0; i < data.Get_N(); i++)	// fitness function에 넣어 fitness 계산하기.
		{
			double now = data.get_rangeOfchromo(i);
			double fitness = data.Get_fitness(now);
			data.Add_chromofitness(fitness);

			Total_fitness += abs(fitness);

		}

		data.Set_Totalfitness(Total_fitness);

		Calculate_FitnessRate(data);

		int c = 0;
		vector<string> chromo_descendant;
		while (c != 100)	// 새로운 해집단의 크기가 100개가 될때까지 돌리기
		{
			Make_Descendant Descendant;

			// 염색체 한 쌍을  선택하기.
			int offspring1_Idx = Descendant.Roulette(data);
			int offspring2_Idx;
			do
			{	// 중복 방지..
				offspring2_Idx = Descendant.Roulette(data);
			} while (offspring1_Idx == offspring2_Idx);

			string offspring1 = data.get_chromo(offspring1_Idx);
			string offspring2 = data.get_chromo(offspring2_Idx);

			Descendant.CrossOver(offspring1, offspring2, data);
			Descendant.Mutation(offspring1, data);
			Descendant.Mutation(offspring2, data);

			data.set_chromo(offspring1, offspring1_Idx);
			data.set_chromo(offspring2, offspring2_Idx);

			chromo_descendant.push_back(offspring1);
			chromo_descendant.push_back(offspring2);

			c++;
		}

		for (int i = 0; i < data.Get_N(); i++)	// 현재 해집단을 새로운 해집단으로 교체하기.
			data.set_rangeOfchromo(ExpressInRange(chromo_descendant[i], data), i);

		for (int i = 0; i < data.Get_N(); i++)	// fitness function에 넣어 fitness 계산하기.
		{
			double now = data.get_rangeOfchromo(i);
			double fitness = data.Get_fitness(now);
			data.Set_chromofitness(fitness, i);

		}

		cout << "Test" << t << "----------" << endl;
		Print(data, outfile);

		t++;
	}
	outfile.close();

}

void Chromosome::Print(Data &data, ofstream &outfile)
{
	
	double sum = 0;	double max = -8;	int max_index = -1;
	for (int i = 0; i < data.Get_N(); i++)
	{
		double now = data.get_rangeOfchromo(i);

		if (now > max)
		{
			max_index = i;		max = now;
		}		sum += now;
		/*cout << data.get_rangeOfchromo(i) << " ";

		cout << data.get_chromofitness(i) << " ";*/

	}
	//cout << endl;
	cout << "Average : " << sum / data.Get_N() << " \t max : " << max << "\t fx_max : " << data.get_chromofitness(max_index) << endl;
	outfile << sum / data.Get_N() << "\t" << max << "\t" << data.get_chromofitness(max_index) << "\n";


}

string Chromosome::Random_bit(int chro_length)
{
	random_device _num;		mt19937_64 NUM(_num());
	uniform_real_distribution<> PICK_NUM_RANDOMLY(0, 1);

	string bits = "";
	

	for (int i = 0; i < chro_length; i++)
	{
		if (PICK_NUM_RANDOMLY(NUM) > 0.5)
			bits += "1";
		else
			bits += "0";
	}

	return bits;
}

double Chromosome::bin2dec(string choromo) // 2진수 10진수로 변환하기.
{
	int val = 0;
	int value_to_add = 1;

	for (int i = choromo.length(); i > 0; i--)
	{
		if (choromo.at(i - 1) == '1')
			val += value_to_add;

		value_to_add *= 2;

	}//next bit

	return val;
}

double Chromosome::ExpressInRange(string chromo, Data &data)
{
	double dec = bin2dec(chromo);	

	double inRange = 0;
	
	inRange = dec*(14 / (pow(2, data.Get_chroLength()) - 1)) - 7;
	//inRange = ((dec / pow(2, data.Get_chroLength()) / 14)) - 7;
	

	return inRange;
}

void Chromosome::Calculate_FitnessRate(Data &data)	// 적합도 비율 계산하기.
{
	for (int i = 0; i < data.Get_N(); i++)
	{
		double each_rate = 0;
		each_rate = (abs(data.get_chromofitness(i)) / data.get_Totalfitness()) * 100;
		data.add_fitness_rate(each_rate);
	}
}