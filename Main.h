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
#include <Series.hpp>

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
#define BIT17   0x020000
#define BIT18   0x040000
#define BIT19   0x080000
#define BIT20   0x100000
#define BIT21   0x200000
#define BIT22   0x400000
#define BIT23   0x800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

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
        TLabel *Label1;
        TDateTimePicker *DateTimePicker1;
        TButton *Button2;
        TMenuItem *N4;
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
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox13;
        TCheckBox *CheckBox14;
        TCheckBox *CheckBox15;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TCheckBox *CheckBox18;
        TCheckBox *CheckBox19;
        TCheckBox *CheckBox20;
        TCheckBox *CheckBox21;
        TTimer *TimerTimeout;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TCheckBox *CheckBox9;
        TCheckBox *CheckBox10;
        TCheckBox *CheckBox11;
        TCheckBox *CheckBox12;
        TButton *Button1;
        TStringGrid *StringGrid1;
        TEdit *Edit2;
        TLabel *Label3;
        TStringGrid *StringGrid2;
        TButton *Button5;
        TChart *Chart1;
        TButton *Button6;
        TAreaSeries *Series1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TProgressBar *ProgressBar1;
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
        void __fastcall TimerTimeoutTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
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
}  Meter[3];
struct Energy_Day
{
 int kttv;
 int kttc;
 int energy_t;
 int energy_t1;
 int energy_t2;
 int energy_t3;
 int energy_t4;

} energy_day[32],energy_month[25];
// My_Meter;//={{{52,0x00},2,{0x01,0},{0x01,0},{0x02,0}},
                   // {{76,0x00},2,{0x01,0},{0x01,0},{0x03,0}}};



        __fastcall TForm1(TComponent* Owner);
        unsigned short CRC16b(unsigned char *, int);   //   Chek sum

        bool DecodeInBuffer();
        unsigned char GetCurrentNA();
        bool __fastcall ReadSysPar();                         //   true - if decode is right, else - false
        bool __fastcall Energy_begining_day(unsigned char);     //   true - if decode is right, else - false
        SendData(unsigned char, unsigned char, unsigned char);
        bool Energy_begining_month(unsigned char);   // IDP, IDR,NET_ADRESS
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
