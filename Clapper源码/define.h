//�ṹ������ԭ��
#ifndef DEFINE_H
#define DEFINE_H
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

struct Action    //��Ϊ������
{
	string name;   //��Ϊ����
	Act num;       //��Ϊ��ֵ
	unsigned int DFS;    //������
	int ATK;             //������
	int POW;             //����ֵ
	int LIF;             //������
	bool real_atk;       //�Ƿ�Ϊ��ʵ�˺�
	int crit_rate;       //�Ա����ʵ�Ӱ��
	int pra_time;        //������ֵ��Ӱ��
	
};
static Action Rec = { "�ָ�",rec,0,0,1,0,false,0,0 };
static Action Dod = { "����",dod,1,0,0,0,false,0,0 };
static Action Def = { "����",def,5,0,0,0,false,0,0 };
static Action Hit = { "����",hit,0,1,-1,0,false,0,0 };
static Action Kil = { "նɱ",kil,0,1,-5,0,true,0,0 };
static Action Pra = { "��",pra,1,0,-4,1,false,0,1 };
static Action Rep = { "���",rep,1,0,-4,0,false,0,1 };


class Hero
{
private:
	string name;           //��Ա����
	int life;              //��Ա������ֵ
	Action act;            //��Ա����Ϊ
	int power;             //��Ա���е�����
	int crit_rate;         //��Ա�ı�����
	int crit_checker;      //����Աʱ�񱩻�,�Ա����˺�����
	int crit_plus;         //��¼��Աÿ�����ӵı�����
	float win_rate;        //��Ա��ʤ��
	unsigned int pra_time; //��¼��Ա��������
	bool rep_note;         //�ж��Ƿ��Ѿ�����|�ϵ�����|
public:
	Hero(string _name="/0", int _life=3, Action& _act=Rec, int _power=0, int _crit_rate=5, int _crit_checker=0,
		int _crit_plus=0, float _win_rate=0, unsigned int _pra_time=0, bool _rep_note=true);
	bool Ending(Hero& MY)
	{
		return(life > 0 && MY.life > 0);
	};
	void Name(void);
	void Com_act(Hero& MY_ACT);
	Action& Number_to_action(int number);
	void My_act(void);
	void Face(void);
	int Life(Hero &MY_LIFE);
	void Win_rate(Hero& MY_WIN);
	void Inf(void);
	void Note(void);
	int Again(void);
	void First(void);
	//��������
};

int Menu(void);
#endif