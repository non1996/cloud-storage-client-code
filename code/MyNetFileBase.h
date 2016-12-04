#pragma once

#ifndef MYNETFILEBASE_H_
#define MYNETFILEBASE_H_

#include "Cleaner.h"
#include <string>

class MyNetFileBase
{
private:
	std::string uId;
	std::string name;
	std::string path;
	std::string date;
	unsigned long long size;
public:
	MyNetFileBase();
	MyNetFileBase(std::string &name, std::string &path, std::string &date, unsigned long long size);
	MyNetFileBase(std::string &uId, std::string &name, std::string &path, std::string &date, unsigned long long size);
	virtual ~MyNetFileBase();

	void SetUid(std::string &uId) {
		this->uId = uId;
	}

	void SetName(std::string &name) {
		this->name = name;
	}

	void SetPath(std::string &path) {
		this->path = path;
	}

	void SetDate(std::string &data) {
		this->path = path;
	}

	void SetSize(unsigned long long size) {
		this->size = size;
	}

	std::string & GetUid() {
		return uId;
	}

	std::string & GetName() {
		return name;
	}

	std::string & GetPath() {
		return path;
	}

	std::string &GetDate() {
		return date;
	}

	virtual std::string GetType() {
		return "";
	}

	unsigned long long GetSize() {
		return size;
	}
};

class MyNetFileNorm 
	:public MyNetFileBase{
private:
	
public:
	MyNetFileNorm() 
		:MyNetFileBase(){

	}
	
	MyNetFileNorm(std::string &uId, std::string &name, std::string &path, std::string &date, unsigned long long size)
		:MyNetFileBase(uId, name, path, date, size) {

	}
	
	virtual std::string GetType() {
		return "file";
	}
};

class MyNetFileDir
	:public MyNetFileBase{
private:

public:
	MyNetFileDir()
		:MyNetFileBase() {

	}

	MyNetFileDir(std::string &uId, std::string &name, std::string &path, std::string &date, unsigned long long size)
		:MyNetFileBase(uId, name, path, date, size) {

	}

	virtual std::string GetType() {
		return "dir";
	}
};
#endif // !MYNETFILEBASE_H_


