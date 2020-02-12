// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocChest.h"

TlocChest::TlocChest()
{
	opened = false;
	_object = nullptr;
}

TlocChest::~TlocChest()
{
	opened = false;
	_object = nullptr;
}

void TlocChest::SetOpened(bool open)
{
	opened = open;
}

void TlocChest::SetObject(ATlocObject* _obj)
{
	_object = _obj;
}

bool TlocChest::GetOpened()
{
	return opened;
}

ATlocObject* TlocChest::GetObject()
{
	return _object;
}
