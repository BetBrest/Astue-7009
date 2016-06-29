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
bool DataToGrid=false;
unsigned int read_byte; // the number of bits read from comport
unsigned char work_buffer[256];  //com buffers
unsigned int Packet_Send=0;

unsigned char IDP; //  request ID  1-byte
unsigned char IDR; //  additional  request 1-byte

Word  Year, Month, Day;
double days_between,Mounth_between;

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

     if (GetCurrentNA())
     {
      PageControl1->ActivePage= TabSheet5 ;
      Edit1->Text= IntToStr(GetCurrentNA());
     }
     else
     ShowMessage("Для получения инорфмации выберите счетчик !");
      
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//************** Clear ValueList Editor*****************************************
for (int i=1; i<12;i++)
ValueListEditor1->Cells[1][i]="" ;
//************** Clear ChekBox*****************************************
CheckBox1->Checked=false;
CheckBox2->Checked=false;
CheckBox3->Checked=false;
CheckBox4->Checked=false;
CheckBox5->Checked=false;
CheckBox6->Checked=false;
CheckBox7->Checked=false;
CheckBox8->Checked=false;
CheckBox9->Checked=false;
CheckBox10->Checked=false;
CheckBox11->Checked=false;
CheckBox12->Checked=false;
CheckBox13->Checked=false;
CheckBox14->Checked=false;
CheckBox15->Checked=false;
CheckBox16->Checked=false;
CheckBox17->Checked=false;
CheckBox18->Checked=false;
CheckBox19->Checked=false;
CheckBox20->Checked=false;
CheckBox21->Checked=false;

//******************************************************************************
 // ValueListEditor1->Cells[1][1]="7009"  ;
  dir = GetCurrentDir();
  ComPort1->LoadSettings(stIniFile, dir + "\\PortSettings.ini");
  ComPort1->Open();
 //ComPort1->Write("00",1) ;
//*************add NEt Adress to packet*****************************************

 if (GetCurrentNA())
 {
 ReadInfo[1]=GetCurrentNA();
 ReadInfo[2]=GetCurrentNA()>>8;
 ReadInfo[3]=0x00;
 ReadInfo[4]=0x00;
 //*************add CRC to packet*****************************************
 ReadInfo[5]=CRC16b(&ReadInfo[0],ReadInfo[0]-2);
 ReadInfo[6]=CRC16b(&ReadInfo[0],ReadInfo[0]-2)>>8;
 ComPort1->Write(ReadInfo,sizeof(ReadInfo)) ;
 Button3->Enabled=false;
 TimerTimeout->Enabled=true;
 }
   else
 ShowMessage("Для получения инорфмации выберите счетчик !");

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

//***** End initialization meters from file meters.ini******************************

//***** Set today time***********************************************************
DateTimePicker1->Date= Now();

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
   TimerTimeout->Enabled=false;
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

      if  ( (read_byte == work_buffer[0])&&(read_byte>=7))
      {
      // ShowMessage("Пакет принят");
        if(DecodeInBuffer())
        {
        // ShowMessage("Пакет разобран");
          new_paket = true;
          read_byte=0;
         Timer1->Enabled=true;
         if (Packet_Send)
         {
         Sleep(15);
         SendData(Packet_Send+int(days_between),10);
         ProgressBar1->Position= Day-Packet_Send;
         }
        }
        else
        {
      //  ShowMessage("Пакет не разобран");
        read_byte=0;
        Timer1->Enabled=true;
        }

      }

  

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


//***********  Check CRC *******************************************************
  if (!CRC16b(&work_buffer[0],work_buffer[0]))  ;
  else
  {
   ShowMessage("Ошибка контрольной суммы!!!" + IntToStr(CRC16b(&work_buffer[0],work_buffer[0]-2)));
  return false;
  }
//   ShowMessage(" контрольной суммы!!!" + IntToStr(CRC16b(&work_buffer[0],work_buffer[0]-2)));


//************** Chek Net Adress ***********************************************

 if (GetCurrentNA()==(((work_buffer[2]&0x3f)<<8) + work_buffer[1] ))
  {
     ValueListEditor1->Cells[1][11]=IntToStr(((work_buffer[2]&0x3f)<<8) + work_buffer[1] )  ;
  }
     else
  {
   ValueListEditor1->Cells[1][11]=IntToStr(((work_buffer[2]&0x3f)<<8) + work_buffer[1] )  ;
   ShowMessage("Не правильный сетевой адрес!!");
   return false;
  }

