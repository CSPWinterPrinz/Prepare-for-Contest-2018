#include <bits/stdc++.h>
#define N 1001
using namespace std;
/*
void Debug()
{

    for(int i = 1; i <= cnt_S; i++)
        cout << Char_S[i] << " " << Num_S[i] << endl;
    cout << endl;
    for(int i = 1; i <= cnt_T; i++)
        cout << Char_T[i] << " " << Num_T[i] << endl;
}*/

void Convert(string s, char res_char[N], int res_num[N], int &cnt)
{
    s = s + "z";
    //cout << s << endl;
    int n = s.length() - 1, num = 0;

    for(int i = 0; i <= n; i++)
    {
        if(s[i] >= 'a') {
            res_num[cnt] = num;
            num = 0;
            res_char[++cnt] = s[i];
        }
        else {
            num = num * 10 + (s[i] - '0');
        }

    }
    cnt--;
    s.erase(s.length() - 1,1);
    //cout << s << endl;
    return;
}

long long Convert2(string s)
{
    s = s + "z"; char res_char[N]; int res_num[N], cnt = 1;
    int n = s.length() - 1, num = 0;
    int Len = 0;

    for(int i = 0; i <= n; i++)
    {
        if(s[i] >= 'a') {
            res_num[cnt] = num;
            Len += res_num[cnt];
            num = 0;
            res_char[++cnt] = s[i];
        }
        else {
            num = num * 10 + (s[i] - '0');
        }
    }
    s.erase(s.length() - 1,1);
    return Len;
}

string Print(char Char_S[N], int Num_S[N], int fir, int las)
{
    string trunggian = "";
    string decimal[N];

    for(int i = fir; i <= las; i++)
    {
        int j = Num_S[i];
        while(j > 0) {
            decimal[i] = decimal[i] + (char)(j % 10 + 48);
            j /= 10;
        }
        for(int z = 0; z < decimal[i].length() / 2; z++)
            swap(decimal[i][z], decimal[i][decimal[i].length() - z - 1]);
        //cout << decimal[i] << endl;
    }

    for(int i = fir; i <= las; i++)
    {
        trunggian = trunggian + Char_S[i];
        trunggian = trunggian + decimal[i];
    }
    //cout << trunggian << endl;
    return trunggian;

}

string Querry_One_SUM_String(string s, string t)
{
    string ANS = "";
    int Num_T[N], Num_S[N], cnt_S = 0, cnt_T = 0;
    char Char_T[N], Char_S[N];
    //cout << s << " " << t << endl;
    Convert(s, Char_S, Num_S, cnt_S);
    Convert(t, Char_T, Num_T, cnt_T);

    /// mang chay tu 1 -> cnt_T or cnt_S
/*
    for(int i = 1; i <= cnt_S; i++)
        cout << Char_S[i] << " " << Num_S[i] << endl;
    cout << endl;
    for(int i = 1; i <= cnt_T; i++)
        cout << Char_T[i] << " " << Num_T[i] << endl;
*/

    if(Char_S[cnt_S] == Char_T[1]) {
        Num_S[cnt_S] += Num_T[1];
        ANS = ANS + Print(Char_S, Num_S, 1, cnt_S);
        ANS = ANS + Print(Char_T, Num_T, 2, cnt_T);
        //cout << Print(Char_S, Num_S, 1, cnt_S) << " " << Print(Char_T, Num_T, 2, cnt_T) << endl;
    }
    else {
        ANS = ANS + Print(Char_S, Num_S, 1, cnt_S);
        ANS = ANS + Print(Char_T, Num_T, 1, cnt_T);
    }
   // cout << ANS << endl;
    //cout << s << " " << t << endl;
    return ANS;
}

