//����
#include "clapper.h"
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include<iomanip>
using namespace std;

int Whole = 1, Round = 1;
float win_round = 0.0;
//����������غ��������ʤ������
Hero COM = { "Com", 3, rec, 1, 5, 0, 0, 0.0, 0,true },
MY = { "\0", 3, rec, 0, 5, 0, 0, 0.0, 0,true };
//�Ե��ԡ���ҵ�����ʼ����


int menu(void) //��ӡ�˵�
{
	int choice;
	do {
		cout << "        *************************          " << endl;
		cout << "        *        �� �� ��       *          " << endl;
		cout << "        *     1.�� ʼ �� Ϸ     *          " << endl;
		cout << "        *     2.�� Ϸ �� ��     *          " << endl;
		cout << "        *     3.�� Ϸ ͼ ��     *          " << endl;
		cout << "        *     4.�� �� �� Ա     *          " << endl;
		cout << "        *     5.�� �� �� Ϸ     *          " << endl;
		cout << "        *************************          " << endl;
		cout << "�������ѡ��:";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			name(MY);
			return 1;
		case 2:
			cout << "��Ϸ�淨:  ������       " << endl;
			break;
		case 3:
			cout << "��Ϸͼ��:  ������       " << endl;
			break;
		case 4:
			cout << "     �� �� �� Ա       " << endl;
			cout << "     CannonBox       \n" << endl;
			cout << "     Version:1.2.0       " << endl;
			break;
		case 5:
			return 5;
		default:
			cout << "û�����ѡ��!" << endl;

		}
		cout << "����������ز˵���       " << endl;
		system("pause");
		system("cls");
	} while (choice != 1 || choice != 5);
	return choice;
}

void name(Hero& NAME) //���Ϊ��ɫȡ��
{
	cout << "Ϊ��Ľ�ɫȡ������(����7���ַ�):\n";
	cin.ignore();
	getline(cin,NAME.name);
	while (NAME.name.length() > 7)
	{
		cout << "�������̫����!��ȡһ����:\n";
		getline(cin, NAME.name);
	}
}

string action(Hero& ACTION) //������Ϊֵ������Ϊ
{
	switch (ACTION.act)
	{
	case rec:
		return "�ָ�";
	case dod:
		return "����";
	case def:
		return "����";
	case hit:
		return "����";
	case kil:
		return "նɱ";
	case pra:
		return "��";
	case rep:
		return "���";

	default:
		return "\0";
	}
}

int power_checker(const Act POWER) //���ڸ�����Ϊ�ж������仯,�������ĵ�����ֵ
{
	int power;
	switch (POWER)
	{
	case rec:
		power = 1;
		break;
	case dod:
		power = 0;
		break;
	case def:
		power = -1;
		break;
	case hit:
		power = -1;
		break;
	case kil:
		power = -5;
		break;
	case pra:
		power = -4;
		break;
	case rep:
		power = -4;
	}
	return power;
}

void com_act(Hero& COM_ACT, Hero& MY_ACT) //������������ж�
{
	srand((unsigned)time(NULL));
	if (Round > 1)
	{
		do {
			do {
				COM_ACT.act = (Act)(rand() % 7 + 1);
			} while ((MY_ACT.power < 5 && COM_ACT.act == def) || (COM_ACT.pra_time < 3 && COM_ACT.act == rep));

			if (COM_ACT.power == 0)
			{
				if (rand() % 3 != 0)
				{
					COM_ACT.act = rec;
				}
				else
				{
					COM_ACT.act = dod;
				}
			}

			if (COM_ACT.power >= 4)
			{
				if (rand() % COM_ACT.life == 0 && COM_ACT.pra_time < 3)
				{
					COM_ACT.act = pra;
				}
				else if (rand() % 2 == 0 && COM_ACT.pra_time >= 3)
				{
					COM_ACT.act = rep;
				}
			}

			if (COM_ACT.power >= 5)
			{
				if (rand() % MY_ACT.life != 0)
				{
					COM_ACT.act = kil;
				}
			}

			if (MY_ACT.power >= 5)
			{
				if (rand() % 4 == 0)
				{
					COM_ACT.act = def;
				}
			}
		} while (COM_ACT.power + power_checker(COM_ACT.act) < 0);
		COM_ACT.power += power_checker(COM_ACT.act);
	}
	if (COM_ACT.act == pra)
	{
		++COM_ACT.pra_time;
	}
}

