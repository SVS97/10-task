#include <stdio.h>

// State definitions, states are the routine the program jumps to, these are prefixed with an 'S'
enum states { S_OFF, S_ON, S_ESP_R, S_ESP_M, S_STEAM_R, S_STEAM_M };
enum events { E_OFF, E_ON, E_HEADUP, E_STEAMon, E_STEAMoff, E_ESPoff, E_ESPon, E_KNOBfor, E_KNOBback, E_ESPMAKE };
// Global variables
int	Current_State = S_OFF;

char* StateToStr(enum states st)
{
	switch (st)
	{
	case S_OFF:
		return "S_OFF";
		break;

	case S_ON:
		return "S_ON";
		break;

	default:
		return "Unknown";
		break;
	}
}

char * EvtToStr(enum events evt)
{
	return "XYZ";
}

void StateOffToOnProcessing()
{
	printf("Working on %s\n", __func__);
}

void StateM(enum events event)
{
	int Previous_State = Current_State;	//!!!!! 


	switch (Current_State)	
	{					
	case S_OFF:			
		switch (event)		
		{
		case E_ON:
			StateOffToOnProcessing();
			Current_State = S_ON;
			printf("State switch. From = %s, to = %s, by event = %s\n", StateToStr(Previous_State), StateToStr(Current_State), EvtToStr(event));
			break;

		default: 
		return "Unknown";
			break;
		}
		break;

	case S_ON:
		switch (event)
		{
		case E_HEADUP:
			Current_State = S_ESP_R;
			break;
		case E_OFF:
			Current_State = S_OFF;
			break;

		}
	default:
		return "Unknown";
		break;

	case S_ESP_R:		
		switch (event)	
		{
		case E_ESPon:
			Current_State = S_ESP_M; 
			break;
		case E_STEAMon:
			Current_State = S_STEAM_R;
			break;
		case E_OFF:
			Current_State = S_OFF;
		default:
			return "Unknown";
			break;

		}
	case S_ESP_M:
		switch (event)
		{
		case E_ESPoff:
			Current_State = S_ESP_R;
		default:
			return "Unknown";
			break;

		}


	case S_STEAM_R:
		switch (event)
		{
		case E_KNOBfor:
			Current_State = S_STEAM_M;
			break;
		case E_OFF:
			Current_State = S_OFF;
			break;
		case E_STEAMoff:
			Current_State = S_ESP_R;
			
		default:
			return "Unknown";
			break;
		}
	case S_STEAM_M:
		switch (event)
		{
		case E_KNOBback:
			Current_State = S_STEAM_R;
		default:
			return "Unknown";
			break;
		}
	
		break;

	}
}

int main(void)
{
	printf("STATE MACHINE TESTING STARTED!!!\n\n");
	//
	StateM(E_ON);

	//
	printf("\nTESTING COMPLITED!\n");
}









