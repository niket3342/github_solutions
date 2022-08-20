for (int i = 0; i <= n; i++) dp[i][0] = startFuel;
​
for (int i = 0; i < n; i++)
for (int j = 0; j <= i; j++) {
if (i >= j+1)
dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
if (dp[i][j] >= stations[i][0])
dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + stations[i][1]);
}
dp[0] = startFuel;
for (int i = 0; i < n; i++)
for (int j = i; j >= 0; j--) {
if (dp[j] >= stations[i][0])
dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
}