void my_act(Hero& MY_ACT) //��Ҿ����ж�
{
	int temp_act;
	cin >> temp_act;
	while ((temp_act > 6) || (temp_act < 1))
	{
		cout << "��Ϊ��Ч,�����¾���:";
		cin >> temp_act;
	}
	while (MY_ACT.power + power_checker((Act)temp_act) < 0)
	{
		cout << "��������,�����¾���:";
		cin >> temp_act;
	}
	if (temp_act == 6)
	{
		if (MY_ACT.pra_time >= 3)
			temp_act = 7;
		else
		{
			++MY_ACT.pra_time;
		}
	}
	MY_ACT.act = (Act)temp_act;
}

int situ(const Act com_act, const Act my_act) //������Ϊֵ���ض�Ӧ��Ψһ���ֵ
{
	int situation = com_act * 10 + my_act;
	return situation;
}

void face(Hero& FACE) //��ӡ����
{
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "��" << Whole << "��|��" << Round << "�غ�" << endl;
	cout << "1.�� ��  2.�� ��  3.�� ��" << endl
		<< "4.�� ��  5.ն ɱ  ";
	if (FACE.pra_time < 3)
	{
		cout << "6.�� ��" << endl;
	}
	else
	{
		cout << "6.�� ��" << endl;
	}
	cout << "����������ж�:";
	my_act(FACE);
	cout << "\n���\t\t����\t\t��Ϊ\t\t����\t\t������\t\tʤ��\n";
}

int life(Hero& COM_LIFE, Hero& MY_LIFE) //�ж���������,�������˺�ֵ
{
	srand((unsigned)time(NULL));
	unsigned int hurt = 0;
	int situation = situ(COM_LIFE.act, MY_LIFE.act);
	//�������ֵ���з���
	switch (situation)
	{
	case 74:
		COM_LIFE.crit_plus = rand() % 6 + 10;
	case 14:
		hurt = 1;
		if ((rand() % 100 + 1) <= MY_LIFE.crit_rate)
		{
			hurt = 2;
			MY_LIFE.crit_checker = 2;
		}
		goto COM_HURT;
	case 75:
		COM_LIFE.crit_plus = rand() % 6 + 10;
	case 15:
	case 25:
	case 45:
		hurt = 1;
		if ((rand() % 100 + 1) <= MY_LIFE.crit_rate)
		{
			if ((hurt = rand() % 2 + 2) > 1)
			{
				MY_LIFE.crit_checker = 2;
				if (hurt > 2)
				{
					MY_LIFE.crit_checker = 3;
				}
			}
		}
		goto COM_HURT;
	case 35:
		hurt = 0;
		COM_LIFE.crit_plus = rand() % 4 + 3;
		goto COM_HURT;
	case 66:
		MY_LIFE.crit_plus = rand() % 6 + 3;
		MY_LIFE.crit_rate += MY_LIFE.crit_plus;
		++MY_LIFE.life;
	case 61:
	case 62:
	case 63:
	case 64:
		hurt = -1;
		COM_LIFE.crit_plus = rand() % 6 + 3;
		goto COM_HURT;
	case 65:
		hurt = 0;
		COM_LIFE.crit_plus = rand() % 6 + 3;
		goto COM_HURT;
	case 71:
	case 72:
	case 73:
		COM_LIFE.crit_plus = rand() % 6 + 10;
		goto COM_HURT;

	COM_HURT:
		COM_LIFE.crit_rate += COM_LIFE.crit_plus;
		COM_LIFE.life -= hurt;
		break;

	case 47:
		COM_LIFE.crit_plus = rand() % 6 + 10;
	case 41:
		hurt = 1;
		if ((rand() % 100 + 1) <= COM_LIFE.crit_rate)
		{
			hurt = 2;
			COM_LIFE.crit_checker = 2;
		}
		goto MY_HURT;
	case 57:
		MY_LIFE.crit_plus = rand() % 6 + 10;
	case 51:
	case 52:
	case 54:
		hurt = 1;
		if ((rand() % 100 + 1) <= COM_LIFE.crit_rate)
		{
			if ((hurt = rand() % 2 + 2) > 1)
			{
				COM_LIFE.crit_checker = 2;
				if (hurt > 2)
				{
					MY_LIFE.crit_checker = 3;
				}
			}
		}
		goto MY_HURT;
	case 53:
		hurt = 0;
		MY_LIFE.crit_plus = rand() % 6 + 3;
		goto MY_HURT;
	case 16:
	case 26:
	case 36:
	case 46:
		hurt = -1;
		MY_LIFE.crit_plus = rand() % 6 + 3;
		goto MY_HURT;
	case 56:
		hurt = 0;
		MY_LIFE.crit_plus = rand() % 6 + 3;
		goto MY_HURT;
	case 17:
	case 27:
	case 37:
		hurt = 0;
		MY_LIFE.crit_plus = rand() % 6 + 10;
		goto MY_HURT;

	MY_HURT:
		MY_LIFE.crit_rate += MY_LIFE.crit_plus;
		MY_LIFE.life -= hurt;
		break;

	default:
		hurt = 0;
	}

	return hurt;
}

