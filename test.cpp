#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>
#include <stdio.h>    
#include <stdlib.h> 
#include<map>
#include<vector>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstddef>
using namespace std;
int current_pointer_layout=0;
int current_pointer_vlc=0;
int compressed_line_layout[512];
int compressed_line_vlc[512];
int previous_word[64];
int current_word[64];
int check_id,check_id_bdi;
int string_length=512;
int input_string [512];
int vlc_code();
int Test_all_zeros (int *array_test);
int Test_previous_64_bit_word (int *array_test_0,int *array_test_1);
int Test_previous_previous_64_bit_word (int *array_test_0,int *array_test_1);
int Test_previous_previous_previous_previous_64_bit_word (int *array_test_0,int *array_test_1);
int Test_32data_32zero_64_bit_word (int *array_test);
int Test_16_bit_sign_64_bit_word (int *array_test);
int Test_32_bit_sign_64_bit_word (int *array_test);
int Test_44_bit_delta_previous_64_bit_word (int *array_test_0,int *array_test_1);
int Test_52_bit_delta_previous_64_bit_word (int *array_test_0,int *array_test_1);
int Test_12_bit_delta_previous_previous_64_bit_word (int *array_test_0,int *array_test_1);
int  Test_sign_exponent_1_64_bit_word (int *array_test_0);
int  Test_sign_exponent_2_64_bit_word (int *array_test_0);
int  Test_sign_exponent_3_64_bit_word (int *array_test_0,int *array_test_1);
int  Test_exponent_4_64_bit_word (int *array_test_0);
int  Test_full_64_bit_word (int *array_test);
int  Test_full_32_bit_word (int *array_test);
int  Test_full_16_bit_word (int *array_test);
int  Test_full_8_bit_word (int *array_test);
int  Test_full_64_double_bit_word (int *array_test);
int  Test_full_32_float_bit_word (int *array_test);
int  Test_480_full_64_bit_word (int *array_test);
int  Test_480_full_32_bit_word (int *array_test);
int  Test_480_full_16_bit_word (int *array_test);
int  Test_480_full_8_bit_word (int *array_test);
int  Test_480_full_64_double_bit_word (int *array_test);
int  Test_480_full_32_float_bit_word (int *array_test);

