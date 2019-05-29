#pragma once
#include "Data.h";

// ����(crossover) : �θ� ����ü ���� �������� ������ ���Ƿ� �����ϰ�, ����ü���� �� �������� ���ʿ� �ִ� �κ��� ��ȯ��
//					 ���ο� �ڽ� ����ü �� ���� �����Ѵ�.
//					 ����ü ���� �������� ������ ����ü ������ �̷���� �θ� �Ȱ��� ������ �ڽ��� �����.

// ����(mutation) : Ž�� �˰����� ���� �������� ������ �ʵ��� �����ϴ� ������ �Ѵ�. 
//					���ð� ���� ���길 �����ϴ� ���� �������� �����ܿ��� ��ü�� �� �ִ�. => ������ �پ缺�� ����.
//					����ü���� ���Ƿ� ������ �����ڸ� �����´�.

class Make_Descendant
{
public:
	int Roulette(Data &data);
	void CrossOver(string &offspring1, string &offspring2, Data &data);
	void Mutation(string &bits, Data &data);
};