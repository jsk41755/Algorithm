class Solution {
    public long solution(int k, int d) {
        long answer = 0;
        long n = (long) d * d;

        for (int i = 0; i <= d; i += k) {
            int l = 0, r = d;
            int t = 0;
            while (l <= r) {
                int mid = (l + r) / 2;

                if ((long) mid * mid + (long) i * i <= n) {
                    l = mid + 1;
                    t = mid;  // 항상 최댓값을 `t`에 할당
                } else {
                    r = mid - 1;
                }
            }
            answer += t / k + 1;  // 정확한 개수 계산
        }

        return answer;
    }
}
