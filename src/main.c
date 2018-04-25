#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
  const char* filename = "./text1";

  if (stat(filename, &stat1)) {
    puts("invalid filename");
  }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
  const char* filename = "./text2";

  if (stat(filename, &stat2)) {
    puts("invalid filename");
  }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	if(stat1){
		time1 = stat1.st_mtime;
	}
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	if(stat2){
		time2 = stat2.st_mtime;
	}
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	
	int result=0;

	result=time1->tm_mon-time2->tm_mon;

	puts("date compare");

	switch(result)
	{
	case result>0:
	puts("text2 is early");
	break;
	
	case result<0:
	puts("text1 is early");	
	break;

	default:
	result=time1->tm_mday - time2->tm_mday;
	switch(result)
	{
		case result>0:
		puts("text2 is early");
		break;
		
		case result<0:
		puts("text1 is early");	
		break;
	
		default:
		puts("same date");
		break;
	}
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	int result=0;

	result=time1->tm_hour-time2->tm_hour;

	puts("time compare");

	switch(result)
	{
	case result>0:
	puts("text2 is early");
	break;
	
	case result<0:
	puts("text1 is early");	
	break;

	default:
	result=time1->tm_min - time2->tm_min;
	switch(result)
	{
		case result>0:
		puts("text2 is early");
		break;
		
		case result<0:
		puts("text1 is early");	
		break;
	
		default:
		puts("same time");
		break;
	}
	}
}

