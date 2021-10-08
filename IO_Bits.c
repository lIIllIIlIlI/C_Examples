// Es braucht nur die Addresse und ein paar Bitoperationen um auf ein spezielles Bit des uC zuzugreifen. Es gibt vom Hersteller in der Regel in der Controller Header
// Header für den deutlich einfacheren Zugang. Beispiel:

// 1. Makro bereitstellen zum erstellen eines Pointers, der auf den Start eines bestimmten Registerblocks zeigt. Gleichzeitig zeigt
//    der Pointer auf eine Variable vom Typ IOREGISTER_Type. Über diesen Typ kann man anschließend den einfachen Zugriff realisieren.
#define IOREGISTER_BASE 0x502010000UL
#define IOREGISTER ((IOREGISTER_Type *) IOREGISTER_BASE)

// 2. Typedef anlegen, dieser wäre für eine definition viel zu groß, dies ist aber garnicht nötig. Man greift lediglich per Pointer auf 
//    den Typ zu. Dadurch erhält man den korrekten Offset sowohl innerhalb der Register wie auch innerhalb des ausgewählten Registers.
typedef struct { 
  union{
    uint reg;
    struct{
      uint8 BIT1: 1
      uint8 BIT2: 1
    } bit;
  } IORegister1;
    union{
    uint reg;
    struct{
      uint8 BIT1: 1
      uint8 BIT2: 1
    } bit;
  } IORegister2;
  ...
} IOREGISTER_Type;

// 3. Einfacher Zugriff aus dem User Code mit nur einer Zeile. 
// Note: '->var' ist die Kurzversion von '(*var).', IOREGISTER ist ein Pointer, er wird mit dem Operator dereferenziert um auf das Struct zugreifen zu können. 
bool Register1Bit1Value = IOREGISTER->IORegister1.bit.BIT1;


