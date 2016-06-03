//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Main.h"
#include "About_program.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma resource "*.dfm"
AnsiString dir = GetCurrentDir();

TForm1 *Form1;
unsigned char ReadInfo[] ={0x07, 0x34, 0x00, 0x00, 0x00, 0xBB, 0xF0 } ;

TIniFile *Ini = new TIniFile( dir + "/meters.ini");
int count_meters=0;

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
unsigned  int  IndexTree;
  PageControl1->ActivePage= TabSheet5 ;

   IndexTree= TreeView1->Selected->AbsoluteIndex;
 for(int i=0; i< count_meters ;i++)
 { if(IndexTree == Meter[i].IndexTree)
     Edit1->Text= IntToStr(Meter[i].NetAdres);
      //ShowMessage("Win" + IntToStr(Meter[i].NetAdres));
      //  ShowMessage(IntToStr( ((Meter[0].NetAdres[1]&0x3f)<<8) + Meter[0].NetAdres[0] ));

 }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  ValueListEditor1->Cells[1][1]="7009"  ;
  dir = GetCurrentDir();
  ComPort1->LoadSettings(stIniFile, dir + "\\PortSettings.ini");
 ComPort1->Open();
 //ComPort1->Write("00",1) ;
 ComPort1->Write(ReadInfo,sizeof(ReadInfo)) ;
// new_paket=true;
// Timer1->Enabled=true;
 //Timer2->Enabled=true;
// Button3->Enabled=false;
//ComPort1->Close();


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
//***** Initialization meters from file meters.ini******************************
count_meters = Ini->ReadInteger("Count_meters","Count",0);

 for( int i=0; i<count_meters;i++)
 {
 Meter[i].NetAdres= Ini->ReadInteger("meter"+IntToStr(i+1),"NetAdres",0);
 Meter[i].SpeedRS485 = Ini->ReadInteger("meter"+IntToStr(i+1),"SpeedRS485",0);
 Meter[i].IndexTree = Ini->ReadInteger("meter"+IntToStr(i+1),"IndexTree",0);
  }

// ShowMessage(IntToStr( Meter[0].NetAdres ));
 // ShowMessage(IntToStr( Meter[1].NetAdres ));
  //   Meter[0].NetAdres[1]= 0;
 //    Meter[0].SpeedRS485=5;
// My_Meter Meter2={};
//ShowMessage(IntToStr( ((Meter[0].NetAdres[1]&0x3f)<<8) + Meter[0].NetAdres[0] ));
//ShowMessage(IntToStr(Meter[0].SpeedRS485 ) );
//ShowMessage(IntToStr(Meter[0].Ktvolt) );
//ShowMessage(IntToStr(Meter[0].Ktamper) );
//ShowMessage(IntToStr(Meter[0].IndexTree[0]+Meter[0].IndexTree[1]) );

//***** End initialization meters from file meters.ini******************************
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)   // click "about program"
{
Form2->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender)  // Click "Settings Comport"
{
     dir = GetCurrentDir();
     ComPort1->LoadSettings(stIniFile, dir + "\\PortSettings.ini");
     ComPort1->ShowSetupDialog();
     ComPort1->StoreSettings(stIniFile, dir + "\\PortSettings.ini");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 unsigned int newadres=0;
 bool flag_ismeter=false;

 newadres=StrToInt(Edit1->Text);
 if ( (0 < newadres) && (newadres < 255))
 {  for(int i=0; i< count_meters ;i++)
     { if(unsigned(TreeView1->Selected->AbsoluteIndex) == Meter[i].IndexTree)
        {
         Ini->WriteInteger("meter"+IntToStr(i+1),"NetAdres",newadres );
         Meter[i].NetAdres= Ini->ReadInteger("meter"+IntToStr(i+1),"NetAdres",0 );
         ShowMessage("Адрес " + IntToStr(newadres) + " успешно сохранен." );
         flag_ismeter=true;
        }
      }
 }
 else
 {
 ShowMessage("Не верный формат адреса!");
 }
 if(flag_ismeter==false)
 {
  ShowMessage("Выбирите конкретный счетчик!");
 }
 else  flag_ismeter=false ;


}
//---------------------------------------------------------------------------


