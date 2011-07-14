// Visual Studio setting.
//
// -m sequence K.xml -sift
// 
// Please set working directory as $(SolutionDir)
//
// Set .exe output directory as 
// $(SolutionDir)bin

#include <stdio.h>
#include <string.h>

#include "sfm.h"

/// �ΰ��� �ɼ��� ����. Structure from Motion�� �ϴ���, Sequence Play�� �ϴ���.
#define doSFM		0
#define doPlaySeq	1

/**
 * ���� �Լ� : Ŀ�ǵ���� ��ǲ�� �޾Ƽ� �ش� �Լ��� �б�.
 * 
 * \author Hyon Lim
 *
 * Usage : main [-s|-p] [<sequence-path>] [<K-matrix.xml>] [-harris|-sift|-surf]
 *
 * - -s  SfM�� �����Ѵ�.
 * - -p  Sequence�� ����Ѵ�.
**/
int main(int argc,char *argv[])
{
	int option = -1;
	int featureExtractor = HARRIS;	// Default value

	/// Information
	printf("================================\n");
	printf(" Working path : %s\n",argv[1]);
	printf("================================\n");

	/// Input variable find
	if (argc >= 3)
	{
		if(argc >= 4 && strcmp(argv[1], "-m") == 0)
		{
			option = doSFM;
		}
		else if(strcmp(argv[1], "-p") == 0)
		{
			option = doPlaySeq;
		}

		if(argc >= 5 && strcmp(argv[4], "-harris") == 0)
		{
			featureExtractor = HARRIS;
		}
		else if(argc >= 5 && strcmp(argv[4], "-sift") == 0)
		{
			featureExtractor = SIFT;
		}
		else if(argc >= 5 && strcmp(argv[4], "-surf") == 0)
		{
			featureExtractor = SURF;
		}
	}

	switch(option)
	{
		case doSFM:
			SfM(argv[2], argv[3], featureExtractor);
			break;

		case doPlaySeq:
			break;

		default:
			printf("Usage : %s [-s|-p] [<sequence-path>] [<K-matrix.xml>]\n", argv[0]);
			printf("-s\tdo structure from motion (K matrix required)\n");
			printf("-p\tplay the sequence\n");
			break;
	}

	return 0;
}