//##################################################################################################################
//******************************************************************************************************************
//****************************************Main Program**************************************************************
//******************************************************************************************************************
int main (int argc, const char * argv[])
{

	int a=227;
	int res=a%16;
	int blk_num=(a-(res))/16;
	cout<<"\n"<<res<<"\n";
	cout<<"\n"<<blk_num<<"\n";
	int i,j,k;
	//*****************Test Section**********************
	//cout<<"\nAll zero 64-bit\n"; 
	//cout<<rand()%2<<rand()%2<<rand()%2<<"\n";
	for(i=0;i<string_length;i++)
			//input_string[i]=rand()%2;
		input_string[i]=0;

	//{30b delta} x 5 + {29b delta} x 10

	/*for(j=29;j<32;j++)
		{
			input_string[j]=0;
		}

	for(k=1;k<6;k++)
		for(j=30;j<32;j++)
			{
				input_string[j+k*32]=0;
			}

	for(k=6;k<16;k++)
		for(j=29;j<32;j++)
			{
				input_string[j+k*32]=0;
			}*/

	/*for(j=54;j<64;j++)
		{
			input_string[j]=0;
		}

	for(k=1;k<5;k++)
		for(j=54;j<64;j++)
			{
				input_string[j+k*64]=0;
			}

	for(k=5;k<8;k++)
		for(j=53;j<64;j++)
			{
				input_string[j+k*64]=0;
			}*/
/*
	for(j=27;j<32;j++)
		{
			input_string[j]=0;
		}

	for(k=1;k<4;k++)
		for(j=28;j<32;j++)
			{
				input_string[j+k*32]=0;
			}

	for(k=4;k<16;k++)
		for(j=27;j<32;j++)
			{
				input_string[j+k*32]=0;
			}*/
	/*
	for(i=56;i<64;i++)
	{
		input_string[i+64]=0;
		input_string[i+128]=0;
	}
	input_string[63+64]=1;*/
		
		/*for(i=0;i<52;i++)
		{
			input_string[i+64*0]=1;
			input_string[i+64*1]=1;
		}
			input_string[89]=0;

		for(i=0;i<44;i++)
		{
			input_string[i+64*2]=1;
			input_string[i+64*3]=1;
		}

		for(i=0;i<12;i++)
		{
			input_string[i+64*4]=1;
			input_string[i+64*5]=1;
		}*/
	/*input_string[13]=1;input_string[13+16]=1;
	input_string[20+32]=1;input_string[20+48]=1;


	for(i=0;i<64;i++){
		input_string[i+3*64]=1;
		input_string[i+4*64]=1;
		input_string[i+7*64]=1;
	}
		input_string[28+6*64]=1;
	*/
	/*cout<<"\n";
	for(i=0;i<string_length;i++)
	{
		cout<<input_string[i];
		if((i+1)%64==0)
			cout<<"\n";

	}
	cout<<"\n";*/	


	//################################################ 64b Base--> {54b delta} x 4 + {53b delta} x 3
			
		check_id_bdi=Test_full_64_bit_word(input_string);
		if(check_id_bdi==101)
		{

			compressed_line_layout[0]=1;
			compressed_line_layout[1]=1;
			compressed_line_layout[2]=0;
			compressed_line_layout[3]=0;
			current_pointer_layout=4;
			for(i=0;i<64;i++)
				compressed_line_layout[current_pointer_layout+i]=input_string[i];
			current_pointer_layout+=64;

			for(i=0;i<4;i++)
			{
				for(j=0;j<54;j++)
				{
					compressed_line_layout[current_pointer_layout+i*54+j]=input_string[(i+1)*64+j];
				}
			}

			current_pointer_layout+=54*4;

			for(i=0;i<3;i++)
			{
				for(j=0;j<53;j++)
				{
					compressed_line_layout[current_pointer_layout+i*53+j]=input_string[(i+5)*64+j];
				}
			}

			current_pointer_layout+=53*3;
			//cout<<"\n64b Base--> {54b delta} x 4 + {53b delta} x 3 \n";

		}
	//################################################ {28b delta} x 2 + {27b delta} x 13
			if(check_id_bdi==0)
				{
					check_id_bdi=Test_full_32_bit_word(input_string);
					if(check_id_bdi==102)
					{

						compressed_line_layout[0]=1;
						compressed_line_layout[1]=1;
						compressed_line_layout[2]=0;
						compressed_line_layout[3]=1;
						current_pointer_layout=4;
						for(i=0;i<32;i++)
							compressed_line_layout[current_pointer_layout+i]=input_string[i];
						current_pointer_layout+=32;

						for(i=0;i<2;i++)
						{
							for(j=0;j<28;j++)
							{
								compressed_line_layout[current_pointer_layout+i*28+j]=input_string[(i+1)*32+j];
							}
						}

						current_pointer_layout+=28*2;

						for(i=0;i<13;i++)
						{
							for(j=0;j<27;j++)
							{
								compressed_line_layout[current_pointer_layout+i*27+j]=input_string[(i+3)*32+j];
							}
						}

						current_pointer_layout+=27*13;
						//cout<<"\n32b Base--> {28b delta} x 2 + {27b delta} x 13\n";

					}
				}
	//################################################{14b delta} x 20 + {13b delta} x 11
		if(check_id_bdi==0)
			{
				check_id_bdi=Test_full_16_bit_word(input_string);
				if(check_id_bdi==103)
				{

					compressed_line_layout[0]=1;
					compressed_line_layout[1]=1;
					compressed_line_layout[2]=1;
					compressed_line_layout[3]=0;
					current_pointer_layout=4;
					for(i=0;i<16;i++)
						compressed_line_layout[current_pointer_layout+i]=input_string[i];
					current_pointer_layout+=16;

					for(i=0;i<20;i++)
					{
						for(j=0;j<14;j++)
						{
							compressed_line_layout[current_pointer_layout+i*14+j]=input_string[(i+1)*16+j];
						}
					}

					current_pointer_layout+=20*14;

					for(i=0;i<11;i++)
					{
						for(j=0;j<13;j++)
						{
							compressed_line_layout[current_pointer_layout+i*13+j]=input_string[(i+21)*16+j];
						}
					}

					current_pointer_layout+=11*13;
					//cout<<"\n16b Base--> {14b delta} x 20 + {13b delta} x 11\n";

				}
			}
	//################################################{7b delta} x 53 + {6b delta} x 10
			if(check_id_bdi==0)
				{
					check_id_bdi=Test_full_8_bit_word(input_string);
					if(check_id_bdi==104)
					{

						compressed_line_layout[0]=1;
						compressed_line_layout[1]=1;
						compressed_line_layout[2]=1;
						compressed_line_layout[3]=1;
						current_pointer_layout=4;
						for(i=0;i<8;i++)
							compressed_line_layout[current_pointer_layout+i]=input_string[i];
						current_pointer_layout+=8;

						for(i=0;i<53;i++)
						{
							for(j=0;j<7;j++)
							{
								compressed_line_layout[current_pointer_layout+i*7+j]=input_string[(i+1)*8+j];
							}
						}

						current_pointer_layout+=53*7;

						for(i=0;i<10;i++)
						{
							for(j=0;j<6;j++)
							{
								compressed_line_layout[current_pointer_layout+i*6+j]=input_string[(i+54)*8+j];
							}
						}

						current_pointer_layout+=10*6;
						//cout<<"\n8b Base--> {7b delta} x 53 + {6b delta} x 10\n";

					}
				}
	//################################################ {54b delta} x 7
			if(check_id_bdi==0)
				{
						check_id_bdi=Test_full_64_double_bit_word(input_string);
						if(check_id_bdi==105)
						{
							compressed_line_layout[0]=0;
							current_pointer_layout=1;
							for(i=0;i<64;i++)
									compressed_line_layout[current_pointer_layout+i]=input_string[i];
							current_pointer_layout+=64;

							for(i=0;i<7;i++)
							{
								for(j=0;j<54;j++)
								{
									compressed_line_layout[current_pointer_layout+i*54+j]=input_string[(i+1)*64+j];
								}
							}

							current_pointer_layout+=54*7;
							//cout<<"\n64b base (double) --> {54b delta} x 7\n";
						}
						
				}
	//################################################ {28b delta} x 3 + {27b delta} x 12
				if(check_id_bdi==0)
					{		
						check_id_bdi=Test_full_32_float_bit_word(input_string);
						if(check_id_bdi==106)
						{
							compressed_line_layout[0]=1;
							compressed_line_layout[1]=0;
							compressed_line_layout[2]=1;
							current_pointer_layout=3;
							for(i=0;i<32;i++)
								compressed_line_layout[current_pointer_layout+i]=input_string[i];
							current_pointer_layout+=32;

							for(i=0;i<3;i++)
							{
								for(j=0;j<28;j++)
								{
									compressed_line_layout[current_pointer_layout+i*28+j]=input_string[(i+1)*32+j];
								}
							}

							current_pointer_layout+=28*3;

							for(i=0;i<12;i++)
							{
								for(j=0;j<27;j++)
								{
									compressed_line_layout[current_pointer_layout+i*27+j]=input_string[(i+4)*32+j];
								}
							}

							current_pointer_layout+=27*12;
							//cout<<"\n32b base (float) --> {28b delta} x 3 + {27b delta} x 12\n";

						}
					}
	//###############################################################################################
	//################################################ 64b Base--> {59b delta} x 1 + {58b delta} x 6
		if(check_id_bdi==0)
					{	
							check_id_bdi=Test_480_full_64_bit_word(input_string);
							if(check_id_bdi==201)
							{

								compressed_line_layout[0]=1;
								compressed_line_layout[1]=1;
								compressed_line_layout[2]=0;
								compressed_line_layout[3]=0;
								current_pointer_layout=4;
								for(i=0;i<64;i++)
									compressed_line_layout[current_pointer_layout+i]=input_string[i];
								current_pointer_layout+=64;

								for(i=0;i<1;i++)
								{
									for(j=0;j<59;j++)
									{
										compressed_line_layout[current_pointer_layout+i*59+j]=input_string[(i+1)*64+j];
									}
								}

								current_pointer_layout+=59*1;

								for(i=0;i<6;i++)
								{
									for(j=0;j<58;j++)
									{
										compressed_line_layout[current_pointer_layout+i*58+j]=input_string[(i+2)*64+j];
									}
								}

								current_pointer_layout+=58*6;
								//cout<<"\n64b Base--> {59b delta} x 1 + {58b delta} x 6 \n";

							}
		}
	//################################################ {30b delta} x 4 + {29b delta} x 11
			if(check_id_bdi==0)
				{
					check_id_bdi=Test_480_full_32_bit_word(input_string);
					if(check_id_bdi==202)
					{

						compressed_line_layout[0]=1;
						compressed_line_layout[1]=1;
						compressed_line_layout[2]=0;
						compressed_line_layout[3]=1;
						current_pointer_layout=4;
						for(i=0;i<32;i++)
							compressed_line_layout[current_pointer_layout+i]=input_string[i];
						current_pointer_layout+=32;

						for(i=0;i<4;i++)
						{
							for(j=0;j<30;j++)
							{
								compressed_line_layout[current_pointer_layout+i*30+j]=input_string[(i+1)*32+j];
							}
						}

						current_pointer_layout+=30*4;

						for(i=0;i<11;i++)
						{
							for(j=0;j<29;j++)
							{
								compressed_line_layout[current_pointer_layout+i*29+j]=input_string[(i+5)*32+j];
							}
						}

						current_pointer_layout+=11*29;
						//cout<<"\n32b Base--> {30b delta} x 4 + {29b delta} x 11\n";

					}
				}
	//################################################{15b delta} x 21 + {14b delta} x 10
		if(check_id_bdi==0)
			{
				check_id_bdi=Test_480_full_16_bit_word(input_string);
				if(check_id_bdi==203)
				{

					compressed_line_layout[0]=1;
					compressed_line_layout[1]=1;
					compressed_line_layout[2]=1;
					compressed_line_layout[3]=0;
					current_pointer_layout=4;
					for(i=0;i<16;i++)
						compressed_line_layout[current_pointer_layout+i]=input_string[i];
					current_pointer_layout+=16;

					for(i=0;i<21;i++)
					{
						for(j=0;j<15;j++)
						{
							compressed_line_layout[current_pointer_layout+i*15+j]=input_string[(i+1)*16+j];
						}
					}

					current_pointer_layout+=21*15;

					for(i=0;i<10;i++)
					{
						for(j=0;j<14;j++)
						{
							compressed_line_layout[current_pointer_layout+i*14+j]=input_string[(i+22)*16+j];
						}
					}

					current_pointer_layout+=10*14;
					//cout<<"\n16b Base--> {15b delta} x 21 + {14b delta} x 10\n";

				}
			}
	//################################################{8b delta} x 22 + {7b delta} x 41
			if(check_id_bdi==0)
				{
					check_id_bdi=Test_480_full_8_bit_word(input_string);
					if(check_id_bdi==204)
					{

						compressed_line_layout[0]=1;
						compressed_line_layout[1]=1;
						compressed_line_layout[2]=1;
						compressed_line_layout[3]=1;
						current_pointer_layout=4;
						for(i=0;i<8;i++)
							compressed_line_layout[current_pointer_layout+i]=input_string[i];
						current_pointer_layout+=8;

						for(i=0;i<22;i++)
						{
							for(j=0;j<8;j++)
							{
								compressed_line_layout[current_pointer_layout+i*8+j]=input_string[(i+1)*8+j];
							}
						}

						current_pointer_layout+=22*8;

						for(i=0;i<41;i++)
						{
							for(j=0;j<7;j++)
							{
								compressed_line_layout[current_pointer_layout+i*7+j]=input_string[(i+23)*8+j];
							}
						}

						current_pointer_layout+=41*7;
						//cout<<"\n8b Base--> {8b delta} x 22 + {7b delta} x 41\n";

					}
				}
	//################################################64b Base(double)--> {59b delta} x 2 + {58b delta} x 5
		if(check_id_bdi==0)
					{	
							check_id_bdi=Test_480_full_64_double_bit_word(input_string);
							if(check_id_bdi==205)
							{

								compressed_line_layout[0]=1;
								compressed_line_layout[1]=0;
								compressed_line_layout[2]=0;
								current_pointer_layout=3;
								for(i=0;i<64;i++)
									compressed_line_layout[current_pointer_layout+i]=input_string[i];
								current_pointer_layout+=64;

								for(i=0;i<2;i++)
								{
									for(j=0;j<59;j++)
									{
										compressed_line_layout[current_pointer_layout+i*59+j]=input_string[(i+1)*64+j];
									}
								}

								current_pointer_layout+=59*2;

								for(i=0;i<5;i++)
								{
									for(j=0;j<58;j++)
									{
										compressed_line_layout[current_pointer_layout+i*58+j]=input_string[(i+3)*64+j];
									}
								}

								current_pointer_layout+=58*5;
								//cout<<"\n64b Base(double)--> {59b delta} x 2 + {58b delta} x 5 \n";

							}
		}
	//################################################ {30b delta} x 5 + {29b delta} x 10
				if(check_id_bdi==0)
					{		
						check_id_bdi=Test_480_full_32_float_bit_word(input_string);
						if(check_id_bdi==206)
						{

							compressed_line_layout[0]=1;
							compressed_line_layout[1]=0;
							compressed_line_layout[2]=1;
							current_pointer_layout=3;
							for(i=0;i<32;i++)
								compressed_line_layout[current_pointer_layout+i]=input_string[i];
							current_pointer_layout+=32;

							for(i=0;i<5;i++)
							{
								for(j=0;j<30;j++)
								{
									compressed_line_layout[current_pointer_layout+i*30+j]=input_string[(i+1)*32+j];
								}
							}

							current_pointer_layout+=5*30;

							for(i=0;i<10;i++)
							{
								for(j=0;j<29;j++)
								{
									compressed_line_layout[current_pointer_layout+i*29+j]=input_string[(i+6)*32+j];
								}
							}

							current_pointer_layout+=10*29;
							//cout<<"\n32b base (float) --> {30b delta} x 5 + {29b delta} x 10\n";

						}
					}

		//################################################
				int vlc_length=vlc_code();
				//cout<<"\n current_pointer_layout:  "<<l<<"\n";	
		//################################################
				cout<<"\n\nFinal_Results:\n";

				if(vlc_length>480 && current_pointer_layout>480)
				{
					cout<<"\n Incompressible_cache_line\n";
					for(j=0;j<512;j++)
					{
						cout<<input_string[j];
						if(((j+1)%64)==0)
							cout<<"\n";
					}
					cout<<"\n";
				}
				else if(current_pointer_layout<vlc_length)
				{
					cout<<"\n current_pointer_layout:  "<<current_pointer_layout<<"\n";
					for(j=0;j<current_pointer_layout;j++)
					{
						cout<<compressed_line_layout[j];
						if(((j+1)%64)==0)
							cout<<"\n";
					}
					cout<<"\n";
				}
				else
				{
					cout<<"\n vlc_length:  "<<vlc_length<<"\n";
					for(j=0;j<vlc_length;j++)
					{
						cout<<compressed_line_vlc[j];
						if(((j+1)%64)==0)
							cout<<"\n";
					}
					cout<<"\n";

				}


				



  return 0;
}
//*****************************************************************************************************************
//**************************************	All zero 64-bit
int Test_all_zeros (int *array_test)
	{
		int index=1;
		for (int i=0;i<64;i++)
			if(array_test[i]!=0)
			{
				index=0;
				break;
			}	
		
		return index;
	}
