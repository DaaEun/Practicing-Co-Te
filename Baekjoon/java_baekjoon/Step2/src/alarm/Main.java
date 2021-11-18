package alarm;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		
		if(h < 0 || h > 23) {
			System.out.println("잘못된 시(h)정보 입니다.");
		}
		
		if(m < 0 || m > 59) {
			System.out.println("잘못된 분(m)정보 입니다.");
		}

		// 알람시계 맞추기
		int alarmH;
		int alarmM;
		
		if(m >= 45) {
			alarmH = h;
			alarmM = m - 45;
		}
		else {
			alarmM = (60 + m) - 45;
			if(h == 0) {
				alarmH = 23;
			}
			else {
				alarmH = h - 1;
			}
		}
		
		System.out.println(alarmH + " " + alarmM);
		
		sc.close();
	}

}
