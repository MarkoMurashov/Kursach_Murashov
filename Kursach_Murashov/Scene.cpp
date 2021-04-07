#include "pch.h"
#include "Scene.h"
#include "Figure.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

#pragma once
Scene::Scene(const Scene%) { throw gcnew System::InvalidOperationException("Scene cannot be copy-constructed"); }

Scene^ Scene::CreateScene(PictureBox^ pb)
{ 
    _scene.bitmap = gcnew Bitmap(pb->Width, pb->Height);
   _scene.graphics = Graphics::FromImage(_scene.bitmap);

   return % _scene;
}


void Scene::Clear()
{
   _scene.graphics->Clear(Color::White);
}

void Scene::Clear(PictureBox^ pb)
{
    _scene.graphics->Clear(Color::White);

    pb->Image = _scene.bitmap;
}

void Scene::AddFigure(Figure^ f)
{ 
    _scene.figures->Add(f);
}

void Scene::DeleteFigure(String^ name)
{
    Figure^ toDelete;

    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            toDelete = f;
    }

    _scene.figures->Remove(toDelete);
}

Figure^ Scene::FindFigure(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            return f;
    }

    return nullptr;
}

void Scene::Draw(PictureBox^ pb)
{
   for each (Figure^ f in _scene.figures)
   {

      if(!f->IsHidden)
        f->Draw(_scene.graphics);
   }

   pb->Image = _scene.bitmap;
}

void Scene::Draw(PictureBox^ pb, String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {      


        if(f->Name == name && !f->IsHidden)
            f->Draw(_scene.graphics);
       
    }

    pb->Image = _scene.bitmap;
}

void Scene::Draw(PictureBox^ pb, String^ name, float x, float y)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name && !f->IsHidden)
        {
            f->Draw(_scene.graphics, x, y);
        }
    }

    pb->Image = _scene.bitmap;
}

void Scene::ChangeFiguresColor(String^ name, Color color)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            f->ChangeColor(color);
    }
}

void Scene::HideFigure(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            f->IsHidden = !f->IsHidden;
    }
}

void Scene::Move(String^ name, float x, float y)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name) 
        {
            f->Move(x, y, _scene.bitmap->Width, _scene.bitmap->Height);
        }
    } 
}

void Scene::Reset(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            f->Reset();
    }
}

bool Scene::IsBorder(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            return f->CanMove(f, f->AutoCoef, 0.0, _scene.bitmap->Width, _scene.bitmap->Height);
    }

    return false;
}

void Scene::ChangeAutoCoef(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            f->ChangeAutoCoef();
    }

}

float Scene::GetAutoCoef(String^ name)
{
    for each (Figure ^ f in _scene.figures)
    {
        if (f->Name == name)
            return f->AutoCoef;
    }

    return 5.0f;
}

bool Scene::Influence(String^ name)
{
    int currIndex = GetFigureIndex(name);
    for (int i = 0; i < _scene.figures->Count; i++)
    {
        if (currIndex != i)
        {
            if (_scene.figures[i]->MaxY() > _scene.figures[currIndex]->MinY() &&
                _scene.figures[i]->MinY() < _scene.figures[currIndex]->MaxY() &&
                _scene.figures[i]->MinX() < _scene.figures[currIndex]->MaxX() &&
                _scene.figures[i]->MaxX() > _scene.figures[currIndex]->MinX()) 
            {
                return true;
            }
        }
    }

    return false;
}

int Scene::GetFigureIndex(String^ name)
{
    for (int i = 0; i < _scene.figures->Count; i++)
    {
        if (_scene.figures[i]->Name == name)
            return i;
    }

    return 0;
}


FigureMemento^ Scene::CreateMemento()
{
    return gcnew FigureMemento(figures);
}

void Scene::Restore(FigureMemento^ memento)
{
    figures = memento->GetFigures();
}

List<String^>^ Scene::GetFigureNames()
{
    List<String^>^ names = gcnew List<String^>();
    for each (Figure ^ f in _scene.figures)
    {
        names->Add(f->Name);
    }

    return names;
}




