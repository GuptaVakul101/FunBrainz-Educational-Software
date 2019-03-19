#pragma once
#include<vector>
#include<ctime>
#include "HintForm.h"
namespace FunBrainz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Image_Quiz_Display
	/// </summary>
	public ref class Image_Quiz_Display : public System::Windows::Forms::Form
	{
	public:
		Image_Quiz_Display(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Image_Quiz_Display()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  PB_Quiz_Image;
	private: System::Windows::Forms::Button^  btnNext;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btn_submit;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PB_Quiz_Image = (gcnew System::Windows::Forms::PictureBox());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PB_Quiz_Image))->BeginInit();
			this->SuspendLayout();
			// 
			// PB_Quiz_Image
			// 
			this->PB_Quiz_Image->Location = System::Drawing::Point(260, 10);
			this->PB_Quiz_Image->Margin = System::Windows::Forms::Padding(2);
			this->PB_Quiz_Image->Name = L"PB_Quiz_Image";
			this->PB_Quiz_Image->Size = System::Drawing::Size(237, 188);
			this->PB_Quiz_Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PB_Quiz_Image->TabIndex = 0;
			this->PB_Quiz_Image->TabStop = false;
			// 
			// btnNext
			// 
			this->btnNext->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnNext->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->btnNext->Location = System::Drawing::Point(601, 26);
			this->btnNext->Margin = System::Windows::Forms::Padding(2);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(79, 72);
			this->btnNext->TabIndex = 1;
			this->btnNext->Text = L"NEXT";
			this->btnNext->UseVisualStyleBackColor = false;
			this->btnNext->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btnNext_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 10);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Animal";
			// 
			// btn_submit
			// 
			this->btn_submit->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_submit->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->btn_submit->Location = System::Drawing::Point(601, 126);
			this->btn_submit->Margin = System::Windows::Forms::Padding(2);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(79, 72);
			this->btn_submit->TabIndex = 3;
			this->btn_submit->Text = L"SUBMIT";
			this->btn_submit->UseVisualStyleBackColor = false;
			this->btn_submit->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btn_submit_Click);
			// 
			// Image_Quiz_Display
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 586);
			this->Controls->Add(this->btn_submit);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->PB_Quiz_Image);
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Image_Quiz_Display";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Image_Quiz_Display";
			this->Load += gcnew System::EventHandler(this, &Image_Quiz_Display::Image_Quiz_Display_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Image_Quiz_Display::ImageQuiz_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Image_Quiz_Display::ImageQuiz_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PB_Quiz_Image))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		static array<String^>^ image_file_name = gcnew array<String^>(1000); //for file name
		static array<String^>^ image_name = gcnew array<String^>(1000); //for image name
		static array<bool>^ visited_image = gcnew array<bool>(1000); //boolean array to check if the image is already displayed
		static array<int>^ index_ans = gcnew array<int>(14); // for storing the index of the pressed char button 
		
		static int counter_image = 0;
		static int length_of_answer = 0;
		static int index_to_be_filled = 0;
	public:

		

		void button_creator(int x,int y,String^ s){
			Button^ var = gcnew Button();
			//var->BackColor = System::Drawing::SystemColors::ControlDarkDar/*k;
			//var->ForeColor = System::Drawing::SystemColors::ControlDark;*/
			var->Location = System::Drawing::Point(x, y);
			var->Name = s;			
			var->Size = System::Drawing::Size(45,45);
			var->TabIndex = 1;
			var->Text = "";
			var->UseVisualStyleBackColor = false;
			var->Enabled = false;
			this->Controls->Add(var);
		}
		void button_creator2(int x, int y){
			Button^ hint = gcnew Button();
			Button^ clear = gcnew Button();
			Button^ back = gcnew Button();

			hint->Location = System::Drawing::Point(x, y);
			hint->Name = L"hint";
			hint->Size = System::Drawing::Size(70, 45);
			hint->TabIndex = 1;
			hint->Text = "HINT";
			hint->UseVisualStyleBackColor = false;
			this->Controls->Add(hint);
			hint->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btnHint_Click);
			x = x + 75;

			clear->Location = System::Drawing::Point(x, y);
			clear->Name = L"clear";
			clear->Size = System::Drawing::Size(70,45);
			clear->TabIndex = 1;
			clear->Text = "clear";
			clear->UseVisualStyleBackColor = false;
			this->Controls->Add(clear);
			clear->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btnClear_Click);
			x = x + 75;

			back->Location = System::Drawing::Point(x, y);
			back->Name = L"back";
			back->Size = System::Drawing::Size(70,45);
			back->TabIndex = 1;
			back->Text = "back";
			back->UseVisualStyleBackColor = false;
			this->Controls->Add(back);
			back->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btnBack_Click);
		}

		private: System::Void btnHint_Click(System::Object^  sender, System::EventArgs^  e){
					 HintForm^ form = gcnew HintForm;
					 form->ShowDialog();
		}
		
		//HINT functions

		 void Random_letter()
		{
			 Control^ btn_clear = this->Controls[L"clear"];
			 ((Button^)btn_clear)->PerformClick();

			 int randomindex = rand() % length_of_answer;
			 String^ actual_ans = PB_Quiz_Image->Name->ToUpper();
			 actual_ans= actual_ans->Replace(" ","");
			 Char^ dum = actual_ans[randomindex];
			 String^ access_char = System::Convert::ToString(dum);
			 for(int i=0;i<14;i++)
			 {
				 Control^ curr_btn = this->Controls[System::Convert::ToString(100+i)];
				 if(curr_btn->Text == access_char)
				 {
					 ((Button^)curr_btn)->PerformClick();
					 break;
				 }
			 }
		}


		private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e){
			for (int i=0;i<index_to_be_filled;i++)
			{
				Control^ btn_to_remove = this->Controls[System::Convert::ToString(i)];
				btn_to_remove->Text="";
			}

			for (int i=0;i<index_to_be_filled;i++)
			{
				Control^ btn_to_enable = this->Controls[System::Convert::ToString(index_ans[i])];
				btn_to_enable->Enabled=true;
			}
			index_to_be_filled=0;
		}

		private: System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e){
			if (index_to_be_filled==0)
			{
				MessageBox::Show("can't back");
				return;
			}
			Control^ btn_to_remove = this->Controls[System::Convert::ToString(--index_to_be_filled)];
			btn_to_remove->Text="";

			Control^ btn_to_enable = this->Controls[System::Convert::ToString(index_ans[index_to_be_filled])];
			btn_to_enable->Enabled=true;
		}

		void button_creator3(int x, int y,Char^ s,int i)
		{
			String^ dum2 = System::Convert::ToString(100+i);
			Button^ var = gcnew Button();
			//var->BackColor = System::Drawing::SystemColors::ControlDarkDar/*k;
			//var->ForeColor = System::Drawing::SystemColors::ControlDark;*/
			var->Location = System::Drawing::Point(x, y);
			var->Name = dum2;
			var->Size = System::Drawing::Size(45, 45);
			var->TabIndex = 1;
			var->Text = System::Convert::ToString(s)->ToUpper();
			var->UseVisualStyleBackColor = false;
			var->Enabled = true;
			this->Controls->Add(var);
			var->Click += gcnew System::EventHandler(this, &Image_Quiz_Display::btnChar_Click);
			
		}

		private: System::Void btnChar_Click(System::Object^  sender, System::EventArgs^  e){
			if (index_to_be_filled == length_of_answer)
			{
				MessageBox::Show("Can't Filled further");
				return;
			}
			Button^ btn = ((Button^)sender);
			index_ans[index_to_be_filled]= System::Int64::Parse(btn->Name);
			Control^ random = this->Controls[System::Convert::ToString(index_to_be_filled++)];
			btn->Enabled = false;
			random->Text = btn->Text;
		}

		void refresh_image(){
			index_to_be_filled=0;
			length_of_answer=0;

			Image ^image1;
			int random_index;
			int flag = 0;
			for (int i = 0; i < counter_image; i++){
				if (visited_image[i] == false){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				//to do
				return;
			}
			while (1){
				random_index = rand() % counter_image;
				if (visited_image[random_index] == false){
					visited_image[random_index] = true;
					break;
				}
			}
			String ^ str = "media\\" + image_file_name[random_index];
			image1 = gcnew Bitmap(str);
			PB_Quiz_Image->Image = image1;
			PB_Quiz_Image->Name = image_name[random_index];
			
			String^ dummy = image_name[random_index];
			int x = (0.5)*(768 - (dummy->Length)*(45) - (5)*(dummy->Length-1));
			int y = 250;

			for (int i = 0; i < dummy->Length; i++){
				if (dummy[i] == L' '){
					x = x + 50;
					continue;
				}
				button_creator(x, y, length_of_answer.ToString());
				x = x + 50;
				length_of_answer++;
			}
			y = y + 60;
			x = (0.5)*(768 - (3)*(70) - (5)*(2));
			button_creator2(x, y);
			
			//every string is of length 1
			array<Char^>^ all_characters = gcnew array<Char^>(14);
			int count_charcters = 0;
			for (int i = 0; i < dummy->Length; i++)
			{
				if (dummy[i] == L' '){
					continue;
				}
				all_characters[count_charcters++] = dummy[i];
			}
			
			int upper_limit = 14 - count_charcters;
			for (int i = 0; i < upper_limit; i++)
			{
				int rand_no = rand() % 26;
				char dum = rand_no + 65;
				
				all_characters[count_charcters++] = System::Convert::ToChar(dum);
				
			}
			
			int visited_char[14] = { 0 };
			y = y + 60;
			x = (0.5)*(768 - (7)*(45) - (5)*(6));
			for (int i = 0; i < 7; i++)
			{
				int randNo;
				while (1)
				{
					randNo = rand() % 14;
					if (visited_char[randNo] == 0)
					{
						visited_char[randNo] = 1;
						break;
					}
				}
				
				
				button_creator3(x, y,all_characters[randNo],randNo);
				x += 50;
			}
			y += 60;
			x = (0.5)*(768 - (7)*(45) - (5)*(6));
			for (int i = 0; i < 7; i++)
			{
				int randNo;
				while (1)
				{
					randNo = rand() % 14;
					if (visited_char[randNo] == 0)
					{
						visited_char[randNo] = 1;
						break;
					}
				}
				visited_char[randNo] = 1;
				button_creator3(x, y, all_characters[randNo], randNo);
				x += 50;
			}

		}

	private: System::Void Image_Quiz_Display_Load(System::Object^  sender, System::EventArgs^  e) {
				 srand(time(0));
				 try {
					 OleDb::OleDbConnection ^ con = gcnew OleDb::OleDbConnection();
					 con->ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=FunBrainzForKids.accdb;";
					 String^ domain = "Camel";
					 String ^ Sql = "Select * from Image_Quiz_Display where [Domain] = '" + label1->Text + "';";
					 OleDb::OleDbCommand ^ command = gcnew OleDb::OleDbCommand(Sql, con);
					 con->Open();
					 //MessageBox::Show(command->ExecuteScalar()->ToString());
					 OleDb::OleDbDataReader ^ reader = command->ExecuteReader();
					 while (reader->Read()){
						 String^ dum =  reader[0]->ToString();
						 //int index = System::Int64::Parse(dum);
						 image_file_name[counter_image] = reader[2]->ToString();
						 image_name[counter_image] = reader[3] -> ToString();
						 visited_image[counter_image++] = false;

					 }
					 con->Close();
					 refresh_image();

				 }
				 catch (Exception ^ ex) {
					 MessageBox::Show(ex->Message);
				 }
	}
	private: System::Void btnNext_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 int count = 0;
				 Control^ rndom = this->Controls[L"1"];
				 Controls->Remove(rndom);
				 for (int i = 0; i < length_of_answer; i++)
				 {
					 String^ dum2 = System::Convert::ToString(i);
					 Control^ rndom = this->Controls[dum2];
					 Controls->Remove(rndom);
				 }

				 for (int i = 0; i < 14; i++)
				 {
					 String^ dum2 = System::Convert::ToString(100+i);
					 Control^ rndom = this->Controls[dum2];
					 Controls->Remove(rndom);
				 }
	

				 refresh_image();
	}
