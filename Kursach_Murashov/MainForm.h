#pragma once

#include <iostream>
#include <cliext/list>
#include "Scene.h"
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
#include "Polygon.h"
#include "Composite.h"
#include "FigureSaver.h";
#include "DefaultFigureFactory.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			scene = Scene::CreateScene(this->pictureBox1);
			fSaver = gcnew FigureSaver(scene, Directory::GetCurrentDirectory() + "\\figures.txt");
			this->BackgroundImage = Image::FromFile("fon.jpg");
			pictureBoxDrawCircle->BackgroundImage = Image::FromFile("circle.png");
			pictureBoxDrawSquare->BackgroundImage = Image::FromFile("sq.jpg");
			pictureBoxDrawTriangle->BackgroundImage = Image::FromFile("tr.png");
			pictureBoxShowHide->BackgroundImage = Image::FromFile("eye.png");
			pictureBoxChangeColor->BackgroundImage = Image::FromFile("edit.png");
			defFactory = gcnew DefaultFigureFactory();
			pictureBoxDefComp->BackgroundImage = Image::FromFile("comp.png");
			pictureBoxCircleNotDef->BackgroundImage = Image::FromFile("circle.png");
			pictureBoxSquareNotDef->BackgroundImage = Image::FromFile("sq.jpg");
			pictureBoxPolygonNotDef->BackgroundImage = Image::FromFile("tr.png");
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;




















	private: System::Windows::Forms::CheckedListBox^ checkedListBoxFigures;


	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ buttonAutoMove;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::CheckBox^ checkBoxTrace;
	private: System::Windows::Forms::Button^ buttonLeft;
	private: System::Windows::Forms::Button^ buttonRight;
	private: System::Windows::Forms::Button^ buttonDown;
	private: System::Windows::Forms::Button^ buttonUp;
	private: System::Windows::Forms::ColorDialog^ colorDialog;
	private: System::Windows::Forms::TextBox^ textBoxChangeColor;
	private: System::Windows::Forms::Label^ labelColor;
	private: System::Windows::Forms::Button^ buttonMerge;
	private: System::Windows::Forms::PictureBox^ pictureBoxShowHide;






	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::PictureBox^ pictureBoxChangeColor;

	private: System::Windows::Forms::PictureBox^ pictureBoxDrawCircle;

	private: System::Windows::Forms::PictureBox^ pictureBoxDrawSquare;
	private: System::Windows::Forms::PictureBox^ pictureBoxDrawTriangle;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonPaint;
	private: System::Windows::Forms::Button^ buttonRemove;




	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBoxCompositeName;
	private: System::Windows::Forms::Label^ label7;

	private: bool isAuto = false;
	private: FigureSaver^ fSaver;
	private: Scene^ scene;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Button^ buttonLoad;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ pictureBoxDefComp;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::PictureBox^ pictureBoxPolygonNotDef;
	private: System::Windows::Forms::PictureBox^ pictureBoxSquareNotDef;
	private: System::Windows::Forms::PictureBox^ pictureBoxCircleNotDef;
