#pragma once
class CBone
{
	bool isRoot;
	float basePointPos[3];//����λ��
	float vector[3];//����ڸ�Ԫ�س���
public:
	CBone(void);
	virtual ~CBone(void);
	void setAsRoot(void);
	bool getIsRoot(void);
	void draw(void);
};
