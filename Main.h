//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "CPort.hpp"
#include <Chart.hpp>
#include <DbChart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTreeView *TreeView1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TComPort *ComPort1;
        TButton *Button1;
        TLabel *Label1;
        TDateTimePicker *DateTimePicker1;
        TButton *Button2;
        TMenuItem *N4;
        TDBChart *DBChart1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TRichEdit *RichEdit1;
        TTabSheet *TabSheet5;
        TMenuItem *N8;
        TButton *Button3;
        TValueListEditor *ValueListEditor1;
        TEdit *Edit1;
        TLabel *Label2;
        TButton *Button4;
        void __fastcall N4Click(TObject *Sender);
        void __fastcall TreeView1Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall ComPort1RxChar(TObject *Sender, int Count);
        void __fastcall ComPort1Rx80Full(TObject *Sender);
private:	// User declarations
public:		// User declarations

struct set_stable_constants_t  //  36 байт
{							   ////константы на время жизни счетчика
   unsigned char DeviceType[8];	       //  тип прибора  +3
   unsigned long SerialNumber;           //  заводской номер  +6
   unsigned char DateRelise[7];	       //  дата выпуска
   unsigned long CrystalFric;			   //  частота кварцевого резонатора *10
   unsigned char GUID[8];                //  guid счетчика
   unsigned char Reserved[5];            //  резерв
};
struct set_stable_constants_T  //  37 байт
{							   ////константы на время жизни счетчика
   unsigned char DeviceType[8];	       //  тип прибора  +3
   unsigned char ZavNum[4];              //  заводской номер  +6
   unsigned char DateRelise[7];	       //  дата выпуска
   unsigned char CrystalFric[4];	       //  частота кварцевого резонатора *10
   unsigned char GUID[8];                //  guid счетчика
   unsigned char Reserved[6];            //  резерв
};


 struct My_Meter
{
   unsigned int NetAdres;           //  сетевой адрес
   unsigned int SpeedRS485;	       //  Скорость подключения
  // unsigned char Ktvolt[2];		   //   коэфициэнт трансформации напряжения
  // unsigned char Ktamper[2];		   //   коэффициэнт трансформации тока
   unsigned int IndexTree;             //   индекс
  // My_Meter(unsigned char s1[2] ,unsigned char s2 );
}  Meter[2];
// My_Meter;//={{{52,0x00},2,{0x01,0},{0x01,0},{0x02,0}},
                   // {{76,0x00},2,{0x01,0},{0x01,0},{0x03,0}}};



        __fastcall TForm1(TComponent* Owner);
        unsigned short CRC16b(unsigned char *, int);   //   Chek sum

        bool DecodeInBuffer();   //   true - if decode is right, else - false
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
