#pragma once

#ifndef MYMISSIONMANAGER_H_
#define MYMISSIONMANAGER_H_

#include "MyMission.h"
#include <vector>

//----------------------------------------------------
//	������������
//	ά��һ���������
//	�ṩ�������񣬹������񣬻ָ�����ȡ������ȷ���
//----------------------------------------------------
class MyMissionManager
{
private:
	std::vector<MyMission*> missionList;
	int maxCurrency;			//��ͬʱִ�е�������
	int currentTrans;			//��ǰ����ִ�е�������

public:
	MyMissionManager();

	~MyMissionManager();

	//����һ��������,���ͬʱ���е��������ﵽ���ֵ��
	//���������Ӻ���𣬷����������Ӻ�ֱ��ִ��
	bool NewMission(MyMission* m);

//	void SpeedChange(MyMission*, unsigned int speed);
	void ProgressChange(MyMission*, float progress, unsigned int speed);
	void CompleteChange(MyMission*);

#pragma region GetAndSet
	void SetMaxCurrency(const int mc) {
		maxCurrency = mc;
	}

	void SetCurrentTrans(const int ct) {
		currentTrans = ct;
	}

	int GetMaxCurrency() {
		return maxCurrency;
	}

	int GetCurrentTrans() {
		return currentTrans;
	}

	int GetMissionNum() {
		return missionList.size();
	}

	std::string GetPath(int n) {
		if (missionList.size() == 0) {
			return "";
		}
		if (missionList.size() <= n) {
			missionList.back()->GetLocalPath();
		}
		return missionList.at(n)->GetLocalPath();
	}

	bool IsFull() {
		return currentTrans == maxCurrency;
	}

#pragma endregion

#pragma region MissionManage
	//�������д����̣߳��������Ϊ�߳��±�
	//����±�Խ�磬����false
	//����ִ���̵߳�resume�������������䷵��ֵ
	bool Resume(int pos);

	//�������̣߳�����ͣ�����������Ϊ�߳��±�
	//����±�Խ�磬����false
	//����ִ���̵߳Ĺ��������������䷵��ֵ
	bool Suspend(int pos);
	bool Suspend(std::vector<int> &poss);
	bool SuspendAll();

	bool Cancel(int pos);
	bool CancelAll();

	//�����˳�ʱ��ֹ����δ��������߳�
	void CloseAllThread();

#pragma endregion

	void Release();
};

#endif // !MYMISSIONMANAGER_H_