private: System::Void btn_submit_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ actual_ans = PB_Quiz_Image->Name->ToUpper();
			 actual_ans= actual_ans->Replace(" ","");
			 if (index_to_be_filled!=length_of_answer)
			 {
				 MessageBox::Show("You can't submit");
				 return;
			 }			 
			// MessageBox::Show(actual_ans->ToUpper());
			 String^ submitted_string = "";
			 for(int i=0;i<index_to_be_filled;i++)
			 {
				 Control^ btn_access = this->Controls[System::Convert::ToString(i)];
				 submitted_string+= btn_access->Text;
			 }
			 //MessageBox::Show(submitted_string);

			 if (submitted_string == actual_ans)
			 {
				 MessageBox::Show("Correct Answer!!");
				 btnNext->PerformClick();
			 }
			 else
			 {
				  MessageBox::Show("Incorrect Answer!!");
				  Control^ btn_clear = this->Controls[L"clear"];
				  ((Button^)btn_clear)->PerformClick();
			 }
		 }
private: System::Void ImageQuiz_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			// MessageBox::Show(System::Convert::ToString(e->KeyChar));
			 for (int i=0;i<14;i++)
			 {
				 Control^ curr_btn = this->Controls[System::Convert::ToString(100+i)];
				 if(curr_btn->Enabled == false)
				 {
					continue;
				 }
				 if (((Button^)curr_btn)->Text == (System::Convert::ToString(e->KeyChar)->ToUpper()))
				 {
					((Button^)curr_btn)->PerformClick();
					return;
				 }
			 }
		 }
private: System::Void ImageQuiz_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 //MessageBox::Show(System::Convert::ToString(e->KeyValue));
			 if (e->KeyValue == 8)
			 {
				 Control^ btn_back = this->Controls[L"back"];
				 ((Button^)btn_back)->PerformClick();
			 }
		 }
};
}