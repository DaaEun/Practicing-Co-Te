import java.util.*;

public class Main {
	/*
		 나날이 심해지는 미세먼지로 인해 야외뿐만 아니라 집 안에서도 마음 놓을 수 없는 날이 계속되고 있다.
		유해 물질이 창문 틈새로 새어 들어오거나, 외출 후 옷과 신발 등에 붙어 들어와 집 안이 오염될 수 있기 때문이다.
		현대자동차그룹에서는 입주민들이 미세먼지 걱정없이 집 안을 깨끗하게 유지할 수 있도록 세대 내부에도 H 클린알파(H Cleanα)를 도입했다.
		미세먼지 제거와 공기 정화는 물론, 바이러스와 세균까지 잡아주는 기술이다.
		
		H 클린알파의 성능 테스트를 위해서 아래와 같은 조건을 가정한다.
		     1) 1초 간격으로 바이러스들이 집 안으로 침입한다
		     2) 집 안에서 바이러스는 1초당 P배씩 증가한다
		     3) N초 동안 죽는 바이러스는 없다
		
		매초 집 안에 침입하는 바이러스의 숫자가 주어질 때, N초 후에는 총 몇 마리의 바이러스를 잡아야 할까?
		입력형식
		첫 번째 줄에 증가율 P, 총 시간 N(초)이 주어진다.
		두 번째 줄에 매초 침입하는 바이러스의 숫자 Ai (1 ≤ i ≤ N)가 주어진다.
		
		입력은 다음 조건을 만족한다.
		     1 ≤ P ≤ 108 인 정수
		     1 ≤ N ≤ 106 인 정수
		     1 ≤ Ai ≤ 108 인 정수
		     
		최종 바이러스 개수를 1000000007로 나눈 나머지를 출력하라. 
		
		입력예제
		3 3
		1 2 3
		출력예제
		18    
	 */
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		// p, n 값 받아오기
		String str = sc.nextLine();
		String[] pn = str.split(" ");
		int p = Integer.parseInt(pn[0]);
		int n = Integer.parseInt(pn[1]);
		// 바이러스의 숫자들 a 받아오기
		int[] a = new int[n];		
		String str2 = sc.nextLine();
		String[] arr = str2.split(" ");
		for(int i = 0; i < n; i++)	a[i] = Integer.parseInt(arr[i]);
		
		int total = 0;
		for(int j = 0; j < n; j++) {
			total += a[j] * Math.pow(p, n-j);
		}
		
		int answer = total % 1000000007;
		
		System.out.println(answer);
		sc.close();
	}
}
