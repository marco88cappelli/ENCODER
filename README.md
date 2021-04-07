# ENCODER

#Questa libreria semplifica l'utilizzo dell'ENCODER.

La libreria all'evento di rotazione in avanti, idietro o pressione dell'ENCODER esegue 3 funzioni passate come puntatori.
la firma delle funzioni è la seguente:

typedef void(*funzione)();

per cui avremo 3 funzioni:
  1- Incremento;
  2- Decremento;
  3- Pulsante;
 
le funzioni della libreria sono le seguenti:
  1- void begin(int PIN_INCREMENTO, int PIN_DECREMENTO, int PIN_PULSANTE, funzione funIn, funzione funDec, funzione funPull = NULL, bool pullUpI = true , bool pullUpD = true, bool pullUpP = true, bool inversione = true);
  2- void controll_Encoder();
  3- void controll_Button();

La 1° funzione deve essere insetrita all'interno del setup e serve per inizializzare l'oggetto ENCODER, infatti definisce:
  - int PIN_INCREMENTO -> Rappresenta il PIN CLK dell'ENCODER
  - int PIN_DECREMENTO -> Rappresenta il PIN DX dell'ENCODER
  - int PIN_PULSANTE -> Rappresenta il PIN SW sempre dell'ENCODER.
  - funzione funIn -> funzione che viene eseguita quando si rileva la rotazione in senzo orario
  - funzione funDec -> funzione che viene eseguita quando si rileva la rotazione in senzo anti orario
  - funzione funPull -> funzione che viene eseguita alla pressione dello switch dell'ENCODER, di default è dichiarata NULL
  - pullUpI,pullUpD,pullUpP -> servono ad indicare se i pin CLK BX SW sono PullUp o meno. di default è TRUE
  - bool inversione = true -> serve ad invertire l'incremento dal decremento

Le ultime 2 funzioni servono per intercettare gli stati dell'ENCODER e attivare le rispettive funzioni.

Questa libreria per intercettare la rotazione dell'ENCODER non utilizza gli interrupt, per cui può capitare che su codici di grandi dimensioni possa saltare qualche passo.
