// 2week.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
SceneID scene1;
ObjectID ob[4];
int x = 0, speed = 20;
TimerID timer1, timer2, timer3;

int ob_x[4];

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;

}

void keyboardCallback(KeyCode code, KeyState state) {
	if (code == KeyCode::KEY_SPACE) {

	}
}
void tiemrCallback(TimerID timer) {
	if (timer == timer3) {
		for (int i = 0; i < 4; i++) {
			hideObject(ob[i]);//필요없을지도
			if (ob_x[i] >= -100) {
				ob_x[i] -= speed;
				locateObject(ob[i], scene1, ob_x[i], 0);
				showObject(ob[i]);//필요없을지도
			}
			else if (ob_x[i] < -100) {
				startTimer(timer1);
				
				if (i == 0) {					
					ob_x[i] = 1800;
					int n = rand() % 3;
					switch (n) {
					case 0: setObjectImage(ob[i], "gift.jpg"); break;
					case 1: setObjectImage(ob[i], "end.png"); break;
					case 2: setObjectImage(ob[i], "tree.png"); break;
					}
					break;
					locateObject(ob[i], scene1, ob_x[i], 0);
					showObject(ob[i]);
					
				}


				else if (i == 1) {
					int n = rand() % 3;
					switch (n) {
					case 0: ob_x[i] = ob_x[0] + 400 + x, setObjectImage(ob[i], "gift.jpg"); break;
					case 1: ob_x[i] = ob_x[0] + 450 + x, setObjectImage(ob[i], "end.png"); break;
					case 2: ob_x[i] = ob_x[0] + 500 + x, setObjectImage(ob[i], "tree.png"); break;
					}				
					locateObject(ob[i], scene1, ob_x[i], 0);
					showObject(ob[i]);
				}
				
				else if (i == 2) {
					int n = rand() % 3;
					switch (n) {
					case 0: ob_x[i] = ob_x[1] + 400 + x, setObjectImage(ob[i], "gift.jpg"); break;
					case 1: ob_x[i] = ob_x[1] + 450 + x, setObjectImage(ob[i], "tree.png"); break;
					case 2: ob_x[i] = ob_x[1] + 500 + x, setObjectImage(ob[i], "end.png"); break;
					}
					locateObject(ob[i], scene1, ob_x[i], 0);
					showObject(ob[i]);
			
				}
				else if (i == 3) {
					int n = rand() % 3;
					switch (n) {
					case 0: ob_x[i] = ob_x[2] + 400 + x, setObjectImage(ob[i], "gift.jpg"); break;
					case 1: ob_x[i] = ob_x[2] + 450 + x, setObjectImage(ob[i], "tree.png"); break;
					case 2: ob_x[i] = ob_x[2] + 500 + x, setObjectImage(ob[i], "end.png"); break;
					}
					locateObject(ob[i], scene1, ob_x[i], 0);
					showObject(ob[i]);

				}
			}
			
		}
		setTimer(timer3, 0.1f);
		startTimer(timer3);
	}
	if (timer == timer1) {
		if (speed <= 50) {
			x += 2;
			speed += 2;
			setTimer(timer1, 0.1f);

		}
	}
	
}




int main()
{
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	
	setKeyboardCallback(keyboardCallback);
	setTimerCallback(tiemrCallback);
	scene1 = createScene("back");
	
	timer1 = createTimer(0.1f);
	
	timer3 = createTimer(0.01f);

	

	for (int i = 0; i < 4; i++) {
		ob_x[i] = 500 + 500 * i;
;		ob[i] = createObject("gift.jpg", scene1, ob_x[i], 0, true);
	}
	startTimer(timer3);
	
	startGame(scene1);
	
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
