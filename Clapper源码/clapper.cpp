//������
#include "define.h"
#include <iostream>
using namespace std;

extern int Whole, Round;
extern Hero COM, MY;
extern float win_round;

int main(void)
{
	while (Menu() == 1)
	{
		for (int again = 6; again == 6; ++Whole)
		{
			for (Round = 1; COM.Ending(MY); ++Round)
			{
				COM.Com_act(MY);
				MY.Face(); 
				//��Ա��������
				COM.Life( MY);
				COM.Inf();
				MY.Inf();
				COM.Note();
				MY.Note();
			}
			again = COM.Again();
			COM.Win_rate(MY);
			COM.First();
			MY.First();
			system("cls");
		}
	}
	system("cls");
	cout << "���˳���Ϸ" << endl;
	cin.get();
	return 0;
}