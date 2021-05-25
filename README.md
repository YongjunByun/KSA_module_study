# KSA_PostfixCalculator
PostfixCalcutlater on Android Studio with java language.   

[KSA 팀 프로젝트]   
마지막 수정일 : 2021.05.25.   
참여자 : 이철용, 변용준   
  

## 0. 들어가기전
>본 프로젝트는 후위연산을 사용하여 공학용 계산기 어플을 구현하는 것이다. Postfix클래스에서 등장하는 후위연산 스택 알고리즘은 
https://github.com/saimaduri/Android-Postfix-Calculator 의 후위연산 코드를 참고하여 본 프로젝트의 요구사항에 맞게 수정하였음을 미리 밝힌다.


## 1. 요구사항 분석
>후위연산이 가능한 공학용 계산기 구현


## 2. 구조설계
>2-1) UML (Unified Modeling Language)Diagram
>  >(1) Use Case Diagram
>  >
>  >![image](https://user-images.githubusercontent.com/82483513/117675756-d3912a80-b1e7-11eb-93e6-399863d7946d.png)
>  >
>  >(2) Sequence Diagram
>  >
>  >![image](https://user-images.githubusercontent.com/82483513/117676756-cc1e5100-b1e8-11eb-8e76-9f56c0650ef9.png)
>  >
>  >(3) Class Diagram
>  >
>  >![image](https://user-images.githubusercontent.com/82483513/117676871-e821f280-b1e8-11eb-96fe-6ce4dbb82df9.png)


## 3. 입출력 Data 정의
>Data 종류 : 피연산자(double), 연산자(char)“0~9“, (, ), +, -, *, /, log10, mod, exp, pow, !, cos, tan, sin, clear, delete, =


## 4. Algorithms 설계&구현
>(1) MainActivtiy 알고리즘 설계 순서도
>
>![image](https://user-images.githubusercontent.com/82483513/117677259-43ec7b80-b1e9-11eb-8fef-56000dc293a3.png)
>
>(2) Postfix 알고리즘 
>
>![image](https://user-images.githubusercontent.com/82483513/117677410-6088b380-b1e9-11eb-8e3a-418fbe315629.png)


## 5. 코딩 및 test
>(1) 숫자입력 및 후위 연산
>
>![image](https://user-images.githubusercontent.com/82483513/117677469-74341a00-b1e9-11eb-8c37-fc1f8dc6a4d5.png)
>
>(2) log연산
>
>![image](https://user-images.githubusercontent.com/82483513/117677510-7c8c5500-b1e9-11eb-9e0d-30b121084355.png)
>
>(3) 삼각함수 연산 (RAD 값으로 출력)
>
>![image](https://user-images.githubusercontent.com/82483513/117677597-8f068e80-b1e9-11eb-8eaf-1065ed6ec57a.png)
>
>(4) 소숫점 연산
>
>![image](https://user-images.githubusercontent.com/82483513/117677648-9c237d80-b1e9-11eb-91d7-c0967f8c8440.png)
>
>(5) Clear 기능
>
>![image](https://user-images.githubusercontent.com/82483513/117677689-a6457c00-b1e9-11eb-80dd-32e59d863022.png)