//*********Check IDP & IDR******************************************************
 IDP = work_buffer[3];
 IDR = work_buffer[4];
 switch (IDP)
 {case 1:  //  Read system parameters
  {
    switch (IDR)
    {
      case 0:  //  Read system parameters  of meters
      {
      if(ReadSysPar())
       break;
       else
       return false;
      }

      default:  //
      {
      ShowMessage("Неизвестный дополнительный идентефикатор пакета!");
      return false;
      }

     }

     break;
  }
  case 3:  // energy reading at the beginning of the day
  {
    if (IDR < 93)
    {
      if(!Energy_begining_day(IDR-int(days_between)))
      return false;
    }
      else
      {
      ShowMessage("Неизвестный дополнительный идентефикатор пакета!");
      return false;
      }



     break;
  }
  default:
  {
   ShowMessage("Неизвестный идентефикатор пакета!");
   return false;
  }
 }


   return true;
}

unsigned int TForm1::GetCurrentNA()
{
unsigned  int  IndexTree;
IndexTree= TreeView1->Selected->AbsoluteIndex;
 for(int i=0; i< count_meters ;i++)
 { if(IndexTree == Meter[i].IndexTree)
    return Meter[i].NetAdres;
 }
 return 0;
}

bool __fastcall TForm1::ReadSysPar()
{

 AnsiString InfoMeters="";
 AnsiString Ver_Protocol="";
 AnsiString Ver_Soft="";
 AnsiString Release_Date="";
 unsigned int Factory_Number=0;
 unsigned int Meter_Status=0;

 //************ Read Type of meters *********************************************
 if(work_buffer[5]=='C') // read character ID
 InfoMeters+="СЭТ-";
 else
 InfoMeters+="Unknow Type ";

 InfoMeters+=  IntToStr((work_buffer[6]<<8) + work_buffer[7]); //read number index
 InfoMeters+="      Класс точности: " ;

 InfoMeters+=  FloatToStr(float(work_buffer[8])/100) ; //read accuracy class

 InfoMeters+= "     (";
 InfoMeters+= IntToStr(work_buffer[9]); //read nominal current

 InfoMeters+= " - ";
 InfoMeters+= IntToStr(work_buffer[10]); //read max current
 InfoMeters+= ") A ";
 //read service function

  InfoMeters+= "  Сервисные фунции: ";
 if (work_buffer[11]&BIT7) InfoMeters+="A";
 else InfoMeters+=" ";
 if (work_buffer[11]&BIT6) InfoMeters+="R";
 else InfoMeters+=" ";
 InfoMeters+=" ";
 if (work_buffer[11]&BIT5) InfoMeters+="F";
 else InfoMeters+=" ";
 InfoMeters+=" ";
 if (work_buffer[11]&BIT4) InfoMeters+="R";
 else InfoMeters+=" ";
 if (work_buffer[11]&BIT3) InfoMeters+="J";
 else InfoMeters+=" ";
 InfoMeters+=" ";
 if (work_buffer[11]&BIT2) InfoMeters+="M";
 else InfoMeters+=" ";

 ValueListEditor1->Cells[1][1]= InfoMeters ;

//****** read factory number ***************************************************

 Factory_Number=(work_buffer[13]<<24)+(work_buffer[14]<<16)+(work_buffer[15]<<8)+work_buffer[16];
 ValueListEditor1->Cells[1][2]= Factory_Number ;

//****** read version protocol ***************************************************

 Ver_Protocol=  IntToStr(work_buffer[17]) + "." + IntToStr(work_buffer[18]) ;
 ValueListEditor1->Cells[1][3]= Ver_Protocol;

 //****** read version soft ***************************************************

 Ver_Soft=  IntToStr(work_buffer[19]) + "." + IntToStr(work_buffer[20]) ;
 ValueListEditor1->Cells[1][4]= Ver_Soft;

//****** read release date  ***************************************************

  Release_Date = IntToStr(work_buffer[21]) + "." + IntToStr(work_buffer[22]) + ".20" + IntToStr(work_buffer[23]) ;
  ValueListEditor1->Cells[1][5]= Release_Date;

//****** Count resets  ****************************************************

   ValueListEditor1->Cells[1][6]= IntToStr(work_buffer[61]);

//****** Count WDT ****************************************************

   ValueListEditor1->Cells[1][7]= IntToStr(work_buffer[63]);

//****** Count Errors ****************************************************

   ValueListEditor1->Cells[1][8]= IntToStr(work_buffer[66]);

//******  Battery Voltage****************************************************

   ValueListEditor1->Cells[1][9]= FloatToStr(float(work_buffer[69])/10);

//******  Working time in hours****************************************************

   ValueListEditor1->Cells[1][10]= IntToStr(((work_buffer[74]<<24)+(work_buffer[73]<<16)+(work_buffer[72]<<8)+work_buffer[71]));

//****** The  current meter status ****************************************************
//(byte[0]<<24)+(byte[1]<<16)+byte[2]<<8)+byte[3];
    Meter_Status = (work_buffer[48]<<24) + (work_buffer[49]<<16) + (work_buffer[50]<<8) + work_buffer[51];///
    if(Meter_Status & BIT0)
    CheckBox1->Checked = true;
    if(Meter_Status & BIT1)
    CheckBox2->Checked = true;
    if(Meter_Status & BIT2)
    CheckBox3->Checked = true;
    if(Meter_Status & BIT3)
    CheckBox4->Checked = true;
    if(Meter_Status & BIT4)
    CheckBox19->Checked = true;
    if(Meter_Status & BIT5)
    CheckBox5->Checked = true;
    if(Meter_Status & BIT6)
    CheckBox6->Checked = true;
    if(Meter_Status & BIT7)
    CheckBox7->Checked = true;
    if(Meter_Status & BIT8)
    CheckBox8->Checked = true;
    if(Meter_Status & BIT9)
    CheckBox9->Checked = true;
    if(Meter_Status & BIT10)
    CheckBox10->Checked = true;
    if(Meter_Status & BIT11)
    CheckBox11->Checked = true;
    if(Meter_Status & BIT14)
    CheckBox12->Checked = true;
    if(Meter_Status & BIT15)
    CheckBox13->Checked = true;
    if(Meter_Status & BIT16)
    CheckBox14->Checked = true;
    if(Meter_Status & BIT17)
    CheckBox15->Checked = true;
    if(Meter_Status & BIT20)
    CheckBox16->Checked = true;
    if(Meter_Status & BIT21)
    CheckBox17->Checked = true;
    if(Meter_Status & BIT25)
    CheckBox18->Checked = true;
    if(Meter_Status & BIT26)
    CheckBox20->Checked = true;
    if(Meter_Status & BIT27)
    CheckBox21->Checked = true;



return true;
}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
float sum_energy=0, sum_money=0;
Timer1->Enabled=false;
ComPort1->Close();
Button3->Enabled=true; ///
 if(DataToGrid==true)
{
  DataToGrid=false;
  Day--;
  for (int i=0; i<Day; i++)
  {
    StringGrid1->Cells[1][Day-i]= float(energy_day[i].energy_t)/10000;
    StringGrid1->Cells[2][Day-i]= float(energy_day[i].energy_t1)/10000;
    StringGrid1->Cells[3][Day-i]= float(energy_day[i].energy_t2)/10000;
    StringGrid1->Cells[4][Day-i]= float(energy_day[i].energy_t3)/10000;
    StringGrid1->Cells[5][Day-i]= float(energy_day[i].energy_t4)/10000;
    StringGrid1->Cells[6][Day-i]= (float(energy_day[i].energy_t - energy_day[i+1].energy_t))/10000;
    StringGrid1->Cells[7][Day-i]= ((float(energy_day[i].energy_t - energy_day[i+1].energy_t))/10000)*energy_day[i].kttv*energy_day[i].kttc;
    StringGrid1->Cells[8][Day-i]= StringGrid1->Cells[7][Day-i] * Edit2->Text;
    sum_energy = sum_energy + ((float(energy_day[i].energy_t - energy_day[i+1].energy_t))/10000)*energy_day[i].kttv*energy_day[i].kttc;
    sum_money= sum_money  + StringGrid1->Cells[7][Day-i] * Edit2->Text;
  }

    StringGrid1->Cells[0][Day+2]="ИТОГО:"  ;
    StringGrid1->Cells[7][Day+2]=FloatToStrF(sum_energy, ffFixed,10,2)  ;
    StringGrid1->Cells[8][Day+2]=FloatToStrF(sum_money, ffFixed,10,0)  ;
    ProgressBar1->Position=0;




}








}
//---------------------------------------------------------------------------



