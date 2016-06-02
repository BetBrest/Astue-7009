//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma resource "*.dfm"
TForm1 *Form1;

int ff;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
Form1->Close();

 //My_Meter Meter[2]={{{52,0x00},2,{0x01,0},{0x01,0},{0x02,0}},
        //            {{76,0x00},2,{0x01,0},{0x01,0},{0x03,0}}};
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TreeView1Click(TObject *Sender)  // testing
{
 RichEdit1->Lines->Clear();
 RichEdit1->Lines->Add("Уровень TreeView1->Selected->Level: "+IntToStr(TreeView1->Selected->Level));
 int n = TreeView1->Selected->AbsoluteIndex;
 RichEdit1->Lines->Add("Асболютный номер TreeView1->Selected->AbsoluteIndex: "+IntToStr(n));
 RichEdit1->Lines->Add("Текст из выбранного узла: "+TreeView1->Selected->Text);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
TreeView1->Selected->Delete() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
 int  IndexTree;
PageControl1->ActivePage= TabSheet5 ;

   IndexTree= TreeView1->Selected->AbsoluteIndex;
 for(int i=0; i<2;i++)
 { if(IndexTree == 2)
      ShowMessage("Win");
      //  ShowMessage(IntToStr( ((Meter[0].NetAdres[1]&0x3f)<<8) + Meter[0].NetAdres[0] ));

 }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
ValueListEditor1->Cells[1][1]="7009"  ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{    Meter[0].NetAdres[0]= 52;
     Meter[0].NetAdres[1]= 0;
     Meter[0].SpeedRS485=5;
// My_Meter Meter2={};
ShowMessage(IntToStr( ((Meter[0].NetAdres[1]&0x3f)<<8) + Meter[0].NetAdres[0] ));
ShowMessage(IntToStr(Meter[0].SpeedRS485 ) );
//ShowMessage(IntToStr(Meter[0].Ktvolt) );
//ShowMessage(IntToStr(Meter[0].Ktamper) );
//ShowMessage(IntToStr(Meter[0].IndexTree[0]+Meter[0].IndexTree[1]) );
}
//---------------------------------------------------------------------------

