const int mx = 305, inf = (1 << 31) - 1;
int * num_x, * num_y;
int price[mx][mx], lx[mx], ly[mx], linky[mx], slack[mx], visx[mx], visy[mx];

int find_zgl(int x)
{
	visx[x] = 1;//用于后面x减d判断是否已经选择
	for (int i = 0; i < *num_y; ++i) {
		if (!visy[i]) {
			int t = lx[x] + ly[i] - price[x][i];
			if (!t) {
				visy[i] = 1;
				if (linky[i] == -1 || find_zgl(linky[i])) { //此y点没有连接点或能找到新的增广路
					linky[i] = x;
					return 1;
				}
			}
			else if (slack[i] > t) { //更新slack值
				slack[i] = t;
			}
		}
	}
	return 0;
}

int KM()
{
	memset(ly, 0, sizeof(ly));
	memset(linky, -1, sizeof(linky));
	for (int i = 0; i < *num_x; ++i) {
		lx[i] = -inf;
		for (int j = 0; j < *num_y; ++j) {
			if (price[i][j] > lx[i]) lx[i] = price[i][j];
		}
	}
	//以上为初始化 ly为0 lx为与其连接的最大边权 linky为-1
	for (int x = 0; x < *num_x; ++x) { //执行n次 将整个x全部包含在内
		for (int i = 0; i < *num_y; ++i) slack[i] = inf;//slack[i]为与y中lx[x] + ly[i] - price[i]的最小值 便于计算后面的d值 为什么每次都要初始化 按理说lx、ly值不变 slack的值也不会变啊
		while (true) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (find_zgl(x)) break;
			int d = inf;
			for (int i = 0; i < *num_y; ++i) {
				if (!visy[i] && d > slack[i]) d = slack[i];
			}
			for (int i = 0; i < *num_x; ++i) {
				if (visx[i]) lx[i] -= d;//将已选中的x中的点的lx的值减去d 使外界lx[x] + ly[i] - price[i]有为0的 使find_zgl()返回值为1
			}
			for (int i = 0; i < *num_y; ++i) {
				if (visy[i]) ly[i] += d;//保证已选中的点中lx[x] + ly[i] - price[i]值不会变
				else slack[i] -= d;//未选中的y点的slack值减去d 直接处理了
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (linky[i] > -1) res += price[linky[i]][i];
	}
	return res;
}