//**************************************	Same as left 64-bit
int Test_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		
		int index=2;
		for (int i=0;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		
		return index;
	}
//**************************************	Same as left-left 64-bit
int Test_previous_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		
		int index=3;
		for (int i=0;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		
		return index;
	}
//**************************************	Same as left-left-left-left 64-bit
int Test_previous_previous_previous_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		
		int index=4;
		for (int i=0;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		
		return index;
	}
//**************************************	32-bit data, 32-bit zero
int Test_32data_32zero_64_bit_word (int *array_test)
	{
		
		int index;
		int tmp0=0,tmp1=0;
		for (int i=0;i<32;i++)
			{
				tmp0+=array_test[i];
				tmp1+=array_test[i+32];
			}

			if(tmp0!=0 && tmp1==0)
				index=5;
			else
				index=0;
		
		return index;
	}
	//**************************************	2 x {16-bit sign-extension to 32-bit}
int Test_16_bit_sign_64_bit_word (int *array_test)
	{
		
		int index=6;
		for (int i=0;i<16;i++)
			{
				if((array_test[i]!=array_test[16+i])||(array_test[32+i]!=array_test[48+i]))
					{
						index=0;
						break;
					}
			}
	
		return index;
	}
		//**************************************	32-bit sign-extension
int Test_32_bit_sign_64_bit_word (int *array_test)
	{
		
		int index=7;
		for (int i=0;i<32;i++)
			{
				if(array_test[i]!=array_test[32+i])
					{
						index=0;
						break;
					}
			}
	
		return index;
	}
	//**************************************	44-bit delta from left 64-bit 