void __fastcall TForm1::TimerTimeoutTimer(TObject *Sender)
{
TimerTimeout->Enabled=false;
ShowMessage("Счетчик не отвечает!");
ComPort1->Close();
Button3->Enabled=true;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
TDateTime DayBilling, DayToday=Now();

Word  Year2, Month2, Day2;

ProgressBar1->Position=0;
//***************Get a date and chek it**************************
DayBilling=DateTimePicker1->Date;
DecodeDate(DayBilling, Year, Month, Day); Day++;
DecodeDate(DayToday, Year2, Month2, Day2);
days_between = (double)(DayToday - DayBilling );

 if (days_between < 0) //check the date not earlie today
 {
  ShowMessage("Выберите дату не ранее сегодняшнего дня");
  return;
 }

 if ((days_between > 93)  || ((Month2-Month )>= 3)  ) //check the date not older than 3 Months
 {
  ShowMessage("Выберите дату не позднее трех месяцев");
  return;
 }

//************Clear Grid*******************************************************
for (int i=0;i<StringGrid1->ColCount; i++)
 StringGrid1->Cols[i]->Clear();
///*************init string grid and filling first column************************************************
StringGrid1->Cells[0][0]="Дата";
StringGrid1->Cells[1][0]="Показания общие";
StringGrid1->Cells[2][0]="Тариф Т1";
StringGrid1->Cells[3][0]="Тариф Т2";
StringGrid1->Cells[4][0]="Тариф Т3";
StringGrid1->Cells[5][0]="Тариф Т4";
StringGrid1->Cells[6][0]="Приращение";
StringGrid1->Cells[7][0]="Приращение c коэф.тр";
StringGrid1->Cells[8][0]="Сумма";


 ProgressBar1->Max=Day-1;
 StringGrid1->Cells[0][Day-1]= DayBilling.DateString() ;
 for(int i=1; i< Day-1; i++)
  {
   DayBilling -= 1.0  ;
   StringGrid1->Cells[0][Day-i-1]= DayBilling.DateString() ;
   ProgressBar1->Position=i;
  // Sleep(100);

  }

  Packet_Send=Day;
//*************open port and send quest****************************************
  dir = GetCurrentDir();
  ComPort1->LoadSettings(stIniFile, dir + "\\PortSettings.ini");
  ComPort1->Open();
  // ShowMessage(int(days_between));
   SendData(int(days_between),10);



}
//---------------------------------------------------------------------------


