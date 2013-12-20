#pragma once
class CBone
{
	bool isRoot;
	float basePointPos[3];//基点位置
	float vector[3];//相对于父元素朝向
public:
	CBone(void);
	virtual ~CBone(void);
	void setAsRoot(void);
	bool getIsRoot(void);
	void draw(void);
};