private: System::Windows::Forms::TextBox^ textBoxCoord;

	private: DefaultFigureFactory^ defFactory;
	private: int count = 0;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkedListBoxFigures = (gcnew System::Windows::Forms::CheckedListBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonAutoMove = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->checkBoxTrace = (gcnew System::Windows::Forms::CheckBox());
			this->buttonLeft = (gcnew System::Windows::Forms::Button());
			this->buttonRight = (gcnew System::Windows::Forms::Button());
			this->buttonDown = (gcnew System::Windows::Forms::Button());
			this->buttonUp = (gcnew System::Windows::Forms::Button());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->textBoxChangeColor = (gcnew System::Windows::Forms::TextBox());
			this->labelColor = (gcnew System::Windows::Forms::Label());
			this->buttonMerge = (gcnew System::Windows::Forms::Button());
			this->pictureBoxShowHide = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxChangeColor = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDrawCircle = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDrawSquare = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDrawTriangle = (gcnew System::Windows::Forms::PictureBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonPaint = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxCompositeName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			this->pictureBoxDefComp = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxCoord = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxPolygonNotDef = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSquareNotDef = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxCircleNotDef = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowHide))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeColor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawCircle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawSquare))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawTriangle))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDefComp))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPolygonNotDef))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSquareNotDef))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCircleNotDef))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(296, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(617, 411);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// checkedListBoxFigures
			// 
			this->checkedListBoxFigures->FormattingEnabled = true;
			this->checkedListBoxFigures->Location = System::Drawing::Point(12, 24);
			this->checkedListBoxFigures->Name = L"checkedListBoxFigures";
			this->checkedListBoxFigures->Size = System::Drawing::Size(259, 276);
			this->checkedListBoxFigures->TabIndex = 14;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MediumPurple;
			this->panel3->Controls->Add(this->buttonAutoMove);
			this->panel3->Controls->Add(this->buttonReset);
			this->panel3->Controls->Add(this->checkBoxTrace);
			this->panel3->Controls->Add(this->buttonLeft);
			this->panel3->Controls->Add(this->buttonRight);
			this->panel3->Controls->Add(this->buttonDown);
			this->panel3->Controls->Add(this->buttonUp);
			this->panel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel3->Location = System::Drawing::Point(296, 525);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(617, 197);
			this->panel3->TabIndex = 15;
			// 
			// buttonAutoMove
			// 
			this->buttonAutoMove->Location = System::Drawing::Point(141, 27);
			this->buttonAutoMove->Name = L"buttonAutoMove";
			this->buttonAutoMove->Size = System::Drawing::Size(107, 44);
			this->buttonAutoMove->TabIndex = 22;
			this->buttonAutoMove->Text = L"Авто";
			this->buttonAutoMove->UseVisualStyleBackColor = true;
			this->buttonAutoMove->Click += gcnew System::EventHandler(this, &Form1::buttonAutoMove_Click);
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(15, 27);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(106, 44);
			this->buttonReset->TabIndex = 21;
			this->buttonReset->Text = L"Сброс";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Form1::buttonReset_Click);
			// 
			// checkBoxTrace
			// 
			this->checkBoxTrace->AutoSize = true;
			this->checkBoxTrace->Location = System::Drawing::Point(28, 120);
			this->checkBoxTrace->Name = L"checkBoxTrace";
			this->checkBoxTrace->Size = System::Drawing::Size(198, 30);
			this->checkBoxTrace->TabIndex = 20;
			this->checkBoxTrace->Text = L"Оставлять след";
			this->checkBoxTrace->UseVisualStyleBackColor = true;
			// 
			// buttonLeft
			// 
			this->buttonLeft->Location = System::Drawing::Point(255, 106);
			this->buttonLeft->Name = L"buttonLeft";
			this->buttonLeft->Size = System::Drawing::Size(106, 44);
			this->buttonLeft->TabIndex = 19;
			this->buttonLeft->Text = L"←";
			this->buttonLeft->UseVisualStyleBackColor = true;
			this->buttonLeft->Click += gcnew System::EventHandler(this, &Form1::buttonLeft_Click);
			// 
			// buttonRight
			// 
			this->buttonRight->Location = System::Drawing::Point(491, 106);
			this->buttonRight->Name = L"buttonRight";
			this->buttonRight->Size = System::Drawing::Size(106, 44);
			this->buttonRight->TabIndex = 18;
			this->buttonRight->Text = L"→";
			this->buttonRight->UseVisualStyleBackColor = true;
			this->buttonRight->Click += gcnew System::EventHandler(this, &Form1::buttonRight_Click);
			// 
			// buttonDown
			// 
			this->buttonDown->Location = System::Drawing::Point(379, 106);
			this->buttonDown->Name = L"buttonDown";
			this->buttonDown->Size = System::Drawing::Size(106, 44);
			this->buttonDown->TabIndex = 17;
			this->buttonDown->Text = L"↓";
			this->buttonDown->UseVisualStyleBackColor = true;
			this->buttonDown->Click += gcnew System::EventHandler(this, &Form1::buttonDown_Click);
			// 
			// buttonUp
			// 
			this->buttonUp->Location = System::Drawing::Point(379, 37);
			this->buttonUp->Name = L"buttonUp";
			this->buttonUp->Size = System::Drawing::Size(106, 44);
			this->buttonUp->TabIndex = 16;
			this->buttonUp->Text = L"↑";
			this->buttonUp->UseVisualStyleBackColor = true;
			this->buttonUp->Click += gcnew System::EventHandler(this, &Form1::buttonUp_Click);
			// 
			// textBoxChangeColor
			// 
			this->textBoxChangeColor->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->textBoxChangeColor->Location = System::Drawing::Point(100, 87);
			this->textBoxChangeColor->Name = L"textBoxChangeColor";
			this->textBoxChangeColor->Size = System::Drawing::Size(31, 28);
			this->textBoxChangeColor->TabIndex = 1;
			this->textBoxChangeColor->Click += gcnew System::EventHandler(this, &Form1::textBoxChangeColor_Click);
			// 
			// labelColor
			// 
			this->labelColor->AutoSize = true;
			this->labelColor->Location = System::Drawing::Point(35, 87);
			this->labelColor->Name = L"labelColor";
			this->labelColor->Size = System::Drawing::Size(59, 24);
			this->labelColor->TabIndex = 0;
			this->labelColor->Text = L"Цвет:";
			// 
			// buttonMerge
			// 
			this->buttonMerge->Location = System::Drawing::Point(31, 92);
			this->buttonMerge->Name = L"buttonMerge";
			this->buttonMerge->Size = System::Drawing::Size(193, 38);
			this->buttonMerge->TabIndex = 17;
			this->buttonMerge->Text = L"Соединить";
			this->buttonMerge->UseVisualStyleBackColor = true;
			this->buttonMerge->Click += gcnew System::EventHandler(this, &Form1::buttonMerge_Click);
			// 
			// pictureBoxShowHide
			// 
			this->pictureBoxShowHide->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxShowHide->Location = System::Drawing::Point(315, 44);
			this->pictureBoxShowHide->Name = L"pictureBoxShowHide";
			this->pictureBoxShowHide->Size = System::Drawing::Size(123, 97);
			this->pictureBoxShowHide->TabIndex = 21;
			this->pictureBoxShowHide->TabStop = false;
			this->pictureBoxShowHide->Click += gcnew System::EventHandler(this, &Form1::pictureBoxShowHide_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox3->Controls->Add(this->pictureBoxChangeColor);
			this->groupBox3->Controls->Add(this->pictureBoxShowHide);
			this->groupBox3->Controls->Add(this->labelColor);
			this->groupBox3->Controls->Add(this->textBoxChangeColor);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(930, 525);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(482, 197);
			this->groupBox3->TabIndex = 20;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Внешний вид";
			// 
			// pictureBoxChangeColor
			// 
			this->pictureBoxChangeColor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxChangeColor->Location = System::Drawing::Point(137, 75);
			this->pictureBoxChangeColor->Name = L"pictureBoxChangeColor";
			this->pictureBoxChangeColor->Size = System::Drawing::Size(41, 40);
			this->pictureBoxChangeColor->TabIndex = 22;
			this->pictureBoxChangeColor->TabStop = false;
			this->pictureBoxChangeColor->Click += gcnew System::EventHandler(this, &Form1::pictureBoxChangeColor_Click);
			// 
			// pictureBoxDrawCircle
			// 
			this->pictureBoxDrawCircle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxDrawCircle->Location = System::Drawing::Point(383, 447);
			this->pictureBoxDrawCircle->Name = L"pictureBoxDrawCircle";
			this->pictureBoxDrawCircle->Size = System::Drawing::Size(91, 72);
			this->pictureBoxDrawCircle->TabIndex = 21;
			this->pictureBoxDrawCircle->TabStop = false;
			this->pictureBoxDrawCircle->Click += gcnew System::EventHandler(this, &Form1::pictureBoxDrawCircle_Click);
			// 
			// pictureBoxDrawSquare
			// 
			this->pictureBoxDrawSquare->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxDrawSquare->Location = System::Drawing::Point(507, 447);
			this->pictureBoxDrawSquare->Name = L"pictureBoxDrawSquare";
			this->pictureBoxDrawSquare->Size = System::Drawing::Size(78, 72);
			this->pictureBoxDrawSquare->TabIndex = 22;
			this->pictureBoxDrawSquare->TabStop = false;
			this->pictureBoxDrawSquare->Click += gcnew System::EventHandler(this, &Form1::pictureBoxDrawSquare_Click);
			// 
			// pictureBoxDrawTriangle
			// 
			this->pictureBoxDrawTriangle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxDrawTriangle->Location = System::Drawing::Point(619, 447);
			this->pictureBoxDrawTriangle->Name = L"pictureBoxDrawTriangle";
			this->pictureBoxDrawTriangle->Size = System::Drawing::Size(78, 72);
			this->pictureBoxDrawTriangle->TabIndex = 23;
			this->pictureBoxDrawTriangle->TabStop = false;
			this->pictureBoxDrawTriangle->Click += gcnew System::EventHandler(this, &Form1::pictureBoxDrawTriangle_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(12, 602);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(259, 38);
			this->buttonClear->TabIndex = 24;
			this->buttonClear->Text = L"Очистить";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// buttonPaint
			// 
			this->buttonPaint->Location = System::Drawing::Point(12, 319);
			this->buttonPaint->Name = L"buttonPaint";
			this->buttonPaint->Size = System::Drawing::Size(259, 51);
			this->buttonPaint->TabIndex = 25;
			this->buttonPaint->Text = L"Нарисовать";
			this->buttonPaint->UseVisualStyleBackColor = true;
			this->buttonPaint->Click += gcnew System::EventHandler(this, &Form1::buttonPaint_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(12, 386);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(259, 49);
			this->buttonRemove->TabIndex = 26;
			this->buttonRemove->Text = L"Удалить";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &Form1::buttonRemove_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxCompositeName);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->buttonMerge);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(12, 452);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(259, 144);
			this->groupBox4->TabIndex = 27;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Агрегат";
			// 
			// textBoxCompositeName
			// 
			this->textBoxCompositeName->Location = System::Drawing::Point(64, 46);
			this->textBoxCompositeName->Name = L"textBoxCompositeName";
			this->textBoxCompositeName->Size = System::Drawing::Size(176, 28);
			this->textBoxCompositeName->TabIndex = 19;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 24);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Имя:";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(12, 643);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(259, 38);
			this->buttonSave->TabIndex = 28;
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->Location = System::Drawing::Point(12, 687);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(259, 38);
			this->buttonLoad->TabIndex = 29;
			this->buttonLoad->Text = L"Загрузить";
			this->buttonLoad->UseVisualStyleBackColor = true;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &Form1::buttonLoad_Click);
			// 
			// pictureBoxDefComp
			// 
			this->pictureBoxDefComp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxDefComp->Location = System::Drawing::Point(717, 447);
			this->pictureBoxDefComp->Name = L"pictureBoxDefComp";
			this->pictureBoxDefComp->Size = System::Drawing::Size(78, 72);
			this->pictureBoxDefComp->TabIndex = 30;
			this->pictureBoxDefComp->TabStop = false;
			this->pictureBoxDefComp->Click += gcnew System::EventHandler(this, &Form1::pictureBoxDefComp_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->groupBox1->Controls->Add(this->textBoxCoord);
			this->groupBox1->Controls->Add(this->pictureBoxPolygonNotDef);
			this->groupBox1->Controls->Add(this->pictureBoxSquareNotDef);
			this->groupBox1->Controls->Add(this->pictureBoxCircleNotDef);
			this->groupBox1->Location = System::Drawing::Point(941, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(471, 285);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Создать не по умолчанию";
			// 
			// textBoxCoord
			// 
			this->textBoxCoord->Location = System::Drawing::Point(28, 56);
			this->textBoxCoord->Name = L"textBoxCoord";
			this->textBoxCoord->Size = System::Drawing::Size(399, 22);
			this->textBoxCoord->TabIndex = 35;
			// 
			// pictureBoxPolygonNotDef
			// 
			this->pictureBoxPolygonNotDef->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxPolygonNotDef->Location = System::Drawing::Point(325, 107);
			this->pictureBoxPolygonNotDef->Name = L"pictureBoxPolygonNotDef";
			this->pictureBoxPolygonNotDef->Size = System::Drawing::Size(78, 72);
			this->pictureBoxPolygonNotDef->TabIndex = 33;
			this->pictureBoxPolygonNotDef->TabStop = false;
			this->pictureBoxPolygonNotDef->Click += gcnew System::EventHandler(this, &Form1::pictureBoxPolygonNotDef_Click);
			// 
			// pictureBoxSquareNotDef
			// 
			this->pictureBoxSquareNotDef->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxSquareNotDef->Location = System::Drawing::Point(213, 107);
			this->pictureBoxSquareNotDef->Name = L"pictureBoxSquareNotDef";
			this->pictureBoxSquareNotDef->Size = System::Drawing::Size(78, 72);
			this->pictureBoxSquareNotDef->TabIndex = 32;
			this->pictureBoxSquareNotDef->TabStop = false;
			this->pictureBoxSquareNotDef->Click += gcnew System::EventHandler(this, &Form1::pictureBoxSquareNotDef_Click);
			// 
			// pictureBoxCircleNotDef
			// 
			this->pictureBoxCircleNotDef->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBoxCircleNotDef->Location = System::Drawing::Point(89, 107);
			this->pictureBoxCircleNotDef->Name = L"pictureBoxCircleNotDef";
			this->pictureBoxCircleNotDef->Size = System::Drawing::Size(91, 72);
			this->pictureBoxCircleNotDef->TabIndex = 31;
			this->pictureBoxCircleNotDef->TabStop = false;
			this->pictureBoxCircleNotDef->Click += gcnew System::EventHandler(this, &Form1::pictureBoxCircleNotDef_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1424, 734);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBoxDefComp);
			this->Controls->Add(this->buttonLoad);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->buttonRemove);
			this->Controls->Add(this->buttonPaint);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->pictureBoxDrawTriangle);
			this->Controls->Add(this->pictureBoxDrawSquare);
			this->Controls->Add(this->pictureBoxDrawCircle);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->checkedListBoxFigures);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Painter";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxShowHide))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeColor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawCircle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawSquare))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDrawTriangle))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDefComp))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPolygonNotDef))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSquareNotDef))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCircleNotDef))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	//========================================
	//default buttons
	private: System::Void pictureBoxDrawCircle_Click(System::Object^ sender, System::EventArgs^ e) {		

		count++;
		Figure^ circle = defFactory->GetDefaultFigure(defFactory->CIRCLE_NAME);
		circle->Name += count;
		Scene::AddFigure(circle);

		checkedListBoxFigures->Items->Add(circle->Name);
		Scene::Draw(pictureBox1);
	}
	private: System::Void pictureBoxDrawSquare_Click(System::Object^ sender, System::EventArgs^ e) {

		count++;
		Figure^ square = defFactory->GetDefaultFigure(defFactory->SQUARE_NAME);
		square->Name += count;
		Scene::AddFigure(square);

		checkedListBoxFigures->Items->Add(square->Name);
		Scene::Draw(pictureBox1);
	}
	private: System::Void pictureBoxDrawTriangle_Click(System::Object^ sender, System::EventArgs^ e) {
		count++;
		Figure^ polygon = defFactory->GetDefaultFigure(defFactory->TRIANGLE_NAME);
		polygon->Name += count;
		Scene::AddFigure(polygon);

		checkedListBoxFigures->Items->Add(polygon->Name);
		Scene::Draw(pictureBox1);
	}
	//========================================

	//========================================
	//custom figures buttons
	//========================================
	
	//clear graphic
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Scene::Clear(pictureBox1);
	}
	//paint
	private: System::Void buttonPaint_Click(System::Object^ sender, System::EventArgs^ e) {
		if(!checkBoxTrace->Checked) Scene::Clear();
		for each(String^ name in checkedListBoxFigures->CheckedItems) 
		{
			Scene::Draw(pictureBox1, name);
		}
	}
	//remove figure	
	private: System::Void buttonRemove_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cliext::list<String^> str;
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::DeleteFigure(name);		
			str.push_front(name);
		}

		for each (String ^ name in str)
		{
			checkedListBoxFigures->Items->Remove(name);
		}

		Scene::Clear(pictureBox1);
		Scene::Draw(pictureBox1);
	}
	//merge
	private: System::Void buttonMerge_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		List<Figure^>^ figures = gcnew List<Figure^>;
		cliext::list<String^> strToDelete;
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Figure^ f = Scene::FindFigure(name);
			if (f != nullptr) {
				figures->Add(f);
				strToDelete.push_front(name);
			}
		}

		for each (String ^ name in strToDelete)
		{
			Scene::DeleteFigure(name);
			checkedListBoxFigures->Items->Remove(name);
		}

		Figure^ composite = gcnew Composite(textBoxCompositeName->Text, figures);
		Scene::AddFigure(composite);

		checkedListBoxFigures->Items->Add(composite->Name);
		Scene::Clear(pictureBox1);
		Scene::Draw(pictureBox1);
	}
	//change color
	private: System::Void pictureBoxChangeColor_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::ChangeFiguresColor(name, textBoxChangeColor->BackColor);
		}

		Scene::Draw(pictureBox1);
	}
	private: System::Void textBoxChangeColor_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog->ShowDialog();
		textBoxChangeColor->BackColor = colorDialog->Color;
	}
	private: System::Void pictureBoxShowHide_Click(System::Object^ sender, System::EventArgs^ e) {

		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::HideFigure(name);
		}

		if(!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonUp_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::Move(name,0.0,-5.0);
		}

		if(!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonDown_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::Move(name, 0.0, 5.0);
		}

		if(!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonRight_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::Move(name, 5.0, 0.0);
		}

		if(!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::Move(name, -5.0, 0.0);
		}

		if(!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			Scene::Reset(name);
		}

		if (!checkBoxTrace->Checked) Scene::Clear();
		Scene::Draw(pictureBox1);
	}
	private: System::Void buttonAutoMove_Click(System::Object^ sender, System::EventArgs^ e) {
		
		isAuto = !isAuto;
		if (isAuto)
		{
			timer->Start();
		}
		else
		{
			timer->Stop();
		}

	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {

		for each (String ^ name in checkedListBoxFigures->CheckedItems)
		{
			if (!Scene::IsBorder(name))
			{
				Scene::ChangeAutoCoef(name);
			}
			Scene::Move(name, Scene::GetAutoCoef(name), 0.0);

			if (!checkBoxTrace->Checked) Scene::Clear();
			Scene::Draw(pictureBox1, name);
		}
	}
	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		fSaver->Create();
	}
	private: System::Void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e) {
		fSaver->Undo();

		checkedListBoxFigures->Items->Clear();
		List<String^>^ names = scene->GetFigureNames();
		for (int i = 0; i < names->Count; i++)
		{
			checkedListBoxFigures->Items->Add(names[i]);
		}

		Scene::Draw(pictureBox1);
	}
	private: System::Void pictureBoxDefComp_Click(System::Object^ sender, System::EventArgs^ e) {

		count++;
		Figure^ comp = defFactory->GetDefaultFigure(defFactory->COMPOSITE_NAME);
		comp->Name += count;
		Scene::AddFigure(comp);

		checkedListBoxFigures->Items->Add(comp->Name);
		Scene::Draw(pictureBox1);
	}
	private: System::Void pictureBoxCircleNotDef_Click(System::Object^ sender, System::EventArgs^ e) {
		count++;
		Figure^ circle = defFactory->GetDefaultFigure(defFactory->CIRCLE_NAME);
		circle->Name += count;

		List<Point>^ points = gcnew List<Point>;

		for each (String ^ coords in textBoxCoord->Text->Split({ ' ' }))
		{
			if (coords != "") 
			{
				cli::array<String^>^ coordXY = coords->Split({ ',' });

				Point point(Convert::ToSingle(coordXY[0]), Convert::ToSingle(coordXY[1]));
				points->Add(point);
			}
		}
		Scene::AddFigure(circle);

		checkedListBoxFigures->Items->Add(circle->Name);
		Scene::Draw(pictureBox1,circle->Name, points[0].X, points[0].Y);
	}
	private: System::Void pictureBoxSquareNotDef_Click(System::Object^ sender, System::EventArgs^ e) {
		count++;
		Figure^ square = defFactory->GetDefaultFigure(defFactory->SQUARE_NAME);
		square->Name += count;

		List<Point>^ points = gcnew List<Point>;

		for each (String ^ coords in textBoxCoord->Text->Split({ ' ' }))
		{
			if (coords != "")
			{
				cli::array<String^>^ coordXY = coords->Split({ ',' });

				Point point(Convert::ToSingle(coordXY[0]), Convert::ToSingle(coordXY[1]));
				points->Add(point);
			}
		}

		Scene::AddFigure(square);

		checkedListBoxFigures->Items->Add(square->Name);
		Scene::Draw(pictureBox1, square->Name, points[0].X, points[0].Y);
	}
	private: System::Void pictureBoxPolygonNotDef_Click(System::Object^ sender, System::EventArgs^ e) {
		count++;
		Figure^ polygon = defFactory->GetDefaultFigure(defFactory->TRIANGLE_NAME);
		polygon->Name += count;

		List<Point>^ points = gcnew List<Point>;

		for each (String ^ coords in textBoxCoord->Text->Split({ ' ' }))
		{
			if (coords != "")
			{
				cli::array<String^>^ coordXY = coords->Split({ ',' });

				Point point(Convert::ToSingle(coordXY[0]), Convert::ToSingle(coordXY[1]));
				points->Add(point);
			}
		}

		Scene::AddFigure(polygon);

		checkedListBoxFigures->Items->Add(polygon->Name);
		Scene::Draw(pictureBox1, polygon->Name, points[0].X, points[0].Y);
	}
};
}
