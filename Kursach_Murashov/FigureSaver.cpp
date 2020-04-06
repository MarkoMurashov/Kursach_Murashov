#include "pch.h"
#include "FigureSaver.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace System;
using namespace std;

FigureSaver::FigureSaver(Scene^ sc, String^ path)
{
	scene = sc;
	this->path = path;
}

void FigureSaver::Create()
{
	fg = scene->CreateMemento();
	String^ localPath = Directory::GetCurrentDirectory() + "\\Figures";

	if (!Directory::Exists(localPath))
	{
		Directory::CreateDirectory(localPath);
	}
	if (!File::Exists(localPath + path))
	{
		FileStream^ stream = gcnew FileStream(localPath + path, FileMode::Create);
		stream->Close();
	}
	path = localPath + path;

	FileStream^ stream = gcnew FileStream(path, FileMode::Open);
	BinaryFormatter^ bf = gcnew BinaryFormatter();
	bf->Serialize(stream, fg);
	stream->Close();
}
void FigureSaver::Undo()
{
	String^ localPath = Directory::GetCurrentDirectory() + "\\Figures";

	if (!Directory::Exists(localPath))
	{
		Directory::CreateDirectory(localPath);
	}
	if (!File::Exists(localPath + path))
	{
		FileStream^ stream = gcnew FileStream(localPath + path, FileMode::Create);
		stream->Close();
	}
	path = localPath + path;

	FileStream^ stream = gcnew FileStream(path, FileMode::Open);
	BinaryFormatter^ bf = gcnew BinaryFormatter();
	scene->Restore(static_cast<FigureMemento^>(bf->Deserialize(stream)));
	stream->Close();
}