int Test_44_bit_delta_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		int index=8;
		for (int i=44;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		return index;
	}
	//**************************************	52-bit delta from left 64-bit
int Test_52_bit_delta_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		int index=9;
		for (int i=52;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		return index;
	}
	//**************************************	12-bit delta from left-left 64-bit
int Test_12_bit_delta_previous_previous_64_bit_word (int *array_test_0,int *array_test_1)
	{
		int index=10;
		for (int i=12;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		return index;
	}
		//**************************************	sign, exponent([63:52]) as 4-bit delta from bias (1023)
int  Test_sign_exponent_1_64_bit_word (int *array_test_0)
	{
		int index=11;
		for (int i=57;i<64;i++)
			if(array_test_0[56]!=array_test_0[i])
			{
				index=0;
				break;
			}	
		return index;
	}
		//**************************************	sign, exponent([63:52]) as 8-bit delta from bias (1023)
int  Test_sign_exponent_2_64_bit_word (int *array_test_0)
	{
		int index=12;
		for (int i=61;i<64;i++)
			if(array_test_0[60]!=array_test_0[i])
			{
				index=0;
				break;
			}	
		return index;
	}
		//**************************************	sign, exponent([63:52]) as 4-bit delta from left 64-bit
int  Test_sign_exponent_3_64_bit_word (int *array_test_0,int *array_test_1)
	{
		int index=13;
		for (int i=56;i<64;i++)
			if(array_test_0[i]!=array_test_1[i])
			{
				index=0;
				break;
			}	
		return index;
	}
		//**************************************	Exponent([62:52]) as 3-bit delta from bias (1023)
int  Test_exponent_4_64_bit_word (int *array_test_0)
	{
		int index=14;
		for (int i=56;i<63;i++)
			if(array_test_0[55]!=array_test_0[i])
			{
				index=0;
				break;
			}	
		
		return index;
	}

	//########################################################64b Base--> {54b delta} x 4 + {53b delta} x 3  
int  Test_full_64_bit_word (int *array_test)
	{	
		int index=101;
		int tmp_cache_line[512];

		for(int j=1;j<5;j++)
			{
				for(int i=54;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=5;j<8;j++)
			{
				for(int i=53;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################32b Base--> {28b delta} x 2 + {27b delta} x 13    
int  Test_full_32_bit_word (int *array_test)
	{	
		int index=102;
		int tmp_cache_line[512];

		for(int j=1;j<3;j++)
			{
				for(int i=28;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=3;j<16;j++)
			{
				for(int i=27;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################16b Base-->  {14b delta} x 20 + {13b delta} x 11
	int  Test_full_16_bit_word (int *array_test)
	{	
		int index=103;
		int tmp_cache_line[512];

		for(int j=1;j<21;j++)
			{
				for(int i=14;i<16;i++)
				{
					if(array_test[i]!=array_test[i+16*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=21;j<32;j++)
			{
				for(int i=13;i<16;i++)
				{
					if(array_test[i]!=array_test[i+16*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################8b Base-->  {7b delta} x 53 + {6b delta} x 10
	int  Test_full_8_bit_word (int *array_test)
	{	
		int index=104;
		int tmp_cache_line[512];

		for(int j=1;j<54;j++)
			{
				for(int i=7;i<8;i++)
				{
					if(array_test[i]!=array_test[i+8*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=54;j<64;j++)
			{
				for(int i=6;i<8;i++)
				{
					if(array_test[i]!=array_test[i+8*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################64b Base double-->  {54b delta} x 7
	int  Test_full_64_double_bit_word (int *array_test)
	{	
		int index=105;
		int tmp_cache_line[512];

		for(int j=1;j<8;j++)
			{
				for(int i=54;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		return index;
	}
		//########################################################32b Base float-->  {28b delta} x 3 + {27b delta} x 12
	int  Test_full_32_float_bit_word (int *array_test)
	{	
		int index=106;
		int tmp_cache_line[512];

		for(int j=1;j<4;j++)
			{
				for(int i=28;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=4;j<16;j++)
			{
				for(int i=27;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}

	//########################480-bit layout################################
	//######################################################################
	//######################################################################64b Base--> {59b delta} x 1 + {58b delta} x 6￼￼￼￼
int  Test_480_full_64_bit_word (int *array_test)
	{	
		int index=201;
		int tmp_cache_line[512];

		for(int j=1;j<2;j++)
			{
				for(int i=59;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=2;j<8;j++)
			{
				for(int i=58;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################{32b base}    30b delta} x 4 + {29b delta} x 11    
int  Test_480_full_32_bit_word (int *array_test)
	{	
		int index=202;
		int tmp_cache_line[512];

		for(int j=1;j<5;j++)
			{
				for(int i=30;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=5;j<16;j++)
			{
				for(int i=29;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################16b B  {15b delta} x 21 + {14b delta} x 10
	int  Test_480_full_16_bit_word (int *array_test)
	{	
		int index=203;
		int tmp_cache_line[512];

		for(int j=1;j<22;j++)
			{
				for(int i=15;i<16;i++)
				{
					if(array_test[i]!=array_test[i+16*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=22;j<32;j++)
			{
				for(int i=14;i<16;i++)
				{
					if(array_test[i]!=array_test[i+16*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################8b B    {8b delta} x 22 + {7b delta} x 41
	int  Test_480_full_8_bit_word (int *array_test)
	{	
		int index=204;
		int tmp_cache_line[512];

		for(int j=1;j<23;j++)
			{
				for(int i=8;i<8;i++)
				{
					if(array_test[i]!=array_test[i+8*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=23;j<64;j++)
			{
				for(int i=7;i<8;i++)
				{
					if(array_test[i]!=array_test[i+8*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
	//########################################################64b base (double)     {59b delta} x 2 + {58b delta} x 5
	int  Test_480_full_64_double_bit_word (int *array_test)
	{	
			int index=205;
		int tmp_cache_line[512];

		for(int j=1;j<3;j++)
			{
				for(int i=59;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=3;j<8;j++)
			{
				for(int i=58;i<64;i++)
				{
					if(array_test[i]!=array_test[i+64*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}
		//########################################################32b Base float-->  {30b delta} x 5 + {29b delta} x 10
	int  Test_480_full_32_float_bit_word (int *array_test)
	{	
		int index=206;
		int tmp_cache_line[512];

		for(int j=1;j<6;j++)
			{
				for(int i=30;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}

					if(index==0)
						break;
				}
					if(index==0)
						break;
			}

		if(index!=0)
		{
			for(int j=6;j<16;j++)
			{
				for(int i=29;i<32;i++)
				{
					if(array_test[i]!=array_test[i+32*j])
					{
						index=0;
					}
					if(index==0)
						break;
				}
				if(index==0)
						break;
			}
		}

		return index;
	}

//########################################################################################################################################## 
//>>>>>>>>>>>>>>>>>>Variable Length Compression START:**************************************************************************************
//########################################################################################################################################## 
int vlc_code()
{
		int i,j,k;
	for(i=0;i<8;i++)
				{
					for(j=0;j<64;j++)
								current_word[j]=input_string[i*64+j];
					//-----------------All Zeros-------------------------
						check_id=Test_all_zeros(current_word);

						if(check_id==1)
						{
							compressed_line_vlc[current_pointer_vlc+0]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1  Test_all_zeros\n";
							current_pointer_vlc+=3;
						}
					//---------------------------------------------------
					if(i>0 && check_id==0)
					{
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-1)*64];
						check_id=Test_previous_64_bit_word(previous_word,current_word);

						if(check_id==2)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0 Test_previous_64_bit_word\n";
							current_pointer_vlc+=4;
						}


					}
					//---------------------------------------------------
					if(i>1 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-2)*64];

						check_id=Test_previous_previous_64_bit_word(previous_word,current_word);

						if(check_id==3)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1"; 
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+4]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+5]=0;//cout<<"0 Test_previous_previous_64_bit_word\n";
							current_pointer_vlc+=6;
						}
					}
					//---------------------------------------------------
					if(i>3 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-4)*64];

						check_id=Test_previous_previous_previous_previous_64_bit_word(previous_word,current_word);

						if(check_id==4)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+4]=0;//cout<<"0 Test_previous_previous_previous_previous_64_bit_word\n";
							current_pointer_vlc+=5;
						}
					}
					//---------------------------------------------------

					if(check_id==0)
					{			
						
						check_id=Test_32data_32zero_64_bit_word(current_word);

						if(check_id==5)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+4]=0;//cout<<"0 Test_32data_32zero_64_bit_word\n";
							current_pointer_vlc+=5;

							for(j=0;j<32;j++)
								{
									compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
									cout<<compressed_line_vlc[current_pointer_vlc+j];
								}
							current_pointer_vlc+=32;
							//cout<<"   \n";
							
						}
					}
					//---------------------------------------------------
					if(check_id==0)
					{			
						
						check_id=Test_16_bit_sign_64_bit_word(current_word);

						if(check_id==6)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+4]=1;//cout<<"1 Test_16_bit_sign_64_bit_word\n";
							current_pointer_vlc+=5;

							for(j=0;j<16;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								compressed_line_vlc[current_pointer_vlc+j+16]=current_word[j+16];
							}
							for(j=0;j<32;j++)
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							current_pointer_vlc+=32;
							//cout<<"   \n";
								
						}
					}
					//---------------------------------------------------
						if(check_id==0)
					{			
						
						check_id=Test_32_bit_sign_64_bit_word(current_word);

						if(check_id==7)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=0;//cout<<"0 Test_32_bit_sign_64_bit_word\n";
							current_pointer_vlc+=4;

							for(j=0;j<32;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=32;
							//cout<<"   \n";
						}
					}
					//---------------------------------------------------

					if(i>0 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-1)*64];

						check_id=Test_44_bit_delta_previous_64_bit_word(previous_word,current_word);

						if(check_id==8)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+4]=1;//cout<<"1 Test_44_bit_delta_previous_64_bit_word\n";
							current_pointer_vlc+=5;
							for(j=0;j<44;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=44;
							//cout<<"   \n";
						}
					}
				//---------------------------------------------------
					if(i>0 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-1)*64];

						check_id=Test_52_bit_delta_previous_64_bit_word(previous_word,current_word);

						if(check_id==9)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1 Test_52_bit_delta_previous_64_bit_word\n";
							current_pointer_vlc+=4;
							for(j=0;j<52;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=52;
							//cout<<"   \n";
						}
					}  
				//---------------------------------------------------
					if(i>1 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-2)*64];

						check_id=Test_12_bit_delta_previous_previous_64_bit_word(previous_word,current_word);

						if(check_id==10)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1 Test_12_bit_delta_previous_previous_64_bit_word\n";
							current_pointer_vlc+=4;
							for(j=0;j<12;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=12;
							//cout<<"   \n";
						}
					}
				//---------------------------------------------------
					if(check_id==0)
					{			
						
						check_id=Test_sign_exponent_1_64_bit_word(current_word);

						if(check_id==11)
						{
							compressed_line_vlc[current_pointer_vlc+0]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0 Test_sign_exponent_1_64_bit_word\n";
							current_pointer_vlc+=3;
							for(j=0;j<56;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=56;
							//cout<<"   \n";
						}
					}
				//---------------------------------------------------
					if(check_id==0)
					{			
						
						check_id=Test_sign_exponent_2_64_bit_word(current_word);

						if(check_id==12)
						{
							compressed_line_vlc[current_pointer_vlc+0]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1 Test_sign_exponent_2_64_bit_word\n";
							current_pointer_vlc+=3;
							for(j=0;j<60;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=60;
							//cout<<"  \n";
						}
					}
				//---------------------------------------------------
					if(i>0 && check_id==0)
					{			
						for(j=0;j<64;j++)
							previous_word[j]=input_string[j+(i-1)*64];

						check_id=Test_sign_exponent_3_64_bit_word(previous_word,current_word);

						if(check_id==13)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0";
							compressed_line_vlc[current_pointer_vlc+3]=0;//cout<<"0 Test_sign_exponent_3_64_bit_word\n";
							current_pointer_vlc+=4;
							for(j=0;j<56;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=56;
							//cout<<"   \n";
						}

					}
				//---------------------------------------------------
					if(check_id==0)
					{			
						
						check_id=Test_exponent_4_64_bit_word(current_word);

						if(check_id==14)
						{
							compressed_line_vlc[current_pointer_vlc+0]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+1]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+2]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+3]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+4]=1;//cout<<"1";
							compressed_line_vlc[current_pointer_vlc+5]=1;//cout<<"1 Test_exponent_4_64_bit_word\n";
							current_pointer_vlc+=6;
							for(j=0;j<55;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							current_pointer_vlc+=55;
							compressed_line_vlc[current_pointer_vlc]=current_word[63];
							cout<<compressed_line_vlc[current_pointer_vlc];
							current_pointer_vlc++;
							//cout<<"   \n";
						}
						
					}
				//---------------------------------------------------
					if(check_id==0)
					{
						compressed_line_vlc[current_pointer_vlc+0]=0;//cout<<"0";
						compressed_line_vlc[current_pointer_vlc+1]=0;//cout<<"0";
						compressed_line_vlc[current_pointer_vlc+2]=0;//cout<<"0 Incompressible 64-bit\n";
						current_pointer_vlc+=3;
						for(j=0;j<64;j++)
							{
								compressed_line_vlc[current_pointer_vlc+j]=current_word[j];
								cout<<compressed_line_vlc[current_pointer_vlc+j];
							}
							
								current_pointer_vlc+=64;
						//cout<<"   \n";
					}
					
				//---------------------------------------------------

					//cout<<"\n";
			}

	return current_pointer_vlc;
}

//########################################################################################################################################## 
//>>>>>>>>>>>>>>>>>>Variable Length Compression END*****************************************************************************************
//##########################################################################################################################################

	