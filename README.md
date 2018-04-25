# Assignment2
## 0.팀원
팀장

2017202020 이한수 (droplet92)

팀원

2011722001 송민준 (cocoapi)

2017202003 이준혁 (merong245)

2017202026 최형석 (choifluor)

## 1.시작하기
해당프로젝트를 포크해서 진행해주세요.
포크된 내용은 개인의 repository안의 Assignment2에 저장됩니다.
```
git clone https://github.com/[username]/Assignment2.git
cd Assignment2
git checkout -b [branch_name]
```
으로 개별 브랜치 생성후 작업해주세요

## 2.출력예시
```
size compare
text2 is bigger

block compare
text2 is bigger

date compare
same date

time compare
same time
```

## 3.upstream 동기화
```
git remote add upstream https://github.com/droplet92/Assignment2.git
git fetch upstream master
git checkout master
git merge upstream master
```


## 4.참고자료
[stat(2) manpage](http://man7.org/linux/man-pages/man2/stat.2.html)  
[struct tm](http://www.cplusplus.com/reference/ctime/tm/)  