bool __fastcall TForm1::Energy_begining_day(unsigned char i)
{

//****************Read transformation coefficients****************************
energy_day[i].kttv= (work_buffer[5]<<8)+ work_buffer[6];
energy_day[i].kttc= (work_buffer[7]<<8)+ work_buffer[8];
//****************Read Total Energy*******************************************
energy_day[i].energy_t=(work_buffer[9]<<24)+ (work_buffer[10]<<16)+ (work_buffer[11]<<8)+ work_buffer[12];
energy_day[i].energy_t1=(work_buffer[13]<<24)+ (work_buffer[14]<<16)+ (work_buffer[15]<<8)+ work_buffer[16];
energy_day[i].energy_t2=(work_buffer[17]<<24)+ (work_buffer[18]<<16)+ (work_buffer[19]<<8)+ work_buffer[20];
energy_day[i].energy_t3=(work_buffer[21]<<24)+ (work_buffer[22]<<16)+ (work_buffer[23]<<8)+ work_buffer[24];
energy_day[i].energy_t4=(work_buffer[25]<<24)+ (work_buffer[26]<<16)+ (work_buffer[27]<<8)+ work_buffer[28];

// ShowMessage(Energy_T);
return true;
}

TForm1::SendData(unsigned char i , int j)
{
  if (GetCurrentNA())
 {
 ReadInfo[1]=GetCurrentNA();
 ReadInfo[2]=GetCurrentNA()>>8;
 ReadInfo[3]=0x02;
 ReadInfo[4]= i;
 //*************add CRC to packet*****************************************
 ReadInfo[5]=CRC16b(&ReadInfo[0],ReadInfo[0]-2);
 ReadInfo[6]=CRC16b(&ReadInfo[0],ReadInfo[0]-2)>>8;
 ComPort1->Write(ReadInfo,sizeof(ReadInfo)) ;
 //Sleep(1000);
 TimerTimeout->Enabled=true;
 }
   else
 ShowMessage("Для получения инорфмации выберите счетчик !");       //TODO: Add your source code here
 Packet_Send--;
 if (!Packet_Send)
 DataToGrid=true;
 return true;
 }


