//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TreeView1Click(TObject *Sender)  // testing
{
 RichEdit1->Lines->Clear();
 RichEdit1->Lines->Add("������� TreeView1->Selected->Level: "+IntToStr(TreeView1->Selected->Level));
 int n = TreeView1->Selected->AbsoluteIndex;
 RichEdit1->Lines->Add("���������� ����� TreeView1->Selected->AbsoluteIndex: "+IntToStr(n));
 RichEdit1->Lines->Add("����� �� ���������� ����: "+TreeView1->Selected->Text);
  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
TreeView1->Selected->Delete() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
PageControl1->ActivePage= TabSheet5 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
ValueListEditor1->Cells[1][1]="7009"  ;
}
//---------------------------------------------------------------------------
