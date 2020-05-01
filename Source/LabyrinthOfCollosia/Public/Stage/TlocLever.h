// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interruptor.h"

/**
 * 
 */
class LABYRINTHOFCOLLOSIA_API TlocLever : public AInterruptor
{
public:
	TlocLever();
	~TlocLever();

	void InitLever();
	void ReplaceLever(TlocLever &_lev);

	TArray<TCHAR*> GetMeshesFileRoot();

	void SetMesh(const TCHAR* fileRoot, int mesh);

private:

	UStaticMeshComponent* _auxMesh;
	TCHAR* _auxFileRoot;
};
