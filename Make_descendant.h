#pragma once
#include "Data.h";

// 교차(crossover) : 부모 염색체 둘이 끊어지는 지점을 임의로 선택하고, 염색체에서 이 지점보다 뒤쪽에 있는 부분을 교환해
//					 새로운 자식 염색체 두 개를 생성한다.
//					 염색체 쌍이 교차되지 않으면 염색체 복제가 이루어져 부모를 똑같이 복사해 자식을 만든다.

// 변이(mutation) : 탐색 알고리즘이 지역 최적점에 갇히지 않도록 보장하는 역할을 한다. 
//					선택과 교차 연산만 적용하다 보면 동질적인 해집단에서 정체될 수 있다. => 유전적 다양성을 유지.
//					염색체에서 임의로 선택한 유전자를 뒤집는다.

class Make_Descendant
{
public:
	int Roulette(Data &data);
	void CrossOver(string &offspring1, string &offspring2, Data &data);
	void Mutation(string &bits, Data &data);
};