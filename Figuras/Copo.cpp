#include "Copo.h"

/*********************************

	Copo

**********************************/

void Copo::preencherVertices(){
	this->revolutionSolid(x, y, this->pontos, this->fatias);
}

Copo::Copo(int tipo, int detalhe){
	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;
	if( this->fatias > 100 ) this->fatias = 100;

	int i=0;
	
	if( tipo == 1 ){ // copo simples
		this->pontos = 6;

		x[i++] = 0;
		x[i++] = 2;
		x[i++] = 2.5;
		x[i++] = 2.4;
		x[i++] = 1.9;
		x[i++] = 0;

		i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 5;
		y[i++] = 5;
		y[i++] = 0.1;
		y[i++] = 0.1;
	} else if( tipo == 2 ){ // champagne flute
		this->pontos = 41;
		
		x[i++] = 0; x[i++] = 37; x[i++] = 37; x[i++] = 28; x[i++] = 19;
		x[i++] = 11; x[i++] = 7; x[i++] = 5; x[i++] = 4; x[i++] = 4;
		x[i++] = 5; x[i++] = 8; x[i++] = 11; x[i++] = 14; x[i++] = 18;
		x[i++] = 21; x[i++] = 24; x[i++] = 26; x[i++] = 27; x[i++] = 27;
		x[i++] = 27; x[i++] = 27; x[i++] = 26; x[i++] = 25; x[i++] = 23;
		x[i++] = 22; x[i++] = 22; x[i++] = 24; x[i++] = 25; x[i++] = 26;
		x[i++] = 26; x[i++] = 26; x[i++] = 24; x[i++] = 22; x[i++] = 20;
		x[i++] = 17; x[i++] = 14; x[i++] = 10; x[i++] = 7; x[i++] = 5;
		x[i++] = 0;

		i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 3; y[i++] = 4; y[i++] = 8;
		y[i++] = 13; y[i++] = 21; y[i++] = 32; y[i++] = 57; y[i++] = 94;
		y[i++] = 103; y[i++] = 112; y[i++] = 115; y[i++] = 119; y[i++] = 125;
		y[i++] = 131; y[i++] = 139; y[i++] = 148; y[i++] = 158; y[i++] = 175;
		y[i++] = 187; y[i++] = 199; y[i++] = 207; y[i++] = 217; y[i++] = 230;
		y[i++] = 234; y[i++] = 230; y[i++] = 217; y[i++] = 207; y[i++] = 199;
		y[i++] = 175; y[i++] = 168; y[i++] = 162; y[i++] = 155; y[i++] = 149;
		y[i++] = 143; y[i++] = 137; y[i++] = 132; y[i++] = 130; y[i++] = 129;
		y[i++] = 129;
	}else if( tipo == 3 ){ // vinho
		this->pontos = 59;
		
		x[i++] = 0; x[i++] = 106; x[i++] = 106; x[i++] = 98; x[i++] = 88; x[i++] = 77;
		x[i++] = 64; x[i++] = 51; x[i++] = 42; x[i++] = 28; x[i++] = 20;
		x[i++] = 13; x[i++] = 11; x[i++] = 11; x[i++] = 11; x[i++] = 11;
		x[i++] = 12; x[i++] = 13; x[i++] = 17; x[i++] = 23; x[i++] = 30;
		x[i++] = 38; x[i++] = 49; x[i++] = 67; x[i++] = 81; x[i++] = 94;
		x[i++] = 108; x[i++] = 124; x[i++] = 134; x[i++] = 138; x[i++] = 138;
		x[i++] = 137; x[i++] = 135; x[i++] = 131; x[i++] = 127; x[i++] = 123;
		x[i++] = 118; x[i++] = 113; x[i++] = 106; x[i++] = 99; x[i++] = 97;
		x[i++] = 96; x[i++] = 105; x[i++] = 115; x[i++] = 122; x[i++] = 129;
		x[i++] = 133; x[i++] = 135; x[i++] = 135; x[i++] = 130; x[i++] = 118;
		x[i++] = 105; x[i++] = 90; x[i++] = 73; x[i++] = 55; x[i++] = 38;
		x[i++] = 26; x[i++] = 16; x[i++] = 6; x[i++] = 0; 

		i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 9; y[i++] = 11; y[i++] = 12; y[i++] = 14;
		y[i++] = 17; y[i++] = 20; y[i++] = 24; y[i++] = 33; y[i++] = 43;
		y[i++] = 59; y[i++] = 76; y[i++] = 94; y[i++] = 119; y[i++] = 143;
		y[i++] = 162; y[i++] = 184; y[i++] = 204; y[i++] = 220; y[i++] = 233;
		y[i++] = 247; y[i++] = 260; y[i++] = 277; y[i++] = 291; y[i++] = 303;
		y[i++] = 319; y[i++] = 340; y[i++] = 362; y[i++] = 385; y[i++] = 407;
		y[i++] = 430; y[i++] = 448; y[i++] = 468; y[i++] = 486; y[i++] = 502;
		y[i++] = 520; y[i++] = 537; y[i++] = 556; y[i++] = 576; y[i++] = 581;
		y[i++] = 577; y[i++] = 554; y[i++] = 524; y[i++] = 500; y[i++] = 472;
		y[i++] = 448; y[i++] = 424; y[i++] = 390; y[i++] = 366; y[i++] = 344;
		y[i++] = 328; y[i++] = 314; y[i++] = 297; y[i++] = 283; y[i++] = 269;
		y[i++] = 259; y[i++] = 251; y[i++] = 248; y[i++] = 247; 
	} else
		return;

	this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
}