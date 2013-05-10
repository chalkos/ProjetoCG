
#include <stdlib.h>
#include "SolidoRevolucao.h"
#include <iostream>
#include <conio.h>

/*********************************

	SolidoRevolucao

**********************************/

void SolidoRevolucao::preencherVertices(){
	if( this->fechado )
		this->revolutionSolidClose(x, y, this->pontos, this->fatias);
	else
		this->revolutionSolidOpen(x, y, this->pontos, this->fatias);
}

SolidoRevolucao::SolidoRevolucao(TipoSolidoRevolucao tipo, int detalhe){

	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;

	int i=0;
	int j=0; //para confirmar que têm o mesmo numero de coordenadas X e Y
	
	switch (tipo){
	case mesa: // mesa redonda
		this->fechado = true;
		

		// os 3 pontos são um fix para as normais não serem suavizadas 
		x[i++] = 0;

		x[i++] = 2.5;
		x[i++] = 2.5;
		x[i++] = 2.5;
		
		x[i++] = 2.5;
		x[i++] = 2.5;
		x[i++] = 2.5;
		
		x[i++] = 0.5;
		x[i++] = 0.5;
		x[i++] = 0.5;

		x[i++] = 0.5;
		x[i++] = 0.5;
		x[i++] = 0.5;
		
		x[i++] = 4;
		x[i++] = 4;
		x[i++] = 4;

		x[i++] = 4;
		x[i++] = 4;
		x[i++] = 4;
		
		x[i++] = 0;

		
		j=i; i=0;
		y[i++] = 0;

		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 0;
		
		y[i++] = 0.1;
		y[i++] = 0.1;
		y[i++] = 0.1;

		y[i++] = 0.1;
		y[i++] = 0.1;
		y[i++] = 0.1;
		
		y[i++] = 3.9;
		y[i++] = 3.9;
		y[i++] = 3.9;

		y[i++] = 3.9;
		y[i++] = 3.9;
		y[i++] = 3.9;
		
		y[i++] = 4;
		y[i++] = 4;
		y[i++] = 4;
		
		y[i++] = 4;  
		break;

	case garrafa: // garrafa de vinho
		this->fechado = true;

		x[i++] = 0; x[i++] = 32; x[i++] = 33; x[i++] = 35; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 34; x[i++] = 31; x[i++] = 27;
		x[i++] = 22; x[i++] = 18; x[i++] = 14; x[i++] = 13; x[i++] = 13;
		x[i++] = 13; x[i++] = 13; x[i++] = 13; x[i++] = 13; x[i++] = 13; x[i++] = 15; x[i++] = 15; x[i++] = 15; x[i++] = 15; x[i++] = 13; x[i++] = 0;

		j=i; i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 3; y[i++] = 7; y[i++] = 15;
		y[i++] = 26; y[i++] = 38; y[i++] = 52; y[i++] = 65; y[i++] = 78;
		y[i++] = 91; y[i++] = 103; y[i++] = 115; y[i++] = 130; y[i++] = 145;
		y[i++] = 161; y[i++] = 172; y[i++] = 181; y[i++] = 188; y[i++] = 194;
		y[i++] = 200; y[i++] = 205; y[i++] = 211; y[i++] = 217; y[i++] = 230;
		y[i++] = 244; y[i++] = 255; y[i++] = 266; y[i++] = 266; y[i++] = 266; y[i++] = 266; y[i++] = 268; y[i++] = 272; y[i++] = 274; y[i++] = 274; y[i++] = 274;
		break;

	case candeeiro: // candeeiro
		this->fechado = true;

		x[i++] = 0;
		
		x[i++] = 33;
		x[i++] = 33;
		x[i++] = 33;
		
		x[i++] = 32;
		
		x[i++] = 31;
		
		x[i++] = 28;
		x[i++] = 24;
		
		x[i++] = 22;
		x[i++] = 22;
		x[i++] = 22;
		
		x[i++] = 6;
		x[i++] = 6;
		x[i++] = 6;
		
		x[i++] = 6;
		x[i++] = 6;
		x[i++] = 6;
		
		x[i++] = 4;
		x[i++] = 4;
		x[i++] = 4;

		x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4;
		x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4;
		x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 6; x[i++] = 6; x[i++] = 6;
		x[i++] = 6; x[i++] = 6; x[i++] = 6; x[i++] = 11; x[i++] = 15; x[i++] = 20; x[i++] = 23;
		x[i++] = 25; x[i++] = 27; x[i++] = 29; x[i++] = 29; x[i++] = 29;x[i++] = 29;x[i++] = 29;
		x[i++] = 33; x[i++] = 36; x[i++] = 37; x[i++] = 38; x[i++] = 38; x[i++] = 38; x[i++] = 38;
		x[i++] = 46; x[i++] = 55; x[i++] = 66; x[i++] = 77; x[i++] = 88;
		x[i++] = 98; x[i++] = 105; x[i++] = 112; x[i++] = 117; x[i++] = 119;
		x[i++] = 120; x[i++] = 123; x[i++] = 125; x[i++] = 124; x[i++] = 121;
		x[i++] = 118; x[i++] = 116; x[i++] = 115; x[i++] = 112; x[i++] = 107;
		x[i++] = 102; x[i++] = 96; x[i++] = 91; x[i++] = 85; x[i++] = 78;
		x[i++] = 72; x[i++] = 65; x[i++] = 57; x[i++] = 48; x[i++] = 38;
		x[i++] = 26; x[i++] = 15; x[i++] = 0;  


		j=i; i=0;
		y[i++] = 0;
		
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 0;
		
		y[i++] = 10;
		
		y[i++] = 19;
		
		y[i++] = 31;
		y[i++] = 45;
		
		y[i++] = 50;
		y[i++] = 50;
		y[i++] = 50;
		
		y[i++] = 50;
		y[i++] = 50;
		y[i++] = 50;
		
		y[i++] = 58;
		y[i++] = 58;
		y[i++] = 58;
		
		y[i++] = 58;
		y[i++] = 58;
		y[i++] = 58;

		y[i++] = 69; y[i++] = 78; y[i++] = 89; y[i++] = 100; y[i++] = 112;
		y[i++] = 123; y[i++] = 134; y[i++] = 143; y[i++] = 153; y[i++] = 164;
		y[i++] = 173; y[i++] = 184; y[i++] = 197; y[i++] = 210; y[i++] = 210; y[i++] = 210; y[i++] = 210;y[i++] = 210; y[i++] = 210;
		y[i++] = 218; y[i++] = 218; y[i++] = 218; y[i++] = 219; y[i++] = 221; y[i++] = 225; y[i++] = 232;
		y[i++] = 241; y[i++] = 250; y[i++] = 261; y[i++] = 274; y[i++] = 277;y[i++] = 277;y[i++] = 277;
		y[i++] = 278; y[i++] = 281; y[i++] = 285; y[i++] = 289; y[i++] = 294; y[i++] = 294; y[i++] = 294;
		y[i++] = 301; y[i++] = 308; y[i++] = 319; y[i++] = 330; y[i++] = 344;
		y[i++] = 358; y[i++] = 370; y[i++] = 387; y[i++] = 401; y[i++] = 412;
		y[i++] = 417; y[i++] = 417; y[i++] = 419; y[i++] = 422; y[i++] = 422;
		y[i++] = 420; y[i++] = 417; y[i++] = 408; y[i++] = 398; y[i++] = 387;
		y[i++] = 375; y[i++] = 365; y[i++] = 357; y[i++] = 348; y[i++] = 339;
		y[i++] = 334; y[i++] = 328; y[i++] = 323; y[i++] = 317; y[i++] = 313;
		y[i++] = 310; y[i++] = 309; y[i++] = 309;  
		break;

	case abajour:
		this->fechado = false;

		x[i++] = 10;
		x[i++] = 10.5;
		x[i++] = 3.5;
		x[i++] = 3;
		x[i++] = 10;

		j=i; i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 10;
		y[i++] = 10;
		y[i++] = 0;

		break;

	case testeLuz:
		this->fechado = true;
		
		x[i++] = 0;
		x[i++] = 10;
		x[i++] = 10;
		x[i++] = 0;

		j=i; i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 10;
		y[i++] = 10;

		break;
	case testeLuz2:
		this->fechado = true;

		x[i++] = 0;
		x[i++] = 1;
		x[i++] = 2;
		x[i++] =3;
		x[i++] = 4;
		x[i++] = 5;
		x[i++] = 0;

		j=i; i=0;
		y[i++] = 0;
		y[i++] = 1;
		y[i++] = 2;
		y[i++] = 3;
		y[i++] = 4;
		y[i++] = 5;
		y[i++] = 5;

		break;
	case cilindrotesteLuz:
		this->fechado = true;

		x[i++] = 0;
		x[i++] = 10;
		x[i++] = 10;
		x[i++] = 7;
		x[i++] = 4;
		x[i++] = 7;
		x[i++] = 4;
		x[i++] = 2;
		x[i++] = 2;
		x[i++] = 4;
		x[i++] = 7;
		x[i++] = 4;
		x[i++] = 7;
		x[i++] = 10;
		x[i++] = 10;
		x[i++] = 0;

		j=i; i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 4;
		y[i++] = 8;
		y[i++] = 6;
		y[i++] = 4;
		y[i++] = 2;
		y[i++] = 6;
		y[i++] = 12;
		y[i++] = 16;
		y[i++] = 14;
		y[i++] = 12;
		y[i++] = 10;
		y[i++] = 14;
		y[i++] = 18;
		y[i++] = 18;

		break;
	case copoSimples:
		this->fechado = true;

		x[i++] = 0;
		
		x[i++] = 2;
		x[i++] = 2;
		x[i++] = 2;
		
		x[i++] = 2.5;
		x[i++] = 2.5;
		x[i++] = 2.5;
		
		x[i++] = 2.4;
		x[i++] = 2.4;
		x[i++] = 2.4;
		
		x[i++] = 1.9;
		x[i++] = 1.9;
		x[i++] = 1.9;
		
		x[i++] = 0;

		j=i; i=0;
		y[i++] = 0;
		
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 0;
		
		y[i++] = 5;
		y[i++] = 5;
		y[i++] = 5;

		y[i++] = 5;
		y[i++] = 5;
		y[i++] = 5;
		
		y[i++] = 0.3;
		y[i++] = 0.3;
		y[i++] = 0.3;

		y[i++] = 0.3;
		break;

	case copoChampanhe:
		this->fechado = true;

		x[i++] = 0; x[i++] = 37; x[i++] = 37; x[i++] = 37; x[i++] = 37; x[i++] = 28; x[i++] = 19;
		x[i++] = 11; x[i++] = 7; x[i++] = 5; x[i++] = 4; x[i++] = 4;
		x[i++] = 5; x[i++] = 8; x[i++] = 11; x[i++] = 14; x[i++] = 18;
		x[i++] = 21; x[i++] = 24; x[i++] = 26; x[i++] = 27; x[i++] = 27;
		x[i++] = 27; x[i++] = 27; x[i++] = 26; x[i++] = 25; x[i++] = 23;
		x[i++] = 22; x[i++] = 22; x[i++] = 22; x[i++] = 22; x[i++] = 24; x[i++] = 25; x[i++] = 26;//
		x[i++] = 26; x[i++] = 26; x[i++] = 24; x[i++] = 22; x[i++] = 20;
		x[i++] = 17; x[i++] = 14; x[i++] = 10; x[i++] = 7; x[i++] = 5;
		x[i++] = 0;

		j=i; i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 3; y[i++] = 4; y[i++] = 8;
		y[i++] = 13; y[i++] = 21; y[i++] = 32; y[i++] = 57; y[i++] = 94;
		y[i++] = 103; y[i++] = 112; y[i++] = 115; y[i++] = 119; y[i++] = 125;
		y[i++] = 131; y[i++] = 139; y[i++] = 148; y[i++] = 158; y[i++] = 175;
		y[i++] = 187; y[i++] = 199; y[i++] = 207; y[i++] = 217; y[i++] = 230;
		y[i++] = 234; y[i++] = 234; y[i++] = 234; y[i++] = 230; y[i++] = 217; y[i++] = 207; y[i++] = 199;
		y[i++] = 175; y[i++] = 168; y[i++] = 162; y[i++] = 155; y[i++] = 149;
		y[i++] = 143; y[i++] = 137; y[i++] = 132; y[i++] = 130; y[i++] = 129;
		y[i++] = 129;

		break;

	case copoVinho:
		this->fechado = true;

		x[i++] = 0; x[i++] = 106; x[i++] = 106; x[i++] = 106; x[i++] = 106; x[i++] = 98; x[i++] = 88; x[i++] = 77;
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

		j=i; i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 9; y[i++] = 11; y[i++] = 12; y[i++] = 14;
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

		break;


	default:
		return;
	}
	
	if( i != j ){
		std::cout << "[ERRO] #X (=" << j << ") != #Y (=" << i << ") TipoSolidoRevolucao=" << tipo << " @ SolidoRevolucao.cpp\nPress any key to exit" << std::endl;
		getch();
		exit(EXIT_FAILURE);
	}

	this->pontos = i;

	comprimento = 0;
	for(i=0; i<this->pontos-1; i++)
		comprimento += sqrt( (x[i+1] - x[i])*(x[i+1] - x[i]) + (y[i+1]-y[i])*(y[i+1]-y[i]) ); // sqrt(  (x2-x1)^2 + (y2-y1)^2  )
		
	if( this->fechado )
		this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
	else
		this->guardarOBJ( (this->fatias) * (this->pontos-1) * 2 );
}