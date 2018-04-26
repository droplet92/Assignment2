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
	static struct tm t1;
	t1 = *(localtime(&stat1.st_mtime));
	time1 = &t1;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	static struct tm t2;
	t2 = *(localtime(&stat2.st_mtime));
	time2 = &t2;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
  puts("size compare");
  if (stat1.st_size > stat2.st_size)
    puts("text1 is bigger");
  else if (stat1.st_size < stat2.st_size)
    puts("text2 is bigger");
  else
    puts("sizes are equal");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
  puts("block compare");
  if (stat1.st_blksize > stat2.st_blksize)
    puts("text1 is bigger");
  else if (stat1.st_blksize < stat2.st_blksize)
    puts("text2 is bigger");
  else
    puts("sizes are equal");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	puts("date compare");
	//month 또는 date가 작을수록 빨리 만들어진 파일 
	if (time1->tm_mon < time2->tm_mon)
		puts("text1 is early");
	else if (time1->tm_mon > time2->tm_mon)
		puts("text2 is early");
	else
	{
		if (time1->tm_mday < time2->tm_mday)
			puts("text1 is early");
		else if (time1->tm_mday == time2->tm_mday)
			puts("same date");
		else
			puts("text2 is early");
	}

}


	//두 개의 파일 수정 시간 비교하는 함수 작성
void timecmp(void)
{
	puts("time compare");

	//hour 또는 min이 작을수록 빨리 만들어진 파일 
	if (time1->tm_hour < time2->tm_hour)
		puts("text1 is early");
	else if (time1->tm_hour > time2->tm_hour)
		puts("text2 is early");
	else
	{
		if (time1->tm_min < time2->tm_min)
			puts("text1 is early");
		else if (time1->tm_min == time2->tm_min)
			puts("same time");
		else
			puts("text2 is early");
	}

	
}


