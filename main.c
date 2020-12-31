/*
implementation of digital circuits and logic gates
*/
#include<stdio.h>
int count_t=0;
void cTransistor(int*);
int cNotgate(int input);
int cAndgate(int in1,int in2);
int cOrgate(int in1,int in2);
int cNandgate(int in1,int in2);
int cNorgate(int in1,int in2);
int cXorgate(int in1,int in2);
int cHalfadder(int in1,int in2,int* carry);
int cFulladder(int in1,int in2,int in3,int* carry);
int c8bitadder(int* byte1,int* byte2,int* byte3);
int c4bitadder(int* byte1,int* byte2,int* byte3);
int c8bitaddsub(int* byte1,int* byte2,int operation,int* byte3);
void c4bitmul(int* byte1,int* byte2,int* byte3);

void main(){
	int in1,in2,in3,c,t[3],out,error,sum=0,carry=0,byte1[8],byte2[8],byte3[8];
	printf("options...\n");
	printf("1. Transistor	2. NOT gate	3. AND gate	4. OR gate\n");
	printf("5. NAND gate	6. NOR gate	7. XOR gate	8. Half Adder\n");
	printf("9. Full adder	10. 8 bit adder	11. Add/Sub	12. Multiplaction\n");

	printf("Select the option... ");
	scanf("%d",&c);
	printf("only 0/1 as an input\n");

	switch(c){
	case 1:
	printf("Collector= ");
	scanf("%d",&t[0]);
	printf("Base= ");
	scanf("%d",&t[1]);
	printf("Emittor (ground:0,output:-1)= ");//0 for grounded emittor,-1 to check output at emittor
	scanf("%d",&t[2]);
	cTransistor(t);
	printf("transistor output:collector= %d base= %d emittor= %d\n",t[0],t[1],t[2]);
	break;

	case 2:
	printf("not: input= ");
	scanf("%d",&in1);
	out=cNotgate(in1);
	printf("not: output= %d\n",out);
	break;

	case 3:
	printf("and: input 1= ");
	scanf("%d",&in1);
	printf("and: input 2= ");
	scanf("%d",&in2);
	out=cAndgate(in1,in2);
	printf("and: output= %d\n",out);
	break;

	case 4:
	printf("or: input 1= ");
	scanf("%d",&in1);
	printf("or: input 2= ");
	scanf("%d",&in2);
	out=cOrgate(in1,in2);
	printf("or: output= %d\n",out);
	break;

	case 5:
	printf("nand: input 1= ");
	scanf("%d",&in1);
	printf("nand: input 2= ");
	scanf("%d",&in2);
	out=cNandgate(in1,in2);
	printf("nand: output= %d\n",out);
	break;

	case 6:
	printf("nor: input 1= ");
	scanf("%d",&in1);
	printf("nor: input 2= ");
	scanf("%d",&in2);
	out=cNorgate(in1,in2);
	printf("nor: output= %d\n",out);
	break;

	case 7:
	printf("xor: input 1= ");
	scanf("%d",&in1);
	printf("xor: input 2= ");
	scanf("%d",&in2);
	out=cXorgate(in1,in2);
	printf("xor: output= %d\n",out);
	break;

	case 8:
	printf("Halfadder: input 1= ");
	scanf("%d",&in1);
	printf("Halfadder: input 2= ");
	scanf("%d",&in2);
	sum=cHalfadder(in1,in2,&carry);
	printf("Halhadder:output= sum=%d carry=%d\n",sum,carry);
	break;

	case 9:
	printf("Fulladder: input 1= ");
	scanf("%d",&in1);
	printf("Fulladder: input 2= ");
	scanf("%d",&in2);
	printf("Fulladder: input 3= ");
	scanf("%d",&in3);
	sum=cFulladder(in1,in2,in3,&carry);
	printf("Fulladder:output= sum=%d carry=%d\n",sum,carry);
	break;

	case 10:
	printf("8-bit adder: input 1= ");
	scanf("%d%d%d%d%d%d%d%d",&byte1[7],&byte1[6],&byte1[5],&byte1[4],&byte1[3],&byte1[2],&byte1[1],&byte1[0]);
	printf("8-bit adder: input 2= ");
	scanf("%d%d%d%d%d%d%d%d",&byte2[7],&byte2[6],&byte2[5],&byte2[4],&byte2[3],&byte2[2],&byte2[1],&byte2[0]);
	carry=c8bitadder(byte1,byte2,byte3);
	printf("8-bit adder: output = %d %d %d %d %d %d %d %d carry=%d\n",byte3[7],byte3[6],byte3[5],byte3[4],byte3[3],byte3[2],byte3[1],byte3[0],carry);
	break;

	case 11:
	printf("8-bit add sub: input 1= ");
	scanf("%d%d%d%d%d%d%d%d",&byte1[7],&byte1[6],&byte1[5],&byte1[4],&byte1[3],&byte1[2],&byte1[1],&byte1[0]);
	printf("8-bit add sub: input 2= ");
	scanf("%d%d%d%d%d%d%d%d",&byte2[7],&byte2[6],&byte2[5],&byte2[4],&byte2[3],&byte2[2],&byte2[1],&byte2[0]);
	printf("8-bit add sub: option (Add 0,Sub 1) = ");
	scanf("%d",&in1);
	carry=c8bitaddsub(byte1,byte2,in1,byte3);
	printf("8-bit add sub: output = %d %d %d %d %d %d %d %d carry=%d\n",byte3[7],byte3[6],byte3[5],byte3[4],byte3[3],byte3[2],byte3[1],byte3[0],carry);
	break;

	case 12:
	printf("4-bit mul: input 1= ");
	scanf("%d%d%d%d",&byte1[3],&byte1[2],&byte1[1],&byte1[0]);
	printf("4-bit mul: input 2= ");
	scanf("%d%d%d%d",&byte2[3],&byte2[2],&byte2[1],&byte2[0]);
	c4bitmul(byte1,byte2,byte3);
	printf("4-bit mul: output = %d %d %d %d %d %d %d %d\n",byte3[7],byte3[6],byte3[5],byte3[4],byte3[3],byte3[2],byte3[1],byte3[0]);
	break;

	default:
	printf("chose a valid option\n");
	break;

}
	printf("Developer note: Total %d transistors were used for the above operation.\n",count_t);
//_____________________________________________________________________
}
//////////////////////////////////////////////////////////
void c4bitmul(int* byte1,int* byte2,int* byte3){
int in1[4],in2[4],out[4],c1;

byte3[0]=cAndgate(byte1[0],byte2[0]);
in1[0]=cAndgate(byte1[1],byte2[0]);
in1[1]=cAndgate(byte1[2],byte2[0]);
in1[2]=cAndgate(byte1[3],byte2[0]);
in1[3]=0;
in2[0]=cAndgate(byte1[0],byte2[1]);
in2[1]=cAndgate(byte1[1],byte2[1]);
in2[2]=cAndgate(byte1[2],byte2[1]);
in2[3]=cAndgate(byte1[3],byte2[1]);
c1=c4bitadder(in1,in2,out);

byte3[1]=out[0];
in1[0]=out[1];
in1[1]=out[2];
in1[2]=out[3];
in1[3]=c1;
in2[0]=cAndgate(byte1[0],byte2[2]);
in2[1]=cAndgate(byte1[1],byte2[2]);
in2[2]=cAndgate(byte1[2],byte2[2]);
in2[3]=cAndgate(byte1[3],byte2[2]);
c1=c4bitadder(in1,in2,out);

byte3[2]=out[0];
in1[0]=out[1];
in1[1]=out[2];
in1[2]=out[3];
in1[3]=c1;
in2[0]=cAndgate(byte1[0],byte2[3]);
in2[1]=cAndgate(byte1[1],byte2[3]);
in2[2]=cAndgate(byte1[2],byte2[3]);
in2[3]=cAndgate(byte1[3],byte2[3]);
c1=c4bitadder(in1,in2,out);

byte3[3]=out[0];
byte3[4]=out[1];
byte3[5]=out[2];
byte3[6]=out[3];
byte3[7]=c1;

}
////////////////////////////////////////////////////////////////////
int c8bitaddsub(int* byte1,int* byte2,int k,int* byte3){
int out1,out2,carry;
out1=cXorgate(byte2[0],k);
byte3[0]=cFulladder(byte1[0],out1,k,&carry);
out1=cXorgate(byte2[1],k);
byte3[1]=cFulladder(byte1[1],out1,carry,&carry);
out1=cXorgate(byte2[2],k);
byte3[2]=cFulladder(byte1[2],out1,carry,&carry);
out1=cXorgate(byte2[3],k);
byte3[3]=cFulladder(byte1[3],out1,carry,&carry);
out1=cXorgate(byte2[4],k);
byte3[4]=cFulladder(byte1[4],out1,carry,&carry);
out1=cXorgate(byte2[5],k);
byte3[5]=cFulladder(byte1[5],out1,carry,&carry);
out1=cXorgate(byte2[6],k);
byte3[6]=cFulladder(byte1[6],out1,carry,&carry);
out1=cXorgate(byte2[7],k);
byte3[7]=cFulladder(byte1[7],out1,carry,&carry);
return carry;
}
//////////////////////////////////////////////////////
int c4bitadder(int* byte1,int* byte2,int* byte3){
int carry=0;
byte3[0]=cFulladder(byte1[0],byte2[0],0,&carry);
byte3[1]=cFulladder(byte1[1],byte2[1],carry,&carry);
byte3[2]=cFulladder(byte1[2],byte2[2],carry,&carry);
byte3[3]=cFulladder(byte1[3],byte2[3],carry,&carry);
return carry;
}
/////////////////////////////////////////////////////
int c8bitadder(int* byte1,int* byte2,int* byte3){
int carry=0;
byte3[0]=cFulladder(byte1[0],byte2[0],0,&carry);
byte3[1]=cFulladder(byte1[1],byte2[1],carry,&carry);
byte3[2]=cFulladder(byte1[2],byte2[2],carry,&carry);
byte3[3]=cFulladder(byte1[3],byte2[3],carry,&carry);
byte3[4]=cFulladder(byte1[4],byte2[4],carry,&carry);
byte3[5]=cFulladder(byte1[5],byte2[5],carry,&carry);
byte3[6]=cFulladder(byte1[6],byte2[6],carry,&carry);
byte3[7]=cFulladder(byte1[7],byte2[7],carry,&carry);
return carry;
}
///////////////////////////////////////////////////////
int cFulladder(int in1,int in2,int in3,int* carry){
	int sum,carry1,carry2;
	sum=cHalfadder(in1,in2,&carry1);
	sum=cHalfadder(sum,in3,&carry2);
	*carry=cOrgate(carry1,carry2);
	return sum;
}
//////////////////////////////////////////////
int cHalfadder(int in1,int in2,int* carry){
int sum;
*carry=cAndgate(in1,in2);
sum=cXorgate(in1,in2);
return sum;
}
//////////////////////////////////////////////
int cXorgate(int in1,int in2){
int out1,out2;
out1=cOrgate(in1,in2);
out2=cAndgate(in1,in2);
out2=cNotgate(out2);
out2=cAndgate(out1,out2);
return out2;
}
//////////////////////////////////////////////
int cNorgate(int in1,int in2){
int out;
out=cOrgate(in1,in2);
out=cNotgate(out);
return out;
}
////////////////////////////////////////////////
int cNandgate(int in1,int in2){
int out;
out=cAndgate(in1,in2);
out=cNotgate(out);
return out;
}
////////////////////////////////////////////////
int cOrgate(int in1,int in2){
	int vcc=1,gnd=0,out;//take vcc, ground and a output
	//-1 indicates that terminal is a output terminal and not connected to vcc/gnd
	int t1[3]={vcc,in1,-1};//take a transistotr1 and make connections {collector,base,emittor}
	cTransistor(t1);//turn on/execute the transistor1
	//printf("transistor output:c= %d b= %d e= %d \n",t1[0],t1[1],t1[2]);
	int t2[3]={vcc,in2,-1};//take transistor2 and make connections
	cTransistor(t2);//turn on/execute the transistor2
	//printf("transistor output:c= %d b= %d e= %d \n",t2[0],t2[1],t2[2]);
	out=t1[2]+t2[2];//take the combined output of two emittors
	//just to make sure that output becomes 0/1 (in case of 1|1)
	if(out==2){
		out= out--;
	}
	return out;
}
////////////////////////////////////////////////////
int cAndgate(int in1,int in2){
	int vcc=1,gnd=0;//take vcc and ground
	//-1 indicates that terminal is a output terminal and not connected to vcc/gnd
	int t1[3]={vcc,in1,-1};//take a transistor1 and make the connections {collector, base, emittor}
	cTransistor(t1);//turn on/execute the transistor1
	//printf("transistor output:c= %d b= %d e= %d error=%d\n",t[0],t[1],t[2],error);
	int t2[3]={t1[2],in2,-1};//take transistor2 and make the connections
	cTransistor(t2);//turn on/execute the transistor2
	//printf("transistor output:c= %d b= %d e= %d error=%d\n",t[0],t[1],t[2],error);
	return t2[2];//take the output from transistor2 emittor

}
/////////////////////////////////////////////////////////
int cNotgate(int input){
	int vcc=1,gnd=0;//take vcc and ground
	int t[3]={vcc,input,gnd};//take a transistor and make the connections {collector, base, emittor}
	cTransistor(t);//turn on/execute the transistor
	return t[0];//take the output from collector
}

/////////////////////////////////////////////////////////////
void cTransistor(int *t){
	//static int count_t=0;
	count_t++;
	if(t[2]!=1){//if emittor is not connected to vcc
		if(t[1]==0){    //if base= 0
			t[2]=0;
		}
		else if(t[1]==1){ //if base= 1
			if(t[2]==0){//if emittor is connected to ground
				t[0]=0;//collector becomes grounded/0
			}
			else if(t[2]!=0){//if emittor is not connected to ground
				t[2]=t[0];//emittor = collector
			}
		}
		//printf("transistor-%d status: Collector= %d Base= %d Emittor= %d\n",count_t,t[0],t[1],t[2]);
	}
	else{
		printf("Do not connect emittor to Vcc.\n");
		printf("To check output from emittor make it output terminal by providing -1 as emittor value\n");
	}
}

//end of project
//