void __fastcall TForm1::Button6Click(TObject *Sender)
{

Series1->Clear();
for (int i=1; i<=Day; i++)
{
Series1->AddXY(Day-i,(float(energy_day[i-1].energy_t- energy_day[i].energy_t)/10000)*energy_day[i].kttv*energy_day[i].kttc);
//ShowMessage((float(energy_day[i-1].energy_t- energy_day[i].energy_t)/10000)*energy_day[i].kttv*energy_day[i].kttc);
}
for (int i=Day; i<32; i++)
{
Series1->AddXY(i,0);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 TDateTime MonthBilling, DayToday=Now();

 Word  Year2, Month2, Day2;

//ProgressBar1->Position=0;
//***************Get a date and chek it**************************
MonthBilling=DateTimePicker1->Date;
DecodeDate(MonthBilling, Year, Month, Day); Day++;
DecodeDate(DayToday, Year2, Month2, Day2);
Mounth_between = (double)(DayToday - MonthBilling );

 if (Mounth_between < 0) //check the date not earlie today
 {
  ShowMessage("Выберите дату не ранее сегодняшнего дня");
  return;
 }

 //************Clear Grid*******************************************************
 for (int i=0;i<StringGrid2->ColCount; i++)
  StringGrid2->Cols[i]->Clear();
///*************init string grid and filling first column************************************************
 StringGrid2->Cells[0][0]="Дата";
 StringGrid2->Cells[1][0]="Показания общие";
 StringGrid2->Cells[2][0]="Тариф Т1";
 StringGrid2->Cells[3][0]="Тариф Т2";
 StringGrid2->Cells[4][0]="Тариф Т3";
 StringGrid2->Cells[5][0]="Тариф Т4";
 StringGrid2->Cells[6][0]="Приращение";
 StringGrid2->Cells[7][0]="Приращение c коэф.тр";
 StringGrid2->Cells[8][0]="Сумма";


 if(RadioButton1->Checked)  //if cheked with begin of year
 {
  if ((Year2-Year )> 0  ) //check the date in this year
  {
   ShowMessage("Выберите дату в этом году!" );
   return;
  }

   Mounth_between= Month;

   for(int i=0; i< Month; i++)
   {
    StringGrid2->Cells[0][Month-i]=  EncodeDate(Year, Month-i, 1).DateString() ;
   }
 }

  if(RadioButton2->Checked)  //if cheked with begin of last year
  {
    if ((Year2-Year )!=1  ) //check the date in this year
   {
    ShowMessage("Выберите дату за прошлый год!" );
    return;
   }

    Mounth_between= Month;

   for(int i=0; i< Month; i++)
   {
    StringGrid2->Cells[0][Month-i]=  EncodeDate(Year, Month-i, 1).DateString() ;
   }

  }

    if(RadioButton3->Checked)  //if cheked with begin of last year
  {
    Mounth_between= Month;
   int j=0;
   for(int i=0; i< 24; i++)
   {

     if ((Month-j)==0)
     {
      Year--;
      Month=12 ;
      j=0;

     }
    StringGrid2->Cells[0][24-i]=  EncodeDate(Year, Month-j, 1).DateString() ;
    j++;

   }

  }


/* ProgressBar1->Max=Day-1;
 StringGrid1->Cells[0][Day-1]= DayBilling.DateString() ;
 for(int i=1; i< Day-1; i++)
  {
   DayBilling -= 1.0  ;
   StringGrid1->Cells[0][Day-i-1]= DayBilling.DateString() ;
   ProgressBar1->Position=i;
  // Sleep(100);

  }

  Packet_Send=Day;
//*************open port and send quest****************************************
  dir = GetCurrentDir();
  ComPort1->LoadSettings(stIniFile, dir + "\\PortSettings.ini");
  ComPort1->Open();
  // ShowMessage(int(days_between));
   SendData(int(days_between),10);
                                    */

}
//---------------------------------------------------------------------------


