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
// Note: Man verwendet '->' statt '.' um über einen Pointer auf elemente eines structs zuzugreifen. Das Bit hingegeben wird tatsächlich als 
// zwischenvariable geladen und daraus wiederum das BIT1 gezogen. 
bool Register1Bit1Value = IOREGISTER->IORegister1.bit.BIT1;


