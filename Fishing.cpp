#include<iostream>

using namespace std;

int visit[61], visit_cong[3], n, vitri_cong[3], sl_nguoi[3], kq;

int tinh(int vt_cong, int sl, int uu_tien){

	int kc = 0;
	if (visit[vt_cong] == 0)
	{
		sl--;
		visit[vt_cong] = 1;
		kc++;
	}
	int left = vt_cong - 1;
	int right = vt_cong + 1;
	if (uu_tien == 0)
	{
		while (sl > 0)
		{
			// Xet trai
			if (left > 0 && visit[left] == 0)
			{
				sl--;
				visit[left] = 1;
				kc+= vt_cong - left + 1;
				if (sl == 0) break;
			}
			// xet phai
			if (visit[right] == 0 && right <= n)
			{
				sl--;
				visit[right] = 1;
				kc+= right - vt_cong + 1;
				if (sl == 0) break;
			}
			left--;
			right++;
		}
	}else
	{
		while (sl > 0)
		{
			// xet phai
			if (visit[right] == 0 && right <= n)
			{
				sl--;
				visit[right] = 1;
				kc+= right - vt_cong + 1;
				if (sl == 0) break;
			}
			// Xet trai
			if (left > 0 && visit[left] == 0)
			{
				sl--;
				visit[left] = 1;
				kc+= vt_cong - left + 1;
				if (sl == 0) break;
			}
			left--;
			right++;
		}
	}
	
	return kc;
}

void back_track(int dem, int kc, int uu_tien){
	if (dem == 3)
	{
		if (kc < kq)
		{
			kq = kc;
		}
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (visit_cong[i] == 0)
		{
			visit_cong[i] = 1;
			int back_up[61];
			for (int j = 1; j <= n; j++)
			{
				back_up[j] = visit[j];
			}
			back_track(dem+1, kc + tinh(vitri_cong[i], sl_nguoi[i], uu_tien), uu_tien);
			visit_cong[i] = 0;
			for (int j = 1; j <= n; j++)
			{
				visit[j] = back_up[j];
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			visit[i] = 0;
		}
		for (int i = 0; i < 3; i++)
		{
			cin >> vitri_cong[i] >> sl_nguoi[i];
			visit_cong[i] = 0;
		}
		kq = 9999;
		back_track(0, 0, 0);
		back_track(0, 0, 1);
		cout << "Case #" << t << "\n";
		cout << kq << "\n";

	}
	return 0;
}
