﻿#ifndef __SKILL_STRUCT_H__
#define __SKILL_STRUCT_H__

enum ECenterType
{
	TYPE_TARGET_POS		= 1,//以客户端选定的位置为中心
	TYPE_TARTGT_OBJ     = 2,//以客户端选定的对象为中心
	TYPE_CASTER_POS		= 3,//以施法者为中心
	TYPE_CASTER_OFFSET	= 4,//以施法者为中心的偏移位置为中心
};

enum ERangeType
{
	TYPE_OBJECTS		= 1,//客户端指定的目标
	TYPE_CYLINDER		= 2,//扇形圆柱
	TYPE_CIRCLE			= 3,//圆形圆柱
	TYPE_BOX			= 4,//矩形区域
};

enum EBulletType
{
	TYPE_CHASE			= 0,//追踪型飞弹
	TYPE_FIXDIRECTION	= 1,//固定方向型飞弹
	TYPE_FIXTARGETPOS	= 2,//固定目标点飞弹
	TYPE_POINT			= 3,//固定点飞弹
	TYPE_LINK			= 4,//连接飞弹
	TYPE_ANNULAR		= 5,//环形飞弹
	TYPE_BACK			= 6,//回旋飞弹
	TYPE_EXTRACT		= 7,//抽取飞弹
	TYPE_BOUNDCE		= 8,//弹跳飞弹
};

enum EAffectShip
{
	EAS_Self = 0, //影响自己
	EAS_Enem = 1, //影响敌方
	EAS_Ally = 2, //影响友方
	EAS_Each = 3, //影响所有
};

enum ESelectPolicy
{
	ESP_DEFAULT			= 0,//默认
	ESP_BY_MOREHEALTH	= 1,//按血量比例最高
	ESP_BY_LESSHEALTH	= 2,//按血量比例最低
	ESP_BY_MOREDISTANCE = 3,//按距离比例最高
	ESP_BY_LESSDISTANCE = 4,//按距离比例最低
};

// enum EObjectStatus
// {
// 	EOS_NONE = 0;//无
// 	EOS_DEAD = 1;//死亡
// 	EOS_IDLE = 2;//静止
// 	EOS_WALK = 3;//走
// 	EOS_RUN = 4;//跑
// 	EOS_FLY = 5;//飞
// 	EOS_NOT_MOVE = 6;//不能移动
// 	EOS_NOT_CAST = 7;//不能放技能
// 	EOS_NOT_BEHURT = 8;//不能被攻击
// 	EOS_NOT_BECONTROL = 9;//无法被控制
// 	EOS_STEALTH = 10;//隐身
// 	EOS_BLIND = 11;//瞎的
// };





struct StBuffInfo
{
	UINT32 BuffID;						//BuffID
	UINT32 BuffEffect;					//Buff目标需要加的特效
	INT32  PtyValue[PROPERTY_NUM];		//加属性值
	INT32  PtyPercent[PROPERTY_NUM];	//加属性百分比
	INT32  TotalTime;                   //总时长(ms)
	INT32  Interval;					//间隔时长
	UINT32 ChangeStatus;				//修改玩家的状态
	BOOL   OverLay;				        //是否可以叠加
	std::string   LuaAdd;				//是否有lua事件
	std::string   LuaTick;				//是否有lua事件
	std::string   LuaRemove;			//是否有lua事件
};

struct StBulletInfo
{
	UINT32 BulletID;    //子弹ID
	UINT32 BulletType;  //子弹类型
	FLOAT  Angle;       //角度
	FLOAT  Speed;       //速度
	FLOAT  AccSpd;      //加速度
	FLOAT  Radius;      //半径
	UINT32 LifeTime;    //生命期
};


struct StSkillEvent
{
	UINT64 TrigerTime = 0;					//触发时间
	UINT32 ActionID = 0;					//受击动作, 击退，击飞， 击倒
	UINT32 SelfBuffID = 0;					//自己的BuffID
	UINT32 TargetBuffID = 0;				//目标的BuffID
	FLOAT  RangeParams[5] = {0};			//范围参数
	ERangeType RangeType = TYPE_OBJECTS;	//范围类型
	UINT32 CenterType = 0;					//中心点类型
	std::vector<StBulletInfo> vtBullets;	//子弹列表
};

struct StSkillInfo
{
	UINT32		SkillID;		//技能ID
	UINT32		Level;			//技能类型
	UINT32		CD;				//技能CD
	UINT32		CostMp;			//消耗魔法值
	UINT64		uDuration;		//技能持续总时间
	INT32		HurtFix;		//固定伤害
	INT32		HurtMuti;		//加成伤害
};


struct StSkillEventInfo
{
	UINT32		SkillID;		//技能ID
	std::vector<StSkillEvent> vtEvents; //技能事件列表
};

struct StComboSkillInfo
{
	UINT32		SkillID;				//主技能ID
	std::vector<UINT32> vtComboSkill;	//连击技能
};


#endif //__CONFIG_STRUCT_H__