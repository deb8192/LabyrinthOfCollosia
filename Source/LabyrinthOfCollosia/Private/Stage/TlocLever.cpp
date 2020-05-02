// Fill out your copyright notice in the Description page of Project Settings.


#include "TlocLever.h"

TlocLever::TlocLever() : AInterruptor()
{
}

TlocLever::~TlocLever()
{
	_auxFileRoot = nullptr;
	_auxMesh = nullptr;
}

void TlocLever::InitLever()
{
	_auxFileRoot = TEXT("/Game/Models/Stages/Stages-objects/Interruptor.Interruptor");
	_auxMesh = _motor->SetMesh(_name, (const TCHAR*)_fileRoot, GetRootComponent(), this);
	_auxMesh->AttachTo(GetRootComponent());
}

void TlocLever::ReplaceLever(TlocLever& _lev)
{
	replaceInterruptor(_lev);

	TArray<TCHAR*> paths = _lev.GetMeshesFileRoot();
	_auxFileRoot = paths[1];
	if (*_auxFileRoot != _T('\0'))
	{
		_auxMesh = _motor->SetMesh(TEXT("Auxiliar mesh"), (const TCHAR*)_auxFileRoot, GetRootComponent(), this);
		_auxMesh->AttachTo(GetRootComponent());
		_motor->RegisterMeshComponent(_auxMesh);
	}
}

TArray<TCHAR*> TlocLever::GetMeshesFileRoot()
{

	TArray<TCHAR*> paths;
	paths.Push(_fileRoot);
	paths.Push(_auxFileRoot);
	return paths;
}

void TlocLever::SetMesh(const TCHAR* fileRoot, int mesh)
{
	switch (mesh)
	{
	case 1:
		AInterruptor::SetMesh(fileRoot);
		break;
	case 2:
		_auxFileRoot = (TCHAR*)fileRoot;
		fileRoot = nullptr;
		_auxMesh = _motor->SetMesh(_name, (const TCHAR*)_auxFileRoot, GetRootComponent(), this);
		break;
	}
}
