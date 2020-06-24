#include<iostream>
using namespace std;
#include<cmath>
#include<stdlib.h>
#define END_TIME 1 //終了時刻を１日とした
#define try 1000 //試行回数
double rand_val() {//0から1の一様分布
	double a;
	a = (rand() + 0.5) / (RAND_MAX + 1);
	return a;
}
double rnd_exp(double ramda) {//指数分布の乱数作成
	return -log(1 - rand_val()) / ramda;
}

int main() {
	srand(18140024);
	int count = 0;
	double sum = 0;
	double ramda = 10;//バスの到達区間を単位時間平均10回来るように設定
	for (int i = 0; i < try; i++) {
		double time = 0;
		double pretime = 0;
		while (true) {
			double x = rnd_exp(ramda);
			time += x;//バス到達時刻時刻を更新
			pretime = time - x;//前のバスの到達時刻を更新
			double y = rnd_exp(1);//乗客は単位時間あたりに一回来る->０から1の間に乱数が1回発生
			if (pretime <= y && y <= time) {//乗客が前のバスと今のバスの間にいた場合の処理
				sum += time - y;
				count += 1;
			}
			if (time > END_TIME) {//終了時刻の時の処理
				time -= x;
				break;
			}

		}
	}
	cout <<sum/count<< endl;//乗客の待ち時間を計算

}
