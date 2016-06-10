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

#define BIT0    0x01
#define BIT1    0x02
#define BIT2    0x04
#define BIT3    0x08
#define BIT4    0x10
#define BIT5    0x20
#define BIT6    0x40
#define BIT7    0x80
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000
#define BIT16   0x010000
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
        TTimer *Timer1;
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
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations

struct set_stable_constants_t  //  36 ����
{							   ////��������� �� ����� ����� ��������
   unsigned char DeviceType[8];	       //  ��� �������  +3
   unsigned long SerialNumber;           //  ��������� �����  +6
   unsigned char DateRelise[7];	       //  ���� �������
   unsigned long CrystalFric;			   //  ������� ���������� ���������� *10
   unsigned char GUID[8];                //  guid ��������
   unsigned char Reserved[5];            //  ������
};
struct set_stable_constants_T  //  37 ����
{							   ////��������� �� ����� ����� ��������
   unsigned char DeviceType[8];	       //  ��� �������  +3
   unsigned char ZavNum[4];              //  ��������� �����  +6
   unsigned char DateRelise[7];	       //  ���� �������
   unsigned char CrystalFric[4];	       //  ������� ���������� ���������� *10
   unsigned char GUID[8];                //  guid ��������
   unsigned char Reserved[6];            //  ������
};


 struct My_Meter
{
   unsigned int NetAdres;           //  ������� �����
   unsigned int SpeedRS485;	       //  �������� �����������
  // unsigned char Ktvolt[2];		   //   ���������� ������������� ����������
  // unsigned char Ktamper[2];		   //   ����������� ������������� ����
   unsigned int IndexTree;             //   ������
  // My_Meter(unsigned char s1[2] ,unsigned char s2 );
}  Meter[2];
// My_Meter;//={{{52,0x00},2,{0x01,0},{0x01,0},{0x02,0}},
                   // {{76,0x00},2,{0x01,0},{0x01,0},{0x03,0}}};



        __fastcall TForm1(TComponent* Owner);
        unsigned short CRC16b(unsigned char *, int);   //   Chek sum

        bool DecodeInBuffer();
        unsigned int GetCurrentNA();
        bool __fastcall ReadSysPar();   //   true - if decode is right, else - false
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