string Querry_Three_COPY_String(string s, int L, int H)
{
    int Num[N], res_num[N], len = 0, sum, sum2, cnt = 0;
    char Char[N], res_char[N];


    Convert(s, Char, Num, len);

    sum = 0; int i = 0;
    while(sum < L) {
        i++;
        sum += Num[i];
    } ; /// l thuoc Char_S (i)

    sum2 = 0; int j = 0;
    while(sum2 < H) {
        j++;
        sum2 += Num[j];
    } sum2 = sum2 - Num[j]; /// h thuoc Char_S(j)

    res_char[++cnt] = Char[i];
    res_num[cnt] = sum - L + 1;

    if(i == j) {
        res_num[cnt] = H - L + 1;
    }
    else {
        for(int z = i + 1; z < j; z++)
        {
            res_char[++cnt] = Char[z];
            res_num[cnt] = Num[z];
        }
        res_char[++cnt] = Char[j];
        res_num[cnt] = H - sum2;
    }

    //cout << i << " " << sum << " " << j << " " << sum2 << " " << L << " " << H << endl;
    ////cout << H << " "   << L << " " << res_num[cnt] << " " << cnt << " " << Num[cnt] << endl;

    string ANS = "";
    string decimal[N];

    for(int i = 1; i <= cnt; i++)
    {
        int j = res_num[i];
        while(j > 0) {
            decimal[i] = decimal[i] + (char)(j % 10 + 48);
            j /= 10;
        }
        for(int z = 0; z < decimal[i].length() / 2; z++)
            swap(decimal[i][z], decimal[i][decimal[i].length() - z - 1]);
        //cout << decimal[i] << endl;
    }

    for(int z = 1; z <= cnt; z++)
    {
        ANS = ANS + res_char[z];
        ANS = ANS + decimal[z];
        //cout << res_char[z] << " " << res_num[z] << endl;
    }
    //cout << ANS;
    return ANS;
}

bool Querry_Five_CHECK_Palin(string s)
{
    int Num_S[N], cnt_S = 0;
    char Char_S[N];
    Convert(s, Char_S, Num_S, cnt_S);
//    for(int i = 1; i <= cnt_S; i++)
  //      cout << Char_S[i] << " " << Num_S[i] << endl;
    //cout << cnt_S << endl;
    for(int i = 1; i <= cnt_S / 2; i++)
    {
        //cout << Char_S[i] << " " << Char_S[cnt_S - i + 1] << " " << Num_S[i] << " " << Num_S[cnt_S - i + 1] << endl;
        if(Char_S[i] != Char_S[cnt_S - i + 1] || Num_S[i] != Num_S[cnt_S - i + 1]) {return false;}

    }
    return true;
}

void Solve()
{
    string start;
    while(cin >> start)
    {
        if(start[1] == '1')  {
                string s, t;
                cin >> s; cin >> t; string RES = Querry_One_SUM_String(s, t);
                //cout << s << " " << t << endl;
                //cout << Querry_One_SUM_String(s, t) << endl;
                cout << RES;
                if(RES.length() == 1) cout << 1 << endl;
                else cout << endl;
        }


        else if(start[1] == '2') {
                string s; int l, h, Len = 0;
                cin >> s; //s = " " + s;
                cin >> l >> h;
                h = l + h - 1;
                Len = Convert2(s); //cout << Len <<endl;
                //cout << Querry_Three_COPY_String(s, 1, l - 1) << endl;
                //cout << Querry_Three_COPY_String(s, h + 1, Len) << endl;
                string RES = Querry_One_SUM_String(Querry_Three_COPY_String(s, 1, l - 1), Querry_Three_COPY_String(s, h + 1, Len));
                //cout << Querry_One_SUM_String(Querry_Three_COPY_String(s, 1, l - 1), Querry_Three_COPY_String(s, h + 1, Len)) << endl;
                cout << RES;
                if(RES.length() == 1) cout << 1 << endl;
                else cout << endl;
        }

        else if(start[1] == '3') {
                string s; int l, h;
                cin >> s; //s = " " + s;
                cin >> l >> h; h = h + l - 1; string RES = Querry_Three_COPY_String(s, l, h);
                cout << RES;
                if(RES.length() == 1) cout << 1 << endl;
                else cout << endl;
        }

        else if(start[1] == '4') {
                string s, t, head, tail, mid = "", mid2 = "";
                long long Len = 0, p;
                cin >> s; cin >> t; cin >> p; Len = Convert2(s);

                head = Querry_Three_COPY_String(s, 1, p - 1); tail = Querry_Three_COPY_String(s, p, Len); //cout << head << " " << tail << " " << Len<< endl;
                mid = Querry_One_SUM_String(head, t); string RES = Querry_One_SUM_String(mid, tail);
                cout << RES;
                if(RES.length() == 1) cout << 1 << endl;
                else cout << endl;
        }

        else if(start[1] == '5') {
                string s; long long l, r;
                cin >> s;
                cin >> l >> r;
                string Mid = Querry_Three_COPY_String(s, l, r);
                //cout << Mid << endl;
                if(Querry_Five_CHECK_Palin(Mid)) cout << "yes" << endl;
                else cout << "no" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("RLESTR.INP", "r", stdin);
    freopen("RLESTR.OUT", "w", stdout);

    Solve();
}
/// XÂU ĐÁNH SỐ TỪ 0