void win_rate(Hero& COM_WIN, Hero& MY_WIN) //�����Աʤ��
{
	if (COM_WIN.life <= 0)
	{
		++win_round;
	}
	MY_WIN.win_rate = win_round / Whole * 100;
	if (Whole - win_round <= 0)
	{
		COM_WIN.win_rate = 0;
	}
	else
	{
		COM_WIN.win_rate = (Whole - win_round) / Whole * 100;
	}
}

void inf(Hero& HERO) //��ӡ���Ժ���ҵ���Ϣ
{
	cout << HERO.name << "\t\t";
	for (int i = 0; i < HERO.life && HERO.life > 0; i++)
	{
		cout << "+";
	}
	if (HERO.crit_rate >= 100)
	{
		HERO.crit_rate = 100;
	}
	cout << "\t\t" << action(HERO)
		<< "\t\t" << HERO.power
		<< "\t\t" << HERO.crit_rate << "\%"
		<< "\t\t" << fixed << setprecision(2) << HERO.win_rate << "\%" << endl;
}

void note(Hero& NOTE) //��������������
{
	bool rep_note = true;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "\n";

	if (NOTE.crit_checker) //����Ա��ɱ���,���ӡ�������
	{
		cout << NOTE.name << "����˱���!,�����" << NOTE.crit_checker << "���˺�" << endl;
		NOTE.crit_checker = 0;
	}

	if (NOTE.act == pra)
	{
		cout << NOTE.name << "�������ϵ�\'�� ��\',���� + 1,������ + " << NOTE.crit_plus << "\%!" << endl;
	}

	if (NOTE.act == rep)
	{
		cout << NOTE.name << "�������ϵ�\'�� ��\',������ + " << NOTE.crit_plus << "\%!" << endl;
	}

	if (NOTE.pra_time == 3 && NOTE.rep_note)
	{
		cout << "|�� �� �� ��|," << NOTE.name << "�� �� \'|�� ��|\'" << endl;
		NOTE.rep_note = false;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int _again(void)
{
	int again;
	if (COM.life > 0)
	{
		MessageBox(NULL, (LPCTSTR)TEXT("�㱻���������ˣ�"), (LPCTSTR)TEXT("ʤ���ѷ�"), MB_OK);
	}
	else
	{
		MessageBox(NULL, (LPCTSTR)TEXT("��ϲ�����˼����"), (LPCTSTR)TEXT("ʤ���ѷ�"), MB_OK);
	}
	again = MessageBox(NULL, (LPCTSTR)TEXT("��������һ�֣�"), (LPCTSTR)TEXT("ʤ���ѷ�"), MB_YESNO);
	return again;
}

void first(void) //���г�ʼ��
{
	COM.life = MY.life = 3;
	COM.act = rec;
	COM.power = 1;
	MY.power = 0;
	COM.crit_rate = MY.crit_rate = 5;
	COM.pra_time = MY.pra_time = 0;
}

void both_fun(Hero& COM_FUN, Hero& MY_FUN, void (*both)(Hero&))  //����ֱ�ӶԳ�Ա����ͬһ����
{
	both(COM_FUN);
	both(MY_FUN);
}