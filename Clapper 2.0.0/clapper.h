//�ṹ������ԭ��
#include <string>
using std::string;
typedef enum
{
	rec = 1,
	dod,
	def,
	hit,
	kil,
	pra,
	rep
} Act;
//������Ϊ����

struct Hero
{
	string name;           //��Ա����
	int life;              //��Ա������ֵ
	Act act;               //��Ա����Ϊ
	int power;             //��Ա���е�����
	int crit_rate;         //��Ա�ı�����
	int crit_checker;      //����Աʱ�񱩻�,�Ա����˺�����
	int crit_plus;         //��¼��Աÿ�����ӵı�����
	float win_rate;        //��Ա��ʤ��
	unsigned int pra_time; //��¼��Ա��������
};

bool menu(void);
string action(Hero& ACTION);
int power_checker(Act POWER);
void com_act(Hero& COM_ACT,Hero& MY_ACT);
void my_act(Hero& MY_ACT);
int situ(const Act com_act, const Act my_act);
void face(Hero& FACE);
int life(Hero& COM_LIFE, Hero& MY_LIFE);
void win_rate(Hero& COM_WIN, Hero MY_WIN);
void inf(Hero& HERO);
void note(Hero& NOTE);
bool _again(void);
void first(void);
void both_fun(Hero& COM_FUN, Hero& MY_FUN,void (*both)(Hero&));
//��������