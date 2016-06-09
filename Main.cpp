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
bool new_paket=true;  //  read the new package from the port
bool Ready_to_start=false;//flag counter ready to set the time

unsigned int read_byte; // the number of bits read from comport
unsigned char in_buffer[256], out_buffer[256],work_buffer[256];  //com buffers



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
 // ValueListEditor1->Cells[1][1]="7009"  ;
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


void __fastcall TForm1::ComPort1RxChar(TObject *Sender, int Count)
{
    if (new_paket==true)
     {
     new_paket =false;
     read_byte=0;
     }

     if ((read_byte+Count)>250)
     {
     ComPort1->ClearBuffer(true, true);
     ShowMessage("Переполнение буффера");
     new_paket = true;

     return;
     }

     ComPort1->Read(&work_buffer[read_byte], Count);
     read_byte+=Count;

      if  ((unsigned (read_byte)==work_buffer[0])&&(read_byte>=7))
      {
      // ShowMessage("Пакет принят");
        if(DecodeInBuffer())
        {
       //  ShowMessage("Пакет разобран");
          read_byte=0;
        }
        else
        {
      //  ShowMessage("Пакет не разобран");
        }
      }

    /* if(work_buffer[0]==0x55 && Ready_to_start==true) // answer on  time request to wite
     {
     ComPort1->ClearBuffer(true, true);
  //   Clean_buf(work_buffer,256);
     //  ShowMessage("Yes");
    // Time_update=true;
     new_paket = true;
     Ready_to_start=false;
   //  ComPort1->Write(WriteTime,14);
       return;
     }  */


   /*  if(work_buffer[0]==0x55 && Time_update==true)  // answer on  time write request
     {
     ComPort1->ClearBuffer(true, true);
     Clean_buf(work_buffer,256);
     Time_update=false;
     Timer2->Enabled=false;
     ShowMessage("Время установлено!");
      Timer1->Enabled=true;
     new_paket = true;

       return;
     }   */

   /*  if (read_byte==9)   // answer on  time read request
     {
     if(work_buffer[7]==0x89)
     {
     //ShowMessage("Пакет  принят 89");
      if(MakeCRC(work_buffer,8)==work_buffer[8])
        {
         //ShowMessage(MakeCRC(work_buffer,8));
         memcpy(&in_buffer[0],&work_buffer[0],read_byte);
         packet_parsing(&in_buffer[0],read_byte);
         Timer2->Enabled=false;
         new_paket =true;
         }
        else  ShowMessage("Неправильная контрольная сумма пакета");
      }
      else ShowMessage("Неправильный формат пакета");

     }

     */

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComPort1Rx80Full(TObject *Sender)
{
 ComPort1->ClearBuffer(true, true);
}
//---------------------------------------------------------------------------


unsigned short TForm1::CRC16b(unsigned char *msg, int len)
{
    int i,j;
  unsigned char bute,check_flag;
  unsigned short CRC=0;

  for (j=0;j<len;j++)
  {
   bute=msg[j];
   for (i=0;i<8;i++)
   {
    check_flag=((bute^CRC)&0x01);
    CRC>>=1;
    bute>>=1;
    if (check_flag==1)CRC^=0xA001;
   }
  }
  return CRC;

}

bool TForm1::DecodeInBuffer()
{
  //  Check CRC
  if (!CRC16b(&work_buffer[0],work_buffer[0]))  ;
  else
  {
   ShowMessage("Ошибка контрольной суммы!!!");
   return false;
  }

  // ShowMessage("CRC in buuifer =" + IntToStr(work_buffer[read_byte-2]) + " " + IntToStr(work_buffer[read_byte-1]))  ;
  // ShowMessage("CRC after function  =" + IntToStr(CRC16b(&work_buffer[0],work_buffer[0])))  ;

  //

   return true;    //TODO: Add your source code here
}
