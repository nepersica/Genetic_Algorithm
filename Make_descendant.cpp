#include "Make_descendant.h"
#include <random>

int Make_Descendant::Roulette(Data &data)
{
	random_device _num;		mt19937_64 NUM(_num());
	uniform_real_distribution<> PICK_NUM_RANDOMLY(0, 100);

	double choose = PICK_NUM_RANDOMLY(NUM);

	double sum = 0;
	for (int i = 0; i < data.Get_N(); i++)
	{
		sum += data.get_fitnessrate(i);

		if(sum >= choose)
			return i;
	}

}

void Make_Descendant::CrossOver(string &offspring1, string &offspring2, Data &data)
{
	random_device _num;		mt19937_64 NUM(_num());
	uniform_real_distribution<> PICK_NUM_RANDOMLY(0, 1);

	// 1�� �������� ���.
	// Crossover Ȯ���� ���� crossover�� ��ġ�� ������ ������ ������.
	// ����, ������ �������� �ʾ� �������� ������ ����ü ������ �θ� �Ȱ��� ������ �ڽ��� �����.
	if (PICK_NUM_RANDOMLY(NUM) < data.Get_crossover_rate())	
	{
		int switchIndex = (int)(data.Get_chroLength()*PICK_NUM_RANDOMLY(NUM));

		string made1 = offspring1.substr(0, switchIndex) + offspring2.substr(switchIndex, data.Get_chroLength());
		string made2 = offspring2.substr(0, switchIndex) + offspring1.substr(switchIndex, data.Get_chroLength());

		offspring1 = made1;	offspring2 = made2;

		
	}

}

void Make_Descendant::Mutation(string &bits, Data &data)
{
	random_device _num;		mt19937_64 NUM(_num());
	uniform_real_distribution<> PICK_NUM_RANDOMLY(0, 1);

	for (int i = 0; i < data.Get_chroLength(); i++)
	{
		if (PICK_NUM_RANDOMLY(NUM) < data.Get_mutation_rate())
		{
			if (bits.at(i) == '1')

				bits.at(i) = '0';
			else

				bits.at(i) = '1';
		}
	}
}
